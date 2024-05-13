#include <iostream>
using namespace std;
int max(int arr[], int size)
{
int m = arr[0];
for (int i = 1; i < size; i++)
{
if (arr[i] > m)
{
m = arr[i];
}
}
return m;
}
void countSort(int arr[], int size)
{
int k = max(arr, size);
int count[10]{};
for (int i = 0; i < size; i++)
{
count[arr[i]]++;
}
for (int i = 1; i <= k; i++)
{
count[i] += count[i - 1];
}
int output[size];
for (int i = size - 1; i >= 0; i--)
{
output[--count[arr[i]]] = arr[i];
}
for (int i = 0; i < size; i++)
{
arr[i] = output[i];
}
}
int main()
{
int arr[] = {4, 1, 9, 7, 3, 1, 2, 5, 6, 8};

countSort(arr, 10);
for (int i : arr)
{
cout << i << " ";
}
return 0;
}
