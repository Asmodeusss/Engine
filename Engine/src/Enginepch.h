#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Engine/Log.h"
#include "Engine/KeyCodes.h"

#ifdef PLATFORM_WINDOWS
	#include <Windows.h>
	#include <stdint.h>
#endif