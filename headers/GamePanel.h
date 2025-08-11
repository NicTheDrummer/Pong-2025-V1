#ifndef GAMEPANEL_H
#define GAMEPANEL_H
#include <SFML/Graphics.hpp>
#include "../headers/Ball.h"
#include "../headers/Player.h"

class GamePanel {

private:

    unsigned int m_WindowWidth = 1280;
    unsigned int m_WindowHeight = 720;

    sf::RenderWindow* m_Window;
    sf::VideoMode m_VideoMode;

    Ball ball;

    Player playerOne;
    Player playerTwo;

    sf::FloatRect ballBounds;
    sf::FloatRect playerOneBounds;
    sf::FloatRect playerTwoBounds;

    const char* m_WindowTitle = "Pong";
    const char* m_DefaultString;

    void InitVariables();
    void InitWindow();
    void InitEntities();
    void InitText();

public:

    sf::Font m_Font;
    sf::Text m_P1Score = sf::Text(m_Font, m_DefaultString);
    sf::Text m_P2Score = sf::Text(m_Font, m_DefaultString);

    sf::Clock clock;

    float deltaTime;

    GamePanel();
    ~GamePanel();

    const bool Running() const;

    void Update();
    void Draw();
};

#endif //GAMEPANEL_H