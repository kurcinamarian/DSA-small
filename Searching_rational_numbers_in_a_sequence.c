#include <stdlib.h>
#include <stdio.h>

int main(){
    int N;
    scanf("%d",&N);
    long long *integer = (long long*)malloc(N * sizeof(long long));
    long long *decimal = (long long*)malloc(N * sizeof(long long));
    char *string =(char*)malloc(11 * sizeof(char));
    for(int i=0; i<N; i++){
        string[0]='\0';
        scanf("%lld,%s",&integer[i],string);
        long long j = 0;
        for(int k = 0; k<9; k++){
            if(string[k]>='0' && string[k]<='9'){
                j = j + (string[k]-'0');
            }
            j *= 10;
        }
        decimal[i] = j;
    }
    int P;
    scanf("%d",&P);
    for (int i=0; i<P; i++){
        long long Pc;
        long long Pd;
        string[0]='\0';
        scanf("%lld,%s",&Pc,string);
        long long p = 0;
        for(int k = 0; k<9; k++){
            if(string[k]>='0' && string[k]<='9'){
                p = p + (string[k]-'0');
            }
            p *= 10;
        }
        Pd = p;
        int max = N-1;
        int min = 0;
        int avg;
        int was = 0;
        while(min <= max && was == 0){
            avg = min + (max-min)/2;
            if(integer[avg] == Pc){
                if(Pc < 0){
                    if(Pd < decimal[avg]){
                        min = avg+1;
                    }
                    else if(Pd > decimal[avg]){
                        max = avg-1;
                    }
                    else{
                        was = 1;
                    }
                }
                else{
                    if(Pd < decimal[avg]){
                        max = avg-1;
                    }
                    else if(Pd > decimal[avg]){
                        min = avg+1;
                    }
                    else{
                        was = 1;
                    }
                }
            }
            else if(integer[avg] > Pc){
                max = avg-1;
            }
            else{
                min = avg+1;
            }
        }
        if(was == 0){
            printf("0");
        }
        else{
            printf("%d",avg+1);
        }
        if(i!=P-1){
            printf("\n");
        }
    }
    free(integer);
    free(decimal);
    free(string);

    
    
   

}

