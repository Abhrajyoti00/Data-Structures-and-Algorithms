#include<stdio.h>
void fun1(int x){
    if(x > 0){
    printf("%d\n", x);
    fun1(x - 1); // Tell recursion
    }
}
void fun2(int x){
    if(x > 0){
    fun2(x - 1); // Head recursion
    printf("%d\n", x);
    }
}
int main(int argc, char const *argv[])
{
    int x = 3;
    fun1(x);
    fun2(x);
    return 0;
}

// Thank You Argha :)
//Thank u so much bubu ;)*