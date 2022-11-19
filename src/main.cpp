#include "pch.h"
#include "utils/GameTimer.h"
#include "client/Engine.h"
#include "Game.h"
#include "client/graphics/Vulkan/VulkanContext.h"

// Nobody is forgotten, nothing is forgotten

// D.E.L.E.T.E.D
// summonDestructor3000 
// 2021-2021
// Rest in peace

int main()
{
    // Create a window
    auto &window = Engine::getWindow("TRUE RPG");

    VulkanContext context;
    context.init();
    context.destroy();

    auto &graphicsContext = Engine::getGraphicsContext();
    graphicsContext.init();

    Game game;

    GameTimer time(0.0f, 0.0f, 0.0f);

    while (window.isOpen())
    {
        game.update(time.getDeltaTime());
        graphicsContext.swapBuffers();
        window.pollEvents();
    }

    game.destroy();
    graphicsContext.destroy();
    window.destroy();

    return 0;
}
