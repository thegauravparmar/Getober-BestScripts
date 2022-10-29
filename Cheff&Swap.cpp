#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,c=0,k=-1,l=-1,temp=0,d=0,count =0,prevl=-1,prevk=-1;
        long long int cost=0;
        cin>>n;
        long long int a[n],b[n];
        for(i=1; i<=n; i++)
            cin>>a[i];
        for(i=1; i<=n; i++)
            cin>>b[i];

        //while(c!=n)
       // {
            sort(a+1,a+n+1);
            sort(b+1,b+n+1);

            for(i=1; i<=n; i++)
            {
                if(a[i]==b[i])
                    c++;
                else if(a[i]!=b[i] && n==1)
                    d++;
                else if(k<0)
                {
                    k=i;
                }
                else if(k>=0 && l<0)
                {
                    l=i;
                    temp=a[k];
                    a[k]=b[l];
                    b[l]=temp;
                    cost+=min(a[k],b[l]);
                    i=-1;
                    sort(a,a+n);
                    sort(b,b+n);
                    if(prevl==l && prevk==k)
                        break;
                    prevl=l;
                    prevk=k;
                    l=-1;
                    k=-1;
                    count=1;
                    c=0;
                }
            }
            if(c==n && count==0)
            {
                cout<<"0"<<endl;
            }
            else if(d==1)
            {
                cout<<"-1"<<endl;
            }
            else if(c==n && count>0)
                cout<<cost<<endl;
            else if(c!=n)
            {
                cout<<"-1"<<endl;
            }
        //}
    }
    return 0;
}
