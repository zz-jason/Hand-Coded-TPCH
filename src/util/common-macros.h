#ifndef HCTH_UTIL_COMMON_MACROS_H
#define HCTH_UTIL_COMMON_MACROS_H

/// Compiler hint that this branch is likely or unlikely to
/// be taken. Take from the "What all programmers should know
/// about memory" paper.
#ifdef LIKELY
#undef LIKELY
#endif

#ifdef UNLIKELY
#undef UNLIKELY
#endif

#define LIKELY(expr) __builtin_expect(!!(expr), 1)
#define UNLIKELY(expr) __builtin_expect(!!(expr), 0)

/// Force inlining. The 'inline' keyword is treated by most compilers as a hint,
/// not a command. This should be used sparingly for cases when either the function
/// needs to be inlined for a specific reason or the compiler's heuristics make a bad
/// decision, e.g. not inlining a small function on a hot path.
#ifdef ALWAYS_INLINE
#undef ALWAYS_INLINE
#endif
#define ALWAYS_INLINE __attribute__((always_inline))

#ifdef SAFE_DELETE
#undef SAFE_DELETE
#endif
#define SAFE_DELETE(x) \
do { \
    delete x; \
    x = NULL; \
} while (false);

#endif
