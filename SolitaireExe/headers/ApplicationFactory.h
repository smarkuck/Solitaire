#pragma once

#include <memory>
#include <string>

namespace solitaire {
class Application;

namespace interfaces {
class Context;
class Solitaire;
}

namespace events::interfaces {
class EventsProcessor;
}

namespace graphics::interfaces {
class Renderer;
}

namespace time::interfaces {
class FPSLimiter;
}
}

class ApplicationFactory {
public:
    solitaire::Application make() const;

private:
    std::unique_ptr<solitaire::interfaces::Context> makeContext() const;
    std::unique_ptr<solitaire::interfaces::Solitaire> makeSolitaire() const;

    std::unique_ptr<solitaire::events::interfaces::EventsProcessor>
    makeEventsProcessor(solitaire::interfaces::Context&) const;

    std::unique_ptr<solitaire::graphics::interfaces::Renderer>
    makeRenderer(const solitaire::interfaces::Context&) const;

    std::unique_ptr<solitaire::time::interfaces::FPSLimiter>
    makeFPSLimiter() const;

    std::string findAssetsPath() const;
};
