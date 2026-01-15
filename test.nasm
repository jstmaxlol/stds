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
    msg4 db `let           ==> OK!\n\0`
    msg0 db `print         ==> OK!\n\0`
    msg1 db `if_*          ==> OK!\n\0`
    msg2 db `while_*       ==> OK!\n\0`
    msg3 db `for reg, n    ==> OK!\n\0`

    ; other variables
    let dd, i1, 0

section .text
    global _start

_start:
    
    ; let tested in .data
    print msg4
    print msg0

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
    rof ebx, 1

    ;printn i1

    return 0

