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
LL s,x;
LL a[N],sum[N];
//LL pre[N];
void solve()
{
	cin>>n>>s>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
//		pre[i]=pre[i-1]+(a[i]==x);
	}
	int last_x=0;
	LL ans=0;
	map<LL,int>mp;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>x)
		{
			mp.clear();
			last_x=i;
			continue;
		}
		if(a[i]==x)
		{
			//add
			for(int j=last_x;j<i;j++)
			{
				mp[sum[j]]++;
//				cout<<"add "<<sum[j]<<endl;
			}
			last_x=i;
		}
		if(a[i]<=x)
		{
			//ask
			//pre[i]-pre[old]==s
			//pre[old]==pre[i]-s
			ans+=mp[sum[i]-s];
//			cout<<"i="<<i<<" sum="<<sum[i]<<" ask(sum[i]-s)="<<sum[i]-s<<" ans+="<<mp[sum[i]-s]<<endl;
		}
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
