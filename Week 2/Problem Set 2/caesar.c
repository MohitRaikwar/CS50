#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
string cipher_text(string str,int key);
int main(int argc,char* argv[])
{
    if(argc!=2)
    {
        printf("Usage : ./caesar key\n");
        return 1;
    }
    int k=atoi(argv[1]);        //ASCII to int
    printf("%i\n",k);
    string plain_text=get_string("Plaintext : ");
    string ciphertext=cipher_text(plain_text,k);
    printf("Cipher text :%s\n",ciphertext);
    return 0;
}
string cipher_text(string str,int key)
{
  if(key>26)
  {
      key=key/26;
  }
  for(int i=0;str[i]!='\0';i++)
  {
      if(isalpha(str[i]))
      {
          int val=(int)str[i]+key;
          if(isupper(str[i]) && val >90)
          {
              str[i]=(char)(val%26+52);
          }
          else if(islower(str[i]) && val > 122)
          {
              str[i]=(char)(val%26+78);
          }
          else 
          str[i]+=key;
      }
      
  }
  return str;
}