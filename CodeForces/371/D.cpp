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
int n,m;
LL a[N];
pair<LL,int>link[N];
#define inf 0x3f3f3f3f
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		link[i]=mk(a[i],i+1);
	}
//	link[n]=mk(a[n],0);
	a[n+1]=inf;
	link[n+1]=mk(a[n+1],n+2);
	link[0].second=1;
	cin>>m;
	while(m--)
	{
		int op,x;
		LL y;
		cin>>op;
		if(op==1)
		{
			cin>>x>>y;
			int p=x-1,q=x;
			while(p<=n)
			{
				int d=min(link[q].first,y);
				y-=d;
				link[q].first-=d;
				if(link[q].first<=0)
				{
					link[p].second=link[q].second;
				}
				if(y<=0)
				{
					break;
				}
				if(y==0) break;
				p=q;
				q=link[q].second;
			}
		}
		else
		{
			cin>>x;
			cout<<a[x]-link[x].first<<endl;
		}
	}
}

int main()
{
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
