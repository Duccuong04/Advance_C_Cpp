#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Interface for observers (display, logger, etc.)
class Observer {
public:
    virtual void update(float temperature, float humidity, float light) = 0;
};

// Subject (SensorManager) holds the state and notifies observers
class SensorManager {
    float temperature;
    float humidity;
    float light;
    std::vector<Observer*> observers;
public:
    void registerObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers() {
        for (auto observer : observers) {
            observer->update(temperature, humidity, light);
        }
    }

    void setMeasurements(float temp, float hum, float lightLvl) {
        temperature = temp;
        humidity = hum;
        light = lightLvl;
        notifyObservers();
    }
};

// Display component (an observer)
class Display : public Observer {
public:
    void update(float temperature, float humidity, float light) override {
        std::cout << "Display: Temperature: " << temperature
                  << ", Humidity: " << humidity
                  << ", Light: " << light << std::endl;
    }
};

// Logger component (an observer)
class Logger : public Observer {
public:
    void update(float temperature, float humidity, float light) override {
        std::cout << "Logging data... Temp: " << temperature
                  << ", Humidity: " << humidity
                  << ", Light: " << light << std::endl;
    }
};

int main() {
    SensorManager sensorManager;

    Display display;
    Logger logger;

    sensorManager.registerObserver(&display);
    sensorManager.registerObserver(&logger);

    sensorManager.setMeasurements(25.0, 60.0, 700.0); // Simulate sensor data update
    sensorManager.setMeasurements(26.0, 65.0, 800.0); // Another sensor update

    return 0;
}


