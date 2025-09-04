#include <stdio.h>
#include <string.h>

int words(char book[])
{
    int number_of_words = 1;
    for (int i = 0; i < strlen(book); i++)
    {
        if (book[i] == ' ')
        {
            number_of_words += 1;
        }
    }

    return number_of_words;
}

int sentence(char book[])
{
    int number_of_sentences = 0;
    for (int i = 0; i < strlen(book); i++)
    {
        if (book[i] == '.' || book[i] == '?' || book[i] == '!')
        {
            number_of_sentences += 1;
        }
    }

    return number_of_sentences;
}

int calculate_L(char book[])
{
    float L = 0;
    float L1 = 0;
    int number_of_words=words(book);
    
        for (int i = 0; i < strlen(book); i++)
        {
            
            if (book[i] == ' ' || book[i] == '.' || book[i] == '!' ||
                book[i] == '?' || book[i] == '-' || book[i] == '—' ||
                book[i] == ',' || book[i] == ':' || book[i] == '"' ||
                book[i] == '\'' || book[i] == '/' || book[i] == '*' ||
                book[i] == ';' || book[i] == '(' || book[i] == ')' ||
                book[i] == '…' || book[i] == '&')
            {
                continue;
            }
            else
            {
                L1 += 1;
            }
        }
    L = (L1 / number_of_words)*100 ;
    return L;
}

int calculate_s(char book[]){
    float S;
    float number_sent = sentence(book);
    float number_words= words(book);

    S=(number_sent/number_words)*100;
    return S;
}

// index = 0.0588 * L - 0.296 * S - 15.8

// where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

// Specification

// For the purpose of this problem, we’ll consider any sequence of characters separated by a space to be a word (so a hyphenated word like “sister-in-law” should be considered one word, not three). You may assume that a sentence:

// will contain at least one word;
// will not start or end with a space; and
// will not have multiple spaces in a row.

int main()
{
char book[100000];
float index,L,S;
int l,s;
printf("Enter the story\n");
gets(book);
l=words(book);
s=sentence(book);
L=calculate_L(book);
S=calculate_s(book);
index = (0.0588 * L) - (0.296 * S) - 15.8;
if (index<1){

    printf("Before Grade 1");
}

else if(index>=16){
    
    printf("Grade 16+");
}
else{
printf("Grade %.0f\n", index);}
// printf("Grade %d\n", (int)index);}
    return 0;
}