#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <iostream>
sf::RenderWindow wnd(sf::VideoMode(sf::VideoMode::getDesktopMode()),"move test",sf::State::Fullscreen);
//constance
const size_t FPS =  60;
const float deltaT = static_cast<float>(1/FPS);
//
/// @brief that circle move while 
/// @tparam number that number type of that
template <typename number = float>
struct moveShape
{
    private:
    //speed var that dervative position by time
    sf::Vector2<number>(*speed)(moveShape,float);
    //that M0(x,y) that default position
    sf::Vector2<number> position;
    //
    void(*shape)(moveShape);
    public:
    //
    sf::Vector2<number> getPosition(){return position;}
    /// @brief that constractor of default 
    /// @param speed speed var that dervative position by time
    /// @param defaultPosition that M0(x,y) that default position
    moveShape(sf::Vector2<number>(*speed)(moveShape,float),sf::Vector2<number> defaultPosition,void(*shape)(moveShape))
    { 
        //set speed shape 
        this->speed  =  speed;
        //set default position  shape
        position  =  defaultPosition;
        //set shape  move
        this->shape = shape;
    }
    /// @brief that function edit position
    /// @param t that time of subject
    void move(number t){position.x+=speed(*this,t).x;position.y+=speed(*this,t).y;} 
    /// @brief thtat function draww self with pos
    void draw(){shape(*this);}
};
sf::Time t; 

std::vector<moveShape<float>> shapes ={moveShape<float>([](moveShape<float> self,float t){return sf::Vector2f(5*sin(t),cos(t));},sf::Vector2f(250,240),[](moveShape<float> self)
    {
        sf::CircleShape l(34);
        l.setPosition(self.getPosition());
        l.setFillColor(sf::Color::Green);
        wnd.draw(l);
    }
)
, 
moveShape<float>([](moveShape<float> self,float t){ return sf::Vector2f(sqrt(t),std::tan(t));},sf::Vector2f(250,240),[](moveShape<float> self)
    {
        sf::CircleShape l(34);
        l.setPosition(self.getPosition());
        l.setFillColor(sf::Color::Yellow);
        wnd.draw(l);
    }
)
};