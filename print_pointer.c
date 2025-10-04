#include "main.h"

/**
 * print_pointer - prints a memory address (void *) in hex with 0x prefix
 * @ptr: pointer to print
 *
 * Return: number of characters printed
 */

int print_pointer(void *ptr)
{
	unsigned long addr;
	int count = 0;

	if (ptr == NULL)
		return (print_string("(nil)"));

	addr = (unsigned long)ptr;

	if (_putchar('0') == -1 || _putchar('x') == -1)
		return (-1);
	count += 2;

	count += print_hex(addr, 0);

	return (count);
}
