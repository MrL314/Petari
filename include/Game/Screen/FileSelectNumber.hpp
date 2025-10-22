#pragma once

#include "Game/Screen/LayoutActor.hpp"
#include "Game/System/NerveExecutor.hpp"

namespace FileSelectNumberSub {
    class SelectAnimController : public NerveExecutor {
    public:
        /// @brief Creates a new `SelectAnimController`.
        /// @param pHost The pointer to the owning actor instance.
        SelectAnimController(LayoutActor* pHost);

        void appear();
        void selectIn();
        void selectOut();
        void exeSelectInStart();
        void exeSelectIn();
        void exeSelectOutStart();
        void exeSelectOut();

    private:
        /* 0x8 */ LayoutActor* mHost;
        /* 0xC */ Nerve* _C;
    };
};

class FileSelectNumber : public LayoutActor {
public:
    /// @brief Creates a new `FileSelectNumber`.
    /// @param pName The pointer to the null-terminated name of the object.
    FileSelectNumber(const char* pName);

    virtual void init(const JMapInfoIter&);
    virtual void appear();
    virtual void control();

    void disappear();
    void setNumber(s32);
    void onSelectIn();
    void onSelectOut();
    void exeAppear();
    void exeWait();
    void exeEnd();

private:
    /* 0x20 */ s32 mNumber;
    /* 0x24 */ u8 _24[8];
    /* 0x2C */ FileSelectNumberSub::SelectAnimController* mSelectAnimCtrl;
};
