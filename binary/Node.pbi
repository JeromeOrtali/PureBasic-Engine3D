XIncludeFile "Config.pbi"

Enumeration
  #NodeComponent_camera
  #NodeComponent_staticModel  
  #NodeComponent_skybox  
  #NodeComponent_light
EndEnumeration


IMPORT_FUNCTION(PB_CreateNodeComponent, .i , *node _ component.l )
IMPORT_FUNCTION(PB_GetChildByName, .i, *node _ name.s _ recursive.b )
IMPORT_FUNCTION(PB_GetChildByID, .i, *node _ id.l )
IMPORT_FUNCTION(PB_SetNodePosition, void , *node _ x.f _ y.f _ z.f )
IMPORT_FUNCTION(PB_SetNodeRotation, void , *node _ x.f _ y.f _ z.f )


; to go to Model.pbi
IMPORT_FUNCTION(PB_SetModel, void , *model _ *resource)
IMPORT_FUNCTION(PB_SetMaterial, void , *model _ *resource)
; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 11
; EnableXP