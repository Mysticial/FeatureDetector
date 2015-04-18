# FeatureDetector

A simple app that detects what hardware features are supported by the host CPU and operating system.

-----

Sample output for a Haswell processor:

````
CPU Vendor String: GenuineIntel

CPU Vendor:
    AMD         = No
    Intel       = Yes

OS Features:
    64-bit      = Yes
    OS AVX      = Yes
    OS AVX512   = No

Hardware Features:
    MMX         = Yes
    x64         = Yes
    ABM         = Yes
    RDRAND      = Yes
    BMI1        = Yes
    BMI2        = Yes
    ADX         = No
    MPX         = No
    PREFETCHWT1 = No

SIMD: 128-bit
    SSE         = Yes
    SSE2        = Yes
    SSE3        = Yes
    SSSE3       = Yes
    SSE4a       = No
    SSE4.1      = Yes
    SSE4.2      = Yes
    AES-NI      = Yes
    SHA         = No

SIMD: 256-bit
    AVX         = Yes
    XOP         = No
    FMA3        = Yes
    FMA4        = No
    AVX2        = Yes

SIMD: 512-bit
    AVX512-F    = No
    AVX512-CD   = No
    AVX512-PF   = No
    AVX512-ER   = No
    AVX512-VL   = No
    AVX512-BW   = No
    AVX512-DQ   = No
    AVX512-IFMA = No
    AVX512-VBMI = No

Summary:
    Safe to use AVX:     Yes
    Safe to use AVX512:  No

