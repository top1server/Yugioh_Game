#include "MenuGame.h"
int main(int argc, char* argv[])
{
    MenuGame menuGame;
    menuGame.InitiationMenu();

    while (1)
    {
        menuGame.HandleInput();
        menuGame.Render();
    }

    return 0;
}