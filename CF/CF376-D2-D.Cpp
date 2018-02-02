/*
explanation : the idea is i will save for each cell the number of accumulative ones conscutive on starting from its left 
and using the fact that if i have 4 ones on my left including me and the the next row from the same position if i have 3 ones
on the left so i can make area 2X3 bec the 3 ones will surely part from the 4 ones from here the idea of sorting comes so i 
will sort the number of ones starting from the current cell to the left among all the  rows and maxmize .

complexity : O( n*n*log(n) )
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
vector<vector<int> > v1;
int arr[5005][5005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    string st;
    for(int i=0;i<n;i++)
    {
        cin>>st;
        int  cnt=0;
        for(int j=0;j<m;j++)
        {
            if(st[j]=='1')
                cnt++;
            else
            {
                cnt=0;
                continue;
            }
            arr[i][j]=cnt;
        }
    }
    for(int i=0;i<m;i++)
    {
        vector<int> v;
        for(int j=0;j<n;j++)
        {
            v.pb(arr[j][i]);
        }
        sort(all(v));
        v1.pb(v);
    }
    int mx=0;
    for(int i=0;i<sz(v1);i++)
    {
        int l=1;
        for(int j=sz(v1[i])-1;j>=0;j--)
        {
           int val=v1[i][j];
           mx=max(mx,l*val);
            l++;
        }
    }
    cout<<mx<<endl;
}
