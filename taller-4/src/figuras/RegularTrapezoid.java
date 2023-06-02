package figuras;

public class RegularTrapezoid extends FiguraGeometrica {

    private Integer base1;
    private Integer base2;
    private Integer height;
    private float side;

    // constructor
    public RegularTrapezoid(String name, Integer base1, Integer base2, Integer height) {
        super(name);
        this.base1 = base1;
        this.base2 = base2;
        this.height = height;
        this.side = (float) Math.sqrt(Math.pow(base1, 2) + Math.pow(base2, 2));
    }

    public float GetPerimeter() {
        return (float) (base1 + base2 + side * 2);

    }

    public float GetArea() {
        return (float) ((height / 2) * (base1 + base2));
    }

}
