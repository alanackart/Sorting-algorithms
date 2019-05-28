#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 5

static int comp(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}


char *my_strdup(const char *str)
{
    size_t len = strlen(str);
    char *x = (char *)malloc(len+1); /* 1 for the null terminator */
    if(!x) return NULL; /* malloc could not allocate memory */
    memcpy(x,str,len+1); /* copy the string into the new buffer */
    return x;
}

int main(void)
{
    char str[100];
    char *str_array[N];
    for(int i = 0; i < N; i++)
    {
        scanf("%s", str);
        str_array[i] = my_strdup(str);
    }
    qsort(str_array, N, sizeof(char *), comp);
    for(int i = 0; i < N; i++)
    {
        printf("%s\n", str_array[i]);
    }

    return 0;
}
