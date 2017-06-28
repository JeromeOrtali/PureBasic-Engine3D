XIncludeFile "Config.pbi"
XIncludeFile "Scene.pbi"
;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
Enumeration ; different component for node
  #UH3_NODECOMPONENT_CAMERA
  #UH3_NODECOMPONENT_STATICMODEL
  #UH3_NODECOMPONENT_ANIMATEDMODEL
  #UH3_NODECOMPONENT_SKYBOX
  #UH3_NODECOMPONENT_LIGHT
  #UH3_NODECOMPONENT_TERRAIN
  #UH3_NODECOMPONENT_SCRIPT
  ;...
  ; more will be arrive...
  ;...
EndEnumeration



;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
Enumeration ; Transformation 
  #UH3_LOCAL
  #UH3_PARENT
  #UH3_WORLD
EndEnumeration

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
IMPORT_FUNCTION(uh3_CreateNodeComponent, .i , *node _ component.l )
IMPORT_FUNCTION(uh3_GetNodeChildByName, .i, *node _ name.s _ recursive.b = #False)
IMPORT_FUNCTION(uh3_GetNodeChildByID, .i, *node _ id.l )
IMPORT_FUNCTION(uh3_SetNodeTemporary, void, state.l)
IMPORT_FUNCTION(uh3_SetNodePosition, void , *node _ x.f _ y.f _ z.f )
IMPORT_FUNCTION(uh3_NodeTranslate, void , *node _ x.f _ y.f _ z.f _ mode.l = #UH3_LOCAL)
IMPORT_FUNCTION(uh3_SetNodeRotation, void , *node _ x.f _ y.f _ z.f )
IMPORT_FUNCTION(uh3_NodeRotate, void , *node _ x.f _ y.f _ z.f _ mode.l = #UH3_LOCAL )
IMPORT_FUNCTION(uh3_SetNodeDirection,  void, *node _  x.f _  y.f _  z.f)
IMPORT_FUNCTION(uh3_SetNodeUniformScale,  void, *node _  scale.f)
IMPORT_FUNCTION(uh3_SetNodeScale,  void, *node _ x.f _  y.f _  z.f)
IMPORT_FUNCTION(uh3_SetNodeWorldPosition,  void, *node _  x.f _  y.f _  z.f)
IMPORT_FUNCTION(uh3_NodeLookAt,  void, *node _  x.f _  y.f _  z.f _  ux.f = 0.0 _  uy.f = 1.0 _  uz.f = 0.0 _  mode.l = #UH3_PARENT)
IMPORT_FUNCTION(uh3_SetNodePitch,  void, *node _  pitch.f _  mode.l = #UH3_LOCAL)
IMPORT_FUNCTION(uh3_SetNodeYaw,  void, *node _  yaw.f _  mode.l = #UH3_LOCAL)
IMPORT_FUNCTION(uh3_SetNodeRoll,  void, *node _  roll.f _  mode.l = #UH3_LOCAL)
IMPORT_FUNCTION(uh3_GetNodePositionX, .f,  *node)
IMPORT_FUNCTION(uh3_GetNodePositionY, .f,  *node)
IMPORT_FUNCTION(uh3_GetNodePositionZ, .f,  *node)
IMPORT_FUNCTION(uh3_GetNodeRotationX, .f,  *node)
IMPORT_FUNCTION(uh3_GetNodeRotationY, .f,  *node)
IMPORT_FUNCTION(uh3_GetNodeRotationZ, .f,  *node)
IMPORT_FUNCTION(uh3_GetNodeDirectionX, .f, *node)
IMPORT_FUNCTION(uh3_GetNodeDirectionY, .f, *node)
IMPORT_FUNCTION(uh3_GetNodeDirectionZ, .f, *node)
IMPORT_FUNCTION(uh3_GetNodeWorldDirectionX, .f, *node)
IMPORT_FUNCTION(uh3_GetNodeWorldDirectionY, .f, *node)
IMPORT_FUNCTION(uh3_GetNodeWorldDirectionZ, .f, *node)
IMPORT_FUNCTION(uh3_GetNodeWorldPositionX, .f, *node)
IMPORT_FUNCTION(uh3_GetNodeWorldPositionY, .f, *node)
IMPORT_FUNCTION(uh3_GetNodeWorldPositionZ, .f, *node)
IMPORT_FUNCTION(uh3_GetNodeWorldRotationX, .f, *node)
IMPORT_FUNCTION(uh3_GetNodeWorldRotationY, .f, *node)
IMPORT_FUNCTION(uh3_GetNodeWorldRotationZ, .f, *node)
IMPORT_FUNCTION(uh3_NodeCreateChild, .i, *node _  name.s _  type.l = #UH3_NODELOCAL)
IMPORT_FUNCTION(uh3_NodeCreateTemporaryChild, .i, *node _  name.s _  type.l = #UH3_NODELOCAL)
IMPORT_FUNCTION(uh3_NodeAttach, void, *nodeParent _  *nodeChild)
IMPORT_FUNCTION(uh3_NodeRemoveChild, void, *node _  *nodeToRemove)
IMPORT_FUNCTION(uh3_NodeRemoveAllChild, void, *node)
IMPORT_FUNCTION(uh3_NodeRemoveChildren, void, *node _  replicated.l _  local.l _  recursive.l)
IMPORT_FUNCTION(uh3_SetNodeParent, void, *node _  *parent)
IMPORT_FUNCTION(uh3_SetNodeEnabled, void, *node _  state.l) ;without recursion
IMPORT_FUNCTION(uh3_SetNodeDeepEnabled, void, *node _  state.l) ;with recursion

; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 44
; FirstLine = 27
; EnableXP