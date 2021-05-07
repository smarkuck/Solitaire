#include "Application.h"
#include "ApplicationFactory.h"
#include "SDL.h"
#include "interfaces/Context.h"
#include "interfaces/events/EventsProcessor.h"
#include "interfaces/graphics/Renderer.h"
#include "interfaces/time/FPSLimiter.h"

int main(int, char**) {
    ApplicationFactory {}.make().run();
    return 0;
}
