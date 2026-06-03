default rel

%include "stds.inc"

section .data
    msg4 db `let           ==> OK!`, 10, 0
    msg0 db `prints        ==> OK!`, 10, 0
    msg1 db `if_*          ==> OK!`, 10, 0
    msg2 db `while_*       ==> OK!`, 10, 0
    msg3 db `for reg, n    ==> OK!`, 10, 0

    let dd, i1, 0

section .text
    global main

main:
    push rbp
    mov rbp, rsp

<<<<<<< HEAD
=======
    ; let tested in .data
>>>>>>> refs/remotes/origin/master
    printf "%s", msg4
    printf "%s", msg0

    mov eax, 2
    if eax, 2
        prints msg1
    fi

<<<<<<< HEAD
=======
    ; while_* test (i1 starts at 0, so while eq 1 won't run - that's correct)
>>>>>>> refs/remotes/origin/master
    mov eax, [i1]
    while eax, 1
        printf "%s", msg2
        inc dword [i1]
        mov eax, [i1]
    done

    ; for test
    for ebx, 1
        printf "%s", msg3
    rof ebx, 1

    printf `TESTS concluded\nALL *should* be fine :)\nAlso, 'printf' ==> OK!\n`

    xor eax, eax
    pop rbp
    ret
<<<<<<< HEAD

section .note.GNU-stack noalloc noexec nowrite progbits
=======
>>>>>>> refs/remotes/origin/master

section .note.GNU-stack noalloc noexec nowrite progbits
