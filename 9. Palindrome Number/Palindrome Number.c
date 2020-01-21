#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int isPalindrome(int x) {
    int T = 1;
        if(x < 0){
            T = 0; return T;
        }
        else if (x == 0) return T;
        else {
            int tmp = x,i = 0;
            int count = 0;
            while(tmp > 0){tmp = tmp/10;count++;}
            int check[count]; tmp = x;
            while(i < count){check[i] = tmp%10;tmp/=10;i++;}
            for(i = 0;i<count;i++){
                if (check[i] != check[count-1-i]){
                        T = 0; return T;
                }
            }
            return T;
        }
}


int main(){
    int x;
    scanf("%d",&x);
    printf("%d\n",x);
    printf("%d\n", isPalindrome(x));
    return 0;
}