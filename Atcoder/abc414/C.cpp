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



LL n;
int A,B;
LL ans=0;


LL s2i(string str)
{
	LL res=0;
	for(int i=0;i<str.size();i++) res=res*10+str[i]-'0';
	return res;
}

void check(string str)
{
	LL x=s2i(str);
	if(x>n) return;
	//A
	string strA;
	LL xx=x;
	while(xx)
	{
		strA.push_back(xx%A);
		xx/=A;
	}
	//check strA
	bool succ=1;
	for(int i=0;i<strA.size();i++)
	{
		if(strA[i]!=strA[strA.size()-i-1]) succ=0;
	}
	if(succ)
	{
		ans+=x;
	}
}

string i2s(LL x)
{
	string res;
	while(x) res.push_back(x%10+'0'),x/=10;
	reverse(res.begin(),res.end());
	return res;
}

void solve()
{
	cin>>A>>n;
	B=log10(n);
	
	for(LL i=1;i<=1000000;i++)
	{
		//i+i'
		string left=i2s(i);
		string right=left;
		reverse(right.begin(),right.end());
		check(left+right);
		//
		right=left;
		right.pop_back();
		reverse(right.begin(),right.end());
		check(left+right);
	}
	cout<<ans<<endl;
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
