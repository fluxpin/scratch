#include <inttypes.h>
#include <stdio.h>

#include "crc32.h"

static const char test[] = "123456789\0\0\0\0";
static const uint32_t crc = 0x45FC71A;

int main(void)
{
        printf("%" PRIX32 " -> %" PRIX32 "\n",
               crc,
               crc32(test, sizeof(test) - 1, 0));
        return 0;
}
