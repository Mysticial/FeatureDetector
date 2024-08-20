/* Main.cpp
 *
 * Author           : Alexander J. Yee
 * Date Created     : 04/17/2015
 * Last Modified    : 04/17/2015
 *
 */

#include <iostream>
using std::cout;
using std::endl;

#include "x86/cpu_x86.h"
using namespace FeatureDetector;

bool case_insensitive_char_compare(char a, char b) {
    return std::tolower(a) == std::tolower(b);
}

bool case_insensitive_compare(const std::string& s1, const std::string& s2) {
    return s1.size() == s2.size() && std::equal(s1.begin(), s1.end(), s2.begin(), case_insensitive_char_compare);
}

int main(int argc, char* argv[]) {
    cpu_x86 features;
    features.detect_host();

    if (argc == 1)
    {
        cout << "CPU Vendor String: " << cpu_x86::get_vendor_string() << endl;
        cout << endl;

        features.print();
#if _WIN32
        system("pause");
#endif
        return 0;
    }

    struct feature {
        const char* name;
        bool cpu_x86::* feature;
    };

    static feature featureList[] = {
        {"AMD", &cpu_x86::Vendor_AMD},
        {"Intel", &cpu_x86::Vendor_Intel},

        {"OS AVX", &cpu_x86::OS_AVX},
        {"OS AVX512", &cpu_x86::OS_AVX512},

        {"MMX", &cpu_x86::HW_MMX},
        {"x64", &cpu_x86::HW_x64},
        {"ABM", &cpu_x86::HW_ABM},
        {"RDRAND", &cpu_x86::HW_RDRAND},
        {"RDSEED", &cpu_x86::HW_RDSEED},
        {"BMI1", &cpu_x86::HW_BMI1},
        {"BMI2", &cpu_x86::HW_BMI2},
        {"ADX", &cpu_x86::HW_ADX},
        {"MPX", &cpu_x86::HW_MPX},
        {"PREFETCHW", &cpu_x86::HW_PREFETCHW},
        {"PREFETCHWT1", &cpu_x86::HW_PREFETCHWT1},
        {"RDPID", &cpu_x86::HW_RDPID},
        {"GFNI", &cpu_x86::HW_GFNI},
        {"VAES", &cpu_x86::HW_VAES},

        {"SSE", &cpu_x86::HW_SSE},
        {"SSE2", &cpu_x86::HW_SSE2},
        {"SSE3", &cpu_x86::HW_SSE3},
        {"SSSE3", &cpu_x86::HW_SSSE3},
        {"SSE4a", &cpu_x86::HW_SSE4a},
        {"SSE4.1", &cpu_x86::HW_SSE41},
        {"SSE4.2", &cpu_x86::HW_SSE42},
        {"AES-NI", &cpu_x86::HW_AES},
        {"SHA", &cpu_x86::HW_SHA},

        {"AVX", &cpu_x86::HW_AVX},
        {"XOP", &cpu_x86::HW_XOP},
        {"FMA3", &cpu_x86::HW_FMA3},
        {"FMA4", &cpu_x86::HW_FMA4},
        {"AVX2", &cpu_x86::HW_AVX2},

        {"AVX512-F", &cpu_x86::HW_AVX512_F},
        {"AVX512-CD", &cpu_x86::HW_AVX512_CD},
        {"AVX512-PF", &cpu_x86::HW_AVX512_PF},
        {"AVX512-ER", &cpu_x86::HW_AVX512_ER},
        {"AVX512-VL", &cpu_x86::HW_AVX512_VL},
        {"AVX512-BW", &cpu_x86::HW_AVX512_BW},
        {"AVX512-DQ", &cpu_x86::HW_AVX512_DQ},
        {"AVX512-IFMA", &cpu_x86::HW_AVX512_IFMA},
        {"AVX512-VBMI", &cpu_x86::HW_AVX512_VBMI},
        {"AVX512-VPOPCNTDQ", &cpu_x86::HW_AVX512_VPOPCNTDQ},
        {"AVX512-4VNNIW", &cpu_x86::HW_AVX512_4VNNIW},
        {"AVX512-4FMAPS", &cpu_x86::HW_AVX512_4FMAPS},
        {"AVX512-VBMI2", &cpu_x86::HW_AVX512_VBMI2},
        {"AVX512-VPCLMUL", &cpu_x86::HW_AVX512_VPCLMUL},
        {"AVX512-VNNI", &cpu_x86::HW_AVX512_VNNI},
        {"AVX512-BITALG", &cpu_x86::HW_AVX512_BITALG},
        {"AVX512-BF16", &cpu_x86::HW_AVX512_BF16},
    };

    auto result = true;

    for (auto argIndex = 1; argIndex < argc; argIndex++)
    {
        for (const auto& feature : featureList)
        {
            if (!case_insensitive_compare(argv[argIndex], feature.name))
                continue;

            auto supported = features.*(feature.feature);
            if (!supported)
                result = false;

            cout << feature.name << " = " << (supported ? "Yes" : "No") << endl;
        }
    }

    cout << "Final = " << (result ? "Yes" : "No") << endl;

    return result ? 0 : 1;
}
