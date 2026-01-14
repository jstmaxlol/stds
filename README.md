# STDS
**STDS** (**S**_imple_ _s_**T**_andar_**D** **S**_tuff_) \
=> a minimal std library for nasm heads! \
copyleft --- czjstmax <jstmaxlol@disroot.org>, <github.com/jstmaxlol> \

&nbsp;&nbsp; working on this as a side-project to spend time and learn more \
about NASM (and generally assembly) development :)

## RECOMMENDATIONS UND STUFF:
- put this file into `/usr/include/asm/` or any other include directory.
- use my utility bash script ('nas.sh', found in this repo) to compile nasm faSHt.
...to add more stuff!

# PHILOSOPHIE
- linux first, always.
- every 'function' is *de facto* a `%macro..%endmacro` block:
```nasm
%macro print 1
    mov rax, 1
    mov rdi, 1
    lea rsi, [%1]
    mov rdx, %1_len
    syscall
%endmacro
```
this has been chosen for both **speed** and **functionality** \
(_fake, i just hate actual 'functions' in assembly_)

# API
### `print`
to use `print` you have to declare a string + its length. \
**stds** assumes that the caller has already enabled `default rel` \
before `%include`-ing the file. --- if this is not true, issues may arise.
example usage:
```nasm
default rel
%include "stds.inc"
; ...

; in section .data you are going to have
    string db "hello, world!", 10, 0
    ; the name for the length of the string
    ; *must* be the string's name (label) +
    ; _len, in our case, string_len:
    string_len equ $ - string

; in _start you are going to have
    print string
```

### `return`
very simple and minimal. just `return <number>` like you would in C.

