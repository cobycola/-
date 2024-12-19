/*某国为促进城市间经济交流，决定对货物运输提供补贴。共有 n 个编号为 1 到 n 的城市，通过道路网络连接，网络中的道路仅允许从某个城市单向通行到另一个城市，不能反向通行。
网络中的道路都有各自的运输成本和政府补贴，道路的权值计算方式为：运输成本 - 政府补贴。权值为正表示扣除了政府补贴后运输货物仍需支付的费用；权值为负则表示政府的补贴超过
了支出的运输成本，实际表现为运输过程中还能赚取一定的收益。

然而，在评估从城市 1 到城市 n 的所有可能路径中综合政府补贴后的最低运输成本时，存在一种情况：图中可能出现负权回路。负权回路是指一系列道路的总权值为负，这样的回路使得
通过反复经过回路中的道路，理论上可以无限地减少总成本或无限地增加总收益。为了避免货物运输商采用负权回路这种情况无限的赚取政府补贴，算法还需检测这种特殊情况。

请找出从城市 1 到城市 n 的所有可能路径中，综合政府补贴后的最低运输成本。同时能够检测并适当处理负权回路的存在。
城市 1 到城市 n 之间可能会出现没有路径的情况*/

/*Bellman_ford 判断负权回路 松弛n次 最后一次如果还发生改变即为负权回路*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1001, M = 10001;
int he[N], to[M], w[M], ne[M], idx;
int n, m, s, t, v;
int md[N];
void addE(int a, int b, int c)
{
    to[idx] = b;
    w[idx] = c;
    ne[idx] = he[a];
    he[a] = idx++;
}
bool BF()
{
    memset(md, 0x3f3f3f3f, sizeof md);
    md[1] = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            for (int j = 1; j <= n; j++)
            {
                if (md[j] == 0x3f3f3f3f) continue;
                for (int k = he[j]; k != -1; k = ne[k])
                {
                    if (md[to[k]] > md[j] + w[k]) return false;
                }
            }
        }
        for (int j = 1; j <= n; j++)
        {
            if (md[j] == 0x3f3f3f3f) continue;
            for (int k = he[j]; k != -1; k = ne[k])
            {
                md[to[k]] = min(md[to[k]], md[j] + w[k]);
            }
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(to, 0, sizeof to);
    memset(ne, 0, sizeof ne);
    memset(he, -1, sizeof he);
    memset(w, 0, sizeof w);
    idx = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> t >> v;
        addE(s, t, v);
    }
    if (!BF()) cout << "circle";
    else if (md[n] >= 101) cout << "unconnected";
    else cout << md[n];
    return 0;
}