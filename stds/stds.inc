;  ______  __ _  
; (_  || \(_   ) 
; __) ||_/__) /_ 
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

; ---------------------- ;
;      STDS MACROS       ;
; ---------------------- ;

; ------general.inc------ ;
%include "stds_general.inc"
; ----------------------- ;

; --------let.inc-------- ;
%include "stds_let.inc"
; ----------------------- ;

; ---------if.inc-------- ;
%include "stds_if.inc"
; ----------------------- ;

; -------while.inc------- ;
%include "stds_while.inc"
; ----------------------- ;

; --------for.inc-------- ;
%include "stds_for.inc"
; ----------------------- ;

