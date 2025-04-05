/**************************************************************
 * Problem: 
 * Author: Vanilla_chan
 * Date: 
 * E-Mail: heshaohong2015@outlook.com
 **************************************************************/
#include<bits/stdc++.h>
#define IL inline
#define re register
#define LL long long
#define ll long long
#define ULL unsigned long long
#define ull unsigned long long
#define mk(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define endl '\n'
#ifdef TH
#define debug cout<<"Now is "<<__LINE__<<endl;
#else
#define debug
#endif

std::string COLORS[]={"\033[0m","\033[91m","\033[92m","\033[93m","\033[94m","\033[95m","\033[96m"};
std::string COLOR_NAMES[]={"RESET","RED","GREEN","YELLOW","BLUE","MAGENTA","CYAN"};

#define DEBUG(x,color)                   \
cout<<COLORS[color];                     \
cout << #x << " : " << x << endl;        \
cout<<COLORS[0];                         \
cout.flush();

#define LOOP(While_times) while(While_times-->0)
using namespace std;


#define N 1000100
bool isprime[N];
vector<LL>prime;
void init()
{
	for(int i=2;i<=1000000;i++)
	{
		isprime[i]=1;
	}
	for(int i=2;i<=1000000;i++)
	{
		if(isprime[i])
		{
			prime.push_back(i);
			for(int j=i*2;j<=1000000;j+=i)
			{
				isprime[j]=0;
			}
		}
	}
}
void solve()
{
	int q;cin>>q;
	while(q--)
	{
		LL a;cin>>a;
		LL b=sqrt(a);
		while(b>=0)
		{
			LL bb=b;
			int cnt=0;
			for(int i=2;i<=sqrt(bb);i++)
			{
				if(bb%i==0)
				{
					cnt++;
					while(bb%i==0) bb/=i;
				}
			}
			if(bb!=1) cnt++;
//			DEBUG(cnt,1);
			if(cnt==2)
			{
				cout<<b*b<<endl;
				break;
			}
			b--;
		}
	}
}

int main()
{
//	init();
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
//	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
