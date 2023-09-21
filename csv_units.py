class CSV:
    file_path = ''  # файловый путь
    region = ''  # выбранный регион
    column_id: str # номер колонки
    columns_headers = []  # заголовки
    columns_data = []  # выбранная колонка
    all_regions = set()  # все регионы
    region_data = []
    chosen_stroke_data = []  # выбранная строка в таблице
    file_size = int(2**30)
