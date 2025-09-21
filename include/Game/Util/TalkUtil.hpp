#pragma once

#include "Game/NPC/TalkMessageFunc.hpp"
#include "Game/Util/JMapInfo.hpp"
#include "Game/Util/MessageUtil.hpp"
#include "JSystem/JGeometry/TVec.hpp"
#include "revolution/mtx.h"
#include <JSystem/JGeometry.hpp>

class TalkMessageCtrl;
class LiveActor;

namespace MR {

    void registerBranchFunc(TalkMessageCtrl *, const TalkMessageFuncBase &);
    void registerEventFunc(TalkMessageCtrl *, const TalkMessageFuncBase &);
    void registerAnimeFunc(TalkMessageCtrl *, const TalkMessageFuncBase &);
    void registerKillFunc(TalkMessageCtrl *, const TalkMessageFuncBase &);
    void setMessageArg(TalkMessageCtrl *, int);
    void setMessageArg(TalkMessageCtrl *, const wchar_t *);

    void resetAndForwardNode(TalkMessageCtrl *, s32);

    bool tryTalkForceWithoutDemoMarioPuppetableAtEnd(TalkMessageCtrl *);

    void setDistanceToTalk(TalkMessageCtrl *, f32);

    void onRootNodeAutomatic(TalkMessageCtrl *);
    void offRootNodeAutomatic(TalkMessageCtrl *);

    void resetNode(TalkMessageCtrl *);

    bool tryTalkForce(TalkMessageCtrl *);
    bool tryTalkForceAtEnd(TalkMessageCtrl *);

    void forwardNode(TalkMessageCtrl *);

    void onStartOnlyFront(TalkMessageCtrl *);

    bool isExistNextNode(const TalkMessageCtrl *);

    bool tryTalkRequest(TalkMessageCtrl *);
    bool tryTalkSelectLeft(TalkMessageCtrl *);
    bool tryTalkSelectRight(TalkMessageCtrl *);

    void setMessageBalloonFollowOffset(TalkMessageCtrl *, const TVec3f &);

    TalkMessageCtrl* createTalkCtrlDirect(LiveActor *, const JMapInfoIter &, const char *,const TVec3f &, MtxPtr);
    TalkMessageCtrl* createTalkCtrlDirectOnRootNodeAutomatic(LiveActor *, const JMapInfoIter &, const char *, const TVec3f &, MtxPtr);

    inline void setMessageArgToCurrentGalaxyName(TalkMessageCtrl *pCtrl, const char *pName) {
        MR::setMessageArg(pCtrl, MR::getGalaxyNameOnCurrentLanguage(pName));
    }

    bool isNearPlayer(const TalkMessageCtrl *, f32);

    bool tryTalkNearPlayerAtEnd(TalkMessageCtrl *);
    
    bool tryTalkNearPlayer(TalkMessageCtrl *);

    bool tryTalkForceWithoutDemo(TalkMessageCtrl *);

    bool tryTalkTimeKeepDemo(TalkMessageCtrl *);
    bool tryTalkTimeKeepDemoMarioPuppetable(TalkMessageCtrl *);

    bool tryTalkForceWithoutDemoAtEnd(TalkMessageCtrl *);

    bool inMessageArea(const TalkMessageCtrl *);

    bool isTalkTalking(const TalkMessageCtrl *);

    class ActorTalkParam {
    public:
        void setNoTurnAction(const char *);
        void setSingleAction(const char *);

        u8 _0;
        u8 _1;
        u8 _2;
        u8 _3;
        f32 _4;
        f32 _8;
        f32 _C;
        f32 _10;
        const char* _14;
        const char* _18;
        const char* _1C;
        const char* _20;
    };
};
