#include <bits/stdc++.h>

using namespace std;
int n;
void generatePossibleBinOfSize2n(string s , int sum1 , int sum2)
{
    if (s.size() == 2*n)
    {
        if(sum1 == sum2)
        cout << s << endl;
        return;
    }
    //  TRY '0'       N
    generatePossibleBinOfSize2n(s + '0', sum1 , sum2);
    //  TRY '1' console.log(s);
    
    if(s.size()< n) generatePossibleBinOfSize2n(s + '1' , sum1+1 , sum2);
    else generatePossibleBinOfSize2n(s + '1' , sum1 , sum2+1);
    // this will generate the tree of 0s & 1s
}

void possibleBinOfSize2n(string s, int sum1, int sum2)
{
    if (s.size() == 2*n)
    {
        if(sum1 == sum2)
        {
            cout << s << endl;
        }
        return;
    }
    //  TRY '0'
    possibleBinOfSize2n(s + '0', sum1, sum2);
    //  TRY '1'
   if(s.size() < n) possibleBinOfSize2n(s + '1', sum1+1, sum2);
   else possibleBinOfSize2n(s + '1', sum1, sum2+1);
    // this will generate the tree of 0s & 1s
}
int main()
{
    // Given a number n, find all binary Sequences of length 2n such that the sum  
    // of the first n bits is the same as sum of last n bits
cin >> n;
generatePossibleBinOfSize2n("", 0 , 0);
// possibleBinOfSize2n("", 0, 0);

}