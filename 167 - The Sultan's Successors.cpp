/*
name:       Egyptian Tourist
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
//----------------------------------//

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

//-------------------------------------------------------//
#define rep(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define repr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define lp(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define lpr(i,n) for (int i = (n) - 1; ~i; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
//-------------------------------------------------------------------------------------//

#define clr(ar, val) memset(ar, val, sizeof(ar))
//----------------------------------------------//

#define inn freopen("in.in","r",stdin)
#define outt freopen("out.out","w",stdout)
#define PI 3.1415926535897932385
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define pob pop_back
#define bit(n) (1<<(n))
#define Last(i) ( (i) & (-i) )
#define all(v) ((v).begin()), ((v).end())
#define sq(x) ((x) * (x))
#define INF INT_MAX
#define Ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

//-------------------------------------------------------------//
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
//------------------------------------------------------------//

template<class T>
T _f_pow(T a, T b)
{
    T res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
#define N (int)1e5 + 5
int t;
int grid[9][9];
int vis[9][9];
bool check(int r, int c)
{

    lp(i, c)
    {
        if(vis[r][i])
            return false;
    }
    for(int i = r, j = c; ~i && ~j;i--, j--)
    {
        if(vis[i][j])
            return false;
    }
    for(int i = r, j = c; i < 8 && ~j;i++, j--)
    {
        if(vis[i][j])
            return false;
    }
    return true;
}
int Accumulate()
{
    int ret = 0;
    lp(i, 8)
    {
        lp(j, 8)
        {
            if(vis[i][j])
                ret += grid[i][j];
        }
    }
    return ret;
}
int solve(int c)
{
    if(c >= 8)
        return Accumulate();
    int ret = 0;
    lp(i, 8)
    {
        if(check(i,c))
        {
            vis[i][c] = 1;
            ret = max(ret,solve(c+1));
            vis[i][c] = 0;
        }
    }
    return ret;
}
int main()
{
    Ios;
    //inn;outt;
    scanf("%d", &t);
    while(t--)
    {
        lp(i, 8)
        {
            lp(j, 8)
            {
                scanf("%d", &grid[i][j]);
            }
        }
        cout<<setw(5)<<setiosflags(ios::right)<<solve(0)<<endl;
    }
    return 0;
}
