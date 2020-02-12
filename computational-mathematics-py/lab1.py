import numpy

from scipy.interpolate import spline, lagrange
from math import tan
from scipy.integrate import quad

x = numpy.array([-1.0, -0.96, -0.86, -0.79, 0.22, 0.5, 0.93])
fx = numpy.array([-1.0, -0.151, 0.894, 0.986, 0.895, 0.5, -0.306])


def getXk(k):
    return -1 + 0.1 * k


xk = numpy.array([])
for i in range(1, 20):
    xk = numpy.append(xk, getXk(i))

splineResult = spline(x, fx, xk)
lagrangeResult = lagrange(x, fx)

for i in range(0, 19):
    print("Xk = " + str(xk[i])),
    print(":\t SPLINE: " + str(splineResult[i])) ,
    print ("\tLAGRANGE: " + str(lagrangeResult(xk[i]))),
    print (" \t S - L: " + str(float(splineResult[i] - lagrangeResult(xk[i]))))

quanc8Result = quad(lambda num: tan(num) / num, 1, 2)
print ("integral for quanc8: " + str(quanc8Result))
