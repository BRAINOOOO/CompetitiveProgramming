/*
Here it direct RMQ problem i think the only trick is that the size of string wont exceed 30 chars so thats why it fits with 
simple implementation so the only advice here is to take care of constrains 
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
vi v;
int tree[262143+9],arr[100000+9];
char st[30+9];
void update(int place,int num,int s,int e,int p)
{
    if(s==e)
     {
         tree[p]=num;
        return;
     }

    if(place<=(s+e)/2)
        update(place,num,s,(s+e)/2,p*2);
    else
        update(place,num,(s+e)/2+1,e,2*p+1);


   tree[p]=min(tree[2*p],tree[2*p+1]);


   return ;

}
int query(int from,int to,int s,int e,int p)
{
    if(from>e||to<s)
        return 1000000;
    if(from<=s&&to>=e)
        return tree[p];
    int mid=(s+e)/2;

    return min(query(from,to,s,(s+e)/2,2*p),query(from,to,mid+1,e,2*p+1));
}


void format()
{
    v.clear();
    int siz=strlen(st);
    int s=0;

  for(int i=0;i<siz;i++)
  {
    s=0;
    while(i<siz&&isdigit(st[i]))
    {
        s=s*10+st[i]-'0';
        i++;

    }
    if(s)
    v.pb(s);
  }



}
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);

    for(int i=0;i<262143+9;i++)
        tree[i]=1000000;

    for(int i=1;i<=n;i++)
    {
     scanf("%d",&arr[i]);
     update(i,arr[i],1,n,1);
    // cout<<tree[i]<<endl;
    }
    while(q--)
    {


        scanf("%s",st);
        format();



        if(st[0]=='q')
        {
           printf("%d\n",query(v[0],v[1],1,n,1));
        }
        else
        {
           int e=arr[v[0]];
            for(int i=0;i<sz(v);i++)
            {
               int f=v[i];
               int nx=v[(i+1)%sz(v)];
                arr[f]=arr[nx];

            }

           arr[v[sz(v)-1]]=e;


            for(int i=0;i<sz(v);i++)
                update(v[i],arr[v[i]],1,n,1);




        }

    }
}





