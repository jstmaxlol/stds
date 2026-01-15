; _____________ ;
;  ______  __   ;
; (_  || \(_    ;
; __) ||_/__)   ;
; ------------- ;
; > for.inc     ;
; for sugar for ;
; netwide asm!  ;
; _____________ ;

%macro for 2
    %push for
    xor %1, %1
    jmp %$CHECK
%$LOOP:
%endmacro

%macro rof 2
    inc %1
%$CHECK:
    cmp %1, %2
    jl %$LOOP
%$END:
    %pop
%endmacro

