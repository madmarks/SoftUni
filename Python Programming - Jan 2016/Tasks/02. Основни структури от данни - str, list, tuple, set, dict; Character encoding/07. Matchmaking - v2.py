'''

Задача: 7. Matchmaking - v2

Да разширим предходната задача.

Вече имаме малко повече информация за хората, и искаме да прибавим
допълнителни условия към matchmaking-a.

Освен условията досега:

    - момиченце с момченце; ако сте по-свободомислещи, можете да комбинирате и
      момченце с момченце, но все пак да има някакво правило :о);
    - трябва да имат поне един общ интерес;
    - търсим максимален брой съвпадения в интересите
    - момиченцето и момченцето от избраната двойка да не участват при търсенето на
      следваща подходяща двойка

ще имаме и допълнителни условия:

    - разликата в годините не трябва да бъде по-голяма от 6;
    - не бива да комбинирате хора с бившите им партньори - някакси ще се получи неловко :о)

Резултатът от програмата също ще трябва да заизглежда малко по-добре:

Мария (24) и Калоян (29) ; общи интереси: пътуване, кино
. . .

'''

people = [
    {
        'name': "Мария",
        'interests': ['пътуване', 'танци', 'плуване', 'кино'],
        'age': 24,
        'gender': "female",
        "ex": ["Кирил", "Петър"],
    },
    {
        'name': "Диана",
        'interests': ['мода', 'спортна стрелба', 'четене', 'скандинавска поезия'],
        'age': 21,
        'gender': "female",
        "ex": [],
    },
    {
        'name': "Дарина",
        'interests': ['танци', 'покер', 'история', 'софтуер'],
        'age': 34,
        'gender': "female",
        "ex": ["Борис"],
    },
    {
        'name': "Лилия",
        'interests': ['покер', 'автомобили', 'танци', 'кино'],
        'age': 36,
        'gender': "female",
        "ex": [],
    },
    {
        'name': "Галя",
        'interests': ['пътуване', 'автомобили', 'плуване', 'баскетбол'],
        'age': 18,
        'gender': "female",
        "ex": ['Димитър'],
    },
    {
        'name': "Валерия",
        'interests': ['плуване', 'покер', 'наука', 'скандинавска поезия'],
        'age': 27,
        'gender': "female",
        "ex": [],
    },
    {
        'name': "Ина",
        'interests': ['кино', 'лов със соколи', 'пътуване', 'мода'],
        'age': 20,
        'gender': "female",
        "ex": [],
    },
    {
        'name': "Кирил",
        'interests': ['баскетбол', 'автомобили', 'кино', 'наука'],
        'age': 19,
        'gender': "male",
        'ex': ["Мария"],
    },
    {
        'name': "Георги",
        'interests': ['автомобили', 'футбол', 'плуване', 'танци'],
        'age': 32,
        'gender': "male",
        'ex': [],
    },
    {
        'name': "Андрей",
        'interests': ['футбол', 'скандинавска поезия', 'история', 'танци'],
        'age': 26,
        'gender': "male",
        'ex': ["Мария"],
    },
    {
        'name': "Емил",
        'interests': ['летене', 'баскетбол', 'софтуер', 'наука'],
        'age': 34,
        'gender': "male",
        'ex': ['Дарина'],
    },
    {
        'name': "Димитър",
        'interests': ['футбол', 'лов със соколи', 'автомобили', 'баскетбол'],
        'age': 22,
        'gender': "male",
        'ex': ['Галя'],
    },
    {
        'name': "Петър",
        'interests': ['пътуване', 'покер', 'баскетбол', 'лов със соколи'],
        'age': 23,
        'gender': "male",
        'ex': ["Мария"],
    },
    {
        'name': "Калоян",
        'interests': ['кино', 'покер', 'пътуване', 'автомобили'],
        'age': 29,
        'gender': "male",
        'ex': [],
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
            if abs(boy['age'] - girl['age']) > 6:
                continue
            if boy['name'] in girl['ex'] or girl['name'] in boy['ex']:
                continue

            joint_interests = set(boy['interests']) & set(girl['interests'])

            if len(joint_interests) > len(best_joint_interests):
                best_joint_interests = joint_interests
                best_boy = boy
                best_girl = girl

    if len(best_joint_interests) == 0:
        break
    else:
        print('{} ({}) и '.format(best_girl['name'], best_girl['age']), end='')
        print('{} ({}) ; '.format(best_boy['name'], best_boy['age']), end='')
        print('общи интереси: {}'.format(', '.join(best_joint_interests)))
        boys.remove(best_boy)
        girls.remove(best_girl)
