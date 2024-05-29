#include <stdio.h>
#include <stdint.h>

uint32_t rev_hex1(uint32_t org_hex)
{
    // 0xDEAD;
    uint32_t u_hex = org_hex >> 16;
    // 0xBEEF
    uint32_t l_hex = org_hex & 0xFFFF;
    // 0xDEAD ---> 0xADDE
    u_hex = u_hex >> 8 | (u_hex & 0xFF) << 8;
    // 0xBEEF ---> 0xEFBE
    l_hex = l_hex >> 8 | (l_hex & 0xFF) << 8;
    // 0xDEADBEEF ---> 0xEFBEADDE
    return u_hex | l_hex << 16;
}

uint32_t rev_hex2(uint32_t org_hex)
{
    // 0xEF000000  | 0xBE0000 | 0xAD00 | 0xDE
    return ((((org_hex) & 0xFF) << 24) | (((org_hex >> 8) & 0xFF) << 16) | (((org_hex >> 16) & 0xFF) << 8) | ((org_hex >> 24)));
}

int main() {
    uint32_t org_hex = 0xDEADBEEF;
    printf("Reversed HEX: %x \n", rev_hex1(org_hex));
    printf("Reversed HEX: %x \n", rev_hex2(org_hex));

    return 0;
}
