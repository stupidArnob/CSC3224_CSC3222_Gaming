/**
 * @file
 * @author Dan Nixon
 */

#ifndef _SIMULATION_PHYSICS_PHYSICSSIMULATION_H_
#define _SIMULATION_PHYSICS_PHYSICSSIMULATION_H_

#include "Entity.h"
#include "InterfaceDef.h"

namespace Simulation
{
namespace Physics
{
  /**
   * @class PhysicsSimulation
   * @brief Contains utilities for running a physical simulation.
   * @author Dan Nixon
   */
  class PhysicsSimulation
  {
  public:
    PhysicsSimulation();
    virtual ~PhysicsSimulation();

    /**
     * @brief Pauses or resumes the simulation.
     * @param run If the simulation should be running
     */
    void setRunning(bool run)
    {
      m_run = run;
    }

    /**
     * @param Checks if the simulation is running.
     * @return True if the simualtion is running
     */
    bool running() const
    {
      return m_run;
    }

    /**
     * @brief Adds a new entity to the simulation.
     * @param ent New entity to add
     */
    void addEntity(Entity *ent)
    {
      m_entities.push_back(ent);
    }

    /**
     * @brief Gets a list of all entities managed by this system.
     * @return Entities
     */
    Entity::EntityPtrList &entities()
    {
      return m_entities;
    }

    /**
     * @brief Gets a list of all current interfaces.
     * @return Interfaces
     */
    std::vector<InterfaceDef> interfaces()
    {
      return m_interfaces;
    }

    /**
     * @brief Performs all physics updates.
     * @param dtMilliSec Time step in milliseconds
     */
    inline void update(float dtMilliSec)
    {
      if (m_run)
      {
        updatePositions(dtMilliSec);
        detectInterfaces();
        resolveInterfaces();
      }
    }

  private:
    void updatePositions(float dtMilliSec);
    void detectInterfaces();
    void resolveInterfaces();

  private:
    bool m_run;
    Entity::EntityPtrList m_entities;
    std::vector<InterfaceDef> m_interfaces;
  };
}
}

#endif