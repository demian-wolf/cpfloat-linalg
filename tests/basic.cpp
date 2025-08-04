#include <linalg_core.hpp>

int main() {
    linalg::CPFloatOptStructRAII fpopts;

    const size_t n = 3;

    float a[n] = {1.0f, 2.0f, 3.0f};
    float b[n] = {4.0f, 5.0f, 6.0f};

    float addf_X[n];
    float dotf_X;

    linalg::cpfloat_addf(addf_X, a, b, n, fpopts);
    linalg::cpfloat_dotf(&dotf_X, a, b, n, fpopts);

    return 0;
}
