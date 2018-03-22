/*
explanation : here the idea is from n to n*2 the distance is n so as i am increasing n the range increase from here the idea 
of binary search comes if the number of elements is not enough expand n the rest is related to combinatroics
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
ll comb[65][65];
ll m;
int k;
pair<int,int> ispoweroftwo(ll n)
{
   if( floor(log10(n)/log10(2))==ceil(log10(n)/log10(2)))
    return mp(1,log10(n)/log10(2));
   return mp(0,0);
}

void fun()
{
    for(int i=0;i<65;i++)
        for(int j=0;j<65;j++)
         comb[i][j]= (j==0 ? 1 : i==0 ? 0 : comb[i-1][j-1]+comb[i-1][j]);
}
ll calc(ll num)
{
    ll ans=0;
    int ones= countNumBit1(num);

    for(int i=0;i<=63;i++)
    {
        if(getBit(num,i)==1)
        {
            ones-=1;

            if(ones+1<=k&&i!=0)
            {
                int d= k-ones;
                ans+= comb[i][d];
            }


        }
    }
    return ans;
}

int check(ll n)
{
    pair<int,int> p1= ispoweroftwo(n+1);

    ll a,b;

    if(p1.first==1)
    {
        int index=p1.second;
        a=comb[index][k];
    }
    else
    {
        a=calc(n);
    }

    pair<int,int> p2= ispoweroftwo(n*2+1);

    if(p2.first==1)
    {
        int index=p1.second;
        b=comb[index][k];
    }
    else
    {

         b=calc(n*2);
    }

    if(b-a>m)
        return 0;
    if(b-a<m)
        return 1;
    return 2;
}
int main()
{
    cin>>m>>k;
     fun();
    ll l=1;
    ll h=1000000000000000000;
    ll ans;
    while(l<=h)
    {
        ll mid=(l+h)/2;

        ll res= check(mid);

        if(res==1)
            l=mid+1;
        else if(res==0)
            h=mid-1;
        else
        {
            ans=mid;
            break;
        }
    }
    cout<<ans<<endl;
}
