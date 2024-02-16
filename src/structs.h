
#include <raylib-cpp.hpp>

struct Pen {
    raylib::Color color;
    Pen(raylib::Color c) : color(c) {}
};

struct DrawTools {
    Pen pen;
    DrawTools() : pen(LIGHTGRAY) {} 
};



struct Settings {
    unsigned screenWidth;
    unsigned screenHeight;
    unsigned cellWidth;
    unsigned cellHeight;
    unsigned landscapeWidth;
    unsigned landscapeHeight;

    Settings(unsigned sw, unsigned sh, unsigned lw, unsigned lh, unsigned cw, unsigned ch)
        : screenWidth(sw)
        , screenHeight(sh)
        , cellWidth(cw)
        , cellHeight(ch)
        , landscapeWidth(lw)
        , landscapeHeight(lh)
    {}
};

struct Cell {
    DrawTools drawTools;
    Rectangle rect;
    Color color;
    unsigned x = 0;
    unsigned y = 0;
    unsigned width = 0;
    unsigned height = 0;

    Cell();
    Cell(unsigned x_, unsigned y_, unsigned w, unsigned h)
        : x(x_)
        , y(y_)
        , width(w)
        , height(h)
        , drawTools()
        , color(LIGHTGRAY)
        {}

    void Draw() {
        DrawRectangleRec(rect, color);
    }
};
