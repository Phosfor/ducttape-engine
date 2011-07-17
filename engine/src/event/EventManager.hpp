
// ----------------------------------------------------------------------------
// This file is part of the Ducttape Project (http://ducttape-dev.org) and is
// licensed under the GNU LESSER PUBLIC LICENSE version 3. For the full license
// text, please see the LICENSE file in the root of this project or at
// http://www.gnu.org/licenses/lgpl.html
// ----------------------------------------------------------------------------

#ifndef DUCTTAPE_ENGINE_EVENT_EVENTMANAGER
#define DUCTTAPE_ENGINE_EVENT_EVENTMANAGER

#include <vector>

#include "Event.hpp"
#include "EventListener.hpp"
#include "BindingsManager.hpp"

namespace dt {

/**
  * Class holding all EventListeners, which is responsible to send all Events through the
  * Event system.
  * @see EventListener
  * @see Event
  */
class EventManager {
public:
    /**
      * Default constructor.
      */
    EventManager();

    /**
      * Initializer.
      */
    void Initialize();

    /**
      * Deinitializer.
      */
    void Deinitialize();

    /**
      * Method used to initiate an Event being sent to all EventListeners.
      * @param event The Event to be sent.
      */
    void HandleEvent(Event* event);

    /**
      * Checks if the EventListener is in the list.
      * @param listener The EventListener to find.
      * @returns True if the EventListener is registered, otherwise false.
      */
    bool HasListener(EventListener* listener);

    /**
      * Adds an EventListener to the list of listeners.
      * @param listener The EventListener to add.
      */
    void AddListener(EventListener* listener);

    /**
      * Removes an EventListener from the list of listeners.
      * @param listener The EventListener to remove.
      */
    void RemoveListener(EventListener* listener);

    /**
      * Returns the BindingsManager.
      * @returns The BindingsManager.
      */
    BindingsManager* GetBindingsManager();
private:
    std::vector<EventListener*> mListeners; //!< The list of EventListeners.
    BindingsManager mBindingsManager;
};

}

#endif
