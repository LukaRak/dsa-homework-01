#include <SFML/Graphics.hpp>
#include<iostream>
#include<vector>

class Flower
{
    float a;
    float b;
public:
    void set_a(float x)
    {
        this->a = x;
    }

    void set_b(float x)
    {
        this->b = x;
    }

    float get_a()
    {
        return a;
    }
    float get_b()
    {
        return b;
    }
};

int main()
{
    Flower f;
    float temp;

    std::cout << "Enter the paramaters for the window in which the picture will be (at least 100.f):" << std::endl;
    std::cout << "1. ";
    std::cin >> temp;
    f.set_a(temp);
    std::cout << "2. ";
    std::cin >> temp;
    f.set_b(temp);

    float a = f.get_a();
    float b = f.get_b();
    
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(a,b)), "SFML works!");
    sf::CircleShape shape(40.f);
    shape.setFillColor(sf::Color::Yellow);
    shape.setOutlineColor(sf::Color::Red);
    shape.setOutlineThickness(20);
    shape.setPosition({ 210.f , 120.f });

    sf::RectangleShape stem({ 10.f, 100.f });
    stem.setFillColor(sf::Color::Green);
    stem.setPosition({ 245.f,220.f });

    sf::ConvexShape leaf;
    leaf.setPointCount(3);
    leaf.setPoint(0, { 250.f,255.f });
    leaf.setPoint(1, { 290.f,300.f });
    leaf.setPoint(2, { 330.f,290.f });
    leaf.setFillColor(sf::Color::Green);
    

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.draw(stem);
        window.draw(leaf);
        window.display();
    }
    return 0;
}