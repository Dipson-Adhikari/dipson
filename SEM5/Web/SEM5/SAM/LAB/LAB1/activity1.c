/*
    activity1: 
    a) calculate the value of PI using monte carlo method
    b)calculate the error percentage
    c)Repeat the experiment for at least five different value of input iterations and
     calculate true value , experiment's output and error percentage of each .

     Algorithm:
    1)initiate circle point, square point, interval to zero
    2)generate random point 'x' (between 0 and 1)
    3)generate random poimt 'y' (between 0 and 1)
    4)calculate d=x^2 + y^2
    5)if d<=1,implement circle point 
    6)increment interval, increment square point
    7)if increment < no of iteration repeat from step 2
    8)calculate pi=4*circle point /square point
    9)display positive value
*/


// #include <stdio.h>
// #include <stdlib.h>
// #define SEED 35791246

// int main()
// {
//     int circle_point = 0, square_point = 0;
//     int i, n;
//     double x, y, d, pi,error_percentage;

//     printf("Enter number of iterations: ");
//     scanf("%d", &n);

//     // Seed random number generator
//     srand(SEED);    

//     for(i = 0; i < n; i++)
//     {
//         // Generate random values between 0 and 1
//         x = (double)rand() / RAND_MAX;
//         y = (double)rand() / RAND_MAX;

//         // Distance from origin
//         d = x * x + y * y;

//         // Check if point is inside the circle
//         if(d <= 1)
//         {
//             circle_point++;
//         }

//         square_point++;
//     }

//     // Calculate PI
//     pi = 4.0 * circle_point / square_point;

//     printf("Estimated value of PI = %lf\n", pi);
//     error_percentage = ((3.14159265358979323846 - pi) / 3.14159265358979323846) * 100;
//     printf("Error percentage = %lf%%\n", error_percentage);


//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SEED 35791246

int main()
{
    int iterations[5] = {100, 1000, 10000, 100000, 1000000};
    int i, j;
    int circle_point, square_point;
    double x, y, d, pi, error;
    double true_pi = 3.141592653589793;

    srand(SEED);

    printf("Iterations\tTrue PI\t\tEstimated PI\tError(%%)\n");
    printf("---------------------------------------------------------------\n");

    for(i = 0; i < 5; i++)
    {
        circle_point = 0;
        square_point = 0;

        for(j = 0; j < iterations[i]; j++)
        {
            x = (double)rand() / RAND_MAX;
            y = (double)rand() / RAND_MAX;

            d = x * x + y * y;

            if(d <= 1)
                circle_point++;

            square_point++;
        }

        pi = 4.0 * circle_point / square_point;

        error = fabs((true_pi - pi) / true_pi) * 100;

        printf("%d\t\t%lf\t%lf\t%lf%%\n",
               iterations[i], true_pi, pi, error);
    }

    return 0;
}