#include "graph.h"
#include <QFile>
#include <QStringList>

Graph::Graph() :
    m_iE(0),
    m_iV(0)
{

}

Graph::Graph(const QString &strFileName) :
    Graph()

{
    parseFile(strFileName);
}

QString Graph::toString() const
{
    QString strGraph = QString("%1 vertices, %2 edges\n").arg(m_iV).arg(m_iE);
    for(int v = 0; v < m_iV; ++v)
    {
        strGraph += QString::number(v) + ": ";
        foreach(auto w, m_vecAdj[v])
        {
            strGraph += QString::number(w) + " ";
        }
        strGraph += "\n";
    }
    return strGraph;
}

int Graph::V() const
{
    return m_iV;
}

int Graph::E() const
{
    return m_iE;
}

const QVector<int> &Graph::adj(int v) const
{
    return m_vecAdj[v];
}

void Graph::addEdge(int v, int w)
{
    m_vecAdj[v].append(w);
    m_vecAdj[w].append(v);
}

void Graph::parseFile(const QString &strFileName)
{
    QFile f(strFileName);
    if(!f.open(QIODevice::ReadOnly))
    {
        return;
    }

    m_iV = QString(f.readLine()).toInt();
    m_iE = QString(f.readLine()).toInt();

    m_vecAdj.resize(m_iV);

    while(!f.atEnd())
    {
        QStringList l = QString(f.readLine()).split(" ", QString::SkipEmptyParts);
        int v = l.at(0).toInt();
        for(int i = 1; i < l.size(); ++i)
        {
            auto w = l.at(i).toInt();
            addEdge(v, w);
        }
    }

}

#ifdef TEST_GRAPH
#include <QDebug>
#include <iostream>
using namespace std;

int main()
{
    Graph g("tinyG.txt");
    cout << g.toString().toStdString() << endl;
    return 0;
}
#endif

int GraphUtility::degree(const Graph &G, int v)
{
    return G.adj(v).size();
}

int GraphUtility::maxDegree(const Graph &G)
{
    int max = 0;
    for(int v = 0; v < G.V(); ++v)
    {
        qMax(max, degree(G, v));
    }
    return max;
}

double GraphUtility::avgDegree(const Graph &G)
{
    return 2 * G.E() / G.V();
}

int GraphUtility::numberOfSelfLoops(const Graph &G)
{
    int count = 0;
    for(int v = 0; v < G.V(); ++v)
    {
        for(int w : G.adj(v))
        {
            if(v == w)
            {
                count++;
            }
        }
    }
    return count / 2;
}
