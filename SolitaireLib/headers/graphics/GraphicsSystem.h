#pragma once

#include <string>

namespace solitaire {

namespace geometry {
struct Area;
struct Position;
}

namespace graphics {

struct TextureId;

class GraphicsSystem {
public:
    virtual ~GraphicsSystem() = default;

    virtual void createWindow(const std::string& title, const unsigned width,
                              const unsigned height) = 0;

    virtual TextureId loadTexture(const std::string& path) = 0;
    virtual void setTextureAlpha(const TextureId, const uint8_t alpha) const = 0;
    virtual void renderTexture(const TextureId, const geometry::Position&,
                               const geometry::Area&) const = 0;
    virtual void renderTextureInFullWindow(const TextureId) const = 0;
    virtual void renderFrame() const = 0;
};

}
}
