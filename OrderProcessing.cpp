/*
  File: orders.cpp
  Created by: ??
  Creation Date: ??
  Synopsis: ??
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

// CLASS DEFINITIONS

class Time {
    int hours;
    int minutes;
    int seconds;

public:
    void setHours(int h) { hours = h; }
    void setMinutes(int m) { minutes = m; }
    void setSeconds(int s) { seconds = s; }
    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }
    string twoDigits(int num) const {
        if (num < 10) {
            return "0" + to_string(num);
        }
        else {
            return to_string(num);
        }
    }
    string toString() const {
        return twoDigits(hours) + ":" + twoDigits(minutes) + ":" + twoDigits(seconds);
    }
};

class Order {
    string id;
    double price;
    int quantity;
    Time time;

public:
    void setID(string i) { id = i; }
    void setPrice(double p) { price = p; }
    void setQuantity(int q) { quantity = q; }
    void setTime(Time t) { time = t; }
    string getID() const { return id; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    Time getTime() const { return time; }
    void display() const {
        double total = price * quantity;
        cout << "Order " << id << ", $" << fixed << setprecision(2) << price << ", "
            << quantity << " units, costs $" << total << ", taken @ " << time.toString() << endl;
    }
};

// FUNCTION PROTOTYPES GO HERE:

void readOrders(vector<Order>& orders, int maxPrice);
void displayOrders(const vector<Order>& orders);
void drawHistogram(const vector<Order>& orders);

int main() {
    const int MAX_PRICE = 100;
    vector<Order> orders;
    readOrders(orders, MAX_PRICE);
    if (!orders.empty()) {
        displayOrders(orders);
        drawHistogram(orders);
    }
    return 0;
}

// FUNCTION DEFINITIONS GO HERE:
void readOrders(vector<Order> & orders, int maxPrice){
    cout << "Enter today's orders:" << endl;
    int orderNum = 1;
    while (true) {
        cout << "Order #" << orderNum << " - ";
        string id;
        double price;
        int quantity, hours, minutes, seconds;
        cin >> id;
        if (id == "quit") {
            break;
        }
        cin >> price >> quantity >> hours >> minutes >> seconds;
        if (price <= maxPrice && quantity > 0 && id.size() <= 3) {
            bool validID = true;
            for (char c : id) {
                if (!('a'<=c && c<='z')&&!('0'<=c && c<='9')) {
                    validID = false;
                    break;
                }
            }
            if (validID) {
                Order order;
                order.setID(id);
                order.setPrice(price);
                order.setQuantity(quantity);
                Time time;
                time.setHours(hours);
                time.setMinutes(minutes);
                time.setSeconds(seconds);
                order.setTime(time);
                orders.push_back(order);
                cout << "Order recorded." << endl;
            }
            else {
                cout << "Invalid id, try again." << endl;
                break;
            }
        }
        else {
            cout << "Invalid input. Order not recorded." << endl;
            break;
        }
        orderNum++;
    }
}
void displayOrders(const vector<Order>& orders) {
    for (const Order& order : orders) {
        order.display();
    }
}

void drawHistogram(const vector<Order>& orders){
    const int NUM_BINS = 10;
    int binCounts[NUM_BINS] = {0};
    for (const Order& order : orders){
        int bin = order.getPrice() * NUM_BINS / 100;
        if (bin >= 0 && bin < NUM_BINS){
            binCounts[bin]++;
        }
    }
}