package figuras;

public class Circle extends FiguraGeometrica {
    private Integer radious;

    public Circle(String name, Integer radious) {

        super(name);
        this.radious = radious;
    }

    public float GetPerimeter() {
        return 0.0f;

    }

    public float GetArea() {
        return 0.0f;
    }

}
