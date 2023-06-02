package figuras;

public class FiguraGeometrica {
    // atributo
    private String name;

    // constructor
    public FiguraGeometrica(String name) {
        this.name = name;
        Circle circle = new Circle("circle", 5);
        Rectangle rectangle = new Rectangle("rectangle", 5, 10);
        Square square = new Square("square", 6);
        Parallelogram parallelogram = new Parallelogram("parallelogram", 20, 13, 12);
        RegularTrapezoid trapezoid = new RegularTrapezoid("trapezoid", 3, 10, 5);
    }

    public float GetPerimeter() {
        return 0.0f;

    }

    public float GetArea() {
        return 0.0f;
    }
}
