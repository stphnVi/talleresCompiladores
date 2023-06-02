
import figuras.*;

public class App {
    public static void main(String[] args) throws Exception {
        FiguraGeometrica[] figura = new FiguraGeometrica[5];

        Circle circle = new Circle("circle", 5);
        Rectangle rectangle = new Rectangle("rectangle", 5, 10);
        Square square = new Square("square", 6);
        Parallelogram parallelogram = new Parallelogram("parallelogram", 20, 13, 12);
        RegularTrapezoid trapezoid = new RegularTrapezoid("trapezoid", 3, 10, 5);

        figura[0] = circle;
        figura[1] = rectangle;
        figura[2] = square;
        figura[3] = parallelogram;
        figura[4] = trapezoid;

        for (FiguraGeometrica figuraGeometrica : figura) {

            System.out.println("Nombre: " + figuraGeometrica.name);
            System.out.println("Area: " + figuraGeometrica.GetArea());
            System.out.println("Perimetro: " + figuraGeometrica.GetPerimeter());
            System.out.println();
        }
    }
}
