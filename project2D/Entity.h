#pragma once
class Entity
{
public:

	void createParent();
	void createChild();

	virtual void update();
	virtual void draw();
	Entity();
	~Entity();

protected:
	Entity* Parent;
	Entity* Child
};

