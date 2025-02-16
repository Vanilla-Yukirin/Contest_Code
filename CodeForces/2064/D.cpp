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


#define N 200010

int n,q,a[N],b[N];
int mx[N][24];
int lg[N];
int calc_b(int x)
{
//	debug
	int ans=0;
	while(x) x>>=1,ans++;
	return ans;
}
void pre()
{
	for(int j=1;j<21;j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
		}
	}
}
int ask(int x,int y)
{
//	cout<<"ask "<<x<<" "<<y<<endl;
	return max(mx[x][lg[y-x+1]],mx[y-(1<<lg[y-x+1])+1][lg[y-x+1]]);
}
int suf[N],sum_xor[N],sum[N];
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=calc_b(a[i]);
		mx[i][0]=b[i];
		sum_xor[i]=sum_xor[i-1]^a[i];
		sum[i]=sum[i-1]+a[i];
	}
	pre();
//	suf[n]=a[n];
//	for(int i=n-1;i>=1;i++)
//	{
//		suf[i]=suf[i+1]^a[i];
//	}
	while(q--)
	{
		int x;cin>>x;
		int now=n+1,ans=0;
		while(1)
		{
			int b_x=calc_b(x);
			if(now==1) break;
			if(x<a[now-1]) break;
			// 倍增
			int jump=now;
			for(int k=21;k>=0;k--)
			{
				int tar=jump-(1<<k);
				if(tar<=0) continue;
				if(ask(tar,now-1)<b_x)
				{
//					DEBUG(ask(tar,now-1),4);
//					DEBUG(b_x,4);
//					DEBUG(k,4);
//					DEBUG(tar,4);
					jump=tar;
				}
			}
			if(jump!=now) //can jump
			{
				x^=(sum_xor[now-1]^sum_xor[jump-1]);
				ans+=now-jump;
//				DEBUG(ans,2);
				now=jump;
			}
			else
			{
				if(x>=a[now-1])
				{
					x^=a[now-1];
					ans++;
//					DEBUG(ans,3);
					now--;
				}
			}
//			DEBUG(now,1);
		}
		cout<<ans<<" ";
	}
	cout<<endl;
	
}

int main()
{
	lg[1]=0;
	for(int i=2;i<=200000;i++) lg[i]=lg[i>>1]+1;
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
