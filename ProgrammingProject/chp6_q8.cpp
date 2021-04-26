#include <string>
#include <vector>
#include <map>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::vector;
// using std::map;
// using std::pair;

class PplAndGifts {
 public:
  vector<string> giftVec;
  string name;
  PplAndGifts* next;
};

class list {
 private:
  PplAndGifts* head;
  PplAndGifts* tail;
  // Create a new PplAndGifts
  PplAndGifts* createOne(string insertName, string insertGift);
  // Find the target person
  PplAndGifts* findPpl(string targetName);
  // Find the person before the target person
  PplAndGifts* findPrev(string targetName);

 public:
  // Add person to the list
  void addPpl(string insertName);
  // Add gift to the target person
  void addGift(string insertGift, string targetName);
  // Remove a person
  void removePpl(string targetName);
  // Remove a person's gift
  void removeGift(string targetGift, string targetName);
  // Access a person's name
  string getPpl();
  // Access a person's gift
  string getGift();
};

PplAndGifts* list::createOne(string insertName = "", string insertGift = "") {
  PplAndGifts* n = new PplAndGifts;
  n->giftVec.push_back(insertGift);
  n->name = insertName;
  n->next = nullptr;
}

PplAndGifts* list::findPpl(string targetName) {
  PplAndGifts* n = head;
  for (; n != nullptr && n->name != targetName; n = n->next) {}
  return n;
}

PplAndGifts* list::findPrev(string targetName) {
  PplAndGifts* n = findPpl(targetName);
  if (n == nullptr) {
    cout << "Person doesn't exit." << endl;
    return;
  }
  else if (n == head) {
    cout << "Person is at the first position." << endl;
  }
  else {
    PplAndGifts* nPrev = head;
    while (nPrev->next != n) {
      nPrev = nPrev->next;
    }
    return nPrev;
  }
  return n;
}

void list::addPpl(string insertName) {
  if (head == nullptr) {
    PplAndGifts* n = createOne(insertName);
    head = n;
    tail = n;
  }
  else {
    PplAndGifts* n = findPpl(insertName);
    if(n == nullptr) {
      cout << "Person exits." << endl;
      return;
    }
    else {
      tail->next = n;
      tail = n;
    }
  }
}

void list::addGift(string insertGift, string targetName) {
  if (head == nullptr) {
    cout << "Nothing in the list, please add a person first." << endl;
    return;
  }
  else {
    PplAndGifts* n = findPpl(targetName);
    if (n == nullptr) {
      cout << "Person doesn't exist, please add first." << endl;
      return;
    }
    else {
      n->giftVec.push_back(insertGift);
    }
  }
}

void list::removePpl(string targetName) {
  PplAndGifts* n = findPpl(targetName);
  if (n == nullptr) {
    cout << "Person doesn't exist." << endl;
    return;
  }
  else if (n == head) {
    head = head->next;
    delete n;
  }
  else if (n == tail) {
    PplAndGifts* nPrev = findPrev(targetName);
    nPrev->next = nullptr;
    tail = nPrev;
    delete n;
  }
  else {
    PplAndGifts* nPrev = findPrev(targetName);
    nPrev->next = n->next;
    delete n;
  }
}

void list::removeGift(string targetGift, string targetName) {
  PplAndGifts* n = findPpl(targetName);
  if (n == nullptr) {
    cout << "Person doesn't exist." << endl;
  }
  else {
    vector<string>::iterator iter = n->giftVec.begin();
    for (; iter != n->giftVec.end(); ++iter) {
      if (*iter == targetGift) {
        n->giftVec.erase(iter);
      }
    }
  }
}