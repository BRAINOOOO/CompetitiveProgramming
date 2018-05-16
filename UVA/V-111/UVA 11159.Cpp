/*
algo used minpathvertexcover maxflow
*/

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
#define     point                    complex<long double>
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
int A[209],B[209];
bool canMatch(vector< vector<int> > & adjMax, vector<int> & vis, vector<int> & L, vector<int> & R, int i) // O(m*n)
{
	for(int j=0;j<sz(adjMax[i]);j++)
	{
       int r=adjMax[i][j];
       //cout<<r<<endl;
        if( vis[r])
            continue;

		 vis[r] = 1;
		// cout<<L[r]<<endl;
		  if( L[r] == -1 || canMatch(adjMax, vis, L, R, L[r]) )
		  {
			L[r] = i, R[i] = r;
			return true;
		   }
    }

	return false;
}

int bipartiteMatching(vector< vector<int> > adjMax,int n,int m)
{

	int maxFlow = 0;
	vector<int> vis, L(n+m, -1), R(m+n, -1);
	for(int i=0;i< n;i++)
    {
		vis = vector<int>(n+m, 0);

		if( canMatch(adjMax, vis, L, R, i)  )
			maxFlow++;
	}


	return maxFlow;
}
int main()
{
    int cs=1,T;
    cin>>T;
    while(T--)
    {
        vector< vector<int> > v;

        int n,m;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>A[i];

        cin>>m;
        for(int i=0;i<m;i++)
            cin>>B[i];
        v.resize(n+m);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(A[i]!=0)
                {
                    if(B[j]%A[i]==0)
                        v[i].pb(j+n);
                }
                else if(A[i]==0&&B[j]==0)
                    v[i].pb(j+n);
            }
        }
        cout<<"Case "<<cs++<<": "<<bipartiteMatching(v,n,m)<<endl;
    }
}



