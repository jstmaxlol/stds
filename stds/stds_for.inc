; _____________ ;
;  ______  __   ;
; (_  || \(_    ;
; __) ||_/__)   ;
; ------------- ;
; > for.inc     ;
; for sugar for ;
; netwide asm!  ;
; _____________ ;

%macro for 1
    %push for
    %define %$I 0
    %define %$N %1
%$LOOP:
    cmp %$I, %$N
    jge %$END
%endmacro

%macro rof 0
    inc %$I
    jmp %$LOOP
%$END:
    %pop
%endmacro

