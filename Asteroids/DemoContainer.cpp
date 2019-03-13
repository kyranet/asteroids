#include "DemoContainer.h"

DemoContainer::DemoContainer(SDLGame* game) :
		Container(game),
		tennisball_(game->getServiceLocator()->getTextures()->getTexture(Resources::TennisBall)),
		backToCenter_(SDLK_c),
		bounceOnBorders_(true,true,true,true)
{
	addC(&tennisball_);
	addC(&backToCenter_);
	addC(&naturalMove_);
	addC(&bounceOnBorders_);
	addC(&keysInfo_);

	reset();

}

DemoContainer::~DemoContainer() {
}

void DemoContainer::reset() {
	setWidth(15);
	setHeight(15);
	setPosition(Vector2D(getGame()->getWindowWidth() / 2 - 6, getGame()->getWindowHeight() / 2 - 6));

	RandomNumberGenerator* r =
			getGame()->getServiceLocator()->getRandomGenerator();
	int dx = 1 - 2 * r->nextInt(0, 2); // 1 or -1
	int dy = 1 - 2 * r->nextInt(0, 2); // 1 or -1
	Vector2D v(dx * r->nextInt(2, 7), // 2 to 6
	dy * r->nextInt(2, 7)  // 2 to 6
			);
	setVelocity(v.normalize() * 2);
}
