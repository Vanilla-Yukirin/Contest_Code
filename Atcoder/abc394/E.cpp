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


#define N 110

int n;
string mp[N];
struct statu
{
	int x;
	string str;
};
void solve()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>mp[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			bool succ=0;
			set<pair<int,string>>si,sj,ni,nj;
			si.insert(make_pair(i,""));
			sj.insert(make_pair(j,""));
			for(int step=1;step<=n*2;step++)
			{
				//check
				for(auto iti=si.begin();iti!=si.end();iti++)
				{
					for(auto itj=sj.begin();itj!=sj.end();itj++)
					{
						if(iti->second==itj->second)
						{
							if(iti->first==itj->first)
							{
								succ=1;
								cout<<iti->second.size()*2<<" ";
								
								//output
								
//								cout<<endl;
//								DEBUG(i,1);
//								DEBUG(j,2);
//								DEBUG(iti->second,3);
							}
							else if(mp[iti->first][itj->first]!='-')
							{
								succ=1;
								cout<<iti->second.size()*2+1<<" ";
								
//								cout<<endl;
//								DEBUG(i,1);
//								DEBUG(j,2);
//								DEBUG(iti->second,3);
							}
						}
					}
				}
				if(succ) break;
				//go
				ni.clear();
				for(auto it=si.begin();it!=si.end();it++)
				{
					for(int y=0;y<n;y++)
					{
						if(mp[it->first][y]!='-')
						{
							ni.insert(make_pair(y,it->second+mp[it->first][y]));
						}
					}
				}
				nj.clear();
				for(auto it=sj.begin();it!=sj.end();it++)
				{
					for(int y=0;y<n;y++)
					{
						if(mp[y][it->first]!='-')
						{
							nj.insert(make_pair(y,it->second+mp[y][it->first]));
						}
					}
				}
				//merge
				si.clear();
				sj.clear();
				for(auto iti=ni.begin();iti!=ni.end();iti++)
				{
					for(auto itj=nj.begin();itj!=nj.end();itj++)
					{
						if(iti->second==itj->second)
						{
//							debug
//							cout<<"insert "<<iti->second<<endl;
							si.insert(*iti);
							sj.insert(*itj);
						}
					}
				}
			}
			
			if(succ==0)
			{
				cout<<-1<<" ";
			}
		}
		cout<<endl;
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
