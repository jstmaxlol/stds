; _____________ ;
;  ______  __   ;
; (_  || \(_    ;
; __) ||_/__)   ;
; ------------- ;
; > printf.inc  ;
; fancy printf  ;
; for nasm!     ;
; _____________ ;

extern stds_printf

%macro _pcall 0
    push rbp
    mov rbp, rsp
    and rsp, ~15
    xor eax, eax
    call stds_printf
    mov rsp, rbp
    pop rbp
%endmacro

%macro printf 1
    %push printf_ctx
    section .rodata
%%fmt:  db %1, 0
    section .text
    lea rdi, [rel %%fmt]
    _pcall
    %pop
%endmacro

%macro printf 2
    %push printf_ctx
    section .rodata
%%fmt:  db %1, 0
    section .text
    lea rdi, [rel %%fmt]
    mov rsi, %2
    _pcall
    %pop
%endmacro

%macro printf 3
    %push printf_ctx
    section .rodata
%%fmt:  db %1, 0
    section .text
    lea rdi, [rel %%fmt]
    mov rsi, %2
    mov rdx, %3
    _pcall
    %pop
%endmacro

%macro printf 4
    %push printf_ctx
    section .rodata
%%fmt:  db %1, 0
    section .text
    lea rdi, [rel %%fmt]
    mov rsi, %2
    mov rdx, %3
    mov rcx, %4
    _pcall
    %pop
%endmacro

%macro printf 5
    %push printf_ctx
    section .rodata
%%fmt:  db %1, 0
    section .text
    lea rdi, [rel %%fmt]
    mov rsi, %2
    mov rdx, %3
    mov rcx, %4
    mov r8, %5
    _pcall
    %pop
%endmacro
