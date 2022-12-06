/*  LeetCode convert temperatures from celsius to kelvin and fahrenheit  */
#include <stdio.h>
#include <stdlib.h>
double *convertTemperature(double celsius, int *returnSize);
int main() {
    double testcase = 35; int returnsz = 2;
    double *result = convertTemperature(testcase, &returnsz);
    printf("celsius: %f kelvin: %f fahrenheit: %f\n", testcase, result[0], result[1]);
}
double *convertTemperature(double celsius, int *returnSize){
    double *ans = (double *)malloc(sizeof(double)*2);
    *returnSize = 2;
    *ans=(celsius+273.15);
    *++ans=(celsius*1.8+32);
    return --ans;
}
