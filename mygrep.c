#include <stdio.h>
#include <string.h>

void main()
{
    printf("welcome to my grep program \n");
    char filename[10],pattern[10],temp[1000];
    FILE *fptr;

    printf("enter the file name to open in reading mode \n");
    scanf("%s",filename);

    printf("enter the patter to be searched \n");
    scanf("%s",pattern);

    fptr = fopen(filename,"r");
    while(!feof(fptr))
    {
        fgets(temp,1000,fptr);
        if(strstr(temp,pattern))
        {
            printf("%s",temp);
        }
    }
    fclose(fptr);

}