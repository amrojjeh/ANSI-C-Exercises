#include <stdio.h>
#include <string.h> // Used for strcpy
#define TRUE 1
#define FALSE 0

void squeeze(char s1[], char s2[]); // Deletes each character in s1 that matches any character in the string s2

int main()
{
	char string[1000];
	
	strcpy(string, "This is a test");
	squeeze(string, "this");
	printf("This is a test [this] == T  a e : %s\n", string);
	
	strcpy(string, "Wow this is so cool");
	squeeze(string, " ");
	printf("Wow this is so cool [ ] == Wowthisissocool : %s\n", string);

	strcpy(string, "No no no");
	squeeze(string, "");
	printf("No no no [] == No no no : %s\n", string);

	strcpy(string, "Wow this is cool");
	squeeze(string, "Wow this is cool");
	printf("Wow this is cool [Wow this is cool] == : %s\n", string);

	strcpy(string, "How dare you!");
	squeeze(string, "I don't dare");
	printf("How dare you! [I don't dare] == Hwyu! : %s\n", string);
	return 0;
}

void squeeze(char s1[], char s2[])
{
	int i, j;
	for (i = j = 0; s1[i] != '\0'; ++i)
	{
		int found = FALSE;
		for (int x = 0; s2[x] != '\0' && !found; ++x) if (s1[i] == s2[x]) found = TRUE;
		if (!found)
			s1[j++] = s1[i];
	}
	s1[j] = '\0';
}
