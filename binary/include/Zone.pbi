XIncludeFile "Config.pbi"

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////

IMPORT_FUNCTION(uh3_SetZoneSize,void,*zone _ minx.f _ miny.f _ minz.f _ maxx.f _ maxy.f _ maxz.f)
IMPORT_FUNCTION(uh3_SetZoneAmbientColor,void,*zone _ color.l)
IMPORT_FUNCTION(uh3_SetZoneFogColor,void,*zone _ color.l)
IMPORT_FUNCTION(uh3_SetZoneFogStart,void,*zone _ fogStart.f)
IMPORT_FUNCTION(uh3_SetZoneFogEnd,void,*zone _ fogEnd.f)
; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 6
; EnableXP