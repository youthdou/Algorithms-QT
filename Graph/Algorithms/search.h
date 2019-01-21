#ifndef SEARCH_H
#define SEARCH_H

class Graph;

class Search
{
public:
    Search(const Graph &G, int S);
    bool marked(int v);
    int count();

private:
    const Graph &m_G;
    int m_iS;
};

#endif // SEARCH_H
