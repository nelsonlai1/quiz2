#include <stdio.h>
int singleNumber(int *nums, int numsSize)
{
    int left = 0, middle = 0, right = 0;
    for (int i = 0; i < numsSize; i++) {
        right = ~left & (nums[i] ^ right);
        middle = ~left & ((~right & (middle ^ nums[i])) | (middle & right));
        left = ~middle & ~right & (left ^ nums[i]);
    }
    return right;
}

int main ()
{
    int nums[] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 5};
    printf("%d\n", singleNumber(nums, 11));
    return 0;
}
