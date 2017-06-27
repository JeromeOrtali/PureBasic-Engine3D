;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
Global __UH3__SHARED_LIBRARY__

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
#UH3_GENERATE_EMPTY_DOC = #False 
#UH3_DOC_TAB            = Chr(9)

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
CompilerIf #UH3_GENERATE_EMPTY_DOC = #True 
  Debug "GENERATE DOC HTML !"
  Debug ""
  
  Global __UH3__HTMLDOC_FILE__  = OpenFile(#PB_Any,"doc.html")
  Global __UH3__HELP_STRING__.s = ""
  
  __UH3_PARAM__.s
  __UH3_DESC__.s
  __UH3_RETURN_DESC__.s
  
  Macro DOC(__LINE__)
    ;WriteString(__UH3__HTMLDOC_FILE__, __LINE__, #PB_UTF8)
    __UH3__HELP_STRING__ + __LINE__
;     Debug __LINE__
  EndMacro
  
  Macro DOCEOL()
    ;WriteStringN(__UH3__HTMLDOC_FILE__,#UH3_DOC_TAB + "<br/>")
    __UH3__HELP_STRING__ + #UH3_DOC_TAB + "<br/>" +  Chr(10) + Chr(13)
;     Debug ""
  EndMacro
  
  
CompilerEndIf


;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
CompilerIf #PB_Compiler_Processor = #PB_Processor_x86
  CompilerIf #PB_Compiler_OS = #PB_OS_Windows
  __UH3__SHARED_LIBRARY__ = OpenLibrary(#PB_Any,"bin/Engine3D.dll")
  CompilerElseIf #PB_Compiler_OS = #PB_OS_Linux
    MessageRequester("Erreur","ONLY WINDOWS!")
    End 
  CompilerElseIf #PB_Compiler_OS = #PB_OS_MacOS
    MessageRequester("Erreur","ONLY WINDOWS!")
    End 
  CompilerEndIf
CompilerEndIf

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
CompilerIf #PB_Compiler_Processor = #PB_Processor_x64
  MessageRequester("Erreur","ONLY X86!")
  End 
CompilerEndIf

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
Macro void
EndMacro

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
Macro QUOTE
"
EndMacro

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
Macro _
,  
EndMacro

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
Macro HELP_RETURN( _desc_ )
CompilerIf #UH3_GENERATE_EMPTY_DOC = #True 
  __UH3_RETURN_DESC__ = _desk_
CompilerEndIf
EndMacro

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
Macro HELP_DESC( _desc_ )
CompilerIf #UH3_GENERATE_EMPTY_DOC = #True 
  __UH3_DESC__ = _desc_
CompilerEndIf
EndMacro

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
Macro HELP_PARAM( _desc_ )
CompilerIf #UH3_GENERATE_EMPTY_DOC = #True 
  __UH3_PARAM__ = _desc_ + " _ "
CompilerEndIf
EndMacro

;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
Procedure HELP_WRITE_FILE()
CompilerIf #UH3_GENERATE_EMPTY_DOC = #True   
  
_begin.s = "<!DOCTYPE html>" + Chr(10)+Chr(13)
_begin + "<html>" + Chr(10)+Chr(13)
_begin + "<head>" + Chr(10)+Chr(13)
_begin + #UH3_DOC_TAB  +   "<meta charset="+Chr(34)+"utf-8"+Chr(34)+" />" + Chr(10)+Chr(13)
_begin + #UH3_DOC_TAB  +   "<link rel="+Chr(34)+"stylesheet"+Chr(34)+" href="+Chr(34)+"style.css"+Chr(34)+" />" + Chr(10)+Chr(13)
_begin + #UH3_DOC_TAB  +   "<title>PUREBASIC UH3 DOCUMENTION</title>" + Chr(10)+Chr(13)
_begin + "</head>" + Chr(10)+Chr(13)
_begin + "<body>" + Chr(10)+Chr(13)
  
_end.s = "</body>" 
_end.s = "</html>" 
  
  
  WriteString(__UH3__HTMLDOC_FILE__, _begin + __UH3__HELP_STRING__ + _end)
 
  CloseFile(__UH3__HTMLDOC_FILE__)
CompilerEndIf  
EndProcedure


;//////////////////////////////////////////////////////////////////////////////
;//
;//////////////////////////////////////////////////////////////////////////////
Macro IMPORT_FUNCTION(name, ret, param)
  PrototypeC#ret name(param)
  Global name.name = GetFunction(__UH3__SHARED_LIBRARY__,QUOTE#name#QUOTE)
  
  CompilerIf #UH3_GENERATE_EMPTY_DOC = #True 
    p$ = QUOTE#param#QUOTE
    p$ = ReplaceString(p$," ","")
    p$ = ReplaceString(p$,"_",",")
    p$ = ReplaceString(p$,","," , ")
    r$ = QUOTE#ret#QUOTE
    r$ = ReplaceString(r$," ","")
    r$ = r$ + " "
    n$ = QUOTE#name#QUOTE

    DOC("<div class="+Chr(34)+"left"+Chr(34)+"> <table style="+Chr(34)+"width:90%"+Chr(34)+"><table>  <tr> <th>")
    DOC("<span class = "+Chr(34)+"function"+Chr(34)+">"+ n$ + "</span>"+r$+"("+"<span class = "+Chr(34)+"parameters"+Chr(34)+">"+p$+"</span>)")
;     DOC("</th></tr>")
;     DOC("<tr><th>")
      DOC(__UH3_DESC__) : __UH3_DESC__ = ""
    DOC("</th></tr>")
    DOCEOL()
    
    If p$ <> ""      
       DOC("<tr><th>")
      DOC("Parameters :")
      DOCEOL()
      __UH3_PARAM__ = Mid(__UH3_PARAM__,1,Len(__UH3_PARAM__)-2)
      For i = 0 To CountString(p$,",")
        PH$ = StringField(__UH3_PARAM__, i+1,"_")
        DOC( "<span class = "+Chr(34)+"param"+Chr(34)+">"+#UH3_DOC_TAB + StringField(p$,i+1,",") + #UH3_DOC_TAB + "</span> = " + PH$)
        DOCEOL()
      Next 
      DOC("</th></tr>")
      __UH3_PARAM__ = ""
      DOCEOL()
      DOCEOL()
    Else
      DOCEOL()
      DOCEOL()
    EndIf 
    
    If r$ = " "
       DOC("<tr><th>")
      DOC("No return value")
      DOC("</th></tr>")
      DOCEOL()
      DOCEOL()
    Else 
      DOC("<tr><th>")
      DOC("Return value : " + r$)
      DOCEOL()
      DOC(__UH3_RETURN_DESC__) : __UH3_RETURN_DESC__ = ""
      DOC("</th></tr>")
      DOCEOL()
      DOCEOL()
    EndIf 
    DOC("</table>")
    DOC("</div>")

  CompilerEndIf
  
EndMacro




; IDE Options = PureBasic 5.60 (Windows - x86)
; CursorPosition = 46
; FirstLine = 15
; Folding = ---
; EnableXP