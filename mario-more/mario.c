#include<stdio.h>
void show_pyramid(int n);
int main(){
    int n=0;
   do {
    printf("%s", "Height: ");
    scanf("%d", &n);
    } while (n<1 || n>8);
    show_pyramid(n);
    return 0;
}
void show_pyramid(int n){
    int pattern = 1;
    int spaces = n-pattern;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=spaces;j++){
            printf("%s", " ");
        }
        for (int k=1;k<=pattern;k++){
            printf("%s", "#");
        }
        printf("%s", "  ");
        for (int k=1;k<=pattern;k++){
            printf("%s", "#");
        }
        spaces-=1;
        pattern+=1;
        printf("\n");
    }
}
