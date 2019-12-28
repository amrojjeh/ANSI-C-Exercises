/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each
line of input, and to delete entirely blank lines.
*/

#include <stdio.h>
#define MAX_LINE 1000

int mgetline(char line[], int maxLength); // Gets the next line and returns its length
void mcopy(char frm[], char to[]); // Assumes that the destination buffer is big enough

int main() // example input : "This is a test 		\n0" two tabs C : 14
{
    char line[MAX_LINE];
    int length;
    while (length = mgetline(line, MAX_LINE))
    {
        int cursor;
        int c;
        for (cursor = length - 2; (c = line[cursor]) == ' ' || c == '\t'; --cursor); // We subtract two because we want to skip the newline and 0
        line[cursor + 1] = '\n';
        line[cursor + 2] = 0;
        if (line[0] != '\n') printf("%s", line);
    }
}

int mgetline(char line[], int maxLength) // [T, H, I, S, 0] -> 4
{
    int length = 0;
    int c = 0;
    for (; (c = getchar()) != EOF && c != '\n' && length < maxLength; ++length) line[length] = c;
    
    if (c == '\n')
    {
        line[length] = c;
        ++length;
    }
    line[length] = 0;
    return length;
}
