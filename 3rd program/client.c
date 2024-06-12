#include<stdio.h>
#include<stdlib.h>

int main() {
    FILE *fp1, *fp2;
    int i;
    char c, cnt = 49;

    fp1 = fopen("fp1.txt", "r");
    fp2 = fopen("fp2.txt", "w");

    if (fp1 == NULL) {
        printf("Cannot open fp1.txt");
        exit(1);
    } else if (fp2 == NULL) {
        printf("Cannot open fp2.txt");
        exit(1);
    } else {
        c = getc(fp1);
        while (c != EOF) {
            putc(cnt++, fp2);
            fputs(", 192.168.1.1, 192.168.1.2, ", fp2); // Added space after the comma
            for (i = 0; i < 5; i++) {
                c = getc(fp1);
                putc(c, fp2);
            }
            putc(10, fp2);
        }
        printf("Frames generated in fp2.txt file.");
        fclose(fp1);
        fclose(fp2);
    }
    return 0;
}
