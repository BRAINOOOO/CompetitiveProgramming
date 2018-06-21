
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
#define     point                    complex<long double>
typedef  long long     ll ;
typedef  unsigned long long ull;
const double eps= (1e-10);
using namespace std;
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
int getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
int setBit1(int num, int idx) {return num | (1<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(int mask) {int ret=0; while (mask) 	{mask &= (mask-1);++ret;	}return ret;}
int k,m,n,q,arr[109][109];
map<string,int> mb;
vector< pair<int,string> > ans[109];
vector< pair<string,int> > ans2[109];
map< string,vector< pair<string,string> >  > v;
vector< string > comp,bc;
int main()
{
    cin>>k>>n>>m>>q;
    string st;
    for(int i=0;i<n;i++)
    {
        cin>>st;
        bc.pb(st);
        mb[st]=i+1;
    }
    string line,sst;
    cin.ignore();
    for(int i=0;i<m;i++)
    {

        getline(cin,line);

        stringstream ss(line);

        string art;
        ss>>art;

        art.erase(art.end()-1);

        string st,no;

        while(ss>>st>>no)
        {
           // cerr<<st<<" "<<no<<endl;
           if(no[sz(no)-1]==',')
            no.erase(no.end()-1);

           v[art].pb(mp(st,no));
        }
        comp.pb(art);

    }
    int num;
    while(q--)
    {

        cin>>num>>st;
        if(mb[st]==0)
            continue;

        arr[num][mb[st]]++;
    }

    for(int i=1;i<=k;i++)
    {


        for(int j=0;j<m;j++)
        {

            string com=comp[j];
            int mi=INT_MAX;

            for(int l=0;l<sz(v[com]);l++)
            {


               string basic= v[com][l].first;
               int num= atoi(v[com][l].second.c_str());

              mi= min(mi, arr[i][mb[basic]]/num);
            }



            if(mi!=0)
            ans[i].pb(mp(mi,com));
        }
    }

    for(int i=1;i<=k;i++)
    {

        sort(allr(ans[i]));

        for(int j=0;j<sz(ans[i]);j++)
        {

           string com= ans[i][j].second;
            int mi=INT_MAX;
            for(int l=0;l<sz(v[com]);l++)
            {


               string basic= v[com][l].first;
               int num= atoi(v[com][l].second.c_str());

              mi= min(mi, arr[i][mb[basic]]/num);
            }

             for(int l=0;l<sz(v[com]);l++)
            {


               string basic= v[com][l].first;
               int num= atoi(v[com][l].second.c_str());

               arr[i][mb[basic]]-= mi*num;
            }
            if(mi!=0)
                ans2[i].pb(mp(com,mi));
        }
    }







    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][mb[bc[j]]]>0)
                ans2[i].pb(mp(bc[j],arr[i][mb[bc[j]]]));
        }
    }

    for(int i=1;i<=k;i++)
        sort(all(ans2[i]));

    for(int i=1;i<=k;i++)
    {
        cout<<sz(ans2[i])<<endl;
        for(int j=0;j<sz(ans2[i]);j++)
        {
            cout<<ans2[i][j].first<<" "<<ans2[i][j].second<<endl;
        }
    }

}





