#include<stdio.h>
#include<ctype.h>
#include<cs50.h>
#include<string.h>
string encipher(string str,string key);
int test_arguments(int arguments,string key[]);
int main(int argc,char*argv[])
{
    
    if(test_arguments(argc,argv))
    {
        return 1;
    }
    else
    {
        string key=argv[1];
        string plaintext=get_string("plaintext: ");
        printf("ciphertext: %s\n",encipher(plaintext,key));
   }
   return 0;
}
int test_arguments(int arguments,string key[])
{
    if(arguments!=2)
    {
        printf("Usage : ./substitution key.\n");
        return 1;
    }
    else if(strlen(key[1])!=26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for(int i=0,n=strlen(key[1]);i<n;i++)
    {
        char i_char=key[1][i];
        if(!isalpha(key[1][i]))
        {
          printf("Keys must contain only alphabetic characters.\n");
          return 1;
        }
        for(int j=0;j<n;j++)
        {
          char j_char=key[1][j];
          if(toupper(i_char)==toupper(j_char) && i!=j)
          {
              printf("Key must not contain repeated characters.\n");
              return 1;
          }
        }
    }
    return 0;
}
string encipher(string str,string key)
{
   int ch;
   for(int i=0;str[i]!='\0';i++)
   {
       if(isalpha(str[i]))
       {
        if(isupper(str[i]))
       {
           ch=(int)str[i]-65;
           str[i]=toupper(key[ch]);
       }
        if(islower(str[i]))
        {
            ch=(int)str[i]-97;
            str[i]=tolower(key[ch]);
        }
       }
   }
   return str;
}