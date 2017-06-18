#include "Event.hpp"

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_EventHandler::PB_EventHandler(Urho3D::Context* context) : Urho3D::Object(context) {
	SubscribeToEvent(Urho3D::E_KEYDOWN, URHO3D_HANDLER(PB_EventHandler, ev_KeyDown));
	SubscribeToEvent(Urho3D::E_KEYUP, URHO3D_HANDLER(PB_EventHandler, ev_KeyUp));
	SubscribeToEvent(Urho3D::E_MOUSEBUTTONDOWN, URHO3D_HANDLER(PB_EventHandler, ev_MouseButtonDown));
	SubscribeToEvent(Urho3D::E_MOUSEBUTTONUP, URHO3D_HANDLER(PB_EventHandler, ev_MouseButtonUp));
	SubscribeToEvent(Urho3D::E_MOUSEMOVE, URHO3D_HANDLER(PB_EventHandler, ev_MouseMove));
	SubscribeToEvent(Urho3D::E_MOUSEWHEEL, URHO3D_HANDLER(PB_EventHandler, ev_MouseWheel));

	attachObserver(this);

}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void PB_EventHandler::ev_KeyDown(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData) {
	Event event;
	event.type				= keyDown;
	event.key.key			= eventData[Urho3D::KeyDown::P_KEY].GetInt();
	event.key.scancode		= eventData[Urho3D::KeyDown::P_SCANCODE].GetInt();
	event.key.buttons		= eventData[Urho3D::KeyDown::P_BUTTONS].GetInt();
	event.key.qualifiers	= eventData[Urho3D::KeyDown::P_QUALIFIERS].GetInt();
	event.key.repeat		= eventData[Urho3D::KeyDown::P_REPEAT].GetInt();

	notifyObservers((int)event.type, &event, sizeof(Event));

	PB_EVENT->push(event);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void PB_EventHandler::ev_KeyUp(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData) {
	Event event;
	event.type				= keyUp;
	event.key.key			= eventData[Urho3D::KeyUp::P_KEY].GetInt();
	event.key.scancode		= eventData[Urho3D::KeyUp::P_SCANCODE].GetInt();
	event.key.buttons		= eventData[Urho3D::KeyUp::P_BUTTONS].GetInt();
	event.key.qualifiers	= eventData[Urho3D::KeyUp::P_QUALIFIERS].GetInt();
	event.key.repeat		= 0;

	notifyObservers((int)event.type, &event, sizeof(Event));

	PB_EVENT->push(event);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void PB_EventHandler::ev_MouseButtonDown(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData) {
	Event event;
	event.type						= mouseButtonDown;
	event.mousebutton.button		= eventData[Urho3D::MouseButtonDown::P_BUTTON].GetInt();
	event.mousebutton.buttons		= eventData[Urho3D::MouseButtonDown::P_BUTTONS].GetInt();
	event.mousebutton.qualifiers	= eventData[Urho3D::MouseButtonDown::P_QUALIFIERS].GetInt();
	
	notifyObservers((int)event.type, &event, sizeof(Event));

	PB_EVENT->push(event);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void PB_EventHandler::ev_MouseButtonUp(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData) {
	Event event;
	event.type						= mouseButtonUp;
	event.mousebutton.button		= eventData[Urho3D::MouseButtonUp::P_BUTTON].GetInt();
	event.mousebutton.buttons		= eventData[Urho3D::MouseButtonUp::P_BUTTONS].GetInt();
	event.mousebutton.qualifiers	= eventData[Urho3D::MouseButtonUp::P_QUALIFIERS].GetInt();

	notifyObservers((int)event.type, &event, sizeof(Event));

	PB_EVENT->push(event);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void PB_EventHandler::ev_MouseMove(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData) {
	Event event;
	event.type					= mouseMove;
	event.mousemove.x			= eventData[Urho3D::MouseMove::P_X].GetInt();
	event.mousemove.y			= eventData[Urho3D::MouseMove::P_Y].GetInt();
	event.mousemove.dx			= eventData[Urho3D::MouseMove::P_DX].GetInt();
	event.mousemove.dy			= eventData[Urho3D::MouseMove::P_DY].GetInt();
	event.mousemove.buttons		= eventData[Urho3D::MouseMove::P_BUTTONS].GetInt();
	event.mousemove.qualifiers	= eventData[Urho3D::MouseMove::P_QUALIFIERS].GetInt();

	notifyObservers((int)event.type, &event, sizeof(Event));

	PB_EVENT->push(event);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void PB_EventHandler::ev_MouseWheel(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData) {
	Event event;
	event.type					= mouseWheel;
	event.mousewheel.wheel		= eventData[Urho3D::MouseWheel::P_WHEEL].GetInt();
	event.mousewheel.buttons	= eventData[Urho3D::MouseWheel::P_BUTTONS].GetInt();
	event.mousewheel.qualifiers	= eventData[Urho3D::MouseWheel::P_QUALIFIERS].GetInt();

	notifyObservers((int)event.type, &event, sizeof(Event));

	PB_EVENT->push(event);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void PB_EventHandler::notify(int what, void* data, int size) {
	for (auto & m : m_bindfunction) {
		if (what == m.first) {
			Event &event = *(Event*)data;
			(*m.second)(&event);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void PB_EventHandler::bindFunction(EventType type, fn_callback callback) {
	auto found = m_bindfunction.find(type);
	if (found == m_bindfunction.end()) {
		m_bindfunction.emplace(type, callback);
	}
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void PB_EventHandler::unBindFunction(EventType type, fn_callback) {
	auto found = m_bindfunction.find(type);
	if (found != m_bindfunction.end()) {
		m_bindfunction.erase(found);
	}
}


///////////////////////////////////////////////////////////////////////////////
// EXPORTED FUNCTIONS
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(int) PB_EnginePoolEvent(Event* ev) {
	if (PB_EVENT->size()) {
		*ev = PB_EVENT->front();
		PB_EVENT->pop();
		return 1;
	}
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(void) PB_BindEvent(int type, void* callback) {
	PB_URHOEVENT->bindFunction((EventType)type, (PB_EventHandler::fn_callback)callback);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(void) PB_UnBindEvent(int type, void* callback) {
	PB_URHOEVENT->unBindFunction((EventType)type, (PB_EventHandler::fn_callback)callback);
}