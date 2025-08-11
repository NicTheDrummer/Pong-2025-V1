#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

class Player {

public:

    sf::RectangleShape m_Paddle;
    float m_Speed = 20.f;
    float m_YVelocity = 0;

    bool m_MoveUp = false;
    bool m_MoveDown = false;

    Player();
    Player(sf::RectangleShape &paddle, sf::Vector2f size, sf::Vector2f position, int windowWidth, int windowHeight);

    void Update(float deltaTime);
private:

    int m_WindowWidth = 0;
    int m_WindowHeight = 0;
};
#endif //PLAYER_H