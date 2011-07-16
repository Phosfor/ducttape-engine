#include "EventBinding.hpp"

#include "Root.hpp"

namespace dt {

EventBinding::EventBinding() {
    mTriggerType = "";
}

EventBinding::EventBinding(const std::string& trigger_type, Event* target) {
    if(trigger_type == target->GetType()) {
        Logger::Error("The EventBinding " + trigger_type + " -> " + target->GetType() + " will cause an infinte event loop.");
    }
    mTriggerType = trigger_type;
    mTarget = std::shared_ptr<Event>(target);
}

EventBinding::~EventBinding() {}

void EventBinding::TriggerEvent(Event* e) {
    if(e->GetType() == mTriggerType) {
        Event* target = mTarget->Clone();
        if(target->TranslateFrom(e) && target->GetType() != e->GetType()) // prevent looping (see Event::TranslateFrom)
            Root::get_mutable_instance().GetEventManager()->HandleEvent(target);
    }
}

}
