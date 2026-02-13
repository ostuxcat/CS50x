#include<stdio.h>
#include<stdbool.h>
int get_len(long a);
void check_valid(long card);
bool checksum_validation(long card, int len);
int get_starting_digits(long card);
int main(){
    long card;
    do{
        printf("%s", "Number: ");
        scanf("%ld", &card);
    }while(card<0);
    check_valid(card);
    return 0;
}
int get_len(long a){
    int len = 0;
    do{
        len++;
        a /= 10;
    }while(a>0);
    return len;
}
void check_valid(long card){
    int card_len = get_len(card);
    if(card_len!=13 && card_len!=15 && card_len!=16){
        printf("%s\n", "INVALID");
        return;
    }
    if(!checksum_validation(card, card_len)){
        printf("%s\n", "INVALID");
        return;
    }
    int starting_digits = get_starting_digits(card);
    if((starting_digits==34 || starting_digits==37) && card_len==15){
        printf("%s\n", "AMEX");
    }else if((starting_digits>=40 && starting_digits<=49) && (card_len==13 || card_len==16)){
        printf("%s\n", "VISA");
    }else if((starting_digits>=51 && starting_digits<=55) && card_len==16){
        printf("%s\n", "MASTERCARD");
    }else{
        printf("%s\n", "INVALID");
    }
};
bool checksum_validation(long card, int len){
    int sum=0;
    for(int i=(len-1);i>=0;i--){
        if((len%2==0) == (i%2==0)){
            int temp = (card%10)*2;
            if(temp<10){
                sum+=temp;
            }else{
                sum+=temp/10;
                sum+=temp%10;
            }
        }else{
            sum+=card%10;
        }
        card/=10;
    }
    return (sum%10==0);
};
int get_starting_digits(long card){
    do{
        card /= 10;
    }while(card>=100);
    return card;
};
