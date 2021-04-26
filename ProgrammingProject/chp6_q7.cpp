#include <iostream>
#include <string>

// Cards class
template <class T>
class Cards{
 private:
  T cardRank;
  T cardSuit;

 public:
  // Default constructor
  Cards<T>(T rank, T suit);
  // Access cardRank
  T getRank();
  // Modify cardRank
  void setRank(T rank);
  // Access cardSuit
  T getSuit();
  // Modify cardSuit
  void setSuit(T suit);
};

template <class T>
Cards<T>::Cards(T rank, T suit) {
  cardRank = rank;
  cardSuit = suit;
}

template <class T>
T Cards<T>::getRank() {
  return cardRank;
}

template <class T>
void Cards<T>::setRank(T rank) {
  cardRank = rank;
}

template <class T>
T Cards<T>::getSuit() {
  return cardSuit;
}

template <class T>
void Cards<T>::setSuit(T suit) {
  cardSuit = suit;
}

static const int  cardsTotal = 52;
typedef Cards value_type;
typedef size_t size_type;
// Class deck, inherited from class Cards
template <class T>
class Deck : public Cards<T> {
 private:
  value_type sequence[cardsTotal];
  size_type numOfCards;
  std::string ranks[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

 public:
  // Default constructor
  Deck();
  // Customized constructor
  Deck(size_type size);
  // Insert cards into the deck
  void insertCard(value_type deck, size_type t);
  // Swap cards in the deck
  void swap(size_type i);
  // Shuffle the deck
  void shuffleDeck();
  // Output the cards
  friend void outputDeck(Deck& d);
};

template <class T>
Deck<T>::Deck() {
  // Suit spades
  for (int i = 0; i < 13; ++i) {
    value_type cards("Spades", ranks[i % 13]);
    sequence[i] = cards;
  }
  // Suit hearts
  for (int i = 0; i < 13; ++i) {
    value_type cards("Hearts", ranks[i % 13]);
    sequence[i] = cards;
  }
  // Suit clubs
  for (int i = 0; i < 13; ++i) {
    value_type cards("Clubs", ranks[i % 13]);
    sequence[i] = cards;
  }
  // Suit Diamonds
  for (int i = 0; i < 13; ++i) {
    value_type cards("Diamonds", ranks[i % 13]);
    sequence[i] = cards;
  }
}

template <class T>
Deck<T>::Deck(size_type size) {
  numOfCards = 13;
}

template <class T>
void Deck<T>::insertCard(value_type deck, size_type i) {
  sequence[i] = deck;
}

template <class T>
void Deck<T>::swap(size_type i) {
  Cards tmp = sequence[i];
  sequence[i] = sequence[numOfCards - 1];
  sequence[numOfCards - 1] = tmp;
}

template <class T>
void Deck<T>::shuffleDeck() {
  srand(time(0));
  size_type randomInt = rand() % numOfCards;
  swap(randomInt);
}

template <class T>
void outputDeck(Deck<T>& d) {
  for (int i = 0; i < d.numOfCards; ++i) {
    if (d.sequence[i].getRank() == "A") {
      std::cout << d.sequence[i].getSuit() << " A" << std::endl;
    }
    else if (d.sequence[i].getRank() == "J") {
      std::cout << d.sequence[i].getSuit() << " J" << std::endl;
    }
    else if (d.sequence[i].getRank() == "Q") {
      std::cout << d.sequence[i].getSuit() << " Q" << std::endl;
    }
    else if (d.sequence[i].getRank() == "K") {
      std::cout << d.sequence[i].getSuit() << " K" << std::endl;
    }
    else {
      std::cout << d.sequence[i].getRank() << " " << d.sequence[i].getSuit() << std::endl;
    }
  }
}