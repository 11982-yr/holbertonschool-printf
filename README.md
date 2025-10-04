# holbertonschool-printf

A minimal re-implementation of `printf` that supports `%c`, `%s`, `%%`, `%d`, `%i`, `%b`, `%u`, `%o`, `%x`, `%X`, `%S`, and `%p`
## Prototype
```c
int _printf(const char *format, ...);
```
## Description

The **_printf** project is a custom implementation of the C standard library function `printf`.
Its purpose is to reproduce the behavior of `printf` by handling format specifiers and writing formatted output to the standard output stream (stdout).

This function takes a **format string** and a **variable number of arguments**.
The format string can contain:

- **Ordinary characters**, which are printed as they are.
- **Conversion specifiers** (introduced by `%`), which determine how the corresponding argument is formatted and printed.

Unlike the standard library version, this project focuses only on a subset of conversion specifiers.
It does **not** handle field width, precision, flags, or length modifiers.

### Supported Specifiers

- `%c` : Prints a single character

- `%s` : Prints a string

- `%%` : Prints a literal percent sign

- `%d` : Prints a signed decimal integer

- `%i` : Prints a signed decimal integer

- `%b` : Prints an unsigned integer in binary (base 2)

- `%u` : Prints an unsigned decimal integer

- `%o` : Prints an unsigned integer in octal (base 8)

- `%x` : Prints an unsigned integer in lowercase hexadecimal (base 16)

- `%X` : Prints an unsigned integer in uppercase hexadecimal (base 16)

- `%S` : Prints a string, but non-printable characters (ASCII value < 32 or ≥ 127) are displayed as \xHHwhere HH is the uppercase hexadecimal code of the character.

- `%p` : Prints a pointer (memory address) in hexadecimal format, prefixed with 0x. A null pointer is printed as (nil).

### Return Value

On success, `_printf` returns the number of characters printed (excluding the null byte).
On error, it returns `-1`.

### Example Usage
```c
_printf("First letter: %c\n", 'A');
_printf("Hello %s! Number: %d%%\n", "Yara and Najla", 42);
_printf("Binary: %b\n", 42);
_printf("Unsigned/Octal: %u | %o\n", 1024, 255);
_printf("Hex: %x | %X\n", 255, 255);
_printf("%S\n", "Best\nSchool");
_printf("Pointer: %p\n", (void *)0x7ffe637541f0);
```
- **Output**
```c 
First letter: A
Hello Yara and Najla! Number: 42%
Binary: 101010
Unsigned/Octal: 1024 | 377
Hex: ff | FF
Best\x0ASchool
Pointer: 0x7ffe637541f0
```
### Authors
Yara Khalid Alrasheed & Najla Abdulaziz Alajaleen


