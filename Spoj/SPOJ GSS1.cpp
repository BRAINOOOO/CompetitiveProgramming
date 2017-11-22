/*
explanation : here we can think of the problem as subproblems first we will need
to store the prefix , suffix , sum and the overall max we can reach, the maxleft we
can reach is either the left of the first range or sum of all left range plus the left
range of the right node and the max right is either the right of the right node or its 
sum plus the right of left node and the max can reach is either the max of the left node
or the max of the right node or the left of right node + right of the left node.

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
struct node
{
    int l,r,mx,sum;
} tree[131071+9];
int max3(int a,int b,int c)
{
    return max(max(a,b),c);
}
int arr[50000+9];
void update(int s,int e,int p)
{

    if(s==e)
    {
        tree[p].l=tree[p].r=tree[p].mx=tree[p].sum=arr[s];
        return;
    }

    int mid=(s+e)/2;

    update(s,mid,p*2);
    update(mid+1,e,p*2+1);

    tree[p].l=max(tree[2*p].l,tree[2*p].sum+tree[2*p+1].l);
    tree[p].r=max(tree[2*p+1].r,tree[p*2+1].sum+tree[2*p].r);
    tree[p].sum=tree[2*p].sum+tree[2*p+1].sum;
    tree[p].mx=max3(tree[p*2].mx,tree[2*p+1].mx,tree[2*p].r+tree[2*p+1].l);

    return ;

}
void query(node &res,int a,int b,int s,int e,int p)
{

    if(s>=a&&e<=b)
    {
         res=tree[p];
         return;
    }
    int mid=(s+e)/2;

    if(b<=mid)
        query(res,a,b,s,mid,2*p);
    else if(a>mid)
        query(res,a,b,mid+1,e,2*p+1);
    else
    {
      node lf,ri;
       query(lf,a,b,s,mid,2*p);
       query(ri,a,b,mid+1,e,2*p+1);
       res.l=max(lf.l,lf.sum+ri.l);
       res.r=max(ri.r,ri.sum+lf.r);
       res.sum=lf.sum+ri.sum;
       res.mx=max3(lf.mx,ri.mx,lf.r+ri.l);
    }
}
int main()
{
    int n;
     scanf("%d",&n);
        int no;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&no);
            arr[i]=no;
        }
        update(0,n-1,1);
        int m;
        scanf("%d",&m);
        int x,y;
        while(m--)
        {
          scanf("%d %d",&x,&y);
            x--;
            y--;
            node res;
            query(res,x,y,0,n-1,1);
            printf("%d\n",res.mx);
        }   
}
