#include "DemoGC.h"

DemoGC::DemoGC() {
}

DemoGC::~DemoGC() {
}

void DemoGC::render(Container* c, Uint32 time) {

	Texture msg0(c->getGame()->getRenderer(),
			"This is just a demo",
			*(c->getGame()->getServiceLocator()->getFonts()->getFont(
					Resources::ARIAL24)), { COLOR(0x0022ffff) });
	msg0.render(c->getGame()->getRenderer(),
			c->getGame()->getWindowWidth() / 2 - msg0.getWidth() / 2, c->getGame()->getWindowHeight()-150);

	Texture msg1(c->getGame()->getRenderer(),
			"Press C to reset the ball",
			*(c->getGame()->getServiceLocator()->getFonts()->getFont(
					Resources::ARIAL24)), { COLOR(0x00ff22ff) });
	msg1.render(c->getGame()->getRenderer(),
			c->getGame()->getWindowWidth() / 2 - msg1.getWidth() / 2, c->getGame()->getWindowHeight()-100);

	Texture msg2(c->getGame()->getRenderer(),
			"Press ESC to exit",
			*(c->getGame()->getServiceLocator()->getFonts()->getFont(
					Resources::ARIAL24)), { COLOR(0xff1122ff) });
	msg2.render(c->getGame()->getRenderer(),
			c->getGame()->getWindowWidth() / 2 - msg2.getWidth() / 2, c->getGame()->getWindowHeight()-50);

}
