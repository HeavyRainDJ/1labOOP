import numpy as np
from csv_units import CSV
import statistics


class Calculation:

    def calculation_metric(self):
        print("Calculating metrics")
        data = []
        for item in CSV.region_data:
            num = item[int(CSV.column_id)]
            if num != "":
                data.append(float(num))
        if len(data) != 0:
            print(f'Maximum: {max(data)}')
            print(f'Minimum: {min(data)}')
            print(f'Median: {statistics.median(data)}')

            percentile = int(input("Enter your persintel: "))
            if percentile < 0 or percentile >= 101:
                print(" Your persintality not correct")
                percentile = int(input("Try again. Enter your persintel: "))
            self.percintality(data, percentile)

    @staticmethod
    def percintality(data, percentile):
        print("+-------+-------------+")
        print("|   N%  |  Percentile |")
        print("+-------+-------------+")
        for i in range(0, 101, percentile):
            print(f'    {i}%:      {round(np.percentile(data, i), 3)}')
