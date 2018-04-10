/*
here the idea of the problem is 

i have 2 ways the first is yo set all equal to dots then the next equals to ones 
the second way is to make the string alternating if you allowed this results in the max probability ever but if you start at an odd 
position you can shift it to right this have the same probability but its lexigraphically smaller

if yu stuck simulate on paper and observe :)
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
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}

int main()
{
    ll n,k,p;
    cin>>n>>k>>p;

    int way;
    ll N;
    ll K;
    if(k>n/2)
    {

       ll z=n-k;

       N= z+z;
       K=z;

       if((n-k+1)/2 >= N/2)
            way=1;
        else
            way=0;

    }
    else
    {

    if(n%2==0)
    {
        if((n-k+1)/2 >= n/2)
            way=1;
        else
            way=0;
    }
    else
    {
        ll w= k+(k-1);
        if(n-w+1%2==0)
        {
            if((n-k+1)/2 >= n/2+1)
                way=1;
            else
                way=0;
        }
        else
        {

        if((n-k+1)/2 >= n/2)
            way=1;
        else
            way=2;

        }
    }
    }
    ll x;
    for(int i=0;i<p;i++)
    {
        cin>>x;


        if(way==1)
        {
            ll l=n-k+1;
            ll r=n;

            if(x>=l&&x<=r)
                cout<<"X";
            else
                cout<<".";
        }

        if(way==0&&k<=n/2)
        {
            ll w= k+(k-1);

            if(x<n-w+1)
                cout<<".";
            else
            {
                if((n-w+1)%2==0)
                {
                    if(x%2==0)
                        cout<<"X";
                    else
                        cout<<".";
                }
                else
                {
                    if(x%2!=0)
                        cout<<"X";
                    else
                        cout<<".";

                }
            }
        }

        if(way==0&&k>n/2)
        {

           if(x>=1&&x<=N)
           {
               if(x%2==0)
              cout<<"X";
            else
                cout<<".";
           }
           else
            cout<<"X";
        }

        if(way==2)
        {

             ll w= k+(k-2);

            if(x<n-w+1)
                cout<<".";
            else
            {
                if(x>=n-w+1&&x<=n-2)
                 {
                     if(x%2==0)
                     cout<<"X";
                    else
                        cout<<".";
                 }
                 else
                    cout<<"X";

            }
        }

    }
}
