// printf.c|o
// _____________ /
//  ______  __   /
// (_  || \(_    /
// __) ||_/__)   /
// ------------- /
// > vprintf.c|o /
// fancy printf  /
// linkage :)    /
// thanks so fkn /
// much to MUSL! /
// _____________ /

// => /usr/lib/musl/include/stdio.h
#include <stdio.h>
#include <stdarg.h>

int stds_printf(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int r = vprintf(fmt, ap);
    va_end(ap);
    return r;
}

