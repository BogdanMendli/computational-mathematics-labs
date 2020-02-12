import utils.LagrangeInterpolation;

public class Main {
    public static void main(String[] args) {
        double[] x = {-1.000, -0.960, -0.860, -0.790, 0.220, 0.500, 0.930};
        double[] y = {-1.000, -0.151, 0.894, 0.986, 0.895, 0.500, -0.306};
        Spline spline = new Spline(x, y);
        LagrangeInterpolation lagrange = new LagrangeInterpolation(x, y);

        for (int i = 1; i <= 19; i++) {
            final double xk = getXk(i);
            final double splineResult = spline.Interpol(xk);
            final double lagrangeResult = lagrange.interpolar(xk);
            System.out.println(String.format(
                    "Xk = %2.1f:\tSPLINE = %1.10f \t LAGRANGE = %2.10f \t SPLINE - LAGRANGE = %2.10f",
                    xk,
                    splineResult,
                    lagrangeResult,
                    splineResult - lagrangeResult));
        }
    }

    private static double getXk(int i) {
        return -1 + 0.1 * i;
    }
}
