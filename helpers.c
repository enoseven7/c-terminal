#include "eno.h"

// 0: the strings are equal
// < 0: str1 < str2
// > 0: str1 > str2

int my_strcmp(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }

    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int my_strlen(const char* str)
{
    size_t len = 0;
    while (*str)
    {
        len++;
        str++;
    }
    return len;
}

char* my_getenv(const char *name, char** env) {
    if(name == NULL || env == NULL)
    {
        return NULL;
    }

    size_t name_len = my_strlen(name);
}
