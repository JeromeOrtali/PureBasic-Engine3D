XIncludeFile "Config.pbi"

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
IMPORT_FUNCTION(uh3_SetCameraFov, void , *camera _ fov.f)
IMPORT_FUNCTION(uh3_GetCameraFov, .f , *camera )
IMPORT_FUNCTION(uh3_SetCameraNearClip, void , *camera _ near.f)
IMPORT_FUNCTION(uh3_GetCameraNearClip, .f , *camera)
IMPORT_FUNCTION(uh3_SetCameraFarClip, void , *camera _ far.f)
IMPORT_FUNCTION(uh3_GetCameraFarClip, .f , *camera _ far.f)
IMPORT_FUNCTION(uh3_SetCameraViewMask, void , *camera _ viewMask.l)
IMPORT_FUNCTION(uh3_GetCameraViewMask, .l , *camera)
IMPORT_FUNCTION(uh3_SetCameraAutoAspectRatio, void , *camera _ enable.l)
IMPORT_FUNCTION(uh3_SetCameraUseReflection, void , *camera _ enable.l)
IMPORT_FUNCTION(uh3_SetCameraReflectionPlane, void , *camera _ *plane)
IMPORT_FUNCTION(uh3_SetCameraUseClipping, void , *camera _ enable.l)
IMPORT_FUNCTION(uh3_SetCameraClipPlane, void , *camera _ *plane)
IMPORT_FUNCTION(uh3_SetCameraAspectRatio,void, *camera _ aspectRatio.f)
IMPORT_FUNCTION(uh3_CreatePlane, .i , nx.f _ ny.f _ nz.f _ px.f _ py.f _ pz.f)
IMPORT_FUNCTION(uh3_CreatePlane2, .i , *node _ nx.f _ ny.f _ nz.f _ px.f _ py.f _ pz.f)
IMPORT_FUNCTION(uh3_FreePlane, void , *plane)

; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 20
; EnableXP