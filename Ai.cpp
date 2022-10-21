#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long int n;
	cin>>n;
	long long int count=0;
	long long int arr[n-1];
	for(int i=0;i<n-1;i++)
	{
		cin>>arr[i];
		count=count+arr[i];
	}
	cout<<(n*(n+1)/2)-count;
	return 0;
}
