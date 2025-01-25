#include "generateWebsite.cpp"
#include "generateWebsite.h"
#include "generateVideo.h"
#include "generateVideo.cpp"
#include "generateImage.h"
#include "generateImage.cpp"
#include "generateArticle.h"
#include "generateArticle.cpp"

int main() {
    generateArticle site;
    site.generate();
    return 0;
}