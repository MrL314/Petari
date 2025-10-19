#include "Game/Screen/MovieStarter.hpp"
#include "Game/Screen/MoviePlayingSequence.hpp"
#include "Game/Util/EventUtil.hpp"
#include "Game/Util/JMapUtil.hpp"

MovieStarter::MovieStarter(const char *pName) :
    LiveActor(pName),
    mMovieIdx(-1)
{
    
}

void MovieStarter::init(const JMapInfoIter &rIter) {
    MR::connectToSceneLayoutMovement(this);
    MR::invalidateClipping(this);

    if (MR::useStageSwitchReadAppear(this, rIter)) {
        MR::FunctorV0M<MovieStarter *, void (MovieStarter::*)()> appearFunc = MR::Functor_Inline<MovieStarter>(this, &MovieStarter::appear);
        MR::listenStageSwitchOnAppear(this, appearFunc);
    }

    MR::useStageSwitchWriteDead(this, rIter);
    MR::createMoviePlayingSequence();
    MR::getJMapInfoArg0WithInit(rIter, &mMovieIdx);
    makeActorDead();
}

void MovieStarter::appear() {
    LiveActor::appear();

    if (mMovieIdx == 0) {
        if (MR::isOnGameEventFlagPlayMoviePrologueA()) {
            kill();
            return;
        }

        MR::onGameEventFlagPlayMoviePrologueA();
    }

    if (mMovieIdx == 1) {
        MR::onGameEventFlagPlayMoviePrologueB();
    }

    MR::startMovie(mMovieIdx);
}

void MovieStarter::kill() {
    if (MR::isValidSwitchDead(this)) {
        MR::onSwitchDead(this);
    }

    LiveActor::kill();
}

void MovieStarter::control() {
    if (MR::isEndMovie(mMovieIdx)) {
        kill();
    }
}
