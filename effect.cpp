#include "effect.h"

Effect::Effect()
{
}

Effect::Effect(int x, int y, int dx, int dy)
{
    this->x = x;
    this->y = y;
    this->dx = dx;
    this->dy = dy;
}

EffectZero::EffectZero()
{
}

EffectZero::EffectZero(int x, int y, int dx, int dy) : Effect(x, y, dx, dy)
{
}

void EffectZero::apply(Board *board)
{
    for (int i = x; i <= dx; i++)
        for (int j = y; j <= dy; j++)
            board -> getCondition(i, j) = 0;
}

EffectOne::EffectOne()
{
}

EffectOne::EffectOne(int x, int y, int dx, int dy) : Effect(x, y, dx, dy)
{
}

void EffectOne::apply(Board *board)
{
    for (int i = x; i <= dx; i++)
        for (int j = y; j <= dy; j++)
            board->getCondition(i, j) = 1;
}

EffectTwo::EffectTwo()
{
}

EffectTwo::EffectTwo(int x, int y, int dx, int dy) : Effect(x, y, dx, dy)
{
}

void EffectTwo::apply(Board *board)
{
    for (int i = x; i <= dx; i++)
        for (int j = y; j <= dy; j++)
        {
            if (board->getCondition(i, j) == 0)
                board->getCondition(i, j) = 1;
            else
                board->getCondition(i, j) = 0;
        }
}

EffectThree::EffectThree()
{
}

EffectThree::EffectThree(int x, int y, int dx, int dy) : Effect(x, y, dx, dy)
{
}

void EffectThree::apply(Board *board)
{
    Board copyBoard = *board;
    for (int i = x; i <= dx; i++)
    {
        for (int j = y; j <= dy; j++)
        {
            if (copyBoard.getCondition(i, j) == 1)
            {
                int neighbourCount = 0;
                for (int n = -1; n < 2; n++)
                {
                    for (int m = -1; m < 2; m++)
                    {
                        if (!(n == 0 && m == 0))
                        {
                            int a = i;
                            int b = j;
                            a += n;
                            b += m;
                            switch (a)
                            {
                            case -1:
                                a = 15;
                                break;
                            case 16:
                                a = 0;
                                break;
                            }

                            switch (b)
                            {
                            case -1:
                                b = 15;
                                break;
                            case 16:
                                b = 0;
                                break;
                            }
                            if (copyBoard.getCondition(a, b) == 1)
                                ++neighbourCount;
                        }
                    }
                }
                if (!(neighbourCount == 2 || neighbourCount == 3))
                    board->getCondition(i, j) = 0;
                else
                    board->getCondition(i, j) = 1;
            }
            else
                board->getCondition(i, j) = 0;
        }
    }
}

EffectFour::EffectFour()
{
}

EffectFour::EffectFour(int x, int y, int dx, int dy) : Effect(x, y, dx, dy)
{
}

void EffectFour::apply(Board *board)
{
    Board copyBoard = *board;
    for (int i = x; i <= dx; i++)
    {
        for (int j = y; j <= dy; j++)
        {
            if (copyBoard.getCondition(i, j) == 0)
            {
                int neighbourCount = 0;
                for (int n = -1; n < 2; n++)
                {
                    for (int m = -1; m < 2; m++)
                    {
                        if (!(n == 0 && m == 0))
                        {
                            int a = i;
                            int b = j;
                            a += n;
                            b += m;
                            switch (a)
                            {
                            case -1:
                                a = 15;
                                break;
                            case 16:
                                a = 0;
                                break;
                            }

                            switch (b)
                            {
                            case -1:
                                b = 15;
                                break;
                            case 16:
                                b = 0;
                                break;
                            }
                            if (copyBoard.getCondition(a, b) == 1)
                                ++neighbourCount;
                        }
                    }
                }
                if (neighbourCount == 3)
                    board->getCondition(i, j) = 1;
                else
                    board->getCondition(i, j) = 0;
            }
            else
                board->getCondition(i, j) = 0;
        }
    }
}

EffectFive::EffectFive()
{
}

EffectFive::EffectFive(int x, int y, int dx, int dy) : Effect(x, y, dx, dy)
{
}

void EffectFive::apply(Board *board)
{
    if (!isSave)
    {
        this->board = board;
        isSave = true;
    }
    else
    {
        for (int i = x; i <= dx; i++)
        {
            for (int j = y; j <= dy; j++)
            {
                if ((this->board->getCondition(i, j) & 1) ^ (board->getCondition(i, j) & 1))
                {
                    board->getCondition(i, j) = 1;
                }
                else
                {
                    board->getCondition(i, j) = 0;
                }
            }
        }
        isSave = false;
    }
}

EffectSix::EffectSix()
{
}

EffectSix::EffectSix(int x, int y, int dx, int dy) : Effect(x, y, dx, dy)
{
}

void EffectSix::apply(Board *board)
{
    if (!isSave)
    {
        this->board = board;
        isSave = true;
    }
    else
    {
        for (int i = x; i <= dx; i++)
        {
            for (int j = y; j <= dy; j++)
            {
                if (this->board->getCondition(i, j) == 1)
                    board->getCondition(i, j) = 1;
                if (this->board->getCondition(i, j) == 0)
                    board->getCondition(i, j) = 0;
            }
        }
        isSave = false;
    }
}