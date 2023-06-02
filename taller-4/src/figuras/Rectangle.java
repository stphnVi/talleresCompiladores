package figuras;

public class Rectangle extends FiguraGeometrica {
    private Integer width;
    private Integer large;

    // constructor

    public Rectangle(String name, Integer width, Integer large) {

        super(name);
        this.width = width;
        this.large = large;
    }

    public float GetPerimeter() {
        return (int) ((width * 2) + (large * 2));

    }

    public float GetArea() {
        return (int) (width * large);
    }

}
