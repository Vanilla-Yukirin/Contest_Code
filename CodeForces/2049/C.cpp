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
#define pb(a,b) push_back(a,b)
//#define endl '\n'
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
int four[10]={0,2,1,0,1};
void solve()
{
	int x,y;
	cin>>n>>x>>y;
	if(n==3)
	{
//		debug
		cout<<"0 1 2"<<endl;
	}
	else if(n==4)
	{
//		debug
		if(y-x==1||y-x==n-1)//no change
		{
			cout<<"0 1 0 1"<<endl;
		}
		else
		{
			vector<int>ans(n+1);
			for(int i=1,j=x;i<=n;i++,j=(j%n)+1)
			{
				ans[j]=four[i];
			}
			for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
			cout<<endl;
		}
	}
	else
	{
		if(n%3==0)
		{
			if(y-x==1||y-x==n-1)
			{
				for(int i=1;i<=n;i++)
				{
					cout<<i%3<<" ";
				}
				cout<<endl;
			}
			else
			{
				int delta=(y-x)%3;
				if(delta==0)
				{
					/*
					确定x，让x为1
					交换x与x+1
					*/
					vector<int>ans(n+1);
					for(int i=1,j=x;i<=n;i++,j=(j%n)+1)
					{
						ans[j]=i%3;
					}
					swap(ans[x],ans[x+1]);
					for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
					cout<<endl;
				}
				else if(delta==1)
				{
					// 让ans[x]=1
					vector<int>ans(n+1);
					for(int i=1,j=x;i<=n;i++,j=(j%n)+1)
					{
						ans[j]=i%3;
					}
					for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
					cout<<endl;
				}
				else if(delta==2)
				{
					// 让ans[x]=2
					vector<int>ans(n+1);
					for(int i=1,j=x;i<=n;i++,j=(j%n)+1)
					{
						ans[j]=(i+1)%3;
					}
					for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
					cout<<endl;
				}
			}
			
		}
		else if(n%3==2)
		{
			int delta=y-x;
			int re_delta=n-delta;
			if(delta%3!=0)
			{
				vector<int>ans(n+1);
				if(delta<re_delta)
				{
					for(int i=1,j=x;i<=n;i++,j=(j%n)+1)
					{
						ans[j]=(i-1)%3;
					}
				}
				else
				{
//					debug;
					for(int i=1,j=x;i<=n;i++,j=(j-2+n)%n+1)
					{
						ans[j]=(i-1)%3;
					}
				}
				for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
				cout<<endl;
			}
			else
			{
				vector<int>ans(n+1);
				for(int i=1,j=x;i<=n;i++,j=(j-2+n)%n+1)
				{
					ans[j]=(i-1)%3;
				}
				for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
				cout<<endl;
			}
		}
		else if(n%3==1) //|0 1 2| 0 1 0 1
		{
//			debug
			int delta=y-x;
			int re_delta=n-delta;
			if(delta%3!=0)
			{
				vector<int>ans(n+1);
				if(delta%3==1) // 7 1 5
				{
					for(int i=1,j=x;i<=n;i++,j=(j%n)+1)
					{
						ans[j]=(i-1)%3;
						if(n-i<4)
						{
							ans[j]=(n-i+1)%2;
						}
					}
				}
				else//7 1 6
					//7 1 3!!!
				{
					for(int i=1,j=x;i<=n;i++,j=(j-2+n)%n+1)
					{
						ans[j]=(i-1)%3;
						if(n-i<4)
						{
							ans[j]=(n-i+1)%2;
						}
					}
				}
				for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
				cout<<endl;
			}
			else
			{
				vector<int>ans(n+1);
				for(int i=1,j=x;i<=n;i++,j=(j-2+n)%n+1)
				{
					ans[j]=(i-1)%3;
					if(n-i<4)
					{
						ans[j]=(n-i+1)%2;
					}
//					DEBUG(i,1);
//					DEBUG(j,2);
//					DEBUG(ans[j],3);
				}
				for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
				cout<<endl;
			}
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
