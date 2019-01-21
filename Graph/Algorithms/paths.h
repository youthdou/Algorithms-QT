#ifndef PATHS_H
#define PATHS_H


#include <QVector>

class Paths
{
public:
    Paths();
    virtual bool hasPathTo(int v) = 0;
    virtual QVector<int> pathTo(int v) = 0;
};

#endif // PATHS_H
