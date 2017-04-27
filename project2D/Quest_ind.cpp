#include "Quest_ind.h"
#include "input.h"

using namespace aie;

Quest_ind::Quest_ind()
{
	m_questIndTexture = new Texture("./textures/rock_small.png "); //input quest indicator from heap

	rotateSpeed = 2.0f; //initialuizing rotation speed 
}

Quest_ind::~Quest_ind()
{
	delete m_questIndTexture;
}

void Quest_ind::update(float deltaTime)
{
	Input* input = Input::getInstance(); //creating instance

	if (input->isKeyDown(INPUT_KEY_Q))
	{
		rotate = rotateSpeed * deltaTime;
	}

	if (input->isKeyDown(INPUT_KEY_E))
	{
		rotate = -rotateSpeed * deltaTime;
	}

	Matrix3 questRotate;
	questRotate.setRotateZ(rotate);
	m_localMatrix = m_localMatrix * questRotate;

	Vector2 Pos = Vector2(2, 3);

	Matrix3 questPos;
	questPos.setPos(Pos);
	m_localMatrix = m_localMatrix * questPos;

	updateTransform();
}

void Quest_ind::draw(aie::Renderer2D* m_2dRenderer)
{
	m_2dRenderer->begin();
	m_2dRenderer->drawSpriteTransformed3x3(m_questIndTexture, m_globalMatrix);
}