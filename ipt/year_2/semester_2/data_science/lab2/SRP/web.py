# -*- coding: utf-8 -*-

from spyre import server
import numpy as np
from matplotlib import pyplot as plt
import hdr # Импортируемые библиотеки
import additional as adnl # Файл со вспомогательными функциями

def giveRegName():
    res = []
    for i in range(1,28):
        temp = {"label": adnl.regionName(i), "value": adnl.regionName(i)}
        res.append(temp)
    return sorted(res, key=lambda k: k['label']) 

def giveYears():
    res = []
    for i in range(1981,2017):
        temp = {"label": i, "value": i}
        res.append(temp)
    return res

class Title(server.App):
    regions = giveRegName()
    years = giveYears()
    title = "Лабораторная работа 2"
    inputs = [{ "type":'dropdown',
                "label": 'Данные',
                "options" : [ {"label": "VHI", "value":"VHI"},
                              {"label": "TCI", "value":"TCI"},
                              {"label": "VCI", "value":"VCI"}],
                "key": "data",
                "action_id": "update_data"},
              { "type":'dropdown',
                "label": 'Область',
                "options" : regions,
                "key": "region",
                "action_id": "update_data"},
              { "type":'dropdown',
                "label": 'С',
                "options" : years,
                "key": "data_from",
                "action_id": "update_data"},
              { "type":'slider',
                "key": 'freq_from',
                "value" : 1,
                "min" : 1,
                "max" : 52,
                "action_id" : "update_data" },
              { "type":'dropdown',
                "label": 'По',
                "options" : years,
                "key": "data_to",
                "action_id": "update_data"},
              { "type":'slider',
                "key": 'freq_to',
                "value" : 1,
                "min" : 1,
                "max" : 52,
                "action_id" : "update_data" }]
    controls = [{"type" : "button",
                 "label" : "Обновить",
                 "id" : "update_data"}]
    tabs = ["Введение", "График", "Данные", "Экстремумы", "Выводы"]
    outputs = [{ "type" : "table",
                 "output_id" : "table_id",
                 "control_id" : "update_data",
                 "tab" : "Данные",
                 "on_page_load" : False ,
                 "sortable" : True },
               { "type" : "plot",
                 "output_id" : "plot",
                 "control_id" : "update_data",
                 "tab" : "График",
                 "on_page_load" : False},
               { "type" : "html",
                 "id" : "HTML_id",
                 "tab" : "Введение"},
               { "type" : "table",
                 "id" : "extDF",
                 "on_page_load" : False,
                 "control_id" : "update_data",
                 "tab" : "Экстремумы"},
               { "type" : "html",
                 "id" : "concl",
                 "tab" : "Выводы"}]
    def table_id(self, params): # Таблица данных
        self.data = params['data']
        self.region = params['region']
        self.data_from = params['data_from']
        self.data_to = params['data_to']
        self.freq_from = params['freq_from']
        self.freq_to = params['freq_to']
        return adnl.makeDF(self.region, self.data, self.data_from, self.data_to, self.freq_from, self.freq_to)
    def getPlot(self, params): # График
        df = self.table_id(params)
        return adnl.makeFig(df, self.data, self.region, self.data_from, self.data_to)
    def HTML_id(self, params):
        return "<h1>Часть 1</h1><p style='margin: 20px; font-size: 20px'>Первая часть лабораторной работы состоит в создании репозитория на ресурсе <i><b>GitHub</b></i>.<br>После создания аккаунта на <i><b>GitHub</b></i> и установки <i><b>git</b></i> на локальный компьютер, был создан локальный репозиторий, связанного с удалленым, при этом была выполнена связка локального и удаленного репозитория командами: <br><i>git clone https://github.com/Nikita-L/SRP.git<br>git config user.name Nikita-L<br>git config user.email lyovkin@i.ua</i><br>Чтобы узнать состояние нашей <i><b>gid</b></i>-копии, использовалась команда:<br><i>git status</i><br>После внесения изменений в рабочую копию, нужно сделаь коммит всех изменений: <br><i>git add путь_к_файлу<br>git commit</i><br>Загрузка локальных изменений в удаленный репозиторий: <br><i>git push origin master</i><br><br><a href='https://github.com/Nikita-L/SRP'>Ссылка</a> на созданный репозиторий.</p><br>"
    def extDF(self, params):
        df = self.table_id(params)
        return adnl.makeExtVHI(df, self.data)
    def concl(self, params):
        return "<h1>Выводы</h1><p style='margin: 20px; font-size: 20px'>При выполнении этой лабораторной работы, я углубил знания в работе со средой обработки данных в Python, изучил новые возможности <i><b>pandas</b></i>, а также ознакомился и получил практические навыки работы с библиотекой <i><b>spyre</b></i>.</p>"

app = Title()
app.launch()