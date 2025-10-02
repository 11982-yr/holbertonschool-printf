#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int handle_char_str(char format, va_list args);
int handle_numbers(char format, va_list args);
int print_string(char *str);
int print_number(int n);
int print_uint(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n, int uppercase);
int print_binary(unsigned int n);
int print_S(char *str);

#endif /* MAIN_H */
