/*
Time Complexity: O(n) 
Auxiliary Space: O(n)

Use map

Functions to be used:
end():  Returns an iterator pointing to the position past the last element in the container in the unordered_map containe
find(): returns an iterator or a constant iterator that refers to the position where the key is present in the map. 
        If the key is not present in the map container, it returns an iterator or a constant iterator which refers to map.end().
at() sidha frequency return karta hai

>> ek map bnao jisme key= array element and value = frequency ho
>> int difference=sum-a[i]
>> check if difference(will act as key) is already in the map, hai to count ko uski frequency se badhao bcoz utne hi pairs banenge
>> if nhi hai to insert karo us key koand aage badho
>> baari baari a[i] daalte jao map me and count badhao uska
>> 

>> corner case: agar a[i]>sum hai to usko skip karo bcoz usme aur kuch add karke sum laana possible nhi
>> n>=2

*/

#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <iterator>
using namespace std;

int getPairsCount(int a[], int n, int sum)
{
	int count=0,difference,position;
	
	//create a map
	unordered_map<int, int> m;
	
	for(int i=0;i<n;i++)
	{
		if(a[i]<sum)
		{
			difference=sum-a[i];
		
			// Key is not present, insert key and count
    		if (m.find(difference)==m.end())
    		{
    			m.insert(make_pair(difference,1));
			}
			// Key is present, return count + frequency
			else if(m.find(difference)!=m.end())
			{
				//find the position of that key in map and store it in variable
				count=count+m.at(difference);
			}
		}        
	}
	
	return count;
	
}

int main()
{
	//static inputs
	int arr[] = { 1, 5, 7, -1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 6;
    
    if(n>=2)
    {
    	cout << "\n\nCount of pairs is \n\n"<< getPairsCount(arr, n, sum);
	}
    
	return 0;
}
