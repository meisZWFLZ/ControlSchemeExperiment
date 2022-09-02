#include "events/actions/callback.h"
#include <functional>

void CallbackListener::execute() { callback(); };
CallbackListener::CallbackListener(std::function<void(void)> callback)
    : callback(callback){}