#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "Player.h"
#include "Quest_ind.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;

	aie::Font*			m_font;
	aie::Audio*			m_audio;
	Player*				m_ship;
	Quest_ind*		    m_QstInd;
	float m_cameraX, m_cameraY;
	float m_timer;
};