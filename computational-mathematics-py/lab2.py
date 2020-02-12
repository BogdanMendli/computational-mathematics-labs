import numpy

matrixA = numpy.asmatrix([[13.0, 2.0, 8.0, -7.0, 7.0, 5.0, -7.0, -7.0],
                          [7.0, 2.0, -4.0, 2.0, 3.0, 3.0, -1.0, -2.0],
                          [-7.0, 2.0, 1.0, 3.0, 6.0, -6.0, -3.0, -4.0],
                          [-2.0, -8.0, -6.0, -1.0, 6.0, 2.0, 1.0, -4.0],
                          [0.0, 4.0, -7.0, 1.0, 22.0, 0.0, -6.0, -6.0],
                          [0.0, -3.0, -6.0, 6.0, 4.0, 13.0, 0.0, 6.0],
                          [-8.0, -6.0, -4.0, 7.0, -5.0, -5.0, -2.0, 1.0],
                          [5.0, 5.0, -2.0, -2.0, -3.0, 0.0, -7.0, 14.0]])

matrixB = numpy.asmatrix([[6.0], [36.0], [-25.0], [-57.0], [32.0], [62.0], [-71.0], [70.0]])

pValues = [1.0, 0.1, 0.01, 0.0001, 0.000001]

for p in pValues:
    print('P =', p)
    matrixA[0, 0] = 13.0 + p
    matrixB[0, 0] = 6.0 + 4 * p
    print("A(0,0):\t"
          + str(matrixA[0, 0]))
    print("B(0,0):\t"
          + str(matrixB[0, 0]))
    print("X1: \n"
          + str(numpy.linalg.solve(
                matrixA,
                matrixB))
          + "\n\n")
    newMatrixA = matrixA.transpose() * matrixA
    newMatrixB = matrixA.transpose() * matrixB
    print('X2: \n'
          + str(numpy.linalg.solve(newMatrixA, newMatrixB))
          + "\n\n")
    print("COND - P: \n"
          + str(numpy.linalg.cond(matrixA)
                - (numpy.linalg.solve(matrixA, matrixB)
                   - numpy.linalg.solve(newMatrixA, newMatrixB)
                   / numpy.linalg.solve(newMatrixA, newMatrixB)))
          + "\n")
    print("----------------------------------------------\n")