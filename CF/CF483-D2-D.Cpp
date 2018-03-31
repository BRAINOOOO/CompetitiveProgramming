/*
explanation : the topic used is segment tree , each node express the mask of its range.
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
const int MAX= 262143;

int tree[MAX],ans[100009],n,m,vis[100009][33],L[100009],R[100009],Q[100009];
pair<int,int> lazy[MAX];

void apply(int root,int st,int mid,int en)
{
    if(lazy[root].first==-1)
        return;
    int ri= root*2;  int lf=root*2+1;
    lazy[ri].second|=lazy[root].second;
    lazy[ri].first=0;
    lazy[lf].second|=lazy[root].second;
    lazy[lf].first=0;
    tree[ri]|=lazy[root].second;
    tree[lf]|=lazy[root].second;

    lazy[root].first=-1;
}




void update(int a,int b,int val,int st,int en,int root)
{

    if(b<st||a>en)
        return ;

    if(a<=st&&en<=b)
    {
        lazy[root].second|=val;
        lazy[root].first=0;
        tree[root]|=val;
        return ;
    }

     int mid= (st+en)>>1;

     apply(root,st,mid,en);

     update(a,b,val,st,mid,root*2);
     update(a,b,val,mid+1,en,root*2+1);

}
int query(int a,int b,int st,int en,int root)
{
    if(a>en||b<st)
        return 0;


    if(a<=st&&en<=b)
    {
        return tree[root];
    }

    int mid=(st+en)>>1;

    apply(root,st,mid,en);

   return query(a,b,st,mid,root*2)+query(a,b,mid+1,en,root*2+1);
}

bool check()
{

   for(int i=1;i<=n;i++)
   {
       int v=ans[i];

       for(int j=0;j<32;j++)
       {

           if(getBit(v,j)==1)
           {
               vis[i][j]=  vis[i-1][j] +1;
           }
           else
             vis[i][j]=  vis[i-1][j] ;


       }
   }

   for(int i=0;i<m;i++)
   {
       int l=L[i]; int r=R[i]; int q=Q[i];

       for(int j=0;j<32;j++)
       {
           if(getBit(q,j)==1)
           {
               if(vis[r][j]-vis[l-1][j] != r-l+1)
                return 0;
           }
           else
           {
               if(vis[r][j]-vis[l-1][j]==r-l+1)
                return 0;
           }
       }

   }
   
   return 1;

}

int main()
{
    cin>>n>>m;
    for(int i=0;i<MAX;i++)
        lazy[i].first=-1,lazy[i].second=0;
    for(int k=0;k<m;k++)
    {
        int l,r,q;
        cin>>l>>r>>q;
        L[k]=l; R[k]=r; Q[k]=q;
        update(l,r,q,1,n,1);
    }

    for(int i=1;i<=n;i++)
    {
        ans[i]=query(i,i,1,n,1);
    }

    if(check())
    {
        cout<<"YES\n";
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<" ";

    }
    else
        cout<<"NO\n";
}
