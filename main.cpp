#include "board.h"
#include "effect.h"

void applyEffect(Effect *effect, Board *board)
{
    effect->apply(board);
}

Effect *effect;
Effect *effectFive;
Effect *effectSix;
Board *boards[2];

int main(int argc, char const *argv[])
{
    boards[0] = new Board();
    boards[1] = new Board();
    bool isSave1;
    bool isSave2;
    isSave1 = isSave2 = false;
    int x;
    int y;
    int dx;
    int dy;
    int e;
    int d;

    while (!cin.eof())
    {
        cin >> x >> y >> dx >> dy >> e >> d;
        if (!cin.eof())
        {
            if (x >= 0 && x <= 15 && y >= 0 && y <= 15 && dx <= 15 && dx >= 0 && dy >= 0 && dy <= 15 && e >= 0 && e <= 6 && d >= 0 && d <= 1 && x <= dx && y <= dy)
            {
                switch (e)
                {
                case 0:
                    effect = new EffectZero(x, y, dx, dy);
                    break;
                case 1:
                    effect = new EffectOne(x, y, dx, dy);
                    break;
                case 2:
                    effect = new EffectTwo(x, y, dx, dy);
                    break;
                case 3:
                    effect = new EffectThree(x, y, dx, dy);
                    break;
                case 4:
                    effect = new EffectFour(x, y, dx, dy);
                    break;
                case 5:
                    if (!isSave1)
                    {
                        effectFive = new EffectFive(x, y, dx, dy);
                        effect = effectFive;
                        isSave1 = true;
                    }
                    else
                    {
                        effect = effectFive;
                        isSave1 = false;
                    }
                    break;
                case 6:
                    if (!isSave2)
                    {
                        effectSix = new EffectSix(x, y, dx, dy);
                        effect = effectSix;
                        isSave2 = true;
                    }
                    else
                    {
                        effect = effectSix;
                        isSave2 = false;
                    }
                    break;
                }
                applyEffect(effect, boards[d]);
            }
        }
    }
    boards[d]->print();
    return 0;
}
