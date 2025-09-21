#pragma once

#include "Game/Screen/LayoutActor.hpp"

namespace nw4r {
    namespace lyt {
        class TexMap;
    };
};

class MiiConfirmIcon : public LayoutActor {
public:
    /// @brief Creates a new `MiiConfirmIcon`.
    /// @param pName The pointer to the null-terminated name of the object.
    MiiConfirmIcon(const char* pName);

    /// @brief Destroys the `MiiConfirmIcon`.
    virtual ~MiiConfirmIcon();

    virtual void init(const JMapInfoIter& rIter);
    virtual void appear();

    void appear(nw4r::lyt::TexMap*, const wchar_t*);
    void disappear();
    void exeAppear();
    void exeWait();
    void exeDisappear();
    bool isDisappear() const;
};
