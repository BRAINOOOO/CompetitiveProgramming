/*
explanation : first of all problem description is bad, the idea is the ones from the same channel 
working at the smae time can be recorded using the same recorder but if they are from different
channels here i must use 2 recorders implement then max on the number of recoders work at the same
time at different channels.

complexity : O(N*C)
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
int s[100000];
int t[100000];
int c[100000];
int merge[200000];
int time[200000] = {0};
int main(void)
{
    int N, C;
    int i, j;
    int max = 0;
    scanf("%d %d", &N, &C);
 
    for (i = 0; i < N; i++)
    {
        scanf("%d %d %d", &s[i], &t[i], &c[i]);
    }
 
    for (i = 1; i <= C; i++)
    {
        for (j = 0; j < 200000; j++)
        {
            merge[j] = 0;
        }
        for (j = 0; j < N; j++)
        {
            if (c[j] == i){
                merge[s[j]*2-1] = 1;
                merge[t[j]*2] = -1;
            }
        }
        for (j = 1; j < 200000; j++)
        {
            merge[j] += merge[j-1];
        }
        for (j = 0; j < 200000; j++)
        {
            if (merge[j] > 0){
                time[j]++;
            }
        }
    }
 
    for (i = 0; i < 200000; i++)
    {
        max = time[i]>max?time[i]:max;
    }
 
    printf("%d\n", max);
 
}
