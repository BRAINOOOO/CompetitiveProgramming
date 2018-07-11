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
#define     point                    complex<double>
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-5);
using namespace std;
int dcmp(double a,double b){   return fabs(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(ll num, int idx) {return ((num >> idx) & 1ll) == 1;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}




int vis[9][9][9][9][9][9][9][9][9];
struct board{
    int nu[9];
    board (){}
    board(int a,int b,int c,int d,int e,int f,int g,int h,int i){
        nu[0] = a;
        nu[1] = b;
        nu[2] = c;
        nu[3] = d;
        nu[4] = e;
        nu[5] = f;
        nu[6] = g;
        nu[7] = h;
        nu[8] = i;
    }
};

int da[]={0,1,3,4};
int db[]={1,2,4,5};
int dc[]={3,4,6,7};
int dd[]={4,5,7,8};

char str[11];
int moves;
int mx = 0;

void solve()
{
    queue< board > q;
    q.push(board{0,1,2,3,4,5,6,7,8}); // starting board
    vis[0][1][2][3][4][5][6][7][8] = 1;
    while(!q.empty())
    {
        board u = q.front();
        q.pop();
        for(int k=0;k<4;k++)
        {
            int ta = da[k], tb = db[k], tc = dc[k], td = dd[k];
            board v = u;

            v.nu[ta] = u.nu[tc]; // rotate clockwise
            v.nu[tb] = u.nu[ta];
            v.nu[tc] = u.nu[td];
            v.nu[td] = u.nu[tb];

            if(!vis[v.nu[0]][v.nu[1]][v.nu[2]][v.nu[3]][v.nu[4]][v.nu[5]][v.nu[6]][v.nu[7]][v.nu[8]]){ // check if vis
                vis[v.nu[0]][v.nu[1]][v.nu[2]][v.nu[3]][v.nu[4]][v.nu[5]][v.nu[6]][v.nu[7]][v.nu[8]]
                = vis[u.nu[0]][u.nu[1]][u.nu[2]][u.nu[3]][u.nu[4]][u.nu[5]][u.nu[6]][u.nu[7]][u.nu[8]]+1,
                q.push(v);
                mx = max(mx,vis[v.nu[0]][v.nu[1]][v.nu[2]][v.nu[3]][v.nu[4]][v.nu[5]][v.nu[6]][v.nu[7]][v.nu[8]]);
            }
            v = u;

            v.nu[ta] = u.nu[tb]; // rotate anti-clockwise
            v.nu[tb] = u.nu[td];
            v.nu[tc] = u.nu[ta];
            v.nu[td] = u.nu[tc];
            if(!vis[v.nu[0]][v.nu[1]][v.nu[2]][v.nu[3]][v.nu[4]][v.nu[5]][v.nu[6]][v.nu[7]][v.nu[8]]){ // check if vis
                vis[v.nu[0]][v.nu[1]][v.nu[2]][v.nu[3]][v.nu[4]][v.nu[5]][v.nu[6]][v.nu[7]][v.nu[8]]
                = vis[u.nu[0]][u.nu[1]][u.nu[2]][u.nu[3]][u.nu[4]][u.nu[5]][u.nu[6]][u.nu[7]][u.nu[8]]+1,
                q.push(v);
                mx = max(mx,vis[v.nu[0]][v.nu[1]][v.nu[2]][v.nu[3]][v.nu[4]][v.nu[5]][v.nu[6]][v.nu[7]][v.nu[8]]);
            }
        }
    }
    return;
}

int main()
{
    int tc = 0;
    solve(); // generate all possible moves
    while(scanf("%s",str) && str[1] > '0')
    {
        moves = str[0]-'0';
        board v;
        for(int i=1;i<10;i++) // get the number of the board
            v.nu[i-1] = (str[i]-'0'-1);

        int ts = vis[v.nu[0]][v.nu[1]][v.nu[2]][v.nu[3]][v.nu[4]][v.nu[5]][v.nu[6]][v.nu[7]][v.nu[8]];
        ts--;

        if(ts > moves)
            printf("%d. %d\n",++tc,-1);
        else
            printf("%d. %d\n",++tc,ts);
    }
}









