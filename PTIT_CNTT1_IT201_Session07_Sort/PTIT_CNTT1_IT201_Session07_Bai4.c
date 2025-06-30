#include <stdio.h>

int main(){
    char string[50];
    printf("Nhap chuoi can sap xep: \n");
    scanf("%s", string);
    for(int i=0; i<strlen(string) - 1; i++){
        for(int j= i+1; j<strlen(string) - 1 - i; j++){
            if(string[i] > string[j]){
                char temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
        }
    }
    printf("%s\n", string);
}