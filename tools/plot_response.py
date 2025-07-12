import matplotlib.pyplot as plt
import csv

def main():
    times, temps = [], []
    with open('response.csv') as f:
        reader = csv.DictReader(f)
        for row in reader:
            times.append(float(row['time']))
            temps.append(float(row['temperature']))

    plt.plot(times, temps)
    plt.xlabel('Time (s)')
    plt.ylabel('Temperature (°C)')
    plt.title('PID Step Response')
    plt.savefig('response.png')
    print('Plot saved as response.png')

if __name__ == '__main__':
    main()
