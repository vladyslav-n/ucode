#include <stdlib.h>

char *mx_strnew(const int size) {
    if (size >= 0)
    {
        char *str = (char*) malloc(size + 1);
        if (NULL == str)
            return NULL; 
        else
            for (int i = 0; i <= size; i++) 
                str[i] = '\0';
        return str;
    }
    else return NULL;
}

