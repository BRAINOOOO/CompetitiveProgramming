/*
explanation : the idea is we will use dp to get the max profit and print what we will choose but Takecare of
1- we are always want to start the job as soon as possible to finish it before the deadline so there is no need to pass the time
2- we will start the jobs sorted based on their deadline 

about the implementation which is the harder part

we will work in the min domain and as its not available to work in some times so do array called next which express the first next allowed 
min to work at if its notavailable else the farest possible min i can work till it then i will do array jump which express that if i 
start the subject c2 at min c so i will take how many mins to end it its obvious this for each day.

happy coding :)
*/
#include <bits/stdc++.h>
#define sz(v)   ((int)(v).size())
#define  all(v)    ((v).begin()),((v).end())
#define  allr(v)    ((v).rbegin()),((v).rend())
#define   pb         push_back
//#define   mp         make_pair
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
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}

const int MAXN = 100;
const int oops = 1<<25;

class Subject
{
    public:
        string name;
        int time;
}subject[MAXN+5];

class Job
{
    public:
        int input_id,subject_id;
        int profit,deadline;
    bool operator < (const Job &with) const
    {
        if (deadline != with.deadline)return deadline < with.deadline;
        return input_id < with.input_id;
    }
}job[MAXN+5];

char tempo[40];
map<string,int>mp;
int m,n,k;

int from[10],to[10];

int scanTime(FILE *in)
{
    int hours,minutes;
    fscanf(in,"%d:%d",&hours,&minutes);
    return hours*60 + minutes;
}

bool busy[30 * 24 * 60 + 5];
int nex[30 * 24 * 60 + 5];

int jump[1440 + 5][MAXN+5];

int best[30*24*60+5][MAXN+5];
bool choose[30*24*60+5][MAXN+5];
bool flag[30*24*60+5][MAXN+5];

int solve(int day,int ind)
{
    if (day >= k * 1440)
        return -oops;
    if (ind == n)
    return 0;

    int &ret = best[day][ind];

    if (flag[day][ind])
        return ret;

    ret = solve(day,ind+1);

    choose[day][ind]=0;

    if (~job[ind].subject_id && day + jump[day%1440][job[ind].subject_id] <= job[ind].deadline)
    {
        int temp = job[ind].profit + solve(day+jump[day%1440][job[ind].subject_id],ind+1);

        if (temp > ret)
        {
            ret = temp;
            choose[day][ind]=1;
        }
    }
    flag[day][ind]=1;
    return ret;
}


int main()
{
    FILE *in=stdin;
    int c,c2;
    fscanf(in,"%d%d%d",&m,&n,&k);
    for (c=0;c<m;c++)
    {
        fscanf(in,"%s",tempo);
        mp[subject[c].name=tempo]=c;
    }
    for (c=0;c<m;c++)
        fscanf(in,"%d",&subject[c].time);

    for (c=0;c<4;c++){
        from[c]=scanTime(in);
        fscanf(in,"-");
        to[c]=scanTime(in);
    }
    char st[40];
    for (c=0;c<n;c++)
    {
        fscanf(in,"%s",st);

        map<string,int>::iterator it = mp.find(st);
        job[c].input_id = c+1;
        job[c].subject_id = -1;
        if (it!=mp.end())
            job[c].subject_id = it->second;
        int day;
        fscanf(in,"%d",&day);

        job[c].deadline = (day-1)*1440 + scanTime(in);
        fscanf(in,"%d",&job[c].profit);
    }
    sort(job,job+n);

    int c3;

    for (c=0;c<k;c++)
        for (c2=0;c2<4;c2++)
            for (c3=from[c2];c3<=to[c2];c3++)
                busy[c*1440 + c3]=1;
    int farfree = k*1440;
    int nearfree = k*1440;
    for (int day=k*1440-1;day>=0;day--)
    {
        if (busy[day])
        {
            nex[day] = nearfree;
            farfree = -1;
        }
        else
        {
            farfree=max(farfree,day);
            nearfree = day;
            nex[day] = farfree;
        }
    }

    for (c=0;c<k*1440;c++)
        if (!busy[c])
            break;

    if (c == k*1440){
        printf("0\n0\n");
        return 0;
    }

    for (c=0;c<1440;c++)
        for (c2=0;c2<m;c2++)
        {
            int total = subject[c2].time;
            int now = c;
            while(now<k*1440 && total)
            {
                if (busy[now])now = nex[now];
                else
                {
                    int alpha = min(total,nex[now]-now+1);
                    now+=alpha;
                    total-=alpha;
                }
            }
            if (total)
                jump[c][c2]=oops;
            else jump[c][c2] = now - c;
        }

    int ret = solve(0,0);
    printf("%d\n",ret);
    int jobs=0;
    int day = 0;
    int ind = 0;

    for (ind=0;ind<n;ind++)
    {
        if (choose[day][ind])
        {
            day+=jump[day%1440][job[ind].subject_id];
            jobs++;
        }
    }
    printf("%d\n",jobs);
    for (day=0,ind=0;ind<n;ind++)
    {
        if (choose[day][ind])
        {
            int start = day;

            int ending = day + jump[day%1440][job[ind].subject_id] - 1;

            if (busy[start])

                start = nex[start];
            printf("%d %d %.2d:%.2d %d %.2d:%.2d\n",job[ind].input_id,start/1440 + 1,start%1440/60,start%1440%60,ending/1440+1,ending%1440/60,ending%1440%60);
            day = ending+1;
        }
    }


}
