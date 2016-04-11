/**
 * @file
 * @author Dan Nixon
 */

#ifndef _SIMULATION_SNOOKER_PLAYERSTATE_H_
#define _SIMULATION_SNOOKER_PLAYERSTATE_H_

#include <Simulation_AI/FunctionalState.h>

#include "SnookerSimulation.h"

namespace Simulation
{
namespace Snooker
{
  class PlayerState : public Simulation::AI::FunctionalState
  {
  public:
    PlayerState(Simulation::AI::IState *parent, Simulation::AI::StateMachine *machine, int playerNumber,
                SnookerSimulation *simulation);

    /**
     * @brief Gets the number of this player.
     * @return Player number
     */
    inline int playerNumber() const
    {
      return m_playerNumber;
    }

    /**
     * @brief Gets this players score.
     * @return Players score
     */
    inline int score() const
    {
      return m_score;
    }

    /**
     * @brief Resets this players score to zero.
     */
    inline void reset()
    {
      m_score = 0;
    }

    /**
     * @brief Increments this players score.
     * @param points Number of points to increment by
     */
    inline void addToScore(int points)
    {
      m_score += points;
      updateScoreText();
    }

    void updateScoreText() const;

    PlayerState *otherPlayer();

  protected:
    virtual void onEntry(IState *last);

  private:
    int m_playerNumber;              //!< Player number (0 or 1)
    int m_score;                     //!< Players score
    SnookerSimulation *m_simulation; //!< SImulation this player takes part in
    PlayerState *m_otherPlayer;      //!< Cached pointer to other player
  };
}
}

#endif