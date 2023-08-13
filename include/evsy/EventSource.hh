#ifndef EVSY_EVENT_SOURCE_HH
#define EVSY_EVENT_SOURCE_HH

#include <evsy/EventHandler.hh>

#include <vector>

namespace evsy
{

template <typename EventType>
class EventSource
{
public:
	void setHandler(EventHandler <EventType>& handler)
	{
		this->handler = &handler;
	}

	void emit(EventType&& event)
	{
		if(handler)
			handler->handle(event);
	}

private:
	EventHandler <EventType>* handler = nullptr;
};

}

#endif
