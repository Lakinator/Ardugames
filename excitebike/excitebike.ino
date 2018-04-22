#include <Arduboy2.h>

Arduboy2 arduboy;

const unsigned char bike_bmp_normal[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0xd0, 0x78, 0x38, 0xe8, 0xc8, 0xb0, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1a, 0x26, 0x2f, 0x1f, 0x13, 0x16, 0x1e, 0x0c, 0x1f, 0x2f, 0x25, 0x1a, 0x00, 0x00};
const unsigned char bike_bmp_fast[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x80, 0xe8, 0xbc, 0x1c, 0x74, 0x64, 0xd8, 0xc0, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x19, 0x25, 0x2f, 0x1f, 0x09, 0x0b, 0x0f, 0x06, 0x1f, 0x27, 0x26, 0x19, 0x00, 0x00};
const unsigned char *bike_anim_bmp[] = {
    bike_bmp_normal, bike_bmp_fast};

const unsigned char street_bmp_normal[] PROGMEM = {
    0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00};

/**
    * AnimationTimer class 
    * 
    */

class AnimationTimer
{
  public:
    enum Speeds
    {
        NONE = 0,
        SLOW,
        MIDDLE,
        FAST,
        VERY_FAST,
        ULTRA_FAST
    };

    AnimationTimer(int fps, int frames, AnimationTimer::Speeds updateSpeed);
    int getCurrentImage();
    void changeUpdateSpeed(AnimationTimer::Speeds updateSpeed);

  private:
    int fps;                            //Frames per second in the application
    int frames;                         //The frame count of the animation
    AnimationTimer::Speeds updateSpeed; //Speed in which the images change, dependent on the fps
    int pastFrames;                     //counter for past frames
};

AnimationTimer::AnimationTimer(int fps, int frames, AnimationTimer::Speeds updateSpeed)
{
    this->fps = fps;
    this->frames = frames;
    this->updateSpeed = updateSpeed;
    this->pastFrames = 0;
}

int AnimationTimer::getCurrentImage()
{
    int currImg = 0;
    int frameTime = (fps / frames) - (updateSpeed * 5);

    pastFrames++;

    if (pastFrames > (frameTime * frames))
        pastFrames = 0;

    for (int i = 0; i < frames; i++)
    {
        if (pastFrames >= (i * frameTime) && pastFrames < ((i + 1) * frameTime))
        {
            currImg = i;
        }
    }

    return currImg;
}

void AnimationTimer::changeUpdateSpeed(AnimationTimer::Speeds updateSpeed)
{
    this->updateSpeed = updateSpeed;
}

/**
    * Bike class 
    * 
    */

class Bike
{
  public:
    Bike();
    ~Bike();
    void render(Arduboy2 *ardu);
    void move(bool isForwardDown);

    void setSpeed(int speed);
    int getSpeed();
    void setPos(int posX, int posY);
    int getPosX();
    int getPosY();

  private:
    AnimationTimer *animTimer;
    int speed;
    int posX, posY;
    int moveCounter;
};

Bike::Bike()
{
    this->speed = 0; // 0 - 5
    this->animTimer = new AnimationTimer(60, 2, static_cast<AnimationTimer::Speeds>(this->speed));
    this->posX = 0;
    this->posY = 10;
    this->moveCounter = 0;
}

Bike::~Bike()
{
    delete animTimer;
}

void Bike::render(Arduboy2 *ardu)
{
    int currentImage = animTimer->getCurrentImage();
    ardu->drawBitmap(this->posX, this->posY, bike_anim_bmp[currentImage], 16, 16, WHITE);
}

void Bike::move(bool isForwardDown)
{

    int delay = 100;

    if (isForwardDown)
    {
        moveCounter++;
        if (moveCounter > delay)
            moveCounter = 1;
    }
    else
    {
        moveCounter--;
        if (moveCounter < 0)
            moveCounter = delay - 1;
    }

    if (moveCounter == delay)
    {
        if (speed + 1 <= 5)
        {
            speed++;
        }
    }
    else if (moveCounter == 0)
    {
        if (speed - 1 >= 0)
        {
            speed--;
        }
    }

    if (isForwardDown && speed == 0)
    {
        speed = 1;
    }

    animTimer->changeUpdateSpeed(static_cast<AnimationTimer::Speeds>(this->speed));

    //LOG
    arduboy.print(moveCounter);
}

void Bike::setSpeed(int speed)
{
    this->speed = speed;
    animTimer->changeUpdateSpeed(static_cast<AnimationTimer::Speeds>(this->speed));
}

int Bike::getSpeed()
{
    return this->speed;
}

void Bike::setPos(int posX, int posY)
{
    this->posX = posX;
    this->posY = posY;
}

int Bike::getPosX()
{
    return this->posX;
}

int Bike::getPosY()
{
    return this->posY;
}

/**
    * Street class 
    * 
    */

class Street
{
  public:
    Street();
    Street(int posX, int posY);
    void render(Arduboy2 *ardu);
    void move(int speed);

  private:
    int posX, posY;
};

Street::Street()
{
    this->posX = 0;
    this->posY = 0;
}

Street::Street(int posX, int posY)
{
    this->posX = posX;
    this->posY = posY;
}

void Street::render(Arduboy2 *ardu)
{
    ardu->drawBitmap(this->posX, this->posY, street_bmp_normal, 8, 16, WHITE);
}

void Street::move(int speed)
{
    posX -= speed;

    if (speed > 1)
        posX -= 1;

    if (posX + 8 < 0)
    {
        posX = 127;
    }
}

/**
 * Main program
 * 
 */

Bike bike;
Street street1[17];

void renderStats();

void setup()
{
    arduboy.begin();
    arduboy.setFrameRate(60);

    for (int i = 0; i < 17; i++)
    {
        int x = i * 8;
        int y = 14;
        street1[i] = Street(x, y);
        street1[i].render(&arduboy);
    }
}

void loop()
{
    if (!arduboy.nextFrame())
        return;

    arduboy.clear();
    arduboy.setCursor(0, 0);

    bike.move(arduboy.pressed(RIGHT_BUTTON));

    for (int i = 0; i < 17; i++)
    {
        street1[i].move(bike.getSpeed());
        street1[i].render(&arduboy);
    }

    bike.render(&arduboy);

    renderStats();

    arduboy.display();
}

void renderStats()
{
    arduboy.drawLine(0, 46, 128, 46);
    arduboy.drawLine(5 * 8, 46, 5 * 8, 64);
    arduboy.drawLine(11 * 8, 46, 11 * 8, 64);

    arduboy.setCursor(1 * 8, 48);
    arduboy.print("Best");
    arduboy.setCursor(1 * 8, 56);
    arduboy.print("32s");

    arduboy.setCursor(6 * 8, 48);
    arduboy.print("Speed");
    arduboy.setCursor(6 * 8, 56);
    if (bike.getSpeed() <= 0)
    {
        arduboy.drawRect(6 * 8, 56, 1, 8);
    }
    else
    {
        arduboy.drawRect(6 * 8, 56, (bike.getSpeed() * 6) - 1, 8);
    }

    arduboy.setCursor(12 * 8, 48);
    arduboy.print("Time");
    arduboy.setCursor(12 * 8, 56);
    arduboy.print("22s");
}