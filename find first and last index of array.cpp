#include <iostream>
using namespace std;

int firstPosition(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            high = mid - 1;   // search on left side
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int lastPosition(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            low = mid + 1;   // search on right side
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int n = 7;
    int key = 2;

    int first = firstPosition(arr, n, key);
    int last = lastPosition(arr, n, key);

    cout << "First Position: " << first << endl;
    cout << "Last Position: " << last << endl;

    return 0;
}
