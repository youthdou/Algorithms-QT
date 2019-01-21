#ifndef DEPTHFIRSTSEARCH_H
#define DEPTHFIRSTSEARCH_H

class Graph;

#include <QVector>

#include "paths.h"

class DepthFirstSearch : public Paths
{
public:
    DepthFirstSearch(const Graph &G, int s);
    bool marked(int w);
    int count();
    virtual bool hasPathTo(int v) Q_DECL_OVERRIDE;
    virtual QVector<int> pathTo(int v) Q_DECL_OVERRIDE;

private:
    void dfs(const Graph &G, int v);

private:
    const Graph &m_G;
    int m_iS;
    QVector<bool> m_vecMarked;
    QVector<int> m_vecEdgeTo;
    int m_iCount;
};

#endif // DEPTHFIRSTSEARCH_H
