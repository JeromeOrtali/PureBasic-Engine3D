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
IMPORT_FUNCTION(uh3_InitEngine3D, void, argc.l _ *argv)
IMPORT_FUNCTION(uh3_OpenScreen3D, void, width.l _ height.l _ fullscreen.l _ title.s _ resizable.l)
IMPORT_FUNCTION(uh3_EmbedScreen, void, *window)
IMPORT_FUNCTION(uh3_EngineRun, .i , void)
IMPORT_FUNCTION(uh3_EngineExit, void, void)
IMPORT_FUNCTION(uh3_EngineRenderFrame, void, void)
IMPORT_FUNCTION(uh3_PoolEvent, void, *event)
IMPORT_FUNCTION(uh3_BindEvent, void, type.l _ *callback)
IMPORT_FUNCTION(uh3_UnBindEvent, void, type.l _ *callback)
IMPORT_FUNCTION(uh3_GetResource, .i, type.l _ name.s)
IMPORT_FUNCTION(uh3_GetResourceBackground, .l, type.l _ name.s)
IMPORT_FUNCTION(uh3_AddManualResource,void, *resource)
IMPORT_FUNCTION(uh3_SetDrawShadow,void,enable.l)
IMPORT_FUNCTION(uh3_GetDrawShadow,.l,void)
IMPORT_FUNCTION(uh3_SetHDRRendering,void,enable.l)
IMPORT_FUNCTION(uh3_GetHDRRendering,.l,void)
IMPORT_FUNCTION(uh3_SetSpecularLighting,void,enable.l)
IMPORT_FUNCTION(uh3_GetSpecularLighting,.l,void)
IMPORT_FUNCTION(uh3_SetShadowMapSize,void,size.l)
IMPORT_FUNCTION(uh3_SetShadowMapQuality,void,quality.l)
IMPORT_FUNCTION(uh3_GetShadowMapQuality,.l,void)





; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 67
; FirstLine = 22
; EnableXP
; Executable = Test.exe