#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAXCODE 800000

int main(int argc, char *argv[])
{
	int c = 0; // Current character
	int prevc = 0; // Previous character
	char prevcc = 0; // Previous previous character, thanks to '\\' and " This is a test \\" "
	int inComment = FALSE; // Inside any comment
	int inLineComment = FALSE; // Inside an inline comment
	int inMLComment = FALSE; // Inside a multiline comment
	int inString = FALSE; // Inside a string such as "This is a string"
	int inChar = FALSE; // Inside a constant such as '"'
	char code[MAXCODE]; // Code buffer
	int index = 0;
	char* testString = "This is a // test, \" I don't want this to be a comment /* if you know what I mean */"; // JUST A TEST
	// This is another test, inline comments make things so damn hard \
	Am I right?
	while ((c = getchar()) != EOF && index != MAXCODE - 1)
	{
		if (((prevc == '\\' && prevcc == '\\') || (prevc != '\\' )) && inComment == FALSE && inString == FALSE && c == '\'')
			inChar = inChar == TRUE ? FALSE : TRUE; // Detect if inside a character constant
		if (((prevc == '\\' && prevcc == '\\') || (prevc != '\\' )) && inComment == FALSE && inChar == FALSE && c == '"')
			inString = inString == TRUE ? FALSE : TRUE; // Detect if inside a string
		if (inChar == FALSE && inString == FALSE && inComment == TRUE && ((inLineComment == TRUE && c == '\n' && prevc != '\\') || (inMLComment == TRUE && c == '/' && prevc == '*'))) // Detect if outside comment
		{
			inComment = FALSE;
			inLineComment = FALSE;
		}
		if (inChar == FALSE && inString == FALSE && prevc == '/' && inComment == FALSE) // Detect if inside comment
		{
			if (c == '/')
			{
				inComment = TRUE;
				inLineComment = TRUE;
				--index;
			}
			else if (c == '*')
			{
				inComment = TRUE;
				inMLComment = TRUE;
				--index;
			}
		}
		if (inComment == FALSE) // Commit uncommented code to buffer
		{
			if (inMLComment == FALSE) code[index++] = c; // Kind of a hack, but it skips the last / character in a multiline comment. Hence why it doesn't get assigned to FALSE when it gets out of the comment, it does it here.
			inMLComment = FALSE;
		}
		prevcc = prevc;
		prevc = c;
	}
	printf("%s", code);
}
