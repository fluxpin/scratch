#include "crc32.h"

/* 0x1EDC6F41 (Castagnoli) */
static const uint32_t P = 0x82F63B78;

uint32_t crc32(const void *buf, size_t size, uint32_t crc)
{
        const uint8_t *b = buf;
        size_t i, j;
        for (i = 0; i < size; ++i) {
                crc ^= *b++;
                for (j = 0; j < 8; ++j) {
                        if (crc & 1) {
                                crc >>= 1;
                                crc ^= P;
                        } else {
                                crc >>= 1;
                        }
                }
        }
        return crc;
}
