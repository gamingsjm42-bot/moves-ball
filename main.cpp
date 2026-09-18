
#include "moveShape.cpp"
#include <iostream>
//set shapes 
int main()
{ 
    sf::Clock clk;
    //set time vars
    //set infinit while loop
    while (wnd.isOpen())
    {
        //set event
        while (std::optional event =wnd.pollEvent())
        {
            //set close event
            if(event->is<sf::Event::Closed>()) wnd.close();
        }
        //set
        t=clk.getElapsedTime();
        //set fps
        wnd.setFramerateLimit(FPS); 
        //
        for (auto shape =shapes.begin() ; shape !=shapes.end(); shape++)
        {
            shape->move(t.asSeconds());
            shape->draw();
        }
        
        //set image
        //display wnd
        wnd.display();
        wnd.clear(sf::Color::Red);
         //compare
    }
    
}