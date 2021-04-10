#include <string>

#include "Solitaire.h"
#include "cards/DeckGenerator.h"
#include "piles/FoundationPile.h"
#include "piles/StockPile.h"
#include "piles/TableauPile.h"

using namespace solitaire::cards;
using namespace solitaire::piles;

namespace solitaire {

Solitaire::Solitaire(std::unique_ptr<DeckGenerator> deckGenerator,
                     std::shared_ptr<StockPile> stockPile,
                     FoundationPiles foundationPiles,
                     TableauPiles tableauPiles):
    deckGenerator {std::move(deckGenerator)},
    stockPile {std::move(stockPile)},
    foundationPiles {std::move(foundationPiles)},
    tableauPiles {std::move(tableauPiles)} {
}

void Solitaire::startNewGame() {
    const auto deck = deckGenerator->generate();

    for (auto& pile: foundationPiles)
        pile->initialize();

    const auto firstNotUsedCard = initializeTableauPilesAndReturnFirstNotUsedCard(deck);
    stockPile->initialize(firstNotUsedCard, deck.end());
}

Deck::const_iterator
Solitaire::initializeTableauPilesAndReturnFirstNotUsedCard(const Deck& deck) {
    auto firstNotUsedCard = deck.begin();
    unsigned currentPileCardsCount = 1;

    for (auto& pile: tableauPiles) {
        const auto firstPileCard = firstNotUsedCard;
        std::advance(firstNotUsedCard, currentPileCardsCount++);
        pile->initialize(firstPileCard, firstNotUsedCard);
    }

    return firstNotUsedCard;
}

const FoundationPile& Solitaire::getFoundationPile(unsigned id) const {
    if (id >= foundationPiles.size())
        throw std::runtime_error{"Cannot access foundation pile with id: " + std::to_string(id)};
    return *foundationPiles[id];
}

const TableauPile& Solitaire::getTableauPile(unsigned id) const {
    if (id >= tableauPiles.size())
        throw std::runtime_error{"Cannot access tableau pile with id: " + std::to_string(id)};
    return *tableauPiles[id];
}

const StockPile& Solitaire::getStockPile() const {
    return *stockPile;
}

}
