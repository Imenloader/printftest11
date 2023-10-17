#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
/**
 * _printf_char - Print a character.
 * @format: Format string.
 * @list: Variable argument list.
 * Return: Number of characters printed.
 */
int _printf_char(const char *format, va_list *list)
{
char character = va_arg(*list, int);
write(1, &character, 1);
return (1);
}
/**
 * _printf_string - Print a string.
 * @format: Format string.
 * @list: Variable argument list.
 * Return: Number of characters printed.
 */
int _printf_string(const char *format, va_list *list)
{
char *string = va_arg(*list, char *);
write(1, string, strlen(string));
return (strlen(string));
}
/**
 * _printf - Printf function.
 * @format: Format string.
 * ...: Variable arguments.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
int characters_printed = 0;
va_list list;
va_start(list, format);
while (*format)
{
if (*format != '%')
{
write(1, format, 1);
characters_printed++;
}
else
{
format++;
switch (*format)
{
case '%':
write(1, format, 1);
characters_printed++;
break;
case 'c':
characters_printed += _printf_char(format, &list);
break;
case 's':
characters_printed += _printf_string(format, &list);
break;
}
}
format++;
}
va_end(list);
return (characters_printed);
}
