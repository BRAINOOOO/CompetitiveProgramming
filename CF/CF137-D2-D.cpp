/*
explanation : here in this problem you can think of geting the K sub strings using dp
but we will noticed that we want tknow the cost of every range to turn it to palindrome
we can do so by a preprocessed array ( consider even and odd palindrome ) then we will 
min on cost.

complextiy : O(n^3)
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
string s;
int n,cost[500+9][500+9],mem[500+9][500+9];
int fun(int start,int k)
{
    if(start==n)
    {
        if(k>=0)
        return 0;
      return 10000000;
    }
    int &ret=mem[start][k];
    if(ret!=-1)
        return ret;
    int ans=10000000;
    for(int i=start;i<n;i++)
    {
        ans=min(ans, cost[start][i]+fun(i+1,k-1));
    }
    return ret=ans;
}
void print (int i,int j)
{
    if(i)
        cout<<"+";
    cout<<s.substr(i,(j-i+2)>>1);
    string s1=s.substr(i,(j-i+1)>>1);
    reverse(all(s1));
    cout<<s1;
}
void out(int start,int k)
{
    if(start==n)
    {
        return ;
    }

    int &ret=mem[start][k];


    for(int i=start;i<n;i++)
    {
        if(ret== cost[start][i]+fun(i+1,k-1))
        {
            print(start,i);

            return out(i+1,k-1);
        }
    }
}
int main()
{
    int k;
    cin>>s>>k;
    n=sz(s);
   for(int l=0;l<n;l++)
   {
      int c=0;
       for(int i=l,j=l;i>=0&&j<n;i--,j++)
       {
           if(s[i]!=s[j])
           {
               c++;
           }
           cost[i][j]=c;
       }
       c=0;
       for(int i=l,j=l+1;i>=0&&j<n;j++,i--)
       {
           if(s[i]!=s[j])
            c++;
           cost[i][j]=c;
       }
   }
   clr(mem,-1);
   cout<< fun(0,k) <<endl;
   out(0,k);
   cout<<endl;
}
