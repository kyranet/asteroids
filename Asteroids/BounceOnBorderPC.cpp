#include "BounceOnBorderPC.h"

BounceOnBorderPC::BounceOnBorderPC() :
		BounceOnBorderPC(true, true, true, true) {

}

BounceOnBorderPC::BounceOnBorderPC(bool left, bool right, bool top, bool bot) :
		left_(left), right_(right), top_(top), bot_(bot) {
}

BounceOnBorderPC::~BounceOnBorderPC() {
}

void BounceOnBorderPC::update(Container* c, Uint32 time) {
	Vector2D p = c->getPosition();
	Vector2D v = c->getVelocity();


	if ( top_ ) {
		if (p.getY() <= 0) {
			p.setY(0);
			v.setY( -v.getY() );
		}

	}

	if ( bot_ ) {
		if (p.getY() + c->getHeight() >= c->getGame()->getWindowHeight()) {
			p.setY(c->getGame()->getWindowHeight() - c->getHeight());
			v.setY( -v.getY() );
		}

	}

	if ( left_ ) {
		if (p.getX() <= 0) {
			p.setX(0);
			v.setX( -v.getX() );
		}

	}

	if ( right_ ) {
		if (p.getX() + c->getWidth() >= c->getGame()->getWindowWidth()) {
			p.setX(c->getGame()->getWindowWidth() - c->getWidth());
			v.setX( -v.getX() );
		}
	}

	c->setPosition(p);
	c->setVelocity(v);
}
