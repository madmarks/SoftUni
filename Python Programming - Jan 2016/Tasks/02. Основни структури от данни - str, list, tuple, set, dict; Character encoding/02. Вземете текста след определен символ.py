'''

Задача: 2. Вземете текста след определен символ

Напишете код, който взима два текста от потребителя, използвайки input(), след
което покажете първия текст, но само частта която се намира след втория текст.

Пример:

Първи текст: This is soo difficult, I prefer playing WoW
Втори текст: soo
   Резултат: difficult, I prefer playing WoW

'''

str_1 = input('Първи текст: ')
str_2 = input('Втори текст: ')

# print('Резултат: ')
# if str_1.find(str_2) != -1:
#     print('{0}'.format(str_1[str_1.index(str_2) + len(str_2):]))

print('Резултат: {0}'.format(str_1.partition(str_2)[2]))
