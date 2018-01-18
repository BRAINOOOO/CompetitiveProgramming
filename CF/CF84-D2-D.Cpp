/*
explanation : first imagin that all the visits of all the animals are equal to x for example and the number
of the animals are n so i make a cycle and each one enters one time their order will be the same and the number
of visits will be reduced by the number of cycles so i can make min( x,k/n ) turns okay but in fact the visits 
of the animals are not equal or sorted so i can always make the min between all the available animals turns 
and then search for the next min among the available animals ( i mean by available animals the animals that still
exists after all the pervious cycles ) and so on till the k will be smaller that one cycle i will get it out and 
handel it manually .

complexity : O( N )
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
vector<pair<int,int>> v;
vector<int> v2,v1;

int main()
{
    ll n,k;
    cin>>n>>k;
    ll s=0,no;
    for(int i=1;i<=n;i++)
    {
        cin>>no;
        v.pb(mp(no,i));
        v2.pb(no);
        s+=no;
    }
   if(s<k)
   {
       cout<<"-1\n";
       return 0;
   }
  sort(all(v2));
  ll c=0,Ci;
  int emptyy=0;
  while(1)
  {
      if(v2.back()<=c)
      {
          emptyy=1;
          break;
      }
     int  id= upper_bound(all(v2),c)-v2.begin();
     ll turns= v2[id]-c ;
     int N= n-id;
     ll m=min(turns,k/N);

      if(k==0)
        break;
     else if(k<N)
      {
          Ci=c;
          break;
      }
      else if(k>=N)
      {
          c+=m;
          k-=m*N;
      }
  }
  if(emptyy)
  {
      cout<<endl;
      return 0;
  }
  for(int i=0;i<n;i++)
  {
      if(k==0&&v[i].first>c)
        cout<<v[i].second<<" ";
      else if(k>0&&v[i].first>c)
      {
           v[i].first--;
           if(v[i].first-c>0)
          v1.pb(v[i].second);
          k--;
      }
  }
  for(int i=0;i<sz(v1);i++)
    cout<<v1[i]<<" ";
}
