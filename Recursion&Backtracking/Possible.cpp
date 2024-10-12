#include <bits/stdc++.h>
#define int long long

using namespace std;

int x = 100;
int n = 2;
int cnt =0;
string v;

int k;
void g(long long i , long long sum)
{

    if(i == 50)
    {
       if(sum == x)
       {
            cnt++;
       }
        return;
    }

    if((sum + pow(i,n)) <= x ){
        g(i+1 ,sum + pow(i,n));
    }
    g(i +1 , sum);


}

void possibleSol(string s)
{
    if (s.size() == k)
    {
        cout << s << endl;
        return;
    }

    for (int i = 0; i < v.size(); i++)
    {
        possibleSol(s + v[i]);
    }
    
    
}

int32_t main()
{
  cin >> v;
  cin >> k;
  possibleSol("");
//   cout << cnt <<endl;


}