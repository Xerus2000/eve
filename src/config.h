#ifndef EVE_CONFIG_H
#define EVE_CONFIG_H

#define MIN_FOOD_SIZE 100.0
#define MAX_FOOD_SIZE 400.0
#define INDIVIDUAL_FOOD_FACTOR 5.0
#define SURVIVAL_THRESHOLD MAX_FOOD_SIZE
#define REPRODUCTION_THRESHOLD 100 + MAX_FOOD_SIZE
#define VISION_RANGE 25.0
#define MOUTH_ANGLE 59

/* Action constants */
#define TURN_RATE 10
#define MOVE_RATE 10

/* Action multiplier */
#define ACTION_FACTOR_MOVE 0.0001
#define ACTION_FACTOR_TURN 0.0001

/* Energy consumption multiplier per action */
#define ENERGY_FACTOR_SLEEP 0.995
#define ENERGY_FACTOR_TURN  0.991
#define ENERGY_FACTOR_MOVE  0.990

/* SDL RENDER PARAMETERS */
/** scaling of individuals and food for easier identification */
#define SCALE_FACTOR 1
/** delay between drawn frames in ms */
#define RENDER_DELAY 10

/* DEBUG CONSTANTS */
#define RENDER_TERMINALVIEW false
#define RENDER_SDLVIEW true

#define AMOUNT_OF_FREDS 10
#define AMOUNT_OF_PIERCIES 0

/* COLOR constants */
#define POINTER_COLOR    0xFFAAAAAA
#define BACKGROUND_COLOR 0xFF000000
#define INDIVIDUAL_COLOR 0xFF00FFFF
#define FOOD_COLOR       0xFF0000FF

#endif //EVE_CONFIG_H
