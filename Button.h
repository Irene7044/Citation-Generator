#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

class Button {
    private:
        bool isPressed;
        bool isHover;

        RectangleShape shape;
        Font font;
        Text text;

        Color idleColour;
        Color hoverColour;
        Color activeColour;

    public:
        Button(float positionX, float positionY, float width, float height, int fontSize, Font font, std::string text, Color idleColour, Color hoverColour, Color activeColour);
        void render(RenderTarget* target);
        void updateButton(Vector2f(mousePosition));
        const bool getButtonState();
        bool isMouseOver(Vector2f mousePos);
        ~Button();
};

#endif