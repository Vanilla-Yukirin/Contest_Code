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


#define N 10000010

LL L,R;
LL prime[N],cnt;
bool book[N];
bool book2[N];
void solve()
{
	cin>>L>>R;
	for(int i=2;i<=10000000;i++)
	{
		if(!book[i])
		{
			prime[++cnt]=i;
			for(int j=2;i*1ll*j<=10000000;j++)
			{
				book[i*j]=1;
			}
		}
	}
	int pk=0;
	for(int i=1;i<=cnt;i++)
	{
		LL now=prime[i];
		now=now*now;
		if(now>R) break;
		for(int k=2;now<=R;k++,now*=prime[i])
		{
			if(now>=L+1) pk++;
		}
	}
//	DEBUG(pk,1);
	int p0=R-L;
	for(int i=1;i<=cnt;i++)
	{
		LL st=max((L+1+prime[i]-1)/prime[i]*prime[i],prime[i]*prime[i]);
		for(LL j=st;j<=R;j+=prime[i])
		{
			if(j>=L&&book2[j-L]==0)
			{
				book2[j-L]=1;
				p0--;
			}
		}
	}
//	DEBUG(p0,2);
	cout<<pk+p0+1<<endl;
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
