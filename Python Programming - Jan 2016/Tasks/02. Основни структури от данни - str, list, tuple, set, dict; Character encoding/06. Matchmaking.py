'''

Задача: 6. Matchmaking

Да си направим програмка за запознанства.

В едно list-че сме си съчинили малко информация за момиченца и момченца.
От данните, програмата трябва да изведе резултати кои хора биха си паснали,
съгласно следните правила:

    - момиченце с момченце; ако сте по-свободомислещи, можете да комбинирате и
      момченце с момченце, но все пак да има някакво правило :о);
    - трябва да имат поне един общ интерес;
    - търсим максимален брой съвпадения в интересите
    - момиченцето и момченцето от избраната двойка да не участват при търсенето на
      следваща подходяща двойка

Примерен резултат:

Мария и Георги - общи интереси: плуване, танци
. . .

'''

people = [
    {
        'name': "Мария",
        'interests': ['пътуване', 'танци', 'плуване', 'кино'],
        'gender': "female",
    },
    {
        'name': "Диана",
        'interests': ['мода', 'спортна стрелба', 'четене', 'скандинавска поезия'],
        'gender': "female",
    },
    {
        'name': "Дарина",
        'interests': ['танци', 'покер', 'история', 'софтуер'],
        'gender': "female",
    },
    {
        'name': "Лилия",
        'interests': ['покер', 'автомобили', 'танци', 'кино'],
        'gender': "female",
    },
    {
        'name': "Галя",
        'interests': ['пътуване', 'автомобили', 'плуване', 'баскетбол'],
        'gender': "female",
    },
    {
        'name': "Валерия",
        'interests': ['плуване', 'покер', 'наука', 'скандинавска поезия'],
        'gender': "female",
    },
    {
        'name': "Ина",
        'interests': ['кино', 'лов със соколи', 'пътуване', 'мода'],
        'gender': "female",
    },
    {
        'name': "Кирил",
        'interests': ['баскетбол', 'автомобили', 'кино', 'наука'],
        'gender': "male",
    },
    {
        'name': "Георги",
        'interests': ['автомобили', 'футбол', 'плуване', 'танци'],
        'gender': "male",
    },
    {
        'name': "Андрей",
        'interests': ['футбол', 'скандинавска поезия', 'история', 'танци'],
        'gender': "male",
    },
    {
        'name': "Емил",
        'interests': ['летене', 'баскетбол', 'софтуер', 'наука'],
        'gender': "male",
    },
    {
        'name': "Димитър",
        'interests': ['футбол', 'лов със соколи', 'автомобили', 'баскетбол'],
        'gender': "male",
    },
    {
        'name': "Петър",
        'interests': ['пътуване', 'покер', 'баскетбол', 'лов със соколи'],
        'gender': "male",
    },
    {
        'name': "Калоян",
        'interests': ['история', 'покер', 'пътуване', 'автомобили'],
        'gender': "male",
    },
]

boys = [person for person in people if person['gender'] == 'male']
girls = [person for person in people if person['gender'] == 'female']

while True:
    best_joint_interests = set()
    best_boy = set()
    best_girl = set()

    for boy in boys:
        for girl in girls:
            joint_interests = set(boy['interests']) & set(girl['interests'])

            if len(joint_interests) > len(best_joint_interests):
                best_joint_interests = joint_interests
                best_boy = boy
                best_girl = girl

    if len(best_joint_interests) == 0:
        break
    else:
        print('{} и {} - общи интереси: '.format(best_boy['name'], best_girl['name']), end='')
        print('{}'.format(', '.join(best_joint_interests)))
        boys.remove(best_boy)
        girls.remove(best_girl)
