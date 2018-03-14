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
int mem[(1<<14)+9][2],n;

class  RowAndCoins
{

public :
    string s;

    int solve(int st,int t)
    {
       int &ret=mem[st][t];
       if(ret!=-1)
            return ret;

       int ones= countNumBit1(st);
       if(ones==n-1)
       {
           for(int i=0;i<n;i++)
           {

               if(getBit(st,n-1-i)==0)
               {

                   if(s[i]=='A')
                   {

                       if(t==1)
                       return ret=1;

                       return ret=0;

                   }
                   else
                   {
                       if(t==1)
                       return ret=0;

                       return ret=1;

                   }
                    break;
               }
           }
       }

        for(int l=0;l<n;l++)
        {
            for(int r=l;r<n;r++)
            {
                int fl=0,nst;
                nst=st;
                for(int i=l;i<=r;i++)
                {
                    if(getBit(st,n-1-i)==1)
                        fl=1;
                }

                if(!fl&&(n-((r-l+1)+ones))>=1)
                {
                   for(int i=l;i<=r;i++)
                   {
                       nst=setBit1(nst,n-1-i);
                   }

                   if(solve(nst,t^1))
                   {

                    return ret=0;
                   }

                }
            }
        }

        return ret=1;
    }

     string getWinner(string ss)
     {

         s=ss;
         int st=0;
         n=sz(s);
         clr(mem,-1);
            if(solve(st,0)==0);
            return "Alice";

         return "Bob";

     }
};
/*
int main()
{
    RowAndCoins my;
    string st;
    cin>>st;
    cout<<my.getWinner(st);

}
/*
