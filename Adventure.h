#ifndef ADVENTURE_H
#define ADVENTURE_H

#include "Cat.h"
#include <string>

class Adventure
{
public:
    Adventure(Cat& cat);
    void play();

private:
    Cat& m_cat;
    int m_room;
    int m_mischief;
    bool m_finished;
    bool m_foundToy;
    bool m_scratchedCouch;
    bool m_pushedRemote;
    bool m_climbedCurtains;
    bool m_zoomedAcrossCouch;
    bool m_scratchedTV;
    bool m_boopedRascal;

    int getChoice(const int minimum, const int maximum) const;
    void livingRoom();
    void exploreCouch();
    void exploreCurtains();
    void exploreTVStand();
    void hallway();
    void kitchen();
    void bonusMission();
    void addMischief(const std::string& action);
    void finishGame(const std::string& title,
                    const std::string& ending, bool caught);
};

#endif
