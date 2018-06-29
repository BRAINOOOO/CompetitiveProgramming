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
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
#define pii pair<int, int>
const int MXN = 1e6 + 5;
int fibs[MXN];
int successor[MXN];
int len[MXN];
int m;

int get_len(int pos)
{
	if (len[pos] != -1) return len[pos];

	if (successor[pos] == -1) return 1;

	return len[pos] = 1 + get_len(successor[pos]);
}

int main()
{
	int tests,cs=1;
	cin>>tests;
	while(tests--)
    {
		cin>>m;
		if (m == 1)
            cout<<"Case "<<cs++<<": "<<1<<endl;
		else
        {
			// 1. Generating the fibonacci sequence modulo M for 2 cycles
			fibs[0] = 0;
			fibs[1] = 1;
			fibs[2] = 1;
			int p = 3;
			int flag = 0;
			while (true)
            {
				fibs[p] = (fibs[p - 1] + fibs[p - 2]) % m;

				if (fibs[p] == 1 && fibs[p - 1] == 1 && fibs[p - 2] == 0)
				{
					flag++;
					if (flag == 2)
					{ // This is the second cycle
						p -= 2;
						p /= 2; // p is now the length of 1 cycle
						break;
					}
				}
				p++;
			}
			// 2. Calculating the successor of each element from 1 to p
			priority_queue<pii, vector<pii>, std::greater<pii> > pq;

			memset(successor, -1, sizeof(successor));
			memset(len, -1, sizeof(len));

			for(int i=0;i< 2 * p;i++)
			{
				while (!pq.empty() && fibs[i] > pq.top().first)
                {
					successor[pq.top().second] = i ;
					pq.pop();
				}
                pq.push(make_pair(fibs[i], i));
			}
			// 3. Getting the total length
			ll res = 0;
			for(int i=0;i<p;i++)
            {
				res += get_len(i);
			}
			cout<<"Case "<<cs++<<": "<<res<<endl;
		}
	}

}
