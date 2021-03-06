#include <array>

#include <crc.h>

using crc8_standard = crc::crc_base<uint8_t, 8, 0x07, 0x0, 0x0, false, false>;
using crc16_ccitt = crc::crc_base<uint16_t, 16, 0x1021, 0x0, 0x0, false, false>;
using crc32_standard = crc::crc_base<uint32_t, 32, 0x4C11DB7, 0xFFFFFFFF, 0xFFFFFFFF, true, true>;

int main()
{
    crc16_ccitt crc;
    const std::array<uint8_t, 5> data = { 1, 2, 3, 4, 5 };
    uint16_t result1 = crc.compute_checksum(data.begin(), data.end()); // 0x8208
    uint16_t result2 = crc.compute_checksum(data, 0, 5); // Offset/length also supported

    return 0;
}

