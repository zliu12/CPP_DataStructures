//
// Created by toast on 4/5/2021.
//

#include "Fonts.h"
sf::Font Fonts::font;
bool Fonts::fontload = false;
void Fonts::loadFont()
{
    if (!fontload)
    {
        if (!font.loadFromFile("OpenSans-Bold.ttf"))
        {
            std::cout << "It's not working!!\n";
            system("pause");
            fontload = true;

        }
    }
}

sf::Font& Fonts::getFont()
{
    loadFont();
    return font;
}