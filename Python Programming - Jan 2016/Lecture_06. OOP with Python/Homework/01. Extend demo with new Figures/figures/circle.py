from .base import Figure


class Circle(Figure):

    def __init__(self, radius, extent=360, **kwargs):
        super().__init__(**kwargs)
        self.radius = radius
        self.extent = extent

    def draw(self, turtle, **kwargs):
        turtle.penup()
        # From docs: The center is radius units left of the turtle;
        turtle.goto(self.center_x, self.center_y - self.radius)
        turtle.pendown()
        turtle.color(self.color)
        turtle.setheading(0)  # point the turtle right
        turtle.circle(self.radius, **kwargs)
