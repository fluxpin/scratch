#ifndef CRC32_H
#define CRC32_H

#include <stddef.h>
#include <stdint.h>

void crc32_table(void);
uint32_t crc32(const void *buf, size_t size, uint32_t crc);

#endif /* CRC32_H */
