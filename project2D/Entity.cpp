#include "Entity.h"


Entity::Entity()
{
	//collider stuff
	m_parent = nullptr;
}

Entity::~Entity()
{
}

void Entity::updateTransform()
{

}

void Entity::createParent(Entity* Parent)
{
	Parent = m_parent;
}

void Entity::createChild(Entity* Child)
{
	m_child.push_back(Child);
}

void Entity::update()
{
	if (m_parent != nullptr)
		m_globalMatrix = m_parent->m_globalMatrix * m_localMatrix;
	else
		m_localMatrix = m_globalMatrix;
	for (auto child : m_child)
		child->updateTransform();
}

void Entity::draw(aie::Renderer2D* m_render2D)
{

}

Vector2 Entity::getPos()
{
	Vector2 Pos;
	Pos.x = m_globalMatrix.m[6];
	Pos.y = m_globalMatrix.m[7];
	return Pos;
}