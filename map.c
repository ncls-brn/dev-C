#include <stdio.h>
#include <stdlib.h>

typedef struct Map{
    int height;
    int width;
}Map;


typedef struct Block {
    int pos_x;
    intpos_y;
    struct Block* top, right, bot, left;
}Block;

typedef struct Player {
        struct Map*map;
        struct Block* position;
        void* move;
}Player;


Map* get_map(int height, int width);
Player* get_player(Map* map);
void load_blocks(Map*map);
void move(Player* player, char direction);
//direction 't','r','b','l'
// assigner une touche du clavier  pour 't','r',b','l'




int maint(){


}

Map* get_map(int height, int width){
    Map*map = malloc(sizeof(Map));
    //height/width
    return map;
}

Player* get_player(Map* map){
    //instence player 
    //player.map = map 
    // player position = somewhere on the map
}

void load_blocks(Map*map){
    //for x in range height
    //save Block block__top[width]
    //      for y in range width
                //save current_block;
                /*Block current_block {
                    top[width],
                    0,
                    0,
                    block_leftr
                }*/
               //current_block, top,right, bot, left
}

