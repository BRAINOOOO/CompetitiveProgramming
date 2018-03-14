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
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1ll;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
int mem[(1<<20)+9];
class  EllysCheckers
{
public:
    int n;

    int solve(int st)
    {

         int &ret=mem[st];
         if(ret!=-1)
            return ret;
         for(int i=n-1;i>=0;i--)
         {
             if(getBit(st,i)==1)
             {

                 if(i-1>=0&&getBit(st,i-1)==0)
                 {
                    int nst= setBit0(st,i);
                     if(i-1!=0)
                     nst= setBit1(nst,i-1);

                     if(solve(nst))
                        return ret=0;

                 }

                 if(i-3>=0&& getBit(st,i-1)==1&&getBit(st,i-2)==1&&getBit(st,i-3)==0)
                 {
                     int nst;

                     nst=setBit0(st,i);
                     if(i-3!=0)
                     nst=setBit1(nst,i-3);

                     if(solve(nst))
                        return ret=0;
                 }


             }
         }

         return ret=1;
    }
    string getWinner(string s)
    {

        int st=0;
        n=sz(s);
        if(s.back()=='o')
            s.back()='.';
        for(int i=0;i<n;i++)
        {
            if(s[i]=='o')
              st=setBit1(st,n-i-1) ;
        }

       clr(mem,-1);

       if(solve(st)==0)
        return "YES";

       return "NO";
    }
};

int main()
{
    string st;
     cin>>st;
    EllysCheckers my;
   cout<< my.getWinner(st);
}
