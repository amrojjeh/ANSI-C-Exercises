#define NUMBER '0'

int getop(char []); // Gets next number or operator and returns the type
void push(double n);
double pop(void);
double seek(void); // Seeks the top element without popping it
void duplicate(void); // Duplicates the top two elements
void clear(void); // Clears the stack
void swap(void);
int getch(void);
void ungetch(int);