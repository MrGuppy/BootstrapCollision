#pragma once
#include <vector>
#include "vector2.h"
#include "matrix3.h"
#include "Texture.h"

class Entity
{
public:
	
	Entity();
	~Entity();

	void createParent(Entity* Parent);
	void createChild(Entity* Child1);

	virtual void update();
	void updateTransform();
	virtual void draw();


protected:

	Entity* m_parent;
	std::vector<Entity*> m_child; 

	Matrix3 m_localMatrix;  //local matrix
	Matrix3 m_globalMatrix; //global matrix

};

