#include <stdio.h>
#define MAXLINES 10000
#define MAXLINE 1000
#define LONGLINE 80

int mgetline(char line[], int maxLength); // Gets the next line and returns its length
void appendsString(int indexOfZero, char to[], char from[]); // Add a string to another string

int main()
{
    char longLines[MAXLINES]; // All lines longer than 80 characters
    int index = 0;
    char currentLine[MAXLINE]; // The current line
    int len = 0; // The length of current line

    while ((len = mgetline(currentLine, MAXLINE)) > 0)
    {
        if (len >= LONGLINE)
        {
            appendsString(index, longLines, currentLine);
            index += len;
        }
    }

    if (index > 0) printf("Lines longer than %d\n%s", LONGLINE, longLines);

}


int mgetline(char line[], int maxLength)
{
    int length;
    int c;

    for (length = 0; length < maxLength && (c = getchar()) != EOF && c != '\n'; ++length) line[length] = c;

    if (c == '\n')
    {
        line[length] = c;
        ++length;
    }

    line[length] = 0;
    return length;
}

void appendsString(int indexOfZero, char to[], char from[])
{
    for (int i = 0; (to[indexOfZero + i] = from[i]) != 0; ++i);
}