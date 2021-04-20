#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "Monster.h"

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <list>


#define GAME_INIT -1
#define GAME_SETTING 0
#define GAME_SELECT 1
#define GAME_BEGIN 2
#define GAME_CONTINUE 3
#define GAME_FAIL 4
#define GAME_TERMINATE 5
#define GAME_NEXT_LEVEL 6
#define GAME_EXIT 7

#define window_width 800
#define window_height 600


const float FPS = 60;

class GameWindow
{
public:

    GameWindow();

    void game_init();
    void game_reset();
    void game_play();
    void game_begin();
    void draw_menu();

    int game_run();
    void show_err_msg(int msg);
    void game_destroy();
    void draw_running_map();
    void draw_end();
    int process_event();
public:
    bool initial = true;

private:
    ALLEGRO_BITMAP *icon;


    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *LevelBackground = NULL;
    ALLEGRO_BITMAP *manu = NULL;
    ALLEGRO_BITMAP *button = NULL;
    ALLEGRO_BITMAP *redbutton = NULL;
    ALLEGRO_BITMAP *endbackground = NULL;
    ALLEGRO_BITMAP *l2bg = NULL;
    ALLEGRO_BITMAP *l3bg = NULL;
    ALLEGRO_BITMAP *l4bg = NULL;
    ALLEGRO_BITMAP *l5bg = NULL;

    //ALLEGRO_BITMAP *pearl= NULL;

    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_FONT *font = NULL;
    ALLEGRO_FONT *manufont=NULL;
    ALLEGRO_FONT *Medium_font = NULL;
    ALLEGRO_FONT *Large_font = NULL;
    ALLEGRO_FONT *Levelfont = NULL;

    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_EVENT event;
    ALLEGRO_TIMER *timer = NULL;
    ALLEGRO_TIMER *beats = NULL;
    ALLEGRO_TIMER *beats2 = NULL;

    ALLEGRO_TIMER *miss = NULL;
    ALLEGRO_TIMER *miss1 = NULL;
    ALLEGRO_TIMER *miss2 = NULL;
    ALLEGRO_TIMER *miss3 = NULL;
    ALLEGRO_TIMER *miss4 = NULL;

    ALLEGRO_SAMPLE *sample = NULL;
    ALLEGRO_SAMPLE_INSTANCE *startSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *music1 = NULL;
    ALLEGRO_SAMPLE_INSTANCE *clearSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *finish = NULL;
    ALLEGRO_SAMPLE_INSTANCE *backgroundSound = NULL;
    ALLEGRO_SAMPLE_INSTANCE *music2 = NULL;


    int page;
    int select,select2;

    int Level;
    bool hit;
    bool hit1;
    bool hit2;
    bool hit3;
    bool hit4;

    bool pause;
    bool ohoh;
    bool ohoh1;
    bool ohoh2;
    bool ohoh3;
    bool ohoh4;
    int new_best;
    int combo;
    int maxcombo;
    int point;
    int combo_level;

};

