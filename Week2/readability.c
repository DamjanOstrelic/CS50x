#include <stdio.h>
#include <cs50.h>
#include <string.h>

int getLetters(string text);
int getWords(string text);
int getSentences(string text);
float getGrade(int letters, int words, int sentences);

int main(void)
{
    string textInput = get_string("Enter text: ");
    // printf("Input: %s\n", textInput);
    // printf("Letters: %i\n", getLetters(textInput));
    // printf("Words: %i\n", getWords(textInput));
    // printf("Sentences: %i\n", getSentences(textInput));
    float grade = getGrade(getLetters(textInput), getWords(textInput), getSentences(textInput));
    if (grade < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (grade >= 15.5)
    {
        printf("Grade 16+\n");
        return 0;
    }

    printf("Grade %.0f\n", grade);
    return 0;

}

int getLetters(string text)
{
    int letterCount = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) // letter count
        {
            letterCount++;
        }

    }
    return letterCount;
}

int getWords(string text)
{
    int wordCount = 1;

    for (int i = 0; i < strlen(text); i++) //word count
    {
        if (text[i] == ' ')
        {
            wordCount++;
        }
    }
    return wordCount;
}

int getSentences(string text)
{
    int sentenceCount = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') //sentence count
        {
            sentenceCount++;
        }
    }
    return sentenceCount;
}



float getGrade(int letters, int words, int sentences) //average letters and sentences per 100 words and calculate grade index
{
    float wordFactor = 100 / (float) words;
    float lettersPer100 = letters * wordFactor;
    float sentencesPer100 = sentences * wordFactor;

    float index = (0.0588 * lettersPer100) - (0.296 * sentencesPer100) - 15.8;

    return index;
}

