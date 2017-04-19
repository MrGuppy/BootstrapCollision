#include "Player.h"
#include "input.h"
#include "Texture.h"

using namespace aie;

Player::Player()
{
	//m_shipTexture = new Texture("./textures/crabby.png");
}

Player::~Player()
{
}

void Player::update()
{
	Input* input = Input::getInstance(); // change cam to player pos

	if (input->isKeyDown(INPUT_KEY_UP));
		

	if (input->isKeyDown(INPUT_KEY_DOWN));


	if (input->isKeyDown(INPUT_KEY_LEFT));


	if (input->isKeyDown(INPUT_KEY_RIGHT));
}

void Player::draw()
{

}