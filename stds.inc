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

; ------------------------ ;
; --------if_* x y-------- ;

%macro endif 0
    fi
%endmacro

%macro else 0
    %if %$HAS_ELSE = 1
        %error "stds :> else used twice in the same if block"
    %endif
    %define %$HAS_ELSE 1
    jmp %$FI
%$ELSE:
%endmacro

%macro fi 0
    %if %$HAS_ELSE = 0
%$ELSE:     ; if there was no else, define the else label here
    %endif
%$FI:
    %pop
%endmacro

; --- condition starters ---
; each if_* opens a context and sets up shared labels

%macro if_eq 2
    %push if
    %define %$HAS_ELSE 0
    cmp %1, %2
    jne %$ELSE
%endmacro

%macro if_ne 2
    %push if
    %define %$HAS_ELSE 0
    cmp %1, %2
    je %$ELSE
%endmacro

%macro if_gt 2
    %push if
    %define %$HAS_ELSE 0
    cmp %1, %2
    jle %$ELSE
%endmacro

%macro if_lt 2
    %push if
    %define %$HAS_ELSE 0
    cmp %1, %2
    jge %$ELSE
%endmacro

%macro if_ge 2
    %push if
    %define %$HAS_ELSE 0
    cmp %1, %2
    jl %$ELSE
%endmacro

%macro if_le 2
    %push if
    %define %$HAS_ELSE 0
    cmp %1, %2
    jg %$ELSE
%endmacro

; unsigned < (below)
%macro if_bu 2
    %push if
    %define %$HAS_ELSE 0
    cmp %1, %2
    jae %$ELSE
%endmacro

; unsigned > (above)
%macro if_au 2
    %push if
    %define %$HAS_ELSE 0
    cmp %1, %2
    jbe %$ELSE
%endmacro
; ------------------------ ;

; printex <str> (manual _len)
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
