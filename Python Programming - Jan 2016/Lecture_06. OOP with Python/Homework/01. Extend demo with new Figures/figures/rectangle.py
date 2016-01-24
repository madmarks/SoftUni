from .base import Figure


class Rectangle(Figure):

    def __init__(self, width, height, **kwargs):
        super().__init__(**kwargs)
        self.width = width
        self.height = height

    def draw(self, turtle):
        half_width = self.width / 2
        half_height = self.height / 2
        left = self.center_x - half_width
        top = self.center_y + half_height

        turtle.penup()
        turtle.goto(left, top)
        turtle.pendown()
        turtle.color(self.color)
        turtle.setheading(270)  # point the turtle down
        for _ in range(2):
            turtle.forward(self.height)
            turtle.left(90)
            turtle.forward(self.width)
            turtle.left(90)
