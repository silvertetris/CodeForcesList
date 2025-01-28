#include <stdio.h>

int main(void)
{
    int w;
    scanf("%d", &w);

    if (w % 2 != 0 || w < 4)
    {
        printf("NO");
    } else {
        printf("YES");
    }
}