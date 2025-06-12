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

int calc_right(string ans,string now)
{
	int cnt=0;
	for(int i=0;i<3;i++)
	{
		if(ans.find(now[i])!=string::npos) cnt++;
	}
	return cnt;
}

int calc_pos_right(string ans,string now)
{
	int cnt=0;
	for(int i=0;i<3;i++)
	{
		if(ans[i]==now[i]) cnt++;
	}
	return cnt;
}


void solve()
{
	string str="   ";
	for(str[0]='a';str[0]<='z';str[0]++)
	{
		for(str[1]='a';str[1]<='z';str[1]++)
		{
			for(str[2]='a';str[2]<='z';str[2]++)
			{
				if(calc_right(str,"abc")==1&&calc_pos_right(str,"abc")==1)
				{
					if(calc_right(str,"aef")==1&&calc_pos_right(str,"aef")==0)
					{
						if(calc_right(str,"cka")==2&&calc_pos_right(str,"cka")==0)
						{
							if(calc_right(str,"deb")==0)
							{
								if(calc_right(str,"bdk")==1&&calc_pos_right(str,"bdk")==0)
								{
									cout<<str<<endl;
								}
							}
						}
					}
				}
				
				
			}
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
