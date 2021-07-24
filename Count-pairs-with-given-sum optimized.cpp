/*
Naive Solution – A simple solution is to traverse each element and check if there’s another number in the array 
which can be added to it to give sum. using 2 loops i and j=i+1

Time Complexity: O(n2) 
Auxiliary Space: O(1)

Another approach:

Sort the array
use 2 pointer approach

corner case n>2 to make a pair

*/

#include <bits/stdc++.h>
using namespace std;

int getPairsCount(int a[], int n, int sum)
{
	int count=0;
	
	sort(a,a+n);
	
	//2 pointers
	int left=0;
	int right=n-1;
	
	while(left<right)
	{
		if(a[left]+a[right]==sum)
		{
			cout<<"\n{ "<<a[left]<<" , "<<a[right]<<" }";
			count++;
			left++;
		}
		else if(a[left]+a[right]<sum)                           //sum aage hoga
		{
			left++;
		}
		else if(a[left]+a[right]>sum)                           //sum piche hoga
		{
			right--;
		}
	}
	
}

int main()
{
	//static inputs
	int arr[] = { 1, 5, 7, -1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 6;
    cout << "\n\nCount of pairs is \n\n"<< getPairsCount(arr, n, sum);
    
	return 0;
}
