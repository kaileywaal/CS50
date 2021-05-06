#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


int countLetters(string text);
int countWords(string text);
int countSentences(string text);
int findGradeLevel(int letters, int words, int sentences);
void printGrade(int grade);


int main(void)
{
    // Get string from user
    string text = get_string("Text: ");
    // Determine number of letters in string
    int letters = countLetters(text);

    // Determine number of words in string
    int words = countWords(text);

    // Determine number of sentences in string
    int sentences = countSentences(text);

    // Determine grade level of string
    int grade = findGradeLevel(letters, words, sentences);

    // Print out grade level of text
    printGrade(grade);
}

int countLetters(string text)
{
    int letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //check if letter is alphatbetic
        if (isalpha(text[i]))
        {
            letters ++;
        }
    }

    return letters;
}

int countWords(string text)
{
    // Initialize number of words to one
    int words = 1;

    // Count spaces between words to determine how many words there are.
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }

    return words;
}

int countSentences(string text)
{
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Check for period, exclamation point, or question mark
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences++;
        }
    }

    return sentences;
}

int findGradeLevel(int letters, int words, int sentences)
{
    // find average number of letters per 100 words
    float L = (100 * (float) letters) / (float) words;

    // find average number of sentences per 100 words
    float S = (100 * (float) sentences) / (float) words;

    //Use Coleman-Liau index to calculate gradeyes
    float grade = 0.0588 * L - 0.296 * S - 15.8;

    return round(grade);
}

void printGrade(int grade)
{
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", grade);
    }
}

