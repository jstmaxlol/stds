; _____________ ;
;  ______  __   ;
; (_  || \(_    ;
; __) ||_/__)   ;
; ------------- ;
; > while.inc   ;
; while sugar   ;
; for nasm!     ;
; _____________ ;

%macro done 0
    jmp %$LOOP
%$END:
    %pop
%endmacro

%macro while_eq 2
    %push while
%$LOOP:
    cmp %1, %2
    jne %$END
%endmacro

%macro while_ne 2
    %push while
%$LOOP:
    cmp %1, %2
    je %$END
%endmacro

%macro while_gt 2
    %push while
%$LOOP:
    cmp %1, %2
    jle %$END
%endmacro

%macro while_lt 2
    %push while
%$LOOP:
    cmp %1, %2
    jge %$END
%endmacro

%macro while_ge 2
    %push while
%$LOOP:
    cmp %1, %2
    jl %$END
%endmacro

%macro while_le 2
    %push while
%$LOOP:
    cmp %1, %2
    jg %$END
%endmacro

%macro while_bu 2      ; below (unsigned <)
    %push while
%$LOOP:
    cmp %1, %2
    jae %$END
%endmacro

%macro while_au 2      ; above (unsigned >)
    %push while
%$LOOP:
    cmp %1, %2
    jbe %$END
%endmacro

