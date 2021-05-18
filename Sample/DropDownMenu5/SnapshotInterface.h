#ifndef PROJECT1_SNAPSHOTINTERFACE_H
#define PROJECT1_SNAPSHOTINTERFACE_H
#include "Snapshot.h"
#include <iostream>
class SnapshotInterface {
public:
    virtual Snapshot& getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot& snapshot) = 0;

    SnapshotInterface(){};
    SnapshotInterface(std::string compoentID);
};


#endif //PROJECT1_SNAPSHOTINTERFACE_H
