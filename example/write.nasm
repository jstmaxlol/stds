default rel

; i have copied my nasm include files
; to /asm/ --- you can also just change this
%include "/asm/stds.inc"

section .data
    ; example string
    string db "hello, world!", 10, 0

section .text
    global _start

_start:
	; print
    print string

	; exit
    return 0

