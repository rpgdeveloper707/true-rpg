if(NOT TRUERPG_CCACHE_DISABLE)
  set(CMAKE_C_COMPILER_LAUNCHER "ccache")
  set(CMAKE_CXX_COMPILER_LAUNCHER "ccache")
endif()
