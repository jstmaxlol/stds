# STDS 2
**STDS** (`S`_imple_ _s_`T`_andar_`D` `S`_tuff_) \
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
    lea rdi, [%1]
    call strlen
    mov rdx, rax
    mov rsi, rdi
    mov rdi, 1
    mov rax, 1
    syscall
%endmacro
```
this has been chosen for both **speed** and **functionality** \
(_fake, i just hate actual 'functions' in assembly_)

# API
### `print`
to use `print` you have to declare a string. \
**stds** assumes that the caller has already enabled `default rel` \
before `%include`-ing the file. --- if this is not true, issues may arise.
example usage:
```nasm
default rel
%include "stds.inc"
; ...

; in section .data you are going to have
    string db "hello, world!", 10, 0

; in _start you are going to have
    print string
```
### `printex`
to use `printex` (for **printex**plicit) you have to declare a string **+ its length.** \
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
    printex string
```

### `return`
very simple and minimal. just `return <number>` like you would in C.

# FEATURES
- `if_* x y`, `else`: almost real `if`/`else` chains in nasm! \
i know `%if` exists but it was cool to make nonetheless) \
syntax:
```nasm
mov rax, 2
if_eq rax, 2
    ; stuff
else
    ; other stuff
fi
```

- `while_*`: very similar to `if_*` \
syntax:
```nasm
mov rax, 2
while_eq rax, 2
    ; stuff
done
```

- `for reg, count`: a simple for-n iterator \
(!) you must specify a register to store 'i' \
syntax:
```nasm
mov rax, 0
for eax, 420
    inc rax
rof
```

- `let size, var, data`: beautyfication of normal 'variable' declaration \
(!) expands to a data declaration and must be used in `section .data` \
syntax:
```nasm
let dd, x, 2
; expands to x dd 2
```
(?) there also is `let*` as in `letd x, 2` will expand to `x dd 2` \
(?) `lets` is available and it defaults to _what i decided is_ the \
&nbsp;&nbsp;the most common data size (dword) --- it is used as follows:
```nasm
lets x, 2
```
(?) there is `letz` for `.bss` too.

