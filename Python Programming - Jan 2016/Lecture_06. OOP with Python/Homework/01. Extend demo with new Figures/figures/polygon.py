from .circle import Circle


class Polygon(Circle):

    def __init__(self, radius, num_sides, **kwargs):
        super().__init__(radius, **kwargs)
        self.steps = num_sides

    def draw(self, turtle, **kwargs):
        super().draw(turtle, steps=self.steps)
