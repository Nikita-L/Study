# -*- coding: utf-8 -*-

import hdr # Импортируемые библиотеки

region_names = ['Винница', 'Волынь', 'Днепропетровск', 'Донецк', 'Житомир', 'Закарпатье', 'Запорожье', 'Ивано-Франковск', 'Киев', 'Киевская область', 'Кировоград', 'Крым', 'Луганск', 'Львов', 'Николаев', 'Одесса', 'Полтава', 'Ровно', 'Севастополь', 'Сумы', 'Тернополь', 'Харьков', 'Херсон', 'Хмельницкий', 'Черкасы', 'Чернигов', 'Черновцы']

def regionName(index): # Вернуть название области на русском
    if index == 1:
        return 'Черкасы'
    elif index == 2:
        return 'Чернигов'
    elif index == 3:
        return 'Черновцы'
    elif index == 4:
        return 'Крым'
    elif index == 5:
        return 'Днепропетровск'
    elif index == 6:
        return 'Донецк'
    elif index == 7:
        return 'Ивано-Франковск'
    elif index == 8:
        return 'Харьков'
    elif index == 9:
        return 'Херсон'
    elif index == 10:
        return 'Хмельницкий'
    elif index == 11:
        return 'Киев'
    elif index == 12:
        return 'Киевская область'
    elif index == 13:
        return 'Кировоград'
    elif index == 14:
        return 'Луганск'
    elif index == 15:
        return 'Львов'
    elif index == 16:
        return 'Николаев'
    elif index == 17:
        return 'Одесса'
    elif index == 18:
        return 'Полтава'
    elif index == 19:
        return 'Ровно'
    elif index == 20:
        return 'Севастополь'
    elif index == 21:
        return 'Сумы'
    elif index == 22:
        return 'Тернополь'
    elif index == 23:
        return 'Закарпатье'
    elif index == 24:
        return 'Винница'
    elif index == 25:
        return 'Волынь'
    elif index == 26:
        return 'Запорожье'
    elif index == 27:
        return 'Житомир'

def download(i): # Загрузка одного файла по номру в папку data
    index = str(i).zfill(2)
    current_name = regionName(i) # Название области
    current_file = hdr.glob.glob('data/clean/?? ' + current_name + ' ????-??-?? ??:??.csv')
    if (current_file): # Если есть "очищенный" файл для этой области, он будет удален
        hdr.os.remove(current_file[0])
    hdr.ur.urlretrieve('http://www.star.nesdis.noaa.gov/smcd/emb/vci/gvix/G04/ts_L1/ByProvince/Mean/L1_Mean_UKR.R' + index + '.txt', 'data/raw/' + index + ' ' + current_name + ' ' + hdr.strftime("%Y-%m-%d %H:%M", hdr.localtime()) + '.csv')

def refresh(button_value = 0): # Обновить файлы
    inet_access = inetConnection()
    if (inet_access): # Кнопка работает только при наличии доступа к интернет
        hdr.clear_output() # Убрать output выполненых команд
        hdr.os.chdir("data/raw")
        filelist = hdr.glob.glob("?? * ????-??-?? ??:??.csv")
        for f in filelist:
            hdr.os.remove(f)
        hdr.os.chdir("../..")
        for i in range(1, 28):
            download(i);
    else:
        print ("Нет доступа к сети интернет")

def inetConnection(): # Проверка подключение к сети интернет
    try :
        hdr.ur.urlopen("https://www.google.com")
        return True
    except hdr.ue.URLError as err:
        return False

def findFile(pattern, path): # Найти файл, возвращаеться название файла
    result = ''
    for root, dirs, files in hdr.os.walk(path):
        for name in files:
            if hdr.fnmatch.fnmatch(name, pattern):
                result = result + hdr.os.path.join(root, name)
    return result

def checkData(data_type): # Проеврка есть ли все данные
    if (data_type == 'clean'):
        path = 'data/clean'
    elif (data_type == 'raw'):
        path = 'data/raw'
    for i in range(1, 28):
        if not findFile('?? ' + regionName(i) + ' ????-??-?? ??:??.csv', path):
            return False
    return True

def makeFig(df, data, region, data_from, data_to): # Создать график
    data_from = int(data_from)
    data_to = int(data_to)
    x=df.index
    y=df[data]
    fig =  hdr.plt.figure()
    fig.suptitle(region, fontsize=20)
    axes = fig.add_subplot(111)
    weeks_total = len(df.index)
    weeks_2016 = len(df.loc[df['Год'] == 2016])
    hdr.plt.xticks( hdr.np.linspace(0, weeks_total-weeks_2016, 0), hdr.np.linspace(data_from, data_to, 0).astype(int))
    hdr.plt.xlabel("Недели") # Года
    hdr.plt.ylabel(data)
    axes.plot(x,y)
    return fig

def makeDF(current_name, data, data_from, data_to, freq_from, freq_to): # Создать датафрейм
    data_from = int(data_from)
    data_to = int(data_to)
    freq_from = int(freq_from)
    freq_to = int(freq_to)
    current_name = findFile('?? ' + current_name + ' ????-??-?? ??:??.csv', 'data/clean')
    df = hdr.pd.read_csv(current_name, header=0)
    if (data_from == data_to):
        if (freq_from == freq_to):
            df = df.loc[(df["Год"] == data_to) & (df["Неделя"] == freq_to)]
        else:
            df = df.loc[(df["Год"] == data_to) & (df["Неделя"] >= freq_from) & (df["Неделя"] <= freq_to)]
    else:
        df = df.loc[(df["Год"] > data_from) & (df["Год"] < data_to) | ((df["Год"] == data_from) & (df["Неделя"] >= freq_from)) | ((df["Год"] == data_to) & (df["Неделя"] <= freq_to))]
    return df

def changeIndex(button_value = 0): # Изменить индексы "чистых" файлов
    data_ok = checkData("clean") # Проверка наличия данных
    if (data_ok):
        j = 0
        for i in region_names:
            j = j + 1
            current_file = findFile ('?? ' + i + ' ????-??-?? ??:??.csv', 'data/clean')
            new_current_file = 'data/clean/' + str(j).zfill(2) + current_file[13:]
            hdr.os.rename(current_file, new_current_file)
        hdr.clear_output() # Убрать output выполненых команд
    else:
        print("Нет полных данных")

def cleanRow(current_file): # "Отчистить" строку таблицы
    with open(current_file, "r") as f_in:
        with open('data/clean' + current_file[8:], 'a+') as f_out:
            writer = hdr.csv.writer(f_out)
            incsv = hdr.csv.reader(f_in)
            for row in hdr.islice(incsv, 1, None): # Пропустить первую строку
                if (row[0][0] == 'y'):
                    current_title = ['Год', 'Неделя', 'SMN', 'SMT', 'VCI', 'TCI', 'VHI', 'Процент площади где VHI < 15%', 'Процент площади где VHI < 35%']
                    writer.writerow(current_title)
                elif (float(row[2]) < 0 or float(row[3]) < 0 or float(row[4]) < 0 or float(row[5]) < 0 or float(row[6]) < 0 or float(row[7]) < 0 or float(row[8]) < 0): pass
                else:
                    writer.writerow(row)

def recleanData(button_value = 0): # "Отчистить" все данные еще раз
    data_ok = checkData("raw") # Проверка наличия данных
    if (data_ok):
        hdr.os.chdir("data/clean")
        filelist = hdr.glob.glob("?? * ????-??-?? ??:??.csv")
        for f in filelist:
            hdr.os.remove(f)
        hdr.os.chdir("../..")
        for i in range(1, 28):
            current_file = findFile('?? ' + regionName(i) + ' ????-??-?? ??:??.csv', 'data/raw')
            cleanRow(current_file)
    else:
        print("Нет полных данных")

def makeExtVHI(df, data): # Отобразить максимальное/минимальное значение
    maxData = df[data].idxmax()
    minData = df[data].idxmin()
    df1 = df.loc[[maxData]]
    df2 = df.loc[[minData]]
    return df1.append(df2)

def areaShow (region, percent, colomn): # Показать датафрейм в отфильтрованном виде, создать файл с отфильтрованными данными
    df = makeDF(region) # Создать датафрейм
    df = df.loc[(df[colomn] > percent)]
    if (df.empty):
        print("Нет соответствующих данных")
    else:
        if (colomn == "Процент площади где VHI < 15%"):
            VHI_percent = "15%"
        else:
            VHI_percent = "35%"
        source_path = findFile('?? ' + region + ' ????-??-?? ??:??.csv', "data/clean")
        start = 14 + len(region)
        source_path = source_path[start:]
        if (findFile(region + " " + str(percent) + " VHI<" + VHI_percent + source_path , "data/filtered")): pass
        else:
            old_data = findFile(region + " " + str(percent) + " VHI<" + VHI_percent + ' ????-??-?? ??:??.csv' , "data/filtered")
            if (old_data): # Если был этот же файл для этой области, то он будет удален и заменен на более новые данные
                hdr.os.remove(old_data)
            current_path = "data/filtered/" + region + " " + str(percent) + " VHI<" + VHI_percent + source_path
            df.drop(df.columns[[0]], axis=1)
            df.to_csv(current_path) # Запись DataFrame в файл
            with open(current_path,"r+") as f: # Редактирование файла используя Python 3
                table = []
                for row in hdr.csv.reader(f): # Считать с файла в список
                    table_row = row[1:]
                    table_row[3] = table_row[3][0:7] # Убрать лишнюю информацию
                    table.append(table_row)
                f.seek(0) # Отчистить файл
                f.truncate()
                writer = hdr.csv.writer(f) # Записать со списка в файл
                for row in table:
                    writer.writerow(row)
        hdr.display(df)
