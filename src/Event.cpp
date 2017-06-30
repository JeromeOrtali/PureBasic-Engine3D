/*	PureBasic Engine3D licence
*	--------------------------
*
*	MIT License
*
*	Copyright (c) 2017 Jerome Ortali
*
*	Permission is hereby granted, free of charge, to any person obtaining a copy
*	of this software and associated documentation files (the "Software"), to deal
*	in the Software without restriction, including without limitation the rights
*	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*	copies of the Software, and to permit persons to whom the Software is
*	furnished to do so, subject to the following conditions:
*
*	The above copyright notice and this permission notice shall be included in all
*	copies or substantial portions of the Software.
*
*	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*	SOFTWARE.
*/
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

	SubscribeToEvent(Urho3D::E_RESOURCEBACKGROUNDLOADED, URHO3D_HANDLER(PB_EventHandler, ev_BackgroundLoadResource));

	SubscribeToEvent(Urho3D::E_FILECHANGED, URHO3D_HANDLER(PB_EventHandler, ev_ResourceFileChange));

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
void PB_EventHandler::ev_BackgroundLoadResource(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData) {
	Event event;
	event.type = backgroundResourceLoaded;
	event.resourceLoaded.name		= (wchar_t*)Urho3D::WString( eventData[Urho3D::ResourceBackgroundLoaded::P_RESOURCENAME].GetString() ).CString();
	event.resourceLoaded.success	= (int)						 eventData[Urho3D::ResourceBackgroundLoaded::P_SUCCESS].GetBool();
	event.resourceLoaded.resource	= (void*)					 eventData[Urho3D::ResourceBackgroundLoaded::P_RESOURCE].GetPtr();

	notifyObservers((int)event.type, &event, sizeof(Event));

	PB_EVENT->push(event);
}	

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void PB_EventHandler::ev_ResourceFileChange(Urho3D::StringHash eventType, Urho3D::VariantMap& eventData) {
	Event event;
	event.type = resourceFileChange;
	event.resourceFileChange.resourceName = (wchar_t*)Urho3D::WString(eventData[Urho3D::FileChanged::P_RESOURCENAME].GetString()).CString();
	event.resourceFileChange.fileName     = (wchar_t*)Urho3D::WString(eventData[Urho3D::FileChanged::P_FILENAME].GetString()).CString();

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
PB_FUNCTION(int) uh3_PoolEvent(Event* ev) {
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
PB_FUNCTION(void) uh3_BindEvent(int type, void* callback) {
	PB_URHOEVENT->bindFunction((EventType)type, (PB_EventHandler::fn_callback)callback);
}

///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
PB_FUNCTION(void) uh3_UnBindEvent(int type, void* callback) {
	PB_URHOEVENT->unBindFunction((EventType)type, (PB_EventHandler::fn_callback)callback);
}