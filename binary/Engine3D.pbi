﻿Macro void
EndMacro

Macro QUOTE
"
EndMacro

Macro _
,  
EndMacro

Macro IMPORT_FUNCTION(name, ret, param)
  PrototypeC#ret name(param)
  Global name.name = GetFunction(0,QUOTE#name#QUOTE)
EndMacro


OpenLibrary(0,"bin/Engine3D.dll")


IMPORT_FUNCTION(PB_InitEngine3D, void, argc.l _ *argv)
IMPORT_FUNCTION(PB_OpenScreen3D, void, width.l _ height.l _ fullscreen.l _ title.s _ resizable.l)
IMPORT_FUNCTION(PB_EmbedScreen, void, *window)
IMPORT_FUNCTION(PB_EngineRun, void, void)
IMPORT_FUNCTION(PB_EngineExit, void, void)
IMPORT_FUNCTION(PB_EngineRenderFrame, void, void)

IMPORT_FUNCTION(PB_EnginePoolEvent, void, *event)
IMPORT_FUNCTION(PB_BindEvent, void, type.l _ *callback)
IMPORT_FUNCTION(PB_UnBindEvent, void, type.l _ *callback)


IncludeFile "Event.pbi"




; ExamineLibraryFunctions(0)
; 
; While NextLibraryFunction()
; Debug LibraryFunctionName()  
;   
; Wend

ProcedureC foo(*ev.Event)
Debug *ev\mousemove\dx
EndProcedure




PB_InitEngine3D(#Null,#Null)


PB_BindEvent(#Event_MouseMove,@foo()) 

 PB_OpenScreen3D(640,780,0,"test",1)
;  OpenWindow(0,0,0,800,600,"")
;  ContainerGadget(0,50,50,256,256)
;  PB_EmbedScreen(GadgetID(0))

;   PB_OpenScreen3D(640,780,0,"test",1)

While PB_EngineRun()
  
  ev.Event
  While PB_EnginePoolEvent(@ev)
;     Debug ev\type
     If ev\type = 1
;       
;       Debug ev\key\qualifiers
;       Debug ev\key\buttons
;       Debug ev\key\repeats
;       Debug ev\key\scancode
;       Debug ev\key\key
;       
       If ev\key\key = 27
         Break 2
       EndIf 
;       
     EndIf 
    
  Wend 
  
  
;    Repeat
;    e = WindowEvent()
;    If e = #PB_Event_CloseWindow
;   
;      
;      Break 2
;    EndIf 
;    Until e = #PB_Event_None
  
  
  
  PB_EngineRenderFrame()
  
  
  
  
  
Wend

;     CloseWindow(0)
    PB_EngineExit()
    CloseLibrary(0)
    End 
;    

; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 80
; FirstLine = 42
; Folding = -
; EnableXP
; Executable = Test.exe
; SubSystem = opengl