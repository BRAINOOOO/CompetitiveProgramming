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

const int Inf = 1e9;
int BaseCosts[51][51];

int NumOpera;
int StoreNum[14];
int StoreSaved[14];
int DirectCosts[14][14];

// Based on node at, which have visited previously
bool visited[14][1 << 14 + 1];
int bestSaved[14][1 << 14 + 1];

int TryOut(int index, int travelledTo)
{
    int &best = bestSaved[index][travelledTo];
    if (!visited[index][travelledTo])
    {
        visited[index][travelledTo] = true;
        
        // Go back immediately. Will add store bonus later
        best = -DirectCosts[index][0];
        
        for (int i = 0; i <= NumOpera; ++i)
        {
            if (!(travelledTo & (1 << i)))
                best = max(best,
                           TryOut(i, travelledTo | (1 << i)) - DirectCosts[index][i]);
        }
        
        best += StoreSaved[index];
    }
    
    return best;
}

int main()
{
    int T;
    cin >> T;
    
    while (T--)
    {
        int N, M;
        cin >> N >> M;
        ++N;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
                BaseCosts[i][j] = Inf;
            BaseCosts[i][i] = 0;
        }
        
        while (M--)
        {
            int start, end, dollars, cents;
            char junk;
            cin >> start >> end >> dollars >> junk >> cents;
            
            BaseCosts[start][end] = BaseCosts[end][start] =
                min(BaseCosts[end][start], dollars * 100 + cents);
        }
        
        // Calculate travel costs between all stores
        for (int k = 0; k < N; ++k)
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                    BaseCosts[i][j] = min(BaseCosts[i][j], BaseCosts[i][k] + BaseCosts[k][j]);
        
        StoreNum[0] = 0;
        cin >> NumOpera;
        for (int i = 1; i <= NumOpera; ++i)
        {
            int dollars, cents;
            char junk;
            cin >> StoreNum[i] >> dollars >> junk >> cents;
            StoreSaved[i] = dollars * 100 + cents;
            
            for (int j = 0; j < i; ++j)
                DirectCosts[i][j] = DirectCosts[j][i] = BaseCosts[StoreNum[i]][StoreNum[j]];
        }
        
        // TODO: Try having all gone to
        for (int i = 0; i <= NumOpera; ++i)
        {
            for (int j = 0; j <= (1 << (NumOpera + 2) - 1); ++j)
                visited[i][j] = false;
        }
        
        int best = TryOut(0, 0);
        
        if (best > 0)
            cout << "Daniel can save $" << (best / 100) << '.' << setw(2) << setfill('0') << (best % 100) << '\n';
        else
            cout << "Don't leave the house\n";
    }
}
