#include <iostream>
#include <sstream>
#include <cmath>

#include <CMUgraphics.h>

using namespace std;

int grid[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

int Detect()
{
    bool won = false;
    // Diagonal
    if(grid[0] == 1 && grid[4] == 1 && grid[8] == 1)
    {
        // X Wins
        won = true;
        return 1;
    }
    else if(grid[2] == 2 && grid[4] == 2 && grid[6] == 2)
    {
        // O Wins
        won = true;
        return 2;
    }

    // Horizontal
    for(int i=0; i<=6; i+=3)
    {
        if(grid[i] == 1 && grid[i+1] == 1 && grid[i+2] == 1)
        {
            // X Wins
            won = true;
            return 1;
        }
        else if(grid[i] == 2 && grid[i+1] == 2 && grid[i+2] == 2)
        {
            // O Wins
            won = true;
            return 2;
        }
    }

    // Vertical
    for(int x=0; x<3; x++)
    {
        if(grid[x] == 1 && grid[x+3] == 1 && grid[x+6] == 1)
        {
            // X Wins
            won = true;
            return 1;
        }
        else if(grid[x] == 2 && grid[x+3] == 2 && grid[x+6] == 2)
        {
            // O Wins
            won = true;
            return 2;
        }
    }

    // Check All
    if(grid[0] > 0 && grid[1] > 0 && grid[2] > 0 && grid[3] > 0 && grid[4] > 0 && grid[5] > 0 && grid[6] > 0 && grid[7] > 0 && grid[8] > 0 && won == false)
    {
        // Tie
        return 3;
    }
    else
    {
        return 0;
    }
}

void printGrid(window &gameWindow)
{
    ostringstream o0, o1, o2, o3, o4, o5, o6, o7, o8;
    gameWindow.SetPen(WHITE);
    gameWindow.SetFont(82, PLAIN, BY_NAME, "Arial");
    // Row 1
    if(grid[0] == 1)
    {
        o0 << "X";
        gameWindow.DrawString(120, 46, o0.str());
    }
    else if(grid[0] == 2)
    {
        o0 << "O";
        gameWindow.DrawString(120, 46, o0.str());
    }
    if(grid[1] == 1)
    {
        o1 << "X";
        gameWindow.DrawString(231, 46, o1.str());
    }
    else if(grid[1] == 2)
    {
        o1 << "O";
        gameWindow.DrawString(231, 46, o1.str());
    }
    if(grid[2] == 1)
    {
        o2 << "X";
        gameWindow.DrawString(339, 46, o2.str());
    }
    else if(grid[2] == 2)
    {
        o2 << "O";
        gameWindow.DrawString(339, 46, o2.str());
    }

    // Row 2
    if(grid[3] == 1)
    {
        o3 << "X";
        gameWindow.DrawString(120, 157, o3.str());
    }
    else if(grid[3] == 2)
    {
        o3 << "O";
        gameWindow.DrawString(120, 157, o3.str());
    }
    if(grid[4] == 1)
    {
        o4 << "X";
        gameWindow.DrawString(231, 157, o4.str());
    }
    else if(grid[4] == 2)
    {
        o4 << "O";
        gameWindow.DrawString(231, 157, o4.str());
    }
    if(grid[5] == 1)
    {
        o5 << "X";
        gameWindow.DrawString(339, 157, o5.str());
    }
    else if(grid[5] == 2)
    {
        o5 << "O";
        gameWindow.DrawString(339, 157, o5.str());
    }

    // Row 3
    if(grid[6] == 1)
    {
        o6 << "X";
        gameWindow.DrawString(120, 265, o6.str());
    }
    else if(grid[6] == 2)
    {
        o6 << "O";
        gameWindow.DrawString(120, 265, o6.str());
    }
    if(grid[7] == 1)
    {
        o7 << "X";
        gameWindow.DrawString(231, 265, o7.str());
    }
    else if(grid[7] == 2)
    {
        o7 << "O";
        gameWindow.DrawString(231, 265, o7.str());
    }
    if(grid[8] == 1)
    {
        o8 << "X";
        gameWindow.DrawString(339, 265, o8.str());
    }
    else if(grid[8] == 2)
    {
        o8 << "O";
        gameWindow.DrawString(339, 265, o8.str());
    }
}

// Function to wait for a mouse click and clear the screen
void WaitNClear(window &inputWindow);

int main()
{
    int iX, iY;
    bool player1 = true, playing = true;
    
    window gameWindow(500, 500, 5, 5);

    // Change the window title to something different
    gameWindow.ChangeTitle("Based Tic-tac-toe");
    
    gameWindow.SetPen(BLACK);
    gameWindow.SetFont(16, BOLD, SWISS);
    gameWindow.DrawString(gameWindow.GetWidth()/2 - 100, gameWindow.GetHeight() - 25, "Click mouse to continue...");
    WaitNClear(gameWindow);
    
    // -- Title Screen --

    image startImage("images\\Start.png", PNG);
    gameWindow.DrawImage(startImage, 0, 0);
    
    // Wait for a mouse click and clear the window
    WaitNClear(gameWindow);
    
    image gameImage("images\\Game.png", PNG);
    gameWindow.DrawImage(gameImage, 0, 0);

    gameWindow.SetBuffering(true);
    
    bool bQuit = false;
    keytype ktInput;
    clicktype ctInput;
    char cKeyData;
    
    gameWindow.FlushMouseQueue();
    gameWindow.FlushKeyQueue();

    gameWindow.SetFont(32, BOLD, BY_NAME, "Arial");

    do
    {
        // Draws instructions
        gameWindow.DrawImage(gameImage, 0, 0);
        gameWindow.SetPen(WHITE);   
        ktInput = gameWindow.GetKeyPress(cKeyData);
        ctInput = gameWindow.GetMouseClick(iX, iY);

        if(player1)
        {
            gameWindow.SetPen(RED, 2);    
            gameWindow.DrawRectangle(169, 383, 329, 433, FRAME);
        }
        else
        {
            gameWindow.SetPen(RED, 2);    
            gameWindow.DrawRectangle(169, 433, 329, 473, FRAME);
        }

        printGrid(gameWindow);

        // Update the screen buffer
        gameWindow.UpdateBuffer();

        bool trip = false;
  
        if(ctInput == LEFT_CLICK) {

            // Row 1
            if(iX > 90 && iX < 196 && iY > 36 && iY < 142)
            {
                if(player1 && grid[0] == 0)
                {
                    grid[0] = 1;
                    trip = true;
                }
                else if(player1 != true && grid[0] == 0)
                {
                    grid[0] = 2;
                    trip = true;
                }
            }
            if(iX > 201 && iX < 312 && iY > 36 && iY < 142)
            {
                if(player1 && grid[1] == 0)
                {
                    grid[1] = 1;
                    trip = true;
                }
                else if(player1 != true && grid[1] == 0)
                {
                    grid[1] = 2;
                    trip = true;
                }
            }
            if(iX > 309 && iX < 415 && iY > 36 && iY < 142)
            {
                if(player1 && grid[2] == 0)
                {
                    grid[2] = 1;
                    trip = true;
                }
                else if(player1 != true && grid[2] == 0)
                {
                    grid[2] = 2;
                    trip = true;
                }
            }

            //Row 2
            if(iX > 90 && iX < 196 && iY > 147 && iY < 253)
            {
                if(player1 && grid[3] == 0)
                {
                    grid[3] = 1;
                    trip = true;
                }
                else if(player1 != true && grid[3] == 0)
                {
                    grid[3] = 2;
                    trip = true;
                }
            }
            if(iX > 201 && iX < 312 && iY > 147 && iY < 253)
            {
                if(player1 && grid[4] == 0)
                {
                    grid[4] = 1;
                    trip = true;
                }
                else if(player1 != true && grid[4] == 0)
                {
                    grid[4] = 2;
                    trip = true;
                }
            }
            if(iX > 309 && iX < 415 && iY > 147 && iY < 253)
            {
                if(player1 && grid[5] == 0)
                {
                    grid[5] = 1;
                    trip = true;
                }
                else if(player1 != true && grid[5] == 0)
                {
                    grid[5] = 2;
                    trip = true;
                }
            }

            // Row 3
            if(iX > 90 && iX < 196 && iY > 255 && iY < 361)
            {
                if(player1 && grid[6] == 0)
                {
                    grid[6] = 1;
                    trip = true;
                }
                else if(player1 != true && grid[6] == 0)
                {
                    grid[6] = 2;
                    trip = true;
                }
            }
            if(iX > 201 && iX < 312 && iY > 255 && iY < 361)
            {
                if(player1 && grid[7] == 0)
                {
                    grid[7] = 1;
                    trip = true;
                }
                else if(player1 != true && grid[7] == 0)
                {
                    grid[7] = 2;
                    trip = true;
                }
            }
            if(iX > 309 && iX < 415 && iY > 255 && iY < 361)
            {
                if(player1 && grid[8] == 0)
                {
                    grid[8] = 1;
                    trip = true;
                }
                else if(player1 != true && grid[8] == 0)
                {
                    grid[8] = 2;
                    trip = true;
                }
            }
        }

        if(Detect() == 1 || Detect() == 2)
        {
            playing = false;
            bQuit = true;
        }
        else if(Detect() == 3)
        {
            playing = false;
            bQuit = true;
        }

        if(playing)
        {
            gameWindow.UpdateBuffer();  
            if(player1 == true && trip == true)
            {
                player1 = false;
            }
            else if (player1 != true && trip == true)
            {
                player1 = true;
            }
			Pause(250);
        }

    } while(bQuit != true);

    gameWindow.SetBuffering(false);

    if(Detect() == 1)
    {
        image end1Image("images\\End1.png", PNG);
        gameWindow.DrawImage(end1Image, 0, 0);
    }
    else if(Detect() == 2)
    {
        image end2Image("images\\End2.png", PNG);
        gameWindow.DrawImage(end2Image, 0, 0);
    }
    else
    {
        image end3Image("images\\End3.png", PNG);
        gameWindow.DrawImage(end3Image, 0, 0);
    }
     
	return 0;
}

void WaitNClear(window &inputWindow)
{
 int iX, iY;

    // Flush the mouse queue
    inputWindow.FlushMouseQueue();
    // Ignore return value since we don't care what type of click it was
    inputWindow.WaitMouseClick(iX, iY);
    // Set the brush and pen white so we can clear the background
    inputWindow.SetPen(WHITE, 0);    
    inputWindow.SetBrush(WHITE);
    // Draw a rectangle that covers the entire window
    inputWindow.DrawRectangle(0, 0, inputWindow.GetWidth(), inputWindow.GetHeight());
}