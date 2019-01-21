#include "paths.h"
#include "graph.h"
#include "depthfirstsearch.h"


Paths::Paths()
{

}

#ifdef TEST_PATHS

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        cout << "Usage: file s" << endl;
        return 0;
    }

    Graph G = Graph(QString(argv[1]));
    int iS = QString(argv[2]).toInt();
    Paths &S = DepthFirstSearch(G, iS);
    for(int v = 0; v < G.V(); v++)
    {
        cout << iS << " to " << v << ": ";
        if(S.hasPathTo(v))
        {
            for(int x : S.pathTo(v))
            {
                if(x == iS)
                {
                    cout << x;
                }
                else
                {
                    cout << " - " << x;
                }
            }
        }
        cout << endl;
    }
    return 0;
}



#endif
