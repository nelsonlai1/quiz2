#include <stdint.h>
#include <stdio.h>
#include <string.h>

uint64_t hexchar2val(char *in) {
  uint64_t result = 0;
  for (int i = 0; i < strlen(in); i++) {
    uint64_t letter = in[i] & 0x40;
    uint64_t shift = (letter >> 3) | (letter >> 6);
    result = result << 4 | ((in[i] + shift) & 0xf);
  }
  return result;
}

int main()
{
  printf("%ld\n", hexchar2val("FF"));
  printf("%ld\n", hexchar2val("CAFEBABE"));
  printf("%ld\n", hexchar2val("8BADF00D"));
  return 0;
}
