#include "../headers/Player.h"

Player::Player(){}

Player::Player(sf::RectangleShape &paddle, sf::Vector2f size, sf::Vector2f position, int windowWidth, int windowHeight){

    this->m_Paddle = paddle;
    this->m_Paddle.setPosition(position);
    this->m_Paddle.setSize(size);

    this->m_WindowWidth = windowWidth;
    this->m_WindowHeight = windowHeight;
}

void Player::Update(float deltaTime){

    if(m_MoveUp == true){
        m_YVelocity = -m_Speed;
    }else if(m_MoveDown == true){
        m_YVelocity = m_Speed;
    } else {
        m_YVelocity = 0;
    }

    m_Paddle.move(sf::Vector2f(0.0f, m_YVelocity) * m_Speed * deltaTime);

    //Screen Bounds
    if(m_Paddle.getPosition().y < 0){
        m_Paddle.setPosition(sf::Vector2f(m_Paddle.getPosition().x, 0));
    } else if (m_Paddle.getPosition().y > m_WindowHeight - m_Paddle.getSize().y){
        m_Paddle.setPosition(sf::Vector2f(m_Paddle.getPosition().x, m_WindowHeight - m_Paddle.getGlobalBounds().size.y));
    }
}