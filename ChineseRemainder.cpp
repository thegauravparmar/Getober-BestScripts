#include<bits/stdc++.h>
using namespace std;

int inverse(int a, int b){
    for(int j=1; j<b; j++){
        if((a*j)%b == 1){
            return j;
        }
    }
}

int main() {
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int num[n], rem[n], p[n], inv[n], prod=1, x=0;

    cout<<"Enter the numbers: ";
    for(int i=0; i<n; i++){
        cin>>num[i];
        prod *= num[i];
    }
    cout<<"Enter the remainders: ";
    for(int i=0; i<n; i++)
        cin>>rem[i];

    // p[i] is product of all num[] divided by num[i]
    for(int i=0; i<n; i++){
        p[i] = prod/num[i];
    }

    //Finding modular multiplicative inverse of p[i]
    for(int i=0; i<n; i++){
        int a = p[i], b = num[i];
        inv[i] = inverse(a, b);
    }

    // x = (∑(rem[i]*p[i]*inv[i])) % prod
    for(int i=0; i<n; i++) {
        x = (x%prod + (rem[i]*p[i]*inv[i])%prod) % prod;
    }
    cout<<"Smallest value of x: "<<x;
    return 0;
}
