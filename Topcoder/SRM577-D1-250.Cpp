/* 
explanation : the problem is i want the expectation of the ratings in elly's room okay if i supposed there is already T ratings in her
room so expectation is ( sum of ratings/ T ) okay bec of linearity of expectations this is equal to E(rating1)+....+E(ratingT)  then 
divided by T and E( ratingi ) is the average of ratings from the ith stage okay thats the general solution but there is a special cases 
where n(number of people) may be not divisable by rooms and this id divided into 2 senarios first one if elly is in the last stage at
elly's room elly ofcourse must be exist so i will take people at last stage else i might take one or not thats law of total expectaion
revice it :)
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
class EllysRoomAssignmentsDiv1
{
 public :
 double getAverage(vector<string> in)
   {

    vector<double> v;
		string x = "";
		for(int i=0;i<sz(in);i++)
			x += in[i];
		stringstream ss(x);
		int iny;
		while (ss >> iny)
			v.pb(iny);
      int n=sz(v);
      double me=v[0];
      sort(allr(v));
      int R= ceil((n+0.0)/20);
      double res=0.0;
      int idex=0;
      vector< double > v2;
       for(int i=0;i<n;i+=R)
       {
           double s=0.0;
           int fl=0;
           for(int j=i;j<min(i+R,n);j++)
           {
               s+=v[j];
               if(dcmp(v[j],me)==0)
               {
                   fl=1;
                   idex=j;
                   break;
               }
           }
          s= s/(min(i+R,n)-i);
           if(fl)
           {
               res+=me;
               v2.pb(me);
           }
           else
           {
                res+= s;
                v2.pb(s);
           }
       }
       int t=n/R;
       if(n%R==0)
       {
           return res/t;
       }
       else if(idex/R==t)
       {
           return (res+0.0)/(t+1);
       }
       else
       {
           double p=((n%R)+0.0)/(R);
           double ans=p*(res/(t+1))+ (1.0-p)*((res-v2[t])/t);
           return ans;
       }
   }
};
