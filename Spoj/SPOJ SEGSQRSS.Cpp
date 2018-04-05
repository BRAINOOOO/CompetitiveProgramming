/*
the idea of the problem is  x^2 + y^2 + z^2   to become  (x+H)^2 + (y+H)^2 + (z+H)^2  yu have to add h*(range)+2*h*(x+y+z)
*/
#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
#define    clr(v,d)      memset( v, d ,sizeof(v))
#define   angle(n)      atan2((n.imag()),(n.real()))
#define   vec(a,b)       ((b)-(a))
#define   length(a)      hypot( (a.imag()),(a.real()) )
#define   normalize(a)      (a)/(length(a))
#define    dp(a,b)          (((conj(a))*(b)).real())
#define    cp(a,b)          (((conj(a))*(b)).imag())
#define    lengthsqrt(a)       dp(a,a)
#define    rotate0( a,ang)    ((a)*exp( point(0,ang) ))
#define    rotateA(about,p,ang)   (rotate0(vec(about,p),ang)+about)
#define    lcm(a,b)                ((a*b)/(__gcd(a,b)))
#define    reflection0(m,v)         (conj((v)/(m))*(m))
#define     reflectionA(m,v,p0)     (conj( (vec(p0,v))/(vec(p0,m)) ) * (vec(p0,m)) ) + p0
#define     same(p1,p2)               ( dp(  vec(p1,p2),vec(p1,p2)) < eps )
#define     point                    complex<double>
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
const int MAX=(1<<18);
pair<ll,ll> tree[MAX];
pair<ll,ll> lazy[MAX];
ll n,arr[100009];

void build(int s=1,int e=n,int root=1)
{

    if(s==e)
    {
        tree[root].first= arr[s];
        tree[root].second= arr[s]*arr[s];
        return;
    }
    int mid=(s+e)>>1;

    build(s,mid,root*2);
    build(mid+1,e,root*2+1);

    tree[root].first= tree[root*2].first+tree[root*2+1].first;
    tree[root].second= tree[root*2].second+ tree[root*2+1].second;


}

void apply(int root,int s,int mid,int e)
{


    int lf=root*2;
    int rg=root*2+1;
    if(lazy[root].second==-1)
    {

     if(lazy[lf].second==-1)
    lazy[lf].first+=lazy[root].first;
     else
    lazy[lf].second+=lazy[root].first;
    
    
    if(lazy[rg].second==-1)
    lazy[rg].first+=lazy[root].first;
     else
    lazy[rg].second+=lazy[root].first;
    
    tree[lf].second+= tree[lf].first*2*lazy[root].first+(lazy[root].first*lazy[root].first*(mid-s+1));
    tree[lf].first+= lazy[root].first*(mid-s+1);

    tree[rg].second+=  tree[rg].first*2*lazy[root].first+(lazy[root].first*lazy[root].first*(e-(mid+1)+1));
    tree[rg].first+=   lazy[root].first*(e-(mid+1)+1);

    lazy[root].first=0;
    }
    else if(lazy[root].second!=-1)
    {
    
    
    lazy[lf].second=lazy[root].first,lazy[lf].first=0;
    
    lazy[rg].second=lazy[root].first,lazy[rg].first=0;
    
    
    tree[lf].second= lazy[root].second*lazy[root].second*(mid-s+1);
    tree[lf].first= lazy[root].second*(mid-s+1);

    tree[rg].second=  lazy[root].second*lazy[root].second*(e-(mid+1)+1);
    tree[rg].first=   lazy[root].second*(e-(mid+1)+1);


    lazy[root].second=-1;

    }
}










void update(int a,int b,int v,int f,int s=1,int e=n,int root=1)
{

    if(a>e||b<s)
        return ;

    if(a<=s&&e<=b)
    {

        if(f==0)
        {


            tree[root].second=(v*v)*(e-s+1);
            tree[root].first= v*(e-s+1);
            lazy[root].first=0;
            lazy[root].second=v;
            return ;

        }
        else
        {

            ll add= 2*v*tree[root].first;
            ll w= (v*v)*(e-s+1);

            tree[root].second+=add+w;
            tree[root].first+= v*(e-s+1);
            if(lazy[root].first==0)
            {
                lazy[root].second+=v;

            }
            else
            {
            lazy[root].first+=v;
            lazy[root].second=0;
            }
            return;
        }
    }
    ll mid=(s+e)>>1;
    apply(root,s,mid,e);

    update(a,b,v,f,s,mid,root*2);
    update(a,b,v,f,mid+1,e,root*2+1);

    tree[root].second= tree[root*2].second+tree[root*2+1].second;
    tree[root].first= tree[root*2].first+tree[root*2+1].first;

}

ll query(int a,int b,int s=1,int e=n,int root=1)
{
    if(a>e||b<s)
        return 0;



    if(a<=s&&e<=b)
        return tree[root].second;

    ll mid=(s+e)>>1;
    apply(root,s,mid,e);

   return query(a,b,s,mid,root*2)+query(a,b,mid+1,e,root*2+1);

}












int main()
{
    int t;
    cin>>t;

    for(int cs=1;cs<=t;cs++)
    {
        int q;
        cin>>n>>q;
        for(int i=0;i<100000;i++)
            lazy[i].second=-1;
        for(int i=1;i<=n;i++)
          cin>>arr[i];
        cout<<"Case "<<cs<<":\n";
        build();
        while(q--)
        {
            int st,a,b,x;
            cin>>st;
            if(st==2)
            {
                cin>>a>>b;
                cout<<query(a,b)<<endl;
            }
            else if(st==0)
            {
                cin>>a>>b>>x;

                update(a,b,x,0);
            }
            else
             {
                 cin>>a>>b>>x;
                update(a,b,x,1);
             }
        }
    }
}

