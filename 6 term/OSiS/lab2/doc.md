Варианты работы скрипта:

    1. Отправить запись:
        1.1. В качестве аргумента передан только id пользователя -- для ввода загружаемого текста используется stdin (cntrl+D)
        1.2. В качестве аргумента передан id пользователя и абсолютный путь до файла -- отправляется текст выбранного файла
        1.3. В качестве аргумента передан id пользователя и текст, не являющийся путем до файла -- отправляется переданный текст
    2. Получить запись:
        2.1. В качестве аргумента передан только id записи -- запись выводится в консоль
        2.2. В качестве аргумента переданы id записи и имя файла -- создается (при его отсутсвии) файл, запись переносится туда

Примеры запуска:

    На отправку:
        1. bash lab2.sh post *user_id*
        2. bash lab2.sh post *user_id* ~/test.txt
        3. bash lab2.sh post *user_id* test_text

    На получение:
        1. bash lab2.sh read *file_id*
        2. bash lab2.sh read *file_id* text.txt
