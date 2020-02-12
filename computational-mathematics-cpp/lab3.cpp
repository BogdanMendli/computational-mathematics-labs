#include <cstdio>
#include <cmath>
#include <iostream>
#include "Apollo/rkf45.h"

void sourceFunction(double, double *, double *);

int main() {
    int N = 2;
    int FLAG = 1;
    double WORK[15];
    int I_WORK[30];
    double X0[2] = {0, 1};
    double T = 0;
    double TOUT = 0;
    double R_EPSILON = 0.0001;
    double A_EPSILON = 0.0001;
    double h = 0.02;
    std::cout << std::endl << "result for RKF45 with H = 0.02 and EPSILON = 0.0001" << std::endl << std::endl;
    while (TOUT < 1.00001) {
        RKF45(sourceFunction, N, X0, &T, &TOUT, &R_EPSILON, &A_EPSILON, &FLAG, WORK, I_WORK);
        printf("T = %.2f,\t FLAG = %d, \t X = (%.6f; %.6f)\n", T, FLAG, X0[0], X0[1]);
        TOUT += h;
    }

    std::cout << std::endl << "---------------------------------------" << std::endl;

    double K1[2];
    double K2[2];
    double K3[2];
    double K4[2];
    double kTemporary[2];
    double Zn[2];

    std::cout << std::endl << "punct a) RKF4 4 degree for H_int = 0.01" << std::endl << std::endl;
    X0[0] = 0;
    X0[1] = 1;
    T = 0;
    h = 0.01;

    for (int i = 0; T < 1.01; i++) {

        sourceFunction(T, X0, K1);

        K1[0] *= h;
        K1[1] *= h;

        kTemporary[0] = X0[0] + K1[0] / 3;
        kTemporary[1] = X0[1] + K1[1] / 3;

        sourceFunction(T + h / 3, kTemporary, K2);

        K2[0] *= h;
        K2[1] *= h;

        kTemporary[0] = X0[0] - K1[0] / 3 + K2[0];
        kTemporary[1] = X0[1] - K1[1] / 3 + K2[1];

        sourceFunction(T + 2 * h / 3, kTemporary, K3);

        K3[0] *= h;
        K3[1] *= h;

        kTemporary[0] = X0[0] + K1[0] - K2[0] + K3[0];
        kTemporary[1] = X0[1] + K1[1] - K2[1] + K3[1];

        sourceFunction(T + h, kTemporary, K4);

        K4[0] *= h;
        K4[1] *= h;

        Zn[0] = X0[0] + (K1[0] + 3 * K2[0] + 3 * K3[0] + K4[0]) / 8;
        Zn[1] = X0[1] + (K1[1] + 3 * K2[1] + 3 * K3[1] + K4[1]) / 8;

        X0[0] = Zn[0];
        X0[1] = Zn[1];

        if (!(i % 2)) {
            printf("T = %.2f,\t X = (%.6f; %.6f)\n", T, Zn[0], Zn[1]);
        }

        T += h;
    }

    std::cout << std::endl << "---------------------------------------" << std::endl;
    std::cout << std::endl << "punct b) RKF4 4 degree for H_int = 0.0008" << std::endl << std::endl;
    X0[0] = 0;
    X0[1] = 1;
    T = 0;
    h = 0.0008;

    for (int i = 0; T < 1.005; i++) {

        sourceFunction(T, X0, K1);

        K1[0] *= h;
        K1[1] *= h;

        kTemporary[0] = X0[0] + K1[0] / 3;
        kTemporary[1] = X0[1] + K1[1] / 3;

        sourceFunction(T + h / 3, kTemporary, K2);

        K2[0] *= h;
        K2[1] *= h;

        kTemporary[0] = X0[0] - K1[0] / 3 + K2[0];
        kTemporary[1] = X0[1] - K1[1] / 3 + K2[1];

        sourceFunction(T + 2 * h / 3, kTemporary, K3);

        K3[0] *= h;
        K3[1] *= h;

        kTemporary[0] = X0[0] + K1[0] - K2[0] + K3[0];
        kTemporary[1] = X0[1] + K1[1] - K2[1] + K3[1];

        sourceFunction(T + h, kTemporary, K4);

        K4[0] *= h;
        K4[1] *= h;

        Zn[0] = X0[0] + (K1[0] + 3 * K2[0] + 3 * K3[0] + K4[0]) / 8;
        Zn[1] = X0[1] + (K1[1] + 3 * K2[1] + 3 * K3[1] + K4[1]) / 8;

        X0[0] = Zn[0];
        X0[1] = Zn[1];

        if (!(i % 20)) {
            printf("T = %.2f,\t X = (%.6f; %.6f)\n", T, Zn[0], Zn[1]);
        }

        T += h;
    }
}

void sourceFunction(double T, double *x, double *dx) {
    dx[0] = -310 * x[0] - 3000 * x[1] + 1
            / (10 * pow(T, 2) + 1);
    dx[1] = x[0] + exp(-2 * T);
}
