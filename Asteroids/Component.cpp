#include "Component.h"
#include "Messages_defs.h"

Component::Component() {}

Component::~Component() {}

void Component::receive(Container*, const msg::Message&) {
  // By default components do not do anything when receiving a message.
  // Only those interested will implement this method
}
