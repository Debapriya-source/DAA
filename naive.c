#include <stdio.h>
#include <string.h>

int substring_count(char *string, char *substring)
{
    int i, j, len1, len2;
    int counter = 0;
    int found = 0;

    len1 = strlen(string);
    len2 = strlen(substring);

    for (i = 0; i < len1; i++)
    {
        found = 1;
        for (j = 0; j < len2; j++)
        {
            if (string[i + j] != substring[j])
            {
                found = 0;
                break;
            }
        }

        if (found)
        {
            printf("Found at index %d ", i);
            counter++;
        }
    }
    printf("\n");
    return counter;
}

int main()
{
    char string[30];
    char substring[30];
    int count = 0;

    printf("Enter a string: ");
    gets(string);

    printf("Enter a substring: ");
    gets(substring);

    count = substring_count(string, substring);

    printf("Substring occurred %d times.\n", count);

    return 0;
}