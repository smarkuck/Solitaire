#pragma once

namespace solitaire::archivers {

class Snapshot {
public:
    virtual ~Snapshot() = default;
    virtual void restore() const = 0;
};

}