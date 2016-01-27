#include<stdio.h>



int main(){
while(i<10){
    int r=rand()%10+1;

    for (x = 0; x < i; x++)
    {
        if(array[x]==r){
            break;
        }
    }
    if(x==i){
        array[i++]=r;
    }
}

return 0;
}