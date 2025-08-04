#ifndef LINALG_CHECK_HPP
#define LINALG_CHECK_HPP

#include <stdexcept>
#include <string>

namespace detail {
    inline void check(int status, const char* func) {
        #ifndef NDEBUG
            if (status) throw std::runtime_error(
                std::string(func) + ": returned error " + std::to_string(status),
            );
        #else
            (void)status;  // suppress warning for unused value
        #endif
    }
}

#endif /* LINALG_CHECK_HPP */
