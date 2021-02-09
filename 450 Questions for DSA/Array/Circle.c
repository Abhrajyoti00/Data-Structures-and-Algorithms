// To check where a point lies in a circle

#include<stdio.h>
#include<math.h>
int main(){
    int rad = 5;
    int x,y;
    int centrex = 1;
    int centrey = 2;
    scanf("%d", &x);
    scanf("%d", &y);
    
    float dist = 0.0;
    dist = sqrt(pow(x-centrex, 2) + pow(y-centrey, 2));

    if(dist<rad)
        printf("It is inside the circle\n");
    if(dist == rad)
    printf("It is on the circumference of the circle\n");
    if(dist>rad)
    printf("It is outside the circle\n");

}