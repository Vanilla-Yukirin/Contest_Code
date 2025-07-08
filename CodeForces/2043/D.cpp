/**************************************************************
 * Problem: 
 * Author: ArisuVanilla
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


LL gcd(LL a,LL b)
{
	if(b) return gcd(b,a%b);
	return a;
}

LL l,r,g;
void solve()
{
	cin>>l>>r>>g;
	LL x=(l+g-1)/g,y=r/g;
	if(x>y)
	{
		cout<<"-1 -1"<<endl;
		return;
	}
	for(LL k=y-x;k>=0;k--)
	{
		for(LL i=x,j=x+k;j<=y;i++,j++)
		{
			if(gcd(i,j)==1)
			{
				cout<<i*g<<" "<<j*g<<endl;
				return;
			}
		}
	}
	cout<<"-1 -1"<<endl;
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
