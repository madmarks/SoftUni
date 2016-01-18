'''

Задача: 8. Изчисляване лице на триъгълник по дължините на страните му

Използвайте Хероновата формула: S=SQRT(p(p-a)(p-b)(p-c))

'''

import math

print('Въведете дължините на страните на триъгълника!')
a = float(input('a = '))
b = float(input('b = '))
c = float(input('c = '))

if a + b <= c or b + c <= a or c + a <= b:
    print('Грешни данни. Това не е триъгълник.')
else:
    p = (a + b + c)/2
    s = math.sqrt(p * (p - a) * (p - b) * (p - c))
    print('Лицето на триъгълника е = {0:.3f}'.format(s))
