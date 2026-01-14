;  ______  __
; (_  || \(_  /|
; __) ||_/__)  |
; -----------------------------------------
; STDS (Simple sTandarD Stuff)
; => a minimal std library for nasm heads!
; copyleft --- czjstmax <jstmaxlol@disroot.org>, <github.com/jstmaxlol>
; -----------------------------------------
;
; RECOMMENDATIONS UND STUFF:
; > put this file into /usr/include/asm/ or any other include directory.
; > use my utility bash script ('nas.sh', found in this repo) to compile nasm faSHt.
; ...to add more stuff!
;
; -----------------------------------------
; working on this as a side-project to spend time and learn more
; about NASM (and generally assembly) development :)
; -----------------------------------------
; to include a file into a .nasm source file:
; %include "path/to/stds.inc"
; -----------------------------------------

default rel

; print <str>
%macro print 1
    mov rax, 1
    mov rdi, 1
    lea rsi, [%1]
    mov rdx, %1_len
    syscall
%endmacro

; return <int>
%macro return 1
    mov rax, 60
    mov rdi, %1
    syscall
%endmacro
