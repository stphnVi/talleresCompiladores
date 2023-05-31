package figuras;

public class RegularTrapezoid extends FiguraGeometrica {

    private Integer base1;
    private Integer base2;
    private Integer height;
    private Integer side;

    // constructor
    public RegularTrapezoid(String name, Integer base1, Integer base2, Integer height, Integer side) {
        super(name);
        this.base1 = base1;
        this.base2 = base2;
        this.height = height;
        this.side = side;
    }

    public float GetPerimeter() {
        return 0.0f;

    }

    public float GetArea() {
        return 0.0f;
    }

}
