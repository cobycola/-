/*ĳ��Ϊ�ٽ����м侭�ý����������Ի��������ṩ���������� n �����Ϊ 1 �� n �ĳ��У�ͨ����·�������ӣ������еĵ�·�������ĳ�����е���ͨ�е���һ�����У����ܷ���ͨ�С�
�����еĵ�·���и��Ե�����ɱ���������������·��Ȩֵ���㷽ʽΪ������ɱ� - ����������ȨֵΪ����ʾ�۳������������������������֧���ķ��ã�ȨֵΪ�����ʾ�����Ĳ�������
��֧��������ɱ���ʵ�ʱ���Ϊ��������л���׬ȡһ�������档

Ȼ�����������ӳ��� 1 ������ n �����п���·�����ۺ�������������������ɱ�ʱ������һ�������ͼ�п��ܳ��ָ�Ȩ��·����Ȩ��·��ָһϵ�е�·����ȨֵΪ���������Ļ�·ʹ��
ͨ������������·�еĵ�·�������Ͽ������޵ؼ����ܳɱ������޵����������档Ϊ�˱�����������̲��ø�Ȩ��·����������޵�׬ȡ�����������㷨�������������������

���ҳ��ӳ��� 1 ������ n �����п���·���У��ۺ�������������������ɱ���ͬʱ�ܹ���Ⲣ�ʵ�����Ȩ��·�Ĵ��ڡ�
���� 1 ������ n ֮����ܻ����û��·�������*/

/*Bellman_ford �жϸ�Ȩ��· �ɳ�n�� ���һ������������ı伴Ϊ��Ȩ��·*/

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