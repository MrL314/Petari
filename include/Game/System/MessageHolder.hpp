#pragma once

#include "Game/Util.hpp"
#include "Game/NPC/TalkNodeCtrl.hpp"

class TalkNode;
class TalkMessageInfo;

struct MessageInfoBlock {
    u32 mMagic;
    u32 mBlockSize;
    u16 mItemCount;
    u16 mItemSize;
    u32 _C;
};

struct MessageDataBlock {
    u32 mMagic;
    u32 mBlockSize;
};

struct MessageFlowBlock {
    u32 mMagic;
    u32 mBlockSize;
    u16 mNodeCount;
    u16 _A;
    u32 _C;
};

struct MessageFLI1Block {
    u32 mMagic;
    u32 mBlockSize;
};

class MessageData {
public:
    MessageData(const char*);

    bool getMessageDirect(TalkMessageInfo*, const char*) const;
    bool getMessage(TalkMessageInfo*, u16, u16) const;
    TalkNode* findNode(const char*) const;
    TalkNode* getNode(u32) const;
    TalkNode* getBranchNode(u32) const;
    bool isValidBranchNode(u32) const;
    u8* getMessageInfoTool(int) const;
    s32 findMessageIndex(const char*) const;

    JMapInfo* mIDTable;     // 0x0
    MessageInfoBlock* mInfoBlock;       // 0x4
    MessageDataBlock* mDataBlock;       // 0x8
    u32 _C;
    MessageFlowBlock* mFlowBlock;       // 0x10
    u16* _14;
    u8* _18;
    MessageFLI1Block* mFLI1Block;       // 0x1C
};

class MessageHolder {
public:
    MessageHolder();

    void initSceneData();
    void destroySceneData();
    void initSystemData();
    void initGameData();

    MessageData* mSystemMessage;        // 0x0
    MessageData* mGameMessage;          // 0x4
    MessageData* mSceneData;            // 0x8
};

class MessageSystem {
public:

    class Node {

    };

    struct FlowNodeBranch {

    };

    struct FlowNodeEvent {
        u8 mFlowType;       // 0x0
        u8 mEventType;      // 0x1
        u16 mBranchID;      // 0x2
        u32 mArg;           // 0x4
    };

    static inline TalkNode* getCurrentBranchNodeFromSceneMsg(u32 idx) {
        return getSceneMessageData()->getBranchNode(idx);
    }

    static void getSystemMessageDirect(TalkMessageInfo*, const char*);
    static void getGameMessageDirect(TalkMessageInfo*, const char*);
    static void getLayoutMessageDirect(TalkMessageInfo*, const char*);
    static MessageData* getSceneMessageData();
};
