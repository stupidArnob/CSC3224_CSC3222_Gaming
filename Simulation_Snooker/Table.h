/**
 * @file
 * @author Dan Nixon
 */

#pragma once

#include <RenderableObject.h>
#include <Vector2.h>
#include "Cushion.h"

/**
 * @class Table
 * @brief Represents a snooker table.
 * @author Dan Nixon
 */
class Table : public Engine::Graphics::RenderableObject
{
public:
  static const Engine::Maths::Vector2 DIMENSIONS;
  static const Engine::Maths::Vector2 HALF_DIMENSIONS;

  Table();
  virtual ~Table();

private:
  Cushion *m_cushions[4]; //!< Side cushions
};