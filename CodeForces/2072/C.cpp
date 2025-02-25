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

bool in(int y,int x) // check y in x?
{
	for(int k=0;k<30;k++)
	{
		if(k!=0) x>>=1,y>>=1;
		if(x&1) continue;
		if(y&1) return false;
	}
	return true;
}

int n,x;
void solve()
{
	cin>>n>>x;
	int OR=0;
	bool bai=0;
	for(int i=0;i<n;i++)
	{
		OR|=i;
		if(i==n-1)
		{
			if(OR==x) cout<<i<<" ";
			else cout<<x<<" ";
		}else
		//i in x
		if(in(OR,x)==0)
		{
//			bai=1;
			cout<<x<<" ";
		}
		else
		{
			cout<<i<<" ";
		}
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
