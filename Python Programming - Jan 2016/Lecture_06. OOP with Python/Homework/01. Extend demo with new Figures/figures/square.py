from .base import Figure


class Square(Figure):

    def __init__(self, side, **kwargs):
        super().__init__(**kwargs)
        self.side = side

    def draw(self, turtle):
        half_side = self.side / 2
        left = self.center_x - half_side
        top = self.center_y + half_side

        turtle.penup()
        turtle.goto(left, top)
        turtle.pendown()
        turtle.color(self.color)
        turtle.setheading(270)  # point the turtle down
        for _ in range(4):
            turtle.forward(self.side)
            turtle.left(90)
