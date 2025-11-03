//Hello World
/*
NAME: GRIFFIN MUTALI
REG NO: PA106/G/28744/25
*/
#include <stdio.h>

int main()
{
    int scores[2][2] = {
        {65, 92},
        {35, 70}
    };

    int i, j;

    printf("Scores Array:\n");

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            printf("%d ", scores[i][j]);
        }
        printf("\n");
    }

    return 0;
}
