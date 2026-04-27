/** @file yabool.h
  * @author asaeppel4231
  * @version 0.1
  * @brief Drop-in replacement of stdbool.h to make my programs and other ya- libraries ANSI C compatible.
  *
  * This header defines the `yabool` type and related helper functions.
  * It is designed to be minimal, portable, and usable in ANSI C environments where stdbool.h is not available.
*/

#ifndef YABOOL_H
#define YABOOL_H

#include <stddef.h> //!< Just included for the NULL pointer

/**
 * @typedef yabool
 * @brief Boolean type (optionally) used by the ya-framework.
 *
 * This is an unsigned char that represents boolean values in ANSI C.
 * Use YATRUE and YAFALSE instead of 1 and 0 for clarity.
 */
typedef unsigned char yabool;

/**
 * @def YATRUE
 * @brief Boolean true value for yabool.
 */
#define YATRUE 1

/**
 * @def YAFALSE
 * @brief Boolean false value for yabool.
 */
#define YAFALSE 0

/**
 * @brief Checks whether a yabool value is false.
 * @param boolean The value to check.
 * @return 1 if false, 0 otherwise.
 */
static inline int yabool_is_false(yabool boolean){
    return boolean == YAFALSE;
}

/**
 * @brief Checks whether a yabool value is true.
 * @param boolean The value to check.
 * @return 1 if true, 0 otherwise.
 */
static inline int yabool_is_true(yabool boolean){
    return boolean == YATRUE;
}

/**
 * @brief Sets a yabool variable to false.
 * @param boolean Pointer to the variable to modify.
 * @return YATRUE on success, YAFALSE if the pointer is NULL.
 */
static inline int yabool_set_false(yabool* boolean){
    if(boolean == NULL){
        return YAFALSE;
    }
    *boolean = YAFALSE;
    return YATRUE;
}


/**
 * @brief Sets a yabool variable to true.
 * @param boolean Pointer to the variable to modify.
 * @return YATRUE on success, YAFALSE if the pointer is NULL.
 */
static inline int yabool_set_true(yabool* boolean){
    if(boolean == NULL){
        return YAFALSE;
    }
    *boolean = YATRUE;
    return YATRUE;
}

#endif
