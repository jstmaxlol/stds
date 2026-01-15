; _____________ ;
;  ______  __   ;
; (_  || \(_    ;
; __) ||_/__)   ;
; ------------- ;
; > let.inc     ;
; let var data  ;
; candy for thy ;
; netwide asm!  ;
; _____________ ;

%macro let 3
    %2 %1 %3
%endmacro

%macro letb 2
    %1 db %2
%endmacro

%macro letw 2
    %1 dw %2
%endmacro

%macro letd 2
    %1 dd %2
%endmacro

%macro letq 2
    %1 dq %2
%endmacro

%macro letz 1
    %1 resd 1
%endmacro

%macro lets 2
    %1 dd %2
%endmacro
