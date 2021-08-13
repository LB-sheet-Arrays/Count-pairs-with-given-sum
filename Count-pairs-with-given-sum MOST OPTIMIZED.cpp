/*
Time Complexity: O(n) 
Auxiliary Space: O(n)

Use map

Functions to be used:
end():  Returns an iterator pointing to the position past the last element in the container in the unordered_map containe
find(): returns an iterator or a constant iterator that refers to the position where the key is present in the map. 
        If the key is not present in the map container, it returns an iterator or a constant iterator which refers to map.end().
//at() sidha key ki value return karta hai

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
	int count=0,difference,position,key;
	
	//create a map
	unordered_map<int, int> m;
	/*
	Elements store karo pehle map me
	*/
	for(int i=0;i<n;i++)
	{
		key=a[i];
		m.insert(make_pair(key,1));
	}
	
	//checking for pair
	for(int i=0;i<n;)
	{
			cout<<"\n\na[i] => "<<a[i];
			difference=sum-a[i];
			cout<<"\ndifference => "<<difference;
			// Key is not present, insert key and count
    		if (m.find(difference)==m.end())
    		{
    			cout<<"\nKey not present isiliye aage badho";
    			i++; //difference agar nhi hai to aage badho
			}
			// Key is present, return count + frequency
			else if(m.find(difference)!=m.end())
			{
				cout<<"\nKey present to count++";
				//find the position of that key in map and store it in variable
				count=count+m.at(difference);
				//us key ko ab delete kar do taaki double count naa ho jaise (1,5) and (5,1) count hora tha
				m.erase(difference);
				m.erase(a[i]);
				cout<<"\ncount => "<<count;
				i++;
			}
		       
	}
	
	return count;
	
}

int main()
{
	//static inputs
	int arr[] = {1, 5, 7, -1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 6;
    
    if(n>=2)
    {
    	cout << "\n\nCount of pairs is \n\n"<< getPairsCount(arr, n, sum);
	}
	else
	{
		cout<<"\nAtleast do to hona na";
	}
    
	return 0;
}
