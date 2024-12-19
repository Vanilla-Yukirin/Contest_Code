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
bool a[N],b[N];
vector<bool>ans,now;
int l,r;
bool upd(vector<bool>x)
{
	if(x.size()<ans.size()) return 0;
	if(x.size()>ans.size())
	{
		ans=x;
		return 1;
	}
	int bigger=1;
	for(unsigned int i=0;i<ans.size();i++)
	{
		if(x[i]<ans[i])
		{
			bigger=0;
		}
		if(x[i]>ans[i]) break;
	}
	if(bigger)
	{
		ans=x;
		return 1;
	}
	return 0;
}
void output(vector<bool>x,string str="")
{
	cout<<str<<endl;
	for(unsigned int i=0;i<x.size();i++) cout<<x[i];
	cout<<endl;
}
void solve()
{
	string str;cin>>str;
	ans.clear();
	ans.push_back(0);
	int n=str.size();
	for(int i=0;i<n;i++) a[i]=str[i]-'0';
	for(int k=0;k<n;k++)
	{
		now.clear();
		bool head=1;
//		DEBUG(k,1);
		for(int i=0;i<k;i++)
		{
			if(a[i]==0)
			{
				if(head==0) now.push_back(0);
			}
			else
			{
				now.push_back(1);
				head=0;
			}
		}
		head=1;
		int now_l=n-k;
		for(int i=k;i<n;i++)
		{
			if(a[i]==1&&a[i-k]==1)
			{
				if(head&&i!=n-1)
				{
					now.push_back(1);
				}
				else
				{
					now.push_back(0);
					now_l=min(now_l,i-k);
				}
			}
			else if(a[i]^a[i-k])
			{
				now.push_back(1);
				if(a[i-k]) head=0,now_l=min(now_l,i-k);
				else
				{
					
				}
			}
			else
			{
				if(now.size()) now.push_back(0),now_l=min(now_l,i-k);
			}
		}
//		output(now);
		if(upd(now))
		{
			l=now_l+1;
			r=n-k;
		}
	}
//	output(ans,"ANS:");
//	DEBUG(l,2);
//	DEBUG(r,2);
	cout<<1<<" "<<n<<" "<<l<<" "<<r<<endl;
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
