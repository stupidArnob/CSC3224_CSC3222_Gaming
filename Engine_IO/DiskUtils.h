/**
 * @file
 * @author Dan Nixon
 */

#ifndef _ENGINE_IO_DISKUTILS_H_
#define _ENGINE_IO_DISKUTILS_H_

#include <string>

namespace Engine
{
namespace IO
{
  class DiskUtils
  {
  public:
    static bool Exists(const std::string &path);

    static bool MakeDirectories(const std::string &path);

    static bool IsFile(const std::string &path);
    static bool IsDirectory(const std::string &path);
  };
}
}

#endif