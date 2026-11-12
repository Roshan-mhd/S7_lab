
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char prod[10][10];
char first[10], follow[10];
int n, fc, foc;

void FIRST(char c)
{
    int i, j;

    if (!isupper(c))
    {
        first[fc++] = c;
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (prod[i][0] == c)
        {
            if (prod[i][2] == '#')
                first[fc++] = '#';

            else
            {
                for (j = 2; prod[i][j] != '\0'; j++)
                {
                    FIRST(prod[i][j]);

                    if (first[fc - 1] != '#')
                        break;
                }
            }
        }
    }
}

void FOLLOW(char c)
{
    int i, j;

    if (c == prod[0][0])
        follow[foc++] = '$';

    for (i = 0; i < n; i++)
    {
        for (j = 2; prod[i][j] != '\0'; j++)
        {
            if (prod[i][j] == c)
            {
                if (prod[i][j + 1] != '\0')
                    FIRST(prod[i][j + 1]);

                if (prod[i][j + 1] == '\0' ||
                    first[fc - 1] == '#')
                {
                    if (prod[i][0] != c)
                        FOLLOW(prod[i][0]);
                }
            }
        }
    }
}

int main()
{
    int i, j;
    char c;

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (use # for epsilon):\n");

    for (i = 0; i < n; i++)
        scanf("%s", prod[i]);

    printf("\nFIRST sets:\n");

    for (i = 0; i < n; i++)
    {
        c = prod[i][0];
        fc = 0;

        FIRST(c);

        printf("FIRST(%c) = { ", c);

        for (j = 0; j < fc; j++)
            printf("%c ", first[j]);

        printf("}\n");
    }

    printf("\nFOLLOW sets:\n");

    for (i = 0; i < n; i++)
    {
        c = prod[i][0];
        foc = 0;

        FOLLOW(c);

        printf("FOLLOW(%c) = { ", c);

        for (j = 0; j < foc; j++)
            printf("%c ", follow[j]);

        printf("}\n");
    }

    return 0;
}
