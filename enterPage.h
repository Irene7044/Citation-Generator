#ifndef ENTERPAGE
#define ENTERPAGE
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"
#include "generateWebsite.h"

class enterPage {
    private:
        Button* Copy;
        Font font;

    public:
        enterPage() {
            font.loadFromFile("./Font.ttf"); // load font file

            // Check if successfully loaded
            if (!font.loadFromFile("./Font.ttf")) {
                std::cout << "File failed to load" << std::endl;
            }
        }

        void displayCitation(std::string citation) {
            // Get the device screen size
            VideoMode desktop = VideoMode::getDesktopMode();

            // Create the window in the center of the screen
            RenderWindow window(VideoMode(1300, 800), "Citation Generator");

            // Calculate the center position
            int windowPosX = (desktop.width - 1300) / 2;
            int windowPosY = (desktop.height - 800) / 2;
            window.setPosition(Vector2i(windowPosX, windowPosY));

            // Make title (in italics)
            Text title;
            title.setFont(this->font); // set font
            title.setString("Citation Generator"); // set the string to display
            title.setCharacterSize(60); // set the character size
            title.setFillColor(Color::Black); // set the color
            title.setStyle(Text::Regular); // set the text style to italic for the title

            // Make reference text (regular style)
            Text reference;
            reference.setFont(this->font); // set font
            reference.setString(citation); // set the citation string to display
            reference.setCharacterSize(30); // set a smaller character size for the citation
            reference.setFillColor(Color::Black); // set the color
            reference.setStyle(Text::Regular); // regular style for the citation

            // Center the title horizontally and vertically
            FloatRect titleBounds = title.getGlobalBounds();
            float titleX = (window.getSize().x - titleBounds.width) / 2.0f;
            title.setPosition(titleX, 50);

            // Position the reference text below the title
            FloatRect referenceBounds = reference.getGlobalBounds();
            float referenceX = (window.getSize().x - referenceBounds.width) / 2.0f;
            reference.setPosition(referenceX, 150); // Change this Y position if you need it further down

            // Make background
            Texture homeBackground;
            homeBackground.loadFromFile("Grid Background.jpg"); // Load file
            if (!homeBackground.loadFromFile("Grid Background.jpg")) {
                std::cout << "Texture file failed to load" << std::endl;
            }

            Sprite background(homeBackground);
            Vector2u windowSize = window.getSize(); // get window size
            Vector2u textureSize = homeBackground.getSize(); // get image size
            // Calculate scale factors to make image fit to window
            float scaleX = (1.0f * windowSize.x) / textureSize.x;
            float scaleY = (1.0f * windowSize.y) / textureSize.y;
            background.setScale(scaleX, scaleY); // scale the sprite

            // Initialise buttons 
            Copy = new Button(1100,650,120,100,20,this->font,"Copy",Color(199,214,255,200),Color(135,147,176,255),Color(98,115,140,200));

            while (window.isOpen()) {
                Event event;
                while (window.pollEvent(event)) {
                    // Handle close event
                    if (event.type == Event::Closed) {
                        window.close();
                    }
                }

                Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                Copy->updateButton(mousePos);

                // Transition to reference type page when adelaideUni button is pressed
                if (Copy->getButtonState() == true) {
                    Clipboard::setString(citation);
                }


                // Clear the window
                window.clear(Color::White);

                // Draw the background, title, and reference
                window.draw(background);
                window.draw(title); // Draw the title in italics
                window.draw(reference); // Draw the reference text in regular style
                Copy->render(&window);
                // Display everything on the window
                window.display();
            }
        }

        ~enterPage() {delete Copy;}
};

#endif
