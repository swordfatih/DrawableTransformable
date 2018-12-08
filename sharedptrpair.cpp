#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

using Drawable = std::shared_ptr<sf::Drawable>; 
using Transformable = std::shared_ptr<sf::Transformable>;
using drawableTransformable = std::pair<Drawable, Transformable>;

int main()
{
    sf::RenderWindow window({940, 480}, "Window");

    std::vector<drawableTransformable> objects;

    auto shape = std::make_shared<sf::CircleShape>(30);
    objects.push_back(drawableTransformable(shape, shape));

    std::get<Transformable>(objects[0])->setPosition(50, 50);

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
            window.draw(*std::get<Drawable>(it));
        }
        window.display();
    }

    return 0;
}
