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
  #UH3_NODECOMPONENT_ANIMATIONCONTROLLER
  #UH3_NODECOMPONENT_ZONE
  
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
; Create new component for node, see #UH3_NODECOMPONENT_xxx where xxx is your component
; component constant are defined inside Node.pbi
; the return value is the component pointer
;
IMPORT_FUNCTION(uh3_CreateNodeComponent, .i , *node _ component.l )

; Get the component pointer of the node, if the node have multiple and same component
; the first component is returned
; the return value is the component pointer
;
IMPORT_FUNCTION(uh3_GetNodeComponent,.i, *node _ component.l)

; Get a child node by name, return the pointer of the node, overwise #null if failed
; you can search with recursivity if the node is inside another node ( sub-child search )
;
IMPORT_FUNCTION(uh3_GetNodeChildByName, .i, *node _ name.s _ recursive.b = #False)

; Get a child node by ID, return the pointer of the node, overwise #null if failed
; the ID is provided by the engine and visible inside the editor
;
;
IMPORT_FUNCTION(uh3_GetNodeChildByID, .i, *node _ id.l )

; Set node temporary, a temporary node is ignored when you save your scene
; usefull in case of you create an editor , for example , you wont save manipulator 3D , or icon 3D, etc... 
;
;
IMPORT_FUNCTION(uh3_SetNodeTemporary, void, state.l)

; Set node position in world space parent
;
IMPORT_FUNCTION(uh3_SetNodePosition, void , *node _ x.f _ y.f _ z.f )

; Translate node at (x,y,z) from current position , the mode can be local (#UH3_LOCAL, relative from himself)
; parent (#UH3_PARENT, relative from parent) or world (#UH3_WORLD, relative to world)
;
IMPORT_FUNCTION(uh3_NodeTranslate, void , *node _ x.f _ y.f _ z.f _ mode.l = #UH3_LOCAL)

; Set node rotation in euler angle (0,360°) 
;
IMPORT_FUNCTION(uh3_SetNodeRotation, void , *node _ x.f _ y.f _ z.f )

; Rotate node from current angle, the mode can be local (#UH3_LOCAL, relative from himself)
; parent (#UH3_PARENT, relative from parent) or world (#UH3_WORLD, relative to world)
;
IMPORT_FUNCTION(uh3_NodeRotate, void , *node _ x.f _ y.f _ z.f _ mode.l = #UH3_LOCAL )

; Set node direction , for example for UP direction : 0,1,0 , DOWN : 0,-1,0
;
IMPORT_FUNCTION(uh3_SetNodeDirection,  void, *node _  x.f _  y.f _  z.f)

; Scale the node with the scale value , all directions are scaled at the same value
; a scale of 1.0 is the original scale, with 0.5, you divide the scale by 2
;
IMPORT_FUNCTION(uh3_SetNodeUniformScale,  void, *node _  scale.f)

; Scale the node with the x,y,z value for each direction
; a scale of 1.0 is the original scale, with 0.5, you divide the scale by 2
;
IMPORT_FUNCTION(uh3_SetNodeScale,  void, *node _ x.f _  y.f _  z.f)

; Set the node position in world coordinate
;
IMPORT_FUNCTION(uh3_SetNodeWorldPosition,  void, *node _  x.f _  y.f _  z.f)

; turn a node to look at position (x,y,z) , the UP vector can be define with (ux,uy,uz) usualy 0,1,0
; the mode can be local (#UH3_LOCAL, relative from himself)
; parent (#UH3_PARENT, relative from parent) or world (#UH3_WORLD, relative to world)
;
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
; CursorPosition = 64
; FirstLine = 77
; EnableXP