#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,x,i,day=0,c=0,cured,first,infected,left;
        cin>>n>>x;
        long long int a[n];
        for(i=0; i<n; i++)
            cin>>a[i];
        sort(a,a+n);
        for(i=0; i<n; i++)
        {
            if(x<=a[i])
            {
                first=a[i];
                break;
            }
            c++;
        }
        cured=x;
        while(i<n)
        {
            first=a[i];
            while(cured<first)
            {
                left=first-cured;
                infected=2*left;
                if(infected>first)
                {
                    infected=first;
                    cured=2*cured;
                }
                else
                {
                    cured=infected;
                }
                day++;
            }
            day++;
            cured=2*first;
            i++;
        }
        cout<<c+day;
    }
    return 0;
}
