#ifndef EVSY_EVENT_HANDLER_HH
#define EVSY_EVENT_HANDLER_HH

namespace evsy
{

template <typename EventType>
class EventHandler
{
public:
	virtual void handle(EventType& event) = 0;
};

}

#endif
