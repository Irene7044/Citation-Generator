#pragma once
#include "generateWebsite.h"

using namespace std;

string generateWebsite::generate() {
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

    cout << "Website name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::getline(cin, this->webName); 


    reference = "" + this->lastName + ", " + (this->firstName)[0] + " " + this->yearPublished + ", " 
    + this->title + ", " + this->webName + ", viewed " + this->dayViewed + " " + this->monthViewed + " " + this->yearViewed + ", <"
    + this->URL + ">.";
    cout << reference << endl;
    return reference;
    
}


// Author's family name, Initial(s) OR Authoring body Year, Title of webpage (in italics), 
// Title of website, viewed Date Month Year, <URL>.