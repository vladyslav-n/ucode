#include "../inc/libmx.h"
#include <stdio.h>
#define DEBUG

int **create_grid(int row, int col, int val)
{
    int i, j = 0;

    int **arr = (int **)malloc(row * sizeof(int *)); 
    for (i = 0; i < row; i++) 
         arr[i] = (int *)malloc(col * sizeof(int)); 
  
    // Note that arr[i][j] is same as *(*(arr+i)+j) 
    for (i = 0; i <  row; i++) 
      for (j = 0; j < col; j++) 
        arr[i][j] = val;
    return arr;
}

char **create_list_of_names(int count, const char *s)
{
    char **names = (char**) malloc((count + 1) * sizeof(char*));
    names[count] = NULL;
    for (int i = 0; i < count; i++) {
        names[i] = (char*)s;
    }
    return names;
}

int word_index(char **arr, char *word)
{
    for (int i = 0; arr[i]; i++) 
    {
        if (!mx_strcmp(arr[i], word))
            return i;
    }
    return -1;
}

void printerror(int num)
{  
    switch (num) 
    {
        case INV_NUM_OF_ISLS:
            mx_printerror("error: invalid number of islands\n");
            break;
    }
    exit(num);
}

int main(int argc, char *argv[])
{
    // open(argv[1], O_RDONLY);
    /* save file to str */
    char *file = mx_file_to_str(argv[1]);
    int lines_count = 0;

    /* devide file into separate lines & save the islands quantity */
    char **file_lines = mx_strsplit_ncount(file, '\n', &lines_count);
    int isl_count = mx_atoi(file_lines[0]);

    /* creating an array of lines, splitted into words */
    char ***extra_isl_names = (char***) malloc((lines_count - 1) * sizeof(char**));
    for (int i = 0; i < lines_count - 1; i++) {
        extra_isl_names[i] = mx_strsplit(file_lines[i + 1], '-');
    }
    for (int i = 0; i < lines_count - 1; i++) {
        extra_isl_names[i][1][mx_get_char_index(extra_isl_names[i][1], ',')]
            = 0;
    }

    /* creating an array of distances between islands */
    int **grid = create_grid(isl_count, isl_count, GRID_INIT_VAL);

    /* creating an array of islands' names and filling the grid */
    char **isl_names = create_list_of_names(isl_count, "");
    int count = 0;
    int wi1, wi2 = -2;
    // int names_in_file_count = 0;
    for (int i = 0; i < lines_count - 1; i++)
    {
        if ((wi1 = word_index(isl_names, extra_isl_names[i][0])) < 0) {
            if (count == isl_count) {
                printerror(INV_NUM_OF_ISLS);
            }
            isl_names[count] = mx_strdup(extra_isl_names[i][0]);
            wi1 = count++;
        }
        if ((wi2 = word_index(isl_names, extra_isl_names[i][1])) < 0) {
            if (count == isl_count) {
                printerror(INV_NUM_OF_ISLS);
            }
            isl_names[count] = mx_strdup(extra_isl_names[i][1]);
            wi2 = count++;
        }
        grid[wi1][wi2] = mx_atoi(extra_isl_names[i][1] 
            + mx_strlen(extra_isl_names[i][1]) + 1);
        grid[wi2][wi1] = grid[wi1][wi2];
    }
    if (count < isl_count) {
        printerror(INV_NUM_OF_ISLS);
    }
#ifdef DEBUG
mx_print_strarr(isl_names, "\n");
printf("\nand the grid:\n");
for (int i = 0; i < isl_count; i++)
{
      for (int j = 0; j < isl_count; j++) 
         printf("%d ", grid[i][j]); 
    printf("\n");
}
#endif 
    argc++;
}

