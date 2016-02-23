/**
 * @file
 * @author Dan Nixon
 */

#include "Entity.h"

#include <Random.h>
#include <Vector3.h>

using namespace Engine::Maths;
using namespace Engine::Utility;

namespace Simulation
{
namespace Physics
{
  /**
   * @brief Creates an Entity with a randomised 2D position and aggro range.
   * @param symmLimit Limit for random number generation
   */
  Entity::Entity(float symmLimit)
  {
    if (symmLimit > 0.0f)
    {
      float aggroRange = Random::random(-symmLimit, symmLimit);

      m_position = Vector2(Random::random(-symmLimit, symmLimit),
                           Random::random(-symmLimit, symmLimit));
    }
  }

  /**
   * @brief Creates an Entity with a given position.
   * @param pos Position
   */
  Entity::Entity(const Vector2 &pos)
  {
  }

  Entity::~Entity()
  {
  }

  /**
   * @brief Sets the position of this Entity.
   * @param pos Position
   * @see Entity::shiftPosition()
   * @see Entity::position()
   */
  void Entity::setPosition(const Vector2 &pos)
  {
    m_position = pos;
  }

  /**
   * @brief Offsets the position of this Entity by a given amount.
   * @param offset Position offset
   * @see Entity::setPosition()
   * @see Entity::position()
   */
  void Entity::shiftPosition(const Vector2 &offset)
  {
    m_position += offset;
  }

  /**
   * @brief Sets the velocity of this Entity in the current timestep.
   * @param vel Velocity
   * @see Entity::velocity()
   */
  void Entity::setVelocity(const Vector2 &vel)
  {
    m_velocity = vel;
  }

  /**
   * @brief Sets the acceleration of this Entity in the current timestep.
   * @param acc Acceleration
   * @see Entity::acceleration()
   */
  void Entity::setAcceleration(const Vector2 &acc)
  {
    m_acceleration = acc;
  }
}
}
