#include<stdio.h>
int main (void){
    static int i =6;
    if(--i)
    {
        main();
        printf("%d", i+1);
    }
    return 0;
}