#include "main.h"

/**
 * handle_char_str - handles c and s specifiers
 * @format: format character
 * @args: argument list
 *
 * Return: number of characters printed or -1 on error
 */
int handle_char_str(char format, va_list args)
{
	int w;

	if (format == 'c')
		return (_putchar(va_arg(args, int)));

	if (format == 's')
	{
		w = print_string(va_arg(args, char *));
		return (w);
	}

	return (0);
}

/**
 * handle_numbers - handles d, i, u, o, x, X specifiers
 * @format: format character
 * @args: argument list
 *
 * Return: number of characters printed or -1 on error
 */
int handle_numbers(char format, va_list args)
{
	int w = 0;

	if (format == 'd' || format == 'i')
		w = print_number(va_arg(args, int));
	else if (format == 'u')
		w = print_uint(va_arg(args, unsigned int));
	else if (format == 'o')
		w = print_octal(va_arg(args, unsigned int));
	else if (format == 'x')
		w = print_hex(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		w = print_hex(va_arg(args, unsigned int), 1);

	return (w);
}
