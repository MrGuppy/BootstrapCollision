#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Player.h"

using namespace aie;

Application2D::Application2D() 
{
}

Application2D::~Application2D() 
{
}

bool Application2D::startup() 
{
	m_2dRenderer = new Renderer2D();

	m_ship = new Player();

	m_QstInd = new Quest_ind();

	m_font = new Font("./font/consolas.ttf", 32);

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() 
{
	delete m_QstInd;
	delete m_font;
	delete m_ship;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;
	m_ship->update(deltaTime);
	m_QstInd->update(deltaTime);
}

void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering


	// begin drawing sprites
	m_2dRenderer->begin();
	 m_ship->draw(m_2dRenderer); //can't draw both at once 
	m_QstInd->draw(m_2dRenderer);









	// draw a thin line
	m_2dRenderer->drawLine(300, 300, 500, 400, 2, 1);

	// draw a moving purple circle
	m_2dRenderer->setRenderColour(1, 0, 1, 1);
	m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);

	// draw a rotating red box
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);

	// draw a slightly rotated sprite with no texture, coloured yellow
	m_2dRenderer->setRenderColour(1, 1, 0, 1);
	m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press Space for sound!", 0, 720 - 64);
	//m_2dRenderer->setUVRect(0,0,1,1);
	//m_2dRenderer->drawSprite(m_crabTexture, 600, 400, 0, 0, m_timer, 1);

	// done drawing sprites
	m_2dRenderer->end();
}