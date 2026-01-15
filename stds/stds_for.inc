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
%$LOOP:
    cmp %1, %2
    jge %$END
%endmacro

%macro rof 1
    inc %1
    jmp %$LOOP
%$END:
    %pop
%endmacro

