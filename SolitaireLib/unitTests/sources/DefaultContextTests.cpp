#include <utility>

#include "DefaultContext.h"
#include "mock_ptr.h"
#include "SolitaireMock.h"
#include "cards/Card.h"
#include "colliders/FoundationPileColliderMock.h"
#include "gtest/gtest.h"

using namespace testing;
using namespace solitaire::colliders;
using namespace solitaire::geometry;
using namespace solitaire::piles;

namespace solitaire {

class DefaultContextTests: public Test {
public:
    using FoundationPileColliderMocks = std::array<
        mock_ptr<FoundationPileColliderMock>,
        Solitaire::foundationPilesCount>;

    DefaultContextTests() {
        DefaultContext::FoundationPileColliders foundationPileColliders;
        std::transform(
            foundationPileColliderMocks.begin(), foundationPileColliderMocks.end(),
            foundationPileColliders.begin(), [](auto& collider) {
                return collider.make_unique();
            }
        );

        context = std::make_unique<DefaultContext>(
            solitaireMock.make_unique(), std::move(foundationPileColliders));
    }

    mock_ptr<SolitaireMock> solitaireMock;
    FoundationPileColliderMocks foundationPileColliderMocks;
    std::unique_ptr<DefaultContext> context;
};

TEST_F(DefaultContextTests, setAndGet) {
    EXPECT_EQ(&context->getSolitaire(), solitaireMock.get());
    EXPECT_EQ(&std::as_const(context)->getSolitaire(), solitaireMock.get());

    for (PileId id {0}; id < Solitaire::foundationPilesCount; ++id) {
        EXPECT_EQ(&context->getFoundationPileCollider(id),
                  foundationPileColliderMocks[id].get());

        EXPECT_EQ(&std::as_const(context)->getFoundationPileCollider(id),
                  foundationPileColliderMocks[id].get());
    }

    Position position1 {1, 7};
    Position position2 {2, 4};

    context->setMousePosition(position1);
    EXPECT_EQ(context->getMousePosition(), position1);
    context->setMousePosition(position2);
    EXPECT_EQ(context->getMousePosition(), position2);
    context->setCardsInHandPosition(position1);
    EXPECT_EQ(context->getCardsInHandPosition(), position1);
    context->setCardsInHandPosition(position2);
    EXPECT_EQ(context->getCardsInHandPosition(), position2);
}

}
