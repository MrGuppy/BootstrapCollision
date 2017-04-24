#include "Player.h"
#include "input.h"
#include "vector2.h"
#include "matrix3.h"

using namespace aie;

Player::Player()
{
	m_crabTexture = new Texture("./textures/crabby.png");
	speed = 100.0f;
}

Player::~Player()
{
	delete m_crabTexture;
}

void Player::update(float deltaTime)
{
	Input* input = Input::getInstance(); // change cam to player pos

	dir = Vector2(0, 0); //starting vector at origin point 

	if (input->isKeyDown(INPUT_KEY_W))
		dir = Vector2(0, 1);

	if (input->isKeyDown(INPUT_KEY_S))
		dir = Vector2(0, -1);

	if (input->isKeyDown(INPUT_KEY_A))
		dir = Vector2(-1, 0);

	if (input->isKeyDown(INPUT_KEY_D))
		dir = Vector2(1, 0);

	velocity += dir * speed * deltaTime;
	Pos = velocity * deltaTime;

	Matrix3 PlayerPos;
	PlayerPos.setPos(Pos);

	 m_localMatrix = m_localMatrix * PlayerPos;
	 
	 updateTransform();

}

void Player::draw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setCameraPos(m_globalMatrix.m[6] - 640, m_globalMatrix.m[7] - 360);
	m_2dRenderer->drawSpriteTransformed3x3(m_crabTexture, m_globalMatrix);
}