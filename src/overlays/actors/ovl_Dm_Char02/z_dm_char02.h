#ifndef Z_DM_CHAR02_H
#define Z_DM_CHAR02_H

#include "global.h"

struct DmChar02;

typedef void (*DmChar02ActionFunc)(struct DmChar02*, PlayState*);

typedef struct DmChar02 {
    /* 0x000 */ Actor actor;
    /* 0x144 */ SkelAnime skelAnime;
    /* 0x188 */ UNK_TYPE1 pad188[0x108];
    /* 0x290 */ DmChar02ActionFunc actionFunc;
    /* 0x294 */ UNK_TYPE1 pad294[0x4C];
    /* 0x2E0 */ s16 animIndex;
    /* 0x2E2 */ UNK_TYPE1 pad2E2[0xE];
    /* 0x2F0 */ u32 unk2F0;
} DmChar02; // size = 0x2F4

extern const ActorInit Dm_Char02_InitVars;

#endif // Z_DM_CHAR02_H
