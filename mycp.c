#include <stdio.h>
#include <stdlib.h> // For exit()

int main()
{
    printf("welcome to mycp\n");
    FILE *fptr1, *fptr2;
    char filename1[100], filename2[100], c;
 
    printf("Enter the filename to open for reading (e.g., 1.txt): \n");
    scanf("%s", filename1);
 
    // Open one file for reading
    fptr1 = fopen(filename1, "r");
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s \n", filename1);
        exit(0);
    }
 
    printf("Enter the filename to open for writing (e.g., 2.txt): \n");
    scanf("%s", filename2);
 
    // Open another file for writing in append mode
    fptr2 = fopen(filename2, "w");
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s \n", filename2);
        exit(0);
    }
 
    // Read contents from file
    c = fgetc(fptr1);
    while (c != EOF)
    {
        fputc(c, fptr2);
        c = fgetc(fptr1);
    }
 
    printf("\nContents copied to %s\n", filename2);
 
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}
