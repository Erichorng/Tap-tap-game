#include "GameWindow.h"
#include <iostream>
#include<vector>
#include<stdio.h>
using namespace std;


float f[]={4,6.75,8,12,14.5/**/,16,20,22.5,26.25,26.5,30.25,  41.5,52,60.5,61,61.5,64,64.5,66,68,68.5,69,77,77.5,80,81,83,83.5,84.5,85.25,85.5,92,92.5,93.5,94.5,99.25,};
float f1[]={4.75,8.75,14.5/**/,18.5,22,24,29.5,39,40,40.75,  41.75,54,60,62,65,65.5,66,68,72,72.5,73,/*elec*/76,80.5,81.5,84,85,92,92.5,97.5,98.25,98.5,99,99.5,};
float f2[]={5.5,7.5,10,14/**/,18.25,22.25,26,28.75,31,33.75,34.25,37.5,38.25,56,62.5,63,63.5,66,66.5,68,76.5,79,80,81,83,83.5,84.5,92,92.5,95.75,96,99.75,};
float f3[]={6,9.5,14.25/**/,18,18.5,22.5,28,36,36.75,40.5,  41.75,58,60,62,67,67.5,68,76,78,78.5,79,82,82.5,83.25,84,85,92,92.5,96.25,99.25,};
float f4[]={13,17,21,25,33,44,45,46,47,48,49,50,51,52.5,53,53.5,54.5,55,55.5,56.5,57,57.5,58.5,59,59.5,93,95,97};

float g[]={619,
740,
857,
953,
983,
1101,
1219,
1337,
1421,
1441,
1460,
1695,
1736,
1789,
1803,
1818,
1941,
1973,
2028,
2041,
2056,
2172,
2356,
2379,
2399,
2418,
2540,};
float g1[]={2660,
2781,
2872,
2901,
3020,
3139,
3259,
3321,
3345,
3366,
3381,
3498,
3622,
3800,
3829,
3977,
4102,
4133,
4343,};
float g2[]={558,
680,
799,
919,
1037,
1157,
1276,
1396,
1518,
1636,
1764,
1875,
1999,
2124,
2242,
2353,
2399,
2481,
2597,};
float g3[]={501,
619,
745,
985,
1099,
1219,
1461,
1577,
1701,
1937,
2054,
2178,
2381,
2420,
2599,2830,
2954,
3083,
3200,
3317,
3436,
3563,
3678,
3801,
3983,
4286,
4308,
4328,};
float g4[]={1000,1001,};
int index=0;
int index1=0;
int index2=0;
int index3=0;
int index4=0;

int second=0;
int t;
int t1;
int t2;
int t3;
int t4;
int n;
int y;
int y1;
int y2;
int y3;
int y4;
float music_pro=0.0;
float music_pro2=0.0;
int i;
std::vector<Monster*>monsterset;
std::vector<Monster1*>monsterset1;
std::vector<Monster2*>monsterset2;
std::vector<Monster3*>monsterset3;
std::vector<Monster4*>monsterset4;

void
GameWindow::game_init()
{
    page=1;
    maxcombo=0;
    select=0;
    select2=0;
    Level=1;
    combo=0;
    point=0;
    ohoh1=ohoh2=ohoh3=ohoh=ohoh4=false;
    pause=false;
    new_best=false;
    combo_level=1;
    hit=hit1=hit2=hit3=hit4=false;
    icon = al_load_bitmap("./icon.png");
    background = al_load_bitmap("./gamebackground.jpg");
    endbackground = al_load_bitmap("endbackground.jpg");
    LevelBackground=al_load_bitmap("./Level.jpg");
    manu=al_load_bitmap("./manu.jpg");
    button=    al_load_bitmap("buttonbigbig.png");
    redbutton=al_load_bitmap("Red_button.png");
    l2bg=al_load_bitmap("level2.jpg");
    l3bg=al_load_bitmap("level3.jpg");
    l4bg=al_load_bitmap("level4.jpg");
    l5bg=al_load_bitmap("level6.jpg");

    al_set_display_icon(display, icon);
    al_reserve_samples(3);

    sample = al_load_sample("growl.wav");
    startSound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(startSound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(startSound, al_get_default_mixer());

    sample = al_load_sample("deemoMirror Night.wav");
    backgroundSound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(backgroundSound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(backgroundSound, al_get_default_mixer());

    sample=al_load_sample("We Go Up.wav");
    music1=al_create_sample_instance(sample);
    al_set_sample_instance_playmode(music1, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(music1, al_get_default_mixer());

    sample = al_load_sample("Erik Satie.wav");
    finish = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(finish, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(finish, al_get_default_mixer());

    sample = al_load_sample("Run Away.wav");
    music2 = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(music2, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(music2, al_get_default_mixer());


}


void
GameWindow::game_play()
{
    int msg;

    srand(time(NULL));

    msg = -1;
//    game_reset();
    game_begin();

    while(msg != GAME_EXIT)
    {
        msg = game_run();
    }

    show_err_msg(msg);
}

void
GameWindow::show_err_msg(int msg)
{
    if(msg == GAME_TERMINATE)
        fprintf(stderr, "Game Terminated...");
    else
        fprintf(stderr, "unexpected msg: %d", msg);

    game_destroy();
    exit(9);
}

GameWindow::GameWindow()
{
    if (!al_init())
        show_err_msg(-1);

    printf("Game Initializing...\n");
    Level=1;
    display = al_create_display(window_width, window_height);
    event_queue = al_create_event_queue();

    timer = al_create_timer(1.0 / FPS);
    beats = al_create_timer(1.0 / 77.5);
    miss=al_create_timer(1.0 / 77.5);
    miss1=al_create_timer(1.0 / 77.5);
    miss2=al_create_timer(1.0 / 77.5);
    miss3=al_create_timer(1.0 / 77.5);
    miss4=al_create_timer(1.0 / 77.5);
    beats2=al_create_timer(1.0 / 85.5);

    if(timer == NULL || beats == NULL)
        show_err_msg(-1);

    if (display == NULL || event_queue == NULL)
        show_err_msg(-1);

    al_init_primitives_addon();
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon(); // initialize the ttf (True Type Font) addon
    al_init_image_addon(); // initialize the image addon
    al_init_acodec_addon(); // initialize acodec addon

    al_install_keyboard(); // install keyboard event
    al_install_mouse();    // install mouse event
    al_install_audio();    // install audio event

    font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",15,0); // load small font
    Medium_font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",24,0); //load medium font
    Large_font = al_load_ttf_font("Caviar_Dreams_Bold.ttf",36,0); //load large font
    manufont = al_load_ttf_font("pirulen.ttf", 40, 0);
    Levelfont = al_load_ttf_font("pirulen.ttf", 100, 0);
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());

    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_timer_event_source(beats));
    al_register_event_source(event_queue, al_get_timer_event_source(miss));
    al_register_event_source(event_queue, al_get_timer_event_source(miss1));
    al_register_event_source(event_queue, al_get_timer_event_source(miss2));
    al_register_event_source(event_queue, al_get_timer_event_source(miss3));
    al_register_event_source(event_queue, al_get_timer_event_source(miss4));
    al_register_event_source(event_queue, al_get_timer_event_source(beats2));

    game_init();
}

void
GameWindow::game_begin()
{

    draw_running_map();
   // beats2=al_create_timer(1.0 / 85.5);//___________________________________________________


    al_play_sample_instance(startSound);
    while(al_get_sample_instance_playing(startSound));
    al_play_sample_instance(backgroundSound);

    al_start_timer(timer);

}

int
GameWindow::game_run()
{
    int error = GAME_CONTINUE;

    if (!al_is_event_queue_empty(event_queue)) {

        error = process_event();
    }
    return error;
}

void
GameWindow::game_reset()
{


    // stop sample instance
    al_stop_sample_instance(backgroundSound);
    al_stop_sample_instance(startSound);
    al_stop_sample_instance(finish);
    al_stop_sample_instance(music1);
    al_stop_sample_instance(music2);

    // stop timer
    al_stop_timer(timer);
    al_stop_timer(beats);
    al_stop_timer(miss);
    al_stop_timer(miss1);
    al_stop_timer(miss2);
    al_stop_timer(miss3);
    al_stop_timer(miss4);
    al_stop_timer(beats2);
    al_set_timer_count(beats2,0);
    //al_destroy_timer(beats2);

    combo_level=1;
    pause=false;
    maxcombo=0;
    page=1;
    point=0;
    new_best=false;
    select=0;
    select2=0;
    //Level=1;
    combo=0;
    hit=hit1=hit2=hit3=hit4=false;
    ohoh1=ohoh2=ohoh3=ohoh=ohoh4=false;
    index=0;
    index1=0;
    index2=0;
    index3=0;
    index4=0;

    second=0;
    music_pro=0;
    music_pro2=0;
    monsterset.clear();
    monsterset1.clear();
    monsterset2.clear();
    monsterset3.clear();
    monsterset4.clear();
}

void
GameWindow::game_destroy()
{
  //  game_reset();

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_font(font);
    al_destroy_font(Medium_font);
    al_destroy_font(Large_font);

    al_destroy_timer(timer);
    al_destroy_timer(beats);



    al_destroy_bitmap(icon);
    al_destroy_bitmap(background);

    al_destroy_sample(sample);
    al_destroy_sample_instance(startSound);
    al_destroy_sample_instance(backgroundSound);


}
void
GameWindow::draw_menu()
{
    al_draw_filled_rectangle(240, 0, 260, 550, al_map_rgb(255, 255, 150));
    al_draw_filled_rectangle(340, 0, 360, 550, al_map_rgb(255, 255, 150));
    al_draw_filled_rectangle(440, 0, 460, 550, al_map_rgb(255, 255, 150));
    al_draw_filled_rectangle(540, 0, 560, 550, al_map_rgb(255, 255, 150));
    al_draw_bitmap(button,223,543,0);
    al_draw_bitmap(button,323,543,0);
    al_draw_bitmap(button,423,543,0);
    al_draw_bitmap(button,523,543,0);
    al_draw_bitmap(button,223,543,0);
    //printf("%d\n",t);
    if(ohoh){

        al_draw_bitmap(redbutton,217,y,0);
        if(t==20){
            t=0;
            al_stop_timer(miss);
            ohoh=false;

        }
    }
    if(ohoh1){
        al_draw_bitmap(redbutton,317,y1,0);
        if(t1>=20){
            t1=0;
            al_stop_timer(miss1);
            ohoh1=false;

        }
    }
    if(ohoh2){
        al_draw_bitmap(redbutton,417,y2,0);
        if(t2>=20){
            t2=0;
            al_stop_timer(miss2);
            ohoh2=false;

        }
    }
    if(ohoh3){
        al_draw_bitmap(redbutton,517,y3,0);
        if(t3>=20){
            t3=0;
            al_stop_timer(miss3);
            ohoh3=false;
        }
    }

    if(ohoh4){
        al_draw_filled_rectangle(220, y4, 580, y4+40, al_map_rgb(255, 0, 0));
        if(t4>=20){
            t4=0;
            al_stop_timer(miss4);
            ohoh4=false;
        }
    }

    if(hit){
            al_draw_bitmap(redbutton,217,535,0);
            hit=false;
            }
    if(hit1){
            al_draw_bitmap(redbutton,317,535,0);
            hit1=false;
            }
    if(hit2){
            al_draw_bitmap(redbutton,417,535,0);
            hit2=false;
            }
    if(hit3){
            al_draw_bitmap(redbutton,517,535,0);
            hit3=false;
            }
    if(hit4){
           // al_draw_bitmap(redbutton,517,535,0);
            hit4=false;
            }
            char buffer[50];

             sprintf(buffer, "%d", combo);

             if(combo_level==1||combo_level==2){
                if(combo>1)al_draw_text(font, al_map_rgb(255, 255, 255), 10, 350, 0, "combo");
                if(combo>1)al_draw_text(Large_font, al_map_rgb(255, 255, 255), 60, 330, 0, buffer);

             }
             else if(combo_level==3||combo_level==4){
                if(combo>1)al_draw_text(font, al_map_rgb(255,0 , 0), 10, 350, 0, "combo");
                if(combo>1)al_draw_text(Large_font, al_map_rgb(255, 0, 0), 60, 330, 0, buffer);

             }
             else{
                if(combo>1)al_draw_text(font, al_map_rgb(0,0 , 0), 10, 350, 0, "combo");
                if(combo>1)al_draw_text(Large_font, al_map_rgb(0, 0, 0), 60, 330, 0, buffer);


             }

             sprintf(buffer, "%d", point);
             if(combo_level==1||combo_level==2){
                al_draw_text(font, al_map_rgb(255, 255, 255), 10, 400, 0, "score");
                al_draw_text(Large_font, al_map_rgb(255, 255, 255), 60, 380, 0, buffer);


             }
             else if(combo_level==3||combo_level==4){
                al_draw_text(font, al_map_rgb(255, 0, 0), 10, 400, 0, "score");
                al_draw_text(Large_font, al_map_rgb(255, 0, 0), 60, 380, 0, buffer);


             }
             else{
                al_draw_text(font, al_map_rgb(0, 0, 0), 10, 400, 0, "score");
                al_draw_text(Large_font, al_map_rgb(0, 0, 0), 60, 380, 0, buffer);



             }



}
void
GameWindow::draw_end()
{
    al_draw_filled_circle(140,150,80,al_map_rgb(100, 100, 100));
    al_draw_filled_circle(140,450,80,al_map_rgb(100, 100, 100));
    //al_draw_text(Medium_font, al_map_rgb(0, 200, 200), 100, 270, 0, "restart");
    al_draw_text(Medium_font, al_map_rgb(0, 200, 200), 107, 310, 0, "menu");
    al_draw_text(Medium_font, al_map_rgb(240, 0, 0), 100, 90, 0, "Max");
    al_draw_text(Medium_font, al_map_rgb(240, 0, 0), 110, 115, 0, "Combo");
    al_draw_text(Medium_font, al_map_rgb(240, 0, 0), 90, 400, 0, "Score");

    char buffer[50];

    sprintf(buffer, "%d", maxcombo);
    al_draw_text(Large_font, al_map_rgb(255, 255, 255), 110, 150, 0, buffer);
    sprintf(buffer, "%d", point);
    al_draw_text(Large_font, al_map_rgb(255, 255, 255), 90, 450, 0, buffer);
    FILE *fp,*fpp;
    fp=freopen("best_score.txt", "r",stdin);
    scanf("%d",&n);
    if(point>n){
        fpp=freopen("best_score.txt","w",stdout);
        new_best=true;
        printf("%d",point);
        fclose(fpp);
    }
    fclose(fp);
    if(new_best)al_draw_text(Large_font, al_map_rgb(240, 0, 0), 10, 250, 0,"New Best!");



}

int
GameWindow::process_event()
{

    int instruction = GAME_CONTINUE;



    al_wait_for_event(event_queue, &event);

    if(page==1){
        draw_running_map();
        if(event.type==ALLEGRO_EVENT_KEY_DOWN){
            switch(event.keyboard.keycode){
            case ALLEGRO_KEY_DOWN:
                printf("ff\n");
                select++;


                break;
            case ALLEGRO_KEY_UP:
                printf("dd\n");
                select--;
                break;
            case ALLEGRO_KEY_ENTER:
                if(select%3==0){
                        page=3;
                        al_stop_sample_instance(backgroundSound);
                }
                if(select%3==1||select%3==-2)page=2;
                if(select%3==2||select%3==-1)show_err_msg(-1);
                break;

            }
        }


    }
    else if(page==2){
        draw_running_map();
        if(event.type==ALLEGRO_EVENT_KEY_DOWN){
            switch(event.keyboard.keycode){
            case ALLEGRO_KEY_UP:
                select2--;
                if(select2%2==0)Level=1;
                if(select2%2==1||select2%2==-1)Level=2;

                break;
            case ALLEGRO_KEY_DOWN:
                select2++;
                if(select2%2==0)Level=1;
                if(select2%2==1||select2%2==-1)Level=2;
                break;
            case ALLEGRO_KEY_ENTER:
             //   if(select2%2==0)Level=1;
               // if(select2%2==1||select%2==-1)Level=2;
                page=1;

                break;

            }
        }



    }
    else if(page==3){
            draw_running_map();
            //static int  second=0;
            if(second/60==97)(page=4);/////////////////////////////////////////////

            if(event.type==ALLEGRO_EVENT_TIMER){
                if(event.timer.source==timer){
                    second++;
                    if(second%60==0){
                    //    printf("%d\n",second/60);
                    }
                }
                if(event.timer.source==beats){
                    music_pro++;
                    /*if(music_pro%60==0){
                        printf("%d\n",music_pro/60);
                    }*/


                }
                if(event.timer.source==beats2){
                    music_pro2++;
                    /*if(music_pro%60==0){
                        printf("%d\n",music_pro/60);
                    }*/


                }

                if(event.timer.source==miss){

                    t++;
                }
                if(event.timer.source==miss1){
                  //  printf("gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg\n");
                    t1++;
                }
                if(event.timer.source==miss2){
                    t2++;
                }
                if(event.timer.source==miss3){
                    t3++;
                }
                if(event.timer.source==miss4){
                    t4++;
                }

                //-___________________________________________


                  if((event.timer.source==beats2||event.timer.source==timer)&&Level==1){
                std::  vector<Monster*>::iterator it_i;
                for(it_i=monsterset.begin();it_i<monsterset.end();it_i++){
                   (*it_i)->Move();
                }

                std::  vector<Monster1*>::iterator it_i1;
                for(it_i1=monsterset1.begin();it_i1<monsterset1.end();it_i1++){
                   (*it_i1)->Move();
                }

                std::  vector<Monster2*>::iterator it_i2;
                for(it_i2=monsterset2.begin();it_i2<monsterset2.end();it_i2++){
                   (*it_i2)->Move();
                }

                std::  vector<Monster3*>::iterator it_i3;
                for(it_i3=monsterset3.begin();it_i3<monsterset3.end();it_i3++){
                   (*it_i3)->Move();
                }
                std::  vector<Monster4*>::iterator it_i4;
                for(it_i4=monsterset4.begin();it_i4<monsterset4.end();it_i4++){
                   (*it_i4)->Move();
                }



                }



                if((event.timer.source==beats||event.timer.source==timer)&&Level==2){
                std::  vector<Monster*>::iterator it_i;
                for(it_i=monsterset.begin();it_i<monsterset.end();it_i++){
                   (*it_i)->Move();
                }

                std::  vector<Monster1*>::iterator it_i1;
                for(it_i1=monsterset1.begin();it_i1<monsterset1.end();it_i1++){
                   (*it_i1)->Move();
                }

                std::  vector<Monster2*>::iterator it_i2;
                for(it_i2=monsterset2.begin();it_i2<monsterset2.end();it_i2++){
                   (*it_i2)->Move();
                }

                std::  vector<Monster3*>::iterator it_i3;
                for(it_i3=monsterset3.begin();it_i3<monsterset3.end();it_i3++){
                   (*it_i3)->Move();
                }
                std::  vector<Monster4*>::iterator it_i4;
                for(it_i4=monsterset4.begin();it_i4<monsterset4.end();it_i4++){
                   (*it_i4)->Move();
                }



                }



//_______________________________________________
            }


            if(second/60<5&&second%60==0)printf("%d",5-(second/60));
            else if((second/60)==5&&second%60==0){
                //printf("hhhh\n");
                if(Level==2){
                    al_play_sample_instance(music1);
                    al_start_timer(beats);
                }
                if(Level==1){
                    al_play_sample_instance(music2);
                    al_start_timer(beats2);

                }

            }
            else if(second/60>=5) {
        //----------------------------------------------------------------------
            if(music_pro/60.0==f[index]+2.5/*&&music_pro%60==0*/&&Level==2){
                    //printf("%f-----------\n",music_pro/60);
                    index++;
                Monster* m=new Monster;
                monsterset.push_back(m);
         //       printf("pushback!\n");

            }
            if(al_get_timer_count(beats2)+180==g[index]/*&&music_pro%60==0*/&&Level==1){
                    //printf("%f-----------\n",music_pro2/60);
                    index++;
                Monster* m=new Monster;
                monsterset.push_back(m);
    //            printf("pushback!\n");

            }
        //------------------------------------------------------------------------
            if(music_pro/60.0==f1[index1]+2.5/*&&music_pro%60==0*/&&Level==2){
                    index1++;
                Monster1* m=new Monster1;
                monsterset1.push_back(m);

            }
            if(al_get_timer_count(beats2)+180==g1[index1]/*&&music_pro%60==0*/&&Level==1){
                   // printf("%f-----------\n",music_pro2/60);
                    index1++;
                Monster1* m=new Monster1;
                monsterset1.push_back(m);
  //              printf("pushback!\n");

            }



        //------------------------------------------------------------------------
                if(music_pro/60.0==f2[index2]+2.5/*&&music_pro%60==0*/&&Level==2){
                    index2++;
                Monster2* m=new Monster2;
                monsterset2.push_back(m);

                }
                if(al_get_timer_count(beats2)+180==g2[index2]/*&&music_pro%60==0*/&&Level==1){
                 //   printf("%f-----------\n",music_pro2/60);
                    index2++;
                Monster2* m=new Monster2;
                monsterset2.push_back(m);
//                printf("pushback!\n");

            }

        //------------------------------------------------------------------------


            if(music_pro/60.0==f3[index3]+2.5/*&&music_pro%60==0*/&&Level==2){
                    index3++;
                Monster3* m=new Monster3;
                monsterset3.push_back(m);

            }
            if(al_get_timer_count(beats2)+180==g3[index3]/*&&music_pro%60==0*/&&Level==1){
               //     printf("%f-----------\n",music_pro2/60);
                    index3++;
                Monster3* m=new Monster3;
                monsterset3.push_back(m);
                //printf("pushback!\n");

            }



        //------------------------------------------------------------------------
        if(music_pro/60.0==f4[index4]+2.5/*&&music_pro%60==0*/&&Level==2){
                    index4++;
                Monster4* m=new Monster4;
                monsterset4.push_back(m);

            }
            if(music_pro2/60.0==g4[index4]+2.25/*&&music_pro%60==0*/&&Level==1){
                  //  printf("%f-----------\n",music_pro2/60);
                    index4++;
                Monster4* m=new Monster4;
                monsterset4.push_back(m);
               // printf("pushback!\n");

            }


        //______________________________________________________________________
            if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
                if(Level==1){
                    cout<<al_get_timer_count(beats2)<<endl;

                }

            }
        //_____________________________________________________________________

            if(event.type==ALLEGRO_EVENT_KEY_DOWN){
            switch(event.keyboard.keycode){

            case ALLEGRO_KEY_P:
                //printf("stop_nigga_hold_on\n");
              //  pause=!pause;
                //if(pause)al_set_sample_instance_playing(music1,false);
               // else al_play_sample_instance(music1);
               game_reset();
               game_begin();
               game_run();


                break;
                case ALLEGRO_KEY_F:
                    if(!monsterset.empty()){
                        std::  vector<Monster*>::iterator q=monsterset.begin();
                        if((*q)->pos_y<430){
                            combo=0;
                            printf("too early!!\n");
                            ohoh=true;
                            t=0;
                            y=(*q)->pos_y;
                            al_start_timer(miss);

                            monsterset.erase(q);
                        }

                    }

                    hit=true;

                    break;
                case ALLEGRO_KEY_G:
                    if(!monsterset1.empty()){
                        std::  vector<Monster1*>::iterator q=monsterset1.begin();
                        if((*q)->pos_y<430){
                            combo=0;
                            t1=0;
                            printf("too early!!\n");
                            ohoh1=true;
                            y1=(*q)->pos_y;
                            al_start_timer(miss1);
                //            printf("jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj");
                            monsterset1.erase(q);
                        }

                    }
                    hit1=true;
                      break;
                case ALLEGRO_KEY_H:
                    if(!monsterset2.empty()){
                        std::  vector<Monster2*>::iterator q=monsterset2.begin();
                        if((*q)->pos_y<430){
                            combo=0;
                            printf("too early!!\n");
                            ohoh2=true;
                            t2=0;
                            y2=(*q)->pos_y;
                            al_start_timer(miss2);

                            monsterset2.erase(q);
                        }

                    }
                    hit2=true;

                    break;
                case ALLEGRO_KEY_J:
                    if(!monsterset3.empty()){
                        std::  vector<Monster3*>::iterator q=monsterset3.begin();
                        if((*q)->pos_y<430){
                            combo=0;
                            printf("too early!!\n");
                            ohoh3=true;
                            t3=0;
                            y3=(*q)->pos_y;
                            al_start_timer(miss3);
                            monsterset3.erase(q);
                        }

                    }
                    hit3=true;
                    break;
                    case ALLEGRO_KEY_SPACE:
                    if(!monsterset4.empty()){
                        std::  vector<Monster4*>::iterator q=monsterset4.begin();
                        if((*q)->pos_y<480){
                            combo=0;
                            printf("too early!!\n");
                            ohoh4=true;
                            t4=0;
                            y4=(*q)->pos_y;
                            al_start_timer(miss4);
                            monsterset4.erase(q);
                        }

                    }
                    hit4=true;
                    break;
                    //_______________________
                   /* case ALLEGRO_KEY_R:
                        FILE *fp3=freopen("runaway.txt", "w",stdout);
                        printf("%lld,\n",al_get_timer_count(beats2));
                        fclose(fp3);


                    break;
                    case ALLEGRO_KEY_T:
                        FILE *fp4 =freopen("runaway1.txt", "w",stdout);
                        printf("%lld,\n",al_get_timer_count(beats2));
                        fclose(fp4);

                    break;
                    case ALLEGRO_KEY_Y:
                        FILE *fp5=freopen("runaway2.txt", "w",stdout);
                        printf("%lld,\n",al_get_timer_count(beats2));
                        fclose(fp5);

                    break;
                    case ALLEGRO_KEY_U:
                        FILE* fp6=freopen("runaway3.txt", "w",stdout);
                        printf("%lld,\n",al_get_timer_count(beats2));
                        fclose(fp6);

                    break;*/








                    //_______________________
            }

            /*if(!monsterset.empty()){
                    std::  vector<Monster*>::iterator q=monsterset.begin();
               if(hit&&((*q)->pos_y>400&&(*q)->pos_y<500)){
                    monsterset.erase(q);
               printf("hit!!\n");

               }
               else if((*q)->pos_y>500){
               monsterset.erase(q);

               printf("miss...\n");


               }

                    }*/


            }
            if(!monsterset.empty()){
                    std::  vector<Monster*>::iterator q=monsterset.begin();
               if(hit&&((*q)->pos_y>430&&(*q)->pos_y<520)){
                    monsterset.erase(q);
             //  printf("hit!!\n");
               if(combo_level==1)point+=10;
               if(combo_level==2)point+=20;
               if(combo_level==3)point+=40;
               if(combo_level==4)point+=80;
               if(combo_level==5)point+=160;
               combo++;
               if(combo>maxcombo) maxcombo++;

               }
               else if((*q)->pos_y>520){
               monsterset.erase(q);

               //printf("miss...\n");
               combo=0;


               }

                    }

            if(!monsterset1.empty()){
                    std::  vector<Monster1*>::iterator q=monsterset1.begin();
               if(hit1&&((*q)->pos_y>430&&(*q)->pos_y<520)){
                    monsterset1.erase(q);
               //printf("hit!!\n");
               if(combo_level==1)point+=10;
               if(combo_level==2)point+=20;
               if(combo_level==3)point+=40;
               if(combo_level==4)point+=80;
               if(combo_level==5)point+=160;
               combo++;
                if(combo>maxcombo) maxcombo++;

               }
               else if((*q)->pos_y>520){
               monsterset1.erase(q);

              // printf("miss...\n");
               combo=0;


               }

                    }
            if(!monsterset2.empty()){
                    std::  vector<Monster2*>::iterator q=monsterset2.begin();
               if(hit2&&((*q)->pos_y>430&&(*q)->pos_y<520)){
                    monsterset2.erase(q);
               //printf("hit!!\n");
               if(combo_level==1)point+=10;
               if(combo_level==2)point+=20;
               if(combo_level==3)point+=40;
               if(combo_level==4)point+=80;
               if(combo_level==5)point+=160;
               combo++;
                if(combo>maxcombo) maxcombo++;


               }
               else if((*q)->pos_y>520){
               monsterset2.erase(q);

               //printf("miss...\n");
                combo=0;

               }

                    }
            if(!monsterset3.empty()){
                    std::  vector<Monster3*>::iterator q=monsterset3.begin();
               if(hit3&&((*q)->pos_y>430&&(*q)->pos_y<520)){
                    monsterset3.erase(q);
               //printf("hit!!\n");
               if(combo_level==1)point+=10;
               if(combo_level==2)point+=20;
               if(combo_level==3)point+=40;
               if(combo_level==4)point+=80;
               if(combo_level==5)point+=160;
               combo++;
                if(combo>maxcombo) maxcombo++;

               }
               else if((*q)->pos_y>520){
               monsterset3.erase(q);

               //printf("miss...\n");
               combo=0;


               }

                    }
                    if(!monsterset4.empty()){
                    std::  vector<Monster4*>::iterator q=monsterset4.begin();
               if(hit4&&((*q)->pos_y>480&&(*q)->pos_y<570)){
                    monsterset4.erase(q);
               //printf("hit!!\n");
               if(combo_level==1)point+=10;
               if(combo_level==2)point+=20;
               if(combo_level==3)point+=40;
               if(combo_level==4)point+=80;
               if(combo_level==5)point+=160;
               combo++;
                if(combo>maxcombo) maxcombo++;

               }
               else if((*q)->pos_y>570){
               monsterset4.erase(q);

              // printf("miss...\n");
               combo=0;


               }

                    }
                //________________
                if(combo>=80)combo_level=5;
                else if(combo>=60)combo_level=4;
                else if(combo>=40)combo_level=3;
                else if(combo>=20)combo_level=2;
                else combo_level=1;




                //__________________





        }



    }
    if(page==4){
        al_stop_sample_instance(music1);
        al_stop_sample_instance(music2);
        al_play_sample_instance(finish);
        al_stop_timer(beats);
        al_stop_timer(beats2);

        al_stop_timer(timer);
        draw_running_map();
        if(event.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
            if(event.mouse.x>105&&event.mouse.x<175&&event.mouse.y>270&&event.mouse.y<290){
                printf("restart!\n");
            }
            if(event.mouse.x>107&&event.mouse.x<172&&event.mouse.y>310&&event.mouse.y<330){
                printf("menu!\n");
                game_reset();
                game_begin();
                game_run();


            }



        }


    }

    return instruction;

}

void
GameWindow::draw_running_map()
{


    if(page==1){
        if(select%3==0){
        al_draw_bitmap(manu, 0, 0, 0);
        al_draw_filled_rectangle(300, 300, 500, 350, al_map_rgb(100, 0, 0));
        al_draw_filled_rectangle(300, 370, 500, 420, al_map_rgb(100, 100, 100));
        al_draw_filled_rectangle(300, 440, 500, 490, al_map_rgb(100, 100, 100));
        al_draw_text(manufont, al_map_rgb(0, 255, 255), 310, 300, 0, "Start");
        al_draw_text(manufont, al_map_rgb(0, 255, 255), 313, 370, 0, "Level");
        al_draw_text(manufont, al_map_rgb(0, 255, 255), 333, 440, 0, "Quit");
       // al_flip_display();

        }else if(select%3==1||select%3==-2){
        al_draw_bitmap(manu, 0, 0, 0);
        al_draw_filled_rectangle(300, 300, 500, 350, al_map_rgb(100, 100, 100));
        al_draw_filled_rectangle(300, 370, 500, 420, al_map_rgb(100, 0, 0));
        al_draw_filled_rectangle(300, 440, 500, 490, al_map_rgb(100, 100, 100));
        al_draw_text(manufont, al_map_rgb(0, 255, 255), 310, 300, 0, "Start");
        al_draw_text(manufont, al_map_rgb(0, 255, 255), 313, 370, 0, "Level");
        al_draw_text(manufont, al_map_rgb(0, 255, 255), 333, 440, 0, "Quit");
        //al_flip_display();
        }else if(select%3==2||select%3==-1){
        al_draw_bitmap(manu, 0, 0, 0);
        al_draw_filled_rectangle(300, 300, 500, 350, al_map_rgb(100, 100, 100));
        al_draw_filled_rectangle(300, 370, 500, 420, al_map_rgb(100, 100, 100));
        al_draw_filled_rectangle(300, 440, 500, 490, al_map_rgb(100, 0, 0));
        al_draw_text(manufont, al_map_rgb(0, 255, 255), 310, 300, 0, "Start");
        al_draw_text(manufont, al_map_rgb(0, 255, 255), 313, 370, 0, "Level");
        al_draw_text(manufont, al_map_rgb(0, 255, 255), 333, 440, 0, "Quit");

        }


        al_flip_display();

    }
    else if(page==2){
        if(Level==1){
            al_draw_bitmap(LevelBackground, 0, 0, 0);
            //al_draw_text(Large_font, al_map_rgb(255, 255, 255), 10, 200, 0, "level2");
            al_draw_text(Levelfont, al_map_rgb(0, 255, 255), 400, 300, 0, "Easy");

        }

        if(Level==2){
            al_draw_bitmap(LevelBackground, -840, 0, 0);
           // al_draw_text(Large_font, al_map_rgb(255, 255, 255), 10, 200, 0, "level3");
           al_draw_text(Levelfont, al_map_rgb(0, 255, 255), 50, 300, 0, "Hard");


        }


        al_flip_display();

    }

    else if(page==3){
            if(combo_level==1){
                al_draw_bitmap(background, -140, 0, 0);

            }
            if(combo_level==2){
                al_draw_bitmap(l2bg, -150, 0, 0);
                al_draw_text(Large_font, al_map_rgb(255, 255, 255), 10, 200, 0, "level2");


            }
            if(combo_level==3){
                al_draw_bitmap(l3bg, -103, 0, 0);
                al_draw_text(Large_font, al_map_rgb(255, 0, 0), 10, 200, 0, "level3");


            }
            if(combo_level==4){
                    al_draw_bitmap(l4bg, -150, 0, 0);
                    al_draw_text(Large_font, al_map_rgb(255, 0,0 ), 10, 200, 0, "level4");


            }
            if(combo_level==5){
                al_draw_bitmap(l5bg, -150, 0, 0);
                al_draw_text(Large_font, al_map_rgb(0, 0, 0), 10, 200, 0, "level5");

            }

        //al_draw_bitmap(background, -150, 0, 0);
        draw_menu();
        if(second/60<=5){
                if(second/60==0)al_draw_text(manufont, al_map_rgb(255, 255, 255), 380, 280, 0, "5");
                if(second/60==1)al_draw_text(manufont, al_map_rgb(230, 230, 230), 380, 280, 0, "4");
                if(second/60==2)al_draw_text(manufont, al_map_rgb(200, 200, 200), 380, 280, 0, "3");
                if(second/60==3)al_draw_text(manufont, al_map_rgb(230, 200, 200), 380, 280, 0, "2");
                if(second/60==4)al_draw_text(manufont, al_map_rgb(230, 190, 180), 380, 280, 0, "1");
                if(second/60==5)al_draw_text(manufont, al_map_rgb(0, 255, 255), 300, 280, 0, "Start!");

        }else{
            //-------------------------------------------------

          std::  vector<Monster*>::iterator it_i;
        for(it_i=monsterset.begin();it_i<monsterset.end();it_i++){
            (*it_i)->Draw();

        }
        //-------------------------------------------------------
        std::  vector<Monster1*>::iterator it_i1;
        for(it_i1=monsterset1.begin();it_i1<monsterset1.end();it_i1++){
            (*it_i1)->Draw();

        }

        //-------------------------------------------------------
        std::  vector<Monster2*>::iterator it_i2;
        for(it_i2=monsterset2.begin();it_i2<monsterset2.end();it_i2++){
            (*it_i2)->Draw();

        }
        //-------------------------------------------------------
        std::  vector<Monster3*>::iterator it_i3;
        for(it_i3=monsterset3.begin();it_i3<monsterset3.end();it_i3++){
            (*it_i3)->Draw();
          //  printf("%d",(*it_i3)->pos_y);

        }
        //--------------------------------------------------------
         std::  vector<Monster4*>::iterator it_i4;
        for(it_i4=monsterset4.begin();it_i4<monsterset4.end();it_i4++){
            (*it_i4)->Draw();
          //  printf("%d",(*it_i3)->pos_y);

        }
        //____________________________



        }



     al_flip_display();

    }
    if(page==4){
            al_draw_bitmap(endbackground, -20, 0, 0);
            draw_end();
            al_flip_display();

    }

}
