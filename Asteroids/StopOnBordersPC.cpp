#include "StopOnBordersPC.h"

#include "Vector2D.h"


StopOnBordersPC::StopOnBordersPC() :
		StopOnBordersPC(true, true, true, true) {
}

StopOnBordersPC::StopOnBordersPC(bool left, bool right, bool top, bool bot) :
	left_(left), right_(right), top_(top), bot_(bot) {
}

StopOnBordersPC::~StopOnBordersPC() {

}

void StopOnBordersPC::update(Container* c, Uint32 time) {

	Vector2D p = c->getPosition();
	Vector2D v = c->getVelocity();


	if ( top_ ) {
		if (p.getY() <= 0) {
			p.setY(0);
			v.setY(0);
		}

	}

	if ( bot_ ) {
		if (p.getY() + c->getHeight() >= c->getGame()->getWindowHeight()) {
			p.setY(c->getGame()->getWindowHeight() - c->getHeight());
			v.setY(0);
		}

	}

	if ( left_ ) {
		if (p.getX() <= 0) {
			p.setX(0);
			v.setX(0);
		}

	}

	if ( right_ ) {
		if (p.getX() + c->getWidth() >= c->getGame()->getWindowWidth()) {
			p.setX(c->getGame()->getWindowWidth() - c->getWidth());
			v.setX(0);
		}
	}

	c->setPosition(p);
	c->setVelocity(v);
}
