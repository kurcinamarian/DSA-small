#include <stdlib.h>
#include <stdio.h>

int main(){
    int N;
    scanf("%d",&N);  // Read the number of test cases
    for (int i = 0; i < N; i++) {
        // Allocate memory for the input string and stack
        char *string =(char*)malloc(100000 * sizeof(char));
        char *stack =(char*)malloc(100000 * sizeof(char));
        
        // Read the string to be processed
        scanf("%s",string);
        
        int k = 0;  // Pointer to track the current character in the string
        int s = 0;  // Stack pointer to track open brackets
        int error = 0;  // Variable to track unmatched brackets (errors)
        
        // Process each character of the string
        while(string[k] != '\0'){  
            // If the character is an opening bracket, push it to the stack
            if(string[k] == '{'||string[k] == '('||string[k] == '<'||string[k] == '['){
                stack[s] = string[k];  // Push to stack
                s++;  // Increment the stack pointer
            }
            // If the character is a closing bracket, check if it matches the top of the stack
            else if(string[k] == '}'){
                // If it matches an opening bracket, pop from the stack
                if(stack[s-1] == '{'){
                    s--;  // Pop from stack
                }
                else if(s==0){
                    error++;  // If no matching opening bracket, increment error count
                }
                else{
                    error++;  // Mismatched brackets, increment error count
                    s--;  // Pop from stack to continue checking
                }
            }
            
            else if(string[k] == ')'){
                // Matching check for closing parenthesis
                if(stack[s-1] == '('){
                    s--;  // Pop from stack
                }
                else if(s==0){
                    error++;  // If no matching opening bracket, increment error count
                }
                else{
                    error++;  // Mismatched brackets, increment error count
                    s--;  // Pop from stack to continue checking
                }
            }
            else if(string[k] == '>'){
                // Matching check for closing angle bracket
                if(stack[s-1] == '<'){
                    s--;  // Pop from stack
                }
                else if(s==0){
                    error++;  // If no matching opening bracket, increment error count
                }
                else{
                    error++;  // Mismatched brackets, increment error count
                    s--;  // Pop from stack to continue checking
                }
            }
            else if(string[k] == ']'){
                // Matching check for closing square bracket
                if(stack[s-1] == '['){
                    s--;  // Pop from stack
                }
                else if(s==0){
                    error++;  // If no matching opening bracket, increment error count
                }
                else{
                    error++;  // Mismatched brackets, increment error count
                    s--;  // Pop from stack to continue checking
                }
            }
            k++;  // Move to the next character in the string
        }
        
        // Print the total number of errors (unmatched brackets) + remaining open brackets in stack
        printf("%d",error+s);
        
        // Print newline for each test case except the last one
        if(i != N-1){
            printf("\n");
        }
        
        // Free the allocated memory for the string and stack
        free(stack);
        free(string);
    } 
}

