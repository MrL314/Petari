#include "Game/Map/ScenarioSelectStar.hpp"
#include "Game/MapObj/PowerStar.hpp"
#include "Game/Util.hpp"
#include "math_types.hpp"
//#include <JSystem/JMath/JMATrigonometric.hpp>

namespace NrvScenarioSelectStar {
    NEW_NERVE(ScenarioSelectStarNrvAppear, ScenarioSelectStar, Appear);
    NEW_NERVE(ScenarioSelectStarNrvNotPointing, ScenarioSelectStar, NotPointing);
    NEW_NERVE(ScenarioSelectStarNrvPointing, ScenarioSelectStar, Pointing);
    NEW_NERVE(ScenarioSelectStarNrvEndPointing, ScenarioSelectStar, EndPointing);
    NEW_NERVE(ScenarioSelectStarNrvSelected, ScenarioSelectStar, Selected);
    NEW_NERVE(ScenarioSelectStarNrvSelectedMove, ScenarioSelectStar, SelectedMove);
    NEW_NERVE(ScenarioSelectStarNrvNotSelected, ScenarioSelectStar, NotSelected);
};

ScenarioSelectStar::ScenarioSelectStar(EffectSystem *pSystem) :
    MultiSceneActor("シナリオ選択のスター", "PowerStar", false),
    _44(0),
    mFrame(1),
    _4C(0),
    _50(false),
    _54(0.0f),
    _5C(gZeroVec),
    _68(gZeroVec),
    _74(60),
    _78(1.0f)
{
    initEffect(pSystem, 0, "ScenarioStar");
}

void ScenarioSelectStar::init(const JMapInfoIter &rIter) {
    initNerve(&NrvScenarioSelectStar::ScenarioSelectStarNrvNotPointing::sInstance);
}

void ScenarioSelectStar::calcViewAndEntry() {
    if (!isNerve(&NrvScenarioSelectStar::ScenarioSelectStarNrvAppear::sInstance)
        || !MultiScene::isLessEqualStep(this, _74 + 1))
    {
        MultiSceneActor::calcViewAndEntry();
    }
}

void ScenarioSelectStar::appear() {
    mScale.x = 0.9f;
    mScale.y = 0.9f;
    mScale.z = 0.9f;
    _50 = false;
    _54 = 0.0f;
    updatePos();
    MultiScene::startBtp(this, "PowerStar");
    MultiScene::startBva(this, "PowerStar");
    MultiScene::setBtpFrameAndStop(this, PowerStar::getBtpFrameCurrentStage(mFrame));
    MultiScene::setBvaFrameAndStop(this, _44 == 0 ? 1.0f : 0.0f);
    MultiSceneActor::appear();
    setNerve(&NrvScenarioSelectStar::ScenarioSelectStarNrvAppear::sInstance);
}

void ScenarioSelectStar::kill() {
    MultiScene::forceDeleteEffectAll(this);
    MultiSceneActor::kill();
}

void ScenarioSelectStar::tryPointing() {
    _50 = true;

    if (isNerve(&NrvScenarioSelectStar::ScenarioSelectStarNrvNotPointing::sInstance)
        || isNerve(&NrvScenarioSelectStar::ScenarioSelectStarNrvEndPointing::sInstance))
    {
        setNerve(&NrvScenarioSelectStar::ScenarioSelectStarNrvPointing::sInstance);
    }
}

void ScenarioSelectStar::select() {
    setNerve(&NrvScenarioSelectStar::ScenarioSelectStarNrvSelected::sInstance);
}

void ScenarioSelectStar::notSelect() {
    setNerve(&NrvScenarioSelectStar::ScenarioSelectStarNrvNotSelected::sInstance);
}

bool ScenarioSelectStar::isAppearEnd() const {
    bool ret = !_30 && !isNerve(&NrvScenarioSelectStar::ScenarioSelectStarNrvAppear::sInstance);

    return ret;
}

void ScenarioSelectStar::setup(s32 a1, int a2, const TVec3f &a3, s32 a4) {
    _44 = a2;
    mFrame = a1;
    _5C.set<f32>(a3);
    _4C = a4;

    mRotation.set(0.0f, 0.0f, (150.0f * a4));
    int v7 = _4C;
    _74 = 15 * v7 + 60;
    _58 = 15 * v7 + ((v7 % 2) ? 0 : 0x5A);
}
/*
void ScenarioSelectStar::control() {
    _50 = false;
    mRotation.z = MR::modAndSubtract(mRotation.z + _54, 360.0f, 0.0f);

    if (isNerve(&NrvScenarioSelectStar::ScenarioSelectStarNrvNotPointing::sInstance)
        || isNerve(&NrvScenarioSelectStar::ScenarioSelectStarNrvPointing::sInstance)
        || isNerve(&NrvScenarioSelectStar::ScenarioSelectStarNrvEndPointing::sInstance))
    {
        _58++;
        updatePos();
    }
}
*/

bool ScenarioSelectStar::tryEndPointing() {
    if (!_50) {
        setNerve(&NrvScenarioSelectStar::ScenarioSelectStarNrvEndPointing::sInstance);
        return true;
    }

    return false;
}

/*
void ScenarioSelectStar::updatePos() {
    f32 mod = MR::modAndSubtract(360.0f * (_58 / 180.0f), 360.0f, 0.0f);
    //f32 val = MR::sin_inline(mod);

    _58 = mod;
}
*/

void ScenarioSelectStar::exeAppear() {
    if (MultiScene::isStep(this, _74)) {
        MultiScene::startBck(this, "ScenarioAppear");
        MR::startSystemSE("SE_OJ_SCEN_SEL_STAR_APPEAR", -1, -1);
    }

    if (MultiScene::isStep(this, _74 + 1)) {
        if (_44 == 1) {
            MultiScene::emitEffect(this, "ClearStarLight");
        }
        else {
            MultiScene::emitEffect(this, "Light");
        }
    }

    if (MultiScene::isGreaterStep(this, _74)) {
        MultiScene::setNerveAtBckStopped(this, &NrvScenarioSelectStar::ScenarioSelectStarNrvNotPointing::sInstance);
    }
}

void ScenarioSelectStar::exeNotPointing() {
    if (MultiScene::isFirstStep(this)) {
        mScale.x = 0.9f;
        mScale.y = 0.9f;
        mScale.z = 0.9f;
        _54 = 1.5f;
    }
}

void ScenarioSelectStar::exePointing() {
    if (MultiScene::isFirstStep(this)) {
        MR::startSystemSE("SE_SY_CURSOR_1", -1, -1);
        MR::tryRumblePadWeak(this, 0);
        _54 = 3.0f;
    }

    if (MultiScene::isLessStep(this, 20)) {
        f32 rate = MultiScene::calcNerveRate(this, 20);
        f32 scale = MR::getScaleWithReactionValueZeroToOne(rate, 1.5f, -0.25f);
        f32 linerVal = MR::getLinerValue(scale, 0.9f, 1.5f, 1.0f);
        mScale.setAll<f32>(linerVal);
    }
    else {
        mScale.x = 1.5f;
        mScale.y = 1.5f;
        mScale.z = 1.5f;
    }

    tryEndPointing();
}

void ScenarioSelectStar::exeEndPointing() {
    if (MultiScene::isFirstStep(this)) {
        _54 = 1.5f;
    }

    f32 easeOut = MR::getEaseOutValue(MultiScene::calcNerveRate(this, 10), 1.5f, 0.9f, 1.0f);
    mScale.set(easeOut);
    MultiScene::setNerveAtStep(this, &NrvScenarioSelectStar::ScenarioSelectStarNrvNotPointing::sInstance, 10);
}

void ScenarioSelectStar::exeSelected() {
    if (MultiScene::isFirstStep(this)) {
        MultiScene::emitEffect(this, "Select");
        MR::tryRumblePadMiddle(this, 0);
        _68.set<f32>(mTranslation);
        _54 = 3.0f;
        _78 = mScale.x;
    }

    mScale.set(MultiScene::calcNerveValue(this, 40, _78, 1.5f));
    MultiScene::setNerveAtStep(this, &NrvScenarioSelectStar::ScenarioSelectStarNrvSelectedMove::sInstance, 40);
}

void ScenarioSelectStar::exeSelectedMove() {
    if (MultiScene::isFirstStep(this)) {
        mScale.x = 1.5f;
        mScale.y = 1.5f;
        mScale.z = 1.5f;
    }

    if (MultiScene::isStep(this, 60)) {
        MR::startSystemSE("SE_DM_SENARIO_SE_ACCEL", -1, -1);
    }

    if (MultiScene::isLessStep(this, 60)) {
        f32 rate = 1.0f - MultiScene::calcNerveEaseOutRate(this, 60);
        mTranslation.scale(rate, _68);
        _54 = MR::getLinerValue(rate, 3.0f, 6.0f, 1.0f);
    }
    else {
        mTranslation.x = 0.0f;
        mTranslation.y = 0.0f;
        mTranslation.z = 0.0f;
        _54 = MR::getLinerValue(MultiScene::calcNerveRate(this, 60, 180), 6.0f, 20.0f, 1.0f);
    }
}

void ScenarioSelectStar::exeNotSelected() {
    s32 v2 = 10 * _4C;

    if (MultiScene::isFirstStep(this)) {
        _54 = 1.5f;
    }

    if (MultiScene::isStep(this, v2)) {
        _54 = 0.0f;
        mRotation.z = 150.0f * _4C;
        MultiScene::startBck(this, "ScenarioHide");
        MultiScene::deleteEffectAll(this);
    }

    if (MultiScene::isGreaterStep(this, v2)) {
        if (MultiScene::isBckStopped(this)) {
            kill();
        }
    }
}

ScenarioSelectStar::~ScenarioSelectStar() {

}
