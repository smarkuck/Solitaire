#pragma once

namespace solitaire::time {

class FPSLimiter {
public:
    virtual ~FPSLimiter() = default;

    virtual void saveFrameStartTime() = 0;
    virtual void sleepRestOfFrameTime() const = 0;
};

}
