#include "search.h"
#include "graph.h"

Search::Search(const Graph &G, int S):
    m_G(G),
    m_iS(S)
{

}

bool Search::marked(int v)
{
    return m_G.adj(m_iS).indexOf(v) != -1;
}

int Search::count()
{
    return m_G.adj(m_iS).count();
}


#ifdef  TEST_SEARCH

#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        cout << "Usage: file vertex" << endl;
        return 0;
    }
    Graph G = Graph(QString(argv[1]));
    int iS = QString(argv[2]).toInt();
    Search S(G, iS);
    cout << iS << " ";
    for(int v = 0; v < G.V(); ++v)
    {
        if(S.marked(v))
        {
            cout << v << " ";
        }
    }
    cout << endl;

    if(S.count() != G.V())
    {
        cout << "NOT ";
    }
    cout << "connected" << endl;
    return 0;
}
#endif
