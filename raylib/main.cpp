#include <raylib.h>
int main(){
    const int screenWidth = 1280;
    const int screenHeight = 720;
    
    InitWindow(screenWidth, screenHeight, "basic window");
    
    Vector2 BallPosition = {640, 350};
    HideCursor();
    float BallRadius = 50.0;
    Color ballColor = RED;
    bool MouseControl = false;

    SetTargetFPS(60);

    while(!WindowShouldClose()){
        if(IsKeyPressed(KEY_H)){
            if(IsCursorHidden()) {
                ShowCursor();
                MouseControl = true;
            }
            else {
                HideCursor();
                MouseControl = false;
            }
        }
        if(MouseControl == true) BallPosition = GetMousePosition();
        else {
            if (IsKeyDown(KEY_RIGHT)) BallPosition.x += 6;
            if (IsKeyDown(KEY_LEFT)) BallPosition.x -= 6;
            if (IsKeyDown(KEY_UP)) BallPosition.y -= 6;
            if (IsKeyDown(KEY_DOWN)) BallPosition.y += 6;
        }
        
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) ballColor = RED;
        if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) ballColor = BLUE;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle(BallPosition.x, BallPosition.y, BallRadius, ballColor);
        DrawText("\"H\" changes the controller (mouse/rows) \nLeft click will make circle red, and right click to blue \n", 705, 640, 20, BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
