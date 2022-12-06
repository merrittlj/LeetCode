/*  LeetCode minimum partitions using deci-binary numbers  */
#include <stdio.h>
int minPartitions(char *n);
int main() {
    char testcase[] = "81221302745";
    printf("minimum partitions for %s is %d\n", testcase, minPartitions(testcase));  //print results
}
int minPartitions(char *n){
    char highest = '0';
    while(*n!='\0') {  //Iterate through string
        if(*n>highest) {  //If the number is higher then the previous highest
            highest=*n;
        }
        n++;  //Increment pointer
    }
    return highest-'0';  //Return int of highest
}
