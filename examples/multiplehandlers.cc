#include <evsy/EventSource.hh>

#include <vector>
#include <cstdio>

// Define an example event source.
class SourceExample
{
public:
	struct ExampleEvent
	{
		ExampleEvent() {}
	};

	evsy::EventSource <ExampleEvent> example;
};

// Define an event handler which forwards events to other handlers.
class ExampleDistributor :
	public evsy::EventHandler <SourceExample::ExampleEvent>
{
public:
	void addHandler(evsy::EventHandler <SourceExample::ExampleEvent>& handler)
	{
		handlers.push_back(&handler);
	}

	// When an event is received, forward it to the handlers.
	void handle(SourceExample::ExampleEvent& event) override
	{
		for(auto& handler : handlers)
			handler->handle(event);
	}

private:
	std::vector <evsy::EventHandler <SourceExample::ExampleEvent>*> handlers;
};

class ExampleHandler :
	public evsy::EventHandler <SourceExample::ExampleEvent>
{
public:
	ExampleHandler(int id) : id(id) {}

	void handle(SourceExample::ExampleEvent& event)
	{
		printf("%d got an event\n", id);
	}

private:
	int id;
};

int main()
{
	SourceExample source;
	ExampleDistributor distributor;

	ExampleHandler handler1(1);
	ExampleHandler handler2(2);

	// Distribute events to handler1 and handler2.
	distributor.addHandler(handler1);
	distributor.addHandler(handler2);

	// Send the example events to the distributor.
	source.example.setHandler(distributor);

	// Emit an example event.
	source.example.emit(SourceExample::ExampleEvent());
}
