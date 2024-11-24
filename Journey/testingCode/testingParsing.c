#include <stdio.h>

// this third argument has the information of all
// env variables

int main(int ac, char **av, char **e)
{
    // Print each environment variable
    for (int i = 0; e[i] != NULL; i++)
    {
        printf("%s\n", e[i]);
        printf("\n-------\n");
    }
    return 0;
}