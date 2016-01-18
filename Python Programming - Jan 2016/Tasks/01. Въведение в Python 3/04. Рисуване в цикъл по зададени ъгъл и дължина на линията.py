'''

Задача: 4. Рисуване в цикъл по зададени ъгъл и дължина на линията

Направете програма, която по зададени ъгъл и дължина да рисува линии с turtle в безкраен цикъл,
като всеки път завърта костенурката на подадения брой градуси, и рисува права линия със зададената дължина.

Ъгълът (в градуси) и дължината трябва да се въвеждат от конзолата при стартиране на програмата.
За въвеждане от конзолата използвайте функцията input().

Turtle можете да използвате така:

import turtle

length = 100
turtle.left(length)
turtle.forward(200)


Полезни операции с turtle:

    - turtle.forward(length) - чертае права линия напред с дължина length като премества и костенурката
    - turtle.backward(length) - чертае права линия назад с дължина length като премества и костенурката
    - turtle.left(degrees) - завърта костенурката наляво указания брой градуси.
    - turtle.right(degrees) - завърта костенурката надясно указания брой градуси.
    - turtle.color('red') - сменя цвета на чертане на костенурката; всички рисувания след това ще
      използват този цвят; За цветове можете да използвате 'black', 'red', 'green', 'blue', 'orange',
      'yellow', 'purple', и всички именовани цветове от HTML/CSS; също така можете да използвате и
      HTML/CSS цветове, напр: '#BA3290'.
    - turtle.speed('fastest') - задава скоростта, с която костенурката рисува;
      можете да използвате 'fastest', ''fast'', 'normal', 'slow' и 'slowest'.

'''

import turtle
t = turtle.Turtle()
t.speed('fastest')

break_loop = False


def say_bye(x, y):
    print('Position: (x={0}, y={1})'.format(x, y))
    print('Bye')
    global break_loop
    break_loop = True

t.screen.onscreenclick(say_bye)

angle = float(input('Въведете ъгъл: '))
length = float(input('Въведете дължина: '))

while True:
    t.forward(length)
    t.right(angle)
    if break_loop is True:
        break

turtle.done()
