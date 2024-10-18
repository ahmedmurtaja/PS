#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n = 8;
	vector<int> v = {1,2,3,4,5,6,7,8};
	vector<int> prefixSum(n+1);
	prefixSum[0] = 0;
	for(int i = 1; i <= v.size();++i)
	{
		// prefixSum[0] = 0;
		// prefixSum[1] = prefixSum[0] + 1 (V[0])
		// the sum of the n elements is the sum of previous elements + the sum of the current element
		prefixSum[i] = prefixSum[i-1] + v[i-1];
	}
	
	// the sum of first k element k from 0 to 8
	// 0 1 2 3  4  5  6  7  8
	// 0 1 3 6 10 15 21 28 36
	// Range querys the sum from 3r element to en of the arr



	for(int i = 0; i < prefixSum.size(); ++i )
	{
		cout << prefixSum[i] << " ";
	}
	cout << endl;


	cout << "Compute between n1 & n2" << endl;
	cout << "n1 : " ;
	int n1;
	cin >> n1;
	cout << "n2 : " ;
	int n2;
	cin >> n2;
	cout << endl;
	cout << "Sum between " << n1 << " & " << n2 << " is " << prefixSum[n2] - prefixSum[n1-1] << endl;
	return 0;
}
