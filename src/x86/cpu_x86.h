/* cpu_x86.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 04/12/2014
 * Last Modified    : 04/12/2014
 * 
 */

#pragma once
#ifndef _cpu_x86_H
#define _cpu_x86_H



// Making Windows work for SSE defines
// https://msdn.microsoft.com/en-us/library/b0084kay.aspx
#ifdef _M_IX86_FP
#if _M_IX86_FP < 0
#define __SSE__ 1
#endif
#if _M_IX86_FP < 1
#define __SSE2__ 1
#endif
#endif

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <stdint.h>
#include <string>
namespace FeatureDetector{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
struct cpu_x86{
    //  Vendor
    bool Vendor_AMD;
    bool Vendor_Intel;

    //  OS Features
    bool OS_x64;
    bool OS_AVX;
    bool OS_AVX512;

    //  Misc.
    bool HW_MMX;
    bool HW_x64;
    bool HW_ABM;
    bool HW_RDRAND;
    bool HW_BMI1;
    bool HW_BMI2;
    bool HW_ADX;
    bool HW_PREFETCHWT1;
    bool HW_MPX;

    //  SIMD: 128-bit
    bool HW_SSE;
    bool HW_SSE2;
    bool HW_SSE3;
    bool HW_SSSE3;
    bool HW_SSE41;
    bool HW_SSE42;
    bool HW_SSE4a;
    bool HW_AES;
    bool HW_SHA;

    //  SIMD: 256-bit
    bool HW_AVX;
    bool HW_XOP;
    bool HW_FMA3;
    bool HW_FMA4;
    bool HW_AVX2;

    //  SIMD: 512-bit
    bool HW_AVX512_F;
    bool HW_AVX512_PF;
    bool HW_AVX512_ER;
    bool HW_AVX512_CD;
    bool HW_AVX512_VL;
    bool HW_AVX512_BW;
    bool HW_AVX512_DQ;
    bool HW_AVX512_IFMA;
    bool HW_AVX512_VBMI;

    // Compiler defines
    bool COMP_SSE;
    bool COMP_SSE_MATH;
    bool COMP_SSE2;
    bool COMP_SSE2_MATH;
    bool COMP_SSE3;
    bool COMP_SSSE3;
    bool COMP_SSE4;
    bool COMP_SSE41;
    bool COMP_SSE42;
    bool COMP_AVX;
    bool COMP_AVX2;
    bool COMP_AVX512_BW;
    bool COMP_AVX512_CD;
    bool COMP_AVX512_DQ;
    bool COMP_AVX512_F;
    bool COMP_AVX512_VL;

    // Extended subsets
    bool COMP_AVX512_4FMAPS;
    bool COMP_AVX512_4VNNIW;
    bool COMP_AVX512_IFMA;
    bool COMP_AVX512_VBMI;
    bool COMP_AVX512_VPOPCNTDQ;

public:
    cpu_x86();
    void detect_host();
    void detect_compiler();

    void print() const;
    static void print_host();
    static void print_warnings();

    static void cpuid(int32_t out[4], int32_t x);
    static std::string get_vendor_string();

    std::string warn_compiler() const;

private:
    static void print(const char* label, bool yes);

    static bool detect_OS_x64();
    static bool detect_OS_AVX();
    static bool detect_OS_AVX512();
};

// Because this is in the header, a linking program
// will correctly pick up the current features.
inline void cpu_x86::detect_compiler() {

#ifdef __SSE__
    COMP_SSE = true;
#endif

#ifdef __SSE_MATH__
    COMP_SSE_MATH = true;
#endif

#ifdef __SSE2__
    COMP_SSE2 = true;
#endif

#ifdef __SSE2_MATH___
    COMP_SSE2_MATH = true;
#endif

#ifdef __SSE3__
    COMP_SSE3 = true;
#endif

#ifdef __SSSE3__
    COMP_SSSE3 = true;
#endif

#ifdef __SSE4__
    COMP_SSE4 = true;
#endif

#ifdef __SSE4_1__
    COMP_SSE41 = true;
#endif

#ifdef __SSE4_2__
    COMP_SSE42 = true;
#endif

#ifdef __AVX__ 
    COMP_AVX = true;
#endif

#ifdef __AVX2__
    COMP_AVX2 = true;
#endif

#ifdef __AVX512BW__
    COMP_AVX512_BW = true;
#endif

#ifdef __AVX512CD__
    COMP_AVX512_CD = true;
#endif

#ifdef __AVX512DQ__
    COMP_AVX512_DQ = true;
#endif

#ifdef __AVX512F__
    COMP_AVX512_F = true;
#endif

#ifdef __AVX512VL__
    COMP_AVX512_VL = true;
#endif

#ifdef __AVX512FMAPS__
    COMP_AVX512_FMAPS = true;
#endif

#ifdef __AVX512VNNIW__
    COMP_AVX512_VNNIW = true;
#endif

#ifdef __AVX512IFMA__
    COMP_AVX512_IFMA = true;
#endif

#ifdef __AVX512VBMI__
    COMP_AVX512_VBMI = true;
#endif

#ifdef __AVX512VPOPCNTDQ__
    COMP_AVX512_VPOPCNTDQ = true;
#endif

}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif
