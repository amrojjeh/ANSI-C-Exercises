#define swap(t, x, y) {t temp = y; y = x; x = temp;}

int main()
{
	int a = 13;
	int b = 14;
	swap(int, a, b);
	printf("a:%d\nb:%d\n", a, b);
}