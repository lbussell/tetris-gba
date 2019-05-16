#ifndef LOGIC_H
#define LOGIC_H

#define STAGE_HEIGHT 21
#define STAGE_WIDTH 10
#define NUM_PIECES 7

#define WINNING_LINES 50

#define BLOCKED_LR 0
#define CAN_PLACE 1
#define BLOCKED_DOWN 2

#define LEFT -1
#define RIGHT 1

#define MOV_DELAY 10

#include "gba.h"


/**
 * AppState stores all information about the state that the game is in.
 **/
typedef struct {
    int stage[STAGE_HEIGHT][STAGE_WIDTH];
    int piece_x;
    int piece_y;
    int id;
    int rotation;
    int normalRate;
    int currentRate;
    int canFastFall;
    int lines;
    int score;
    int gameOver;
} AppState;

/**
 * We can add additional structs here (if needed) to help with game development.
 **/

extern int currentPiece[4][4];


/**
 * Initialize a brand new AppState struct and set the variables to what they
 * should be.
 **/
void initializeAppState(AppState *appState);

/**
 * This function processes app frames.
 **/
AppState processAppState(AppState *currentAppState, u32 keysPressedBefore,
                         u32 keysPressedNow);

void spawnPiece(AppState *nextAppState);

int canPlace(AppState *currentAppState, int piece[4][4], int piecex, int piecey);

void place(AppState *nextAppState, int piecex, int piecey);

void rotate(AppState *nextAppState, AppState *currentAppState, int dir);

void removeCompletedLines(AppState *nextAppState);

void drawGrayBlocks(int r, int c);

#endif
