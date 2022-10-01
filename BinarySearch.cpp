#include <bits/stdc++.h>
using namespace std;

int binarysearch(int a[], int n, int key) {
  int l = 0, h = n - 1;
  while (l <= h) {
    int mid = (l + h) / 2;
    if (a[mid] > key)
      h = mid - 1;
    else if (a[mid] < key)
      l = mid + 1;
    else
      return mid;
  }
  return -1;
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int key;
	cin>>key;
	int u = binarysearch(a, n, key);
     if (~u)
       cout << "Key Found at " << (u + 1) << "th position\n";
     else
       cout << "Key does not found\n";
}
	

