/**
* @file
* @author Dan Nixon
*/

#pragma once

#include "Entity.h"

namespace Simulation
{
namespace Physics
{
  /**
   * @class SphericalEntity
   * @brief Represents an entity in a 2D circle.
   * @author Dan Nixon
   */
  class SphericalEntity : public Entity
  {
  public:
    SphericalEntity(const Engine::Maths::Vector2 &pos, float radius);
    virtual ~SphericalEntity();

    float radius() const;
    float radius2() const;

    void setRadius(float radius);

  private:
    float m_radius2; //!< Radius squared
  };
}
}