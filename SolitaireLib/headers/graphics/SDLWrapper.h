#pragma once

#include <optional>
#include <string>

#include "SDL.h"
#include "SDLPtr.h"

namespace solitaire::graphics {

class SDLWrapper {
public:
    virtual int init(Uint32 flags) const = 0;

    virtual void quit() const = 0;

    virtual SDLPtr<SDL_Window> createWindow(
        const std::string& title, int x, int y, int w, int h, Uint32 flags) const = 0;

    virtual SDLPtr<SDL_Renderer> createRenderer(const SDLPtr<SDL_Window>&,
                                                int index, Uint32 flags) const = 0;

    virtual SDLPtr<SDL_Texture> createTextureFromSurface(
        const SDLPtr<SDL_Renderer>&, const SDLPtr<SDL_Surface>&) const = 0;

    virtual SDLPtr<SDL_Surface> loadBMP(const std::string& file) const = 0;

    virtual int setTextureAlphaMod(const SDLPtr<SDL_Texture>&, Uint8 alpha) const = 0;

    virtual int setColorKey(const SDLPtr<SDL_Surface>&, int flag, Uint32 key) const = 0;

    virtual Uint32 mapRGB(const SDLPtr<SDL_Surface>&, Uint8 r, Uint8 g, Uint8 b) const = 0;

    virtual int setRenderDrawColor(const SDLPtr<SDL_Renderer>&,
                                   Uint8 r, Uint8 g, Uint8 b, Uint8 a) const = 0;

    virtual int renderClear(const SDLPtr<SDL_Renderer>&) const = 0;

    virtual int renderCopy(const SDLPtr<SDL_Renderer>&, const SDLPtr<SDL_Texture>&,
                           const std::optional<SDL_Rect>& srcrect,
                           const std::optional<SDL_Rect>& dstrect) const = 0;

    virtual void renderPresent(const SDLPtr<SDL_Renderer>&) const = 0;

    virtual void delay(Uint32 ms) const = 0;
};

}
