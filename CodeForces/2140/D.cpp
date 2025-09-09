/**************************************************************
 * Problem: 
 * Author: Vanilla_chan
 * Date: 
 * E-Mail: heshaohong2015@outlook.com
 **************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define IL inline
#define re register

typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
typedef unsigned long long ull;
#define mk(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define fi first
#define se second
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
#define ALICE cout<<"Alice"<<endl
#define BOB cout<<"Bob"<<endl
#define ALL(x) (x).begin(),(x).end()
#define endl '\n'



#ifdef TH

std::string COLORS[]={"\033[0m","\033[91m","\033[92m","\033[93m","\033[94m","\033[95m","\033[96m"};
std::string COLOR_NAMES[]={"RESET","RED","GREEN","YELLOW","BLUE","MAGENTA","CYAN"};

#define debug cout<<COLORS[6]<<"Now is "<<__LINE__<<COLORS[0]<<endl;

#define DEBUG(x,color)                   \
cout<<COLORS[color];                     \
cout <<"LINE"<<__LINE__<< "\t: " << #x << " : " << x << endl;        \
cout<<COLORS[0];                         \
cout.flush();

void fastIO()
{
	return;
}


#else

#define debug
#define DEBUG(x,color)

void fastIO()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	return;
}

#endif


#define LOOP(While_times) while(While_times-->0)
#define FOR(x,y) for(auto III=(x);III<=(y);III++)

const LL   p9982 = 998244353;
const LL  p1e9p7 = 1000000007;
const LL  p1e9p9 = 1000000009;
const LL   p1926 = 19260817;
const double eps = 1e-6;
const double  pi = acos(-1);
const LL     e18 = 1000000000000000000ll;
const LL     e17 = 100000000000000000ll;
const LL      e9 = 1000000000ll;


const LL       p = p9982;
const LL     inf = e9;
const LL     INF = e18;

const int N = 2000010;
const int M = 2000010;

int n,l[N],r[N];
set<pair<int,int>>lm,rm;
void del(int x)
{
	auto it=lm.find(mk(l[x],x)); if(it!=lm.end()) lm.erase(it);
	it=rm.find(mk(-r[x],x)); if(it!=rm.end()) rm.erase(it);
}
void solve()
{
	cin>>n;
	LL ans=0;
	lm.clear();
	rm.clear();
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		ans+=r[i]-l[i];
		lm.insert(mk(l[i],i));
		rm.insert(mk(-r[i],i));
	}
	while(1)
	{
		if(lm.size()==0||rm.size()==0) break;
		int idl=lm.begin()->second;
		int idr=rm.begin()->second;
		if(idl!=idr)
		{
			del(idl);
			del(idr);
			ans+=r[idr]-l[idl];
		}
		else
		{
			if(lm.size()==1&&rm.size()==1)
			{
				break;
			}
			if(lm.size()==1)
			{
				del(idl);
				idr=rm.begin()->second;
				del(idr);
				ans+=r[idr]-l[idl];
			}
			else if(rm.size()==1)
			{
				del(idl);
				idl=lm.begin()->second;
				del(idl);
				ans+=r[idr]-l[idl];
			}
			else
			{
				int idx=idl;
				del(idx);
				idl=lm.begin()->second;
				idr=rm.begin()->second;
				//choose
				LL ans1=r[idr]-l[idx],ans2=r[idx]-l[idl];
				if(ans1>ans2)
				{
					del(idr);
					ans+=ans1;
				}
				else
				{
					del(idl);
					ans+=ans2;
				}
			}
		}
	}
	
	cout<<ans<<endl;
}

int main()
{
	fastIO();
	cout.precision(10);
	int t=1;
	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
