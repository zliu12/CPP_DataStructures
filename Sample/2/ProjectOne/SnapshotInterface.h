#ifndef PROJECTONETEXTBOX_SNAPSHOTINTERFACE_H
#define PROJECTONETEXTBOX_SNAPSHOTINTERFACE_H
#include "Snapshot.h"

class SnapshotInterface : public Snapshot{
// this function will return a snapshot of the object's current state
    virtual Snapshot& getSnapshot() = 0;

// this function will apply a snapshot to the object.
//This will revert the object back to the state that has been recorded in the snapshot
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};


#endif //PROJECTONETEXTBOX_SNAPSHOTINTERFACE_H
