/*
explanation : the idea is greedy , since the 1 needs 0 but the zero never need 1 i mean by that the zero itself is zebra so we can 
take each zero alone but the 1 requires two zeros one after it and one before it so since it needs zeros i should minmize the 
usage of zeros so why don't i take a series of zebra as long as possible.
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
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
set< int > ones,zeros;
vector< vector<int> > ans(200009);
string st;
char ch[200009];
int main()
{


    scanf("%s",ch);
    st=ch;
    for(int i=0;i<sz(st);i++)
    {
        if(st[i]=='1')
        ones.insert(i);
        else
        zeros.insert(i);
    }

   int  need=0,id=0;

 int cnt=0;
  while(sz(zeros)>0)
  {
      need=0;
     int preid=-1;
      while(1)
      {

         if(need==1)
         {

             auto  it= ones.upper_bound(preid);
             if(it==ones.end())
                break;
             int index= (*it);
            ans[id].pb( index );
            ones.erase(it);
            preid=index;
         }
         else
         {
             auto it=zeros.upper_bound(preid);



            if(sz(zeros)>0&&it==zeros.end())
            {
                int dd=ans[id].back();
                ones.insert(dd);
                ans[id].pop_back();

                break;
            }
            else if(sz(zeros)==0)
            {
                int dd=ans[id].back();
                ones.insert(dd);
                ans[id].pop_back();

                break;

            }
             int index= (*it);
            ans[id].pb( index );
            zeros.erase(it);
            preid=index;
         }

         need=!need;
      }
      id++;
  }

  if(sz(ones)>0)
  {
      cout<<"-1\n";
      return 0;
  }

  cout<<id<<endl;

  for(int i=0;i<id;i++)
  {
      cout<<sz(ans[i])<<" ";

      for(int j=0;j<sz(ans[i]);j++)
        cout<<ans[i][j]+1<<" ";
      cout<<endl;
  }

}
