#pragma once
#include "generateVideo.h"

using namespace std;

string generateVideo::generate() {
    cout << "First name: ";
    cin >> this->firstName;

    cout << "Last name: ";
    cin >> this->lastName;  

    cout << "Title: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::getline(cin, this->title); 
    this->title = "\033[3m" + this->title + "\033[0m";

    cout << "Year published: ";
    cin >> this->yearPublished;
    if (this->yearPublished == "") {
        this->yearPublished = "n.d.";
    }

    cout << "Month published: ";
    cin >> this->monthPublished;
        if (this->monthPublished == "1") {
            this->monthPublished = "January";
        }
        else if (this->monthPublished == "2") {
            this->monthPublished = "February";
        }
        else if (this->monthPublished == "3") {
            this->monthPublished = "March";
        }
        else if (this->monthPublished == "4") {
            this->monthPublished = "April";
        }
        else if (this->monthPublished == "5") {
            this->monthPublished = "May";
        }
        else if (this->monthPublished == "6") {
            this->monthPublished = "June";
        }
        else if (this->monthPublished == "7") {
            this->monthPublished = "July";
        }
        else if (this->monthPublished == "8") {
            this->monthPublished = "August";
        }
        else if (this->monthPublished == "9") {
            this->monthPublished = "September";
        }
        else if (this->monthPublished == "10") {
            this->monthPublished = "October";
        }
        else if (this->monthPublished == "11") {
            this->monthPublished = "November";
        }
        else if (this->monthPublished == "12") {
            this->monthPublished = "December";
        }
        else {
            this->monthPublished = "InvalidMonth";
        } 
    

    cout << "Day published: ";
    cin >> this->dayPublished;
    if (this->dayPublished <= "0" || this->dayPublished >= "32") {
        this->dayPublished = "InvalidDay";
    }


    cout << "URL: ";
    cin >> this->URL;

    cout << "Year viewed: ";
    cin >> this->yearViewed;

    cout << "Month viewed: ";
    cin >> this->monthViewed;
        if (this->monthViewed == "1") {
            this->monthViewed = "January";
        }
        else if (this->monthViewed == "2") {
            this->monthViewed = "February";
        }
        else if (this->monthViewed == "3") {
            this->monthViewed = "March";
        }
        else if (this->monthViewed == "4") {
            this->monthViewed = "April";
        }
        else if (this->monthViewed == "5") {
            this->monthViewed = "May";
        }
        else if (this->monthViewed == "6") {
            this->monthViewed = "June";
        }
        else if (this->monthViewed == "7") {
            this->monthViewed = "July";
        }
        else if (this->monthViewed == "8") {
            this->monthViewed = "August";
        }
        else if (this->monthViewed == "9") {
            this->monthViewed = "September";
        }
        else if (this->monthViewed == "10") {
            this->monthViewed = "October";
        }
        else if (this->monthViewed == "11") {
            this->monthViewed = "November";
        }
        else if (this->monthViewed == "12") {
            this->monthViewed = "December";
        }
        else {
            this->monthViewed = "InvalidMonth";
        } 
    

    cout << "Day viewed: ";
    cin >> this->dayViewed;
    if (this->dayViewed <= "0" || this->dayViewed >= "32") {
        this->dayViewed = "InvalidDay";
    }

    reference = "" + this->lastName + ", " + (this->firstName)[0] + " " + this->yearPublished + ", " 
    + this->title + ", YouTube, " + this->dayPublished + " " + this->monthPublished + ", viewed " + this->dayViewed + " " + this->monthViewed + " " + this->yearViewed + ", <"
    + this->URL + ">.";
    cout << reference << endl;
    return reference;
    
}

