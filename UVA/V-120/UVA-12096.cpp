/*
topic : tree isomorophism
explanation : we will use 2 maps one to map a set of integers ( elements in the node of stack ) to an id 
and the other map from the id to the set so we can make union and intersection we use also set bec they needed
to be sorted, we have 5 operations push we will push an empty set ( its id ) to stack dup just push the top
union and intersect we will deal with the set i mapped to, add i will insert the first to the set of the second
and the ans will be the siz of the set of the top of the stack.

complexity : O( n^2*log(n) )
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
map< set<int> ,int> mb;
map<int,set<int>> rmb;
int name(set<int> s);
 int fununion( set<int> v1, set<int> v2)
{
     set<int> v3;
    set_union(all(v1),all(v2),inserter(v3,v3.begin()));
    return name(v3);
}
 int funinter( set<int> v1, set<int> v2)
{
     set<int> v3;
    set_intersection(all(v1),all(v2),inserter(v3,v3.begin()));
    return name(v3);
}
int name(set<int> s)
{
   if( mb.find(s)==mb.end())
   {
      int id= sz(mb);
       mb[s]=id;
       rmb[id]=s;
       return id;
   }
   else
    return mb[s];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        stack< int > s;
        mb.clear();
        rmb.clear();
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            string st;
            char f[50];
            scanf("%s",f);
            st=f;
            if(st=="PUSH")
            {
                s.push(name(set<int>()));
               printf("0\n");
            }
            else if(st=="DUP")
            {
               s.push(s.top());
              printf("%d\n", sz(rmb[s.top()]) );
            }
            else if(st=="UNION")
            {
              int  v1=s.top();
                s.pop();
               int v2=s.top();
                s.pop();
                int v3= fununion(rmb[v1],rmb[v2]);
               s.push(v3);
                printf("%d\n", sz(rmb[s.top()]) );

            }
            else if(st=="INTERSECT")
            {
                 int v1=s.top();
                s.pop();
               int v2=s.top();
                s.pop();
                int v3= funinter(rmb[v1],rmb[v2]);
               s.push(v3);
               printf("%d\n", sz(rmb[s.top()]) );
            }
            else if(st=="ADD")
            {
                int v1= s.top();
               s.pop();
                int v2=s.top();
               s.pop();
               set<int> v3= rmb[v2];
               v3.insert(v1);
               s.push(name(v3));
               printf("%d\n", sz(rmb[s.top()]) );
            }
        }
        printf("***\n");
    }
}
