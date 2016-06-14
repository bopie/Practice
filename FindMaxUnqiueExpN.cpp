#include <iostream>
#include <string>
#include <set>
using namespace std;

bool isUnique(int);
bool isUnique(int, long long);
int findMaxUniqueExpN(int, int);
unsigned long long pow(int, int);

int main() {
	int m, n;
	char c;
	
	while (cin >> m >> c >> n) {
		int res = findMaxUniqueExpN(m, n);
		if (res != -1) {
			cout << res << endl;
		} else {
			cout << '-' << endl;
		}
	}
	
	return 0;
}

int findMaxUniqueExpN(int m, int n) {
	while (--m > 0) {
		if (!isUnique(m)) {
			continue;
		}
		long double res = pow(m, n);
		if (!isUnique(m, res)) {
			continue;
		}
		return m;
	}
	
	return -1;
}

unsigned long long pow(int m, int n) {
	unsigned long long res = m;
	while (--n > 0) {
		res *= m;
	}
	return res;
}

bool isUnique(int n1, long long n2) {
	string s1 = to_string(n1);
	string s2 = to_string(n2);
	
	set<char> digits;
	for (auto c : s1) {
		digits.insert(c);
	}
	for (auto c : s2) {
		if (digits.find(c) != digits.end()) {
			return false;
		}
	}
	
	return true;
}

bool isUnique(int n) {
	string s = to_string(n);
	
	for (int i = 0; i < s.length(); i++) {
		for (int j = i + 1; j < s.length(); j++) {
			if (s[i] == s[j]) {
				return false;
			}
		}
	}
	
	return true;
}
