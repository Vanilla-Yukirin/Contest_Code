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
int n;
void solve()
{
	cin>>n;
	bool is_rev=0;
	LL sum=0;
	LL ans=0,rans=0;
	deque<LL>q;
	while(n--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			LL tail;
			if(is_rev) tail=q.front(),q.pop_front(),q.push_back(tail);
			else tail=q.back(),q.pop_back(),q.push_front(tail);
			
			if(is_rev)
			{
				rans=rans+(sum-tail)-tail*q.size();
				rans+=tail;
				
				ans=(q.size()+1)*sum-rans;
			}
			else
			{
				ans=ans+(sum-tail)-tail*q.size();
				ans+=tail;

				rans=(q.size()+1)*sum-ans;
			}
			
			
		}
		if(op==2)
		{
			is_rev^=1;
		}
		if(op==3)
		{
			int c;
			cin>>c;
			if(is_rev) q.push_front(c),ans+=sum+c,sum+=c;
			else q.push_back(c),ans+=c*q.size(),sum+=c;
			
			rans=(q.size()+1)*sum-ans;
		}
		
		if(is_rev) cout<<rans<<endl;
		else cout<<ans<<endl;
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
