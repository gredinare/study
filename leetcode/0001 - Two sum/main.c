#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(*returnSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    return result;
}

void test1() {
    int nums[] = {2, 7, 11, 15, 16, 18, 20};
    int numsSize = 7;
    int target = 9;
    int returnSize = 2;

    int* result = twoSum(nums, numsSize, target, &returnSize);
    printf("%d %d : {0, 1}\n", result[0], result[1]);
}

void test2() {
    int nums[] = {3, 2, 4};
    int numsSize = 3;
    int target = 6;
    int returnSize = 2;

    int* result = twoSum(nums, numsSize, target, &returnSize);
    printf("%d %d : {1, 2}\n", result[0], result[1]);
}

void test3() {
    int nums[] = {3, 3};
    int numsSize = 3;
    int target = 6;
    int returnSize = 2;

    int* result = twoSum(nums, numsSize, target, &returnSize);
    printf("%d %d : {0, 1}\n", result[0], result[1]);
}

int main(int argc, char const* argv[]) {
    test1();
    test2();
    test3();
    return 0;
}

