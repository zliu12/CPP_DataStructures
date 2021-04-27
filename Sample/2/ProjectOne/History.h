#ifndef PROJECTONETEXTBOX_HISTORY_H
#define PROJECTONETEXTBOX_HISTORY_H
#include <stack>
#include "Snapshot.h"
# include "KeyBoardShortCut.h"

class History{
private:
    std::stack<Snapshot> stack;
    //static std::map<std::string, GUIComponents*> components;
public:
    History();
    void pushHistory(Snapshot& snapshot);
    Snapshot& topHistory();
    void popHistory();
    void draw(sf::RenderTarget& window, sf::RenderStates states);
    int getSize();
// from EventHandler
    void update();
    friend std::ostream& operator << (std::ostream& out, const History& history);

//from SnapshotInterface
    void applySnapShot(const Snapshot& snapshot);
    Snapshot& getSnapshot();

};


#endif //PROJECTONETEXTBOX_HISTORY_H
