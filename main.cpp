#include "cpuload.h"

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <print.h>

int main(int argc, char **argv)
{
    int tick = 1;

    int n = 1;
    while (n < argc)
    {
        if (strcmp(argv[n], "-s") == 0)
        {
            if (++n >= argc)
                return 1;

            tick = atoi(argv[n]);
        }
        else
        {
            print("wrong option");
            return 1;
        }

        n++;
    }

    if (tick < 1 || tick > 120)
        tick = 1;

    while (1)
    {
        double cpu = cpuload();

        print("load : %lf", cpu);

        sleep(tick);
    }

    return 0;
}


