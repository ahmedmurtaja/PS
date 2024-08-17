#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// 23 out of 5
int a[5];

bool isPossible(int idx , int value)
{

if(idx == 5)
{
  if(value == 23)
  {
    return true;
  }
 return false;
}

return 
  isPossible(idx+1 , value + a[idx]) ||
  isPossible(idx+1 , value - a[idx]) ||
  isPossible(idx+1 , value * a[idx]);

}

int main(){

  freopen("input.txt" , "r" , stdin);
  for(int i=0; i<5; i++)
  {
    cin >> a[i]; 
  }
sort(a , a+ 5);
do
{
if(isPossible(1,a[0])) {
  cout << "Possible" << endl;
  break;
}

  // generate all possible arrangement of numbers

} while (next_permutation(a, a+5));


return 0;
}