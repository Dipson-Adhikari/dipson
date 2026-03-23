#include <stdio.h>

int main()
{
    int n, i, j, k, flag;

    printf("Enter number: ");
    scanf("%d", &n);

    // try all possible primitive roots
    for(i = 2; i < n; i++)
    {
        int visited[100] = {0};
        int value = 1;
        flag = 1;

        for(j = 1; j < n; j++)
        {
            value = (value * i) % n;

            if(visited[value] == 1)
            {
                flag = 0;
                break;
            }

            visited[value] = 1;
        }

        // check if all values from 1 to n-1 appeared   
        for(k = 1; k < n; k++)
        {
            if(visited[k] == 0)
            {
                flag = 0;
                break;
            }
        }

        if(flag == 1)
        {
            printf("Primitive Root: %d\n", i);
            return 0;
        }
    }

    printf("No Primitive Root found\n");
    return 0;
}   