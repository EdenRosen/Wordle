#include <iostream>
#include <string>
#include "raylib.h"

using namespace std;

int main(void)
{
    const int screenWidth = 700;
    const int screenHeight = 700;
    InitWindow(screenWidth, screenHeight, "Flight Simulator");
    SetTargetFPS(1);

    const int boardMargin = 15;
    const int margin = 8;
    const int squareSize = (screenWidth-margin*4-boardMargin*2)/5;
    char letters[5][5] = {"","","","",""};
    int index[2] = {0, 0};

    Font font1 = LoadFont("../resources/fonts/font1.png");
    
    while (!WindowShouldClose())
    {
        int key = GetCharPressed();
        if (key > 0) {
            cout<<key<<endl;
            letters[index[1]][index[0]] = (char)key;
            index[0]++;
            if (index[0] > 4) {
                index[0] = 0;
                index[1]++;
                if (index[1] > 4) {
                    index[1] = 0;
                }
            }
        }

        BeginDrawing();
            ClearBackground(BLACK);


            for (int y = 0; y < 5; y++) {
                for (int x = 0; x < 5; x++) {
                    const int jump  = margin+squareSize;
                    const int posx = boardMargin + jump*x;
                    const int posy = boardMargin + jump*y;
                    DrawRectangle(posx, posy, squareSize, squareSize, DARKGRAY);
                    char l = ' ';
                    if (y < index[1] || (y == index[1] && x <= index[0])) {
                        l = letters[y][x];
                    }
                    char s[] = {l};
                    if (l != ' ') {
                        Vector2 pos;
                        pos.x = posx+35;
                        pos.y = posy+25;
                        cout<<s<<endl;
                        DrawTextEx(font1, s, pos , 90, 0, WHITE);
                    }
                }
            }
            



        EndDrawing();
    }
    CloseWindow();

    return 0;
}