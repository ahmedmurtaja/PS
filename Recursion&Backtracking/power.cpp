#include<bits/stdc++.h>
using namespace std;



// Recursive function for computing power
int powerRec(int x, int y) {
	if (y == 0) return 1;  // Base case: anything to power 0 is 1
	return x * powerRec(x, y - 1);  // Recursive multiplication
}

// Optimized power calculation using divide and conquer
int EnhancedPow(int x, int y) {
	if (y == 0) return 1;  // Base case
	if (y == 1) return x;  // Base case
	int ret = EnhancedPow(x, y / 2);
	if (y % 2 == 0) return ret * ret;  // If even power
	else return ret * ret * x;  // If odd power
}


int main(int argc, char const *argv[])
{
	cout << powerRec(2, 2) << endl;
	cout << EnhancedPow(3,2) << endl;
	return 0;
}
