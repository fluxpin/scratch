#include "crc32.h"

/* 0x1EDC6F41 (Castagnoli) */
static const uint32_t P = 0x82F63B78;
static uint32_t CRC32[256];

void crc32_table(void)
{
        uint8_t b = 0;
        do {
                CRC32[b] = b;
                CRC32[b] = CRC32[b] >> 1 ^ (CRC32[b] & 1) * P;
                CRC32[b] = CRC32[b] >> 1 ^ (CRC32[b] & 1) * P;
                CRC32[b] = CRC32[b] >> 1 ^ (CRC32[b] & 1) * P;
                CRC32[b] = CRC32[b] >> 1 ^ (CRC32[b] & 1) * P;
                CRC32[b] = CRC32[b] >> 1 ^ (CRC32[b] & 1) * P;
                CRC32[b] = CRC32[b] >> 1 ^ (CRC32[b] & 1) * P;
                CRC32[b] = CRC32[b] >> 1 ^ (CRC32[b] & 1) * P;
                CRC32[b] = CRC32[b] >> 1 ^ (CRC32[b] & 1) * P;
        } while (++b);
}

uint32_t crc32(const void *buf, size_t size, uint32_t crc)
{
        const uint8_t *b = buf;
        crc = ~crc;
        while (size--) {
                crc ^= *b++;
                crc = crc >> 8 ^ CRC32[crc & 0xFF];
        }
        return ~crc;
}
