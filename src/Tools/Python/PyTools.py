def parse(_fileway, _parameter):
    #извлечение данных из файла в строку
    file = open(_fileway, 'r')
    fileData = file.read()
    file.close()

    #параметр не найден - выход
    if not _parameter in fileData:
        return False

    #вывод результата
    begin = fileData.index('=', fileData.index(_parameter))
    end   = fileData.index(';', begin)
    return ''.join(fileData[begin + 1 : end + 1].split())

def dataReplace(_fileway, _what, _newValue):
    file = open(_fileway, 'r')
    fileData = file.read()
    file.close()

    if not _what in fileData:
        return False

    result = fileData.replace(_what, _newValue, 1)

    file = open(_fileway, 'w')
    file.write(result)
    file.close()
    return True