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


#define N 1000010

int n;
LL sumL[N],sumR[N];
void solve()
{
	vector<LL>block,a;
	block.push_back(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		sumL[i]=0;
		sumR[i]=0;
		int x;
		cin>>x;a.push_back(x);
		if(i==1) block.push_back(x);
		else
		{
			if((x>0)==(block.back()>0)) block.back()+=x;
			else block.push_back(x);
		}
	}
	sumL[0]=0;
	sumR[n+1]=0;
	LL ans=0;
	for(int i=1;i<block.size();i++)
	{
		sumL[i]=sumL[i-1];
		if(block[i]>0) sumL[i]+=block[i];
	}
	for(int i=block.size()-1;i>=1;i--)
	{
		sumR[i]=sumR[i+1];
		if(block[i]<0) sumR[i]-=block[i];
	}
	for(int i=1;i<block.size();i++)
	{
		ans=max(ans,sumL[i]+sumR[i]);
	}
	cout<<ans<<endl;
}

int main()
{
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
