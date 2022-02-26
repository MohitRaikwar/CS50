#include<stdio.h>
#include<cs50.h>
#include<math.h>
int main()
{
    int quarter=25;
    int dimes=10;
    int nickels=5;
    int pennies=1;
    float dollars;
    do
    {
        dollars=get_float("Enter cash owed :");
    } while (dollars<0);
    
    
    printf("\nEntered no. is :%f",dollars);
    int cents=round(dollars*100);
    int tmp=cents;
    int count=0;

        if(tmp>=quarter)
        {
            count=tmp/quarter;
            tmp%=quarter;
        }

        if(tmp>=dimes)
        {
           count+=tmp/dimes;
            tmp%=dimes;
        }
        if(tmp>=nickels)
        {
            count+=tmp/nickels;
            tmp%=nickels;
        }
        if(tmp>=pennies)
        {
            count+=tmp;

        }
    printf("\n%i\n",count);
    return 0;

}