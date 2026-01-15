#!/usr/bin/env bash

if [[ $# -lt 1 ]]; then
    printf "usage: nas iFILE [oFILE [options]]\n"
    printf "(!) if oFILE not specified, iFILE will be used.\n\n"
    printf "options:\n-I, --include <where? what?>\n-h, --help: shows this screen\n"
    exit 1
elif [[ $# -ge 2 ]]; then
    if [[ "$1" =~ ^-h(elp)?$ || "$1" =~ ^--help$ ]]; then
        # usage
        printf "usage: nas iFILE [oFILE]\n"
        printf "(!) if oFILE not specified, iFILE will be used.\n"
        exit 0
    elif [[ "$3" =~ ^-I(nclude)?$ || "$3" =~ ^--include$ ]]; then
        # assemble with -I (nas ifile ofile -I dir)
        printf ":> ^-I(include)?$ | ^--include$ (%s) parsed.\n" "$3"
        printf ":> using %s as include directory.\n" "$4"
        printf ":> compiling \"%s\" (output=\"%s\")\n" "$1" "$2"
        nasm -felf64 $1 -o $1.o -I $4 \
            && ld $1.o -o $2 \
            && rm $1.o
        exit 0
    else                                                          
        # assemble
        printf ":> compiling \"%s\" (output=\"%s\")\n" "$1" "$2"
        nasm -felf64 $1 -o $1.o \
            && ld $1.o -o $2 \
            && rm $1.o
        exit 0
    fi
else
    if [[ "$1" =~ ^-h(elp)?$ || "$1" =~ ^--help$ ]]; then
        # usage                                                   
        printf "usage: nas iFILE [oFILE]\n"
        printf "(!) if oFILE not specified, iFILE will be used.\n"
        exit 0
    else                                                          
        printf "(!) warning: oFILE not specified. using iFILE (\"%s\") as output FILE\n" "$1"
        printf ":> compiling \"%s\" (output=\"%s\")\n" "$1" "$1"
        nasm -felf64 $1 -o $1.o && ld $1.o -o $1 && rm $1.o
        exit 2
    fi
fi
