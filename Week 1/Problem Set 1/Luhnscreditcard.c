#include<stdio.h>
#include<cs50.h>
int digitcalc(long int);
int digitsum(long int);
int cardtype(long int);
void checkcard(long int);
int firsttwo(long int);
int main()
{
 long int i =get_long("Enter card no. :");
 printf("%li",i);
 printf("\nNo. of digits :%i",digitcalc(i));
 checkcard(i);
 return 0;

}
int digitcalc(long int n)
{
  int count=0;
  do{
     n/=10;
     count++;

  }while(n!=0);
  return count;
}
void checkcard(long int n)
{
  int sum1=0;
     int sum2=0;
     int type;
     long int temp=n;
  do{
      sum1+=temp%10;
      temp/=10;
      int j=2*(temp%10);
      if(digitcalc(j)>1)
      {
       sum2+=digitsum(j);
      }
      else
      {
      sum2+=j;
      }
      temp/=10;
    }while(temp!=0);
  int sum=sum1+sum2;
  printf("\nSum1=%i",sum1);
  printf("\nSum2=%i",sum2);
  type=cardtype(n);
  if((sum%10)==0 && (type!=0))
  {
    switch(type)
  {
  case 0:printf("\nINVALID card no.");
         break;
  case 1:printf("\nAmerican Express Card");
         break;
  case 2:printf("\nMaster Card");
         break;
  case 3:printf("\nVISA Card");
         break;
  default:printf("\nSomething went wrong");
         break;
  }
}
  else
  {
  printf("\nCard no is invalid..");
  }
}

  
int digitsum(long int n)
{
 int sum=0;
 do{
 sum+=n%10;
 n/=10;
 }while(n!=0);
 return sum;
}
int cardtype(long int n)
{
  int f=firsttwo(n);   // Find first two digits
  if(digitcalc(n)==15) //For American Express Card
  {

  if(f==34||f==37)
  return 1; // 1 for American Express Card

  }
  else if(digitcalc(n)==16)
  {
  //for Master Card
  if(f==51||f==52||f==53||f==54||f==55)
  {
   return 2; // 2 for Master Card
  }
  int visa =f/10;
  if(visa==4)
  {
   return 3; //3 for Visa card
  }
  else
  {return 0;}
  }
  else
  {
  return 0;
  }

}
int firsttwo(long int n)
{
while(digitcalc(n)>2)
  {
   n/=10;
  }
  return n;

}
