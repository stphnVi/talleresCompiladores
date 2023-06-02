package figuras;

public class Circle extends FiguraGeometrica {
    private Integer radious;

    public Circle(String name, Integer radious) {

        super(name);
        this.radious = radious;
    }

    public float GetPerimeter() {
        return (float) (2 * Math.PI * radious);

    }

    public float GetArea() {
        return (float) (Math.PI * Math.pow(radious, 2));
    }

}
