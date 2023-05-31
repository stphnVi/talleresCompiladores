package figuras;

public class Parallelogram extends FiguraGeometrica {

    private Integer base;
    private Integer side;
    private Integer height;

    // constructor

    public Parallelogram(String name, Integer base, Integer side, Integer height) {
        super(name);
        this.height = height;
        this.base = base;
        this.side = side;
    }

    public float GetPerimeter() {
        return 0.0f;

    }

    public float GetArea() {
        return 0.0f;
    }

}
