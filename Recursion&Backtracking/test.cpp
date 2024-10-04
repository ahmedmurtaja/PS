#include<bits/stdc++.h>
using namespace std;

string g;
string s;


// Recursive function for computing power
int powerB(int x, int y) {
	if (y == 0) return 1;  // Base case: anything to power 0 is 1
	return x * powerB(x, y - 1);  // Recursive multiplication
}

// Optimized power calculation using divide and conquer
int Enhancedpow(int x, int y) {
	if (y == 0) return 1;  // Base case
	if (y == 1) return x;  // Base case
	int ret = Enhancedpow(x, y / 2);
	if (y % 2 == 0) return ret * ret;  // If even power
	else return ret * ret * x;  // If odd power
}

// Array for prefix sum calculation
int ss[8] = {1, 2, 3, 4, 5, 6, 7, 8};

// Recursive prefix sum calculation
int prefix(int curr) {
	if (curr == 0) return ss[0];  // Base case
	return ss[curr] += prefix(curr - 1);  // Recur and accumulate
}



struct Node {
	Node* next;
	int text;
};

int n, m;
string path;
char grid[100][100];

// Backtracking function to find paths in grid (Right and Down)
void backtrack(int row, int col) {
	if (row == n - 1 && col == m - 1) {
		cout << path << endl;  // Print path when destination is reached
		return;
	}
	if (col < m - 1 && grid[row][col + 1] != '#') {
		path.push_back('R');  // Try moving Right
		backtrack(row, col + 1);  // Recurse
		path.pop_back();  // Undo move
	}
	if (row < n - 1 && grid[row + 1][col] != '#') {
		path.push_back('D');  // Try moving Down
		backtrack(row + 1, col);  // Recurse
		path.pop_back();  // Undo move
	}
}

// Alternative backtracking function that passes the path as an argument
void backtrack2(int row, int col, string path2) {
	if (row == n - 1 && col == m - 1) {
		cout << path2 << endl;  // Print path when destination is reached
		return;
	}
	if (col < m - 1 && grid[row][col + 1] != '#') {
		backtrack2(row, col + 1, path2 + 'R');  // Try Right
	}
	if (row < n - 1 && grid[row + 1][col] != '#') {
		backtrack2(row + 1, col, path2 + 'D');  // Try Down
	}
}

void backtrack3(int row, int col, string path3) {
	if (grid[row][col] == 'C') {
		cout << path3 << endl;  // Print path when item is collected
		return;
	}
	if (col < m - 1 && grid[row][col + 1] != '#') {
		backtrack3(row, col + 1, path3 + 'R');  // Try Right
	}
	if (row < n - 1 && grid[row + 1][col] != '#') {
		backtrack3(row + 1, col, path3 + 'D');  // Try Down
	}
}

int N = 3;
vector<int> subset;

// Recursive function to generate all subsets
void generateSubset(int idx) {
	if (idx == N) {
		if (subset.empty()) cout << "PHI";  // Empty set
		for (int elem : subset) {
			cout << "|" << elem << " ";  // Print current subset
		}
		cout << endl;
		return;
	}
	subset.push_back(idx);  // Include current element
	generateSubset(idx + 1);  // Recur
	subset.pop_back();  // Exclude current element
	generateSubset(idx + 1);  // Recur
}

// Function to check if two floating-point numbers are equal
bool isFEqual(double n1, double n2) {
	return abs(n1 - n2) < 1e-9;
}

const long long MOD = 1e9 + 7;

// Function to calculate factorial with modulo
void factorial(int n) {
	long long x = 1;
	for (int i = 2; i <= n; i++) {
		x = (x * i) % MOD;
	}
	cout << x << endl;
}

int main() {
	generateSubset(0);  // Call to generate subsets
	return 0;
}
