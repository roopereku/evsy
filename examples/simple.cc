#include <evsy/EventSource.hh>

#include <cstdio>

// First let's define a class which defines two events and sources for them.
class SourceExample
{
public:
	// Define an event.
	struct ExampleEvent
	{
		ExampleEvent(int number) : number(number) {}
		int number;
	};

	// Define sources for the example events.
	evsy::EventSource <ExampleEvent> example;

	// Define a function which can emit events.
	void emitEvents()
	{
		printf("Emitting ExampleEvent1\n");
		example.emit(ExampleEvent(10));
	}
};

// Now let's define a class which can handle the example event.
// Event handlers can be created by inheriting from evsy::EventHandler.
class HandlerExample : public evsy::EventHandler <SourceExample::ExampleEvent>
{
public:
	// Define event handler functions.
	void handle(SourceExample::ExampleEvent& event) override
	{
		printf("Got example event %d\n", event.number);
	}
};

int main()
{
	SourceExample sourceExample;
	HandlerExample handlerExample;

	// Use handlerExample as the handler for both of the example events.
	sourceExample.example.setHandler(handlerExample);

	// Let's try to emit events.
	sourceExample.emitEvents();
}
