#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define ll long long int
#define ld long int
#define nl "\n"
#define ss second
#define ff first
using namespace std;

ll MOD = 1000000007;

struct segtree{
    ll size;
    vector<ll> sums;
    /*Initializing the sums vector size(or we can say segtree)*/
    void init(int n){
        size = 1;
        while(size<n){
            size*=2;
        }
        sums.assign(2*size,0LL);
    }
    /*build part2 -> here we use recursion to iterate over segtree
     and add the value of array to the leaf */
    void build2(vector<ll> &a,ll x,ll lx,ll rx){
        if(rx-lx == 1){
            if(lx<a.size()){
                sums[x] = a[lx];
            }
            return;
        }
        ll m = (lx+rx)/2;
        build2(a,2*x+1,lx,m);
        build2(a,2*x+2,m,rx); 
        sums[x] = sums[2*x+1] + sums[2*x+2];
    }

    /* assigning the values of given vector to segtree*/
    void build(vector<ll> &a){
        build2(a,0,0,size);
    }


    /* setting a particluar value of leaf node of segtree */
    void set(ll i ,ll v,ll x,ll lx,ll rx){
        if(rx-lx == 1){
            sums[x] = v;
            return;
        }
        ll m = (lx+rx)/2;
        if(i<m){
        set(i,v,2*x+1,lx,m);
        }
        else{
        set(i,v,2*x+2,m,rx); 
        }
        sums[x] = sums[2*x+1] + sums[2*x+2];
    }

    void set(ll i,ll v){
        set(i,v,0,0,size);
    }



    /* finding sum now */
    ll sum(ll l ,ll r,ll x,ll lx,ll rx){
        /* if the whole segment is outside the limits then return 0 */
        if(lx>=r || rx<=l){
            return 0;
        }
        /* if the whole segment is inside our limits pick all*/
        else if(lx>=l && rx<=r){
            return sums[x];
        }
        /* else perform recursion to iterate over it and find the sum of particular leaf
        */
        ll m = (lx+rx)/2;
        ll s1 = sum(l,r,2*x+1,lx,m);
        ll s2 = sum(l,r,2*x+2,m,rx); 
        return s1+s2;
        
    }

    ll sum(ll l,ll r){
        return sum(l,r,0,0,size);
    }



};



void todo()
{
    ll n,m;
    cin >> n >> m;
    segtree st;
    st.init(n);
    vector<ll> a(n);
    for(ll i = 0;i<n;i++){
        cin >> a[i];
    }

    st.build(a);

    for(ll j = 0;j<m;j++){
        ll op;
        cin >> op;
        if(op == 1){
            ll i,v;
            cin >> i>> v;
            st.set(i,v);
        }
        else{
            ll l,r;
            cin >> l >> r;
            cout << st.sum(l,r) << nl;
        }



    }



}

int main()
{

    // Main Code
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tt = 1;
    // cin >> tt;
    for (ll i = 1; i <= tt; i++)
    {
        // cout << "Case: " << i  << " ";
        todo();
    }

    return 0;
}