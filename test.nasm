default rel

%include "stds.inc"

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
    ; strings
    msg4 db `let           ==> OK!\n`
    msg0 db `print         ==> OK!\n`
    msg1 db `if_*          ==> OK!\n`
    msg2 db `while_*       ==> OK!\n`
    msg3 db `for reg, n    ==> OK!\n`

    ; other variables
    lets i1, 1

section .text
    global _start

_start:
    
    ; let tested in .data
    print msg4

    ; if_* test
    mov eax, 2
    if_eq eax, 2
        print msg1
    fi
    
    ; while_* test
    mov eax, [i1]
    while_lt eax, 1
        print msg2
        inc dword [i1]
        mov eax, [i1]
    done

    ; for *,* test
    for ebx, 1
        print msg3
    rof

    ;printn i1

    return 0

