#ifndef GRAPH_H
#define GRAPH_H

#include <QString>
#include <QVector>

class Graph;

class GraphUtility
{
public:
    static int degree(const Graph &G, int v);
    static int maxDegree(const Graph &G);
    static double avgDegree(const Graph &G);
    static int numberOfSelfLoops(const Graph &G);
};

class Graph
{
public:
    Graph();
    Graph(const QString &strFileName);
    QString toString() const;
    int V() const;
    int E() const;
    const QVector<int> &adj(int v) const;
    void addEdge(int v, int w);

private:
    void parseFile(const QString &strFileName);

private:
    int m_iV;
    int m_iE;
    QVector<QVector<int>> m_vecAdj;
};

#endif // GRAPH_H
