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
multiset<int> st;
ll A[300009],U[300009];
int main()
{
    int T;

    cin>>T;
    int In=0;
    while(T--)
    {
        cin.ignore();
        string line;
       getline(cin,line);

       int n,m;
        if(In)
            printf("\n");

       cin>>m>>n;
       st.clear();

       for(int i=0;i<m;i++)
        cin>>A[i];
       In=1;

       for(int i=0;i<n;i++)
        cin>>U[i];
       int j=0;
       int inc=0,cnt=0;
       multiset<int> ::iterator it;
       for(int i=0;i<m;i++)
       {

                st.insert(A[i]);
                if(i==0)
                it=st.begin();

                if(A[i]<(*it))
                {
                   it--;
                }
              if(inc>0)
                it++,inc--;


            while(j<n&&sz(st)==U[j])
            {
                if(inc>0)
                    it++,inc--;
                //cout<<id<<" ";
                cout<<(*it)<<endl;
                j++;
                inc++;

            }



       }
    }
}













