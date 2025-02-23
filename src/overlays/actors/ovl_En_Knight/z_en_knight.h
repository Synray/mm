#ifndef Z_EN_KNIGHT_H
#define Z_EN_KNIGHT_H

#include "global.h"

struct EnKnight;

typedef void (*EnKnightActionFunc)(struct EnKnight*, PlayState*);

typedef struct EnKnight {
    /* 0x000 */ Actor actor;
    /* 0x144 */ s16 unk_144;
    /* 0x146 */ char unk_146[0x2];
    /* 0x148 */ s8 unk_148;
    /* 0x149 */ char pad149[8];
    /* 0x151 */ s8 unk_151;
    /* 0x152 */ char pad152[1];
    /* 0x153 */ u8 unk_153;
    /* 0x154 */ u8 unk_154;
    /* 0x155 */ char pad155[0x2CB];
    /* 0x420 */ EnKnightActionFunc actionFunc;
    /* 0x424 */ char unk_424[0x25C];
    /* 0x680 */ u8 unk_680;
    /* 0x681 */ char pad681[9];
    /* 0x68A */ s16 unk_68A;
    /* 0x68C */ char pad68C[0x48];
} EnKnight; // size = 0x6D4

extern const ActorInit En_Knight_InitVars;

#endif // Z_EN_KNIGHT_H
