#ifndef DISPLAYSERVER_MOCKDISPLAY_H
#define DISPLAYSERVER_MOCKDISPLAY_H

#include <led-matrix.h>
#include <graphics.h>
#include "Display.h"

namespace displays {

    class MockDisplay : public Display {
    public:
        MockDisplay();
        ~MockDisplay() override;

        bool Initialize(int argc, char **argv) override;

        void SetColor(uint8_t r, uint8_t g, uint8_t b) override;
        void Clear() override;

        void DrawPixel(int x, int y) override;
        void DrawRectangle(int x, int y, int width, int height) override;
        void DrawDigit(int position, int digit) override;
        void DrawSmallText(int x, int y, std::string text) override;
        void DrawLargeText(int x, int y, std::string text) override;

        void Show() override;
    };
}

#endif //DISPLAYSERVER_MOCKDISPLAY_H
