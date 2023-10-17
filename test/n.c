#include <stdio.h>
#include <main.h>

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
{
char Charactera = va_arg(List_Of_Arguments, int);
write(1, &Charactera, 1);
Chars_Print++;
} break;
case 's':
{
char *infinty_strings = va_arg(List_Of_Arguments, char *);
int infinty_strings_len = 0;

while (infinty_strings[infinty_strings_len] != '\0')
{
infinty_strings_len++;
}
write(1, infinty_strings, infinty_strings_len);
Chars_Print += infinty_strings_len;
} break;
}
}
}

va_end(List_Of_Arguments);

return (Chars_Print);
}
