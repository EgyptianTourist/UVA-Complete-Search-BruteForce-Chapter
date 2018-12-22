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
#define N (int)5e5 + 9
bool check(int n)
{
    int sqroot = sqrt(n);
    return sq(sqroot)==n;
}
vi perfect_sqr;
void precalc()
{
    rep(i, 0, N)
    {
        if(check(i))
        {
            perfect_sqr.pb(i);
        }
   }
}
int main()
{
    Ios;
    //inn;outt;
    precalc();
    int t;
    for(scanf("%d", &t); t--;)
    {
        int num;
        scanf("%d", &num);
        int sum;
        bool flag = false;
        lp(i, perfect_sqr.size())
        {
            sum = perfect_sqr[i];
            if(flag)
                break;
            rep(j, i, perfect_sqr.size() - 1)
            {
                if(flag)
                    break;
                if(sum + perfect_sqr[j] <= num)
                {
                    int rem = num - (sum + perfect_sqr[j]);
                    int lw = lower_bound(all(perfect_sqr), rem) - perfect_sqr.begin();
                    if(lw < perfect_sqr.size() && perfect_sqr[j] + perfect_sqr[lw] + sum == num)
                    {
                        vi sol;
                        sol.pb((int)sqrt(sum));
                        sol.pb((int)sqrt(perfect_sqr[j]));
                        sol.pb((int)sqrt(perfect_sqr[lw]));
                        sort(all(sol));
                        printf("%d %d %d\n",sol[0], sol[1], sol[2]);
                        flag = true;
                        break;
                    }
                }
                else
                    break;
            }
        }
        if(!flag)
            puts("-1");
    }
    return 0;
}
