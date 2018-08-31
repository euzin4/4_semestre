#include <stdio.h>
#include <stdlib.h>

int main()
{
    char val[30];
    int car;

    printf("valor:");
    fgets(val, 30, stdin);
    car = strlen(val);

    while(1){
        val[car] = val[car-1];
        car--;
        if(car == 0){
            val[0] = '>';
            break;
        }
    }

    printf("%d\n",car);
    printf("%c",val[1]);
}
