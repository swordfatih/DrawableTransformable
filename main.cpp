#include <SFML/Graphics.hpp>
#include <vector>

using drawableTransformable = std::pair<sf::Drawable*, sf::Transformable*>;

int main()
{
    sf::RenderWindow window({940, 480}, "Window");

    std::vector<drawableTransformable> objects;

    sf::CircleShape shape(40);
    objects.push_back(drawableTransformable(&shape, &shape));

    std::get<sf::Transformable*>(objects[0])->setPosition(50, 50);

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
            window.draw(*std::get<sf::Drawable*>(it));
        }
        window.display();
    }

    return 0;
}
