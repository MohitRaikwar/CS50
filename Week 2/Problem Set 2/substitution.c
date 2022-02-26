#include<stdio.h>
#include<ctype.h>
#include<cs50.h>
#include<string.h>
string cipher_text(string str,string key);
int main(int argc,char*argv[])
{
    if(argc!=2)
    {
        printf("Usage : ./substitution key\n");
        return 1;
    }
    string key=argv[1];
    int length=strlen(key);
    bool is_not_alpha=false;
    bool repetition=false;
    for(int i=0;key[i]!='\0';i++)
    {
        if(!isalpha(key[i]))
        {
          is_not_alpha=true;
        }
    }
    for(int i=0;key[i]!='\0';i++)
    {
      for(int j=i+1;key[j]!='\0';j++)
      {
          if(key[i]==key[j])
          repetition=true;
      }
    }
    if(length!=26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    if( is_not_alpha)
    {
        printf("Keys should contain only characters/n");
        return 1;
    }
    if(repetition)
    {
        printf("Repetition of keys are not allowed \n ");
        return 1;
    }
    string plaintext=get_string("Plaintext : ");
    string ciphertext=cipher_text(plaintext,key);
    printf("ciphertext : %s\n",ciphertext);
    return 0;
}
string cipher_text(string str,string key)
{
   for(int i=0;str[i]!='\0';i++)
   {
       if(isalpha(str[i]))
       {
        if(isupper(str[i]))
       {
           int ch=(int)str[i]-65;
           str[i]=toupper(key[ch]);
       }
        if(islower(str[i]))
        {
            int ch=(int)str[i]-97;
            str[i]=tolower(key[ch]);
        }
       }
   }
   return str;
}