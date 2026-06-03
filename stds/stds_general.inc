; _____________ ;
;  ______  __   ;
; (_  || \(_    ;
; __) ||_/__)   ;
; ------------- ;
; > general.inc ;
; general macros;
; _____________ ;

; print "str"
%macro print 1
    %push print
    section .rodata
%%str:
    db %1, 0
    section .text
    print %%str
    %pop
%endmacro

; prints [str]
%macro prints 1
    lea rdi, [%1]
    push rdi 
    call strlen
    pop rsi
    mov rdx, rax
    mov rdi, 1
    mov rax, 1
    syscall
%endmacro

; printex [str]
%macro printex 1
    mov rax, 1
    mov rdi, 1
    lea rsi, [%1]
    mov rdx, %1_len
    syscall
%endmacro

; exit <code>
%macro exit 1
    mov rax, 60
    mov rdi, %1
    syscall
%endmacro
; alias for muscle-memory
%macro return 1
    exit %1
%endmacro

