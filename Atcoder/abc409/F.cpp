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

LL a[N],b[N];
int n,m;
#define Edge pair<LL,pair<int,int>>
priority_queue<Edge,vector<Edge>,greater<Edge>>q;
int f[N];
int getf(int x)
{
	if(f[x]==x) return x;
	return f[x]=getf(f[x]);
}
void merge(int x,int y)
{
	f[getf(x)]=getf(y);
}
bool ask(int x,int y)
{
	return (getf(x)==getf(y));
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		f[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			q.push(mk(abs(a[i]-a[j])+abs(b[i]-b[j]),mk(i,j)));
		}
	}
	while(m--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			n++;
			cin>>a[n]>>b[n];
			f[n]=n;
			for(int i=1;i<=n-1;i++)
			{
				q.push(mk(abs(a[i]-a[n])+abs(b[i]-b[n]),mk(i,n)));
			}
		}
		if(op==2)
		{
			bool succ=0;
			LL d=-1;
			while(q.size())
			{
				Edge e=q.top();
				if(ask(e.second.first,e.second.second))
				{
					q.pop();
					continue;
				}
				if(succ)
				{
					if(d==e.first)
					{
						merge(e.second.first,e.second.second);
						q.pop();
					}
					else break;
				}
				else
				{
					succ=1;
					merge(e.second.first,e.second.second);
//					cout<<"merge "<<e.second.first<<" "<<e.second.second<<endl;
					d=e.first;
					q.pop();
				}
				
				
			}
			if(succ) cout<<d<<endl;
			else cout<<"-1"<<endl;
		}
		if(op==3)
		{
			int x,y;cin>>x>>y;
			if(ask(x,y)) cout<<"Yes"<<endl;
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
//	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
