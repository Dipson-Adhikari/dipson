// activity2:
//    a) use monte carlo method to calculate the probability of getting 3, 6 or 9 heads in tossing a coin 10 
//    b) find error percentage

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int j, count = 0, limit, i = 0, head;
    double experimental, theoretical, error;

    printf("Enter number of iterations: ");
    scanf("%d", &limit);

    srand(time(0));

    while(i < limit)
    {
        i++;
        head = 0;

        for(j = 0; j < 10; j++)
        {
            if(rand() % 2 == 0)  
                head++;
        }

        if(head == 3 || head == 6 || head == 9)
        {
            count++;
        }
    }

    // Experimental probability
    experimental = (double)count / limit;

    // Theoretical probability
    theoretical = 340.0 / 1024.0;

    // Error percentage
    error = fabs((theoretical - experimental) / theoretical) * 100;

    printf("\nTheoretical Probability = %lf", theoretical);
    printf("\nExperimental Probability = %lf", experimental);
    printf("\nError Percentage = %lf%%\n", error);

    return 0;
}