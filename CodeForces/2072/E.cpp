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

int k;
void solve()
{
	cin>>k;
	if(k==1)
	{
		cout<<"2\n1 1\n1 2\n"<<endl;
		return;
	}
	int sum=0;
	vector<int>vec;
	while(k>1)
	{
		LL n=0;
//		DEBUG(k,2);
		for(LL i=0;i<=k*2;i++)
		{
//			DEBUG(i*(i-1)/2,3);
			if(i*(i-1)/2>k)
			{
//				debug cout<<"i="<<i<<" k="<<k<<endl;
				n=i-1;
				break;
			}
		}
//		DEBUG(n,1);
		k-=n*(n-1)/2;
		vec.push_back(n);
		sum+=n;
//		break;
	}
	if(k==1) sum++;
	cout<<sum<<endl;
	int x=0,y=0;
	for(int i=0;i<vec.size();i++)
	{
		y++;
		while(vec[i]--)
		{
			x++;
			cout<<x<<" "<<y<<endl;
			
		}
	}
	if(k==1) y++,cout<<x<<" "<<y<<endl;
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
