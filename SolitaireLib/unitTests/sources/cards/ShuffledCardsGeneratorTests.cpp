#include <algorithm>

#include "cards/Card.h"
#include "cards/CardsGeneratorUtils.h"
#include "cards/ShuffledCardsGenerator.h"
#include "gmock/gmock.h"

using namespace testing;

namespace solitaire::cards {

namespace {
bool cardsComparator(const Card& lhs, const Card& rhs) {
    if (lhs.getSuit() == rhs.getSuit())
        return lhs.getValue() < rhs.getValue();
    return lhs.getSuit() < rhs.getSuit();
}
}

class ShuffledCardsGeneratorTest: public Test {
public:
    ShuffledCardsGenerator generator;
};

TEST_F(ShuffledCardsGeneratorTest, generateShuffledCards) {
    auto generatedCards = generator.generate();

    EXPECT_FALSE(std::is_sorted(
        generatedCards.begin(), generatedCards.end(), cardsComparator
    ));

    std::sort(generatedCards.begin(), generatedCards.end(), cardsComparator);
    EXPECT_THAT(generatedCards, ContainerEq(createSortedCards()));
}

TEST_F(ShuffledCardsGeneratorTest, generatedCardsHaveDifferentOrder) {
    EXPECT_NE(generator.generate(), generator.generate());
}

}