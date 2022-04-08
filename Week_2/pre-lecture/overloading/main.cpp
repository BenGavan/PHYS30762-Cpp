#include<iostream>

int max(int v1, int v2)
{
    return (v1 > v2) ? v1 : v2;
}

double max(double v1, double v2)
{
    return (v1 > v2) ? v1 : v2;
}

float max(float v1, float v2)
{
    if (v1 > v2) return v1;
    return v2;
}

int main()
{
    int v1{1};
    int v2{2};

    std::cout << "max: " << max(3,2) << std::endl;

    float v1_f{1};
    float v2_f{2};

    std::cout << "max: " << max(v1_f, v2_f) << std::endl;

    double v1_d{4};
    double v2_d{3};

    std::cout << "max: " << max(v1_d, v2_d) << std::endl;
    return 0;
}

