/**
 * @file robot_main.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-06-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>

#include "robot.cpp"
#include "robot_cntrl.cpp"

int main(int argc, char **argv);

int main(int argc, char **argv) {
    robot_cntrl_t robot_cntrl;
    robot_cntrl_init(&robot_cntrl);
    robot_t robot;
    robot_init(&robot);
    robot_cntrl_move_forward(&robot_cntrl, &robot, 10);
    robot_cntrl_move_backward(&robot_cntrl, &robot, 10);
    robot_cntrl_turn_right(&robot_cntrl, &robot, 90);
    robot_cntrl_turn_left(&robot_cntrl, &robot, 90);
    return 0;
}