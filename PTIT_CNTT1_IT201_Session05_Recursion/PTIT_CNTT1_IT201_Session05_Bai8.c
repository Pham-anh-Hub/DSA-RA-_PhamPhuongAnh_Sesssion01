#include <math.h>
#include <stdio.h>

int convertStr(char str[], int size, int index, int res) {
    if (index == size) {
        return res;
    }
    ;
   res = res*10 + (str[index]-'0');
    convertStr(str, size, index+1, res);

}
int main() {
    printf("%d",convertStr("123", 3, 0, 0));
}