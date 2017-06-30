XIncludeFile "Config.pbi"

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////

Enumeration ; Texture format
  #UH3_TEXTURE_RGB  
  #UH3_TEXTURE_RGBA  
EndEnumeration


Enumeration ; TextureUsage
  #UH3_TEXTURE_STATIC  
  #UH3_TEXTURE_DYNAMIC
  #UH3_TEXTURE_RENDERTARGET
  #UH3_TEXTURE_DEPTHSTENCIL
EndEnumeration

Enumeration ; Texture filter mode
  #UH3_FILTER_NEAREST  
  #UH3_FILTER_BILINEAR
  #UH3_FILTER_TRILINEAR
  #UH3_FILTER_ANISOTROPIC
  #UH3_FILTER_DEFAULT
EndEnumeration


;
; Texture2D Function
;
IMPORT_FUNCTION(uh3_CreateTexture2D,.i, width.l _ height.l _ format.l = #UH3_TEXTURE_RGBA _ level.l = 1 _ usage.l = #UH3_TEXTURE_STATIC)
IMPORT_FUNCTION(uh3_FreeTexture2D,void, *texture2D)
IMPORT_FUNCTION(uh3_SetTexture2DData,.l, *texture2D _ x.l _ y.l _ width.l _ height.l _ level.l _ *pixels)
IMPORT_FUNCTION(uh3_GetTexture2DData,void, *texture2D _ level.l _ *pixelsDestination)
IMPORT_FUNCTION(uh3_GetTexture2DRenderSurface,.i, *texture2D )
IMPORT_FUNCTION(uh3_SetTextureFilterMode,void, *texture2D _ mode.l)


;
; Texture common function
;
IMPORT_FUNCTION(uh3_SetTextureName,void, *texture _ name.s )
IMPORT_FUNCTION(uh3_SetRenderSurfaceViewport,void, *surface _ index.l _ *viewport) ; see uh3_GetTexture2DRenderSurface, used for RTT



; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 27
; EnableXP