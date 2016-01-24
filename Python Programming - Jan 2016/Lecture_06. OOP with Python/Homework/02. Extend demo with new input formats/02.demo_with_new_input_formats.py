'''

Задача: 2. Разширете програмата от предишната задача така, че да може да чете различни входни формати

Програмата от предишната задача зарежда данните от JSON файл.

По подобие на метода, който използвахме за чертане на различни фигури, разширете програмата така,
че да може да чете входните си данни от файлове с различни формати - както JSON, така и YAML.

За да решите задачата, е необходимо:
    - Да създадете базов клас - например Loader, който:◦да приема име на файл в конструктора си.
    - да има метод load(), който за този клас е празен; припомняме, че реализацията ще бъде в наследниците,
      и ще бъде специфична за съответните формати



'''

import os
import sys
import turtle

from figures.square import Square
from figures.circle import Circle
from figures.rectangle import Rectangle
from figures.pie import Pie
from figures.polygon import Polygon

from figures.loaders.json_loader import JSONLoader
from figures.loaders.yaml_loader import YAMLLoader

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
    # os.path.splitext връща tuple с 2 стойности - име и разширение на файла
    filename, extension = os.path.splitext(input_filename)
    loader = None
    if extension == '.json':
        loader = JSONLoader(input_filename)
    elif extension == '.yaml':
        loader = YAMLLoader(input_filename)

    if loader is not None:
        return loader.load()
    else:
        raise ValueError("Unsupported file format: {}".format(extension))


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
