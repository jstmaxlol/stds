default rel

%include "/asm/stds.inc"

; -------------- ;
;    test for    ;
;  ______  __    ;
; (_  || \(_  /| ;
; __) ||_/__)  | ;
; -------------- ;
; simple, bad,   ;
; suckful tests  ;
; for STDS 1 :)  ;
; -------------- ;

section .data
    msg1 db `if(_eq) works.. and 2 = 2!\n`

section .text
    global _start

_start:

    mov rax, 2

    if_eq rax, 2
        print msg1
    fi

    ; for loop test

    return 0

