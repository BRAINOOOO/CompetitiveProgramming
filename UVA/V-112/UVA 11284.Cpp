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
int dp[55][(1 << 13)];
int p[15], P, save[15];
int Vmsk;
int d[55][55];
int n, m;

int rec(int idx, int msk)
{
	if ((msk&Vmsk) == Vmsk) 
        return d[idx][0];
    
	int &ret = dp[idx][msk];
	
	if (ret != -1) 
        return ret;
    
	ret = 123456789;
	
	for (int i = 0; i < P; i++)
		if (Vmsk & (1 << i))
			ret = min(ret, rec(p[i], msk | (1 << i)) + d[idx][p[i]]);
	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
    {
		scanf("%d%d", &n, &m);
    
		memset(d, 63, sizeof(d));
		
		for (int i = 0; i < m; i++)
        {
			int u, v, c, cc;
        
			scanf("%d%d%d.%d", &u, &v, &c, &cc);
			c = c * 100 + cc;
			d[u][v] = d[v][u] = min(c,d[u][v]);
		}
		scanf("%d", &P);
		int c, cc;
		int ans = -1;
		for (int i = 0; i < P; i++) 
            scanf("%d%d.%d", p + i, &c, &cc), save[i] = c*100+cc;
		for (int k = 0; k <= n; k++)
			for (int i = 0; i <= n; i++)
				for (int j = 0; j <= n; j++)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        
		for (Vmsk = 0; Vmsk < (1 << P); Vmsk++)
        {
			memset(dp, -1, sizeof(dp));
			int dif = 0;
			for (int i = 0; i < P; i++) 
			if (Vmsk&(1 << i)) 
			dif += save[i];
        
			int ret = rec(0, 0);
			
			if (ret == 123456789) 
                continue;
			if (ret >= dif) 
                continue;
			ans = max(ans, dif - ret);
		}
		if (ans == -1) puts("Don't leave the house");
		else printf("Daniel can save $%.2lf\n", ans/100.);
	}
}
