#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main()
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    if(score1>score2)
     printf("Player 1 wins!\n");
    else if(score2>score1)
     printf("Player 2 wins !\n");
    else
     printf("Tie!\n");
    return 0;
}

int compute_score(string word)
{
    int score=0;
    for(int i=0;word[i]!='\0';i++)
    {
      if(isalpha(word[i]))
      {
        word[i]=toupper(word[i]);
        score+=POINTS[(int)word[i]-65];
      }
      
      /*word[i]=tolower(word[i]);
      if(word[i]=='a')
      score+=POINTS[0];
      else if(word[i]=='b')
      score+=POINTS[1];
      else if(word[i]=='c')
      score+=POINTS[2];
      else if(word[i]=='d')
      score+=POINTS[3];
      else if(word[i]=='e')
      score+=POINTS[4];
      else if(word[i]=='f')
      score+=POINTS[5];
      else if(word[i]=='g')
      score+=POINTS[6];
      else if(word[i]=='h')
      score+=POINTS[7];
      else if(word[i]=='i')
      score+=POINTS[8];
      else if(word[i]=='j')
      score+=POINTS[9];
      else if(word[i]=='k')
      score+=POINTS[10];
      else if(word[i]=='l')
      score+=POINTS[11];
      else if(word[i]=='m')
      score+=POINTS[12];
      else if(word[i]=='n')
      score+=POINTS[13];
      else if(word[i]=='o')
      score+=POINTS[14];
      else if(word[i]=='p')
      score+=POINTS[15];
      else if(word[i]=='q')
      score+=POINTS[16];
      else if(word[i]=='r')
      score+=POINTS[17];
      else if(word[i]=='s')
      score+=POINTS[18];
      else if(word[i]=='t')
      score+=POINTS[19];
      else if(word[i]=='u')
      score+=POINTS[20];
      else if(word[i]=='v')
      score+=POINTS[21];
      else if(word[i]=='w')
      score+=POINTS[22];
      else if(word[i]=='x')
      score+=POINTS[23];
      else if(word[i]=='y')
      score+=POINTS[24];
      else if(word[i]=='z')
      score+=POINTS[25];
      else
      score+=0;
    }*/
    }
    return score;
}
