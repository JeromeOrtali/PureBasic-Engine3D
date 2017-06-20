﻿Enumeration
	#Event_KeyDown
	#Event_KeyUp
	#Event_MouseButtonDown
	#Event_MousseButtonUp
	#Event_MouseMove
	#Event_MouseWheel
	#Event_BackgroundResourceLoaded
	#Event_ResourceFileChanged
EndEnumeration

Structure KeyEvent
  key.l
  scancode.l
  buttons.l
  qualifiers.l
  repeats.b
EndStructure

Structure MouseButton
  button.l
  buttons.l
  qualifiers.l
EndStructure

Structure MouseMove
  x.l
  y.l
  dx.l
  dy.l
  buttons.l
  qualifiers.l
EndStructure

Structure MouseWheel
  wheel.l
  buttons.l
  qualifiers.l
EndStructure

Structure BackgroundResourceLoaded
  *name
  success.l
  *resource
EndStructure

Structure ResourceFileChanged
  *fileName
  *resourceName
EndStructure

Structure Event
  type.l ; see Enumeration
  StructureUnion
    key.KeyEvent
    mousebutton.MouseButton
    mousemove.MouseMove
    mousewheel.MouseWheel
    backgroundResourceLoaded.BackgroundResourceLoaded
    resourceFileChanged.ResourceFileChanged
  EndStructureUnion
EndStructure
; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 59
; FirstLine = 12
; EnableXP