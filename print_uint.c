#include "main.h"

/**
 * print_uint - prints an unsigned int in decimal
 *
 * @n: number to print.
 *
 * Return: number of characters printed.
 */

int print_uint(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += print_uint(n / 10);

	if (_putchar((n % 10) + '0') == -1)
		return (-1);

	return (count + 1);
}
