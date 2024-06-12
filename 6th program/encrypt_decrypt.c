#include <stdio.h>

int main() {
    int i, x; // Variable declarations
    char str[100]; // Array to store the input string

    // Prompt the user to enter a string
    printf("\nPlease enter a string:\t");
    fgets(str, 100, stdin); // Read the input string from the user

    // Display options for the user
    printf("\nPlease choose one of the following options:\n");
    printf("1 = Encrypt the string.\n");
    printf("2 = Decrypt the string.\n");
    scanf("%d", &x); // Read the user's choice

    // Using switch case to handle encryption and decryption
    switch(x) {
        case 1:
            // Encrypt the string by shifting each character by 3 positions in the ASCII table
            for(i = 0; (i < 100 && str[i] != '\0'); i++) {
                str[i] = str[i] + 3; // Add 3 to the ASCII value of each character
            }
            // Print the encrypted string
            printf("\nEncrypted string: %s\n", str);
            break;

        case 2:
            // Decrypt the string by shifting each character back by 3 positions in the ASCII table
            for(i = 0; (i < 100 && str[i] != '\0'); i++) {
                str[i] = str[i] - 3; // Subtract 3 from the ASCII value of each character
            }
            // Print the decrypted string
            printf("\nDecrypted string: %s\n", str);
            break;

        default:
            // Handle invalid choices
            printf("\nError: Invalid choice\n");
    }

    return 0; // End of the program
}
