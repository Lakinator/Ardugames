#include <Arduboy2.h>

#define TILE_SIZE 16

Arduboy2 arduboy;

const char tile_bmp[] PROGMEM = {
    0x00,
    0xfe,
    0x02,
    0x02,
    0x02,
    0x02,
    0x02,
    0x02,
    0x02,
    0x02,
    0x02,
    0x02,
    0x02,
    0x02,
    0xfe,
    0x00,
    0x00,
    0x7f,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x40,
    0x7f,
    0x00,
};

const char cursor_bmp[] PROGMEM = {
    0x00,
    0x8e,
    0x02,
    0x02,
    0x00,
    0x00,
    0x00,
    0x02,
    0x02,
    0x00,
    0x00,
    0x00,
    0x02,
    0x02,
    0x8e,
    0x00,
    0x00,
    0x71,
    0x40,
    0x40,
    0x00,
    0x00,
    0x00,
    0x40,
    0x40,
    0x00,
    0x00,
    0x00,
    0x40,
    0x40,
    0x71,
    0x00,
};

const char circle_bmp[] PROGMEM = {
    0x00,
    0x00,
    0x00,
    0xc0,
    0x20,
    0x10,
    0x08,
    0x08,
    0x08,
    0x08,
    0x10,
    0x20,
    0xc0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x03,
    0x04,
    0x08,
    0x10,
    0x10,
    0x10,
    0x10,
    0x08,
    0x04,
    0x03,
    0x00,
    0x00,
    0x00,
};

const char cross_bmp[] PROGMEM = {
    0x00,
    0x00,
    0x00,
    0x08,
    0x10,
    0x20,
    0x40,
    0x80,
    0x80,
    0x40,
    0x20,
    0x10,
    0x08,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x10,
    0x08,
    0x04,
    0x02,
    0x01,
    0x01,
    0x02,
    0x04,
    0x08,
    0x10,
    0x00,
    0x00,
    0x00,
};

const char title_bmp[] PROGMEM = {
    0x00,
    0x00,
    0x00,
    0x00,
    0x08,
    0x08,
    0x08,
    0x08,
    0x08,
    0xf8,
    0x08,
    0x08,
    0x08,
    0x08,
    0x08,
    0x08,
    0x08,
    0x08,
    0x08,
    0x08,
    0x08,
    0x00,
    0x00,
    0xc0,
    0x38,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x80,
    0xc0,
    0x30,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x30,
    0x10,
    0x10,
    0x98,
    0xe8,
    0x08,
    0x08,
    0x08,
    0x08,
    0x08,
    0x0c,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xc0,
    0xc0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x80,
    0x80,
    0x80,
    0xc0,
    0x40,
    0x40,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x80,
    0x80,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x3f,
    0xe0,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xe0,
    0x1e,
    0x01,
    0x00,
    0x00,
    0x00,
    0x00,
    0x80,
    0xe0,
    0x1c,
    0x06,
    0x01,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xe0,
    0x1f,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x80,
    0x60,
    0x1c,
    0x07,
    0xff,
    0x01,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x80,
    0x60,
    0x10,
    0x08,
    0x04,
    0x02,
    0x03,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x02,
    0x02,
    0xfe,
    0x02,
    0x02,
    0x01,
    0x01,
    0x01,
    0x01,
    0x00,
    0x00,
    0x00,
    0x00,
    0x82,
    0x62,
    0x11,
    0x11,
    0x00,
    0x01,
    0x01,
    0x01,
    0x01,
    0x01,
    0x02,
    0x82,
    0xe6,
    0x18,
    0x00,
    0x00,
    0x03,
    0xc1,
    0x7f,
    0x21,
    0x21,
    0x21,
    0x20,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x80,
    0xff,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x80,
    0xfe,
    0x01,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x3f,
    0x40,
    0x80,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xfc,
    0x03,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xe0,
    0x38,
    0x0c,
    0x03,
    0x01,
    0x02,
    0x02,
    0x02,
    0xff,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x3f,
    0xe0,
    0x80,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0xff,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x03,
    0x04,
    0x08,
    0x08,
    0x08,
    0x08,
    0x08,
    0x04,
    0x04,
    0x02,
    0x03,
    0x00,
    0x00,
    0x00,
    0x00,
    0x30,
    0x38,
    0x17,
    0x10,
    0x10,
    0x10,
    0x10,
    0x10,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x03,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x03,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x01,
    0x01,
    0x01,
    0x01,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x01,
    0x01,
    0x01,
    0x01,
    0x01,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x80,
    0xfc,
    0x84,
    0xa4,
    0xbc,
    0xe0,
    0x00,
    0x20,
    0xe0,
    0x40,
    0x60,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x70,
    0x9e,
    0x80,
    0x00,
    0x00,
    0x60,
    0x50,
    0x50,
    0xe0,
    0x00,
    0xf8,
    0x47,
    0x60,
    0x80,
    0x00,
    0xe4,
    0x00,
    0x00,
    0x00,
};

enum class GameStates
{
    START,
    PLAYING,
    END,
    P1,
    P2,
    DRAW
} gameState;

enum class TileStates
{
    EMPTY,
    P1,
    P2
};

struct Tile
{
    TileStates state;
    uint8_t x, y;
} tiles[3][3];

struct Cursor
{
    //Tilemap position
    int8_t x_tp, y_tp;
    GameStates player;
} cursor;

struct GameInfo
{
    uint8_t winsP1, winsP2;
    GameStates winner;
} gameInfo;

bool buttonStillPressed;
bool full;

void reset();
void drawStatistics();

void setup()
{
    arduboy.begin();
    arduboy.setFrameRate(15);

    reset();

    gameInfo.winsP1 = 0;
    gameInfo.winsP2 = 0;

    buttonStillPressed = false;

    //Grid init
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int x = 10 + (j * TILE_SIZE);
            int y = 10 + (i * TILE_SIZE);
            tiles[i][j].x = x;
            tiles[i][j].y = y;
        }
    }
}

void loop()
{
    if (!arduboy.nextFrame())
        return;

    if (arduboy.notPressed(RIGHT_BUTTON + LEFT_BUTTON + A_BUTTON + UP_BUTTON + DOWN_BUTTON + B_BUTTON))
    {
        buttonStillPressed = false;
    }

    arduboy.clear();

    switch (gameState)
    {
    case GameStates::START:
        //Title image
        arduboy.drawBitmap(0, 0, title_bmp, WIDTH, HEIGHT / 2, WHITE);
        arduboy.setCursor(16, 40);
        arduboy.print("A - Start");
        arduboy.setCursor(16, 50);
        arduboy.print("B - About");

        //Button Input
        if (!buttonStillPressed)
        {
            if (arduboy.pressed(A_BUTTON))
            {
                gameState = GameStates::PLAYING;
                buttonStillPressed = true;
            }
            else if (arduboy.pressed(B_BUTTON))
            {
                //TODO: About screen
                buttonStillPressed = true;
            }
        }

        break;
    case GameStates::PLAYING:
        //Title
        arduboy.setCursor(0, 0);
        arduboy.print("Tic Tac Toe");

        //Button Input
        if (!buttonStillPressed)
        {
            if (arduboy.pressed(UP_BUTTON))
            {
                cursor.x_tp--;
                if (cursor.x_tp == -1)
                    cursor.x_tp = 2;
                else
                    cursor.x_tp = abs(cursor.x_tp) % 3;
                buttonStillPressed = true;
            }
            else if (arduboy.pressed(DOWN_BUTTON))
            {
                cursor.x_tp++;
                cursor.x_tp = abs(cursor.x_tp) % 3;
                buttonStillPressed = true;
            }
            else if (arduboy.pressed(LEFT_BUTTON))
            {
                cursor.y_tp--;
                if (cursor.y_tp == -1)
                    cursor.y_tp = 2;
                else
                    cursor.y_tp = abs(cursor.y_tp) % 3;
                buttonStillPressed = true;
            }
            else if (arduboy.pressed(RIGHT_BUTTON))
            {
                cursor.y_tp++;
                cursor.y_tp = abs(cursor.y_tp) % 3;
                buttonStillPressed = true;
            }
            else if (arduboy.pressed(A_BUTTON))
            {

                if (tiles[cursor.x_tp][cursor.y_tp].state == TileStates::EMPTY)
                {
                    if (cursor.player == GameStates::P1)
                    {
                        tiles[cursor.x_tp][cursor.y_tp].state = TileStates::P1;
                        cursor.player = GameStates::P2;
                    }
                    else if (cursor.player == GameStates::P2)
                    {
                        tiles[cursor.x_tp][cursor.y_tp].state = TileStates::P2;
                        cursor.player = GameStates::P1;
                    }
                }
                buttonStillPressed = true;
            }
            else if (arduboy.pressed(B_BUTTON))
            {
                reset();
                buttonStillPressed = true;
            }
        }

        //Tiles
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {

                //Grid
                if (cursor.x_tp == i && cursor.y_tp == j)
                {
                    //Cursor
                    arduboy.drawBitmap(tiles[i][j].x, tiles[i][j].y, cursor_bmp, TILE_SIZE, TILE_SIZE, WHITE);
                }
                else
                {
                    //Tile
                    arduboy.drawBitmap(tiles[i][j].x, tiles[i][j].y, tile_bmp, TILE_SIZE, TILE_SIZE, WHITE);
                }

                //Player drawings
                if (tiles[i][j].state == TileStates::P1)
                {
                    arduboy.drawBitmap(tiles[i][j].x, tiles[i][j].y, cross_bmp, TILE_SIZE, TILE_SIZE, WHITE);
                }
                else if (tiles[i][j].state == TileStates::P2)
                {
                    arduboy.drawBitmap(tiles[i][j].x, tiles[i][j].y, circle_bmp, TILE_SIZE, TILE_SIZE, WHITE);
                }
            }
        }

        //Statistics - Player
        arduboy.setCursor(10 + (TILE_SIZE * 3) + 13, 14);
        if (cursor.player == GameStates::P1)
        {
            arduboy.print("P1");
            arduboy.drawBitmap(10 + (TILE_SIZE * 3) + 10, 10 + TILE_SIZE, cross_bmp, TILE_SIZE, TILE_SIZE, WHITE);
        }
        else if (cursor.player == GameStates::P2)
        {
            arduboy.print("P2");
            arduboy.drawBitmap(10 + (TILE_SIZE * 3) + 10, 10 + TILE_SIZE, circle_bmp, TILE_SIZE, TILE_SIZE, WHITE);
        }

        drawStatistics();

        //Check for win

        for (int i = 0; i < 3; i++)
        {
            //Horizontal
            if (tiles[i][0].state == TileStates::P1 && tiles[i][1].state == TileStates::P1 && tiles[i][2].state == TileStates::P1)
            {
                gameInfo.winner = GameStates::P1;
            }
            else if (tiles[i][0].state == TileStates::P2 && tiles[i][1].state == TileStates::P2 && tiles[i][2].state == TileStates::P2)
            {
                gameInfo.winner = GameStates::P2;
            } //Vertikal
            else if (tiles[0][i].state == TileStates::P1 && tiles[1][i].state == TileStates::P1 && tiles[2][i].state == TileStates::P1)
            {
                gameInfo.winner = GameStates::P1;
            }
            else if (tiles[0][i].state == TileStates::P2 && tiles[1][i].state == TileStates::P2 && tiles[2][i].state == TileStates::P2)
            {
                gameInfo.winner = GameStates::P2;
            } //Up - Down -> Diagonal  TODO: Put out of loop 
            else if (tiles[0][0].state == TileStates::P1 && tiles[1][1].state == TileStates::P1 && tiles[2][2].state == TileStates::P1)
            {
                gameInfo.winner = GameStates::P1;
            }
            else if (tiles[0][0].state == TileStates::P2 && tiles[1][1].state == TileStates::P2 && tiles[2][2].state == TileStates::P2)
            {
                gameInfo.winner = GameStates::P2;
            } //Down - Up -> Diagonal  TODO: Put out of loop
            else if (tiles[2][0].state == TileStates::P1 && tiles[1][1].state == TileStates::P1 && tiles[0][2].state == TileStates::P1)
            {
                gameInfo.winner = GameStates::P1;
            }
            else if (tiles[2][0].state == TileStates::P2 && tiles[1][1].state == TileStates::P2 && tiles[0][2].state == TileStates::P2)
            {
                gameInfo.winner = GameStates::P2;
            }
        }

        if (gameInfo.winner == GameStates::P1)
        {
            gameInfo.winsP1++;
            gameState = GameStates::END;
        }
        else if (gameInfo.winner == GameStates::P2)
        {
            gameInfo.winsP2++;
            gameState = GameStates::END;
        }
        else
        {
            //Check for draw
            full = true;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (tiles[i][j].state == TileStates::EMPTY)
                    {
                        full = false;
                        break;
                    }
                }
            }

            if (full)
            {
                gameInfo.winner = GameStates::DRAW;
                gameState = GameStates::END;
            }
        }

        break;
    case GameStates::END:

        arduboy.setCursor(0, 0);

        switch (gameInfo.winner)
        {
        case GameStates::DRAW:
            arduboy.print("It's a draw!");
            break;
        case GameStates::P1:
            arduboy.print("Player 1 wins!");
            break;
        case GameStates::P2:
            arduboy.print("Player 2 wins!");
            break;
        }

        //Button Input
        if (!buttonStillPressed)
        {
            if (arduboy.pressed(A_BUTTON) || arduboy.pressed(B_BUTTON))
            {
                reset();
                gameState = GameStates::PLAYING;
                buttonStillPressed = true;
            }
        }

        drawStatistics();
        break;
    }

    arduboy.display();
}

void reset()
{
    gameState = GameStates::START;
    cursor.x_tp = 0;
    cursor.y_tp = 0;
    cursor.player = GameStates::P1;

    gameInfo.winner = GameStates::PLAYING;

    //Grid init
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tiles[i][j].state = TileStates::EMPTY;
        }
    }
}

void drawStatistics()
{
    //Seperator
    arduboy.drawLine(90, 0, 90, 64, WHITE);

    //Statistics - Wins
    arduboy.setCursor(100, 0);
    arduboy.print("Wins");

    arduboy.setCursor(105, 15);
    arduboy.print("P1");
    arduboy.setCursor(100, 25);
    arduboy.print(gameInfo.winsP1);

    arduboy.setCursor(105, 40);
    arduboy.print("P2");
    arduboy.setCursor(100, 50);
    arduboy.print(gameInfo.winsP2);
}