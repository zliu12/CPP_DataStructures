#include "History.h"
static std::stack<Snapshot> stack;
History::History()
{

}
void History::pushHistory(Snapshot& snapshot)
{
    stack.push(snapshot);
}
Snapshot& History::topHistory()
{
    return stack.top();
}

int History::getSize()
{
    return stack.size();
}

void History::popHistory()
{
    stack.pop();
}

//void History::addEventHandler(sf::RenderWindow& window, sf::Event event)
//{
//    if(KeyBoardShortCut::isUndo())
//    {
//        if(!stack.empty())
//        {
//            //stack.top().data->applySnapShot(stack.top().snapshot);
//            stack.pop();
//        }
//    }
//}