#include "../headers/GamePanel.h"
#include <iostream>

int main() {

    GamePanel gamePanel;

    std::cout << "Running Pong!" << std::endl;

    while (gamePanel.Running()) {

        gamePanel.Update();
        gamePanel.Draw();
    }
}