package figuras;

public class Square extends FiguraGeometrica {
    // atributos
    private Integer side;

    // constructor
    public Square(String name, Integer side) {
        super(name);
        this.side = side;
    }

    public float GetPerimeter() {
        return (int) (4 * side);

    }

    public float GetArea() {
        return (int) (side * side);
    }

}
