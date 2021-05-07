#pragma once

#include "geometry/Position.h"
#include "gmock/gmock.h"
#include "interfaces/Context.h"
#include "piles/PileId.h"

namespace solitaire {

class ContextMock: public interfaces::Context {
public:
    MOCK_METHOD(void, setMousePosition, (const geometry::Position&), (override));
    MOCK_METHOD(void, setCardsInHandPosition, (const geometry::Position&), (override));

    MOCK_METHOD(interfaces::Solitaire&, getSolitaire, (), (override));
    MOCK_METHOD(const interfaces::Solitaire&, getSolitaire, (), (const, override));

    MOCK_METHOD(colliders::interfaces::FoundationPileCollider&,
                getFoundationPileCollider, (const piles::PileId), (override));

    MOCK_METHOD(const colliders::interfaces::FoundationPileCollider&,
                getFoundationPileCollider, (const piles::PileId), (const, override));

    MOCK_METHOD(geometry::Position, getMousePosition, (), (const, override));
    MOCK_METHOD(geometry::Position, getCardsInHandPosition, (), (const, override));
};

}
