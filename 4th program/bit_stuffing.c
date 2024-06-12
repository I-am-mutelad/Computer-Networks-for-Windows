#include <stdio.h>

// Function for bit stuffing
void bitStuffing(int N, int arr[])
{
    // Stores the stuffed array
    int brr[30];

    // Variables to traverse arrays
    int i, j, k;
    i = 0;
    j = 0;

    // Loop to traverse in the range [0, N)
    while (i < N) {
        // If the current bit is a set bit
        if (arr[i] == 1) {
            // Stores the count of consecutive ones
            int count = 1;

            // Insert into array brr[]
            brr[j++] = arr[i];

            // Loop to check for next 5 bits
            for (k = i + 1; k < N && arr[k] == 1 && count < 5; k++) {
                brr[j++] = arr[k];
                count++;

                // If 5 consecutive set bits are found, insert a 0 bit
                if (count == 5) {
                    brr[j++] = 0;
                    break;
                }
            }

            // Update i to continue from the next bit after the sequence
            i = k;
        }
        // Otherwise insert arr[i] into the array brr[]
        else {
            brr[j++] = arr[i++];
        }
    }

    // Print Answer
    for (i = 0; i < j; i++) {
        printf("%d", brr[i]);
    }
    printf("\n");
}

// Driver Code
int main()
{
    int N;
    printf("Enter the number of bits: ");
    scanf("%d", &N);

    int arr[N];
    printf("Enter the bits (0 or 1) separated by space: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    bitStuffing(N, arr);

    return 0;
}
