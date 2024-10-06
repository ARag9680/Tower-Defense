#ifndef TOWER_H
#define TOWER_H

#include <utility>

class Tower{
    protected:
        std::pair<int, int> position;

    public:
        std::pair<int, int> getPosition(){return position;};
};

#endif