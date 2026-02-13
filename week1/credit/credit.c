#include<stdio.h>
#include<stdbool.h>
int get_length(long card_num);
bool checksum(long card_num, int len);
void test_credit(long card_num);
int main(){
    long card_num = 4003600000000014;
    printf("%ld\n", card_num);
    int len = get_length(card_num);
    checksum(card_num, len);
    return 0;
}
int get_length(long card_num){
    int length = 0;
    if(card_num==0){
        return 1;
    }
    while(card_num!=0){
        card_num /= 10;
        length++;
    }
    return length;
}
bool checksum(long card_num, int len){
    char buff_card_num[len];
    int sum_of_all = 0;
    sprintf(buff_card_num, "%ld", card_num);
    for(int i=1;i<=len;i++){
        if(!(i%2)){
            sum_of_all += (buff_card_num[i-1]-'0')*2;
        }else{
            sum_of_all += buff_card_num[i-1]-'0';
        }
    }
    printf("%d\n", sum_of_all);
    printf("%d\n", !(sum_of_all%10));
    return !(sum_of_all%10);
}
void test_credit(long card_num){
}
