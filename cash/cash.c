#include<stdio.h>
int return_coins(int n);
int main(){
    int n=0;
    do{
        printf("%s", "Change owed: ");
        scanf("%d", &n);
    }while(n<1);
    printf("%d\n",n);
    printf("%d\n", return_coins(n));
    return 0;
}
int return_coins(int n){
    int coins = 0;
    while(n>0){
        if (n>=25){
            n=n-25;
        }else if(n>=10){
            n=n-10;
        }else if(n>=5){
            n=n-5;
        }else if(n>=1){
            n=n-1;
        }
        coins++;
    }
    return coins;
}
