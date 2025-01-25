#include "generateWebsite.h"
#include <limits>

using namespace std;

string generateWebsite::generate() {

    reference = "" + this->lastName + ", " + (this->firstName)[0] + " " + this->yearPublished + ", " 
    + this->title + ", " + this->webName + ", viewed " + this->dayViewed + " " + this->monthViewed + " " + this->yearViewed + ", <"
    + this->URL + ">.";
    return reference;
    
}


// Author's family name, Initial(s) OR Authoring body Year, Title of webpage (in italics), 
// Title of website, viewed Date Month Year, <URL>.