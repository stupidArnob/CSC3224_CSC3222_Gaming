/**
 * @file
 * @author Dan Nixon (120263697)
 *
 * For CSC3222 Project 2.
 */

#ifndef _SIMULATION_PATHFINDING_NODE_H_
#define _SIMULATION_PATHFINDING_NODE_H_

#include <vector>

#include <Engine_Maths/Vector3.h>

namespace Simulation
{
namespace PathFinding
{
  class Arc;

  /**
   * @class Node
   * @brief Represents a node in a map.
   * @author Dan Nixon
   */
  class Node
  {
  public:
    Node(const std::string &id, const Engine::Maths::Vector3 &position);
    virtual ~Node();

    /**
     * @brief Gets the ID of the node.
     * @retrun String ID
     */
    inline std::string id() const
    {
      return m_id;
    }

    /**
     * @brief Gets the position of this node.
     * @return Node position
     */
    inline Engine::Maths::Vector3 position() const
    {
      return m_position;
    }

  private:
    friend class Edge;

    const std::string m_id;            //!< String ID of the node
    std::vector<Edge *> m_connections; //!< Edges of this node
    Engine::Maths::Vector3 m_position; //!< Posiion of this node
  };
}
}

#endif