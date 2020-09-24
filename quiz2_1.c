#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define PACKED_BYTE(b) (((uint64_t)(b) & (0xff)) * 0x0101010101010101u)

bool is_ascii(const char str[], size_t size)
{
    if (size == 0)
        return false;
    int i = 0;
    while ((i + 8) <= size) {
        uint64_t payload;
        memcpy(&payload, str + i, 8);
        payload |= PACKED_BYTE(0x20);
        if ((payload & PACKED_BYTE(0x80)) == 0) {
            uint64_t a = payload + PACKED_BYTE(128 - 'a');
            uint64_t z = payload + PACKED_BYTE(128 - 'z' - 1);
            if ((a ^ z) & PACKED_BYTE(0x80) ^ PACKED_BYTE(0x80))
                return false;
        }
        i += 8;
    }
    while (i < size) {
        if ((str[i] | 0x20) < 97 || (str[i] | 0x20) > 122)
            return false;
        i++;
    }
    return true;
}
int main() 
{
    char *str = "abcxyz!@ABCXYZ";
    printf("%s\n", is_ascii(str, strlen(str)) ? "true" : "false");
    return 0;
}
