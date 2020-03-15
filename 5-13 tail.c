#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 1000

#define MORE_INFO 0

char* nextLine(char** lines, int n);

#if MORE_INFO
static int newAdditionsSinceCompression = 0;
static int totalCompressions = 0;
#endif

int main(int argc, char* argv[])
{
	int N = 10;
	if (argc > 1)
	{
		N = atoi(argv[1]);
		if (N == 0)
		{
			printf("Usage: tail -n");
			return -1;
		}
	}

	char* lines[MAXLINES];
	char* line;

	for (int lineNumber = 0; (line = nextLine(lines, N)) != NULL; ++lineNumber)
	{
		if (lineNumber >= N)
		{
			for (int x = 0; x < N - 1; ++x)
				lines[x] = lines[x + 1];
			lines[N - 1] = line;
		}
		else lines[lineNumber] = line;
	}

	printf("=====================\n");

	for (int x = 0; x < N; ++x)
		printf("%s\n", lines[x]);

	#if MORE_INFO
	printf("Total compressions: %d\n", totalCompressions);
	#endif
	return 0;
}

#define MAXLINE 100

int getline(char* line)
{
	int c, len;
	for (len = 0; len < MAXLINE && (c = getchar()) != EOF && c != '\n'; ++len)
		line[len] = c;
	if (c == EOF) return -1;
	line[len] = 0;
	return len;
}

#define MAXBUF 10000

static char buffer[MAXBUF];
static char* nextAvailableSpace = buffer;
static int linesStored = 0;
static char line[MAXLINE];

void shiftBuffer(char** lines, int n);

// n is the amount of lines we care about, and lines are all the n lines stored in buffer.
// We need the array so that we can re-sort it if we need to.
char* nextLine(char** lines, int n)
{
	int length = getline(line);

	// No more lines to store
	if (length == -1) return NULL;

	// Not enough space to store the line, no need to panic
	if (MAXBUF - (nextAvailableSpace - buffer) < length)
	{
		// We have more lines stored than what we need, time to replace them
		if (linesStored > n)
		{
			#if MORE_INFO
			printf("Added %d lines since last compression.\n", newAdditionsSinceCompression);
			newAdditionsSinceCompression = 0;
			++totalCompressions;
			#endif
			shiftBuffer(lines, n);

			// Not enough space, even after our compression. Shit.
			if (MAXBUF - (nextAvailableSpace - buffer) < length)
			{
				printf("ERROR: NOT ENOUGH SPACE AFTER COMPRESSION TO STORE ALL %d LINES\n", n);
				return NULL;
			}
		}

		// Not enough space, when we only have the necessary lines. Panic time.
		else
		{
			printf("ERROR: NOT ENOUGH SPACE BEFORE COMPRESSION TO STORE ALL %d LINES\n", n);
			return NULL;
		}
	}

	// We do have enough space, wonderful!
	strcpy(nextAvailableSpace, line);
	char* newString = nextAvailableSpace;
	nextAvailableSpace += length + 1;
	++linesStored;
	#if MORE_INFO
	++newAdditionsSinceCompression;
	#endif
	return newString;

}

char* firstNeededLine(int lines);
void copy(char* dest, char* src, int length);

void shiftBuffer(char** lines, int n)
{
	char* first = firstNeededLine(linesStored - n);
	copy(buffer, first, nextAvailableSpace - first);
	linesStored = n;

	// Fixing the references
	while (n-- > 0)
		lines[n] = lines[n] - first + buffer;
	nextAvailableSpace = nextAvailableSpace - first + buffer;
}

// strcpy copies until 0, we need to go beyond that.
void copy(char* dest, char* src, int length)
{
	for (int x = 0; x < length; ++x)
		dest[x] = src[x];
}


// Where lines are the amount of uneeded lines
// Assumes that there are enough lines in the buffer
char* firstNeededLine(int lines)
{
	char* ptr = buffer;
	while (lines > 0)
	{
		while (*ptr != 0) ptr += 1;
		--lines;
		ptr += 1;
	}
	return ptr;
}
