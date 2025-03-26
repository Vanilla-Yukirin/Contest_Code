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

LL s,k;
vector<bool>vec,nxt;
void solve()
{
	cin>>s>>k;
	if(s>=k*k)
	{
		if(s%k==0) cout<<k<<endl;
		else cout<<max(1ll,k-2)<<endl;
	}
	else
	{
		vec.clear();
		vec.resize(s+1);
		nxt.clear();
		nxt.resize(s+1);
		vec[0]=k;
		for(int i=0;i<=s;i+=k) vec[i]=1;
		if(vec[s])
		{
			cout<<k<<endl;
			return;
		}
		bool right=0;
		for(int kk=k-1;kk>=1;kk--)
		{
//			DEBUG(kk,2);
			if(right)
			{
				for(int i=0;i<=s;i++)
				{
					if(vec[i])
					{
						for(int j=i+kk;j<=s;j+=kk)
						{
							nxt[j]=1;
						}
					}
				}
			}
			else
			{
				for(int i=s;i>=0;i--)
				{
					if(vec[i])
					{
						for(int j=i-kk;j>=0;j-=kk)
						{
							nxt[j]=1;
						}
					}
				}
			}
//			for(int i=0;i<=s;i++) cout<<nxt[i]<<" ";cout<<endl;
			if(nxt[s])
			{
				cout<<kk<<endl;
				return;
			}
			vec=nxt;
			nxt.clear();
			nxt.resize(s+1);
			right=!right;
		}
		
		cout<<1<<endl;
		
		
	}
}

int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	cout.precision(10);
	int t=1;
	cin>>t;
	LOOP(t)
	{
		solve();
	}
	return 0;
}
