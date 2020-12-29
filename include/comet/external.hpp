#ifdef COMET_IMPLEMENTATION

  #define GLFW_INCLUDE_NONE

  #include <GL/glew.h>
  #include <GLFW/glfw3.h>
  #include <comet/types.hpp>

  #define GL_CALL(...)                                                      \
    while(glGetError() != GL_NO_ERROR)                                      \
      ;                                                                     \
    __VA_ARGS__;                                                            \
    if(auto error_code = glGetError())                                      \
    {                                                                       \
      String error_name;                                                    \
                                                                            \
      switch(error_code)                                                    \
      {                                                                     \
      case 0x0500:                                                          \
        error_name = "GL_INVALID_ENUM";                                     \
        break;                                                              \
      case 0x0501:                                                          \
        error_name = "GL_INVALID_VALUE";                                    \
        break;                                                              \
      case 0x0502:                                                          \
        error_name = "GL_INVALID_OPERATION";                                \
        break;                                                              \
      case 0x0503:                                                          \
        error_name = "GL_STACK_OVERFLOW";                                   \
        break;                                                              \
      case 0x0504:                                                          \
        error_name = "GL_STACK_UNDERFLOW";                                  \
        break;                                                              \
      case 0x0505:                                                          \
        error_name = "GL_OUT_OF_MEMORY";                                    \
        break;                                                              \
      case 0x0506:                                                          \
        error_name = "GL_INVALID_FRAMEBUFFER_OPERATION";                    \
        break;                                                              \
      case 0x0507:                                                          \
        error_name = "GL_CONTEXT_LOST";                                     \
        break;                                                              \
      case 0x8031:                                                          \
        error_name = "GL_TABLE_TOO_LARGE";                                  \
        break;                                                              \
      }                                                                     \
                                                                            \
      throw comet::RuntimeError("An OpenGL error occurred (" + error_name + \
                                ").");                                      \
    }

#endif
