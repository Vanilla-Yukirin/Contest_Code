/**************************************************************
 * Problem: 
 * Author: Neko_Yukirin
 * Date: 
 * E-Mail: Neko_Yukirin@outlook.com
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

typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<double,double> pdd;
typedef pair<int,int> pii;

typedef pair<pii,int> ppiii;
typedef pair<int,pii> pipii;

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
int len;
vector<int>A,S1,S0,B1,B2;
void solve()
{
	cin>>n;
	len=1;
	while((1<<len)<=n) len++;
	DEBUG(len,1);
	A.clear();S1.clear();S0.clear();B1.clear();B2.clear();
	
	
	for(int i=1;i<=n;i++)
	{
		A.push_back(i);
		B1.push_back(i);
//		int x=i;
//		for(int j=0;j<len;j++)
//		{
//			if(((1<<j)&x))
//			{
//				sum[j]++;
//			}
//		}
	}
	A.pop_back();
	
	
	for(int j=0;j<len;j++)
	{
		DEBUG(j,2);
		
		int sum=0;
		for(unsigned int i=0;i<B1.size();i++)
		{
			if((B1[i]&(1<<j))) sum++;
		}
		DEBUG(sum,2);
		
		for(unsigned int i=0;i<A.size();i++)
		{
			int x=A[i];
			
			
			cout<<"? "<<x<<" "<<(1<<j)<<endl;
			int b;cin>>b;
			if(b==-1)
			{
				exit(0);
			}
			if(b==1) sum--;
			if(b==1) S1.push_back(x);
			else S0.push_back(x);
		}
//		sol[j]=sum;
		
		DEBUG(sum,3);
		if(sum) A=S1;
		else A=S0;
		S0.clear();
		S1.clear();
		
		
		//guolv
		B2.clear();
		for(unsigned int i=0;i<B1.size();i++)
		{
			if(((B1[i]&(1<<j))!=0)==sum) B2.push_back(B1[i]);
			DEBUG(B1[i],4);
		}
		B1=B2;
		
		DEBUG(B2.size(),2);
		
		if(B1.size()==1)
		{
			cout<<"! "<<B1[0]<<endl;
			return;
		}
		
	}
}

int main()
{
//	fastIO();
	cout.precision(10);
	int t=1;
	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
