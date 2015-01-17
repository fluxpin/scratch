#include <stdio.h>

const char *FB[][2] = {{"%d\n", "Fizz\n"}, {"Buzz\n", "FizzBuzz\n"}};

int main(void)
{
        int i;
        for (i = 1; i <= 100; ++i)
                printf(FB[i % 5 == 0][i % 3 == 0], i);
        return 0;
}
