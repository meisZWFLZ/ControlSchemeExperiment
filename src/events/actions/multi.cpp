#include "events/actions/multi.h"
#include <vector>

MultiAction::MultiAction(std::vector<EventAction> children)
    : children(children){};

void MultiAction::execute() {
  for (auto i = children.begin(); i != children.end(); ++i)
    i->execute();
}