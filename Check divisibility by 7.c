//Given a number N, the task is to check if it is divisible by 7 or not.
//Note: You are not allowed to use the modulo operator, floating point arithmetic is also not allowed. 
#include<stdio.h>
#define isdivisible_of_7(n,x) x*7==n?printf("Divisible"):printf("not Divisible")
int main(){
    int n;
    printf("enter number :  ");  //logic : num is divisible by 7 only if
    scanf("%d",&n);              // div=num/7   division of any number, division * any number = num.
    isdivisible_of_7(n,n/7);    // num=div*7
}
