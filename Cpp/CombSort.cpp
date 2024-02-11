// C++ program to sort an array using the Comb Sort algorithm
#include <iostream>
#include <cmath>
using namespace std;

// to sort arr[] of size n using comb sort
void CombSort(int arr[], int n)
{
    //set the inital variables
    int gap = n;
    double shrink = 1.3;
    bool sorted = false;


    while (!sorted)
    {
        // recalculate gap
        gap = floor(gap / shrink);

        // gap cannot be less than 1
        if (gap <= 1)
        {
            sorted = true;
            gap = 1;
        }
        
        for (int i = 0; i < n - gap; i++)
        {
            if (arr[i] > arr[i+gap])
            {
                // swap values in the array
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                sorted = false;
            }
        }
    }
}

//main driver code
int main() 
{ 
	int arr[] = { 12, 3, 4, 7, 14, 25, 1, -3, -6, 17 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	CombSort(arr, n); 

	cout << "Here is the sorted array: \n"; 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 

	return 0;
};
