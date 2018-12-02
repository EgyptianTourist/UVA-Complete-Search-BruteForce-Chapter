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

#define rep(i,a,b) for (int i = (a), _b = (b); i < _b; i++)
#define repr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define lp(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define lpr(i,n) for (int i = (n) - 1; ~i; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
//-------------------------------------------------------------------------------------//

#define clr(ar, val) memset(ar, val, sizeof(ar))
//----------------------------------------------//

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
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
char s[100];
int  w[100], n, c;
bool solve()
{
    rep(i, 0, n)
    {
        rep(j, i+1, n)
        {

            int ci = (c/w[i])%n;
            int cj = (c/w[j])%n;
            //debug(ci, cj);
            if(ci==cj)
            {
                c = min(((c/w[i]+1) * w[i]), ((c/w[j]+1) * w[j]));
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    Ios;
    //inn;outt;
    while(gets(s))
    {
        n = 0;

        lp(i,strlen(s))
        {
            char tmp[100];
            if(isalpha(s[i]))
            {
                sscanf(s+i,"%s", tmp);
                //printf("%s\n", tmp);
                w[n] = 0;
                lp(j, strlen(tmp))
                {
                    w[n] = (w[n] << 5) +(tmp[j]-'a' + 1);
                }
                //debug(w[n]);
                n++;
                i+=strlen(tmp);
            }
        }
        c = INF;
        lp(i, n)
        {
            c = min(c, w[i]);
        }
        //debug(c, n);
        /*
        Since all such conflicts must be resolved, it is advantageous to choose the largest candidate from
        among the conflicts as the next C to test
        */
        while(solve());
        printf("%s\n%d\n\n", s, c);
    }
    return 0;
}
