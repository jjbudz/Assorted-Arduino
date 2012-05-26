//
// Basic program to test the BoeBot for Arduino with
// whiskers attached. The bot changes direction when
// the whiskers encounter obstacles. The program
// tends to result in a flipped bot or bent whisker.
//

#include <Arduino.h>
#include <Servo.h>

const int kLeftServo  = 10;
const int kRightServo = 11;

const int kLeftWhisker  = 2;
const int kRightWhisker = 3;

const int kStopped = 1500;
const int kCW      = 2000;
const int kCCW     = 1000;

class ServoPair
{
public:

    ServoPair() {};
    ~ServoPair() {};

    void init(int leftIO, int rightIO);

    void left();
    void right();

    void forward();
    void reverse();

    void revLeft();
    void revRight();

    void stop();

protected:

    void setServos(int l, int r);

private:

    ServoPair(ServoPair&);

    Servo _left;
    Servo _right;

};

void ServoPair::init(int leftIO, int rightIO)
{
    _left.attach(leftIO);
    _right.attach(rightIO);

    stop();
}

void ServoPair::setServos(int l, int r)
{
    _left.writeMicroseconds(l);
    _right.writeMicroseconds(r);
}

void ServoPair::left()
{
    setServos(kStopped,kCCW);
}

void ServoPair::right()
{
    setServos(kCW,kStopped);
}

void ServoPair::forward()
{
    setServos(kCW,kCCW);
}

void ServoPair::reverse()
{
    setServos(kCCW,kCW);
}

void ServoPair::revLeft()
{
    setServos(kCCW,kCCW);
}

void ServoPair::revRight()
{
    setServos(kCW,kCW);
}

void ServoPair::stop()
{
    setServos(kStopped,kStopped);
}

enum WhiskerEnum {eNone, eLeft, eRight, eBoth};

class Whiskers
{
public: 

    Whiskers() {};
    ~Whiskers() {};

    void init(int leftIO, int rightIO);

    WhiskerEnum sense() const;

protected:

    // None

private:

    Whiskers(const Whiskers&);

    int _left;
    int _right;

};

void Whiskers::init(int leftIO, int rightIO)
{
    pinMode(_left=leftIO,INPUT);
    pinMode(_right=rightIO,INPUT);
}

WhiskerEnum Whiskers::sense() const
{
    WhiskerEnum e = eNone;
    bool l = (digitalRead(_left) == LOW);
    bool r = (digitalRead(_right) == LOW);

    if (l && r) e = eBoth;
    else if (l) e = eLeft;
    else if (r) e = eRight;

    return e;
}

ServoPair servos;
Whiskers whiskers;

void setup()
{
    Serial.begin(9600);

    servos.init(kLeftServo,kRightServo);
    whiskers.init(kLeftWhisker,kRightWhisker);

    randomSeed(analogRead(0));
}

void loop()
{
    int duration = 100;

    switch (whiskers.sense())
    {
    case eNone:
        servos.forward();
        break;
    case eLeft:
        servos.reverse();
        delay(250);
        servos.revRight();
        duration = 150 + random(150);
        break;
    case eRight:
        servos.reverse();
        delay(250);
        servos.revLeft();
        duration = 150 + random(150);
        break;
    case eBoth:
        servos.reverse();
        duration = 100 + random(400);
        break;
    default:
        break;
    }

    delay(duration);
}
