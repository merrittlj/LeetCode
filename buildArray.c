/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * Broken Code, too lazy to fix
 *!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/*  LeetCode build array from permutation  */
#include <stdio.h>
#include <stdlib.h>
int *buildArray(int *nums, int numsSize, int *returnSize);
int main() {
    int testcaseLength = 2;  //How large the test case is
    int *testcase = (int *)malloc(sizeof(int)*testcaseLength);
    int *returnArray = buildArray(testcase, testcaseLength, &testcaseLength);
    int* iterationEnd=returnArray+testcaseLength;
    for(returnArray != iterationEnd) {
        printf("%d",returnArray);
        returnArray++;
    }returnArray-testcaseLength;
}
int *buildArray(int *nums, int numsSize, int *returnSize){
    int *ans = (int *)malloc(sizeof(int)*numsSize);  //Make space for int array using pointers
    *returnSize = numsSize;
    if(1 <= numsSize <= 1000) {  //Check if numsSize is in range of allowed sizes
        for(int i=0; i<numsSize; i++)
            ans[i] = nums[nums[i]];  //Iterate through nums and set ans accordingly
        return ans;
    }
    return 0;  //If condition failed
}
