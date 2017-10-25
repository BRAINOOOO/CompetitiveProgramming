/*
Here i think the idea is greedy :
first you have to observe that every new height must be counted and 
if its a pervious height to be considered as an expand to pervious 
block all the blocks between them must be greater than or equal to 
its height otherwise cosider it a new block.
implementation : 
how we can get the min height in a range so we need RMQ ( segment tree).
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
#define root 1
#define lft 2*idx
#define rgt 2*idx+1
#define cllft lft,st,mid
#define clrgt rgt,mid+1,ed
int nd[4*100000],pre[100000],a[100000];
map<int,int> mb;
void update(int place,int num,int s,int e,int p)
{
    if(place<s||place>e)
        return;

    if(s==e)
     {
         nd[p]=num;
        return;
     }

    if(place<=(s+e)/2)
        update(place,num,s,(s+e)/2,p*2);
    else
        update(place,num,(s+e)/2+1,e,2*p+1);


    nd[p]=min(nd[p*2],nd[2*p+1]);

   return ;

}

int query(int idx,int st,int ed,int s,int e)
{
    if(st==s && ed==e)return nd[idx];
    int mid=(st+ed)/2;
    if(e<=mid)
        return query(cllft,s,e);
    else if(s>mid)return query(clrgt,s,e);
    else return min(query(cllft,s,mid),query(clrgt,mid+1,e));
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int n,i,res,x,t=1;
	while(cin>>n)
    {
	    mb.clear();
        clr(a,0);
	    clr(nd,0);
	    for(i=1;i<=n;i++)
        {
	        scanf("%d",&a[i]);


	        update(i,a[i],1,n,1);
	    }
	    res=0;
	    for(i=1;i<=n;i++)
        {
	        if(a[i]!=0 && mb.find(a[i])!=mb.end())
	        {
	            x=query(root,1,n,mb[a[i]],i);
	            //cout<<i<<" "<<pre[i]<<" "<<x<<endl;
	            if(x<a[i])res++;
	        }
	        else if(a[i])res++;

	        mb[a[i]]=i;
	    }
	    printf("Case %d: %d\n",t++,res);
	}
	return 0;
}



