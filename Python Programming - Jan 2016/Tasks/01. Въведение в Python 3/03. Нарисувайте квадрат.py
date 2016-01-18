'''

Задача: 3. Нарисувайте квадрат

С помощта на turtle нарисувайте квадрат, като дължината на страна се въвежда от конзолата с input().

    - turtle.forward(length) - чертае права линия напред с дължина length като премества и костенурката
    - turtle.backward(length) - чертае права линия назад с дължина length като премества и костенурката
    - turtle.left(degrees) - завърта костенурката наляво указания брой градуси.
    - turtle.right(degrees) - завърта костенурката надясно указания брой градуси.
    - turtle.color('red') - сменя цвета на чертане на костенурката; всички рисувания след това ще използват
      този цвят; За цветове можете да използвате 'black', 'red', 'green', 'blue', 'orange', 'yellow', 'purple',
      и всички именовани цветове от HTML/CSS; също така можете да използвате и HTML/CSS цветове, напр: '#BA3290'.
    - turtle.speed('fastest') - задава скоростта, с която костенурката рисува;
      можете да използвате 'fastest', ''fast'', 'normal', 'slow' и 'slowest'.

'''

import turtle
t = turtle.Turtle()
t.speed('slowest')

length = float(input('Въведете дължината на страната на квадрата: '))

for i in range(4):
    t.forward(length)
    t.right(90)

turtle.done()
# t.screen.exitonclick()
