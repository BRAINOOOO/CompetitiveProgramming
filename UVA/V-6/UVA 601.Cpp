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
vector<string> v;
int used[105][105], n;
int vis2[105][105][5],fl;
void dfs(int x, int y, char w) {
    if(x < 0 || y < 0 || x >= n || y >= n)
        return ;
    if(used[x][y] || v[x][y] != w)
        return ;

        if(x==n-1&&w=='B')
        {
            fl=1;
            return;
        }
         if(y==n-1&&w=='W')
        {
            fl=1;
            return;
        }

    used[x][y] = 1;
    dfs(x+1, y, w);
    dfs(x-1, y, w);
    dfs(x, y+1, w);
    dfs(x, y-1, w);
}
void dfs2(int r,int c,char ch,int f)
{


    vis2[r][c][f]=1;

    if(r==n-1&&ch=='B')
    {
        fl=1;
        return ;
    }

    if(c==n-1&&ch=='W')
    {
        fl=1;
        return ;
    }
    if(r+1<n&&!vis2[r+1][c][f]&&v[r+1][c]=='U'&&f==0)
     dfs2(r+1,c,ch,1);
    if(r+1<n&&!vis2[r+1][c][f]&&v[r+1][c]==ch)
      dfs2(r+1,c,ch,f);

    if(r-1>=0&&!vis2[r-1][c][f]&&v[r-1][c]==ch)
    dfs2(r-1,c,ch,f);
    if(r-1>=0&&!vis2[r-1][c][f]&&v[r-1][c]=='U'&&f==0)
        dfs2(r-1,c,ch,1);
   if(c+1<n&&!vis2[r][c+1][f]&&v[r][c+1]=='U'&&f==0)
    dfs2(r,c+1,ch,1);
    if(c+1<n&&!vis2[r][c+1][f]&&v[r][c+1]==ch)
    dfs2(r,c+1,ch,f);
    if(c-1>=0&&!vis2[r][c-1][f]&&v[r][c-1]==ch)
    dfs2(r,c-1,ch,f);
    if(c-1>=0&&!vis2[r][c-1][f]&&v[r][c-1]=='U'&&f==0)
    dfs2(r,c-1,ch,1);
}
int main() {
    int i, j, p, q;
    while(cin>>n)
    {
        if(n==0)
        break;
        v.clear();
        string st;
        for(i = 0; i < n; i++)
        {
             cin>>st;
             v.push_back(st);
        }
        memset(used,0,sizeof(used));
        int Wwin = 0, Bwin = 0;

        for(i = 0; i < n; i++)
        {
            if(v[i][0] == 'W')
             {
                 fl=0;
                 dfs(i, 0, 'W');
                 if(fl)
                    Wwin=1;
             }

            if(v[0][i] == 'B')
             {
                 fl=0;
                 dfs(0, i, 'B');
                 if(fl)
                    Bwin=1;
             }
        }

        if(Wwin) {
            puts("White has a winning path.");
            continue;
        }
        if(Bwin) {
            puts("Black has a winning path.");
            continue;
        }
        memset(vis2, 0, sizeof(vis2));
        fl=0;
        for(int l=0;l<n;l++)
        {
            if(v[l][0]=='W')
            {
                fl=0;
                dfs2(l,0,'W',0);
                if(fl)
                {
                    break;
                }

            }
            else if(v[l][0]=='U')
            {
                fl=0;
                dfs2(l,0,'W',1);
                if(fl)
                    break;
            }
        }
        if(fl) {
            puts("White can win in one move.");
            continue;
        }
       memset(vis2, 0, sizeof(vis2));
        fl=0;
        for(int l=0;l<n;l++)
        {
            if(v[0][l]=='B')
            {
                fl=0;
                dfs2(0,l,'B',0);
                if(fl)
                {
                    break;
                }
            }
            else if(v[0][l]=='U')
            {
                fl=0;
                dfs2(0,l,'B',1);
                if(fl)
                    break;
            }

        }
        if(fl) {
            puts("Black can win in one move.");
            continue;
        }
        puts("There is no winning path.");
    }
    return 0;
}
