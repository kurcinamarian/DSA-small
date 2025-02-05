#include <stdlib.h>
#include <stdio.h>

int main(){
    int N;
    scanf("%d",&N);
    for (int i = 0; i < N; i++) {
        char *string =(char*)malloc(100000 * sizeof(char));
        char *stack =(char*)malloc(100000 * sizeof(char));
        scanf("%s",string);
        int k = 0;
        int s = 0;
        int error = 0;
        while(string[k] != '\0'){
            if(string[k] == '{'||string[k] == '('||string[k] == '<'||string[k] == '['){
                stack[s] = string[k];
                s++;
            }
            else if(string[k] == '}'){
                if(stack[s-1] == '{'){
                    s--;
                }
                else if(s==0){
                    error++;
                }
                else{
                    error++;
                    s--;
                }
            }
            
            else if(string[k] == ')'){
                if(stack[s-1] == '('){
                    s--;
                }
                else if(s==0){
                    error++;
                }
                else{
                    error++;
                    s--;
                }
            }
            else if(string[k] == '>'){
                if(stack[s-1] == '<'){
                    s--;
                }
                else if(s==0){
                    error++;
                }
                else{
                    error++;
                    s--;
                }
            }
            else if(string[k] == ']'){
                if(stack[s-1] == '['){
                    s--;
                }
                else if(s==0){
                    error++;
                }
                else{
                    error++;
                    s--;
                }
            }
            k++;
        }
        printf("%d",error+s);
        if(i != N-1){
            printf("\n");
        }
        free(stack);
        free(string);
    } 
}
