#include "main.h"

/**
 * _printf - emulated function developed for
 * printing characters, specified according to
 * a pre-defined format
 * @format: a pointer that points to the const char
 * @...: variable number of arguments which are
 * unsepecified by the function
 * Return: the number of characters to be outputted
 */

int _printf(const char *format, ...)
{
	int va1 = 0;
	int valor = 0;
	int count = 0;
	char *y;
	char x;
	va_list lista;

	va_start(lista, format);

	if (format == NULL)
		return (-1);

	while (format[va1])
	{
		if (format[va1] != '%')
		{
			valor = write(1, &format[va1], 1);
			count += valor;
			va1 = va1 + 1;
			continue;
		}
		switch (format[va1 + 1])
		{
			case 's':
				y = va_arg(lista, char *);
				valor = write(1, y, strlen(y));
				count += valor;
				va1 = va1 + 2;
				break;
			case 'c':
				x = va_arg(lista, int);
				valor = write(1, &x, 1);
				count += valor;
				va1 = va1 + 2;
				break;
			default:
				valor = write(1, &format[va1], 1);
				count += valor;
				va1 = va1 + 1;
				break;
		}
	}
	va_end(lista);
	return (count);
}
