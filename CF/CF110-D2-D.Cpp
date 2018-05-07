// ICPC Champion is here

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
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
vector<string> lucky;
vector<ll> v;
void fun(string s)
{

    if(sz(s)==11)
        return ;

    if(s!="")
    lucky.pb(s);


    fun(s+'4');
    fun(s+'7');

}

int main()
{
   ll pl,pr,vl,vr,k;
   cin>>pl>>pr>>vl>>vr>>k;
    fun("");
    v.pb(0);

    for(int i=0;i<sz(lucky);i++)
    {
        ll num=atoll(lucky[i].c_str());
        v.pb(num);
    }
    sort(all(v));
    ll N=pr-pl+1;  ll M=vr-vl+1;
    ll demo=(N*M),up=0;



    for(int i=1;i<sz(v)-k;i++)
    {
        ll tr=v[i];

        ll bl=v[i+k-1];

        ll tl=v[i-1]+1;

        ll br=v[i+k]-1;

        ll l1=0,r1=0,l2=0,r2=0,l11=0,r11=0,l22=0,r22=0;
        ll rg1=0,rg2=0;

         if(tl>=pl&&tr<=pr)
            rg1=tr-tl+1,l1=tl,r1=tr;
        else if(pl>=tl&&pr<=tr)
            rg1=pr-pl+1,l1=pl,r1=pr;
        else if(pr>tr&&pl>=tl&&pl<=tr)
            rg1=tr-pl+1,l1=pl,r1=tr;
        else if(pl<tl&&pr>=tl&&pr<=tr)
            rg1=pr-tl+1,l1=tl,r1=pr;

        if(bl>=vl&&br<=vr)
            rg2=br-bl+1,l2=bl,r2=br;
        else if(vl>=bl&&vr<=br)
            rg2=vr-vl+1,l2=vl,r2=vr;
        else if(vr>br&&vl>=bl&&vl<=br)
            rg2=br-vl+1,l2=vl,r2=br;
        else if(vl<bl&&vr>=bl&&vr<=br)
            rg2=vr-bl+1,l2=bl,r2=vr;

        up+= rg1*rg2;

        ll rg11=0; ll rg22=0;

         if(tl>=vl&&tr<=vr)
            rg11=tr-tl+1,l11=tl,r11=tr;
        else if(vl>=tl&&vr<=tr)
            rg11=vr-vl+1,l11=vl,r11=vr;
        else if(vr>tr&&vl>=tl&&vl<=tr)
            rg11=tr-vl+1,l11=vl,r11=tr;
        else if(vl<tl&&vr>=tl&&vr<=tr)
            rg11=vr-tl+1,l11=tl,r11=vr;

         if(bl>=pl&&br<=pr)
            rg22=br-bl+1,l22=bl,r22=br;
        else if(pl>=bl&&pr<=br)
            rg22=pr-pl+1,l22=pl,r22=pr;
        else if(pr>br&&pl>=bl&&pl<=br)
            rg22=br-pl+1,l22=pl,r22=br;
        else if(pl<bl&&pr>=bl&&pr<=br)
            rg22=pr-bl+1,l22=bl,r22=pr;

        up+= rg11*rg22;


        ll add=0;

        if(l1>=l2&&r1<=r2)
            add=r1-l1+1;
        else if(l2>=l1&&r2<=r1)
            add= r2-l2+1;
        else if(l2<l1&&r2>=l1&&r2<=r1)
            add=r2-l1+1;
        else if(r2>r1&&l2>=l1&&l2<=r1)
           add= r1-l2+1;
        if(r1==0||l2==0||r2==0||l1==0)
            continue;

    up-= add;

    }
    cout<<fixed<<setprecision(12)<< (up+0.0)/demo<<endl;
}
