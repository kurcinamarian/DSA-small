#include <stdlib.h>
#include <stdio.h>

int main(){
    int N;
    scanf("%d",&N);  // Read the number of entries

    // Allocate memory for arrays to store integer and decimal parts of the input
    long long *integer = (long long*)malloc(N * sizeof(long long));
    long long *decimal = (long long*)malloc(N * sizeof(long long));

    // Allocate memory for the string buffer (to store the decimal part as a string)
    char *string =(char*)malloc(11 * sizeof(char));

    // Read input for N entries
    for(int i=0; i<N; i++){
        string[0]='\0';  // Clear the string buffer
        scanf("%lld,%s",&integer[i],string);  // Read the integer part and decimal part (as string)
        
        long long j = 0;
        // Convert the decimal part (string) into a long long number
        for(int k = 0; k<9; k++){
            if(string[k]>='0' && string[k]<='9'){  // Check if the character is a digit
                j = j + (string[k]-'0');  // Convert the character to its numeric value
            }
            j *= 10;  // Shift the number to the left (prepare for the next digit)
        }
        decimal[i] = j;  // Store the decimal part
    }

    int P;
    scanf("%d",&P);  // Read the number of queries

    // Process each query
    for (int i=0; i<P; i++){
        long long Pc;  // Integer part of the query
        long long Pd;  // Decimal part of the query
        string[0]='\0';  // Clear the string buffer
        scanf("%lld,%s",&Pc,string);  // Read the integer part and decimal part (as string)
        
        long long p = 0;
        // Convert the decimal part (string) into a long long number
        for(int k = 0; k<9; k++){
            if(string[k]>='0' && string[k]<='9'){  // Check if the character is a digit
                p = p + (string[k]-'0');  // Convert the character to its numeric value
            }
            p *= 10;  // Shift the number to the left (prepare for the next digit)
        }
        Pd = p;  // Store the decimal part

        // Binary search initialization to find the matching record
        int max = N-1;
        int min = 0;
        int avg;
        int was = 0;  // Flag to indicate if the record was found

        // Binary search loop
        while(min <= max && was == 0){
            avg = min + (max-min)/2;  // Calculate the midpoint index

            if(integer[avg] == Pc){  // If the integer part matches the query
                if(Pc < 0){  // Handle negative integer parts
                    if(Pd < decimal[avg]){
                        min = avg+1;
                    }
                    else if(Pd > decimal[avg]){
                        max = avg-1;
                    }
                    else{
                        was = 1;  // Record found
                    }
                }
                else{  // Handle positive integer parts
                    if(Pd < decimal[avg]){
                        max = avg-1;
                    }
                    else if(Pd > decimal[avg]){
                        min = avg+1;
                    }
                    else{
                        was = 1;  // Record found
                    }
                }
            }
            else if(integer[avg] > Pc){
                max = avg-1;  // Adjust search range
            }
            else{
                min = avg+1;  // Adjust search range
            }
        }

        // If the record is not found, print 0
        if(was == 0){
            printf("0");
        }
        else{
            // Print the 1-based index of the record
            printf("%d",avg+1);
        }

        // Print newline for each query except the last one
        if(i!=P-1){
            printf("\n");
        }
    }

    // Free allocated memory
    free(integer);
    free(decimal);
    free(string);
}
