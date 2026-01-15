default rel

%include "stds/stds.inc"

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
    ln db `\n`
    tab db `\t`
    msg1 db `if(_eq) works.. and 2 = 2!\n`
    msg2 db `while(_eq) works! (you should see this twice)\t`

    ; other variables
    i1 dd 1

section .text
    global _start

_start:

    mov eax, 2

    if_eq eax, 2
        print msg1
    fi
    
    ; while as a for-esque-loop
    mov eax, [i1]
    while_lt eax, 2
        print msg2
        inc dword [i1]
        mov eax, [i1]
    done
    print ln

    ; for-loop

    return 0

