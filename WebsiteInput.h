#ifndef WEBSITEINPUT
#define WEBSITEINPUT

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"
#include "enterPage.h"
#include "generateWebsite.h"

class WebsiteInput {
private:
    Font font;
    Button* enter;

    // Text inputs for citation fields
    String firstNameInput;
    String lastNameInput;
    String websiteNameInput;
    String titleInput;
    String urlInput;
    String yearPublished;
    String yearViewed;
    String monthViewed;
    String dayViewed;
    
    // Text objects to display input
    Text firstNameText;
    Text lastNameText;
    Text websiteNameText;
    Text urlText;
    Text titleText;
    Text yearPublishedText;
    Text yearViewedText;
    Text monthViewedText;
    Text dayViewedText;

    // Text objects for labels
    Text firstNameLabel;
    Text lastNameLabel;
    Text websiteNameLabel;
    Text urlLabel;
    Text titleLabel;
    Text yearPublishedLabel;
    Text yearViewedLabel;
    Text monthViewedLabel;
    Text dayViewedLabel;

    // Text box rectangles for input fields
    RectangleShape firstNameBox;
    RectangleShape lastNameBox;
    RectangleShape websiteNameBox;
    RectangleShape urlBox;
    RectangleShape titleBox;
    RectangleShape yearPublishedBox;
    RectangleShape yearViewedBox;
    RectangleShape monthViewedBox;
    RectangleShape dayViewedBox;

    // For checking which box is selected
    bool firstNameSelected;
    bool lastNameSelected;
    bool websiteNameSelected;
    bool urlSelected;
    bool titleSelected;
    bool yearPublishedSelected;
    bool yearViewedSelected;
    bool monthViewedSelected;
    bool dayViewedSelected;

public:
    WebsiteInput() {
        if (!font.loadFromFile("./Font.ttf")) { // Load font file
            std::cout << "Font file failed to load" << std::endl;
        }

        // Set up the text properties for input fields
        firstNameText.setFont(font);
        firstNameText.setCharacterSize(30);
        firstNameText.setFillColor(Color::Black);

        lastNameText.setFont(font);
        lastNameText.setCharacterSize(30);
        lastNameText.setFillColor(Color::Black);

        websiteNameText.setFont(font);
        websiteNameText.setCharacterSize(30);
        websiteNameText.setFillColor(Color::Black);

        urlText.setFont(font);
        urlText.setCharacterSize(30);
        urlText.setFillColor(Color::Black);

        titleText.setFont(font);
        titleText.setCharacterSize(30);
        titleText.setFillColor(Color::Black);
        titleText.setStyle(Text::Regular);

        yearPublishedText.setFont(font);
        yearPublishedText.setCharacterSize(30);
        yearPublishedText.setFillColor(Color::Black);

        yearViewedText.setFont(font);
        yearViewedText.setCharacterSize(30);
        yearViewedText.setFillColor(Color::Black);

        monthViewedText.setFont(font);
        monthViewedText.setCharacterSize(30);
        monthViewedText.setFillColor(Color::Black);

        dayViewedText.setFont(font);
        dayViewedText.setCharacterSize(30);
        dayViewedText.setFillColor(Color::Black);

        // Set up the text properties for labels
        firstNameLabel.setFont(font);
        firstNameLabel.setCharacterSize(30);
        firstNameLabel.setFillColor(Color::Black);
        firstNameLabel.setString("First Name");

        lastNameLabel.setFont(font);
        lastNameLabel.setCharacterSize(30);
        lastNameLabel.setFillColor(Color::Black);
        lastNameLabel.setString("Last Name");

        websiteNameLabel.setFont(font);
        websiteNameLabel.setCharacterSize(30);
        websiteNameLabel.setFillColor(Color::Black);
        websiteNameLabel.setString("Website Name");

        urlLabel.setFont(font);
        urlLabel.setCharacterSize(30);
        urlLabel.setFillColor(Color::Black);
        urlLabel.setString("URL");

        titleLabel.setFont(font);
        titleLabel.setCharacterSize(30);
        titleLabel.setFillColor(Color::Black);
        titleLabel.setString("Title");

        yearPublishedLabel.setFont(font);
        yearPublishedLabel.setCharacterSize(30);
        yearPublishedLabel.setFillColor(Color::Black);
        yearPublishedLabel.setString("Year Published");

        yearViewedLabel.setFont(font);
        yearViewedLabel.setCharacterSize(30);
        yearViewedLabel.setFillColor(Color::Black);
        yearViewedLabel.setString("Year Viewed");

        monthViewedLabel.setFont(font);
        monthViewedLabel.setCharacterSize(30);
        monthViewedLabel.setFillColor(Color::Black);
        monthViewedLabel.setString("Month Viewed");

        dayViewedLabel.setFont(font);
        dayViewedLabel.setCharacterSize(30);
        dayViewedLabel.setFillColor(Color::Black);
        dayViewedLabel.setString("Day Viewed");

        // Position the text fields
        firstNameText.setPosition(400, 200);
        lastNameText.setPosition(400, 260);
        websiteNameText.setPosition(400, 320);
        urlText.setPosition(400, 380);
        titleText.setPosition(400, 440);
        yearPublishedText.setPosition(400, 500);
        yearViewedText.setPosition(400, 560);
        monthViewedText.setPosition(400, 620);
        dayViewedText.setPosition(400, 680);

        // Position the labels to the left of the text boxes
        firstNameLabel.setPosition(100, 200);
        lastNameLabel.setPosition(100, 260);
        websiteNameLabel.setPosition(100, 320);
        urlLabel.setPosition(100, 380);
        titleLabel.setPosition(100, 440);
        yearPublishedLabel.setPosition(100, 500);
        yearViewedLabel.setPosition(100, 560);
        monthViewedLabel.setPosition(100, 620);
        dayViewedLabel.setPosition(100, 680);

        // Set up the input text boxes
        firstNameBox.setSize(Vector2f(600.f, 40.f));
        firstNameBox.setFillColor(Color(200, 200, 200, 200));
        firstNameBox.setOutlineThickness(2);
        firstNameBox.setOutlineColor(Color::Black);
        firstNameBox.setPosition(400, 200);

        lastNameBox.setSize(Vector2f(600.f, 40.f));
        lastNameBox.setFillColor(Color(200, 200, 200, 200));
        lastNameBox.setOutlineThickness(2);
        lastNameBox.setOutlineColor(Color::Black);
        lastNameBox.setPosition(400, 260);

        websiteNameBox.setSize(Vector2f(600.f, 40.f));
        websiteNameBox.setFillColor(Color(200, 200, 200, 200));
        websiteNameBox.setOutlineThickness(2);
        websiteNameBox.setOutlineColor(Color::Black);
        websiteNameBox.setPosition(400, 320);

        urlBox.setSize(Vector2f(600.f, 40.f));
        urlBox.setFillColor(Color(200, 200, 200, 200));
        urlBox.setOutlineThickness(2);
        urlBox.setOutlineColor(Color::Black);
        urlBox.setPosition(400, 380);

        titleBox.setSize(Vector2f(600.f, 40.f));
        titleBox.setFillColor(Color(200, 200, 200, 200));
        titleBox.setOutlineThickness(2);
        titleBox.setOutlineColor(Color::Black);
        titleBox.setPosition(400, 440);

        yearPublishedBox.setSize(Vector2f(600.f, 40.f));
        yearPublishedBox.setFillColor(Color(200, 200, 200, 200));
        yearPublishedBox.setOutlineThickness(2);
        yearPublishedBox.setOutlineColor(Color::Black);
        yearPublishedBox.setPosition(400, 500);

        yearViewedBox.setSize(Vector2f(600.f, 40.f));
        yearViewedBox.setFillColor(Color(200, 200, 200, 200));
        yearViewedBox.setOutlineThickness(2);
        yearViewedBox.setOutlineColor(Color::Black);
        yearViewedBox.setPosition(400, 560);

        monthViewedBox.setSize(Vector2f(600.f, 40.f));
        monthViewedBox.setFillColor(Color(200, 200, 200, 200));
        monthViewedBox.setOutlineThickness(2);
        monthViewedBox.setOutlineColor(Color::Black);
        monthViewedBox.setPosition(400, 620);

        dayViewedBox.setSize(Vector2f(600.f, 40.f));
        dayViewedBox.setFillColor(Color(200, 200, 200, 200));
        dayViewedBox.setOutlineThickness(2);
        dayViewedBox.setOutlineColor(Color::Black);
        dayViewedBox.setPosition(400, 680);

        // Set the initial selection state
        firstNameSelected = false;
        lastNameSelected = false;
        websiteNameSelected = false;
        urlSelected = false;
        titleSelected = false;
        yearPublishedSelected = false;
        yearViewedSelected = false;
        monthViewedSelected = false;
        dayViewedSelected = false;
    }

    void displayInput() {
        generateWebsite curr_reference;
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
        title.setString("Citation Generator: Website"); // set the string to display
        title.setCharacterSize(60); // set the character size
        title.setFillColor(Color::Black); // set the color
        title.setStyle(Text::Bold); // set the text style

        // Center the title horizontally
        FloatRect titleBounds = title.getGlobalBounds();
        float titleX = (window.getSize().x - titleBounds.width) / 2.0f;
        title.setPosition(titleX, 50);

        // Make background
        Texture homeBackground;
        if (!homeBackground.loadFromFile("Grid Background.jpg")) {
            std::cout << "Texture file failed to load" << std::endl;
        }

        Sprite background(homeBackground);
        Vector2u windowSize = window.getSize(); // get window size
        Vector2u textureSize = homeBackground.getSize(); // get image size
        float scaleX = (1.0f * windowSize.x) / textureSize.x;
        float scaleY = (1.0f * windowSize.y) / textureSize.y;
        background.setScale(scaleX, scaleY); // scale the sprite

        // Initialise buttons 
        enter = new Button(1100,700,120,100,20,this->font,"Generate",Color(199,214,255,200),Color(135,147,176,255),Color(98,115,140,200));

        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event)) {
                // Handle close event
                if (event.type == Event::Closed) {
                    window.close();
                }

                Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                enter->updateButton(mousePos);

                // Transition to reference type page when adelaideUni button is pressed
                if (enter->getButtonState() == true) {
                    curr_reference.firstName = firstNameInput;
                    curr_reference.lastName = lastNameInput;
                    curr_reference.title = titleInput;
                    curr_reference.webName = websiteNameInput;
                    curr_reference.yearPublished = yearPublished;
                    curr_reference.URL = urlInput;
                    curr_reference.yearViewed = yearViewed;
                    curr_reference.monthViewed = monthViewed;
                    curr_reference.dayViewed = dayViewed;

                    if (curr_reference.monthViewed == "1") {
                        curr_reference.monthViewed = "January";
                    }
                    else if (curr_reference.monthViewed == "2") {
                        curr_reference.monthViewed = "February";
                    }
                    else if (curr_reference.monthViewed == "3") {
                        curr_reference.monthViewed = "March";
                    }
                    else if (curr_reference.monthViewed == "4") {
                        curr_reference.monthViewed = "April";
                    }
                    else if (curr_reference.monthViewed == "5") {
                        curr_reference.monthViewed = "May";
                    }
                    else if (curr_reference.monthViewed == "6") {
                        curr_reference.monthViewed = "June";
                    }
                    else if (curr_reference.monthViewed == "7") {
                        curr_reference.monthViewed = "July";
                    }
                    else if (curr_reference.monthViewed == "8") {
                        curr_reference.monthViewed = "August";
                    }
                    else if (curr_reference.monthViewed == "9") {
                        curr_reference.monthViewed = "September";
                    }
                    else if (curr_reference.monthViewed == "10") {
                        curr_reference.monthViewed = "October";
                    }
                    else if (curr_reference.monthViewed == "11") {
                        curr_reference.monthViewed = "November";
                    }
                    else if (curr_reference.monthViewed == "12") {
                        curr_reference.monthViewed = "December";
                    }
                    else {
                        curr_reference.monthViewed = "InvalidMonth";
                    } 

                    if (curr_reference.dayViewed <= "0" || curr_reference.dayViewed >= "32") {
                        curr_reference.dayViewed = "InvalidDay";
                    }

                    String citation = curr_reference.generate();
            
                    window.close();
                    enterPage generatedPage;
                    generatedPage.displayCitation(citation);
                }

                // Handle mouse clicks for selection
                if (event.type == sf::Event::MouseButtonPressed) {
                    Vector2i mousePos = Mouse::getPosition(window);

                    firstNameSelected = firstNameBox.getGlobalBounds().contains(mousePos.x, mousePos.y);
                    lastNameSelected = lastNameBox.getGlobalBounds().contains(mousePos.x, mousePos.y);
                    websiteNameSelected = websiteNameBox.getGlobalBounds().contains(mousePos.x, mousePos.y);
                    urlSelected = urlBox.getGlobalBounds().contains(mousePos.x, mousePos.y);
                    titleSelected = titleBox.getGlobalBounds().contains(mousePos.x, mousePos.y);
                    yearPublishedSelected = yearPublishedBox.getGlobalBounds().contains(mousePos.x, mousePos.y);
                    yearViewedSelected = yearViewedBox.getGlobalBounds().contains(mousePos.x, mousePos.y);
                    monthViewedSelected = monthViewedBox.getGlobalBounds().contains(mousePos.x, mousePos.y);
                    dayViewedSelected = dayViewedBox.getGlobalBounds().contains(mousePos.x, mousePos.y);
                }

                // Handle text input for selected field
                if (event.type == sf::Event::TextEntered) {
                    if (event.text.unicode < 128) { // Only accept ASCII characters
                        if (firstNameSelected) {
                            if (event.text.unicode == 8 && !firstNameInput.isEmpty()) { // Backspace
                                firstNameInput.erase(firstNameInput.getSize() - 1, 1);
                            } else {
                                firstNameInput += event.text.unicode;
                            }
                        }

                        if (lastNameSelected) {
                            if (event.text.unicode == 8 && !lastNameInput.isEmpty()) { // Backspace
                                lastNameInput.erase(lastNameInput.getSize() - 1, 1);
                            } else {
                                lastNameInput += event.text.unicode;
                            }
                        }

                        if (websiteNameSelected) {
                            if (event.text.unicode == 8 && !websiteNameInput.isEmpty()) { // Backspace
                                websiteNameInput.erase(websiteNameInput.getSize() - 1, 1);
                            } else {
                                websiteNameInput += event.text.unicode;
                            }
                        }

                        if (urlSelected) {
                            if (event.text.unicode == 8 && !urlInput.isEmpty()) { // Backspace
                                urlInput.erase(urlInput.getSize() - 1, 1);
                            } else {
                                urlInput += event.text.unicode;
                            }
                        }

                        if (titleSelected) {
                            if (event.text.unicode == 8 && !titleInput.isEmpty()) { // Backspace
                                titleInput.erase(titleInput.getSize() - 1, 1);
                            } else {
                                titleInput += event.text.unicode;
                            }
                        }

                        if (yearPublishedSelected) {
                            if (event.text.unicode == 8 && !yearPublished.isEmpty()) { // Backspace
                                yearPublished.erase(yearPublished.getSize() - 1, 1);
                            } else {
                                yearPublished += event.text.unicode;
                            }
                        }

                        if (yearViewedSelected) {
                            if (event.text.unicode == 8 && !yearViewed.isEmpty()) { // Backspace
                                yearViewed.erase(yearViewed.getSize() - 1, 1);
                            } else {
                                yearViewed += event.text.unicode;
                            }
                        }

                        if (monthViewedSelected) {
                            if (event.text.unicode == 8 && !monthViewed.isEmpty()) { // Backspace
                                monthViewed.erase(monthViewed.getSize() - 1, 1);
                            } else {
                                monthViewed += event.text.unicode;
                            }
                        }

                        if (dayViewedSelected) {
                            if (event.text.unicode == 8 && !dayViewed.isEmpty()) { // Backspace
                                dayViewed.erase(dayViewed.getSize() - 1, 1);
                            } else {
                                dayViewed += event.text.unicode;
                            }
                        }
                    }
                }
            }

            // Clear the window
            window.clear(Color::White);

            // Draw the background, title, text boxes, labels, and current input
            window.draw(background);
            window.draw(title);

            // Draw labels
            window.draw(firstNameLabel);
            window.draw(lastNameLabel);
            window.draw(websiteNameLabel);
            window.draw(urlLabel);
            window.draw(titleLabel);
            window.draw(yearPublishedLabel);
            window.draw(yearViewedLabel);
            window.draw(monthViewedLabel);
            window.draw(dayViewedLabel);

            // Draw text boxes and the input
            window.draw(firstNameBox);
            window.draw(lastNameBox);
            window.draw(websiteNameBox);
            window.draw(urlBox);
            window.draw(titleBox);
            window.draw(yearPublishedBox);
            window.draw(yearViewedBox);
            window.draw(monthViewedBox);
            window.draw(dayViewedBox);

            firstNameText.setString(firstNameInput);
            lastNameText.setString(lastNameInput);
            websiteNameText.setString(websiteNameInput);
            urlText.setString(urlInput);
            titleText.setString(titleInput);
            yearPublishedText.setString(yearPublished);
            yearViewedText.setString(yearViewed);
            monthViewedText.setString(monthViewed);
            dayViewedText.setString(dayViewed);

            window.draw(firstNameText);
            window.draw(lastNameText);
            window.draw(websiteNameText);
            window.draw(urlText);
            window.draw(titleText);
            window.draw(yearPublishedText);
            window.draw(yearViewedText);
            window.draw(monthViewedText);
            window.draw(dayViewedText);

           enter->render(&window);

            // Display everything on the window
            window.display();
        }
    }

    ~WebsiteInput() {delete enter;}
};

#endif
