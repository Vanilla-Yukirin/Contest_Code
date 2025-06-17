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

int n;
int a[N],b[N];
void solve()
{
	vector<pair<int,int>>ans;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]<a[i])
		{
			swap(a[i],b[i]);
//			cout<<"3 "<<i<<endl;
			ans.pb(mk(3,i));
		}
	}
//	sort(a+1,a+n+1);
//	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(a[j]>a[j+1])
			{
//				cout<<"1 "<<j<<endl;
				ans.pb(mk(1,j));
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(b[j]>b[j+1])
			{
//				cout<<"2 "<<j<<endl;
				ans.pb(mk(2,j));
				swap(b[j],b[j+1]);
			}
		}
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++)
//	{
//		cout<<b[i]<<" ";
//	}
//	cout<<endl;
	//check
//	bool succ=1;
//	for(int i=1;i<n;i++)
//	{
//		if(a[i]>a[i+1]) succ=0;
//		if(b[i]>b[i+1]) succ=0;
//	}
//	for(int i=1;i<=n;i++)
//	{
//		if(a[i]>b[i]) succ=0;
//	}
//	cout<<succ<<endl;
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
