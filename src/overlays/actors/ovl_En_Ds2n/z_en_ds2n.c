/*
 * File: z_en_ds2n.c
 * Overlay: ovl_En_Ds2n
 * Description: Potion Shop Owner from OoT (unused)
 *
 *   This actor was placed in the Staff Office of Stockpot inn
 *   but does not spawn because their object is missing.
 */

#include "z_en_ds2n.h"

#define FLAGS (ACTOR_FLAG_1 | ACTOR_FLAG_8 | ACTOR_FLAG_10 | ACTOR_FLAG_2000000)

#define THIS ((EnDs2n*)thisx)

void EnDs2n_Init(Actor* thisx, PlayState* play);
void EnDs2n_Destroy(Actor* thisx, PlayState* play);
void EnDs2n_Update(Actor* thisx, PlayState* play);
void EnDs2n_Draw(Actor* thisx, PlayState* play);

void EnDs2n_Idle(EnDs2n* this, PlayState* play);

const ActorInit En_Ds2n_InitVars = {
    ACTOR_EN_DS2N,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_DS2N,
    sizeof(EnDs2n),
    (ActorFunc)EnDs2n_Init,
    (ActorFunc)EnDs2n_Destroy,
    (ActorFunc)EnDs2n_Update,
    (ActorFunc)EnDs2n_Draw,
};

static AnimationInfo sAnimations[] = {
    { &gDs2nIdleAnim, 1.0f, 0.0f, 0.0f, ANIMMODE_LOOP, 0.0f },
};

static Vec3f sZeroVec = { 0, 0, 0 };

static TexturePtr sEyeTextures[] = { gDs2nEyeOpenTex, gDs2nEyeHalfTex, gDs2nEyeClosedTex };

void EnDs2n_SetupIdle(EnDs2n* this) {
    this->blinkTimer = 20;
    this->blinkState = 0;
    Actor_ChangeAnimationByInfo(&this->skelAnime, sAnimations, 0);
    this->actionFunc = EnDs2n_Idle;
}

void EnDs2n_Idle(EnDs2n* this, PlayState* play) {
    SubS_FillLimbRotTables(play, this->limbRotTableY, this->limbRotTableZ, DS2N_LIMB_MAX);
}

void EnDs2n_UpdateEyes(EnDs2n* this) {
    s16 nextBlinkTime = this->blinkTimer - 1;

    if (nextBlinkTime >= 3) {
        this->blinkState = 0;
        this->blinkTimer = nextBlinkTime;
    } else if (nextBlinkTime == 0) {
        this->blinkState = 2;
        this->blinkTimer = (s32)(Rand_ZeroOne() * 60.0f) + 20;
    } else {
        this->blinkState = 1;
        this->blinkTimer = nextBlinkTime;
    }
}

void EnDs2n_Init(Actor* thisx, PlayState* play) {
    EnDs2n* this = THIS;

    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 20.0f);
    SkelAnime_InitFlex(play, &this->skelAnime, &gDs2nSkeleton, &gDs2nIdleAnim, NULL, NULL, 0);
    EnDs2n_SetupIdle(this);
}

void EnDs2n_Destroy(Actor* thisx, PlayState* play) {
    EnDs2n* this = THIS;

    SkelAnime_Free(&this->skelAnime, play);
}

void EnDs2n_Update(Actor* thisx, PlayState* play) {
    EnDs2n* this = THIS;

    this->actionFunc(this, play);
    Actor_MoveWithGravity(&this->actor);
    SkelAnime_Update(&this->skelAnime);

    Actor_TrackPlayer(play, &this->actor, &this->headRot, &this->chestRot, this->actor.focus.pos);
    EnDs2n_UpdateEyes(this);
}

s32 EnDs2n_OverrideLimbDraw(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, Actor* thisx) {
    EnDs2n* this = THIS;

    if (limbIndex == DS2N_LIMB_HEAD) {
        Matrix_RotateXS(this->headRot.y, MTXMODE_APPLY);
    }

    return false;
}

void EnDs2n_PostLimbDraw(PlayState* play, s32 limbIndex, Gfx** dList, Vec3s* rot, Actor* thisx) {
    EnDs2n* this = THIS;
    Vec3f focusOffset = sZeroVec;

    if ((limbIndex == DS2N_LIMB_HIPS) || (limbIndex == DS2N_LIMB_LEFT_UPPER_ARM) ||
        (limbIndex == DS2N_LIMB_RIGHT_UPPER_ARM)) {
        rot->y += (s16)Math_SinS(this->limbRotTableY[limbIndex]) * 0xC8;
        rot->z += (s16)Math_CosS(this->limbRotTableZ[limbIndex]) * 0xC8;
    }

    if (limbIndex == DS2N_LIMB_HEAD) {
        Matrix_MultVec3f(&focusOffset, &thisx->focus.pos);
    }
}

void EnDs2n_Draw(Actor* thisx, PlayState* play) {
    EnDs2n* this = THIS;

    OPEN_DISPS(play->state.gfxCtx);

    func_8012C5B0(play->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x08, Lib_SegmentedToVirtual(sEyeTextures[this->blinkState]));

    gSPSegment(POLY_OPA_DISP++, 0x09, Lib_SegmentedToVirtual(sEyeTextures[this->blinkState]));

    SkelAnime_DrawFlexOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable, this->skelAnime.dListCount,
                          EnDs2n_OverrideLimbDraw, EnDs2n_PostLimbDraw, &this->actor);

    CLOSE_DISPS(play->state.gfxCtx);
}
