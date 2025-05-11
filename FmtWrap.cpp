module;

// #include <fmt/format.h> // not working // tried with fmt-headen-only

export module fmtwrap;

import std;
// import std.compat;
import fmt; // also not working!

export namespace fmtwrap {

// template <class... Args>
// auto format(std::format_string<Args...>&& fstr, Args&&... args) {
//     return std::format(fstr, static_cast<Args&&>(args)...);
// }
template <class... Args>
auto format(fmt::format_string<Args...>&& fstr, Args&&... args) {
    return fmt::format(static_cast<fmt::format_string<Args...>&&>(fstr),
        static_cast<Args&&>(args)...);
}

}
