from csv_units import CSV
import csv

class Parser:

    @staticmethod
    def get_region_data():
        for item in CSV.columns_data:
            if item[1] == CSV.region:
                CSV.region_data.append(item)
                print(f"{item}")

    @staticmethod
    def list_all_regions():
        set_regions = set()
        for item in CSV.columns_data:
            set_regions.add(item[1])
        CSV.all_regions = sorted(list(set_regions))

    def read_data_csv(self):
        print("Completed data")
        print(CSV.file_path)
        with open(CSV.file_path, newline='') as file:
            reader = csv.reader(file, delimiter=",")
            try:
                CSV.columns_headers = next(reader)
                for row in reader:
                    CSV.columns_data.append(row)
                csv.Sniffer().sniff(file.read(1024))  # Попытка обнаружить разделитель
                file.seek(0)
            except csv.Error:
                self.list_all_regions()
                print("Файл считан полностью")
            except Exception as e:
                print(f"Ошибка при чтении файла: {str(e)}")
