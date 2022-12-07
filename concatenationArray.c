/*  LeetCode concatenation of array  */
#include <stdio.h>
#include <stdlib.h>
int *getConcatenation(int *nums, int numsSize, int *returnSize);
int main() {
    int testcase[] = {1, 2, 1};
    int testcaseLength = sizeof(testcase)/sizeof(testcase[0]);
    int *returnArray = getConcatenation(&testcase, testcaseLength, &testcaseLength);
    int *returnArrayEnd = returnArray+testcaseLength;
    while(returnArray != returnArrayEnd) {
        printf("%d", returnArray[0]);
        returnArray++;
    }
    printf("\n");
}
int *getConcatenation(int *nums, int numsSize, int *returnSize){
    int *ans = (int*)malloc(sizeof(int)*(numsSize*2));
    *returnSize = 2*numsSize;
    for(int x=0; x<2; x++) {
        for(int y=0; y<numsSize; y++) {
            ans[y+(numsSize*x)] = nums[y];
        }
    }
    return ans;
}
