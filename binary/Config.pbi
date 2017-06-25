
Global __SHARED_LIBRARY__


CompilerIf #PB_Compiler_Processor = #PB_Processor_x86
  CompilerIf #PB_Compiler_OS = #PB_OS_Windows
  __SHARED_LIBRARY__ = OpenLibrary(#PB_Any,"bin/Engine3D.dll")
  CompilerElseIf #PB_Compiler_OS = #PB_OS_Linux
    MessageRequester("Erreur","ONLY WINDOWS!")
    End 
  CompilerElseIf #PB_Compiler_OS = #PB_OS_MacOS
    MessageRequester("Erreur","ONLY WINDOWS!")
    End 
  CompilerEndIf
CompilerEndIf

CompilerIf #PB_Compiler_Processor = #PB_Processor_x64
  MessageRequester("Erreur","ONLY X86!")
  End 
CompilerEndIf




Macro void
EndMacro

Macro QUOTE
"
EndMacro

Macro _
,  
EndMacro

Macro IMPORT_FUNCTION(name, ret, param)
  PrototypeC#ret name(param)
  Global name.name = GetFunction(__SHARED_LIBRARY__,QUOTE#name#QUOTE)
EndMacro
; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 37
; Folding = --
; EnableXP