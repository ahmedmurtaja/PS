#include<bits/stdc++.h>
using namespace std;

string g;
string s;

// Function to reverse and print a string
void rev(string s) {
	if (s.size() == 1) {
		cout << s[0] << endl;
		return;
	}
	cout << s.back();  // Print the last character
	rev(s.substr(0, s.size() - 1));  // Recur with the substring
}

// Recursive string reversal
string revstr(string s) {
	if (s.length() == 1) return s;  // Base case
	return s.back() + revstr(s.substr(0, s.length() - 1));  // Recur
}

// Recursive function to print string in reverse
void printReverse(int idx) {
	if (idx >= s.size()) return;
	printReverse(idx + 1);  // Recurse forward
	cout << s[idx];  // Print from the call stack as it unwinds
}

int main() {
	cin >> s;
	rev(s);
	cout << endl;
	printReverse(0);
	cout << endl;

	return 0;
}
