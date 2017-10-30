#include <stdio.h>

int main()
{
    int a[6],i = 1;

    while(i < 6)
    {
        scanf("%d", &a[i]);
        i++;
    }

    printf("Before sequence:\n");
    for (i = 1; i < 6; i++ )
    {
        printf("a[%d] = %d ", i, a[i]);
    }
    printf("\n");

    sequence(a, 5);

    printf("After sequence:\n");
    i = 1;
    do{
        printf("a[%d] = %d ", i, a[i]);
        i++;
    }while(i < 6);

    return 0;

}
