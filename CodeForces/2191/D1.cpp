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



int n;
string s;
int sufo[N],sufc[N];
void solve()
{
	cin>>n;
	cin>>s;
	s=" "+s;
	sufo[n+1]=sufc[n+1]=0;
	for(int i=n;i>=1;i--)
	{
		sufo[i]=sufo[i+1];
		sufc[i]=sufc[i+1];
		if(s[i]=='(')
			sufo[i]++;
		else if(s[i]==')')
			sufc[i]++;
	}
//	int k=0,maxans=-1;
//	for(int i=1;i<=n;i++)
//	{
//		if(s[i]=='(')
//			k++;
//		else k--;
//		if(s[i]==')')
//		{
//			int o=sufo[i+1];
//			int c=sufc[i+1];
//			if()
//				int ans=i+2*min(c-k,o);
//			maxans=max(ans,maxans);
//		}
//	}
	for(int i=1;i<=n-2;i++)
	{
		if(s[i]==')'&&s[i+1]=='('&&sufo[i+2]>0)
		{
			cout<<n-2<<endl;
			return;
		}
	}
//	cout<<maxans<<endl;
	cout<<-1<<endl;
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
