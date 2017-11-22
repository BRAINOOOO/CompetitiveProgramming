/*
explanation : here we can think of the problem as subproblems first we will need
to store the prefix , suffix , sum and the overall max we can reach, the maxleft we
can reach is either the left of the first range or sum of all left range plus the left
range of the right node and the max right is either the right of the right node or its 
sum plus the right of left node and the max can reach is either the max of the left node
or the max of the right node or the left of right node + right of the left node modifing
is a not a big deal we just modify it normally.

complexity : O( q*log(n) )
*/
#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
#define    clr(v,d)      memset( v, d ,sizeof(v))
#define    vi       vector<int>
#define    vd       vector<double>
#define    vvi      vector< vector<int> >
#define    vvll      vector< vector<long long> >
#define    vvpi     vector< vector< pair<int,int> > >
#define    vvpll     vector< vector< pair<long long,long long> > >
#define    vvd      vector< vector<double> >
#define    vs       vector<string>
#define    vvs      vector< vector<string> >
#define     vpi        vector< pair<int ,int> >
#define      pi        pair<int ,int>
#define      pll       pair<long long ,long long>
#define     vpd        vector< pair<double ,double> >
#define     vpll        vector< pair<long long ,long long> >
#define    vll       vector<long long>
#define    dqi        deque< int >
#define     si         set<int>
#define     spi        set< pair<int ,int > >
#define     row          vector< ll >
#define     matrix            vector< row >
#define     si         set<int>
#define    oo         900000000000000000
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
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
int setBit0(int num, int idx) {return num & ~(1<<idx);}
int flipBit(int num, int idx) {return num ^ (1<<idx);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
typedef struct node
{
    int l,r,mx,sum;
 
    node(int tl,int tr,int tmx,int tsum)
    {
        l=tl;
        r=tr;
        mx=tmx;
        sum=tsum;
    }
}Node;
 
vector< Node > tree(131071+9,node(0,0,0,0));
int arr[50000+9];
inline int max3(int a,int b,int c)
{
    return max(max(a,b),c);
}
 
void build(int s,int e,int p)
{
    if(s>e)
        return ;
    if(s==e)
    {
         tree[p]=node(arr[s],arr[s],arr[s],arr[s]);
         return ;
    }
    int mid=(s+e)/2;
    build(s,mid,p*2);
    build(mid+1,e,2*p+1);
    tree[p].l=max(tree[2*p].l,tree[2*p].sum+tree[2*p+1].l);
    tree[p].r=max(tree[2*p+1].r,tree[2*p+1].sum+tree[2*p].r);
    tree[p].sum=tree[2*p].sum+tree[2*p+1].sum;
    tree[p].mx=max3(tree[p*2].mx,tree[2*p+1].mx,tree[2*p].r+tree[2*p+1].l);
 
}
void update(int id,int val,int s,int e,int p)
{
    if(s>e)
        return ;
    if(s==e)
    {
        tree[p]=node(val,val,val,val);
        return;
    }
    int mid=(s+e)/2;
    if(id<=mid)
        update(id,val,s,mid,p*2);
    else
        update(id,val,mid+1,e,p*2+1);
    tree[p].l=max(tree[2*p].l,tree[2*p].sum+tree[2*p+1].l);
    tree[p].r=max(tree[2*p+1].r,tree[2*p+1].sum+tree[2*p].r);
    tree[p].sum=tree[2*p].sum+tree[2*p+1].sum;
    tree[p].mx=max3(tree[p*2].mx,tree[2*p+1].mx,tree[2*p].r+tree[2*p+1].l);
}
node query(int a,int b,int s,int e,int p)
{
   if(a>e||b<s||s>e)
    return node(-1000000,-1000000,-1000000,-1000000);
    
   if(s>=a&&e<=b)
    return tree[p];
    
   int mid=(s+e)/2;
   
    node lf=query(a,b,s,mid,2*p);
    node rg=query(a,b,mid+1,e,2*p+1);
    
    node res=node(0,0,0,0);
    res.l=max(lf.l,lf.sum+rg.l);
    res.r=max(rg.r,rg.sum+lf.r);
    res.sum=lf.sum+rg.sum;
    res.mx=max3(lf.mx,rg.mx,lf.r+rg.l);
   return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    build(0,n-1,1);
   int m;
    scanf("%d",&m);
    while(m--)
    {
        int st,x,y;
        scanf("%d %d %d",&st,&x,&y);
        if(!st)
        {  x--;
            update(x,y,0,n-1,1);
        }
        else
        {  x--; y--;
            printf("%d\n", query(x,y,0,n-1,1).mx );
        }
    }
}
