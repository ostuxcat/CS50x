#include<stdio.h>
int main(){
    char name[15];
    printf("%s", "What's your name? ");
    scanf("%s", name);
    printf("%s%s\n", "hello, ", name);
    return 0;
}
