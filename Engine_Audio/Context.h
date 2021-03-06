/**
 * @file
 * @author Dan Nixon (120263697)
 *
 * For CSC3224 Project 1.
 */

#ifndef _ENGINE_AUDIO_CONTEXT_H_
#define _ENGINE_AUDIO_CONTEXT_H_

#include <vector>

#include <alc.h>

#include <Engine_ResourceManagment/IMemoryManaged.h>

namespace Engine
{
namespace Audio
{
  /**
   * @class Context
   * @brief Manages an AL context for playing audio.
   * @author Dan Nixon
   */
  class Context : public Engine::ResourceManagment::IMemoryManaged
  {
  public:
    Context();
    virtual ~Context();

    bool open();
    void close();
    bool isOpen() const;

    /**
     * @brief Gets the device used for this context.
     * @return Device
     */
    inline ALCdevice *getDevice() const
    {
      return m_device;
    }

    /**
     * @brief Gets the context.
     * @return Context
     */
    inline ALCcontext *getContext() const
    {
      return m_context;
    }

  private:
    ALCdevice *m_device;   //!< AL device
    ALCcontext *m_context; //!< AL context
  };
}
}

#endif
