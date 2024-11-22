#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	string s;
	cin >> s;
	int len = s.size();
	if (len % 2!= 0) {
		cout << "No" << endl;
		return 0;
	}
	int mid = len / 2;
	bool flag = true;
	map<char, int> mm;
	for (int i = 0; i < mid; i++) {
		if (s[2 * i]!= s[2 * i + 1]) {
			flag = false;
			break;
		}
		mm[s[2 * i]]+=2;
		if (mm[s[2 * i]] > 2) {
			flag = false;
			break;
		}
	}
	cout << (flag? "Yes" : "No") << endl;
	return 0;
}
