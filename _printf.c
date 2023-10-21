#include "main.h"

/**
 *  _printf - performs the printf function
 *  @format: format parameter
 */

int _printf(const char *format, ...) {
	va_list param;
	va_start(param, format);

	int count;
	count = 0;

	while (*format) {
		if (*format != '%') {
			_putchar(*format);
			count++;
		} else {
			format++;
			char flag = flag(&format);
			int width = width(&format);
			int precision = precision(&format);
			int size = size(&format);
			char specifier = specifier(&format);

			count += handleSpecifiers(param, specifier, flag, width, precision, size);
		}
	}
	return (count);
}
