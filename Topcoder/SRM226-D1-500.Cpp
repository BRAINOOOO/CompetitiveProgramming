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
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
class OneArmedBandit
{
public :
    double progressiveJackpot(vector<string> wh,string jk,vector<string> py)
    {
        int vis[11][29];
        clr(vis,0);
        for(int i=0;i<sz(wh);i++)
        {
            for(int j=0;j<sz(wh[i]);j++)
            {
               int ch=wh[i][j]-'A';
                vis[i][ch]++;
            }
        }
        int l=sz(wh[0]);
        double exj=1.0;
        int fl=0;
        for(int i=0;i<sz(jk);i++)
        {
            if(jk[i]=='-')
            continue;
            int ch=jk[i]-'A';
            if(vis[i][ch]>0)
            {
                exj*=((vis[i][ch]+0.0)/l);
            }
            else
            {
                fl=1;
                break;
            }
        }
       double r=0.0;
       for(int i=0;i<sz(py);i++)
       {
           string s=py[i];
           stringstream ss(s);
           string s1;
           int no;
           ss>>s1;
           ss>>no;
           double p=1.0;
           int flg=0;
           for(int j=0;j<sz(s1);j++)
           {
               if(s1[j]=='-')
                continue;
               int ch=s1[j]-'A';
               if(vis[j][ch]==0)
               {
                   flg=1;
                   break;
               }
               p*=((vis[j][ch]+0.0)/l);
           }
           if(flg)
            continue;
           r+=p*no;
       }
       if(r>=1)
       {
           return 0.0;
       }
        if(fl)
        {
            return -1.0;
        }

      double e= 1-r;

     return e/exj;
    }
};
/*
int main()
{
    OneArmedBandit e;
    vector<string>v1,v2;
    string s="KJ--Z";
    v1.pb("KACACEIBGCVDAKMACAAW");
    v1.pb("CECMBDBJCLHFNDCBDDNB");
    v1.pb("BYAGBJFDAGBHEGEFVXDR");
    v1.pb("UDWFABFAHDXACICQHAEH");
    v1.pb("EBHOCHABAHBDAUBZHHAB");
    v2.pb("Z-U-U 23");
    v2.pb("YUBSA 142");
    v2.pb("Q-AN- 92");
    v2.pb("ZA-CX 133");
    v2.pb("-BE-Z 125");
   cout<< e.progressiveJackpot(v1,s,v2)<<endl;
}
*/
