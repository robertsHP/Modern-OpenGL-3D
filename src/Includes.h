#pragma once

#include <iostream>
#include <algorithm>
#include <math.h>
#include <random>
#include <memory>
#include <fstream>
#include <thread>
#include <sstream>

#include <ctime>
#include <utility>
#include <array>
#include <bitset>
#include <string>
#include <forward_list>
#include <list>
#include <any>
#include <stack>
#include <vector>
#include <map>
#include <set>

#include <windef.h>
#include "SDL.h"
#include "glad/gl.h"
#include "GL/glu.h"
#include <glm/ext.hpp>
#include "glm/gtc/matrix_transform.hpp"
#include "SDL_opengl.h"
#include "SDL_image.h"

typedef uint8_t U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;
typedef int8_t I8;
typedef int16_t I16;
typedef int32_t I32;
typedef int64_t I64;

namespace Func {
    int randRanged (int start, int end);
    template<typename Base, typename T> inline bool instanceOf(const T&);
}
