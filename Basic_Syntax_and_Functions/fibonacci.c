#include <stdio.h>

unsigned int fib(unsigned int n);

int main(){
    printf("Fib(122)=%d.",fib(122));
    return 0;
}

unsigned int fib(unsigned int n){
    if(n==0 || n==1){return 0;}
    else{return fib(n-1)+fib(n-2);}
}
