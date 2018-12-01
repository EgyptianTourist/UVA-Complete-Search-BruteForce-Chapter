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

#define lp(i, n) for (int i = 0; i < n; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rep2(i, a, b) for (int i = a; i <= b; i++)
#define clr(ar, val) memset(ar, val, sizeof(ar))
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
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
#define inn freopen("in.in","r",stdin)
#define outt freopen("out.out","w",stdout)

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

#define N (int)1e5 + 5
template<class T>
T _f_pow(T a, T b)
{
    T res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

bool _try(int n)
{
    //debug(n, "Done");
    char digits[10];
    sprintf(digits, "%d", n);//Convert int number to it's string shape or value
    vector<int> vis(10,0);
    int idx = 0;
    int vl = digits[0] - '0';
    lp(i,strlen(digits))
    {
        if((idx = idx + vl % strlen(digits)) >= strlen(digits))
            idx = idx - strlen(digits);
        if(vis[vl] || vl==0)
            return 0;
        vis[vl] = 1;
        vl = digits[idx] - '0';
    }
    if(vl == digits[0]-'0')
        return 1;
    return 0;
}
int num;
vector<int> _run;
int main()
{
    Ios;
    //inn;//outt;
    int cs = 1;
    rep2(i,10,9999999)
        {
            if(_try(i))
            {
                _run.pb(i);
                //printf("%d\n", i);
                //system("pause");
            }
        }
    while(cin >> num,num)
    {
        int lw = lower_bound(all(_run),num) - _run.begin();
        printf("Case %d: %d\n", cs++, _run[lw]);
    }
    return 0;
}
