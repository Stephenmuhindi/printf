#include "main.h"

typedef struct {
    const char *id;
    int (*f)(va_list);
} convert_match;

int printf_char(va_list);
int printf_string(va_list);
int printf_percent(va_list);
int printf_int(va_list);

typedef convert_match convert_match_array[]; 

convert_match_array m = {
    {"%c", printf_char},
    {"%s", printf_string},
    {"%%", printf_percent},
    {"%d", printf_int},
    {"%i", printf_int}
};
