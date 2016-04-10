/**
 * @file
 * @author Dan Nixon
 */

#ifndef _SIMULATION_SNOOKER_PLAYERSTATE_H_
#define _SIMULATION_SNOOKER_PLAYERSTATE_H_

#include <string>

#include <Simulation_AI/FunctionalState.h>
#include <Simulation_AI/StateMachine.h>

#include "SnookerSimulation.h"

namespace Simulation
{
namespace Snooker
{
  class PlayerState : public Simulation::AI::FunctionalState
  {
  public:
    PlayerState(Simulation::AI::IState *parent, Simulation::AI::StateMachine *machine, int playerNumber,
                SnookerSimulation *simulation)
        : FunctionalState("player_" + std::to_string(playerNumber), parent, machine)
        , m_playerNumber(playerNumber)
        , m_score(0)
        , m_simulation(simulation)
    {
    }

    inline int playerNumber() const
    {
      return m_playerNumber;
    }

    inline int score() const
    {
      return m_score;
    }

    inline void reset()
    {
      m_score = 0;
    }

    inline void addToScore(int points)
    {
      m_score += points;
      updateScoreText();
    }

    void updateScoreText() const
    {
      if (m_playerNumber == 0)
        m_simulation->player1ScoreText->setText(std::to_string(m_score));
      else if (m_playerNumber == 1)
        m_simulation->player2ScoreText->setText(std::to_string(m_score));
    }

    PlayerState *otherPlayer() const
    {
      std::string name = "game/running/player_" + std::to_string((m_playerNumber + 1) % 2);
      return dynamic_cast<PlayerState *>(m_machine->rootState()->findState(name).back());
    }

  protected:
    virtual void onEntry(IState *last)
    {
      updateScoreText();

      // Update current player indicator
      m_simulation->player1IndicatorText->setActive(m_playerNumber == 0);
      m_simulation->player2IndicatorText->setActive(m_playerNumber == 1);

      if (last->name() == "pot_cue_ball" || last->name() == "running")
        findState("place_cue_ball").back()->setActivation(true, this, this);
      else
        findState("take_shot").back()->setActivation(true, this, this);
    }

  private:
    int m_playerNumber; //!< Player number (0 or 1)
    int m_score;        //!< Players score
    SnookerSimulation *m_simulation;
  };
}
}

#endif