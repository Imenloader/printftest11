#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
int Chars_Print = 0;
va_list List_Of_Arguments;
if (format == NULL)
{
return (-1);
}
va_start(List_Of_Arguments, format);
while (*format)
{
if (*format != '%')
{
write(1, format++, 1);
Chars_Print++;
}
else
{
switch (*++format)
{
case '%':
write(1, "%", 1);
Chars_Print++;
break;
case 'c':
write(1, &va_arg(List_Of_Arguments, int), 1);
Chars_Print++;
break;
case 's':
{
char *string = va_arg(List_Of_Arguments, char *);
int length = strlen(string);
write(1, string, length);
Chars_Print += length;
break;
}
}
}
}
va_end(List_Of_Arguments);
return (Chars_Print);
}
