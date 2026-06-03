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
    msg0 db `prints        ==> OK!\n\0`
    msg1 db `if_*          ==> OK!\n\0`
    msg2 db `while_*       ==> OK!\n\0`
    msg3 db `for reg, n    ==> OK!\n\0`

    ; other variables
    let dd, i1, 0

section .text
    global _start

_start:
    
    ; let tested in .data
    printf "%s", msg4
    printf "%s", msg0

    ; if_* test
    mov eax, 2
    if eax, 2
        prints msg1
    fi
    
    ; while_* test
    mov eax, [i1]
    while eax, 1
        printf "%s", msg2
        inc dword [i1]
        mov eax, [i1]
    done

    ; for *,* test
    for ebx, 1
        printf "%s", msg3
    rof ebx, 1

;    for ebx, 6
;        for ecx, 2
;            printf "--"
;        rof ecx, 3
;        printf "> %d\n", ebx
;    rof ebx, 6

    printf "TESTS concluded\nALL *should* be fine :)\nAlso, 'printf' ==> OK!\n"

    return 0

