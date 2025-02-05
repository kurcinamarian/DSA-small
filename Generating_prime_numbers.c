#include <stdlib.h>
#include <stdio.h>

// Function to check if a number is prime
int is_prime(int n){
    // Handle base cases for 0 and 1
    if(n==0)
        return 0;  // 0 is not prime
    if(n==1)
        return 0;  // 1 is not prime

    // Check divisibility from 2 up to the square root of n
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){  // If n is divisible by i, it's not prime
            return 0;
        }
    }

    return 1;  // Return 1 if no divisors found, meaning n is prime
}

int main(){
    int a;
    int b;
    short was = 0;  // Flag to track if a prime number has been printed

    // Read the range [a, b] from input
    scanf("%d %d",&a, &b);

    // Loop through the range [a, b] to find prime numbers
    for(int i=a; i<=b;i++){
        if(is_prime(i)){  // If the number is prime
            // Print a comma before the number if it's not the first prime number
            if (was)
                printf(", %d",i);
            else
                printf("%d",i);

            was = 1;  // Set flag to indicate that a prime has been printed
        }
    }
}
