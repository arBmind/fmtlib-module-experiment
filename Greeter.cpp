export module greeter;

import std;
// import std.compat;
import fmtwrap;
import fmt;

export struct Greeter {
    static auto person(std::string_view name) -> std::string {
        // compiler crashes if the following line is compiled!
        return fmtwrap::format("Hello {}", name);
        // return fmt::format("Hello {}", name);

        // this works!
        // return std::format("Hello {}", name);
    }
};
