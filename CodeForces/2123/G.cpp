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

int n,m,q;
int a[N];
LL tail[N];
LL gcd(LL a,LL b)
{
	if(b) return gcd(b,a%b);
	return a;
}
vector<int>yz;
vector<pair<int,int>>zyz;
void dfs(int x,int now)
{
	if(x==zyz.size())
	{
		yz.push_back(now);
		return;
	}
	for(int i=0;i<=zyz[x].second;i++)
	{
		dfs(x+1,now);
		now*=zyz[x].first;
	}
}

void solve()
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	//zyz
	zyz.clear();
	yz.clear();
	int mm=m;
	for(int i=2;i<=mm;i++)
	{
		if(mm%i==0) zyz.push_back(mk(i,0));
		while(mm%i==0)
		{
			mm/=i;
			zyz.back().second++;
		}
	}
//	DEBUG(zyz.size(),1);
	//yz
	dfs(0,1);
//	DEBUG(yz.size(),1);
	//init
	for(int g=0;g<yz.size();g++)
	{
		LL now=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i-1]%yz[g]==a[i]%yz[g]) now=now;
			else now+=((a[i]-a[i-1])%yz[g]+yz[g])%yz[g];
		}
		tail[g]=now;
//		cout<<"g="<<yz[g]<<" tail="<<tail[g]<<endl;
	}
	while(q--)
	{
		int op,x,y;
		cin>>op;
		if(op==1)
		{
			cin>>x>>y;
			int old=a[x];
			a[x]=y;
			for(int g=0;g<yz.size();g++)
			{
				int delta[2]={0,0};
				if(x==0) a[0]=old;
				if(x==n) a[n+1]=old;
				delta[0]=((old-a[x-1])%yz[g]+yz[g])%yz[g];
				delta[1]=((a[x+1]-old)%yz[g]+yz[g])%yz[g];
//				cout<<"d0="<<delta[0]<<" d1="<<delta[1]<<endl;
				tail[g]-=delta[0]+delta[1];
				
				
				if(x==0) a[0]=y;
				if(x==n) a[n+1]=y;
				delta[0]=((a[x]-a[x-1])%yz[g]+yz[g])%yz[g];
				delta[1]=((a[x+1]-a[x])%yz[g]+yz[g])%yz[g];
				tail[g]+=delta[0]+delta[1];
//				cout<<"d0="<<delta[0]<<" d1="<<delta[1]<<endl;
				
//				cout<<"g="<<yz[g]<<" tail="<<tail[g]<<endl;
			}
		}
		else
		{
			cin>>x;
			x=gcd(x,m);
			for(int g=0;g<yz.size();g++)
			{
				if(yz[g]==x) y=g;
			}
			if(tail[y]<m) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
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
	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
