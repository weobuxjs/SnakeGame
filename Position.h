struct TwistPosition
{
    int x;
    int y;
    int Horizontal;
    int Vertical;
    TwistPosition(int x,int y, int right, int up)
    {
        this->x=x;
        this->y=y;
        Horizontal=right;
        Vertical =up;
    }
    
};