#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int count_letters(string text);
int count_sentences(string text);
int count_words(string text);
int main()
{
  string str=get_string("Text :");
  int letters=count_letters(str);
  int words=count_words(str);
  int sentences=count_sentences(str);
  float L=floor(100*((float)letters/(float)words)*100)/100;   //setting precision upto 2 floating points
  float S=floor(100*((float)sentences/(float)words)*100)/100;
  int index=round(0.0588*L - 0.296*S - 15.8);                 //Coleman-Liau index
  printf("%f %f \n",L,S);
  if(index < 1)
  printf("Before Grade 1\n");
  else if(index > 16)
  printf("Grade 16+\n");
  else
  printf("Grade %i\n",index);
  
  return 0;
}
int count_letters(string text)
{
  int count=0;
  for(int i=0;text[i]!='\0';i++)
  {
      if(isalpha(text[i]))
      count++;
  }
  return count;
}
int count_sentences(string text)
{
    int count=0;
    for(int i=0;text[i]!='\0';i++)
    {
      if( text[i]=='.'|| text[i]=='?' || text[i]=='!')
      count++;
    }
    return count;
}
int count_words(string text)
{
    int count=1;
    for(int i=0;text[i]!='\0';i++)
    {
      if( text[i]==' ')
      count++;
    }
    return count;
}