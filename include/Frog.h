#pragma once

class Frog 
{
    public:
        Frog();

        int getX();
        int getY();

        void update();
        void think();
        
    private:
        int x;
        int y;
};
