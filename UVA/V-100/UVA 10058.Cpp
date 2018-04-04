/*
explanation : here its obvious that the solution will be recursively and i represent the problem as a graph 
each node is either the oring of its children or anding of its children 
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
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
int st,vis[1000][1000];
map< string,int> mb;
vector< pair< vector < int> , int > > v(1000);
vector< string> arr;
vector<int> v1;
int fun(int n)
{
   if(vis[n][st])
        return 0;

    vis[n][st]=1;

    if((n>=13&&n<=30))
    {
       if( v1[st]==n )
       {

           st++;
          return 1;
       }
       return 0;
    }


    if(v[n].second==1)
    {


        for(int i=0;i<sz(v[n].first);i++)
        {

           if( fun(v[n].first[i]) )
            ;
           else
            return 0;


        }

        return 1;
    }
   else
   {

       for(int i=0;i<sz(v[n].first);i++)
       {

           if(fun(v[n].first[i])==1)
           {
               if(n==3&&v[n].first[i]==5)
               {

                   if(st==sz(v1)||v1[st]!=6)
                    return 1;
                    else
                     {
                      //   cout<<"1  "<<n<<endl;
                         st+=1;
                         if(fun(3)==1)
                            return 1;
                         return 0;
                     }


               }
               else if(n==1&&v[n].first[i]==2)
               {
                   if(st==sz(v1))
                    return 1;
                   else if(v1[st]==31)
                   {
                      // cout<<"2  "<<st<<endl;
                       st++;
                       if(fun(1))
                        return 1;
                       else
                        return 0;
                    }
                    else
                        return 0;
               }
               else
               return 1;
           }
       }

       return 0;
   }
}





int main()
{

    v[1].first.pb(2);

    v[2].first.pb(11);


    v[11].first.pb(3);
    v[11].first.pb(4);
    v[11].first.pb(3);

    v[3].first.pb(5);


    v[5].first.pb(7);
    v[5].first.pb(8);

    v[8].first.pb(9);
    v[8].first.pb(7);

    v[8].second=1;
    v[10].second=1;
    v[11].second=1;
    v[12].second=1;

   int id=13;
   mb["hate"]=id++;
   mb["love"]=id++;
   mb["know"]=id++;
   mb["like"]=id++;
   mb["hates"]=id++;
   mb["loves"]=id++;
   mb["knows"]=id++;
   mb["likes"]=id++;

   v[4].first.pb(13);
   v[4].first.pb(14);
   v[4].first.pb(15);
   v[4].first.pb(16);
   v[4].first.pb(17);
   v[4].first.pb(18);
   v[4].first.pb(19);
   v[4].first.pb(20);

   mb["tom"]=id++;
   mb["jerry"]=id++;
   mb["goofy"]=id++;
   mb["mickey"]=id++;
   mb["jimmy"]=id++;
   mb["dog"]=id++;
   mb["cat"]=id++;
   mb["mouse"]=id++;

   v[7].first.pb(21);
   v[7].first.pb(22);
   v[7].first.pb(23);
   v[7].first.pb(24);
   v[7].first.pb(25);
   v[7].first.pb(26);
   v[7].first.pb(27);
   v[7].first.pb(28);

   mb["and"]=6;

   mb["a"]=id++;
   mb["the"]=id++;

   v[9].first.pb(29);
   v[9].first.pb(30);

   mb[","]=id;
   string line;
   while(getline(cin,line))
   {

    arr.clear();
    v1.clear();
   stringstream ss;
   ss<<line;
   string str;
   while(ss>>str)
   arr.pb(str);


   for(int i=0;i<sz(arr);i++)
   {
       //cout<<arr[i]<<" "<<mb[arr[i]]<<endl;
       if(mb[arr[i]]==0)
       v1.pb(-1);
       else
        v1.pb(mb[arr[i]]);
   }



   st=0;
   clr(vis,0);
int ans= fun(1);
if(ans)
    cout<<"YES I WILL\n";
else
    cout<<"NO I WON'T\n";
  line="";
  cin.clear();
  }
}





