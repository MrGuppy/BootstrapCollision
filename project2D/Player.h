#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	~Player();

	void update(float deltaTime);
	void draw(aie::Renderer2D* m_2dRenderer);


private:
	//initializing Vectors 
	float speed;
	Vector2 velocity;
	Vector2 dir;
};

