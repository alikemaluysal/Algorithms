#include <assert.h>
#include <stdio.h>

int binary_search_recursive(const int *arr, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binary_search_recursive(arr, l, mid - 1, x);

        return binary_search_recursive(arr, mid + 1, r, x);
    }

    return -1;
}

int binarysearch_iterative(const int *arr, int l, int r, int x)
{
    int mid = l + (r - l) / 2;

    while (arr[mid] != x)
    {
        if (r <= l || r < 0)
            return -1;

        if (arr[mid] > x)
            r = mid - 1;
        else
            l = mid + 1;

        mid = l + (r - l) / 2;
    }

    return mid;
}

void test()
{
    int arr[] = {1, 3, 4, 6, 8, 11, 14, 17, 23, 29, 33, 35, 38, 40};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("----Test 1----\n");

    int x = 14;
    int result = binary_search_recursive(arr, 0, n - 1, x);
    assert(result == 6);
    printf("passed recursive...\n");


    result = binarysearch_iterative(arr, 0, n - 1, x);
    assert(result == 6);
    printf("passed iterative...\n");

    printf("----Test 2----\n");
    x = 5;
    result = binary_search_recursive(arr, 0, n - 1, x);
    assert(result == -1);
    printf("passed recursive...\n");
    
    result = binarysearch_iterative(arr, 0, n - 1, x);
    assert(result == -1);
    printf("passed iterative...\n");
}

int main(void)
{
    test();
    return 0;
}