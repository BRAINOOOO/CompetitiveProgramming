/*
topic dp with masks 
please read the comments in the code
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
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
int mem[(1<<16)+9];
map< pair<int,int>,int> mb;
int upmsk1(int i,int j,int k,int msk)
{
    int nmsk=msk;

    for(int l=j;l<=k;l++)
    {
       int pos=mb[mp(i,l)];
        nmsk= setBit1(nmsk,pos);
    }
    return nmsk;
}
int upmsk2(int i,int j,int k,int msk)
{
    int nmsk=msk;

    for(int l=i;l<=k;l++)
    {
       int pos=mb[mp(l,j)];
        nmsk= setBit1(nmsk,pos);
    }

    return nmsk;
}








int solve(int msk)
{

    int &ret=mem[msk];
    if(ret!=-1)
        return ret;

    if(countNumBit1(msk)==16)
        return ret=0;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {



            int pos= mb[mp(i,j)];

            if(getBit(msk,pos)==1)
                continue;
// trying itself
           int nmsk= upmsk1(i,j,j,msk);
             if(solve(nmsk))
                return ret=0;
// trying right

            for(int k=j+1,u=1;u<=2&&k<4;k++,u++)
            {
                int pos= mb[mp(i,k)];

               if(getBit(msk,pos)==1)
                  break;
                if((u==1&&j==1))
                 continue;

               int nmsk= upmsk1(i,j,k,msk);
                if(solve(nmsk))
                    return ret=0;
            }
// trying down
            for(int k=i+1,u=1;u<=2&&k<4;k++,u++)
            {
                int pos= mb[mp(k,j)];

               if(getBit(msk,pos)==1)
                  break;
                 if((i==1&&u==1))
                 continue;

               int nmsk= upmsk2(i,j,k,msk);
                if(solve(nmsk))
                    return ret=0;
            }
        }
    }

    return ret=1;


}









int main()
{
    int N;
    cin>>N;
    int id=0;

       for(int i=0;i<=3;i++)
        {
            for(int j=0;j<=3;j++)
            {
                mb[mp(i,j)]=id++;
            }
        }


    clr(mem,-1);
    solve(0);


    while(N--)
    {
        string st;
        vector<string> v;
        v.clear();
        for(int i=0;i<4;i++)
            cin>>st,v.pb(st);
        int msk=0;
        for(int i=0;i<4;i++)
        {
             for(int j=0;j<4;j++)
             {
                int pos= mb[mp(i,j)];
                if(v[i][j]=='X')
                msk=setBit1(msk,pos);
             }
        }

       int ans= solve(msk);

        if(ans==0)
            cout<<"WINNING\n";
        else
            cout<<"LOSING\n";
    }
}




