#include <stdio.h>

int main(){
    char foo= (char) 128;
    int bar = (int) foo;
    printf("int(char(128)) is %d.\n",bar);
    int baz16= 0xa;
    int baz8= 012;
    int baz2= 0b100;
    printf("0xa=%d, 012=%d, 0b100=%d.",baz16,baz8,baz2);
    return 0;
}
