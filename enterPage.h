#ifndef ENTERPAGE
#define ENTERPAGE
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"

class enterPage {
    private:
        Button* back;
        Font font;

    public:
        enterPage() {
            font.loadFromFile("./Font.ttf"); // load font file


            // Check if successfully loaded
            if (!font.loadFromFile("./Font.ttf"))
            {
                    std::cout << "File failed to load" << std::endl;
            }
        }
        void displayCitation() {
            // Get the device screen size
            VideoMode desktop = VideoMode::getDesktopMode();

            // Create the window in the center of the screen
            RenderWindow window(VideoMode(1300, 800), "Citation Generator");

            // Calculate the center position
            int windowPosX = (desktop.width - 1300) / 2;
            int windowPosY = (desktop.height - 800) / 2;
            window.setPosition(Vector2i(windowPosX, windowPosY));


            // Make title
            Text title;
            title.setFont(this->font); // set font
            title.setString("Citation Generator"); // set the string to display
            title.setCharacterSize(60); // set the character size
            title.setFillColor(Color::Black); // set the color
            title.setStyle(Text::Bold); // set the text style

            // Center the title horizontally and vertically
            FloatRect titleBounds = title.getGlobalBounds();
            float titleX = (window.getSize().x - titleBounds.width) / 2.0f;
            title.setPosition(titleX, 50);

            // Make background
            Texture homeBackground;
            homeBackground.loadFromFile("Grid Background.jpg"); // Load file
            if (!homeBackground.loadFromFile("Grid Background.jpg")) {
                std::cout << "Texture file failed to load" << std::endl;
            }

            Sprite background(homeBackground);
            Vector2u windowSize = window.getSize(); //get window size
            Vector2u textureSize = homeBackground.getSize(); //get image size
            //Calculate scale factors to make image fit to window
            float scaleX = (1.0f * windowSize.x) / textureSize.x;
            float scaleY = (1.0f * windowSize.y) / textureSize.y;
            background.setScale(scaleX, scaleY); //scale the sprite

            while (window.isOpen()) {
                Event event;
                while (window.pollEvent(event)) {
                    // Handle close event
                    if (event.type == Event::Closed) {
                        window.close();
                    }
                }

                // Clear the window
                window.clear(Color::White);

                // Draw the background and title
                window.draw(background);
                window.draw(title);
                
                // Display everything on the window
                window.display();
            }
        }
        ~enterPage() {}
        
};

#endif