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
string l,r;
int n;
int dfs(int x)
{
	
}
void solve()
{
	cin>>l>>r;
	n=l.size();
	int same=0;
	for(int i=0;i<n;i++)
	{
		if(l[i]==r[i])
		{
			same++;
		}
		else
		{
			break;
		}
	}
	int more=0;
	if(same!=n)
	{
		//first diff is same
		for(int i=same;i<n;i++)
		{
			if(r[i]-l[i]==1)
			{
				//choose l or r
				int more_l=0,more_r=0;
				for(int j=same+1;j<n;j++)
				{
					if(l[j]=='9') more_l++;
					else break;
				}
				for(int j=same+1;j<n;j++)
				{
					if(r[j]=='0') more_r++;
					else break;
				}
				more+=min(more_l,more_r)+1;
				break;
			}
			else
			{
				break;
			}
		}
	}
	cout<<same*2+more<<endl;
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
