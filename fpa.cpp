#include <stdio.h>

// Function to calculate Unadjusted Function Points (UFP)
float calculate_ufp(int inputs, int files, int queries, int interfaces, int outputs) {
    // Ratios for each type of FP
    float ratios_ip[3] = {1.0, 6.0, 3.0};   // Simple:Average:Complex for i/p
    float ratios_file[3] = {1.0, 2.0, 2.0}; // Simple:Average:Complex for file
    float ratios_query[3] = {1.0, 1.0, 1.0}; // All queries are average complexity
    float ratios_if[3] = {0.0, 0.0, 1.0};   // All interfaces are complex
    float ratios_op[3] = {2.0, 2.0, 1.0};   // Simple:Average:Complex for o/p
    
    // Weight factors for FP complexity
    float weights[3] = {0.5, 1.0, 1.5}; // Simple, Average, Complex
    
    // Calculate UFP for each type
    float ufp = 0.0;

    // Calculate UFP for i/p (inputs)
    for (int i = 0; i < 3; ++i) {
        ufp += (ratios_ip[i] / 10.0) * inputs;
    }

    // Calculate UFP for file (files)
    for (int i = 0; i < 3; ++i) {
        ufp += (ratios_file[i] / 5.0) * files;
    }

    // UFP for query (queries)
    ufp += ratios_query[1] * queries; // All queries are average complexity

    // UFP for i/f (interfaces)
    ufp += ratios_if[2] * interfaces; // All interfaces are complex

    // Calculate UFP for o/p (outputs)
    for (int i = 0; i < 3; ++i) {
        ufp += (ratios_op[i] / 5.0) * outputs;
    }

    return ufp;
}

// Function to calculate TDI and VAF
void calculate_tdi_and_vaf(float reliability, float complexity, float *tdi, float *vaf) {
    // Calculate TDI (Technical Difficulty Indicator)
    *tdi = 0.6 + (0.01 * (reliability + complexity));
    
    // Calculate VAF (Value Adjustment Factor)
    *vaf = 0.65 + (0.01 * complexity);
}

// Function to calculate Adjusted Function Points (AFP)
float calculate_afp(float ufp, float vaf) {
    return ufp * vaf;
}

int main() {
    // Given inputs
    int inputs = 60;
    int files = 25;
    int queries = 35;
    int interfaces = 20;
    int outputs = 25;

    float reliability = 0.65; // 65%
    float complexity = 0.75;  // 0.75

    // Calculate UFP
    float ufp = calculate_ufp(inputs, files, queries, interfaces, outputs);
    printf("Unadjusted Function Points (UFP): %.2f\n", ufp);

    // Calculate TDI and VAF
    float tdi, vaf;
    calculate_tdi_and_vaf(reliability, complexity, &tdi, &vaf);
    printf("Technical Difficulty Indicator (TDI): %.2f\n", tdi);
    printf("Value Adjustment Factor (VAF): %.2f\n", vaf);

    // Calculate AFP
    float afp = calculate_afp(ufp, vaf);
    printf("Adjusted Function Points (AFP): %.2f\n", afp);

    return 0;
}
