#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <regex>

namespace Config {
    inline const std::regex APP_NICKNAME_PATTERN(
        R"(^[^\s](?:[a-zA-Z0-9 ._,@#\-]*[^\s])?$)"
    );
}

#endif