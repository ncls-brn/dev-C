#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

typedef struct Map {
    int height;
    int width;
    struct Block*** blocks; 
} Map;

typedef struct Block {
    int pos_x;
    int pos_y;
    struct Block* top;
    struct Block* right;
    struct Block* bot;
    struct Block* left;
} Block;

typedef struct Player {
    struct Block* position;
} Player;

Map* get_map(int height, int width);
void load_blocks(Map* map);
void move(Player* player, char direction);
char get_input();
void display_map(Map* map, Player* player);

int main() {
    int height = 5, width = 5;

    
    Map* map = get_map(height, width);
    load_blocks(map);

    
    Player player;
    player.position = map->blocks[0][0]; 

    printf("Carte initiale :\n");
    display_map(map, &player);

    char input;
    while (1) {
        printf("Appuyez sur une touche (z: haut, q: gauche, s: bas, d: droite, x: quitter) : ");
        input = get_input();

        if (input == 'x') { 
            printf("\nSortie du jeu.\n");
            break;
        }

        move(&player, input);
        printf("Carte après déplacement :\n");
        display_map(map, &player);
    }

    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            free(map->blocks[i][j]);
        }
        free(map->blocks[i]);
    }
    free(map->blocks);
    free(map);

    return 0;
}


Map* get_map(int height, int width) {
    Map* map = malloc(sizeof(Map));
    if (map == NULL) {
        perror("Erreur d'allocation mémoire pour la carte");
        exit(EXIT_FAILURE);
    }

    map->height = height;
    map->width = width;

    
    map->blocks = malloc(height * sizeof(Block**));
    for (int i = 0; i < height; i++) {
        map->blocks[i] = malloc(width * sizeof(Block*));
        for (int j = 0; j < width; j++) {
            map->blocks[i][j] = NULL;
        }
    }

    return map;
}


void load_blocks(Map* map) {
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            
            Block* current_block = malloc(sizeof(Block));
            if (current_block == NULL) {
                perror("Erreur d'allocation mémoire pour un bloc");
                exit(EXIT_FAILURE);
            }

            current_block->pos_x = i;
            current_block->pos_y = j;

            
            current_block->top = (i > 0) ? map->blocks[i - 1][j] : NULL;
            current_block->right = (j < map->width - 1) ? map->blocks[i][j + 1] : NULL;
            current_block->bot = (i < map->height - 1) ? map->blocks[i + 1][j] : NULL;
            current_block->left = (j > 0) ? map->blocks[i][j - 1] : NULL;

            
            map->blocks[i][j] = current_block;

            
            if (current_block->top) {
                current_block->top->bot = current_block;
            }
            if (current_block->left) {
                current_block->left->right = current_block;
            }
        }
    }
}


void move(Player* player, char direction) {
    Block* current_position = player->position;

    switch (direction) {
        case 'z': 
            if (current_position->top) {
                player->position = current_position->top;
                printf("Vous vous déplacez vers le haut.\n");
            } else {
                printf("Déplacement impossible (haut bloqué).\n");
            }
            break;
        case 'd': 
            if (current_position->right) {
                player->position = current_position->right;
                printf("Vous vous déplacez vers la droite.\n");
            } else {
                printf("Déplacement impossible (droite bloquée).\n");
            }
            break;
        case 's': 
            if (current_position->bot) {
                player->position = current_position->bot;
                printf("Vous vous déplacez vers le bas.\n");
            } else {
                printf("Déplacement impossible (bas bloqué).\n");
            }
            break;
        case 'q': 
            if (current_position->left) {
                player->position = current_position->left;
                printf("Vous vous déplacez vers la gauche.\n");
            } else {
                printf("Déplacement impossible (gauche bloqué).\n");
            }
            break;
        default:
            printf("Touche non reconnue.\n");
    }
}


char get_input() {
    struct termios oldt, newt;
    char ch;
 
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

void display_map(Map* map, Player* player) {
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            if (player->position == map->blocks[i][j]) {
                printf(" P "); 
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}
