#include<stdio.h>
int main()
{
    // int a = 34;
    // int *ptra = &a;
    // printf("%d\n", ptra);
    // printf("%d\n", ptra+1);  // Adds +4 (Size of int)
    // printf("%d\n", ptra+2);  // Adds +8 (Size of int)
    // char c = '3';
    // char *ptrc = &c;
    // printf("Chars\n");
    // printf("%d\n", ptrc);
    // printf("%d\n", ptrc+1);
    // printf("%d\n", (ptrc-2));
    int arr[] = {1,2,3,4,5,6,7};
    int *arrayptr = arr;
    printf("The address of first element is  %d\n ", arr);
    printf("The address of first element is  %d\n ", arr[0]);
    printf("The address of first element is  %d\n ", &arr[0]);
    printf("The address of second element is %d\n  ", arr+1);
    printf("The address of second element is %d\n  ", &arr[1]);
    printf("The value at address of first element is  %d\n ", *arr);
    printf("The value at address of first element is  %d\n ", arr[0]);
    printf("The value at address of first element is  %d\n ", *(&arr[0]));
    printf("The value at address of second element is %d\n  ", *(arr+1));
    printf("The value at address of second element is %d\n  ", *(&arr[1]));
    // arr++; // Wrong
    arrayptr++;
    printf("The address of second element is  %d\n ", *arrayptr);

    return 0;
}
