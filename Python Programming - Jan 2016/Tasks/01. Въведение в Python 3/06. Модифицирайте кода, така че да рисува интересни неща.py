'''

Задача: 6. Модифицирайте кода, така че да рисува интересни неща

Използвайки цикли, аритметика, условни и логически оператори, накарайте костенурката да рисува "интересни неща".

Пример:

import turtle
i = 10
while True:
    turtle.left(i % 48)
    turtle.forward(10)
    i+=1

Експерементирайте без ограничения докато не получите интересен резултат - по възможност без вулгарни изображения :)

'''

import turtle
t = turtle.Turtle()
t.speed('fastest')

break_loop = False


def say_bye(x, y):
    print('Position: (x={0}, y={1})'.format(x, y))
    print('Bye')
    global break_loop
    break_loop = not break_loop
    if break_loop is False:
        draw_eye()


def draw_eye():
    length = 150
    angle = 90
    while True:
        t.color('#3F7FFF')
        t.left(angle)
        t.forward(length)
        t.color('#D5FF6D')
        t.left(angle)
        t.forward(length)
        t.left(angle)
        t.forward(length)
        t.color('#3F7FFF')
        t.left(angle)
        t.forward(length)
        t.left(1)
        if break_loop is True:
            break

t.screen.onscreenclick(say_bye)
draw_eye()

turtle.done()
