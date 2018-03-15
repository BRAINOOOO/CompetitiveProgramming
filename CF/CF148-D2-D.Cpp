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
double mem[1001][1001][2];

double solve(int w, int b, bool t)
{
	if (w <= 0 || b <= 0 && !t)
		return 0;

	double& ret = mem[w][b][t];

	if (ret == ret)
		return ret;

	double pw1 = (double)w / (w + b);
	double pb1 = (double)b / (w + b);
	double pw2 = (double)(w - 0) / (w + b - 1);
	double pb2 = (double)(b - 1) / (w + b - 1);

	if (t)
		ret = pw1 + (pb1 * solve(w, b - 1, !t));
	else
		ret = pb1 * (pw2 * (w - 1 < 0 ? 0 : solve(w - 1, b - 1, !t)) + pb2 * (b - 2 < 0 ? 0 : solve(w, b - 2, !t)));

	return ret;
}

int main()
{
	int w, b, i, j;
	cin >> w >> b;
	clr(mem,-1);
	cout << fixed << setprecision(9) << solve(w, b, 1) << endl;
	return 0;
}
