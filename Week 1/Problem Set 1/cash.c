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
    } while (dollars<=0);
    
    
    printf("\nEntered no. is :%f",dollars);
    int cents=round(dollars*100);
    int tmp=cents;
    int coins=0;

        if(tmp>=quarter)
        {
            coins=tmp/quarter;
            tmp%=quarter;
        }

        if(tmp>=dimes)
        {
           coins+=tmp/dimes;
            tmp%=dimes;
        }
        if(tmp>=nickels)
        {
            coins+=tmp/nickels;
            tmp%=nickels;
        }
        if(tmp>=pennies)
        {
            coins+=tmp;

        }
    printf("\n%i\n",coins);
    return 0;
    /*Alternative
    while(cents>0)
    {
        if(cents>=25)
         cents-=25;
        else if(cents>=10)
         cents-=10;
        else if(cents>=5)
         cents-=5;
        else
         cents--;
        coins++;
    }
    */

}