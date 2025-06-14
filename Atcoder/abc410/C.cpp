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

int n,q;
int a[N];
LL mov;
int mv(LL x)
{
	x+=mov;
	x=x-1;
	x%=n;
	x++;
	return x;
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) a[i]=i;
	while(q--)
	{
		int op;
		cin>>op;
		int x,y;
		if(op==1)
		{
			cin>>x>>y;
			a[mv(x)]=y;
		}
		if(op==2)
		{
			cin>>x;
			cout<<a[mv(x)]<<endl;
		}
		if(op==3)
		{
			cin>>x;
			mov+=x;
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
