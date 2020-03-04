#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main()
{
    int n, i, j, h, max;
    double time1, time2;
    srand((unsigned)time(NULL));
    for (h = 1; h <= 20; h++)
    {
        n = 50000 * h;

        int number = 0;
        int mass[n];

        printf("The array include %d elements\n", n);
        for (i = 0; i < n; i++)
        {
            mass[i] = getrand(1, 100001);
        }

        max = mass[0];
        for (i = 0; i < n; i++) //search for the maximum element
        {

            if (mass[i] > max)
                max = mass[i];
        }
        printf("max = %d\n", max);
        int str[max];

        for (i = 0; i < max + 1; i++) //initializing an array
        {
            str[i] = 0;
        }

        time1 = wtime();

        for (i = 0; i < n; i++)
            str[mass[i]]++;

        for (i = 0; i < max + 1; i++)
        {
            for (j = 0; j < str[i]; j++, number++)
                mass[number] = i;
        }

        time2 = wtime();

        printf("%f\n", time2 - time1);
    }
    return 0;
}
