#ifndef Z_EN_ISHI_H
#define Z_EN_ISHI_H

#include "global.h"

struct EnIshi;

typedef void (*EnIshiActionFunc)(struct EnIshi*, PlayState*);
typedef void (*EnIshiUnkFunc)(struct EnIshi*, PlayState*);
typedef void (*EnIshiUnkFunc2)(Actor*, PlayState*);

#define ENISHI_GET_1(thisx) ((thisx)->params & 1)
#define ENISHI_GET_2(thisx) (((thisx)->params >> 1) & 1)
#define ENISHI_GET_4(thisx) (((thisx)->params >> 2) & 1)
#define ENISHI_GET_8(thisx) (((thisx)->params >> 3) & 1)
#define ENISHI_GET_70(thisx) (((thisx)->params >> 4) & 7)
#define ENISHI_GET_F0(thisx) (((thisx)->params >> 4) & 0xF)
#define ENISHI_GET_100(thisx) (((thisx)->params >> 8) & 1)
#define ENISHI_GET_FE00(thisx) (((thisx)->params >> 9) & 0x7F)

typedef struct EnIshi {
    /* 0x000 */ Actor actor;
    /* 0x144 */ ColliderCylinder collider;
    /* 0x190 */ EnIshiActionFunc actionFunc;
    /* 0x194 */ s8 unk_194;
    /* 0x195 */ s8 unk_195;
    /* 0x196 */ s8 unk_196;
    /* 0x197 */ u8 unk_197;
} EnIshi; // size = 0x198

extern const ActorInit En_Ishi_InitVars;

#endif // Z_EN_ISHI_H
