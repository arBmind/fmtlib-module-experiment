import std;
import greeter;
// import fmtwrap;

int main() {
    // auto name = fmtwrap::format("{} {}", "Hans", "Wurst");
    auto name = "Hans";
    std::println("{}!", Greeter::person(name));
    return 0;
}
