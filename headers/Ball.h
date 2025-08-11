#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>

class Ball {

private:

    int m_WindowWidth = 0;
    int m_WindowHeight = 0;

    sf::Clock m_Clock;
    int m_Countdown = 2;
    int m_Timer;

    float m_DefaultSpeed = 200.f;

public:

    float m_Speed = m_DefaultSpeed;
    int m_P1Score = 0;
    int m_P2Score = 0;

    sf::Vector2f m_DefaultPosition = {640.f, 0.f};
    sf::Vector2f m_StartVelocity = {1.f, 1.f};

    sf::Vector2f m_Velocity = m_StartVelocity;

    sf::RectangleShape m_Ball;

    Ball();
    Ball(sf::RectangleShape& shape, sf::Vector2f position, sf::Vector2f size, int windowWidth, int windowHeight);

    void Update(float deltaTime);
    void ResetBall();
};
#endif //BALL_H