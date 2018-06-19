
// ICPC champion is here
#include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<map>
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
#define     point                    complex<long double>
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
using namespace std;
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int inf=INT_MAX,ffpos[300009],fspos[300009],first[100009],second[100009];
pair<int,int> ans[100009];
int main()
{

    int n;
    scanf("%d",&n);
    for(int i=0;i<=300000;i++)
        ffpos[i]=fspos[i]=inf;
    int no;
    for(int i=1;i<=n;i++)
    {

        scanf("%d",&no);
        first[i]=first[i-1];
        second[i]=second[i-1];
        if(no==1)
        {
            first[i]+=1;
            ffpos[first[i]]=i;
        }
        else
        {
            second[i]+=1;
            fspos[second[i]]=i;
        }
    }

    int cnt=0,id1,id2,id=0;
    for(int i=1;i<=n;i++)
    {
        id1=id2=i;

        int mx=-1,s=0,f=0,mi,last;
        while(1)
        {

           mi= min(ffpos[id1],fspos[id2]);
           if(mi>n)
            break;
            mx=max(mx,mi);
            if(mi==ffpos[id1])
                f++,last=1;
            else
                s++,last=2;

            id1=first[mi]+i;
            id2=second[mi]+i;

        }

        if(mx!=n||(last==1&&s>=f)||(last==2&&f>=s))
            continue;

        cnt++;
        ans[id++]=(mp(max(f,s),i));
    }
   sort(ans,ans+cnt);

   printf("%d\n",cnt);
   for(int i=0;i<cnt;i++)
    printf("%d %d\n",ans[i].first,ans[i].second);




    }

