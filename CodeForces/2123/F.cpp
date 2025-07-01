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


#define N 2000100


int prime[N];
int cnt;
bool book[N];
void init()
{
	for(int i=2;i<=100010;i++)
	{
		if(!book[i])
		{
			prime[++cnt]=i;
			for(int j=i*2;j<=100010;j+=i)
			{
				book[j]=1;
			}
		}
	}
}
int n;
int ans[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) ans[i]=i;
	for(int i=n;i>=2;i--)
	{
		if(book[i]==0)
		{
//			int len=1;
//			while(len*i<=n) len++;
//			len--;
//			for(int j=1;j<len;j++)
//			{
//				ans[j*i]=ans[j*i+i];
//			}
//			ans[i*len]=i;
			vector<int>vec;
			int len=1;
			while(len*i<=n) len++;
			len--;
			for(int j=1;j<=len;j++)
			{
				if(ans[i*j]==i*j) vec.push_back(i*j);
			}
			for(int j=1;j<vec.size();j++)
			{
				ans[vec[j]]=vec[j-1];
			}
			ans[i]=vec.back();
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" \n"[i==n];
	}
}

int main()
{
	init();
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout.precision(10);
	int t=1;
	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
