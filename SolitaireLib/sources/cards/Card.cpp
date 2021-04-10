#include "cards/Card.h"
#include "cards/Suit.h"
#include "cards/Value.h"

namespace solitaire::cards {

Card::Card(): Card(Value::Ace, Suit::Heart) {
}

Card::Card(Value value, Suit suit):
    value(value), suit(suit) {
}

Value Card::getValue() const {
    return value;
}

Suit Card::getSuit() const {
    return suit;
}

bool Card::hasValueOneGreaterThan(const Card& card) const {
    return static_cast<std::underlying_type<Value>::type>(value) - 1 ==
           static_cast<std::underlying_type<Value>::type>(card.value);
}

bool Card::hasSameSuitAs(const Card& card) const {
    return suit == card.getSuit();
}

bool Card::hasDifferentColorThan(const Card& card) const {
    return hasRedColor() != card.hasRedColor();
}

bool Card::hasRedColor() const {
    return suit == Suit::Heart or suit == Suit::Diamond;
}

bool operator==(const Card& lhs, const Card& rhs) {
    return lhs.getValue() == rhs.getValue() and lhs.getSuit() == rhs.getSuit();
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    return os << "Card {value: " << to_string(card.getValue())
              << ", suit: " << to_string(card.getSuit()) << '}';
}

}
