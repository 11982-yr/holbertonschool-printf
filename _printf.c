#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
            {
                va_end(args);
                return (-1);
            }

            if (*format == 'c')
            {
                if (_putchar(va_arg(args, int)) == -1)
                {
                    va_end(args);
                    return (-1);
                }
                count++;
            }
            else if (*format == 's')
            {
                int w = print_string(va_arg(args, char *));
                if (w == -1)
                {
                    va_end(args);
                    return (-1);
                }
                count += w;
            }
            else if (*format == '%')
            {
                if (_putchar('%') == -1)
                {
                    va_end(args);
                    return (-1);
                }
                count++;
            }
            else
            {
                if (_putchar('%') == -1 || _putchar(*format) == -1)
                {
                    va_end(args);
                    return (-1);
                }
                count += 2;
            }
        }
        else
        {
            if (_putchar(*format) == -1)
            {
                va_end(args);
                return (-1);
            }
            count++;
        }
        format++;
    }

    va_end(args);
    return (count);
}
