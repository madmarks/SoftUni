'''

Задача: 1. Ограничете дължината на текст

Напишете програма, която взима текст от потребителя използвайки input() и
ограничава текста до 10 символа и добавя ... накрая

Пример:

 Вход: Python3 can do so much, but I have to learn how
Изход: Python3 ca...

'''

str_in = input('Вход: ')

print('Изход: ', end='')
if len(str_in) <= 10:
    print(str_in)
else:
    print(str_in[0:10] + '...')
