#include "generateWebsite.cpp"
#include "generateWebsite.hpp"
#include "generateVideo.hpp"
#include "generateVideo.cpp"
#include "generateImage.hpp"
#include "generateImage.cpp"
#include "generateArticle.hpp"
#include "generateArticle.cpp"

int main() {
    generateArticle site;
    site.generate();
    return 0;
}