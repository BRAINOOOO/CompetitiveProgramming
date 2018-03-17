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
void DFS(int node, const vector<vector<int>> &adj_list,
         vector<bool> &visited, 
         int len, int &long_dist, int start, vector<int> &path,
         set<int> &best, set<int> &worst)
{
    path.push_back(node);
    visited[node] = true;

    if (len > long_dist) {
        best.clear();
        worst.clear();

        long_dist = len;
    }

    if (len == long_dist) {
        worst.insert(node);
        worst.insert(start);

        if (len % 2 == 0)
            best.insert(path[len / 2]);
        else {
            best.insert(path[len / 2]);
            best.insert(path[len / 2 + 1]);
        }
    }

    for (int dest : adj_list[node])
        if (!visited[dest]) {
            DFS(dest, adj_list, visited, len + 1, long_dist,
                start, path, best, worst);
        }

    path.pop_back();
}

int main() {
    int N;
    while (scanf("%d", &N) == 1) {
        vector<vector<int>> adj_list(N);
        for (int i = 0; i < N; i++) {
            int K;
            scanf("%d", &K);
            for (int j = 0; j < K; j++) {
                int node;
                scanf("%d", &node);
                adj_list[i].push_back(node - 1);
            }
        }

        vector<bool> visited(N, false);

        queue<pair<int, int>> q;
        visited[0] = true;
        q.push({0, 0});
        int long_dist = 0;
        
        int potential = 0;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int u = front.first;
            int len = front.second;
            if (len > long_dist) {
                long_dist = len;
                potential = u;
            }

            for (int v : adj_list[u])
                if (!visited[v]) {
                    visited[v] = true;
                    q.push({v, len + 1});
                }
        }


        visited.assign(N, false);
        vector<int> path;
        
        set<int> best, worst;

        DFS(potential, adj_list, visited, 0,
            long_dist, potential, path, best, worst);

        for (int node : worst)
            if (node != potential) {
                potential = node;
                break;
            }

        visited.assign(N, false);
        path.clear();
        DFS(potential, adj_list, visited, 0,
            long_dist, potential, path, best, worst);


        printf("Best Roots  :");
        for (int root : best)
            printf(" %d", root + 1);
        printf("\n");

        printf("Worst Roots :");
        for (int root : worst)
            printf(" %d", root + 1);
        printf("\n");
    }
    return 0;
}
