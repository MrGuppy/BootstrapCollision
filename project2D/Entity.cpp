#include "Entity.h"


Entity::Entity()
{

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

}

void Entity::draw()
{

}