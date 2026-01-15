; _____________ ;
;  ______  __   ;
; (_  || \(_    ;
; __) ||_/__)   ;
; ------------- ;
; > if.inc      ;
; if sugar for  ;
; netwide asm!  ;
; _____________ ;

%macro endif 0
    fi
%endmacro

%macro else 0
    %if %$HAS_ELSE = 1
        %error "stds :> else used twice in the same if block"
    %endif
    %define %$HAS_ELSE 1
    jmp %$FI
%$ELSE:
%endmacro

%macro fi 0
    %if %$HAS_ELSE = 0
%$ELSE:     ; if there was no else, define the else label here
    %endif
%$FI:
    %pop
%endmacro

; --- condition starters --- ;
; each if_* opens a context and sets up shared labels

%macro if_eq 2
    %push if
    %define %$HAS_ELSE 0
    cmp %1, %2
    jne %$ELSE
%endmacro

%macro if_ne 2
    %push if
    %define %$HAS_ELSE 0
    cmp %1, %2
    je %$ELSE
%endmacro

%macro if_gt 2
    %push if
    %define %$HAS_ELSE 0
    cmp %1, %2
    jle %$ELSE
%endmacro

%macro if_lt 2
    %push if
    %define %$HAS_ELSE 0
    cmp %1, %2
    jge %$ELSE
%endmacro

%macro if_ge 2
    %push if
    %define %$HAS_ELSE 0
    cmp %1, %2
    jl %$ELSE
%endmacro

%macro if_le 2
    %push if
    %define %$HAS_ELSE 0
    cmp %1, %2
    jg %$ELSE
%endmacro

; unsigned < (below)
%macro if_bu 2
    %push if
    %define %$HAS_ELSE 0
    cmp %1, %2
    jae %$ELSE
%endmacro

; unsigned > (above)
%macro if_au 2
    %push if
    %define %$HAS_ELSE 0
    cmp %1, %2
    jbe %$ELSE
%endmacro

