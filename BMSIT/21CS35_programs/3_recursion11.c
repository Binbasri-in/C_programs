// 3.11 Recursive program to solve The Towers of Hanoi problem
// Path: 21CS32_programs\3_recursion11.c
#include <stdio.h>

int count = 0;

// prototypes
void tower(int n, char source, char destination, char auxiliary);

// main function
int main()
{
    // read the number of disks
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    // solve the problem
    tower(n, 'S', 'D', 'T');
    // print the result
    printf("Total number of moves: %d\n", count);
}

// tower function
void tower(int n, char source, char destination, char auxiliary)
{
    // termination condition
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        count++;
        return;
    }
    // recursive call
    tower(n - 1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    count++;
    tower(n - 1, auxiliary, destination, source);
}

// Output:
// Enter the number of disks: 3
// Move disk 1 from S to D
// Move disk 2 from S to T
// Move disk 1 from D to T
// Move disk 3 from S to D
// Move disk 1 from T to S
// Move disk 2 from T to D
// Move disk 1 from S to D
// Total number of moves: 7
