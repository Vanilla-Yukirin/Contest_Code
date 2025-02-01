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


//#define N 1000010

int n;
string str;
char ans;
char calc(string str3)
{
//	DEBUG(str3.size(),5);
//	DEBUG(str.size(),5);
	int one=0;
	for(unsigned int i=0;i<str3.size();i++) if(str3[i]=='1') one++;
	if(one>=2) return '1';
	return '0';
}
pair<int,char> dfs(int dep,int x)//dep=1~N,x=0~3^dep-1
{
//	DEBUG(dep,1);
//	DEBUG(x,1);
	string now;
	int ans3[3]={0,0,0};
	if(dep==n-1)
	{
//		if(dep>n-1) cout<<"0"<<endl,exit(0);
//		cout<<"max="<<x*3+3<<endl;
		now=str.substr(x*3,3);
		for(int i=0;i<3;i++) ans3[i]=(now[i]!=ans);
	}
	else
	{
		for(int i=0;i<3;i++)
		{
			auto t=dfs(dep+1,x*3+i);
			ans3[i]=t.first;
			now.push_back(t.second);
		}
	}
//	DEBUG(now,3);
	if(calc(now)==ans)
	{
//		DEBUG(dep,4);
//		DEBUG(x,4);
//		DEBUG(now,4);
//		cout<<"现在不需要修改就可以win"<<endl;
		return make_pair(0,ans);
	}
//	int need=-1;
//	for(int i=0;i<3;i++) if(now[i]!=ans) need++;
//	sort(ans3,ans3+3);
//	int res=0;
//	for(int i=0;i<3;i++)
//	{
//		if(ans3[i]==0) continue;
//		res+=ans3[i];
//		need--;
//		if(need<=0) break;
//	}
	int need=2;
	int res=0;
	sort(ans3,ans3+3);
	for(int i=0;i<need;i++) res+=ans3[i];
//	DEBUG(dep,2);
//	DEBUG(x,2);
//	cout<<"now="<<now<<" res="<<res<<endl;
	return make_pair(res,calc(now));
}
void solve()
{
	cin>>n>>str;
	//calc ans;
	string temp=str;
	for(int i=str.size();i>1;i/=3)
	{
		for(int j=0;j*3<i;j++)
		{
			temp[j]=calc(temp.substr(j*3,3));
		}
	}
	ans=temp[0]^1;
	//
	cout<<dfs(0,0).first;
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
