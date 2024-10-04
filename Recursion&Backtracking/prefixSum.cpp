#include<bits/stdc++.h>
using namespace std;

string g;
string s;

// Array for prefix sum calculation
int ss[8] = {1, 2, 3, 4, 5, 6, 7, 8};

// Recursive prefix sum calculation
int prefix(int curr) {
	if (curr == 0) return ss[0];  // Base case
	return ss[curr] += prefix(curr - 1);  // Recur and accumulate
}

int main(int argc, char const *argv[])
{
	prefix(7);
	for (int i = 0; i < 8; i++)
	{
		cout << ss[i] << endl;
	}
	
	return 0;
}
