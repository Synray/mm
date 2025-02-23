#ifndef Z_OBJ_LIFT_H
#define Z_OBJ_LIFT_H

#include "global.h"

struct ObjLift;

typedef void (*ObjLiftActionFunc)(struct ObjLift*, PlayState*);

typedef struct ObjLift {
    /* 0x000 */ Actor actor;
    /* 0x144 */ char unk_144[0x18];
    /* 0x15C */ ObjLiftActionFunc actionFunc;
    /* 0x160 */ char unk_160[0x1C];
} ObjLift; // size = 0x17C

extern const ActorInit Obj_Lift_InitVars;

#endif // Z_OBJ_LIFT_H
