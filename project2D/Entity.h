#pragma once
#include <vector>
#include "vector2.h"
#include "matrix3.h"
#include "Texture.h"
#include "Renderer2D.h"


class Entity
{
public:
	
	Entity();
	~Entity();

	Vector2 getPos();

	void createParent(Entity* Parent);
	void createChild(Entity* Child);

	virtual void update();
	virtual void draw(aie::Renderer2D* m_render2D);

	void updateTransform();



protected:

	Entity* m_parent;

	aie::Texture* m_shipTexture;
	aie::Texture* m_questIndTexture;


	std::vector<Entity*> m_child; 

	

	Matrix3 m_localMatrix;  //local matrix
	Matrix3 m_globalMatrix; //global matrix

};

