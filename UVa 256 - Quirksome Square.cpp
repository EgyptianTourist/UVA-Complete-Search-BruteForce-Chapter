/*
name:       Dark_Cipher
PlatForm:   CodeForces/SPOJ...etc
LANG:       C++
DIV:        Training
TIME:       *
RATE:       *
*/

/*
Time Consumed:*
Problem Topics: *
*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define rep2(i, a, b) for (ll i = a; i <= b; i++)
#define lp(i, n) for (int i = 0; i < n; i++)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define clr(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define ull unsigned long long
#define ll long long
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) ( (i) & (-i) )
#define sq(x) ((x) * (x))
#define INF INT_MAX
#define mp make_pair
#define inn freopen("in.in","r",stdin)
#define outt freopen("ride.out","w",stdout)
#define Ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define all(v) ((v).begin()), ((v).end())

#ifndef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1)
{
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1<<" | ";
    __f(comma+1, args...);
}
#else
#define debug(...)
#endif

#define N (int)5e5 + 5
/*-----------------------*/
template<typename T>
T _f_pow(T a, T b)
{
    T res = 1;
    while(b)
    {
        res *= (b&1? a : 1);
        a *= a;
        b >>= 1;
    }
    return res;
}
map<int, vector<int>> seq;
pair<int, int> _try(int x)
{
    if(x==100000000)
        return {0,0};
    vector<int> digits(8, 0);
    int tmp = x;
    int ii = 7, cnt = 0;
    while(tmp)
    {
        cnt++;
        digits[ii--] = (tmp%10);
        tmp/=10;
    }
    int n1 = 0, n2 = 0;
    int md = ii + floor((7 - ii)/2.0);
    if(ii==-1)
        ii = 0;
    rep2(i,ii,md)
        n1 = n1 * 10 + digits[i],ii=i;
    ii++;
    rep2(i,ii,7)
        n2 = n2*10+digits[i];
    //debug(n1, n2,x);
    //system("pause");
    if(cnt!=2 && cnt!=4 && cnt!=6 && cnt != 8)
        cnt++;
    return {x, cnt *(_f_pow(n1+n2,2)==x)};
}
void solve()
{
    seq[2].push_back(0);
    seq[4].push_back(0);
    seq[4].push_back(1);
    seq[6].push_back(0);
    seq[6].push_back(1);
    seq[8].push_back(0);
    seq[8].push_back(1);
    rep2(i,0,10000)
    {
        pair<int, int> sol = _try(i*i);
        //if((int)log10(i*i)+1==8)debug(i*i, sol.second);
        if(sol.second)
        {
            //debug(sol.second);
            seq[sol.second].push_back(sol.first);
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
        Ios;
        //inn;//outt;
    #endif // ONLINE_JUDGE
    solve();
    int digits;
    while(cin >> digits)
    {
        for( auto val : seq[digits])
            cout << setw(digits) << setfill('0') << val << endl << flush;
    }
    return 0;
}
