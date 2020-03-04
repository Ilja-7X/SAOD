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
    int n, i, j, t, h;
    double time1, time2;
    srand((unsigned)time(NULL));
    for (h = 1; h <= 20; h++)
    {
        n = 50000 * h;
        int mass[n];
        printf("The array include %d elements\n", n);
        for (i = 0; i < n; i++)
        {
            mass[i] = getrand(1, 100001);
        }

        time1 = wtime();

        for (i = 0; i < n - 1; i++)
        {
            for (j = 0; j < n - 1 - i; j++)
            {
                if (mass[j] > mass[j + 1])
                {
                    t = mass[j];
                    mass[j] = mass[j + 1];
                    mass[j + 1] = t;
                }
            }
        }

        time2 = wtime();

        //for (i = 0; i < n; i++); printf("%d, ", mass[i]);

        printf("%f\n", time2 - time1);
    }
    getchar();
    getchar();
    return 0;
}
