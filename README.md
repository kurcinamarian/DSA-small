# Collection of small programs made for the subject Data Structures and Algorithms in the Summer Semester of 2024

## Generating prime numbers

Your task is to generate all prime numbers within a given interval, meaning numbers that are greater than or equal to the first given number and less than or equal to the second given number.

Input:

Two numbers in the range from 0 to 1,000,000, separated by a single space. These numbers define the interval.

Output:

A list of generated prime numbers within the specified interval, with numbers separated by a comma and a space.

<br><br>

## Searching rational numbers in a sequence

Your task is to create a program that first reads an increasing sequence of rational numbers and stores this sequence. You can only use data types for whole numbers and characters (e.g., int, long, or char) to represent the numbers—floating-point types like float should not be used. These rational numbers have a precision of 0 to 10 digits after the decimal point.

After reading the sequence, the program will receive an arbitrary rational number (in the same format as the sequence). The program should find this number in the stored sequence and return its position (i.e., its index, starting from 1). If the number is not found in the sequence, the program should return 0.

Input:

An integer N (1 ≤ N ≤ 50,000) represents the length of the sequence.
N lines follow, each containing one number from the sequence.
An integer M (1 ≤ M ≤ 100,000) represents the number of queries.
M lines follow, each containing one number that needs to be searched in the sequence.

Output:

For each searched number, print its position in the sequence (1-based index) on a new line. If the number is not found, print 0.

<br><br>

## Brackets

Your task is to analyze a set of sequences consisting of pairs of parentheses:

(), [], {}, and <>.

A sequence is considered incorrect if:

- A pair is missing either its opening or closing parenthesis.
- A mismatched pair is found (e.g., (], <}).
- Parentheses are not correctly nested.

Input:

The first line contains an integer N (1 ≤ N ≤ 200), representing the number of sequences.
The next N lines each contain a sequence of parentheses.
Each sequence has a length between 1 and 100,000 characters.

Output:

For each sequence, print a single integer representing the number of errors in that sequence.
Each output should be on a separate line
