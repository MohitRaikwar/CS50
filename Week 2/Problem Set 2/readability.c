#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int count_letters(string text);
int count_sentences(string text);
int count_words(string text);
int readability_index(int letters,int words,int sentences);
int main()
{
  string str=get_string("Text :");
  int letters=count_letters(str);
  int words=count_words(str);
  int sentences=count_sentences(str);
  int index=readability_index(letters,words,sentences);
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
    int count=0;
    for(int i=0;text[i]!='\0';i++)
    {
      if(text[i]=='-' && isalpha(text[i-1])) {}
      else if(text[i]==39 && isalpha(text[i-1])) {}
      else if(!isalpha(text[i]) && isalpha(text[i-1]))
      {
        count++;
      }
      //if( text[i]==' ')
      //count++;
    }
    return count;
}
int readability_index(int letters,int words,int sentences)
{
  float words_per_100=words/100.0;
  float L=letters/words_per_100;
  float S=sentences/words_per_100;
  int index=round(0.0588*L - 0.296*S - 15.8);
  return index;

}