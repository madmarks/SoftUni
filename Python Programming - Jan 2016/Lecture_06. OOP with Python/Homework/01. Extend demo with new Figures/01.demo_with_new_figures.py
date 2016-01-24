'''

Задача: 1. Разширете програмата с възможност за нови фигури

Разширете програмта така, че да може да рисува и други фигури:

    правоъгълник - с допълнителни параметри "width" & "height"
    pie - сектор от кръг - с допълнителни параметри "radius" & "arg_degrees"
    правилен n-ъгълник - с допълнителни параметри "radius" & "num_sides"

Входен файл от демонстрацията:

[
    {"type": "square", "center_x": 0, "center_y": 0, "side": 2, "color": "black"},
    {"type": "square", "center_x": 0, "center_y": 0, "side": 100, "color": "red"},
    {"type": "square", "center_x": 0, "center_y": 0, "side": 200, "color": "blue"},
    {"type": "circle", "center_x": 0, "center_y": 0, "radius": 50, "color": "blue"},
    {"type": "circle", "center_x": 0, "center_y": 0, "radius": 100, "color": "red"}
]

'''

import sys
import json
import turtle

from figures.square import Square
from figures.circle import Circle
from figures.rectangle import Rectangle
from figures.pie import Pie
from figures.polygon import Polygon

FIGURE_TYPES = {
    "circle": Circle,
    "square": Square,
    "rectangle": Rectangle,
    "pie": Pie,
    "polygon": Polygon
}


def main():
    if len(sys.argv) < 2:
        print("Usage: {} input-file.json".format(sys.argv[0]))
        return 1

    try:
        input_data = load_input_data(sys.argv[1])
        figures = create_figures(input_data)
        draw_figures(figures)
    except Exception as e:
        print("Invalid input file provided! Error: " + str(e))
        return 2


def load_input_data(input_filename):
    with open(input_filename) as f:
        input_data = json.load(f)
        return input_data


def create_figures(input_data: dict):
    result = []
    for figure_info in input_data:
        figure_type = figure_info['type']
        if figure_type in FIGURE_TYPES:
            figure_class = FIGURE_TYPES[figure_type]
            result.append(figure_class(**figure_info))
        else:
            raise ValueError("Unsupported figure")
    return result


def draw_figures(figures):
    t = turtle.Turtle()
    t.speed('normal')
    for figure in figures:
        figure.draw(t)
    t.screen.exitonclick()

if __name__ == "__main__":
    sys.exit(main())
