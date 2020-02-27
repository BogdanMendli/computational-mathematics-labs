# coding=utf-8
import math

import matplotlib.pyplot as plt
import numpy
from pylab import rcParams
from scipy.integrate import odeint
from scipy.integrate import quad
from scipy.special import *
from sympy import *

rcParams["figure.figsize"] = (12, 9)


def rhs(U, t, deltaM, eps):
    return [U[1], -(deltaM + eps * cos(2 * t)) * U[0]]


A = quad(lambda xk: 0.8476479 * math.exp(-5 * math.pow(xk, 3) + xk + 0.5), 0, 1)[0]
x = Symbol('x')
solveEquation = solve(x - 1.4 ** x, x)
B = solveEquation[0]
for solve in solveEquation:
    if B < solve:
        B = solve


B = (B - 4.4102905)**4
print(A)
print(B)

k = 0.5

U0 = A
U01 = B

startTime = 0.
endTime = 10.
NTimeSteps = 20
time = numpy.linspace(startTime, endTime, NTimeSteps + 1)
initX = [U0, U01]
initXk = [U0 * k, U01 * k]

delta = 1.
epsilon = 0.5
out0 = odeint(rhs, initX, time, args=(delta, epsilon))
out1 = odeint(rhs, initXk, time, args=(delta * k, epsilon * k))
print(out0)
plt.ioff()
plt.plot(time, out0[:, 0], label=r'$\delta = 1$, $\varepsilon = 0.5$')
plt.plot(time, out1[:, 0], label=r'$\delta = 1$, $\varepsilon = 0.5$')
plt.legend()
plt.show()
