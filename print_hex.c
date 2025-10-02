#include "main.h"

/**
 * print_hex - prints an unsigned int in hexadecimal
 * @n: number to print
 * @uppercase: flag, if 1 use uppercase letters, else lowercase
 *
 * Return: number of characters printed
 */
int print_hex(unsigned int n, int uppercase)
{
	int count = 0;
	char *digits;

	digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (n / 16)
		count += print_hex(n / 16, uppercase);

	if (_putchar(digits[n % 16]) == -1)
		return (-1);

	return (count + 1);
}

