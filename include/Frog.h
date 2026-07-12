#pragma once

class Frog 
{
    public:
        Frog();

        int getX();
        int getY();
        int setX(int newX);

        void update();
        void think();
        
    private:
        int x;
        int y;
};
