/*

ROUGH
________________
1 0001
2 0010
3 0011
4 0100
5 0101
6 0110
7 0111
8 1000
9 1001
10 1100

________________

My_Approach1: Niave approach

Make a structure with arr[i] and count_f_set_bits as data members
traverse the given array and at each element count set bits and store the arr[i] and count in struct
sort structure on the basis of count


TC = O(n*(binary length of integer)) + O(nlogn) = O(nlogn) + O(nlogn) => O(nlogn)
binary length of integer ko maan lete ki n ke barabar hi hai

SC = O(2*n) = O(n)

GFG_Approach2:

Using custom comparator of std::sort to sort the array according to set-bit count
Counting set bits take Theta of (log (length of number in binary) time

*/

#include<bits/stdc++.h>
using namespace std;

// a utility function that returns total set bits
// count in an integer
int countBits(int a)
{
    int count = 0;
    while (a) {
        if (a & 1)
            count += 1;
        a = a >> 1;
    }
    return count;
}
 
// custom comparator of std::sort
int cmp(int a, int b)
{
    int count1 = countBits(a);
    int count2 = countBits(b);
 
    // this takes care of the stability of
    // sorting algorithm too
    if (count1 <= count2)
        return false;
    return true;
}
 
// Function to sort according to bit count using
// std::sort
void sortBySetBitCount(int arr[], int n)
{
    stable_sort(arr, arr + n, cmp);
}
 
// Utility function to print an array
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Driver Code
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortBySetBitCount(arr, n);
    printArr(arr, n);
    return 0;
}
