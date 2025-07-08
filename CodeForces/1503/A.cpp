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
int n;
string str,A,B;
int a,b;
void solve()
{
	cin>>n>>str;
	a=b=0;
	A.clear();
	B.clear();
	if(str[0]!='1'||str[n-1]!='1')
	{
		cout<<"NO"<<endl;
		return;
	}
	int cnt1=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='1') cnt1++;
	}
	if(cnt1&1)
	{
		cout<<"NO"<<endl;
		return;
	}
	int cnt11=0,cnt00=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='1')
		{
			cnt11++;
			if(cnt11<=cnt1/2)
			{
				A.push_back('(');
				B.push_back('(');
				a++;
				b++;
			}
			else
			{
				A.push_back(')');
				B.push_back(')');
				a--;
				b--;
			}
		}
		else
		{
			cnt00++;
			if(cnt00&1)
			{
				A.push_back('(');
				B.push_back(')');
				a++;
				b--;
			}
			else
			{
				A.push_back(')');
				B.push_back('(');
				a--;
				b++;
			}
		}
	}
	cout<<"YES"<<endl<<A<<endl<<B<<endl;
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
