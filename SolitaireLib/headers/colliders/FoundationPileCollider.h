#pragma once

namespace solitaire {

namespace geometry {
struct Position;
}

namespace colliders {

class FoundationPileCollider {
public:
    virtual ~FoundationPileCollider() = default;
    virtual geometry::Position getPosition() const = 0;
};

}
}
