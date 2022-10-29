#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        long long int sum=0;
        cin>>n;
        int s[n];
        for(i=1; i<=n; i++)
        {
            cin>>s[i];
        }
        for(i=1; i<=n-1; i++)
        {
            if(s[i]<s[i+1])
            {
                sum+= s[i+1]-s[i]-1;
            }
            else if(s[i]>s[i+1])
            {
                sum+= s[i]-s[i+1]-1;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
