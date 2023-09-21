import os
import os.path
from csv_units import CSV
from calculatetion import Calculation
from parser import Parser
# разбить на классы
# упал при вводе айдишника который не является цифрой ( metric только цифры разрешать при вводе строки ошибка)
#  ____                                    _       _               _
# / ___| _   _  ___ ___ ___  ___ ___      | | __ _| |__      _ __ | | ___  __ _ ___  ___
# \___ \| | | |/ __/ __/ _ \/ __/ __|     | |/ _` | '_ \    | '_ \| |/ _ \/ _` / __|/ _ \
#  ___) | |_| | (_| (_|  __/\__ \__ \     | | (_| | |_) |   | |_) | |  __/ (_| \__ \  __/
# |____/ \__,_|\___\___\___||___/___/     |_|\__,_|_.__/    | .__/|_|\___|\__,_|___/\___|

class Stats:
    def __init__(self):
        print("Completed metrics and parsing")

# --------------------------------------------------------------------------------------------------------
    def action_in_csv(self):
        self.__get_path()
        Parser().read_data_csv()
        self.__get_region()
        Parser().get_region_data()
        self.__get_column()
        Calculation().calculation_metric()
        self.__clear_dataset()

# --------------------------------------------------------------------------------------------------------

    @staticmethod
    def __get_column():
        print("FILE column:")
        print(CSV.columns_headers)
        CSV.column_id = input("Enter file column: ")
        while True:
            if not CSV.column_id.isdigit():
                print("Error, please insert columns with digit")
            elif int(CSV.column_id) < 2 or int(CSV.column_id) > 6:
                print("Error")
            else:
                break
            CSV.column_id = input("Enter file column: ")

# --------------------------------------------------------------------------------------------------------
    def __get_path(self):
        flag= int(1)
        print("FILE PATH")
        print("Please use file an extention .csv and less 1gb")
        print("C:/Users/jeiyv/PycharmProjects/pythonProject")
        CSV.file_path = input("Enter file path: ")
        while True:
            if CSV.file_path.find('.csv') == -1:
                print(" That not csv file - you meaning csv ")
            elif not os.path.exists(CSV.file_path):
                print("This file not exist")
            elif os.stat(CSV.file_path).st_size >= CSV.file_size:
                print("File so large you need less file.csv")
            else:
                break
            CSV.file_path = input("Enter file path: ")

# --------------------------------------------------------------------------------------------------------

# --------------------------------------------------------------------------------------------------------

    def __get_region(self):
        print("Select Region: ")
        print('\n'.join(CSV.all_regions))
        CSV.region = input("Enter region name: ")
        while not (CSV.region in CSV.all_regions):
            print("Not exist this region list of regions")
            CSV.region = input("Try again. Enter region name")

# --------------------------------------------------------------------------------------------------------

# --------------------------------------------------------------------------------------------------------

    @staticmethod
    def __get_column_header():
        print("HEADER_COLUMNS")
        try:
            CSV.columns_headers = CSV.columns_data.pop(0)
            print(CSV.columns_headers)
        except IndexError:
            print("This is empty file")

# --------------------------------------------------------------------------------------------------------

# --------------------------------------------------------------------------------------------------------
    @staticmethod
    def __clear_dataset():
        CSV.file_path = ''  # файловый путь
        CSV.region = ''  # выбранный регион
        CSV.columns_headers = []  # заголовки
        CSV.columns_data = []  # выбранная колонка
        CSV.all_regions = set()  # все регионы
        CSV.chosen_stroke_data = []  # выбранная строка в таблице

