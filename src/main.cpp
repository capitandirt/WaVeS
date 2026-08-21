#include <raylib.h>
#include <stdint.h>
#include <iostream>
#include <screen.h>
#include <Wave.h>

int main()
{
    std::cout <<"booted";
    // Initialization
    //-
    const int screenWidth = 1200;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "waves");


    Screen screen(screenWidth, screenHeight);
    WaveDriver waves(screen);

    SetTargetFPS(120);
    std::cout <<"main inited\n";
    waves.createPlate(screenWidth, screenHeight);
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        BeginDrawing();
        if(IsKeyPressed(KEY_ENTER))
        {
            waves.clear();
            std::cout << "waves cleared\n";
        }
        static double mouseStartTime = 0;
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) || IsKeyDown(KEY_SPACE))
        {
            Vector2 mouse = GetMousePosition();
            IntVec intMouse = {(int)mouse.x, (int)mouse.y};
            std::cout <<"coord: " << intMouse.x << " " << intMouse.y << "\n";
            waves.setDotAmplitude(intMouse, 2048*sin((GetTime() - mouseStartTime) / 2 * PI));
        }
        else mouseStartTime = GetTime();
        if(IsKeyDown(KEY_LEFT_SHIFT))
        {
            static double t0 = GetTime();
            waves.setDotAmplitude({0, 0}, 2048*sin((GetTime() - t0) * PI));
        }
        // mathSpace.clear(RED);
        // std::cout <<"IMHERE12\n";
        // Update
        //----------------draw--------------------------------------------------------------
        ClearBackground(BLACK);
        waves.update();
        waves.draw();

        DrawFPS(10, 10);
        DrawText("hold left mouse button to create a wave source in point of mouse", 10, 50, 20, WHITE);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
   
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}