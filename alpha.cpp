#include <bits/stdc++.h>
using namespace std;

int main() {
	 	string s;
	 	cin>>s;
	 	int c=1;
	 	int n=s.length();
	 	int i=0,mn=0;
	 	while(i<n)
	 	{
	 		if(s[i]==s[i+1])
	 		{
	 			c++;
	 			i++;
	 		}
	 		else
	 		{
	 			mn=max(mn,c);
	 			i++;
	 			c=1;
	 		}
	 	}
	 	cout<<mn;
}
