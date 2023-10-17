#include "main.h"
/**
* _printf_char - Print a character.
* @list: Variable argument list.
* Return: Number of characters printed.
*/
int _printf_char(va_list *list)
{
char character = va_arg(*list, int);
write(1, &character, 1);
return (1);
}

/**
* _printf_string - Print a string.
* @list: Variable argument list.
* Return: Number of characters printed.
*/
int _printf_string(va_list *list)
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
characters_printed += _printf_char(&list);
break;
case 's':
characters_printed += _printf_string(&list);
break;
}
}
format++;
}
va_end(list);
return (characters_printed);
}

/**
* main - Entry point for the program.
* @void: No arguments.
* Return: 0 on success.
*/
int main(void)
{
_printf("Hello, world!\n");
return (0);
}
