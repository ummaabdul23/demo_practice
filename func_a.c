#include "main.h"

int print_Char(va_list param, char buffer[], int flag, int widh,int precision, int size)
{
	char c = va_arg(param,int);
	return (handle_write_char(c, buffer, flag, width, precision, size));
}

int print_str(va_list param, char buffer[], int flag, int width, int precision, int size)
{
	int i, count = 0;
	char *str = va_arg(param, char *);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (!str)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";

	while (str[count] != '\0') {
		count++;
	}

	if (precision >= 0 && precision < count)
	{
		count = precision;
	} else if (precision > count) {
		precision = count;
	}

	if (width > count)
	{
		int padding = width - count;
		char padChar = ' ';

		if (!flag)
			padChar = '0';

		if ((flag & '-') == 0) {
			for (i = padding;i > 0; i--)
				_putchar(padChar);
			return (width);
		}
		else
		{
			for (i = padding; i > 0; i--)
				_putchar(str[i]);
			return (width);
		}
	}
	return _putchar(str[i]);
}

int print_Dec(va_list param, char buffer[], int flag, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int neg = 0;
	long int num - va_arg(param, long int);
	unsigned long int n;
	num = convert_size_number(num, size);

	if (!num)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
		n = unsigned long int)num;
		if (num < 0)
		{
			n = (unsigned long int)((-1) * num);
			neg = 1;
		}
	while (n > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(neg, i, buffer, flag, width, precision, size));
}

int print_mod(va_list param, char buffer[]; int flag, int width, int precision,int size)
{
	UNUSED(param);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (_putchar("%%"));
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
