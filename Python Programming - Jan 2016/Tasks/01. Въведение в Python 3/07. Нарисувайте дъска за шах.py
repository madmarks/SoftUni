'''

Задача: 7. Нарисувайте дъска за шах

Използвайки цикли, условни оператори и костенурката нарисувайте дъска за шах с черни и бели квадрати.
Дъската трябва да е с размери 8 на 8 квадрата.

Можете да изполвате следния примерен код, който рисува равностранни триъгълници един до друг,
като редува цвета им:

import turtle
side=40
for i in range(8):
    if i % 2==0:
        turtle.begin_fill()
    turtle.forward(side)
    turtle.left(120)
    turtle.forward(side)
    turtle.left(120)
    turtle.forward(side)
    turtle.left(120)
    turtle.end_fill()
    turtle.forward(side)
turtle.exitonclick()

За да попълните дадена "фигура" използвайте:

turtle.begin_fill() # оказва начало на регион, който ще бъде запълнен
... кода който рисува фигурата
turtle.end_fill() # край на региона, който ще трябва да се запълни

За да спрете автоматичното затваряне на прозореца на костенурката след края на изпълнението сложете
следния код в края на вашата програма:

turtle.exitonclick()

За да преместите костенурката на нова позиция без да чертаете линии използвайте:

turtle.penup() # вдига костенурката от платното за рисуване
turtle.goto(x,y) # x и y са новите координати
turtle.pendown() # поставя костенурката на платното за рисуване

'''

import turtle
t = turtle.Turtle()
t.speed('fastest')

t.penup()
t.goto(-150, 150)
t.pendown()

side = 40
for row in range(8):
    for col in range(8):
        if (row + col) % 2 == 0:
            t.begin_fill()

        for k in range(4):
            t.forward(side)
            t.left(90)

        if (row + col) % 2 == 0:
            t.end_fill()

        t.forward(side)

    if row != 7:
        t.left(180)
        t.forward(8 * side)
        t.left(90)
        t.forward(side)
        t.left(90)

t.screen.exitonclick()
