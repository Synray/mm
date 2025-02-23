#ifndef Z_DM_CHAR04_H
#define Z_DM_CHAR04_H

#include "global.h"

struct DmChar04;

typedef void (*DmChar04ActionFunc)(struct DmChar04*, PlayState*);

typedef struct DmChar04 {
    /* 0x000 */ Actor actor;
    /* 0x144 */ char unk_144[0xF8];
    /* 0x23C */ DmChar04ActionFunc actionFunc;
    /* 0x240 */ char unk_240[0x24];
} DmChar04; // size = 0x264

extern const ActorInit Dm_Char04_InitVars;

#endif // Z_DM_CHAR04_H
