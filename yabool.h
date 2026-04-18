/*
This file is a drop-in-replacement of stdbool.h to make 
h2ot3 ANSI C compatible
*/
#ifndef MBOOL_H
#define MBOOL_H

#include <stddef.h>

typedef unsigned char yabool;

#define MTRUE 1
#define MFALSE 0

static inline int yabool_is_false(yabool boolean){
    return boolean == MFALSE;
}

static inline int yabool_is_true(yabool boolean){
    return boolean == MTRUE;
}

static inline int yabool_set_false(yabool* boolean){
    if(boolean == NULL){
        return MFALSE;
    }
    *boolean = MFALSE;
    return MTRUE; 
}

static inline int yabool_set_true(yabool* boolean){
    if(boolean == NULL){
        return MFALSE;
    }
    *boolean = MTRUE;
    return MTRUE;
}

#endif
