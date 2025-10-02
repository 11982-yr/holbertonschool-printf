#include "main.h"

/**
 * handle_specifier - Handles a format specifier
 * @format: format character
 * @args: list of arguments
 *
 * Return: number of characters printed, -1 on error
 */
int handle_specifier(char format, va_list args)
{
	int count = 0, w;

	if (format == 'c')
		count += _putchar(va_arg(args, int));
	else if (format == 's')
	{
		w = print_string(va_arg(args, char *));
		if (w == -1)
			return (-1);
		count += w;
	}
	else if (format == 'd' || format == 'i')
	{
		w = print_number(va_arg(args, int));
		if (w == -1)
			return (-1);
		count += w;
	}
	else if (format == '%')
		count += _putchar('%');
	else if (format == 'b')
	{
		w = print_binary(va_arg(args, unsigned int));
		if (w == -1)
			return (-1);
		count += w;
	}
	else if (format == 'u')
	{
		w = print_uint(va_arg(args, unsigned int));
		if (w == -1)
			return (-1);
		count += w;
	}
	else if (format == 'o')
	{
		w = print_octal(va_arg(args, unsigned int));
		if (w == -1)
			return (-1);
		count += w;
	}
	else if (format == 'x')
	{
		w = print_hex(va_arg(args, unsigned int), 0);
		if (w == -1)
			return (-1);
		count += w;
	}
	else if (format == 'X')
	{
		w = print_hex(va_arg(args, unsigned int), 1);
		if (w == -1)
			return (-1);
		count += w;
	}
	else
	{
		count += _putchar('%');
		count += _putchar(format);
	}
	return (count);
}

/**
 * _printf - Produces output according to a format
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, w;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
			w = handle_specifier(*format, args);
			if (w == -1)
				return (-1);
			count += w;
		}
		else
		{
			if (_putchar(*format) == -1)
				return (-1);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}
