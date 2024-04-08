#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int n,m,k,one=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		string str;cin>>str;
		for(int j=0;j<str.size();j++)
		{
			if(str[j]=='1') one++;
		}
	}
	cout<<one-2*k<<" "<<3*k-one<<endl;
	return 0;
}
