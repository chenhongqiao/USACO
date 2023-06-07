// Favorite Colors
#include <iostream>
#include <vector>
#include <queue>
struct IO
{
#define MAXSIZE (1 << 20)
#define isdigit(x) (x >= '0' && x <= '9')
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;
#if DEBUG
#else
    IO() : p1(buf), p2(buf), pp(pbuf)
    {
    }
    ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
#endif
    inline char gc()
    {
#if DEBUG // 调试，可显示字符
        return getchar();
#endif
        if (p1 == p2)
            p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin);
        return p1 == p2 ? ' ' : *p1++;
    }
    inline bool blank(char ch)
    {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    template <class T>
    inline void read(T &x)
    {
        double tmp = 1;
        bool sign = 0;
        x = 0;
        char ch = gc();
        for (; !isdigit(ch); ch = gc())
            if (ch == '-')
                sign = 1;
        for (; isdigit(ch); ch = gc())
            x = x * 10 + (ch - '0');
        if (ch == '.')
            for (ch = gc(); isdigit(ch); ch = gc())
                tmp /= 10.0, x += tmp * (ch - '0');
        if (sign)
            x = -x;
    }
    inline void read(char *s)
    {
        char ch = gc();
        for (; blank(ch); ch = gc())
            ;
        for (; !blank(ch); ch = gc())
            *s++ = ch;
        *s = 0;
    }
    inline void read(char &c)
    {
        for (c = gc(); blank(c); c = gc())
            ;
    }
    inline void push(const char &c)
    {
#if DEBUG // 调试，可显示字符
        putchar(c);
#else
        if (pp - pbuf == MAXSIZE)
            fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
        *pp++ = c;
#endif
    }
    template <class T>
    inline void write(T x)
    {
        if (x < 0)
            x = -x, push('-'); // 负数输出
        static T sta[35];
        T top = 0;
        do
        {
            sta[top++] = x % 10, x /= 10;
        } while (x);
        while (top)
            push(sta[--top] + '0');
    }
    template <class T>
    inline void write(T x, char lastChar)
    {
        write(x), push(lastChar);
    }
} io;
using namespace std;
int n, m;
vector<int> g[200005];
int h[200005];
int f[200005];
int ans[200005];
queue<int> q;
int find(int v)
{
    if (f[v] != v)
    {
        f[v] = find(f[v]);
    }
    return f[v];
}
int unite(int a, int b)
{
    int ra = find(a);
    int rb = find(b);
    if (h[ra] < h[rb])
    {
        swap(ra, rb);
    }
    f[rb] = ra;
    g[ra].insert(g[ra].end(), g[rb].begin(), g[rb].end());
    h[ra] = max(h[ra], h[rb] + 1);
    vector<int>().swap(g[rb]);
    return ra;
}
int main()
{
    io.read(n);
    io.read(m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        io.read(a);
        io.read(b);
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
        if (g[i].size() > 1)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int v = q.front();
        for (int i = 0; i < (int)g[v].size() - 1; i++)
        {
            if (find(g[v][i]) != find(g[v][i + 1]))
            {
                int r = unite(g[v][i], g[v][i + 1]);
                if (g[r].size() > 1 && q.back() != r)
                {
                    q.push(r);
                }
            }
        }
        q.pop();
    }
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        int id = find(i);
        if (!ans[id])
        {
            ans[id] = cnt++;
        }
        io.write(ans[id], '\n');
    }
    return 0;
}