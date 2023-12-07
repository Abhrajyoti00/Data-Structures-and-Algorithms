#include<stdio.h>

int main()
{
    printf("Pointers\n");
    int a = 76;
    int *ptra = &a;
    int *ptr2 = NULL ;
    printf("The value of a is %d\n", a);
    printf("The address of a is %d\n", &a);
    printf("The value of ptra is %d\n", ptra);
    printf("The address of pointer to a is %x\n", &ptra); //%x for hex
    printf("The value of a is %d\n", *ptra);
    printf("The address of some garbage is %p\n", ptr2);

}