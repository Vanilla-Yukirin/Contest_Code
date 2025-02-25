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
int pre[100][100];
LL C(LL n,LL m,LL p)
{
	if(n==0)
	{
		if(m==0) return 1;
		else return 0;
	}
	else 
	{
		if(m==0) return 1;
		else return 1;
	}
}

LL Lucas(LL n,LL m,LL p) {
	if (m == 0) return 1;
	return (C(n % p, m % p, p) * Lucas(n / p, m / p, p)) % p;
}
int n,k;
void solve()
{
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(j==1||j==i) pre[i][j]=1;
			else pre[i][j]=pre[i-1][j-1]^pre[i-1][j];
//			cout<<pre[i][j]<<" ";
		}
//		cout<<endl;
	}
//	cout<<endl;
	
	
	cin>>n>>k;
//	for(int i=0;i<n;i++)
//	{
//		if(Lucas(n-1,i,2)) cout<<k<<" ";
//		else cout<<0<<" ";
//	}cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<(Lucas(n-1,i,2)?k:0)<<" ";
	}
	cout<<endl;
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
