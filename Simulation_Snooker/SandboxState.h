/**
 * @file
 * @author Dan Nixon
 */

#ifndef _SIMULATION_SNOOKER_SANDBOXSTATE_H_
#define _SIMULATION_SNOOKER_SANDBOXSTATE_H_

#include <string>

#include <Engine_Graphics/LineMesh.h>
#include <Engine_Maths/VectorOperations.h>

#include <Simulation_AI/IState.h>
#include <Simulation_AI/StateMachine.h>

#include "SnookerControls.h"
#include "SnookerSimulation.h"
#include "WaitForShotState.h"

namespace Simulation
{
namespace Snooker
{
  class SandboxState : public Simulation::AI::IState
  {
  public:
    SandboxState(Simulation::AI::IState *parent, Simulation::AI::StateMachine *machine, SnookerSimulation *simulation);
    virtual ~SandboxState();

  protected:
    virtual IState *testTransferFrom() const;
    virtual void onEntry(IState *last);
    virtual void onOperate();

  private:
    inline void resetMouseStartPosition()
    {
      if (m_mouseStartPosition != nullptr)
        delete m_mouseStartPosition;
      m_mouseStartPosition = nullptr;
    }

  private:
    SnookerSimulation *m_simulation;
    Engine::Maths::Vector2 *m_mouseStartPosition;
  };
}
}

#endif