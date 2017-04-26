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
	float rotateSpeed; 
	float pullBack;
	float mass;

	Vector2 velocity;
	Vector2 dir;
	Player* player;

};

