#include "depthfirstsearch.h"

#include "graph.h"

DepthFirstSearch::DepthFirstSearch(const Graph &G, int s) :
    m_G(G),
    m_iS(s),
    m_iCount(0)
{
    m_vecMarked = QVector<bool>(m_G.V(), false);
    m_vecEdgeTo = QVector<int>(m_G.V(), -1);
    dfs(G, s);
}

bool DepthFirstSearch::marked(int w)
{
    return m_vecMarked[w];
}

int DepthFirstSearch::count()
{
    return m_iCount;
}

bool DepthFirstSearch::hasPathTo(int v)
{
    return m_vecMarked[v];
}

QVector<int> DepthFirstSearch::pathTo(int v)
{
    QVector<int> vecPath;
    if(!hasPathTo(v))
    {
        return vecPath;
    }

    for(int x = v; x != m_iS; x = m_vecEdgeTo[x])
    {
        vecPath.push_front(x);
    }
    vecPath.push_front(m_iS);
    return vecPath;
}

void DepthFirstSearch::dfs(const Graph &G, int v)
{
    m_vecMarked[v] = true;
    m_iCount++;
    for(int w : G.adj(v))
    {
        if(!m_vecMarked[w])
        {
            m_vecEdgeTo[w] = v;
            dfs(G, w);
        }
    }
}
