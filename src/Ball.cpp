#include "../headers/Ball.h"

#include <iostream>

Ball::Ball() {}

Ball::Ball(sf::RectangleShape &shape, sf::Vector2f position, sf::Vector2f size, int windowWidth, int windowHeight) {

    this->m_Ball = shape;

    this->m_Ball.setPosition(position);
    this->m_Ball.setSize(size);

    this->m_Ball.setOutlineColor(sf::Color::Magenta);
    this->m_Ball.setOutlineThickness(-2.f);

    this->m_WindowWidth = windowWidth;
    this->m_WindowHeight = windowHeight;
}

void Ball::Update(float deltaTime) {

    //Side Collision
    if (m_Ball.getPosition().x < 0) {
        m_P2Score++;
        ResetBall();
    } else if (m_Ball.getPosition().x > m_WindowWidth - m_Ball.getSize().x) {
        m_P1Score++;
        ResetBall();
    }

    //Vertical Collision
    if (m_Ball.getPosition().y < 0) {
        m_Velocity.y = -m_Velocity.y;
    } else if (m_Ball.getPosition().y > m_WindowHeight - m_Ball.getSize().y) {
        m_Velocity.y = -m_Velocity.y;
    }

    m_Ball.move(m_Velocity * m_Speed * deltaTime);
}

//COME BACK TO LATER
//GOAL:
//Pause the game for a moment before resetting the ball
//ISSUE:
//When the timer works, the ball does not go to the correct position
//When the timer is disabled, the ball DOES go to the correct position
void Ball::ResetBall() {
    /*
    this->m_Timer = m_Clock.getElapsedTime().asSeconds();

    while (m_Timer >= m_Countdown) {
        m_Countdown--;
    }

    //Reset Parameters
    m_Countdown = 2;
    m_Clock.restart();
    */

    m_Ball.setPosition(m_DefaultPosition);
    std::cout << "Ball Reset" << std::endl;
    m_Speed = m_DefaultSpeed;
}