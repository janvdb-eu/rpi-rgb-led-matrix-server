#include <iostream>
#include "MockDisplay.h"

const int DIGIT_START_X = 7;
const int DIGIT_START_Y = 12;
const char *BDF_SMALL_FONT_FILE = "fonts/6x9.bdf";
const char *BDF_LARGE_FONT_FILE = "fonts/9x18.bdf";

MockDisplay::MockDisplay() {
    std::cout << "MockDisplay()" << std::endl;
}

MockDisplay::~MockDisplay() {
    std::cout << "~MockDisplay()" << std::endl;
}

bool MockDisplay::Initialize(int argc, char *argv[]) {
    std::cout << "Initialize() with ";
    for (int i = 1; i < argc; i++) {
        if (i != 1) std::cout << " ";
        std::cout << argv[i];
    }
    std::cout << std::endl;
    return true;
}

void MockDisplay::SetColor(uint8_t r, uint8_t g, uint8_t b) {
    std::cout << "SetColor(" << (int) r << ", " << (int) g << ", " << (int) b << ")" << std::endl;
}

void MockDisplay::Clear() {
    std::cout << "Clear()" << std::endl;
}

void MockDisplay::DrawPixel(int16_t x, int16_t y) {
    std::cout << "DrawPixel(" << x << ", " << y << ")" << std::endl;
}

void MockDisplay::DrawRectangle(int16_t x, int16_t y, int16_t width, int16_t height) {
    std::cout << "DrawRectangle(" << x << ", " << y << ", " << width << ", " << height << ")" << std::endl;
}

void MockDisplay::DrawDigit(uint8_t position, uint8_t digit) {
    std::cout << "DrawDigit(" << position << ", " << digit << ")" << std::endl;
}

void MockDisplay::DrawSmallText(int16_t x, int16_t y, std::string text) {
    std::cout << "DrawSmallText(" << x << ", " << y << ", \"" << text << "\")" << std::endl;
}

void MockDisplay::DrawLargeText(int16_t x, int16_t y, std::string text) {
    std::cout << "DrawLargeText(" << x << ", " << y << ", \"" << text << "\")" << std::endl;
}

void MockDisplay::Show() {
    std::cout << "Show()" << std::endl << std::endl;
}

boost::shared_ptr<Display> createDisplay() {
    return boost::shared_ptr<MockDisplay>(new MockDisplay());
}