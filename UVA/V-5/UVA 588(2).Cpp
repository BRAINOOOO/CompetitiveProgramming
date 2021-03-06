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

bool intersectSegments(point a, point b, point c, point d, point & intersect)
{
	double d1 = cp(a-b, d-c), d2 = cp(a-c, d-c), d3 = cp(a-b, a-c);
	if(fabs(d1) < eps) 
        return false; 
	double t1 = d2/d1, t2 = d3/d1;
	intersect = a+(b-a)*t1;
	if(t2 < -eps || t2 > 1+eps)
		return false;
    return true;
}

vector<point>  polygonCut(vector<point> &p, point A, point B) 
{
	vector<point> left;

	for (int i = 0; i < sz(p); ++i)
    {
		point cur = p[i], nxt = p[(i+1)%sz(p)];



		if(intersectSegments(A, B, cur, nxt, intersect)) 
        {
			left.push_back(intersect);
		}

		if ( cp(B-A, cur-A) <= 0)	
            left.push_back(cur);
	}
	return left;
}










int main()
{
    int n,cs=1;
    while(cin>>n)
    {
        if(!n)
            break;
        vector<point> v;
        int x,y;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            v.pb(point(x,y));
        }

       vector<point> tv=v;
       for(int i=0;i<n;i++)
       {

          tv= polygonCut(tv,v[i],v[(i+1)%n]);

       }
       cout<<"Floor #"<<cs++<<endl;
       if(sz(tv)==0)
        cout<<"Surveillance is impossible.\n\n";
		else
			cout<<"Surveillance is possible.\n\n";
    }
}


