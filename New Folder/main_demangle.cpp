#include <iostream>
#include <cxxabi.h>

int main() {
    const char* mangled_name = "_Z3fooPii";
    int status;
    char* demangled_name = abi::__cxa_demangle(mangled_name, 0, 0, &status);

    if (status == 0) {
        std::cout << "Demangled name: " << demangled_name << std::endl;
    } else {
        std::cout << "Demangling failed" << std::endl;
    }

    free(demangled_name);
    return 0;
}
