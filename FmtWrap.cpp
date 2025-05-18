export module fmtwrap;

import std;
import fmt;

export namespace fmtwrap {

template <class... Args>
auto format(fmt::format_string<Args...>&& fstr, Args&&... args) {
    return fmt::format(static_cast<fmt::format_string<Args...>&&>(fstr),
        static_cast<Args&&>(args)...);
}

} // namespace fmtwrap
