#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int main()
{
    int fd = open("copy", O_RDONLY);
    char *s = (char*) calloc(160000, 1);
    int sum = 0;
    char *reserv = s;
    int written_bytes = 0, buf_size = 102400;
    while ((written_bytes = mx_read_line(&s, buf_size, '#', fd)) >= 0)
    {
        sum += written_bytes;
    }
//     written_bytes = mx_read_line(&s, buf_size, '*', fd);
//         sum += written_bytes;
// #ifdef DEBUG
// printf("Succsess\n");
//     printf("read chars = %d\n", sum);
//     printf("%s\n", reserv);

// #endif


    
    printf("sum = %d\n", sum);
    printf("%s\n", reserv);
    close(fd);
    //free(s);
}

