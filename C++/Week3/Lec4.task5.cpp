#include <iostream>
#include <vector>
#include <string>
#include <execinfo.h>
#include <cxxabi.h>

class Backtrace {
private:
    std::vector<std::string> stackFrames; // Vector to store the stack frames

    // Demangle the function names from the stack trace
    std::string demangle(const char* symbol) {
        size_t size;
        int status;
        char temp[256];
        char* demangled;
        // Attempt to demangle the symbol using abi::__cxa_demangle
        if (sscanf(symbol, "%*[^(]%*[^_]%255[^)+]", temp) == 1) {
            if ((demangled = abi::__cxa_demangle(temp, nullptr, &size, &status)) != nullptr) {
                std::string result(demangled);
                free(demangled);
                return result;
            }
        }
        // If demangling fails, return the original symbol
        return symbol;
    }

public:
    // Constructor to capture the backtrace
    Backtrace(size_t maxFrames = 64) {
        void* callstack[maxFrames];
        int frames = backtrace(callstack, maxFrames);
        char** strs = backtrace_symbols(callstack, frames);
        for (int i = 0; i < frames; ++i) {
            stackFrames.push_back(demangle(strs[i]));
        }
        free(strs);
    }

    // Method to print the backtrace
    void print() const {
        for (size_t i = 0; i < stackFrames.size(); ++i) {
            std::cout << i << ": " << stackFrames[i] << std::endl;
        }
    }

    // Method to return the backtrace as a vector of strings
    std::vector<std::string> getBacktrace() const {
        return stackFrames;
    }
};
void func3() {
    Backtrace bt;   // Capture the backtrace
    bt.print();     // Print the captured backtrace
}

void func2() {
    func3();
}

void func1() {
    func2();
}

int main() {
    func1();
    return 0;
}