#include "../headers/GamePanel.h"
#include <iostream>

GamePanel::GamePanel() {

    InitVariables();
    InitWindow();
    InitEntities();
    InitText();
}

GamePanel::~GamePanel() {

    delete this->m_Window;
}

void GamePanel::InitVariables() {

    this->m_Window = nullptr;
}

void GamePanel::InitWindow() {

    this->m_VideoMode.size.x = m_WindowWidth;
    this->m_VideoMode.size.y = m_WindowHeight;

    this->m_Window = new sf::RenderWindow(this->m_VideoMode, this->m_WindowTitle);
    this->m_Window->setFramerateLimit(60);
}

void GamePanel::InitEntities() {

    ball = Ball(ball.m_Ball, sf::Vector2f(500, 0), sf::Vector2f(32, 32), m_WindowWidth, m_WindowHeight);

    playerOne = Player(playerOne.m_Paddle, sf::Vector2f(32, 128), sf::Vector2f(128, 256), m_WindowWidth, m_WindowHeight);
    playerOne.m_Paddle.setOutlineColor(sf::Color::Blue);
    playerOne.m_Paddle.setOutlineThickness(-2);

    playerTwo = Player(playerTwo.m_Paddle, sf::Vector2f(32, 128), sf::Vector2f(1152, 256), m_WindowWidth, m_WindowHeight);
    playerTwo.m_Paddle.setOutlineColor(sf::Color::Red);
    playerTwo.m_Paddle.setOutlineThickness(-2);
}

void GamePanel::InitText() {

    this->m_Font.openFromFile("../res/Fonts/HydrogenWhiskey.otf");

    this->m_P1Score.setFont(this->m_Font);
    this->m_P1Score.setCharacterSize(64);
    this->m_P1Score.setPosition(sf::Vector2f(m_WindowWidth/5, 32));

    this->m_P2Score.setFont(this->m_Font);
    this->m_P2Score.setCharacterSize(64);
    this->m_P2Score.setPosition(sf::Vector2f(m_WindowWidth - 384, 32));
}

const bool GamePanel::Running() const {

    return this->m_Window->isOpen();
}

void GamePanel::Update() {

    deltaTime = clock.restart().asSeconds();

    //PLAYER ONE CONTROLS
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        playerOne.m_MoveUp = true;
    } else {
        playerOne.m_MoveUp = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        playerOne.m_MoveDown = true;
    } else {
        playerOne.m_MoveDown = false;
    }

    //PLAYER TWO CONTROLS
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        playerTwo.m_MoveUp = true;
    } else {
        playerTwo.m_MoveUp = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        playerTwo.m_MoveDown = true;
    } else {
        playerTwo.m_MoveDown = false;
    }

    //BALL + PADDLE COLLISION
    ballBounds = ball.m_Ball.getGlobalBounds();
    playerOneBounds = playerOne.m_Paddle.getGlobalBounds();
    playerTwoBounds = playerTwo.m_Paddle.getGlobalBounds();

    if (playerOneBounds.findIntersection(ballBounds) || playerTwoBounds.findIntersection(ballBounds)) {
        ball.m_Velocity.x *= -1;
        ball.m_Speed += 10.f;
        std::cout << "Ball speed increased to: " << ball.m_Speed << std::endl;
    }

    //UPDATE SCORE TEXT
    this->m_P1Score.setString("P1: " + std::to_string(ball.m_P1Score));
    this->m_P2Score.setString("P2: " + std::to_string(ball.m_P2Score));

    //CLOSE CONDITION
    while (const std::optional event = this->m_Window->pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            this->m_Window->close();
        }
    }

    //UPDATE ENTITIES
    ball.Update(deltaTime);
    playerOne.Update(deltaTime);
    playerTwo.Update(deltaTime);
}

void GamePanel::Draw() {

    this->m_Window->clear();

    //DRAW OBJECTS TO SCREEN
    this->m_Window->draw(ball.m_Ball);
    this->m_Window->draw(playerOne.m_Paddle);
    this->m_Window->draw(playerTwo.m_Paddle);

    this->m_Window->draw(this->m_P1Score);
    this->m_Window->draw(this->m_P2Score);

    this->m_Window->display();
}