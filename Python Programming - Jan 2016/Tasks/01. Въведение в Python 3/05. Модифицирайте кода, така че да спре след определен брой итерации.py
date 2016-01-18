'''

Задача: 5. Модифицирайте кода, така че да спре след определен брой итерации

Модифицирайте този код, така че да спре да рисува след определен брой итерации:

import turtle
g = 134
l = 120
while True:
    turtle.left(g)
    turtle.forward(l)

Броят на итерациите трябва да се въвежда при стартиране на програмата с input()

'''

import turtle
t = turtle.Turtle()
t.speed('fast')

g = 134
l = 120

n = int(input('Number of iterations: '))

i = 0
while i < n:
    t.left(g)
    t.forward(l)
    i += 1

turtle.done()
