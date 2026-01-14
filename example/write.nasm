default rel

; i have copied my nasm include files
; to /asm/ --- you can also just change this
%include "/asm/stds.inc"

section .data
    ; example string
    String db "hello, world!", 10, 0
    String_len equ $ - String

section .text
    global _start

_start:
	; print
    print String

	; exit
    return 0

