/**
 * @file
 * @author Dan Nixon
 */

#ifndef _DEMOGAME_H_
#define _DEMOGAME_H_

#include <Game.h>

#include <SDL_ttf.h>

#include <Context.h>
#include <IControlScheme.h>
#include <IMenu.h>
#include <Listener.h>
#include <RenderableObject.h>
#include <Scene.h>
#include <SceneObject.h>
#include <ShaderProgram.h>
#include <Source.h>

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
  int gameStartup();
  void gameLoop(Uint8 id, float dtMilliSec);
  void gameShutdown();

private:
  Uint8 m_graphicsLoop;
  Uint8 m_physicsLoop;
  Uint8 m_audioLoop;
  Uint8 m_profileLoop;
  Uint8 m_testLoop;

  TTF_Font *m_font;

  Engine::Graphics::ShaderProgram *m_sp;
  Engine::Graphics::ShaderProgram *m_uiShader;

  Engine::Graphics::RenderableObject *m_leftStick;
  Engine::Graphics::RenderableObject *m_rightStick;

  Engine::Maths::Matrix4 m_losPMatrix; //!< Perspective matrix for line of sight flying
  Engine::Maths::Matrix4 m_fpvPMatrix; //!< Perspective matrix for first person view flying
  Engine::Common::Scene *m_s;          //!< Scene containing world (terrain and models)
  Engine::Common::Scene *m_ui;         //!< Scene containing UI
  Engine::UIMenu::IMenu *m_menu;

  Engine::Audio::Context *m_audioContext;
  Engine::Audio::Listener *m_audioListener;
  Engine::Audio::Source *m_audioSource1;
  Engine::Audio::Source *m_audioSource2;

  Engine::Common::SceneObject *m_model;

  Engine::Input::IControlScheme *m_simControls;
};

#endif