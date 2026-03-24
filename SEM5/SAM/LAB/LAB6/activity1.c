#include <stdio.h>

#define N 20

// STEP 1: Structure
struct Customer {
    int arrivalTime;
    int serviceTime;
    int startTime;
    int endTime;
};

int main() {
    struct Customer c[N];

    int waitTime[N];
    int timeSpent[N];
    int idleTime[N];

    int totalWait = 0, totalService = 0, totalTimeSpent = 0;
    int totalIdle = 0;

    // STEP 2: Store arrival and service times in arrays
    int interArrival[N] = {0,8,6,1,8,3,8,7,2,3,1,1,5,6,3,8,1,2,4,5};
    int serviceTime[N] = {4,1,4,3,2,4,5,4,5,3,3,5,4,1,5,4,3,3,2,3};

    // Calculate actual arrival times
    for(int i = 0; i < N; i++) {
        if(i == 0)
            c[i].arrivalTime = interArrival[i];
        else
            c[i].arrivalTime = c[i-1].arrivalTime + interArrival[i];

        c[i].serviceTime = serviceTime[i];
    }

    // STEP 3: Calculate Start & End Time
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            c[i].startTime = c[i].arrivalTime;
            idleTime[i] = c[i].arrivalTime;
        } else {
            if(c[i].arrivalTime > c[i-1].endTime) {
                c[i].startTime = c[i].arrivalTime;
                idleTime[i] = c[i].arrivalTime - c[i-1].endTime;
            } else {
                c[i].startTime = c[i-1].endTime;
                idleTime[i] = 0;
            }
        }

        c[i].endTime = c[i].startTime + c[i].serviceTime;

        waitTime[i] = c[i].startTime - c[i].arrivalTime;
        timeSpent[i] = c[i].endTime - c[i].arrivalTime;

        totalWait += waitTime[i];
        totalService += c[i].serviceTime;
        totalTimeSpent += timeSpent[i];
        totalIdle += idleTime[i];
    }

    // STEP 4: Print Table
    printf("\nCustomer Simulation Table:\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("No\tIAT\tAT\tST\tSB\tSE\tT.spent\tWait\tIdle\n");
    printf("--------------------------------------------------------------------------------\n");

    for(int i = 0; i < N; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            i+1,
            interArrival[i],
            c[i].arrivalTime,
            c[i].serviceTime,
            c[i].startTime,
            c[i].endTime,
            timeSpent[i],
            waitTime[i],
            idleTime[i]);
    }

    // STEP 5: Performance Metrics
    float avgWait = (float)totalWait / N;
    float avgService = (float)totalService / N;
    float avgTimeSpent = (float)totalTimeSpent / N;

    int totalTime = c[N-1].endTime;

    float utilization = ((float)totalService / totalTime) * 100;
    float idlePercent = ((float)totalIdle / totalTime) * 100;

    printf("\n----- Performance Parameters -----\n");
    printf("Average Wait Time = %.2f\n", avgWait);
    printf("Average Time Spent in System = %.2f\n", avgTimeSpent);
    printf("Average Service Time = %.2f\n", avgService);
    printf("Server Utilization = %.2f%%\n", utilization);
    printf("Total Idle Time = %d\n", totalIdle);
    printf("Idle Time Percentage = %.2f%%\n", idlePercent);

    return 0;
}