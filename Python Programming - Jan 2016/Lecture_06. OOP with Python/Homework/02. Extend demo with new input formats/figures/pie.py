from .circle import Circle


class Pie(Circle):

    def __init__(self, radius, arg_degrees, **kwargs):
        super().__init__(radius, **kwargs)
        self.extent = arg_degrees

    def draw(self, turtle, **kwargs):
        turtle.penup()
        turtle.goto(self.center_x, self.center_y)
        turtle.pendown()
        turtle.begin_fill()
        turtle.color(self.color)
        turtle.setheading(0)  # point the turtle right
        turtle.goto(self.center_x, self.center_y - self.radius)
        super().draw(turtle, extent=self.extent)
        turtle.end_fill()
