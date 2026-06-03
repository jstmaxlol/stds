; _____________ ;
;  ______  __   ;
; (_  || \(_    ;
; __) ||_/__)   ;
; ------------- ;
; > printf.inc  ;
; fancy printf  ;
; for nasm!     ;
; _____________ ;

extern printf

%macro printf 1+
    lea rdi, [%1]
    call printf
%endmacro

