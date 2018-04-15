/*
it is implementation problem
what you need id addition and multiplication 
At addition it a and y must have the same powers
the term is coff and xpower and ypower
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
int dcmp(long double a,long double b){   return fabsl(a-b)<=eps ? 0: (a>b)? 1:-1  ;}
ll getBit(int num, int idx) {return ((num >> idx) & 1) == 1;}
ll setBit1(ll num, int idx) {return num | (1ll<<idx);}
ll setBit0(ll num, int idx) {return num & ~(1ll<<idx);}
ll flipBit(ll num, int idx) {return num ^ (1ll<<idx);}
void M(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
int countNumBit1(ll mask) {int ret=0; while (mask) 	{mask &= (mask-1ll);++ret;	}return ret;}
vector< pair< pair<int,int> , int > > ans,fnl;
string a,b;
int vis[10009][10009];
pair<int,vector< pair< pair<int,int> , int > >> fun(string a)
{
    vector< pair< pair<int,int> , int > > v1(109);
       string s="";
       int tra=0;
       int fl=0;
       int X=0,Y=0;

    for(int i=0;i<sz(a);i++)
       {
           int coff,pwx,pwy;
           if(a[i]=='x'||a[i]=='y')
           {
                  if(fl==0)
                  {
                      if(s==""||s=="+")
                        coff=1;
                      else if(s=="-")
                        coff=-1;
                      else
                        coff=atoi(s.c_str());
                      v1[tra].second=coff;
                      fl=1;
                  }

                  else if(a[i]=='x'&&fl==1)
                  {
                      if(s=="")
                        pwy=1;
                      else
                        pwy=atoi(s.c_str());
                      v1[tra].first.second=pwy;
                  }
                  else if(a[i]=='y'&&fl==1)
                  {
                      if(s=="")
                      pwx=1;
                      else
                        pwx=atoi(s.c_str());
                      v1[tra].first.first=pwx;
                  }


                  s="";
                  if(a[i]=='x'&&Y==0)
                    X=1;
                  else if(a[i]=='x'&&Y==1)
                    X=2;

                if(a[i]=='y'&&X==0)
                    Y=1;
                else if(a[i]=='y'&&X==1)
                    Y=2;

                  continue;
           }


           if((a[i]=='+'||a[i]=='-')&&i!=0)
           {

              if(X==1&&Y==0)
              {
                  if(s=="")
                    pwx=1;
                  else
                    pwx=atoi(s.c_str());

                  v1[tra].first.first=pwx;
              }
              else if(X!=0&&Y!=0)
              {
                  pwy=-1;
                  if(s=="")
                  {
                      if(Y==2)
                      pwy=1;
                      else
                      pwx=1;
                  }
                  else
                  {
                     if(Y==2)
                    pwy=atoi(s.c_str());
                    else
                    pwx=atoi(s.c_str());

                  }
                  if(pwy!=-1)
                  v1[tra].first.second=pwy;
                  else
                   v1[tra].first.first=pwx;

              }
              else if(X==0&&Y==0)
              {
                  v1[tra].second=atoi(s.c_str());
              }
              else if(X==0&&Y==1)
              {
                  if(s=="")
                    pwy=1;
                  else
                    pwy=atoi(s.c_str());

                  v1[tra].first.second=pwy;
              }

              fl=0;
              s="";
              tra++;
              X=0; Y=0;
           }
           s+=a[i];
       }

       return mp(tra,v1);

}

void multi(pair< pair<int,int> , int > a,pair< pair<int,int> , int > b)
{


        int px=a.first.first+ b.first.first;
        int py=a.first.second+ b.first.second;
        int coff= a.second*b.second;


        ans.pb(mp(mp(px,py),coff));

}


void Add(vector< pair< pair<int,int> , int > > temp)
{

    int sum=0;
    if(sz(temp)==0)
        return ;
    for(int i=0;i<sz(temp);i++)
    {
         sum+=temp[i].second;
         pair< pair<int,int> , int >  tp= temp[i];
         tp.first.second*=-1;

         auto it=find(all(fnl),tp);
         if(it!=fnl.end())
         fnl.erase(it);
    }

    fnl.pb(mp(mp(temp[0].first.first,-temp[0].first.second),sum));
}













int main()
{

    while(cin>>a)
    {
        ans.clear();
        fnl.clear();
        clr(vis,0);

        if(a=="#")
            break;

       cin>>b;

       a+='+';
       b+='+';

    pair<int,vector< pair< pair<int,int> ,int > >> p1= fun(a);

    vector< pair< pair<int,int> , int>  > v1=p1.second;
    int tra=p1.first;

    pair<int,vector< pair< pair<int,int> , int > >> p2= fun(b);

    vector< pair< pair<int,int> , int > > v2=p2.second;
    int trb=p2.first;
    for(int i=0;i<tra;i++)
    {
        for(int j=0;j<trb;j++)
        {
            multi(v1[i],v2[j]);

        }
    }

    for(int i=0;i<sz(ans);i++)
    {
       pair< pair<int,int> , int >  tp= ans[i];
       tp.first.second*=-1;
       fnl.pb(tp);
    }


        for(int k=0;k<sz(ans);k++)
        {

            vector< pair< pair<int,int> ,int > > temp;
            int xx=ans[k].first.first;  int yy=ans[k].first.second;
            if(vis[xx][yy])
                continue;
            vis[xx][yy]=1;
            for(int j=0;j<sz(ans);j++)
            {

                if(ans[j].first.first==ans[k].first.first&&ans[j].first.second==ans[k].first.second)
                {

                   temp.pb(ans[j]);

                }
            }

            Add(temp);

        }
    sort(allr(fnl));

    string pw=""; string res=""; int fl=0;

    for(int i=0;i<sz(fnl);i++)
    {
        int pwx= fnl[i].first.first;
        int pwy=-fnl[i].first.second;
        int coff= fnl[i].second;
        int kd;
        if(coff==0)
            continue;
        if(pwx==0&&pwy==0)
            kd=3;
        else if(pwx!=0&&pwy!=0)
            kd=2;
        else if(pwx==0&&pwy!=0)
            kd=1;
        else
            kd=0;



        if(kd==0||kd==1)
        {
            if(fl==0)
            {

                string w= to_string(coff);
                if(w=="-1")
                    w="-";
                else if(w=="1")
                    w="";
                res+=w;
                if(kd==0)
                res+="x";
                else
                res+="y";

                for(int j=0;j<sz(w)+1;j++)
                    pw+=" ";

                string h;
                if(kd==0)
                h= to_string(pwx);
                else
                 h= to_string(pwy);
                if(h=="1")
                    h="";
                pw+=h;

                for(int j=0;j<sz(h);j++)
                    res+=" ";
                fl=1;
            }
            else
            {
                string w=to_string(abs(coff));

                if(coff<0)
                {
                    res+=" - ";
                    pw+="   ";
                }
                else
                 {
                     res+=" + ";
                     pw+="   ";
                 }

                 coff=abs(coff);
                 if(coff==1)
                    w="";
                res+=w;
                if(kd==0)
                res+="x";
                else
                res+="y";

                for(int j=0;j<sz(w)+1;j++)
                    pw+=" ";

                string h;
                if(kd==0)
                h= to_string(pwx);
                else
                h= to_string(pwy);
                if(h=="1")
                    h="";
                pw+=h;

                for(int j=0;j<sz(h);j++)
                    res+=" ";
            }
        }

        if(kd==2)
        {

              if(fl==0)
            {

                string w= to_string(coff);
                if(w=="-1")
                    w="-";
                else if(w=="1")
                    w="";
                res+=w;

                res+="x";


                for(int j=0;j<sz(w)+1;j++)
                    pw+=" ";

                string h= to_string(pwx);
                if(h=="1")
                    h="";
                pw+=h;

                for(int j=0;j<sz(h);j++)
                    res+=" ";

                res+="y";
                pw+=" ";

                string wh= to_string(pwy);
                if(wh=="1")
                    wh="";
                pw+=wh;

                for(int j=0;j<sz(wh);j++)
                    res+=" ";

                fl=1;
            }
            else
            {

                string w=to_string(abs(coff));

                if(coff<0)
                {
                    res+=" - ";
                    pw+="   ";
                }
                else
                 {
                     res+=" + ";
                     pw+="   ";
                 }

                 coff=abs(coff);
                 if(coff==1)
                    w="";
                res+=w;

                res+="x";

                for(int j=0;j<sz(w)+1;j++)
                    pw+=" ";

                string h= to_string(pwx);
                if(h=="1")
                    h="";
                pw+=h;

                for(int j=0;j<sz(h);j++)
                    res+=" ";

                res+="y";
                pw+=" ";

                string wh= to_string(pwy);
                if(wh=="1")
                    wh="";
                pw+=wh;

                for(int j=0;j<sz(wh);j++)
                    res+=" ";
            }
        }

        if(kd==3)
        {
            if(fl==0)
            {
                string w= to_string(coff);
                res+=w;

                for(int j=0;j<sz(w);j++)
                    pw+=" ";
                fl=1;
            }
            else
            {
                 string w=to_string(abs(coff));

                if(coff<0)
                {
                    res+=" - ";
                    pw+="   ";
                }
                else
                 {
                     res+=" + ";
                     pw+="   ";
                 }

                res+=w;

                for(int j=0;j<sz(w);j++)
                    pw+=" ";
            }
        }
    }
    if(!fl)
    res="0";
    cout<<pw<<endl<<res<<endl;
    }
}
