/**
 * @file
 * @author Dan Nixon
 */

#ifndef _DEMOGAME_H_
#define _DEMOGAME_H_

#include <Game.h>

#include <RenderableObject.h>
#include <Scene.h>
#include <ShaderProgram.h>
#include <IControlScheme.h>

/**
 * @class DemoGame
 * @brief Game demonstrating features of the game engine.
 * @author Dan Nixon
 */
class DemoGame : public Engine::Common::Game
{
public:
  DemoGame();
  virtual ~DemoGame();

protected:
  void gameStartup();
  void gameLoop(Uint8 id, float dtMilliSec);
  void gameShutdown();

private:
  Uint8 m_graphicsLoop;
  Uint8 m_physicsLoop;
  Uint8 m_profileLoop;
  Uint8 m_testLoop;

  Engine::Graphics::ShaderProgram *m_sp;
  Engine::Common::Scene *m_s;

  Engine::Graphics::RenderableObject *m_cube;
  Engine::Graphics::RenderableObject *m_child;

  Engine::Input::IControlScheme * m_simControls;
};

#endif