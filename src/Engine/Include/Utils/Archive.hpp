#pragma once

#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace  ENG
{
  class Archive
  {
    public: 
      static std::string LoadArchive(std::string path)
      {
        std::ifstream file(path);
        if(!file)
        {
          std::string s = "Cant Load " + path;
          throw std::runtime_error(s);
        }
        std::stringstream buff;
        buff << file.rdbuf();
        return buff.str();
      }

    private:

  };
}
