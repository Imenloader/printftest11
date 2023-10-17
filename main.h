#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*Mandatory functions*/
int _printf(const char *format, ...);
int op_ch(va_list arg);
int op_st(va_list arg);
int op_nu(va_list arg);


#endif /* MAIN_H */
