#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	static char buf[1024];
	static int i;
	int w;

	if (c == -1 || i == 1024)
	{
		w = write(1, buf, i);
		if (w == -1)
			return (-1);
		i = 0;
	}

	if (c != -1)
		buf[i++] = c;

	return (1);
}

/**
 * print_string - prints a string
 * @str: string to print
 *
 * Return: number of characters printed, or -1 on error
 */
int print_string(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		if (_putchar(*str) == -1)
			return (-1);
		count++;
		str++;
	}
	return (count);
}

/**
 * print_number - prints an integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_number(int n)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		if (_putchar('-') == -1)
			return (-1);
		count++;
		num = (unsigned int)(-n);
	}
	else
	{
		num = (unsigned int)n;
	}

	if (num / 10)
	{
		int w = print_number(num / 10);

		if (w == -1)
			return (-1);
		count += w;
	}
	if (_putchar((num % 10) + '0') == -1)
		return (-1);
	count++;
	return (count);
}
/**
 * print_binary - prints an unsigned int in binary
 * @n: number to print
 *
 * Return: number of characters printed
 */
int print_binary(unsigned int n)
{
	int count = 0;
	int started = 0;
	unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);

	if (n == 0)
		return (_putchar('0'));

	while (mask)
	{
		if (n & mask)
		{
			if (_putchar('1') == -1)
				return (-1);
			count++;
			started = 1;
		}
		else if (started)
		{
			if (_putchar('0') == -1)
				return (-1);
			count++;
		}
		mask >>= 1;
	}
	return (count);
}
/**
 * print_S - prints a string, replacing non-printable chars
 *           with \x followed by two-digit uppercase hex code
 * @str: string to print
 *
 * Return: number of characters printed, or -1 on error
 */
int print_S(char *str)
{
	int count = 0, i;
	unsigned char c;
	char hex_digits[] = "0123456789ABCDEF";

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		c = (unsigned char)str[i];
		if ((c > 0 && c < 32) || c >= 127)
		{
			if (_putchar('\\') == -1 || _putchar('x') == -1)
				return (-1);
			count += 2;

			if (_putchar(hex_digits[c / 16]) == -1)
				return (-1);
			if (_putchar(hex_digits[c % 16]) == -1)
				return (-1);
			count += 2;
		}
		else
		{
			if (_putchar(c) == -1)
				return (-1);
			count++;
		}
	}
	return (count);
}
