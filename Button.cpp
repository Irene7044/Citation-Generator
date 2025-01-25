#include "Button.h"

Button::Button(float positionX, float positionY, float width, float height, int fontSize, Font font, std::string text, Color idleColour, Color hoverColour, Color activeColour) {
    this->shape.setPosition(Vector2f(positionX,positionY));
    this->shape.setSize(Vector2f(width, height));

    // Initialising button state
    isPressed = false;
    isHover = false;

    // Initialising button text
    this->font = font;
    this->text.setFont(this->font);
    this->text.setString(text);
    this->text.setFillColor(Color::Black);
    this->text.setCharacterSize(fontSize);

    // Set text position to center of button
    this->text.setPosition(
        this->shape.getPosition().x + (this->shape.getSize().x * this->shape.getScale().x) / 2.0f - this->text.getGlobalBounds().width / 2.0f,
        this->shape.getPosition().y + (this->shape.getSize().y * this->shape.getScale().y) / 2.0f - this->text.getGlobalBounds().height / 2.0f - (this->text.getGlobalBounds().height * 0.2f)
    );



    // Initialising button colours
    this->idleColour = idleColour;
    this->hoverColour = hoverColour;
    this->activeColour = activeColour;
    this->shape.setFillColor(this->idleColour);

    shape.setOutlineThickness(1);
    shape.setOutlineColor(Color::Black);
}

void Button::render(RenderTarget* target) {
    // Render the button
    target->draw(this->shape);
    target->draw(this->text);
}

void Button::updateButton(Vector2f(mousePosition)) {
    // Initialising button state
    isPressed = false;
    isHover = false;

    // If button is hovered by mouse
    if (this->shape.getGlobalBounds().contains(mousePosition)) {
        this->isHover = true;

        // If button is clicked
        if (Mouse::isButtonPressed(Mouse::Left)) {
            this->isPressed = true;
        }
    }

    // Changing button colour according to button state
    if (isHover && isPressed == true) {
        this->shape.setFillColor(this->activeColour);

    } else if (isHover == true && isPressed == false) {
        this->shape.setFillColor(this->hoverColour);

    } else if (isHover && isPressed == false) {
        this->shape.setFillColor(this->idleColour);
    } else {
        this->shape.setFillColor(this->idleColour); // If other cases occur
    }
}

const bool Button::getButtonState() {
    if (isPressed == true) {
        return true;
    }
    return false;
}

bool Button::isMouseOver(Vector2f mousePos) {
    FloatRect btnBounds = this->shape.getGlobalBounds(); //get the bounds of the button
    return btnBounds.contains(mousePos); //checks if mouse is hovering over button and within button bounds
}

Button::~Button() {}