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

; ------------------------ ;
;        FUNCTIONS         ;
; ------------------------ ;

section .text
    global strlen

strlen:
    xor rax, rax
.loop:
    cmp byte [rdi + rax], 0
    je .done
    inc rax
    jmp .loop
.done:
    ret


; ------------------------ ;
;       STDS MACROS        ;
; ------------------------ ;

; print <str>  (NUL-terminated)
%macro print 1
    lea rdi, [%1]      ; rdi = str
    push rdi           ; save pointer
    call strlen
    pop rsi            ; rsi = str
    mov rdx, rax       ; len
    mov rdi, 1         ; stdout
    mov rax, 1         ; sys_write
    syscall
%endmacro

; printex <str> (manual _len)
%macro printex 1
    mov rax, 1
    mov rdi, 1
    lea rsi, [%1]
    mov rdx, %1_len
    syscall
%endmacro

; return <code>
%macro return 1
    mov rax, 60
    mov rdi, %1
    syscall
%endmacro

