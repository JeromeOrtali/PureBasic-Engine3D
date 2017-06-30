XIncludeFile "Config.pbi"

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////

IMPORT_FUNCTION(uh3_CreateViewport, .i , *scene _ *camera _ index.l = 0)
IMPORT_FUNCTION(uh3_SetViewportBackgroundColor,.i ,*viewport _ color.l)
IMPORT_FUNCTION(uh3_SetViewportRect,void ,*viewport _ left.l _ top.l _ right.l _ bottom.l) 
IMPORT_FUNCTION(uh3_SetViewportRenderPathXML,void ,*viewport _ *XMLResource)


; TODO MOVE To CAMERA.PBI

IMPORT_FUNCTION(uh3_SetCameraFov, void , *camera _ fov.f)
; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 12
; EnableXP