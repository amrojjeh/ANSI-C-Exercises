#include <stdio.h>

int main()
{
    int array[] = {1, 2, 9, 10};
    printf("5 [1, 2, 9, 10] 4 == -1 : %d\n", binsearch(5, array, 4));
    
    int array1[] = {1, 2, 5, 10};
    printf("5 [1, 2, 5, 10] 4 == 2 : %d\n", binsearch(5, array1, 4));

    int array2[] = {1, 2, 4};
    printf("2 [1, 2, 4] 4 == 1 : %d\n", binsearch(2, array2, 3));

    int array3[] = {1, 2, 4};
    printf("3 [1, 2, 4] 4 == -1 : %d\n", binsearch(3, array3, 3));
}

// binsearch: find x in v[0] <= v[1] <= ... <= v[n - 1], where the index is x
int binsearch(int x, int v[], int n)
{
    int low, mid, high;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (x != v[mid] && low < high)
    {
        if (x < v[mid]) high = mid - 1;
        else low = mid + 1;
        mid = (low + high) / 2;
    }
    if (x == v[mid]) return mid;
    return -1;
}