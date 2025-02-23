/*
 * File: z_en_syateki_man.c
 * Overlay: ovl_En_Syateki_Man
 * Description: Shooting Gallery Man
 */

#include "z_en_syateki_man.h"

#define FLAGS (ACTOR_FLAG_1 | ACTOR_FLAG_8 | ACTOR_FLAG_10 | ACTOR_FLAG_8000000)

#define THIS ((EnSyatekiMan*)thisx)

void EnSyatekiMan_Init(Actor* thisx, PlayState* play);
void EnSyatekiMan_Destroy(Actor* thisx, PlayState* play);
void EnSyatekiMan_Update(Actor* thisx, PlayState* play);
void EnSyatekiMan_Draw(Actor* thisx, PlayState* play);

void func_809C6810(EnSyatekiMan* this, PlayState* play);
void func_809C6848(EnSyatekiMan* this, PlayState* play);
void func_809C6E30(EnSyatekiMan* this, PlayState* play);
void func_809C72D8(EnSyatekiMan* this, PlayState* play);
void func_809C7990(EnSyatekiMan* this, PlayState* play);
void func_809C7A90(EnSyatekiMan* this, PlayState* play);
void func_809C7C14(EnSyatekiMan* this, PlayState* play);
void func_809C7D14(EnSyatekiMan* this, PlayState* play);
void func_809C7EB4(EnSyatekiMan* this, PlayState* play);
void func_809C7FFC(EnSyatekiMan* this, PlayState* play);
void func_809C80C0(EnSyatekiMan* this, PlayState* play);
void func_809C81D0(EnSyatekiMan* this, PlayState* play);
void func_809C8488(EnSyatekiMan* this, PlayState* play);
void func_809C8610(EnSyatekiMan* this, PlayState* play);
void func_809C8710(EnSyatekiMan* this, PlayState* play);
void func_809C8808(EnSyatekiMan* this, PlayState* play);
void func_809C898C(EnSyatekiMan* this, PlayState* play);
void func_809C8BF0(EnSyatekiMan* this, PlayState* play);

const ActorInit En_Syateki_Man_InitVars = {
    ACTOR_EN_SYATEKI_MAN,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_SHN,
    sizeof(EnSyatekiMan),
    (ActorFunc)EnSyatekiMan_Init,
    (ActorFunc)EnSyatekiMan_Destroy,
    (ActorFunc)EnSyatekiMan_Update,
    (ActorFunc)EnSyatekiMan_Draw,
};

static AnimationInfo sAnimations[] = {
    { &gBurlyGuyHandsOnTableAnim, 1.0f, 0.0f, 0.0f, ANIMMODE_LOOP, -8.0f },
    { &gSwampShootingGalleryManHeadScratchLoopAnim, 1.0f, 0.0f, 0.0f, ANIMMODE_LOOP, -8.0f },
    { &gSwampShootingGalleryManHeadScratchEndAnim, 1.0f, 0.0f, 0.0f, ANIMMODE_ONCE, -8.0f },
};

static s16 D_809C91C8[] = {
    0x00C1,
    0x0302,
    0x0019,
    0x0026,
};

static EnSyatekiManUnkStruct D_809C91D0[] = {
    { ACTOR_EN_SYATEKI_WF, -1000.0f, 200.0f, -700.0f, 0x130 },
    { ACTOR_EN_SYATEKI_WF, -1000.0f, 200.0f, -700.0f, 0x20 },
    { ACTOR_EN_SYATEKI_DEKUNUTS, -1000.0f, 200.0f, -700.0f, 0x0 },
    { ACTOR_EN_SYATEKI_DEKUNUTS, -1000.0f, 200.0f, -700.0f, 0x10 },
    { ACTOR_EN_SYATEKI_DEKUNUTS, -1000.0f, 200.0f, -700.0f, 0x20 },
    { ACTOR_EN_SYATEKI_DEKUNUTS, -1000.0f, 200.0f, -700.0f, 0x30 },
    { ACTOR_EN_SYATEKI_DEKUNUTS, -1000.0f, 200.0f, -700.0f, 0x40 },
    { ACTOR_EN_SYATEKI_DEKUNUTS, -1000.0f, 200.0f, -700.0f, 0x1 },
    { ACTOR_EN_SYATEKI_DEKUNUTS, -1000.0f, 200.0f, -700.0f, 0x11 },
    { ACTOR_EN_SYATEKI_CROW, -1000.0f, 200.0f, -700.0f, 0x0 },
    { ACTOR_EN_SYATEKI_CROW, -1000.0f, 200.0f, -700.0f, 0x100 },
    { ACTOR_EN_SYATEKI_CROW, -1000.0f, 200.0f, -700.0f, 0x200 },
    { ACTOR_EN_SYATEKI_CROW, -1000.0f, 200.0f, -700.0f, 0x300 },
    { ACTOR_EN_SYATEKI_CROW, -1000.0f, 200.0f, -700.0f, 0x420 },
    { ACTOR_EN_SYATEKI_CROW, -1000.0f, 200.0f, -700.0f, 0x520 },
    { ACTOR_EN_SYATEKI_CROW, -1000.0f, 200.0f, -700.0f, 0x601 },
    { ACTOR_EN_SYATEKI_CROW, -1000.0f, 200.0f, -700.0f, 0x702 },
    { ACTOR_EN_SYATEKI_CROW, -1000.0f, 200.0f, -700.0f, 0x801 },
    { ACTOR_EN_SYATEKI_CROW, -1000.0f, 200.0f, -700.0f, 0x902 },
};

static EnSyatekiManUnkStruct D_809C934C[] = {
    { ACTOR_EN_SYATEKI_CROW, -1000.0f, 200.0f, -700.0f, 0x0 },
    { ACTOR_EN_SYATEKI_CROW, -1000.0f, 200.0f, -700.0f, 0x100 },
    { ACTOR_EN_SYATEKI_DEKUNUTS, -1000.0f, 200.0f, -700.0f, 0x1 },
    { ACTOR_EN_SYATEKI_DEKUNUTS, -1000.0f, 200.0f, -700.0f, 0x11 },
    { ACTOR_EN_SYATEKI_CROW, -1000.0f, 200.0f, -700.0f, 0x202 },
    { ACTOR_EN_SYATEKI_CROW, -1000.0f, 200.0f, -700.0f, 0x302 },
    { ACTOR_EN_SYATEKI_CROW, -1000.0f, 200.0f, -700.0f, 0x3 },
    { ACTOR_EN_SYATEKI_CROW, -1000.0f, 200.0f, -700.0f, 0x103 },
    { ACTOR_EN_SYATEKI_CROW, -1000.0f, 200.0f, -700.0f, 0x423 },
    { ACTOR_EN_SYATEKI_CROW, -1000.0f, 200.0f, -700.0f, 0x204 },
    { ACTOR_EN_SYATEKI_CROW, -1000.0f, 200.0f, -700.0f, 0x304 },
    { ACTOR_EN_SYATEKI_CROW, -1000.0f, 200.0f, -700.0f, 0x424 },
    { ACTOR_EN_SYATEKI_WF, -1000.0f, 200.0f, -700.0f, 0x25 },
    { ACTOR_EN_SYATEKI_WF, -1000.0f, 200.0f, -700.0f, 0x136 },
};

static EnSyatekiManUnkStruct* D_809C9464[] = {
    D_809C91D0,
    D_809C934C,
};

static s32 D_809C946C[] = {
    ARRAY_COUNT(D_809C91D0),
    ARRAY_COUNT(D_809C934C),
};

static Vec3f D_809C9474 = { 0.0f, 10.0f, 140.0f };
static Vec3f D_809C9480 = { -20.0f, 20.0f, 198.0f };
static Vec3f D_809C948C = { -20.0f, 40.0f, 175.0f };

void func_809C64C0(EnSyatekiMan* this, PlayState* play2, EnSyatekiManUnkStruct arg2[], s32 arg3) {
    PlayState* play = play2;
    s32 i;

    for (i = 0; i < arg3; i++) {
        Actor_SpawnAsChild(&play->actorCtx, &this->actor, play, arg2[i].index, arg2[i].x, arg2[i].y, arg2[i].z, 0, 0, 0,
                           arg2[i].variable);
    }
}

void EnSyatekiMan_Init(Actor* thisx, PlayState* play) {
    EnSyatekiMan* this = THIS;
    s32 pad;
    Path* sp34 = &play->setupPathList[ENSYATEKIMAN_GET_FF00(&this->actor)];
    s32 sp30 = D_809C946C[this->unk_194];

    this->actor.targetMode = 1;
    Actor_SetScale(&this->actor, 0.01f);
    if (play->sceneNum == SCENE_SYATEKI_MORI) {
        SkelAnime_InitFlex(play, &this->skelAnime, &gBurlyGuySkel, &gSwampShootingGalleryManHeadScratchLoopAnim,
                           this->jointTable, this->morphTable, BURLY_GUY_LIMB_MAX);
    } else {
        SkelAnime_InitFlex(play, &this->skelAnime, &gBurlyGuySkel, &gBurlyGuyHandsOnTableAnim, this->jointTable,
                           this->morphTable, BURLY_GUY_LIMB_MAX);
    }

    this->actor.colChkInfo.cylRadius = 100;
    this->actionFunc = func_809C6810;
    this->unk_26A = 0;
    this->unk_270 = 15;
    this->unk_27E = 0;
    this->unk_26E = 0;
    this->unk_190 = 0;
    this->unk_272 = 0;
    this->unk_274 = 0;
    this->unk_280 = 0;
    this->unk_278 = 0;
    this->unk_27A = 0;
    this->unk_284 = 0;
    this->unk_194 = 0;
    this->unk_282 = 0;
    this->eyeIndex = 0;
    this->blinkTimer = 0;

    if (play->sceneNum == SCENE_SYATEKI_MORI) {
        this->path = sp34;
        func_809C64C0(this, play, D_809C9464[this->unk_194], sp30);
    }
}

void EnSyatekiMan_Destroy(Actor* thisx, PlayState* play) {
    gSaveContext.save.weekEventReg[63] &= (u8)~1;
}

s32 func_809C6720(PlayState* play, Vec3f arg1) {
    Player* player = GET_PLAYER(play);
    f32 sp28;
    f32 phi_f0;
    s16 sp22 = Math_Vec3f_Yaw(&player->actor.world.pos, &arg1);

    sp28 = Math_Vec3f_DistXZ(&player->actor.world.pos, &arg1);

    if (sp28 < 5.0f) {
        phi_f0 = 10.0f;
    } else if (sp28 < 30.0f) {
        phi_f0 = 40.0f;
    } else {
        phi_f0 = 80.0f;
    }

    play->actorCtx.unk268 = 1;
    func_800B6F20(play, &play->actorCtx.unk_26C, phi_f0, sp22);

    if (sp28 < 5.0f) {
        return true;
    }

    return false;
}

void func_809C6810(EnSyatekiMan* this, PlayState* play) {
    if (play->sceneNum == SCENE_SYATEKI_MORI) {
        this->actionFunc = func_809C6848;
    } else if (play->sceneNum == SCENE_SYATEKI_MIZU) {
        this->actionFunc = func_809C72D8;
    }
}

void func_809C6848(EnSyatekiMan* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (Actor_ProcessTalkRequest(&this->actor, &play->state)) {
        u16 sp22;

        Actor_ChangeAnimationByInfo(&this->skelAnime, sAnimations, 2);
        sp22 = Text_GetFaceReaction(play, 0x31);
        if (sp22 != 0) {
            Message_StartTextbox(play, sp22, &this->actor);
            this->unk_284 = sp22;
        } else if (player->transformation == PLAYER_FORM_HUMAN) {
            if (this->unk_282 == 0) {
                this->unk_282 = 1;
                Message_StartTextbox(play, 0xA28, &this->actor);
                this->unk_284 = 0xA28;
            } else {
                Message_StartTextbox(play, 0xA29, &this->actor);
                this->unk_284 = 0xA29;
            }
        } else {
            switch (CURRENT_DAY) {
                case 1:
                    Message_StartTextbox(play, 0xA38, &this->actor);
                    this->unk_284 = 0xA38;
                    break;

                case 2:
                    Message_StartTextbox(play, 0xA39, &this->actor);
                    this->unk_284 = 0xA39;
                    break;

                case 3:
                    Message_StartTextbox(play, 0xA3A, &this->actor);
                    this->unk_284 = 0xA3A;
                    break;
            }
        }
        this->actionFunc = func_809C6E30;
    } else {
        func_800B8614(&this->actor, play, 120.0f);
    }

    if (player->actor.world.pos.z < 135.0f) {
        player->actor.world.pos.z = 135.0f;
    }
}

void func_809C6A04(EnSyatekiMan* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (Message_ShouldAdvance(play)) {
        if (play->msgCtx.choiceIndex == 0) {
            if (!CUR_UPG_VALUE(UPG_QUIVER)) {
                play_sound(NA_SE_SY_ERROR);
                Message_StartTextbox(play, 0xA30, &this->actor);
                this->unk_284 = 0xA30;
            } else if (gSaveContext.save.playerData.rupees < 20) {
                play_sound(NA_SE_SY_ERROR);
                Message_StartTextbox(play, 0xA31, &this->actor);
                this->unk_284 = 0xA31;
                if (this->unk_26A == 4) {
                    gSaveContext.minigameState = 3;
                }
                this->unk_26A = 3;
            } else {
                func_8019F208();
                Rupees_ChangeBy(-20);
                gSaveContext.save.weekEventReg[63] |= 1;
                gSaveContext.save.weekEventReg[63] &= (u8)~2;
                play->msgCtx.msgMode = 0x43;
                play->msgCtx.unk12023 = 4;
                this->unk_26A = 7;
                player->stateFlags1 |= 0x20;
                this->actionFunc = func_809C7FFC;
            }
        } else {
            func_8019F230();

            switch (CURRENT_DAY) {
                case 1:
                    Message_StartTextbox(play, 0xA2D, &this->actor);
                    this->unk_284 = 0xA2D;
                    break;

                case 2:
                    Message_StartTextbox(play, 0xA2E, &this->actor);
                    this->unk_284 = 0xA2E;
                    break;

                case 3:
                    Message_StartTextbox(play, 0xA2F, &this->actor);
                    this->unk_284 = 0xA2F;
                    break;
            }

            if (this->unk_26A == 4) {
                gSaveContext.minigameState = 3;
            }

            this->unk_26A = 3;
        }
    }
}

void func_809C6C2C(EnSyatekiMan* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (Message_ShouldAdvance(play)) {
        switch (this->unk_284) {
            case 0xA28:
            case 0xA29:
                Message_StartTextbox(play, 0xA2A, &this->actor);
                this->unk_284 = 0xA2A;
                break;

            case 0xA2B:
            case 0xA2C:
            case 0xA35:
                play->msgCtx.msgMode = 0x43;
                play->msgCtx.unk12023 = 4;
                player->actor.freezeTimer = 0;
                func_80112AFC(play);
                play->interfaceCtx.hbaAmmo = 80;
                func_80123F2C(play, 80);
                this->unk_26A = 1;
                this->actionFunc = func_809C80C0;
                func_801A2BB8(NA_BGM_MINI_GAME_2);
                break;

            case 0xA32:
                if (gSaveContext.save.weekEventReg[63] & 2) {
                    func_801477B4(play);
                    player->stateFlags1 &= ~0x20;
                    gSaveContext.save.weekEventReg[63] &= (u8)~1;
                    gSaveContext.save.weekEventReg[63] &= (u8)~2;
                    this->actionFunc = func_809C6848;
                    gSaveContext.minigameState = 3;
                    this->unk_26A = 0;
                } else {
                    Message_StartTextbox(play, 0xA33, &this->actor);
                    this->unk_284 = 0xA33;
                }
                break;

            case 0xA33:
                Message_StartTextbox(play, 0xA2A, &this->actor);
                this->unk_284 = 0xA2A;
                this->unk_26A = 4;
                break;

            case 0xA34:
                play->msgCtx.msgMode = 0x43;
                play->msgCtx.unk12023 = 4;
                player->actor.freezeTimer = 0;
                gSaveContext.minigameState = 3;
                player->stateFlags1 |= 0x20;
                this->actionFunc = func_809C7A90;
                func_809C7A90(this, play);
                break;
        }
    }
}

void func_809C6E30(EnSyatekiMan* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (player->stateFlags1 & 0x20) {
        player->stateFlags1 |= 0x20;
    }

    switch (Message_GetState(&play->msgCtx)) {
        case 2:
            this->actionFunc = func_809C6848;
            this->unk_26A = 0;
            break;

        case 4:
            func_809C6A04(this, play);
            break;

        case 5:
            func_809C6C2C(this, play);
            break;

        case 6:
            if (Message_ShouldAdvance(play)) {
                play->msgCtx.msgMode = 0x43;
                play->msgCtx.unk12023 = 4;
                player->stateFlags1 &= ~0x20;
                gSaveContext.save.weekEventReg[63] &= (u8)~1;
                gSaveContext.save.weekEventReg[63] &= (u8)~2;
                this->actionFunc = func_809C6848;
                this->unk_26A = 0;
            }
            break;

        case 0:
        case 1:
        case 3:
        case 7:
        case 8:
        case 9:
        case 10:
            break;
    }

    if (this->skelAnime.animation == &gSwampShootingGalleryManHeadScratchEndAnim) {
        if (Animation_OnFrame(&this->skelAnime, this->skelAnime.endFrame)) {
            Actor_ChangeAnimationByInfo(&this->skelAnime, sAnimations, 0);
        }
    }
}

void func_809C6F98(EnSyatekiMan* this, PlayState* play) {
    switch (gSaveContext.save.playerForm) {
        case PLAYER_FORM_HUMAN:
            Flags_SetAllTreasure(play, Flags_GetAllTreasure(play) + 1);
            if (CURRENT_DAY != 3) {
                if (!(this->unk_282 & 1)) {
                    this->unk_282 |= 1;
                    Message_StartTextbox(play, 0x3E8, &this->actor);
                    this->unk_284 = 0x3E8;
                } else {
                    Message_StartTextbox(play, 0x3E9, &this->actor);
                    this->unk_284 = 0x3E9;
                }
            } else if (!(this->unk_282 & 1)) {
                this->unk_282 |= 1;
                Message_StartTextbox(play, 0x3EA, &this->actor);
                this->unk_284 = 0x3EA;
            } else {
                Message_StartTextbox(play, 0x3EB, &this->actor);
                this->unk_284 = 0x3EB;
            }
            break;

        case PLAYER_FORM_DEKU:
            if (CURRENT_DAY != 3) {
                if (!(this->unk_282 & 2)) {
                    this->unk_282 |= 2;
                    Message_StartTextbox(play, 0x3EC, &this->actor);
                    this->unk_284 = 0x3EC;
                } else {
                    Message_StartTextbox(play, 0x3ED, &this->actor);
                    this->unk_284 = 0x3ED;
                }
            } else if (!(this->unk_282 & 2)) {
                this->unk_282 |= 2;
                Message_StartTextbox(play, 0x3EE, &this->actor);
                this->unk_284 = 0x3EE;
            } else {
                Message_StartTextbox(play, 0x3EF, &this->actor);
                this->unk_284 = 0x3EF;
            }
            break;

        case PLAYER_FORM_ZORA:
            if (CURRENT_DAY != 3) {
                if (!(this->unk_282 & 8)) {
                    this->unk_282 |= 8;
                    Message_StartTextbox(play, 0x3F0, &this->actor);
                    this->unk_284 = 0x3F0;
                } else {
                    Message_StartTextbox(play, 0x3F1, &this->actor);
                    this->unk_284 = 0x3F1;
                }
            } else if (!(this->unk_282 & 8)) {
                this->unk_282 |= 8;
                Message_StartTextbox(play, 0x3F4, &this->actor);
                this->unk_284 = 0x3F4;
            } else {
                Message_StartTextbox(play, 0x3F5, &this->actor);
                this->unk_284 = 0x3F5;
            }
            break;

        case PLAYER_FORM_GORON:
            if (CURRENT_DAY != 3) {
                if (!(this->unk_282 & 4)) {
                    this->unk_282 |= 4;
                    Message_StartTextbox(play, 0x3F2, &this->actor);
                    this->unk_284 = 0x3F2;
                } else {
                    Message_StartTextbox(play, 0x3F3, &this->actor);
                    this->unk_284 = 0x3F3;
                }
            } else if (!(this->unk_282 & 4)) {
                this->unk_282 |= 4;
                Message_StartTextbox(play, 0x3F4, &this->actor);
                this->unk_284 = 0x3F4;
            } else {
                Message_StartTextbox(play, 0x3F5, &this->actor);
                this->unk_284 = 0x3F5;
            }
            break;
    }
}

void func_809C72D8(EnSyatekiMan* this, PlayState* play) {
    if (Actor_ProcessTalkRequest(&this->actor, &play->state)) {
        u16 sp26 = Text_GetFaceReaction(play, 0x30);

        if (sp26 != 0) {
            Message_StartTextbox(play, sp26, &this->actor);
            this->unk_284 = sp26;
        } else {
            func_809C6F98(this, play);
        }
        this->actionFunc = func_809C7990;
    } else {
        func_800B8614(&this->actor, play, 120.0f);
    }
}

void func_809C7380(EnSyatekiMan* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (Message_ShouldAdvance(play)) {
        if (play->msgCtx.choiceIndex == 0) {
            if (!CUR_UPG_VALUE(UPG_QUIVER)) {
                play_sound(NA_SE_SY_ERROR);
                if (CURRENT_DAY != 3) {
                    Message_StartTextbox(play, 0x3F9, &this->actor);
                    this->unk_284 = 0x3F9;
                } else {
                    Message_StartTextbox(play, 0x3FA, &this->actor);
                    this->unk_284 = 0x3FA;
                }
            } else if (gSaveContext.save.playerData.rupees < 20) {
                play_sound(NA_SE_SY_ERROR);
                if (CURRENT_DAY != 3) {
                    Message_StartTextbox(play, 0x3FB, &this->actor);
                    this->unk_284 = 0x3FB;
                } else {
                    Message_StartTextbox(play, 0x3FC, &this->actor);
                    this->unk_284 = 0x3FC;
                }

                if (this->unk_26A == 4) {
                    player->stateFlags3 &= ~0x400;
                    gSaveContext.minigameState = 3;
                }
                this->unk_26A = 3;
            } else {
                func_8019F208();
                Rupees_ChangeBy(-20);
                this->unk_26A = 2;
                if (!(this->unk_282 & 0x10)) {
                    this->unk_282 |= 0x10;
                    Message_StartTextbox(play, 0x3FD, &this->actor);
                    this->unk_284 = 0x3FD;
                } else {
                    Message_StartTextbox(play, 0x3FF, &this->actor);
                    this->unk_284 = 0x3FF;
                }
                gSaveContext.save.weekEventReg[63] |= 1;
                gSaveContext.save.weekEventReg[63] &= (u8)~2;
            }
        } else {
            func_8019F230();
            if (CURRENT_DAY != 3) {
                Message_StartTextbox(play, 0x3F7, &this->actor);
                this->unk_284 = 0x3F7;
            } else {
                Message_StartTextbox(play, 0x3F8, &this->actor);
                this->unk_284 = 0x3F8;
            }

            if (this->unk_26A == 4) {
                player->stateFlags3 &= ~0x400;
                gSaveContext.minigameState = 3;
            }
            this->unk_26A = 3;
        }
    }
}

void func_809C7620(EnSyatekiMan* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (Message_ShouldAdvance(play)) {
        switch (this->unk_284) {
            case 0x3E8:
            case 0x3E9:
            case 0x3EA:
            case 0x3EB:
                Message_StartTextbox(play, 0x3F6, &this->actor);
                this->unk_284 = 0x3F6;
                break;

            case 0x3EC:
                Message_StartTextbox(play, 0x3ED, &this->actor);
                this->unk_284 = 0x3ED;
                break;

            case 0x3EE:
                Message_StartTextbox(play, 0x3EF, &this->actor);
                this->unk_284 = 0x3EF;
                break;

            case 0x3F0:
                Message_StartTextbox(play, 0x3F1, &this->actor);
                this->unk_284 = 0x3F1;
                break;

            case 0x3F2:
                Message_StartTextbox(play, 0x3F3, &this->actor);
                this->unk_284 = 0x3F3;
                break;

            case 0x3F4:
                Message_StartTextbox(play, 0x3F5, &this->actor);
                this->unk_284 = 0x3F5;
                break;

            case 0x3FD:
            case 0x3FF:
                if (this->unk_26A == 4) {
                    if (this->unk_284 == 0x3FD) {
                        Message_StartTextbox(play, 0x3FE, &this->actor);
                        this->unk_284 = 0x3FE;
                    } else {
                        Message_StartTextbox(play, 0x400, &this->actor);
                        this->unk_284 = 0x400;
                    }
                } else {
                    play->msgCtx.msgMode = 0x43;
                    play->msgCtx.unk12023 = 4;
                    player->actor.freezeTimer = 0;
                    this->unk_26A = 7;
                    player->stateFlags1 |= 0x20;
                    gSaveContext.save.weekEventReg[63] |= 1;
                    gSaveContext.save.weekEventReg[63] &= (u8)~2;
                    this->actionFunc = func_809C8710;
                }
                break;

            case 0x3FE:
            case 0x400:
                play->msgCtx.msgMode = 0x43;
                play->msgCtx.unk12023 = 4;
                player->actor.freezeTimer = 0;
                this->unk_27E = 0;
                func_80112AFC(play);
                func_80123F2C(play, 0x63);
                this->unk_26A = 1;
                func_801A2BB8(NA_BGM_MINI_GAME_2);
                this->actionFunc = func_809C8808;
                break;

            case 0x401:
                if (gSaveContext.save.weekEventReg[63] & 2) {
                    func_801477B4(play);
                    gSaveContext.save.weekEventReg[63] &= (u8)~1;
                    gSaveContext.save.weekEventReg[63] &= (u8)~2;
                    this->unk_26A = 0;
                    this->actionFunc = func_809C72D8;
                } else {
                    Message_StartTextbox(play, 0x402, &this->actor);
                    this->unk_284 = 0x402;
                }
                break;

            case 0x403:
                if (gSaveContext.save.weekEventReg[63] & 2) {
                    func_801477B4(play);
                    gSaveContext.save.weekEventReg[63] &= (u8)~1;
                    gSaveContext.save.weekEventReg[63] &= (u8)~2;
                    this->unk_26A = 0;
                    this->actionFunc = func_809C72D8;
                } else {
                    Message_StartTextbox(play, 0x404, &this->actor);
                    this->unk_284 = 0x404;
                }
                break;

            case 0x402:
            case 0x404:
                Message_StartTextbox(play, 0x3F6, &this->actor);
                this->unk_284 = 0x3F6;
                this->unk_26A = 4;
                break;

            case 0x405:
            case 0x406:
            case 0x407:
                play->msgCtx.msgMode = 0x43;
                play->msgCtx.unk12023 = 4;
                player->actor.freezeTimer = 0;
                gSaveContext.minigameState = 3;
                this->actionFunc = func_809C7D14;
                func_809C7D14(this, play);
                break;
        }
    }
}

void func_809C7990(EnSyatekiMan* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (player->stateFlags1 & 0x20) {
        player->stateFlags1 |= 0x20;
    }

    switch (Message_GetState(&play->msgCtx)) {
        case 2:
            this->actionFunc = func_809C72D8;
            this->unk_26A = 0;
            break;

        case 4:
            func_809C7380(this, play);
            break;

        case 5:
            func_809C7620(this, play);
            break;

        case 6:
            if (Message_ShouldAdvance(play)) {
                gSaveContext.save.weekEventReg[63] &= (u8)~1;
                gSaveContext.save.weekEventReg[63] &= (u8)~2;
                player->stateFlags1 &= ~0x20;
                this->actionFunc = func_809C72D8;
                this->unk_26A = 0;
            }
            break;

        case 0:
        case 1:
        case 3:
        case 7:
        case 8:
        case 9:
        case 10:
            break;
    }
}

void func_809C7A90(EnSyatekiMan* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (Actor_HasParent(&this->actor, play)) {
        if (!(gSaveContext.save.weekEventReg[59] & 0x10)) {
            gSaveContext.save.weekEventReg[59] |= 0x10;
        } else if (!(gSaveContext.save.weekEventReg[32] & 2) && (this->unk_280 >= 0x884)) {
            gSaveContext.save.weekEventReg[32] |= 2;
        }
        this->actor.parent = NULL;
        this->actionFunc = func_809C7C14;
    } else {
        if ((CUR_UPG_VALUE(UPG_QUIVER) < 3) && !(gSaveContext.save.weekEventReg[59] & 0x10)) {
            Actor_PickUp(&this->actor, play, GI_QUIVER_30 + CUR_UPG_VALUE(UPG_QUIVER), 500.0f, 100.0f);
        } else if (this->unk_280 < 0x884) {
            Actor_PickUp(&this->actor, play, GI_RUPEE_RED, 500.0f, 100.0f);
        } else if (!(gSaveContext.save.weekEventReg[32] & 2)) {
            Actor_PickUp(&this->actor, play, GI_HEART_PIECE, 500.0f, 100.0f);
        } else {
            Actor_PickUp(&this->actor, play, GI_RUPEE_PURPLE, 500.0f, 100.0f);
        }

        player->actor.shape.rot.y = -0x8000;
        player->actor.velocity.z = 0.0f;
        player->actor.velocity.x = 0.0f;
        player->actor.world.rot.y = player->actor.shape.rot.y;
    }
}

void func_809C7C14(EnSyatekiMan* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (Actor_ProcessTalkRequest(&this->actor, &play->state)) {
        if ((CURRENT_DAY == 3) && (gSaveContext.save.time > CLOCK_TIME(12, 0))) {
            Message_StartTextbox(play, 0xA36, &this->actor);
            this->unk_284 = 0xA36;
        } else {
            Message_StartTextbox(play, 0xA37, &this->actor);
            this->unk_284 = 0xA37;
        }
        player->stateFlags1 &= ~0x20;
        this->actor.flags &= ~ACTOR_FLAG_10000;
        this->unk_280 = 0;
        this->unk_26A = 0;
        this->actionFunc = func_809C6E30;
    } else {
        func_800B85E0(&this->actor, play, 500.0f, EXCH_ITEM_MINUS1);
    }
}

void func_809C7D14(EnSyatekiMan* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (Actor_HasParent(&this->actor, play)) {
        if (this->unk_284 == 0x407) {
            if (!(gSaveContext.save.weekEventReg[59] & 0x20)) {
                gSaveContext.save.weekEventReg[59] |= 0x20;
            }
        }

        if ((this->unk_284 == 0x405) || (this->unk_284 == 0x406)) {
            if (!(gSaveContext.save.weekEventReg[32] & 4)) {
                gSaveContext.save.weekEventReg[32] |= 4;
            }
        }
        this->actor.parent = NULL;
        this->actionFunc = func_809C7EB4;
    } else {
        if (this->unk_284 == 0x407) {
            if ((CUR_UPG_VALUE(UPG_QUIVER) < 3) && !(gSaveContext.save.weekEventReg[59] & 0x20)) {
                Actor_PickUp(&this->actor, play, GI_QUIVER_30 + CUR_UPG_VALUE(UPG_QUIVER), 500.0f, 100.0f);
            } else {
                Actor_PickUp(&this->actor, play, GI_RUPEE_PURPLE, 500.0f, 100.0f);
            }
        } else if (!(gSaveContext.save.weekEventReg[32] & 4)) {
            Actor_PickUp(&this->actor, play, GI_HEART_PIECE, 500.0f, 100.0f);
        } else {
            Actor_PickUp(&this->actor, play, GI_RUPEE_HUGE, 500.0f, 100.0f);
        }

        player->actor.shape.rot.y = -0x8000;
        player->actor.velocity.z = 0.0f;
        player->actor.velocity.x = 0.0f;
        player->actor.world.rot.y = player->actor.shape.rot.y;
    }
}

void func_809C7EB4(EnSyatekiMan* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (CURRENT_DAY != 3) {
        if ((Message_GetState(&play->msgCtx) == 6) && Message_ShouldAdvance(play)) {
            player->stateFlags1 &= ~0x20;
            this->unk_280 = 0;
            this->unk_26A = 0;
            gSaveContext.save.weekEventReg[63] &= (u8)~1;
            gSaveContext.save.weekEventReg[63] &= (u8)~2;
            this->actionFunc = func_809C6810;
        }
    } else if (Actor_ProcessTalkRequest(&this->actor, &play->state)) {
        Message_StartTextbox(play, 0x408, &this->actor);
        this->unk_284 = 0x408;
        player->stateFlags1 &= ~0x20;
        this->actor.flags &= ~ACTOR_FLAG_10000;
        this->unk_280 = 0;
        this->unk_26A = 0;
        this->actionFunc = func_809C7990;
    } else {
        func_800B85E0(&this->actor, play, 500.0f, EXCH_ITEM_MINUS1);
    }
}

void func_809C7FFC(EnSyatekiMan* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (func_809C6720(play, D_809C9474)) {
        player->stateFlags1 |= 0x20;
        this->unk_26A = 2;
        if (this->unk_282 != 2) {
            this->unk_282 = 2;
            Message_StartTextbox(play, 0xA2B, &this->actor);
            this->unk_284 = 0xA2B;
        } else {
            Message_StartTextbox(play, 0xA2C, &this->actor);
            this->unk_284 = 0xA2C;
        }
        this->actionFunc = func_809C6E30;
    }
}

void func_809C80C0(EnSyatekiMan* this, PlayState* play) {
    static s16 D_809C9498 = 30;
    Player* player = GET_PLAYER(play);

    if (D_809C9498 > 0) {
        player->actor.world.pos = D_809C9474;
        player->actor.shape.rot.y = -0x8000;
        player->actor.world.rot.y = player->actor.shape.rot.y;
        play->unk_18790(play, -0x8000, &this->actor);
        D_809C9498--;
    } else {
        D_809C9498 = 30;
        this->unk_27E = 0;
        this->unk_280 = 0;
        player->stateFlags1 &= ~0x20;
        Actor_PlaySfxAtPos(&this->actor, NA_SE_SY_FOUND);
        this->unk_272 = 0x1F;
        this->unk_274 = 0;
        this->unk_276 = 0;
        this->unk_26C = 0;
        this->unk_278 = 0;
        this->unk_27A = 0;
        this->unk_27C = 0;
        this->unk_26E = 0;
        func_8010E9F0(1, 100);
        this->actor.draw = NULL;
        this->actionFunc = func_809C81D0;
    }
}

void func_809C81D0(EnSyatekiMan* this, PlayState* play) {
    static s16 D_809C949C = 0;
    Player* player = GET_PLAYER(play);

    if (((this->unk_272 == 0) || (this->unk_26C > 140)) && (D_809C949C == 0) && (this->unk_27C < 4)) {
        D_809C949C = 1;
        this->unk_26C = 0;
        Actor_PlaySfxAtPos(&this->actor, NA_SE_SY_FOUND);
        this->unk_274 = D_809C91C8[this->unk_27E];
        if (this->unk_27E == 3) {
            this->unk_27E = 0;
        } else {
            this->unk_27E++;
        }
    } else if ((this->unk_274 == 0) && (this->unk_272 == 0) && (D_809C949C == 1) && (this->unk_27C < 4)) {
        if (this->unk_27A < 3) {
            this->unk_27A = 0;
        }
        this->unk_26C = 0;
        D_809C949C = 0;
        this->unk_27C++;
        if (this->unk_27C < 4) {
            this->unk_272 = 31;
        }
    }

    if (this->unk_27A == 3) {
        this->unk_27A = 0;
        this->unk_276 |= 1;
    }

    if (this->unk_278 == 10) {
        this->unk_278 = 0;
        this->unk_276 |= 2;
    }

    this->unk_26C++;
    if (gSaveContext.unk_3DE0[1] == 0) {
        gSaveContext.unk_3DE0[1] = 0;
        gSaveContext.unk_3DD0[1] = 5;
        this->actor.draw = EnSyatekiMan_Draw;
        this->unk_27E = 0;
        this->unk_27C = 0;
        player->stateFlags1 |= 0x20;
        D_809C949C = 0;
        func_801A2C20();
        this->actionFunc = func_809C8488;
    } else if ((this->unk_27C == 4) && (this->unk_276 == 0) && (this->unk_26E == 2)) {
        this->actor.draw = EnSyatekiMan_Draw;
        this->unk_27E = 0;
        this->unk_27C = 0;
        player->stateFlags1 |= 0x20;
        D_809C949C = 0;
        func_801A2C20();
        this->unk_26A = 5;
        if (this->unk_280 == 0x848) {
            func_8011B4E0(play, 2);
            gSaveContext.unk_3DD0[1] = 6;
            this->actionFunc = func_809C8610;
        } else {
            gSaveContext.unk_3DD0[1] = 5;
            this->actionFunc = func_809C8488;
        }
    }
}

void func_809C8488(EnSyatekiMan* this, PlayState* play) {
    if ((this->unk_26A == 1) || (this->unk_26A == 5)) {
        this->unk_190 = 0;
        this->unk_272 = 0;
        this->unk_274 = 0;
        this->unk_276 = 0;
        if (this->unk_270 <= 0) {
            if ((s32)((gSaveContext.save.unk_EF4 & 0xFFFF0000) >> 0x10) < this->unk_280) {
                gSaveContext.save.unk_EF4 = ((gSaveContext.save.unk_EF4) & 0xFFFF) | ((u16)this->unk_280 << 0x10);
            }
            this->unk_270 = 15;
            if (this->unk_280 >= 0x848) {
                Message_StartTextbox(play, 0xA34, &this->actor);
                this->unk_284 = 0xA34;
                this->unk_26A = 6;
            } else if (this->unk_280 >= 0x7D0) {
                if (gSaveContext.save.weekEventReg[63] & 2) {
                    gSaveContext.save.weekEventReg[63] &= (u8)~1;
                    gSaveContext.save.weekEventReg[63] &= (u8)~2;
                    this->unk_26A = 0;
                    gSaveContext.minigameState = 3;
                    this->actionFunc = func_809C6848;
                    return;
                }
                Message_StartTextbox(play, 0xA35, &this->actor);
                this->unk_284 = 0xA35;
                this->unk_26A = 4;
                this->unk_280 = 0;
            } else {
                Message_StartTextbox(play, 0xA32, &this->actor);
                this->unk_284 = 0xA32;
                this->unk_26A = 6;
            }
            this->actionFunc = func_809C6E30;
        } else {
            this->unk_270--;
        }
    }

    if (this->unk_270 < 5) {
        play->unk_1887C = -10;
    }
}

void func_809C8610(EnSyatekiMan* this, PlayState* play) {
    static s32 D_809C94A0 = 0;
    Player* player = GET_PLAYER(play);

    player->stateFlags1 |= 0x20;
    if (play->interfaceCtx.unk_286 == 0) {
        if (gSaveContext.unk_3DE0[1] == 0) {
            gSaveContext.unk_3DE0[1] = 0;
            gSaveContext.unk_3DD0[1] = 5;
            this->unk_27E = 0;
            this->unk_27C = 0;
            this->actionFunc = func_809C8488;
            D_809C94A0 = 0;
        } else if (D_809C94A0 > 10) {
            gSaveContext.unk_3E88[1] += 100;
            play->interfaceCtx.unk_25C += 10;
            this->unk_280 += 10;
            Actor_PlaySfxAtPos(&this->actor, NA_SE_SY_TRE_BOX_APPEAR);
            D_809C94A0 = 0;
        } else {
            D_809C94A0++;
        }
    }
}

void func_809C8710(EnSyatekiMan* this, PlayState* play) {
    Vec3f sp24;

    if (gSaveContext.save.playerForm == PLAYER_FORM_FIERCE_DEITY) {
        sp24 = D_809C9480;
    } else {
        sp24 = D_809C948C;
    }

    if (func_809C6720(play, sp24)) {
        if (this->unk_284 == 0x3FD) {
            Message_StartTextbox(play, 0x3FE, &this->actor);
            this->unk_284 = 0x3FE;
        } else {
            Message_StartTextbox(play, 0x400, &this->actor);
            this->unk_284 = 0x400;
        }
        this->unk_26A = 2;
        this->actionFunc = func_809C7990;
    }
}

void func_809C8808(EnSyatekiMan* this, PlayState* play) {
    static s16 D_809C94A4 = 30;
    Player* player = GET_PLAYER(play);

    if (D_809C94A4 == 30) {
        if (player->transformation == PLAYER_FORM_FIERCE_DEITY) {
            player->actor.world.pos = D_809C9480;
        } else {
            player->actor.world.pos = D_809C948C;
        }
        player->actor.prevPos = player->actor.world.pos;
        player->actor.shape.rot.y = -0x8000;
        player->actor.world.rot.y = player->actor.shape.rot.y;
        play->unk_18790(play, -0x8000, &this->actor);
        player->stateFlags1 |= 0x20;
        D_809C94A4--;
    } else if (D_809C94A4 > 0) {
        player->actor.shape.rot.y = -0x8000;
        player->actor.world.rot.y = player->actor.shape.rot.y;
        D_809C94A4--;
    } else if (D_809C94A4 == 0) {
        player->stateFlags1 &= ~0x20;
        this->unk_280 = 0;
        this->unk_27E = 0;
        this->unk_26C = 70;
        this->unk_26E = 0;
        D_809C94A4 = 30;
        func_8010E9F0(1, 75);
        this->actor.draw = NULL;
        this->actionFunc = func_809C898C;
    }
}

void func_809C898C(EnSyatekiMan* this, PlayState* play) {
    static const s32 D_809C94D0[] = {
        0x00000111, 0x00000650, 0x00010025, 0x00011011, 0x00000984, 0x00004050, 0x00010211, 0x00022015,
        0x00026984, 0x00012852, 0x00011999, 0x00022895, 0x0000056A, 0x0002A451, 0x00004115,
    };
    static s32 D_809C94A8 = 0;
    Player* player = GET_PLAYER(play);
    s32 sp30 = (((void)0, gSaveContext.unk_3DE0[1]) * 0.1f) + 1.0f;

    if (sp30 < 0x2EF) {
        s32 temp;

        if (D_809C94A8 == 0) {
            temp = ((void)0, gSaveContext.unk_3DE0[1]) % 500;
        } else {
            temp = (((void)0, gSaveContext.unk_3DE0[1]) + 250) % 500;
        }

        if (temp < 100) {
            this->unk_26C = 80;
        }

        if (this->unk_26E != 0) {
            if (this->unk_26E == 2) {
                gSaveContext.unk_3E18[1] -= 250;
                D_809C94A8 = (D_809C94A8 + 25) % 50;
            }
            this->unk_26E = 0;
        }

        if (this->unk_26C == 0) {
            this->unk_26C++;
        }

        if ((D_809C94A8 == (sp30 % 50)) && (this->unk_26C >= 70)) {
            if (this->unk_27E < 15) {
                this->unk_190 = D_809C94D0[this->unk_27E++];
                Actor_PlaySfxAtPos(&this->actor, NA_SE_SY_FOUND);
                this->unk_26C = 0;
            }
        }

        if (gSaveContext.unk_3DE0[1] == 0) {
            this->unk_27E = 0;
            this->unk_26C = 80;
            gSaveContext.unk_3DE0[1] = 0;
            gSaveContext.unk_3DD0[1] = 5;
            player->stateFlags1 |= 0x20;
            D_809C94A8 = 0;
            this->actor.draw = EnSyatekiMan_Draw;
            func_801A2C20();
            this->actionFunc = func_809C8BF0;
            if (this->unk_280 == 50) {
                func_801A3098(NA_BGM_GET_ITEM | 0x900);
                func_8011B4E0(play, 1);
            }
        }
    }
}

void func_809C8BF0(EnSyatekiMan* this, PlayState* play) {
    if (this->unk_26A == 1) {
        this->unk_190 = 0;
        if ((this->unk_270 <= 0) && (play->interfaceCtx.unk_286 == 0)) {
            Flags_SetAllTreasure(play, this->unk_280);
            this->unk_270 = 15;
            if (((s32)(gSaveContext.save.unk_EF4 & 0xFFFF) < this->unk_280) || (this->unk_280 == 50)) {
                if ((s32)(gSaveContext.save.unk_EF4 & 0xFFFF) < this->unk_280) {
                    if (!(gSaveContext.save.weekEventReg[59] & 0x20)) {
                        Message_StartTextbox(play, 0x407, &this->actor);
                        this->unk_284 = 0x407;
                    } else if (this->unk_280 == 50) {
                        Message_StartTextbox(play, 0x405, &this->actor);
                        this->unk_284 = 0x405;
                    } else {
                        Message_StartTextbox(play, 0x407, &this->actor);
                        this->unk_284 = 0x407;
                    }
                } else if (this->unk_280 == 50) {
                    Message_StartTextbox(play, 0x406, &this->actor);
                    this->unk_284 = 0x406;
                }
                gSaveContext.save.unk_EF4 = (gSaveContext.save.unk_EF4 & 0xFFFF0000) | (this->unk_280 & 0xFFFF);
                this->unk_26A = 6;
            } else {
                if (CURRENT_DAY != 3) {
                    Message_StartTextbox(play, 0x401, &this->actor);
                    this->unk_284 = 0x401;
                } else {
                    Message_StartTextbox(play, 0x403, &this->actor);
                    this->unk_284 = 0x403;
                }
                this->unk_26A = 4;
            }
            this->actionFunc = func_809C7990;
        } else {
            this->unk_270--;
        }
    }

    if (this->unk_270 < 5) {
        play->unk_1887C = -10;
    }
}

void EnSyatekiMan_Blink(EnSyatekiMan* this) {
    switch (this->blinkTimer) {
        case 1:
            this->eyeIndex = 2;
            break;

        case 2:
            this->eyeIndex = 1;
            break;

        case 40:
            this->blinkTimer = 0;

        default:
            this->eyeIndex = 0;
            break;
    }

    this->blinkTimer++;
}

void EnSyatekiMan_Update(Actor* thisx, PlayState* play) {
    EnSyatekiMan* this = THIS;

    this->actionFunc(this, play);
    EnSyatekiMan_Blink(this);
    this->actor.focus.pos.y = 70.0f;
    Actor_SetFocus(&this->actor, 70.0f);
    if (this->unk_26A != 1) {
        SkelAnime_Update(&this->skelAnime);
        Actor_TrackPlayer(play, &this->actor, &this->unk_258, &this->unk_25E, this->actor.focus.pos);
    }
}

s32 EnSyatekiMan_OverrideLimbDraw(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* thisx) {
    EnSyatekiMan* this = THIS;

    if ((play->sceneNum == SCENE_SYATEKI_MIZU) && (limbIndex == BURLY_GUY_LIMB_HEAD)) {
        *dList = gTownShootingGalleryManHeadDL;
    }

    if (limbIndex == BURLY_GUY_LIMB_HEAD) {
        Matrix_Translate(3000.0f, 0.0f, 0.0f, MTXMODE_APPLY);
        Matrix_RotateZS(this->unk_258.x, MTXMODE_APPLY);
        Matrix_RotateXS(this->unk_258.y, MTXMODE_APPLY);
        Matrix_Translate(-3000.0f, 0.0f, 0.0f, MTXMODE_APPLY);
    } else if (limbIndex == BURLY_GUY_LIMB_TORSO) {
        Matrix_RotateXS(-this->unk_25E.y, MTXMODE_APPLY);
    }

    return false;
}

void EnSyatekiMan_PostLimbDraw(PlayState* play, s32 limbIndex, Gfx** dList, Vec3s* rot, Actor* thisx) {
    EnSyatekiMan* this = THIS;
    Vec3f sp18 = { 1600.0f, 0.0f, 0.0f };

    if (limbIndex == BURLY_GUY_LIMB_HEAD) {
        Matrix_MultVec3f(&sp18, &this->actor.focus.pos);
    }
}

void EnSyatekiMan_Draw(Actor* thisx, PlayState* play) {
    static TexturePtr sEyeTextures[] = {
        gSwampShootingGalleryManEyeOpenTex,
        gSwampShootingGalleryManEyeHalfTex,
        gSwampShootingGalleryManEyeHalfTex,
    };
    EnSyatekiMan* this = THIS;
    s32 pad;

    if (play->sceneNum == SCENE_SYATEKI_MIZU) {
        sEyeTextures[0] = gTownShootingGalleryManEyeOpenTex;
        sEyeTextures[1] = gTownShootingGalleryManEyeClosedTex;
        sEyeTextures[2] = gTownShootingGalleryManEyeClosedTex;
    } else {
        sEyeTextures[0] = gSwampShootingGalleryManEyeOpenTex;
        sEyeTextures[1] = gSwampShootingGalleryManEyeHalfTex;
        sEyeTextures[2] = gSwampShootingGalleryManEyeHalfTex;
    }

    OPEN_DISPS(play->state.gfxCtx);

    func_8012C5B0(play->state.gfxCtx);

    gSPSegment(POLY_OPA_DISP++, 0x08, Lib_SegmentedToVirtual(sEyeTextures[this->eyeIndex]));
    gSPSegment(POLY_OPA_DISP++, 0x09, Lib_SegmentedToVirtual(sEyeTextures[this->eyeIndex]));

    SkelAnime_DrawFlexOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable, this->skelAnime.dListCount,
                          EnSyatekiMan_OverrideLimbDraw, EnSyatekiMan_PostLimbDraw, &this->actor);

    CLOSE_DISPS(play->state.gfxCtx);
}
