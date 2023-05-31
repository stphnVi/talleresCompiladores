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
        return 0.0f;

    }

    public float GetArea() {
        return 0.0f;
    }

}
