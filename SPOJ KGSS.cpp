/*
here the same concept if i want to max on 1 num in a range but it is a little bit difficult because here yu need a data structure in side 
segment tree to allow you merging and storing two numbers so i use the struct but it can be in many ways.
*/
#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
#define   mp         make_pair
#define   mt         make_tuple
#define   inf        0x7fffffff
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
#define     vc        vector<char>
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
#define    lp(i,n)    for(i=0;i<n;i++)
#define     si         set<int>
#define    oo         100000000000000000
#define   MOD         1000000007
#define    X            real
#define    Y            imag
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
#define    scani(n)                  scanf("%d",&n)
#define    scanll(n)                  scanf("%I64d",&n)
#define    printi(n)                 printf("%d",n)
#define    printll(n)                 printf("%I64d",n)
#define    scand(n)                  scanf("%lf",&n)
#define    printd(n)                 printf("%lf",n)
#define    scans(n)                  scanf("%s",&n)
#define    prints(n)                 printf("%s",n)
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
const double  PI= acos(-1.0);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
int setBit0(int num, int idx) {return num & ~(1<<idx);}
int flipBit(int num, int idx) {return num ^ (1<<idx);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int N=100000,a[100000+9];
 
struct node
{
    int mx1,mx2;
 
    node()
    {
        mx1=-1000000000;
        mx2=-1000000000;
    }
    node(int v)
    {
        mx1=v;
        mx2=-1000000000;
    }
 
   void mrge(node a,node b)
    {
        vi v;
        v.pb(a.mx1);
        v.pb(a.mx2);
        v.pb(b.mx1);
        v.pb(b.mx2);
        sort(all(v));
 
 
        mx1=v[2];
        mx2=v[3];
 
    }
}tree[262143+9];
 
void build(int id, int left ,int right)
{
	if(left == right)
	{
		tree[id] = node(a[left]);  
		return;
	}
	int mid = (left+right)/2;
	build(2*id , left , mid);
	build(2*id+1,mid+1,right);
	tree[id] = node();
	tree[id].mrge(tree[2*id],tree[2*id+1]);
}
void update(int place,int num,int s=1,int e=N,int p=1)
{
    if(s==e)
     {
        tree[p]=node(num);
        return;
     }
 
    if(place<=(s+e)/2)
        update(place,num,s,(s+e)/2,p*2);
    else
        update(place,num,(s+e)/2+1,e,2*p+1);
 
    tree[p]=node();
 
    tree[p].mrge(tree[2*p],tree[2*p+1]);
}
node query(int from,int to,int s=1,int e=N,int p=1)
{
    if(from>e||to<s)
        return node();
 
    if(from<=s&&to>=e)
        return tree[p];
 
    int mid=(s+e)/2;
 
    if(to<=mid)
        query(from,to,s,mid,2*p);
    if(from>mid)
        query(from,to,mid+1,e,2*p+1);
 
    node a=query(from,to,s,mid,2*p);
    node b=query(from,to,mid+1,e,2*p+1);
 
    node temp=node();
 
    temp.mrge(a,b);
 
    return temp;
}
 
 
 
 
 
 
 
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n,q;
    scanf("%d",&n);
    int no;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        
    }
   build(1,1,N);
 
    scanf("%d",&q);
   char ch;
   int a,b;
 
    for(int i=0;i<q;i++)
    {
         
       scanf(" %c",&ch);
 
        if(ch=='Q')
        {
           scanf("%d%d",&a,&b);
 
          node m1= query(a,b);
          printf("%d\n",m1.mx1+m1.mx2);
 
        }
        else
        {
            scanf("%d%d",&a,&b);
            update(a,b);
        }
    }
 
 
}
 
 
 
 
 
