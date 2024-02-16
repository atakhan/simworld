#include "landscape.h"

class Game
{
  private:
    Settings *settings;
    Landscape landscape;

  public:
    raylib::Window window;

    Game(Settings *s)
        : settings(s)
        , landscape(s)
        , window(s->screenWidth, s->screenHeight, "SimWorld") 
        {}

    void Init() {
        landscape.generateSurface();
    }

    void Update() {}

    void Draw() {
        landscape.Draw();
    }
};