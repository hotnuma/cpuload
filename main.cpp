#include <unistd.h>
#include <print.h>

#include "cpuload.h"

int main()
{
    while (1)
    {
        double cpu = cpuload();

        print("load : %lf", cpu);

        sleep(1);
    }

    return 0;
}


