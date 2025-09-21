#pragma once

#include "Game/NameObj/NameObj.hpp"

class LiveActor;

class NameObjExecuteInfo {
    friend class NameObjExecuteHolder;

public:
    NameObjExecuteInfo();

    void setConnectInfo(NameObj *, int, int, int, int);
    void initConnectting();
    void requestConnect(u8 *);
    void requestDisconnect(u8 *, bool);
    void executeRequirementConnectMovement();
    void executeRequirementDisconnectMovement();
    void executeRequirementConnectDraw();
    void executeRequirementDisconnectDraw();
    void executeRequirementDisconnectDrawDelay();
    void requestMovementOn(int);
    void requestMovementOff(int);
    void findLightInfo() const;
    void connectToScene();
    void disconnectToScene();
    void connectToDraw();
    void disconnectToDraw();

private:
    /* 0x0 */ NameObj* mExecutedObject;
    /* 0x4 */ s8 _4;
    /* 0x5 */ s8 _5;
    /* 0x6 */ s8 _6;
    /* 0x7 */ s8 _7;
    /* 0x8 */ s8 _8;
    /* 0x9 */ s8 _9;
    /* 0xA */ s16 _A;
};

class NameObjExecuteHolder : public NameObj { 
public:
    NameObjExecuteHolder(int);

    virtual ~NameObjExecuteHolder() {}

    void registerActor(NameObj *, int, int, int, int);
    void initConnectting();
    void connectToScene(NameObj *);
    void connectToDraw(NameObj *);
    void disconnectToScene(NameObj *);
    void disconnectToDraw(NameObj *);
    bool isConnectToDraw(const NameObj *) const;
    void executeRequirementConnectMovement();
    void executeRequirementDisconnectMovement();
    void executeRequirementConnectDraw();
    void executeRequirementDisconnectDraw();
    void executeRequirementDisconnectDrawDelay();
    void requestMovementOn(int);
    void requestMovementOff(int);
    NameObjExecuteInfo* getConnectToSceneInfo(const NameObj *) const;

private:
    /* 0x0C */ NameObjExecuteInfo* mExecuteArray;
    /* 0x10 */ s32 mExecuteArrayMaxSize;
    /* 0x14 */ s32 mExecuteArraySize;
    /* 0x18 */ bool _18;
    /* 0x19 */ bool _19;
    /* 0x1A */ bool _1A;
    /* 0x1B */ bool _1B;
    /* 0x1C */ bool _1C;
};

namespace MR {
    void registerNameObjToExecuteHolder(NameObj *, int, int, int, int);
    void initConnectting();
    void connectToSceneTemporarily(NameObj *);
    void disconnectToSceneTemporarily(NameObj *);
    void connectToDrawTemporarily(NameObj *);
    void disconnectToDrawTemporarily(NameObj *);
    bool isConnectToDrawTemporarily(const NameObj *);
    void executeRequirementConnectMovement();
    void executeRequirementDisconnectMovement();
    void executeRequirementConnectDraw();
    void executeRequirementDisconnectDraw();
    void executeRequirementDisconnectDrawDelay();
    void requestMovementOnWithCategory(int);
    void requestMovementOffWithCategory(int);
    void findActorLightInfo(const LiveActor *);
};
