XIncludeFile "Config.pbi"
XIncludeFile "Event.pbi"
XIncludeFile "Scene.pbi"
XIncludeFile "Viewport.pbi"
XIncludeFile "Node.pbi"





Enumeration
	#Resource_Sound
	#Resource_Material
	#Resource_Model
	#Resource_ParticleEffect
	#Resource_TMXFile
	#Resource_XMLFile
	#Resource_JSONFile
	#Resource_Font
	#Resource_Image
	#Resource_script
EndEnumeration



IMPORT_FUNCTION(PB_InitEngine3D, void, argc.l _ *argv)
IMPORT_FUNCTION(PB_OpenScreen3D, void, width.l _ height.l _ fullscreen.l _ title.s _ resizable.l)
IMPORT_FUNCTION(PB_EmbedScreen, void, *window)
IMPORT_FUNCTION(PB_EngineRun, .i , void)
IMPORT_FUNCTION(PB_EngineExit, void, void)
IMPORT_FUNCTION(PB_EngineRenderFrame, void, void)

IMPORT_FUNCTION(PB_EnginePoolEvent, void, *event)
IMPORT_FUNCTION(PB_BindEvent, void, type.l _ *callback)
IMPORT_FUNCTION(PB_UnBindEvent, void, type.l _ *callback)

IMPORT_FUNCTION(PB_getResource, .i, type.l _ name.s)
IMPORT_FUNCTION(PB_backgroundLoadResource, .l, type.l _ name.s)







; ; ExamineLibraryFunctions(0)
; ; 
; ; While NextLibraryFunction()
; ; Debug LibraryFunctionName()  
; ;   
; ; Wend
; 
; ProcedureC fileChange(*ev.Event)
;   Debug ">"
;   Debug PeekS(*ev\resourceFileChanged\fileName)
;   Debug PeekS(*ev\resourceFileChanged\resourceName)
;   Debug ""
; EndProcedure
; 
; ProcedureC backgroundLoad(*ev.Event)
;   Debug "load:"
;   Debug PeekS(*ev\backgroundResourceLoaded\name)
;   Debug *ev\backgroundResourceLoaded\success
;   Debug *ev\backgroundResourceLoaded\resource
;   Debug ""
;   
;   
; EndProcedure
; 
; PB_InitEngine3D(#Null , #Null)
; 
; 
; PB_BindEvent(#Event_ResourceFileChanged,@fileChange()) 
; PB_BindEvent(#Event_BackgroundResourceLoaded,@backgroundLoad()) 
; 
; 
; 
;  PB_OpenScreen3D(640,780,0, "You suck !" ,1)
; ;  OpenWindow(0,0,0,800,600,"")
; ;  ContainerGadget(0,50,50,256,256)
; ;  PB_EmbedScreen(GadgetID(0))
; 
; ;   PB_OpenScreen3D(640,780,0,"test",1)
;  
; Debug PB_backgroundLoadResource(7,"Fonts/Anonymous Pro.ttf")
; Debug PB_backgroundLoadResource(7,"Fonts/BlueHighddway.ttf")
; Debug PB_backgroundLoadResource(8,"Textures/TerrainWddeights.dds")
; 
; 
;  
;  
; While PB_EngineRun()
;   
;   ev.Event
;   While PB_EnginePoolEvent(@ev)
; ;     Debug ev\type
;      If ev\type = 1
; ;       
; ;       Debug ev\key\qualifiers
; ;       Debug ev\key\buttons
; ;       Debug ev\key\repeats
; ;       Debug ev\key\scancode
; ;       Debug ev\key\key
; ;       
;        If ev\key\key = 27
;          Break 2
;        EndIf 
; ;       
;      EndIf 
;     
;   Wend 
;   
;   
; ;    Repeat
; ;    e = WindowEvent()
; ;    If e = #PB_Event_CloseWindow
; ;   
; ;      
; ;      Break 2
; ;    EndIf 
; ;    Until e = #PB_Event_None
;   
;   
;   
;   PB_EngineRenderFrame()
;   
;   
;   
;   
;   
; Wend
; 
; ;     CloseWindow(0)
;     PB_EngineExit()
;     CloseLibrary(0)
;     End 
; ;    

; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 20
; EnableXP
; Executable = Test.exe
; SubSystem = opengl