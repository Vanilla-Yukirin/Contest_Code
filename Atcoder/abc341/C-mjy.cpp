#include <iostream>
#include <string>
using namespace std;
int H, W, N;
string s;
char a[1000005][500] = {0};
bool test(char a[1000005][500], string s, int i, int j) 
{
	a[i][j] = '#';
	char m = a[i][j];
	for (int p = 0; p < s.length(); p++) 
	{
		if (s[p] == 'U') 
		{
			i--;
		}
		else if (s[p] == 'D')
		{
			i++;
		}
		else if (s[p] == 'L') 
		{
			j--;
		}
		else if (s[p] == 'R')
		{
			j++;
		}
		m = a[i][j];
		if (a[i][j] == '#') 
		{
			return false;
		}
	}
	return true;
}
int main() {
	cin >> H >> W >> N;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < H; i++) 
	{
		for (int j = 0; j < W; j++)
		{
			cin >> a[i][j];
		}
	}
	
	for (int i = 0; i < H; i++) 
	{
		for (int j = 0; j < W; j++) 
		{
			if (a[i][j] == '.') 
			{
				if (test(a, s, i, j)) 
				{
					cnt++;
				}
				a[i][j] = '.';
			}
		}
	}
	cout << cnt;
	return 0;
}
