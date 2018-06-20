
// ICPC champion is here
#include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<map>
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
#define     point                    complex<long double>
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
using namespace std;
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
const int MAX=5009;
int n,m,arr[MAX],GCD[MAX];
vector<int> BAD;
vector<int> FGCD[MAX],A[MAX];
map< int,int> bad;
pair<int,int> state[MAX];

vector<int> primefact(int val)
{
    vector<int> v1;

    if(val==1)
        return vector<int>();

    for(int i=2;i*i<=val;i++)
    {
        while(val%i==0)
            v1.pb(i),val/=i;
    }

    if(val>1)
        v1.pb(val);


    return v1;


}














int main()
{

    cin>>n>>m;

    for(int i=0;i<n;i++)
        cin>>arr[i];
    int no;
    for(int i=0;i<m;i++)
        cin>>no,BAD.pb(no),bad[no]=1;

      for(int i=0;i<n;i++)
     {
         A[i]=primefact(arr[i]);
     }
     int EG=0,EB=0;
     for(int i=0;i<n;i++)
     {

         for(int j=0;j<sz(A[i]);j++)
         {

             if(bad[A[i][j]]==1)
                EB++;
             else
                EG++;


         }


     }

    int g=arr[0];
    for(int i=0;i<n;i++)
    {
      int res=__gcd(g,arr[i]);
        GCD[i]=res;
        g=res;
    }

    for(int i=0;i<n;i++)
    {
        FGCD[i]=primefact(GCD[i]);

    }

    for(int i=0;i<n;i++)
    {
        int G=0,B=0;

        for(int j=0;j<sz(FGCD[i]);j++)
        {
            if(bad[FGCD[i][j]]==1)
                B++;
            else
                G++;
        }

        state[i]=mp(G,B);
    }
    int subG,subB;
    subG=subB=0;
    for(int i=n-1;i>=0;i--)
    {
       int TG=state[i].first-subG;
       int TB=state[i].second-subB;

        if(TB>=TG)
        {
            subG+=TG;
            subB+=TB;

            EG-=(TG*(i+1));
            EB-=(TB*(i+1));

        }

    }

    cout<<EG-EB<<endl;
}


