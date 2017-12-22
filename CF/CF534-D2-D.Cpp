/*
explanation : here the idea is at every stage we will have many choices eg 0 1 2 3 4 5 6 7 8 here 
the next can be 9 or 6 by making a contest or 3 or 0 we will realize that all the possibilities %3 
the same so we can store them and just binary search on the <= the cur one, we will target the max 
possible bec if we can do the max we can do the smaller but if we can do the smaller we may cant do 
the max.

complexity : O(nlog(n))
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
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
int setBit0(int num, int idx) {return num & ~(1<<idx);}
int flipBit(int num, int idx) {return num ^ (1<<idx);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
set<pair<int,int>>  v[2*100000+9];
int ans[2*100000+9];
int main()
{
    int n;
    cin>>n;
    int no;
    for(int i=1;i<=n;i++)
    {
        cin>>no;
        v[no%3].insert(mp(no,i));
    }
    int c=0;
    for(int i=0;i<n;i++)
    {
        set< pair<int,int> > :: iterator it;
        it = v[c%3].upper_bound(mp(c,2000009));
        if(it==v[c%3].begin())
        {
            cout<<"Impossible\n";
            return 0;
        }
        it--;
        pair<int,int> cy=(*it);
        v[c%3].erase(it);
        c=cy.first+1;
        ans[i]=cy.second;
    }
  cout<<"Possible\n";
   for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";
}
