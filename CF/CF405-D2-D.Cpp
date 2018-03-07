/*
explanation : 

             sigma x-1 = sigma s-y
             
   s-y=x-1 
   
   y=s-x+1    for each x
 
 if this value is not at set of x so add it to the answer
 else
 
  this means there is a x= s-x+1 umm let it be w
  and it adds x-1+w-1=  x-1+s-x+1-1= s-1 okay to add the same amount to the other side so i need one Y and s-Y+1  so it adds 
  s-Y + s-(s-Y+1) = s-1 the same amount
  but how i grantee that this pair exists well it explained in the editorial in a good way, 
  but takecare of marking the s-x+1 one as its done.
  
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
vector<int> ans,v;
int vis[1000009],vis2[1000009];
int main()
{
    int n;
     scanf("%d",&n);
    int no;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&no);

        v.pb(no);
        vis[no]=1;
    }
    int id=1,s=1000000;
    for(int i=0;i<n;i++)
    {
       if(vis2[v[i]])
        continue;
        if(!vis[s-v[i]+1])
        {
            ans.pb(s-v[i]+1);
        }
        else
        {
            while((id<=s)&&(vis[id]||vis[s-id+1]))
                id++;
            ans.pb(id);
            ans.pb(s-id+1);
            vis[id]=1;
            vis[s-id+1]=1;
            vis2[s-v[i]+1]=1;
        }
    }
     printf("%d\n",sz(ans));
     for(int i=0;i<sz(ans);i++)
            printf("%d\n",ans[i]);
}
