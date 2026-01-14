#!/usr/bin/env bash

if [[ $# -lt 1 ]]; then                                          
    printf "usage: nas FILEi [FILEo]\n"
    printf "(!) if FILEo not specified, FILEi will be used.\n"
    exit 1
elif [[ $# -ge 2 ]]; then                                         
    if [[ "$1" =~ ^-h(elp)?$ || "$1" =~ ^--help$ ]]; then
        # usage                                                   
        printf "usage: nas FILEi [FILEo]\n"
        printf "(!) if FILEo not specified, FILEi will be used.\n"
        exit 0
    else                                                          
        # assemble
        printf ":> compiling \"%s\" (output=\"%s\")\n" "$1" "$2"
        nasm -felf64 $1 -o $1.o && ld $1.o -o $2 && rm $1.o
        exit 0
    fi
else
    if [[ "$1" =~ ^-h(elp)?$ || "$1" =~ ^--help$ ]]; then
        # usage                                                   
        printf "usage: nas FILEi [FILEo]\n"
        printf "(!) if FILEo not specified, FILEi will be used.\n"
        exit 0
    else                                                          
        printf "(!) warning: FILEo not specified. using FILEi (\"%s\") as output FILE\n" "$1"
        printf ":> compiling \"%s\" (output=\"%s\")\n" "$1" "$1"
        nasm -felf64 $1 -o $1.o && ld $1.o -o $1 && rm $1.o
        exit 2
    fi
fi
