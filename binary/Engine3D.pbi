IncludePath "include"
XIncludeFile "Config.pbi"
XIncludeFile "Event.pbi"
XIncludeFile "Scene.pbi"
XIncludeFile "Viewport.pbi"
XIncludeFile "Node.pbi"
XIncludeFile "Model.pbi"
XIncludeFile "AnimatedModel.pbi"
XIncludeFile "Script.pbi"
XIncludeFile "Light.pbi"
XIncludeFile "Texture.pbi"
XIncludeFile "Material.pbi"
XIncludeFile "Camera.pbi"
XIncludeFile "Skybox.pbi"
XIncludeFile "Zone.pbi"
XIncludeFile "Terrain.pbi"

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
Enumeration
  #UH3_RESOURCE_SOUND
  #UH3_RESOURCE_MATERIAL
  #UH3_RESOURCE_MODEL
  #UH3_RESOURCE_PARTICLEEFFECT
  #UH3_RESOURCE_TMXFILE
  #UH3_RESOURCE_XMLFILE
  #UH3_RESOURCE_JSONFILE
  #UH3_RESOURCE_FONT
  #UH3_RESOURCE_IMAGE
  #UH3_RESOURCE_SCRIPT
  #UH3_RESOURCE_TECHNIQUE
EndEnumeration

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
Enumeration
  #UH3_SHADOWQUALITY_SIMPLE_16BIT
  #UH3_SHADOWQUALITY_SIMPLE_24BIT
  #UH3_SHADOWQUALITY_PCF_16BIT
  #UH3_SHADOWQUALITY_PCF_24BIT
  #UH3_SHADOWQUALITY_VSM
  #UH3_SHADOWQUALITY_BLUR_VSM  
EndEnumeration

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////

; Initialize Engine, this function must be called in first before use the engine
; Garde les paramètre ?? 
;
IMPORT_FUNCTION(uh3_InitEngine3D, void, argc.l = 0 _ *argv = #Null)

; Open main screen window at given size 
;
IMPORT_FUNCTION(uh3_OpenScreen3D, void, width.l _ height.l _ fullscreen.l _ title.s _ resizable.l)

; Embed main screen into existing resource ( windows, widget , etc...)
; you can pass to *window a gadget handle or window handle like WindowID() or GadgetID()
; if you use this method, the engine Event will not work, you must provide your Event with 
; regular PureBasic code
;
IMPORT_FUNCTION(uh3_EmbedScreen, void, *window)

; Return true when the engine is running, false when the engine will be end 
; The engine can be ended with uh3_EngineExit() 
;
IMPORT_FUNCTION(uh3_EngineRun, .i , void)

; Call the engine to be ended, and unload internal resources
;
IMPORT_FUNCTION(uh3_EngineExit, void, void)

; bientot obsolete
;
IMPORT_FUNCTION(uh3_EngineRenderFrame, void, void)

; call this function every frame for intercept Event on the engine
; ( keyboard , mouse , joypad , physic , file loading , etc... )
; pass an pointer of uh3_Event ( see Event.pbi ) 
; and retrieve the event type with *Event\type
; this function return True when event waiting to the queue
; false when no event
IMPORT_FUNCTION(uh3_PoolEvent, .l, *event)

; You can bind function with an particular Event 
; the callback function must have this signature : ProcedureC MyCallBack(*ev.uh3_Event)
; ProcedureC is important !
; the type of callback can be a constant defined in Event.pbi aka :
; #UH3_EVENT_KEYDOWN
; #UH3_EVENT_KEYUP
; #UH3_EVENT_MOUSEBUTTONDOWN
; #UH3_EVENT_MOUSSEBUTTONUP
; etc...
; your callbcak function is fired when a event appear 
; to the event queue
;
IMPORT_FUNCTION(uh3_BindEvent, void, type.l _ *callback)

; Unbind a callback
;
IMPORT_FUNCTION(uh3_UnBindEvent, void, type.l _ *callback)

; Urho3D come with a resource manager, the default path 
; is './Datas' all resources is stored but not loaded by the engine
; you can call this function for load a particular resource
; See Engine3D.pbi for see different type of resource 
; All constant type begin whit #UH3_RESOURCE_xxx where xxx is your 
; resource type , ex : #UH3_RESOURCE_MODEL 
; the name is the path of resource inside the current data directories 
; This is a "blocked" function, your program stay at this function 
; until the resource is loaded
;
IMPORT_FUNCTION(uh3_GetResource, .i, type.l _ name.s)

; This function as the same has uh3_GetResource , but in background
; this is an non-blocking function , an event was fired when 
; your resource is ready : #UH3_EVENT_BACKGROUNDRESOURCELOADED
; you can bind an callback to this event and retrieve the resource name
; inside your callback with the callback parameter ( see uh3_BindEvent() )
; ex: 
; ProcedureC MyCallBack(*ev.uh3_Event)
; if *ev\type = #UH3_EVENT_BACKGROUNDRESOURCELOADED
; debug peeks(*ev\backgroundResourceLoaded\name) ; name of resource loaded
; ...
; the event type (uh3_BackgroundResourceLoaded) is defined inside Event.pbi
;
IMPORT_FUNCTION(uh3_GetResourceBackground, .l, type.l _ name.s)

; Add custom resource to the resouce manager, the resource must have a name
; *Texture = uh3_CreateTexture2D(...
; uh3_SetTextureName(*Texture, "MyTexture")
;
IMPORT_FUNCTION(uh3_AddManualResource,void, *resource)  ; NEED TO BE TESTED

; Enable shadow map
;
IMPORT_FUNCTION(uh3_SetDrawShadow,void,enable.l)

; Return true when shadow map is enable, false is not
;
IMPORT_FUNCTION(uh3_GetDrawShadow,.l,void)

; Enable HDR rendering
;
IMPORT_FUNCTION(uh3_SetHDRRendering,void,enable.l)

; Return true when hdr rendering is enable, false is not
;
IMPORT_FUNCTION(uh3_GetHDRRendering,.l,void)

; enable specular lighting , true is enable
;
IMPORT_FUNCTION(uh3_SetSpecularLighting,void,enable.l)

; Return true when specular light is enable, false is not
;
IMPORT_FUNCTION(uh3_GetSpecularLighting,.l,void)

; Set the shadow map size, the size must be power of two
;
IMPORT_FUNCTION(uh3_SetShadowMapSize,void,size.l)

; set the shadow quality
;
;   #UH3_SHADOWQUALITY_SIMPLE_16BIT
;   #UH3_SHADOWQUALITY_SIMPLE_24BIT
;   #UH3_SHADOWQUALITY_PCF_16BIT
;   #UH3_SHADOWQUALITY_PCF_24BIT
;   #UH3_SHADOWQUALITY_VSM
;   #UH3_SHADOWQUALITY_BLUR_VSM  

IMPORT_FUNCTION(uh3_SetShadowMapQuality,void,quality.l)

; retrieve the shadow map quality
;
IMPORT_FUNCTION(uh3_GetShadowMapQuality,.l,void)

; draw debug geomtry, your scene must have a debug component
; the component to debug is defined in Node.pbi
; all constant for this begin with #UH3_NODECOMPONENT_xxx
; you must be logic, you can debug #UH3_NODECOMPONENT_TERRAIN or #UH3_NODECOMPONENT_STATICMODEL
; but debuging #UH3_NODECOMPONENT_SCRIPT has no effect...
; the depthtest can be true if you want see only visible debug line
IMPORT_FUNCTION(uh3_DrawDebugGeometry,void,component.l _ *node _ *debugrenderer _ depthTest.l)


; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 135
; FirstLine = 131
; EnableXP
; Executable = Test.exe