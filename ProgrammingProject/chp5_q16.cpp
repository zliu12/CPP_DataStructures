#include <iostream>
#include <string>

// Cards class
class Cards{
 private:
  std::string cardRank;
  std::string cardSuit;

 public:
  // Default constructor
  Cards(std::string rank, std::string suit);
  // Access cardRank
  std::string getRank();
  // Modify cardRank
  void setRank(std::string rank);
  // Access cardSuit
  std::string getSuit();
  // Modify cardSuit
  void setSuit(std::string suit);
};

Cards::Cards(std::string rank, std::string suit) {
  cardRank = rank;
  cardSuit = suit;
}

std::string Cards::getRank() {
  return cardRank;
}

void Cards::setRank(std::string rank) {
  cardRank = rank;
}

std::string Cards::getSuit() {
  return cardSuit;
}

void Cards::setSuit(std::string suit) {
  cardSuit = suit;
}

static const int  cardsTotal = 52;
typedef Cards value_type;
typedef size_t size_type;
// Class deck, inherited from class Cards
class Deck : public Cards {
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

Deck::Deck() {
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

Deck::Deck(size_type size) {
  numOfCards = 13;
}

void Deck::insertCard(value_type deck, size_type i) {
  sequence[i] = deck;
}

void Deck::swap(size_type i) {
  Cards tmp = sequence[i];
  sequence[i] = sequence[numOfCards - 1];
  sequence[numOfCards - 1] = tmp;
}

void Deck::shuffleDeck() {
  srand(time(0));
  size_type randomInt = rand() % numOfCards;
  swap(randomInt);
}

void outputDeck(Deck& d) {
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