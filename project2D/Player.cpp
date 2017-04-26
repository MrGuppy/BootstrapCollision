#include "Player.h"
#include "input.h"
#include "vector2.h"
#include "matrix3.h"

using namespace aie;

Player::Player()
{
	m_shipTexture = new Texture("./textures/ship.png");
	speed = 1000.0f;
	rotateSpeed = 2.0f;
	pullBack = 1.0f;
	mass = 1.0f;
}

Player::~Player()
{
	delete m_shipTexture;
}

void Player::update(float deltaTime)
{
	Input* input = Input::getInstance(); // change cam to player pos

	Vector2 dir = Vector2(0, 0);
	float rotate = 0;
	float pull = 0;

	if (input->isKeyDown(INPUT_KEY_W))
	{
		dir.y = 1;
	}

	if (input->isKeyDown(INPUT_KEY_S))
	{
		dir.y = -1;

	}
 
	if (input->isKeyDown(INPUT_KEY_A))
	{
		//dir.x = -1;
		rotate = rotateSpeed * deltaTime;

	}

	if (input->isKeyDown(INPUT_KEY_D))
	{
		//dir.x = 1;
		rotate = -rotateSpeed * deltaTime;

	}


	Matrix3 PlayerPos;
	//velocity += dir * speed * deltaTime;
	//Pos += velocity * deltaTime;
	

	//Drag and Mass????
	//should mass be a float?
	//what is dampening?
	//how do you add drag
	
	Vector2 force = dir * speed;
	Vector2 acceleration = force / mass;
	Vector2 dampening = -(velocity * pullBack);

	velocity += (acceleration + dampening) * deltaTime;
	Vector2 Pos = velocity * deltaTime;

	PlayerPos.setPos(Pos);
	m_localMatrix = m_localMatrix * PlayerPos;

	Matrix3 PlayerRotate;
	PlayerRotate.setRotateZ(rotate);
	m_localMatrix = m_localMatrix * PlayerRotate;
	


		updateTransform();
}

void Player::draw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setCameraPos(m_globalMatrix.m[6] - 640, m_globalMatrix.m[7] - 360);
	m_2dRenderer->begin();
	m_2dRenderer->drawSpriteTransformed3x3(m_shipTexture, m_globalMatrix);
}