#ifndef EVENT_HPP
#define EVENT_HPP

#include <Urho3D/Engine/Application.h>
#include <Urho3D/Engine/Engine.h>
#include <Urho3D/Input/InputEvents.h>
#include <Urho3D/Resource/BackgroundLoader.h>
#include <Urho3D/Resource/ResourceEvents.h>
#include <queue>
#include <map>

#include "Observer.hpp"
#include "Subject.hpp"


///////////////////////////////////////////////////////////////////////////////
// PUREBASIC EVENT TYPE
///////////////////////////////////////////////////////////////////////////////
enum EventType {
	keyDown,
	keyUp,
	mouseButtonDown,
	mouseButtonUp,
	mouseMove,
	mouseWheel,
	backgroundResourceLoaded,
	resourceFileChange
};

///////////////////////////////////////////////////////////////////////////////
// KEY EVENT ( KEYDOWN , KEYUP )
///////////////////////////////////////////////////////////////////////////////
struct KeyEvent {
	int key;
	int scancode;
	int buttons;
	int qualifiers;
	bool repeat;
};

///////////////////////////////////////////////////////////////////////////////
// MOUSE BUTTON ( UP & DOWN )
///////////////////////////////////////////////////////////////////////////////
struct MouseButton {
	int button;
	int buttons;
	int qualifiers;
};

///////////////////////////////////////////////////////////////////////////////
// MOUSE MOVE
///////////////////////////////////////////////////////////////////////////////
struct MouseMove {
	int x;
	int y;
	int dx;
	int dy;
	int buttons;
	int qualifiers;
};

///////////////////////////////////////////////////////////////////////////////
// MOUSE WHEEL
///////////////////////////////////////////////////////////////////////////////
struct MouseWheel {
	int wheel;
	int buttons;
	int qualifiers;
};

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
struct ResourceLoaded {
	wchar_t*	name;
	int			success;
	void*		resource;
};

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
struct ResourceFileChange {
	wchar_t*	fileName;
	wchar_t*	resourceName;
};

///////////////////////////////////////////////////////////////////////////////
// PUREBASIC EVENT SYSTEM
///////////////////////////////////////////////////////////////////////////////
struct Event {

	EventType type;

	union {
		KeyEvent			key;
		MouseButton			mousebutton;
		MouseMove			mousemove;
		MouseWheel			mousewheel;
		ResourceLoaded		resourceLoaded;
		ResourceFileChange	resourceFileChange;
	};

};

extern std::queue<Event>*	PB_EVENT;

///////////////////////////////////////////////////////////////////////////////
// INTERNAL REGISTER GENERAL EVENTS
///////////////////////////////////////////////////////////////////////////////
class PB_EventHandler : public Urho3D::Object , public Observer, public Subject {
	URHO3D_OBJECT(PB_EventHandler, Object);
public:

	typedef void(*fn_callback)(Event* event);

	PB_EventHandler(Urho3D::Context* context);

	void ev_KeyDown(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData);

	void ev_KeyUp(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData);

	void ev_MouseButtonDown(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData);

	void ev_MouseButtonUp(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData);

	void ev_MouseMove(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData);

	void ev_MouseWheel(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData);

	void ev_BackgroundLoadResource(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData);

	void ev_ResourceFileChange(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData);

	virtual void notify(int what, void* data, int size);

	void bindFunction(EventType type, fn_callback);
	
	void unBindFunction(EventType type, fn_callback);

private:
	
	std::map<int, fn_callback>	m_bindfunction;

};

extern PB_EventHandler*		PB_URHOEVENT;

#ifndef PB_FUNCTION
	#define PB_FUNCTION(T) __declspec(dllexport) T
#endif 

///////////////////////////////////////////////////////////////////////////////
// EXPORTED FUNCTIONS
///////////////////////////////////////////////////////////////////////////////
extern "C" {

	PB_FUNCTION(int) PB_EnginePoolEvent(Event* ev);

	PB_FUNCTION(void) PB_BindEvent(int type, void* callback);

	PB_FUNCTION(void) PB_UnBindEvent(int type, void* callback);

}



#endif // !EVENT_HPP