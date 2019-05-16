#include "logic.h"
#include "draw.h"
#include "images/grayBlock.h"

int pieces[7/*pieces*/][4/*rotations*/][4/*rows*/][4/*cols*/] = {
    { // I
        { // Rotation 1
            {0, 0, 0, 0},
            {1, 1, 1, 1},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        { // Rotation 2
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0}
        },
        { // Rotation 3
            {0, 0, 0, 0},
            {1, 1, 1, 1},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        { // Rotation 4
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0},
            {0, 0, 1, 0}
        }
    },

    { // O
        { // Rotation 1
            {0, 0, 0, 0},
            {0, 2, 2, 0},
            {0, 2, 2, 0},
            {0, 0, 0, 0},
        },
        { // Rotation 2
            {0, 0, 0, 0},
            {0, 2, 2, 0},
            {0, 2, 2, 0},
            {0, 0, 0, 0},
        },
        { // Rotation 2
            {0, 0, 0, 0},
            {0, 2, 2, 0},
            {0, 2, 2, 0},
            {0, 0, 0, 0},
        },
        { // Rotation 2
            {0, 0, 0, 0},
            {0, 2, 2, 0},
            {0, 2, 2, 0},
            {0, 0, 0, 0},
        }
    },

    { // T
        { // Rotation 1
            {0, 0, 3, 0},
            {0, 3, 3, 3},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
        },
        { // Rotation 2
            {0, 0, 3, 0},
            {0, 0, 3, 3},
            {0, 0, 3, 0},
            {0, 0, 0, 0},
        },
        { // Rotation 3
            {0, 0, 0, 0},
            {0, 3, 3, 3},
            {0, 0, 3, 0},
            {0, 0, 0, 0},
        },
        { // Rotation 4
            {0, 0, 3, 0},
            {0, 3, 3, 0},
            {0, 0, 3, 0},
            {0, 0, 0, 0},
        }
    },

    { // J
        { // Rotation 1
            {0, 0, 4, 0},
            {0, 0, 4, 0},
            {0, 4, 4, 0},
            {0, 0, 0, 0},
        },
        { // Rotation 2
            {0, 4, 0, 0},
            {0, 4, 4, 4},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
        },
        { // Rotation 3
            {0, 0, 4, 4},
            {0, 0, 4, 0},
            {0, 0, 4, 0},
            {0, 0, 0, 0},
        },
        { // Rotation 4
            {0, 0, 0, 0},
            {0, 4, 4, 4},
            {0, 0, 0, 4},
            {0, 0, 0, 0},
        }
    },

    { // L
        { // Rotation 1
            {0, 0, 5, 0},
            {0, 0, 5, 0},
            {0, 0, 5, 5},
            {0, 0, 0, 0},
        },
        { // Rotation 2
            {0, 0, 0, 0},
            {0, 5, 5, 5},
            {0, 5, 0, 0},
            {0, 0, 0, 0},
        },
        { // Rotation 3
            {0, 5, 5, 0},
            {0, 0, 5, 0},
            {0, 0, 5, 0},
            {0, 0, 0, 0},
        },
        { // Rotation 4
            {0, 0, 0, 5},
            {0, 5, 5, 5},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
        }
    },
    
    { // S
        { // Rotation 1
            {0, 0, 0, 0},
            {0, 0, 6, 6},
            {0, 6, 6, 0},
            {0, 0, 0, 0},
        },
        { // Rotation 2
            {0, 6, 0, 0},
            {0, 6, 6, 0},
            {0, 0, 6, 0},
            {0, 0, 0, 0},
        },
        { // Rotation 3
            {0, 0, 6, 6},
            {0, 6, 6, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
        },
        { // Rotation 4
            {0, 0, 6, 0},
            {0, 0, 6, 6},
            {0, 0, 0, 6},
            {0, 0, 0, 0},
        }
    },

    { // Z
        { // Rotation 1
            {0, 0, 0, 0},
            {0, 7, 7, 0},
            {0, 0, 7, 7},
            {0, 0, 0, 0},
        },
        { // Rotation 2
            {0, 0, 7, 0},
            {0, 7, 7, 0},
            {0, 7, 0, 0},
            {0, 0, 0, 0},
        },
        { // Rotation 3
            {0, 7, 7, 0},
            {0, 0, 7, 7},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
        },
        { // Rotation 4
            {0, 0, 0, 7},
            {0, 0, 7, 7},
            {0, 0, 7, 0},
            {0, 0, 0, 0},
        }
    }
};

int horzTimer = 0;
int currentPiece[4][4];

void initializeAppState(AppState* appState) {
    // TA-TODO: Initialize everything that's part of this AppState struct here.
    // Suppose the struct contains random values, make sure everything gets
    // the value it should have when the app begins.

    // clear all blocks in the stage
    for (int r = 0; r < STAGE_HEIGHT; r++) {
        for (int c = 0; c < STAGE_WIDTH; c++) {
            appState->stage[r][c] = 0;
        }
    }

    appState->currentRate = 60;
    appState->normalRate = 60;
    appState->rotation = 0;
    appState->id = 0;
    appState->lines = 0;
    appState->score = 0;
    appState->gameOver = 0;

    spawnPiece(appState);
}

// Add any process functions for sub-elements of your app here.
// For example, for a snake game, you could have a processSnake function
// or a createRandomFood function or a processFoods function.

void spawnPiece(AppState *nextAppState) {
    nextAppState->rotation = 0;
    nextAppState->id = randint(0, 7);
    nextAppState->piece_x = STAGE_WIDTH/2 - 2;
    nextAppState->piece_y = -1;
    nextAppState->canFastFall = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            currentPiece[i][j] = pieces[nextAppState->id]
                                       [nextAppState->rotation]
                                       [i][j];
}

/**
 * Takes in the current app state and returns whether or not we can place
 * the new piece at the given coordinates (piecex, piecey).
 * 0 -> blocked L/R
 * 1 -> can place!
 * 2 -> blocked downwards
 **/
int canPlace(AppState *currentAppState, int piece[4][4], int piecex, int piecey) {
    // iterate through all the squares of the piece
    for (int px = 0; px < 4; px++) {
        for (int py = 0; py < 4; py++) {
            int coordx = piecex + px;
            int coordy = piecey + py;
            if (piece[py][px] != 0) {
                if (coordx < 0 || coordx >= STAGE_WIDTH) {
                    return BLOCKED_LR;
                } else if (coordy >= STAGE_HEIGHT
                        || currentAppState->stage[coordy][coordx] != 0) {
                    return BLOCKED_DOWN;
                }
            }
        }
    }
    return CAN_PLACE;
}

/**
 * Permanently place the piece on the board.
 * Assumes that the placement is already valid, so don't mess it up.
 **/
void place(AppState *nextAppState, int piecex, int piecey) {
    for (int px = 0; px < 4; px++) {
        for (int py = 0; py < 4; py++) {
            int coordx = piecex + px;
            int coordy = piecey + py;
            if (currentPiece[py][px] != 0) {
                nextAppState->stage[coordy][coordx] = currentPiece[py][px];
            }
        }
    }
    nextAppState->score += 10;
}

void rotate(AppState *nextAppState, AppState *currentAppState, int dir) {
    UNUSED(nextAppState); UNUSED(currentAppState);
    if (dir == LEFT) {
        int newRot = (currentAppState->rotation - 1);
        if (newRot < 0) newRot = 3;
        switch(canPlace(currentAppState,
                pieces[currentAppState->id][newRot],
                currentAppState->piece_x, 
                currentAppState->piece_y)) {
            case CAN_PLACE:
                nextAppState->rotation = newRot;
                for (int i = 0; i < 4; i++)
                    for (int j = 0; j < 4; j++)
                        currentPiece[i][j] = pieces[nextAppState->id]
                                                [nextAppState->rotation]
                                                [i][j];
                break;
            case BLOCKED_LR:
                break;
            case BLOCKED_DOWN:
                break;
        }
    } else if (dir == RIGHT) {
        int newRot = (currentAppState->rotation + 1) % 4;
        switch(canPlace(currentAppState,
                pieces[currentAppState->id][newRot],
                currentAppState->piece_x, 
                currentAppState->piece_y)) {
            case CAN_PLACE:
                nextAppState->rotation = newRot;
                for (int i = 0; i < 4; i++)
                    for (int j = 0; j < 4; j++)
                        currentPiece[i][j] = pieces[nextAppState->id]
                                                [nextAppState->rotation]
                                                [i][j];
                break;
            case BLOCKED_LR:
                break;
            case BLOCKED_DOWN:
                break;
        }
    }
}

void removeCompletedLines(AppState *nextAppState) {
    // check for loss
    for (int x = 0; x < STAGE_WIDTH; x++) {
        if (nextAppState->stage[0][x] > 0) {
            nextAppState->gameOver = 1;
        }
    }
    // check the rest of the board
    if (nextAppState->gameOver != 1) {
        for (int y = STAGE_HEIGHT - 1; y > 0; y--) {
            unsigned char isComplete = 1;
            for (int x = 0; x < STAGE_WIDTH; x++) {
                if (nextAppState->stage[y][x] == 0) {
                    isComplete = 0;
                }
            }
            if (isComplete == 1) {
                for (int yc = y; yc > 0; yc--) {
                    for (int x = 0; x < STAGE_WIDTH; x++) {
                        nextAppState->stage[yc][x] = nextAppState->stage[yc - 1][x];
                    }
                }
                nextAppState->lines += 1;
                nextAppState->score += 100;
                y++;
            }
        }
        switch (nextAppState->lines) {
            case 10: nextAppState->normalRate = 25;
                break;
            case 20: nextAppState->normalRate = 20;
                break;
            case 30: nextAppState->normalRate = 15;
                break;
            case 40: nextAppState->normalRate = 10;
                break;
            case 50: nextAppState->normalRate = 5;
                break;
        }
    }
}

void drawGrayBlocks(int r, int c) {
    drawImageDMA(H_OFFSET+c*(MARGIN+SCALE_FACTOR), V_OFFSET+r*(MARGIN+SCALE_FACTOR),
            7, 7, grayBlock);
}

// This function processes your current app state and returns the new (i.e. next)
// state of your application.
AppState processAppState(AppState *currentAppState, u32 keysPressedBefore, u32 keysPressedNow) {
    /* TA-TODO: Do all of your app processing here. This function gets called
     * every frame.
     *
     * To check for key presses, use the KEY_JUST_PRESSED macro for cases where
     * you want to detect each key press once, or the KEY_DOWN macro for checking
     * if a button is still down.
     *
     * To count time, suppose that the GameBoy runs at a fixed FPS (60fps) and
     * that VBlank is processed once per frame. Use the vBlankCounter variable
     * and the modulus % operator to do things once every (n) frames. Note that
     * you want to process button every frame regardless (otherwise you will
     * miss inputs.)
     *
     * Do not do any drawing here.
     *
     * TA-TODO: VERY IMPORTANT! READ THIS PART.
     * You need to perform all calculations on the currentAppState passed to you,
     * and perform all state updates on the nextAppState state which we define below
     * and return at the end of the function. YOU SHOULD NOT MODIFY THE CURRENTSTATE.
     * Modifying the currentAppState will mean the undraw function will not be able
     * to undraw it later.
     */

    AppState nextAppState = *currentAppState;
    int px = currentAppState->piece_x;
    int py = currentAppState->piece_y;

    if (vBlankCounter % currentAppState->currentRate == 0) {
        switch(canPlace(currentAppState, currentPiece, px, py + 1)) {
            case CAN_PLACE:
                nextAppState.piece_y = py + 1;
                break;
            case BLOCKED_LR:
                break;
            case BLOCKED_DOWN:
                place(&nextAppState, px, py);
                removeCompletedLines(&nextAppState);
                spawnPiece(&nextAppState);
                break;
        }
    }

    if (KEY_JUST_PRESSED(BUTTON_LEFT, keysPressedNow, keysPressedBefore)) {
        switch(canPlace(currentAppState, currentPiece, px - 1, py)) {
            case CAN_PLACE:
                nextAppState.piece_x -= 1;
                break;
            case BLOCKED_LR:
                break;
            case BLOCKED_DOWN:
                break;
        }
    } else if (KEY_JUST_PRESSED(BUTTON_RIGHT, keysPressedNow, 
            keysPressedBefore)) {
        switch(canPlace(currentAppState, currentPiece, px + 1, py)) {
            case CAN_PLACE:
                nextAppState.piece_x += 1;
                break;
            case BLOCKED_LR:
                break;
            case BLOCKED_DOWN:
                break;
        }
    }

    if (KEY_HELD(BUTTON_LEFT, keysPressedNow, keysPressedBefore)) {
        horzTimer += 1;
        if (horzTimer > MOV_DELAY && vBlankCounter % 3 == 0) {
            switch(canPlace(currentAppState, currentPiece, px - 1, py)) {
                case CAN_PLACE:
                    nextAppState.piece_x -= 1;
                    break;
                case BLOCKED_LR:
                    break;
                case BLOCKED_DOWN:
                    break;
            }
        }
    } else if (KEY_HELD(BUTTON_RIGHT, keysPressedNow, keysPressedBefore)) {
        horzTimer += 1;
        if (horzTimer > MOV_DELAY && vBlankCounter % 3 == 0) {
            switch(canPlace(currentAppState, currentPiece, px + 1, py)) {
                case CAN_PLACE:
                    nextAppState.piece_x += 1;
                    break;
                case BLOCKED_LR:
                    break;
                case BLOCKED_DOWN:
                    break;
            }
        }
    } else {
        horzTimer = 0;
    }

    if (KEY_JUST_PRESSED(BUTTON_A, keysPressedNow, keysPressedBefore)) {
        rotate(&nextAppState, currentAppState, LEFT);
    } else if (KEY_JUST_PRESSED(BUTTON_B, keysPressedNow, keysPressedBefore)) {
        rotate(&nextAppState, currentAppState, RIGHT);
    }

    if (KEY_JUST_PRESSED(BUTTON_DOWN, keysPressedNow, keysPressedBefore)) {
        nextAppState.canFastFall = 1;
    }

    if (KEY_DOWN(BUTTON_DOWN, keysPressedNow)) {
        if (currentAppState->canFastFall == 1) {
            nextAppState.currentRate = 3;
            nextAppState.score += 2;
        }
    } else {
        nextAppState.currentRate = nextAppState.normalRate;
    }

    UNUSED(keysPressedBefore);
    UNUSED(keysPressedNow);

    return nextAppState;
}
