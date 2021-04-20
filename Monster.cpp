#include "Monster.h"

Monster::Monster()
{
    pearl=al_load_bitmap("pearl_burned1.png");
    pos_x=175;
    pos_y=-125;
}
Monster::~Monster()
{

}
void
Monster::Draw()
{
    al_draw_bitmap(pearl, pos_x, pos_y, 0);

}

void
Monster::Move()
{
    pos_y+=2;
}

//______________________________
Monster1::Monster1()
{
    pearl=al_load_bitmap("pearl_burned1.png");
    pos_x=275;
    pos_y=-125;
}
Monster1::~Monster1()
{

}
void
Monster1::Draw()
{
    al_draw_bitmap(pearl, pos_x, pos_y, 0);

}

void
Monster1::Move()
{
    pos_y+=2;
}
//_________________________________
Monster2::Monster2()
{
    pearl=al_load_bitmap("pearl_burned1.png");
    pos_x=375;
    pos_y=-125;
}
Monster2::~Monster2()
{

}
void
Monster2::Draw()
{
    al_draw_bitmap(pearl, pos_x, pos_y, 0);

}

void
Monster2::Move()
{
    pos_y+=2;
}
//__________---______________________________
Monster3::Monster3()
{
    pearl=al_load_bitmap("pearl_burned1.png");
    pos_x=475;
    pos_y=-125;
}
Monster3::~Monster3()
{

}
void
Monster3::Draw()
{
    al_draw_bitmap(pearl, pos_x, pos_y, 0);

}

void
Monster3::Move()
{
    pos_y+=2;
}


Monster4::Monster4()
{
//    pearl=al_load_bitmap("pearl_burned1.png");
    pos_x=175;
    pos_y=-100;
}
Monster4::~Monster4()
{

}
void
Monster4::Draw()
{
   al_draw_filled_rectangle(220, pos_y, 580, pos_y+40, al_map_rgb(0, 255, 255));
}

void
Monster4::Move()
{
    pos_y+=2;
}

