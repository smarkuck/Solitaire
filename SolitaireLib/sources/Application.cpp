#include "Application.h"
#include "Context.h"
#include "Solitaire.h"
#include "events/EventsProcessor.h"
#include "graphics/Renderer.h"
#include "time/FPSLimiter.h"

using namespace solitaire::events;
using namespace solitaire::graphics;
using namespace solitaire::time;

namespace solitaire {

Application::Application(std::unique_ptr<Context> context,
                         std::unique_ptr<EventsProcessor> eventsProcessor,
                         std::unique_ptr<Renderer> renderer,
                         std::unique_ptr<FPSLimiter> fpsLimiter):
    context {std::move(context)},
    eventsProcessor {std::move(eventsProcessor)},
    renderer {std::move(renderer)},
    fpsLimiter {std::move(fpsLimiter)} {
}

void Application::run() const {
    context->getSolitaire().startNewGame();

    while (not eventsProcessor->shouldQuit()) {
        fpsLimiter->saveFrameStartTime();
        eventsProcessor->processEvents();
        renderer->render();
        fpsLimiter->sleepRestOfFrameTime();
    }
}

}
