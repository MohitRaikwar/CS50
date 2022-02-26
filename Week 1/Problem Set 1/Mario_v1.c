#include<stdio.h>
#include<ctype.h>
#include<stdbool.h>
int main()
{
    int n;
    do
    {
        printf("Enter height of pyramid :");
        scanf("%i",&n);

    } while (n<1 || n>8 );

    for(int x=1;x<=n;x++)
    {
        for(int i=0;i<n-x;i++)
        {
            printf(" ");
        }
        for(int j=0;j<x;j++)
        {
            printf("#");
        }
        printf("\n");    
    }
    
}