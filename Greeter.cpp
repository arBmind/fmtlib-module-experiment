export module greeter;

import std;
import fmtwrap;

export struct Greeter {
    static auto person(std::string_view name) -> std::string {
        return fmtwrap::format("Hello {}", name);
    }
};
