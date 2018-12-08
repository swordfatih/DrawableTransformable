#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

int main()
{
    sf::RenderWindow window({940, 480}, "Window");

    std::vector<std::shared_ptr<sf::Drawable>> objects;

    objects.push_back(std::make_shared<sf::CircleShape>(30));

    std::dynamic_pointer_cast<sf::Transformable>(objects[0])->setPosition(50, 50);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        for(auto& it: objects)
        {
            window.draw(*it);
        }
        window.display();
    }

    return 0;
}
