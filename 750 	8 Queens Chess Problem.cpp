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
int t, row_pos, colomn_pos, LineNo;
int row[10];
bool check(int r, int c)
{
    lp(previous, c)
    {
        if(row[previous] == r || abs(row[previous] - r) == abs(previous - c))
            return false;
    }
    return true;
}
void solve(int c)
{
    //debug(c, row[row_pos]);
    if(c == 8 && row[colomn_pos] == row_pos)
    {
        printf("%2d      %d", ++LineNo, row[0] + 1);
        rep(queen, 1, 7)
        {
            printf(" %d", row[queen]+1);
        }
        puts("");
        //system("pause");
        return;
    }
    lp(r,8)
    if(check(r, c))
    {
        row[c] = r;
        solve(c+1);
        row[c] = -1;
    }
}

int main()
{
    Ios;
    //inn;outt;

    for(scanf("%d", &t); t--;)
    {
        scanf("%d %d", &row_pos, &colomn_pos);
        row_pos--, colomn_pos--;
        clr(row, -1);
        LineNo = 0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        solve(0);
        if(t)
            puts("");
    }
    return 0;
}
