#include <stdio.h>

int main()
{
    int i, j, k, a[50], frame[20], n, no, avail, count = 0;
    
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    
    printf("Enter the page numbers: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    printf("Enter the number of frames: ");
    scanf("%d", &no);
    
    for(i = 0; i < no; i++)
    {
        frame[i] = -1;
    }
    
    j = 0;
    
    printf("\nRef String\tPage Frames\n");
    
    for(i = 0; i < n; i++)
    {
        printf("%d\t\t", a[i]);
        avail = 0;
        
        for(k = 0; k < no; k++)
        {
            if(frame[k] == a[i])
            {
                avail = 1;
                break;
            }
        }
        
        if(avail == 0)
        {
            frame[j] = a[i];
            j = (j + 1) % no;
            count++;
            
            for(k = 0; k < no; k++)
            {
                printf("%d\t", frame[k]);
            }
            printf("\n");
        }
    }
    
    printf("\nPage Fault is %d\n", count);
    
    return 0;
}
