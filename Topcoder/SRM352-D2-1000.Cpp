/*
explanation : strightforward problem first get the expectation of earnings the solve the enquality E( earnings interm of p factor) >= 
minmoney

complexity : 2^n*n
*/
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
class RaceManagement
{
public :

    double getPayoutFactor(vector<int> h,vector<int> val,int M)
    {
          int pl=sz(h);
        vector<double> pro(pl);
        for(int i=0;i<pl;i++)
        {
            pro[i]=h[i];
            pro[i]/=100;
        }
        reverse(all(pro));
        reverse(all(val));
        double constant=0.0,coffp=0.0;
        for(int i=0;i<(1<<pl);i++)
        {
           double sum=0.0,p=1.0;
           int count1s=0;
           int id;
           for(int j=0;j<pl;j++)
           {

              if(getBit(i,j)==0)
              {
                  sum+= val[j];
                  p*=(1-pro[j]);
              }
              else
              {
                  count1s++;
                  sum+=val[j];
                  id=j;
                  p*=pro[j];
              }
           }
           double e=0.0,w=0.0;
           if(count1s==1)
           {
               sum-=val[id];
               w=p*sum;
               e=-p*val[id];
           }
           else
            w=p*sum;
          constant+=w;
          coffp+=e;
        }
          double res;
          if(dcmp(coffp,0.0)==0)
          {
              if(constant>=M)
                return -2;
              return -1;
          }
         res= (M-constant)/coffp;
         if(res<0)
            return -1;
        return res;
    }
};
int main()
{
    RaceManagement e;
    vector<int> v2;
    vector<int> v1;
    v1.pb(30);
    v2.pb(100);
    cout<<e.getPayoutFactor(v1,v2,10);
}
