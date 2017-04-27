#pragma once
#include "Entity.h"

class Quest_ind : public Entity
{
public:
	Quest_ind();
	~Quest_ind();


	//applying update and draw functions do quest_ind
	void update(float deltaTime);
	void draw(aie::Renderer2D* m_2dRenderer);
private:
	float speed;
	float rotateSpeed;
	float rotate;

};

