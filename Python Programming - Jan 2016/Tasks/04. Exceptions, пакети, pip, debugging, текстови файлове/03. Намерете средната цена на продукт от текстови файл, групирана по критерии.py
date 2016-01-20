'''

Задача: 3. Намерете средната цена на продукт от текстови файл, групирана по критерии


Използвайки кода си от предишната задача, и използвайки същите файлове, намерете средната
цена от всички продукти в каталога, групирани по пол и възраст. Използвайте колоната за пол и
възраст която има една от следните стойности:

    - infant
    - kid
    - men
    - unisex
    - woman

catalog_sample.csv
catalog_full.csv

Структурата на CSV файловете е следната:

    - каталожен номер
    - име на продукта
    - цветове на продукта. Ако са повече от един са разделени с /
    - за какъв вид активност е предназначен артикула
    - каква е групата на артикула
    - за кой пол и възраст е предназначен артикула
    - цена

Разделителят на данните е , (запетая), а десеттичният знак е . (точка).

'''

# with open('catalog_sample.csv') as f:
with open('catalog_full.csv') as f:
    avg_price_by_gender_age = {
        'infant': {'count': 0, 'sum': 0.0},
        'kid': {'count': 0, 'sum': 0.0},
        'men': {'count': 0, 'sum': 0.0},
        'unisex': {'count': 0, 'sum': 0.0},
        'woman': {'count': 0, 'sum': 0.0}
    }
    for line in f:
        idx_of_last_comma = line.rfind(',')
        if idx_of_last_comma == -1:
            continue

        idx_of_comma_before_the_last_comma = line[:idx_of_last_comma].rfind(',')
        if idx_of_comma_before_the_last_comma == -1:
            continue

        gender_age = line[idx_of_comma_before_the_last_comma + 1:idx_of_last_comma].lower()

        try:
            price = float(line[idx_of_last_comma + 1:-1])
        except ValueError as e:
            print('ValueError: ', e.args)
            continue

        avg_price_by_gender_age[gender_age]['count'] += 1
        avg_price_by_gender_age[gender_age]['sum'] += price

for key, val in avg_price_by_gender_age.items():
    if val['count'] > 0:
        print('Средна цена на "{0}" продукт: {1:.2f}'.format(
            key.capitalize(),
            val['sum'] / val['count'])
        )
