#pragma once
#include "board.h"

class Effect
{
  protected:
    int x;
    int y;
    int dx;
    int dy;

  public:
    Effect();
    Effect(int, int, int, int);
    virtual void apply(Board *) = 0;
};

class EffectZero : public Effect
{
  public:
    EffectZero();
    EffectZero(int, int, int, int);
    void apply(Board *);
};

class EffectOne : public Effect
{
  public:
    EffectOne();
    EffectOne(int, int, int, int);
    void apply(Board *);
};

class EffectTwo : public Effect
{
  public:
    EffectTwo();
    EffectTwo(int, int, int, int);
    void apply(Board *);
};

class EffectThree : public Effect
{
  public:
    EffectThree();
    EffectThree(int, int, int, int);
    void apply(Board *);
};

class EffectFour : public Effect
{
  public:
    EffectFour();
    EffectFour(int, int, int, int);
    void apply(Board *);
};

class EffectFive : public Effect
{
  private:
    Board *board;
    bool isSave;

  public:
    EffectFive();
    EffectFive(int, int, int, int);
    void apply(Board *);
};

class EffectSix : public Effect
{
  private:
    Board *board;
    bool isSave;

  public:
    EffectSix();
    EffectSix(int, int, int, int);
    void apply(Board *);
};