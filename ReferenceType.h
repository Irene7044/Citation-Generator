#ifndef REFERENCETYPE
#define REFERENCETYPE
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"
#include "WebsiteInput.h"

using namespace sf;

class ReferenceType {
    private:
        Font font;
        Button* Website;
        Button* Article;
        Button* Image;
        Button* Video;

    public:
        ReferenceType() {
            font.loadFromFile("./Font.ttf"); // load font file


            // Check if successfully loaded
            if (!font.loadFromFile("./Font.ttf"))
            {
                    std::cout << "File failed to load" << std::endl;
            }
        }

        void displayTypes() {
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
            title.setPosition(420,40);

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
            Website = new Button(500,200,220,90,30,this->font,"Website",Color(199,214,255,200),Color(135,147,176,255),Color(98,115,140,200));
            Article = new Button(500,320,220,90,30,this->font,"Article",Color(199,214,255,200),Color(135,147,176,255),Color(98,115,140,200));
            Image = new Button(500,440,220,90,30,this->font,"Image",Color(199,214,255,200),Color(135,147,176,255),Color(98,115,140,200));
            Video = new Button(500,560,220,90,30,this->font,"Video",Color(199,214,255,200),Color(135,147,176,255),Color(98,115,140,200));

            while (window.isOpen()) {
                Event event;
                while (window.pollEvent(event)) {
                    // Handle close event
                    if (event.type == Event::Closed) {
                        window.close();
                    }
                }

                Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                Website->updateButton(mousePos);
                Article->updateButton(mousePos);
                Image->updateButton(mousePos);
                Video->updateButton(mousePos);

                // Transition to website input page when adelaideUni button is pressed
                if (Website->getButtonState() == true) {
                    window.close();
                    WebsiteInput inputPage;
                    inputPage.displayInput();
                }

                // Clear the window
                window.clear(Color::White);

                // Draw the background and title
                window.draw(background);
                window.draw(title);
                
                Website->render(&window);
                Article->render(&window);
                Image->render(&window);
                Video->render(&window);

                // Display everything on the window
                window.display();
            }
        }

        ~ReferenceType() {
            delete Website;
            delete Article;
            delete Image;
            delete Video;
        }

};

#endif