#include<bits/stdc++.h>
using namespace std;


int threeNPlusOneSeries(int n, int cnt = 0) {
	if (n == 1) return cnt;  // Base case: if n is 1, return the count
	if (n % 2 == 0) {
		cout << n << " Even"<<endl;
		return threeNPlusOneSeries(n / 2, cnt + 1);  // Even
		}
	cout << n << " Odd"<<endl;
	return threeNPlusOneSeries(3 * n + 1, cnt + 1);  // Odd

	// 24 --even--> 12 --even--> 6 --even--> 3 --odd--> 10 --even--> 5 --odd-->16 --even-->8--even-->4 --even-->2 --even-->1

}


int main() {
	cout << threeNPlusOneSeries(24, 0);
	return 0;
}