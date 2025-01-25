#ifndef GRAPHICS
#define GRAPHICS
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"
#include "ReferenceType.h"
#include "WebsiteInput.h"


using namespace sf;

class Graphics {
    private:
        Font font;
        Button* adelaideUni;

    public:
        Graphics() {
            font.loadFromFile("./Font.ttf"); // load font file


            // Check if successfully loaded
            if (!font.loadFromFile("./Font.ttf"))
            {
                    std::cout << "File failed to load" << std::endl;
            }
        }

        void displayGraphics() {
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

            // Initialising buttons
            float buttonX = (window.getSize().x - 220) / 2.0f;  // Center horizontally
            adelaideUni = new Button(buttonX,280,220,90,20,this->font,"University of Adelaide",Color(199,214,255,200),Color(135,147,176,255),Color(98,115,140,200));

            while (window.isOpen()) {
                Event event;
                while (window.pollEvent(event)) {
                    // Handle close event
                    if (event.type == Event::Closed) {
                        window.close();
                    }
                }

                Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                adelaideUni->updateButton(mousePos);

                // Transition to reference type page when adelaideUni button is pressed
                if (adelaideUni->getButtonState() == true) {
                    window.close();
                    ReferenceType newPage;
                    newPage.displayTypes();
                }

                // Clear the window
                window.clear(Color::White);

                // Draw the background and title
                window.draw(background);
                window.draw(title);
                
                adelaideUni->render(&window);

                // Display everything on the window
                window.display();
            }

        }

        ~Graphics() {delete adelaideUni;}
};

#endif