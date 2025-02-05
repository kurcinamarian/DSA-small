#include <stdlib.h>
#include <stdio.h>


int is_prime(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 0;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}


int main(){
    int a;
    int b;
    short was = 0;
    scanf("%d %d",&a, &b);
    for(int i=a; i<=b;i++){
        if(is_prime(i)){
            if (was)
                printf(", %d",i);
            else
                printf("%d",i);
            was = 1;
        }
    }
}

