
// ICPC Champion is here

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
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
multiset<int> s1,s2,s;
int n,m;
vector<int> v;

int getbest(int f,int val)
{

    if(f==0)
        s=s2;
     else
        s=s1;


        int fr=1,sec=1;
        int mx1= (m-1)-val;
        int mx2=  mx1+m;

        auto it=s.upper_bound(mx1);
        multiset<int> :: iterator pos1;
        if(it==s.begin())
            fr=0;
        else
         {
             it--;
            pos1= it;
         }

        auto it2= s.upper_bound(mx2);

        it2--;
        auto pos2= it2;

        if(fr==0)
        {
            return (*it2);
        }
        else
        {
            if((val+(*it))%m   > (val+(*it2))%m )
            return (*it);

           return (*it2);
        }
    }
int main()
{
    cin>>n>>m;
    int no;
    for(int i=0;i<n;i++)
        cin>>no,s1.insert(no);

    for(int i=0;i<n;i++)
        cin>>no,s2.insert(no);

    while(!s1.empty())
    {
        int a=(*s1.begin());
        int b= getbest(0,a);
        int c= getbest(1,b);

            v.pb((c+b)%m);

            s1.erase(s1.find(c));
            s2.erase(s2.find(b));

    }

    sort(allr(v));
   for(int i=0;i<sz(v);i++)
    cout<<v[i]<<" ";
}
