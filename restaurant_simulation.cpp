#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <memory>
#include <limits>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <sstream>

using namespace std;

// Forward declarations
class Waiter;
class Order;

// Timestamp class for order tracking
class Timestamp {
private:
    int year, month, day, hour, minute, second;

public:
    Timestamp() {
        auto now = chrono::system_clock::now();
        auto time_t = chrono::system_clock::to_time_t(now);
        tm* timeinfo = localtime(&time_t);
        
        year = timeinfo->tm_year + 1900;
        month = timeinfo->tm_mon + 1;
        day = timeinfo->tm_mday;
        hour = timeinfo->tm_hour;
        minute = timeinfo->tm_min;
        second = timeinfo->tm_sec;
    }
    
    // Constructor for simulated timestamps
    Timestamp(int y, int m, int d, int h, int min, int s) 
        : year(y), month(m), day(d), hour(h), minute(min), second(s) {}
    
    string toString() const {
        stringstream ss;
        ss << setfill('0') << setw(2) << day << "/" 
           << setw(2) << month << "/" << year << " "
           << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
        return ss.str();
    }
    
    string toTimeString() const {
        stringstream ss;
        ss << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second;
        return ss.str();
    }
    
    string toDateString() const {
        stringstream ss;
        ss << setfill('0') << setw(2) << day << "/" << setw(2) << month << "/" << year;
        return ss.str();
    }
};

// Enum for order types
enum class OrderType {
    SIT_IN,
    TAKE_OUT
};

// Enum for patron types
enum class PatronType {
    INDIVIDUAL,
    GROUP
};

// Patron class
class Patron {
private:
    string name;
    PatronType type;
    int groupSize;
    bool isSitIn;

public:
    Patron(string n, PatronType t, int size = 1, bool sitIn = true) 
        : name(n), type(t), groupSize(size), isSitIn(sitIn) {}
    
    string getName() const { return name; }
    PatronType getType() const { return type; }
    int getGroupSize() const { return groupSize; }
    bool isSitInOrder() const { return isSitIn; }
    
    string getTypeString() const {
        return (type == PatronType::INDIVIDUAL) ? "Individual" : "Group";
    }
};

// Order class
class Order {
private:
    int orderId;
    shared_ptr<Patron> patron;
    OrderType type;
    double totalAmount;
    shared_ptr<Waiter> waiter;
    string items;
    Timestamp timestamp;

public:
    Order(int id, shared_ptr<Patron> p, OrderType ot, double amount, shared_ptr<Waiter> w, string orderItems)
        : orderId(id), patron(p), type(ot), totalAmount(amount), waiter(w), items(orderItems), timestamp() {}
    
    // Constructor with custom timestamp for simulation
    Order(int id, shared_ptr<Patron> p, OrderType ot, double amount, shared_ptr<Waiter> w, string orderItems, Timestamp ts)
        : orderId(id), patron(p), type(ot), totalAmount(amount), waiter(w), items(orderItems), timestamp(ts) {}
    
    int getOrderId() const { return orderId; }
    shared_ptr<Patron> getPatron() const { return patron; }
    OrderType getType() const { return type; }
    double getTotalAmount() const { return totalAmount; }
    shared_ptr<Waiter> getWaiter() const { return waiter; }
    string getItems() const { return items; }
    Timestamp getTimestamp() const { return timestamp; }
    
    string getTypeString() const {
        return (type == OrderType::SIT_IN) ? "Sit-in" : "Take-out";
    }
};

// Waiter class
class Waiter {
private:
    int waiterId;
    string name;
    vector<shared_ptr<Order>> orders;

public:
    Waiter(int id, string n) : waiterId(id), name(n) {}
    
    int getWaiterId() const { return waiterId; }
    string getName() const { return name; }
    
    void addOrder(shared_ptr<Order> order) {
        orders.push_back(order);
    }
    
    double getTotalSales() const {
        double total = 0.0;
        for (const auto& order : orders) {
            total += order->getTotalAmount();
        }
        return total;
    }
    
    double getCommission() const {
        return getTotalSales() * 0.15; // 15% commission
    }
    
    int getOrderCount() const {
        return orders.size();
    }
    
    vector<shared_ptr<Order>> getOrders() const {
        return orders;
    }
};

// Restaurant class
class Restaurant {
private:
    string name;
    vector<shared_ptr<Waiter>> waiters;
    vector<shared_ptr<Order>> orders;
    int nextOrderId;

public:
    Restaurant(string n) : name(n), nextOrderId(1) {}
    
    void addWaiter(shared_ptr<Waiter> waiter) {
        waiters.push_back(waiter);
    }
    
    void addOrder(shared_ptr<Patron> patron, OrderType orderType, double amount, 
                  shared_ptr<Waiter> waiter, string items) {
        auto order = make_shared<Order>(nextOrderId++, patron, orderType, amount, waiter, items);
        orders.push_back(order);
        waiter->addOrder(order);
    }
    
    // Overloaded method for adding orders with custom timestamps
    void addOrder(shared_ptr<Patron> patron, OrderType orderType, double amount, 
                  shared_ptr<Waiter> waiter, string items, Timestamp timestamp) {
        auto order = make_shared<Order>(nextOrderId++, patron, orderType, amount, waiter, items, timestamp);
        orders.push_back(order);
        waiter->addOrder(order);
    }
    
    // Getter methods for menu system
    string getName() const { return name; }
    vector<shared_ptr<Waiter>> getWaiters() const { return waiters; }
    vector<shared_ptr<Order>> getOrders() const { return orders; }
    
    // Report a) Total number of sales divided into sit-in and take-out orders
    void reportOrderCounts() const {
        cout << "\n=== ORDER COUNT REPORT ===" << endl;
        cout << setw(50) << left << "Report a) Total number of sales divided into sit-in and take-out orders" << endl;
        cout << string(80, '-') << endl;
        
        int sitInCount = 0, takeOutCount = 0;
        
        for (const auto& order : orders) {
            if (order->getType() == OrderType::SIT_IN) {
                sitInCount++;
            } else {
                takeOutCount++;
            }
        }
        
        cout << setw(20) << left << "Sit-in Orders:" << setw(10) << right << sitInCount << endl;
        cout << setw(20) << left << "Take-out Orders:" << setw(10) << right << takeOutCount << endl;
        cout << setw(20) << left << "Total Orders:" << setw(10) << right << (sitInCount + takeOutCount) << endl;
    }
    
    // Report b) Total sales for the day, divided into sit-in and take-out sales
    void reportTotalSales() const {
        cout << "\n=== TOTAL SALES REPORT ===" << endl;
        cout << setw(50) << left << "Report b) Total sales for the day, divided into sit-in and take-out sales" << endl;
        cout << string(80, '-') << endl;
        
        double sitInSales = 0.0, takeOutSales = 0.0;
        
        for (const auto& order : orders) {
            if (order->getType() == OrderType::SIT_IN) {
                sitInSales += order->getTotalAmount();
            } else {
                takeOutSales += order->getTotalAmount();
            }
        }
        
        cout << setw(20) << left << "Sit-in Sales:" << "R" << setw(10) << right << fixed << setprecision(2) << sitInSales << endl;
        cout << setw(20) << left << "Take-out Sales:" << "R" << setw(10) << right << fixed << setprecision(2) << takeOutSales << endl;
        cout << setw(20) << left << "Total Sales:" << "R" << setw(10) << right << fixed << setprecision(2) << (sitInSales + takeOutSales) << endl;
    }
    
    // Report c) Total sales made by each waiter
    void reportWaiterSales() const {
        cout << "\n=== WAITER SALES REPORT ===" << endl;
        cout << setw(50) << left << "Report c) Total sales made by each waiter" << endl;
        cout << string(80, '-') << endl;
        
        cout << setw(5) << left << "ID" << setw(20) << left << "Waiter Name" 
             << setw(15) << right << "Orders" << setw(15) << right << "Total Sales" << endl;
        cout << string(80, '-') << endl;
        
        for (const auto& waiter : waiters) {
            cout << setw(5) << left << waiter->getWaiterId() 
                 << setw(20) << left << waiter->getName()
                 << setw(15) << right << waiter->getOrderCount()
                 << "R" << setw(14) << right << fixed << setprecision(2) << waiter->getTotalSales() << endl;
        }
    }
    
    // Report d) Commission for each waiter (15% of their total sales)
    void reportWaiterCommission() const {
        cout << "\n=== WAITER COMMISSION REPORT ===" << endl;
        cout << setw(50) << left << "Report d) Commission for each waiter (15% of total sales)" << endl;
        cout << string(80, '-') << endl;
        
        cout << setw(5) << left << "ID" << setw(20) << left << "Waiter Name" 
             << setw(15) << right << "Total Sales" << setw(15) << right << "Commission" << endl;
        cout << string(80, '-') << endl;
        
        for (const auto& waiter : waiters) {
            cout << setw(5) << left << waiter->getWaiterId() 
                 << setw(20) << left << waiter->getName()
                 << "R" << setw(14) << right << fixed << setprecision(2) << waiter->getTotalSales()
                 << "R" << setw(14) << right << fixed << setprecision(2) << waiter->getCommission() << endl;
        }
    }
    
    // Display all orders for detailed view
    void displayAllOrders() const {
        cout << "\n=== DETAILED ORDER REPORT ===" << endl;
        cout << string(120, '-') << endl;
        cout << setw(8) << left << "Order ID" << setw(20) << left << "Patron" 
             << setw(15) << left << "Type" << setw(15) << left << "Order Type"
             << setw(20) << left << "Waiter" << setw(20) << left << "Timestamp"
             << setw(15) << right << "Amount" << endl;
        cout << string(120, '-') << endl;
        
        for (const auto& order : orders) {
            cout << setw(8) << left << order->getOrderId()
                 << setw(20) << left << order->getPatron()->getName()
                 << setw(15) << left << order->getPatron()->getTypeString()
                 << setw(15) << left << order->getTypeString()
                 << setw(20) << left << order->getWaiter()->getName()
                 << setw(20) << left << order->getTimestamp().toString()
                 << "R" << setw(14) << right << fixed << setprecision(2) << order->getTotalAmount() << endl;
        }
    }
    
    // Generate all reports
    void generateAllReports() const {
        cout << "\n" << string(80, '=') << endl;
        cout << "RESTAURANT SIMULATION REPORT - " << name << endl;
        cout << string(80, '=') << endl;
        
        reportOrderCounts();
        reportTotalSales();
        reportWaiterSales();
        reportWaiterCommission();
        displayAllOrders();
    }
};

// Function to create sample data for demonstration
void createSampleData(Restaurant& restaurant) {
    // Create waiters with South African names
    auto waiter1 = make_shared<Waiter>(1, "Sipho Ndlovu");
    auto waiter2 = make_shared<Waiter>(2, "Thandi Maseko");
    auto waiter3 = make_shared<Waiter>(3, "Lungile Zulu");
    
    restaurant.addWaiter(waiter1);
    restaurant.addWaiter(waiter2);
    restaurant.addWaiter(waiter3);
    
    // Create patrons with South African names
    auto patron1 = make_shared<Patron>("Nokuthula Dlamini", PatronType::INDIVIDUAL, 1, true);
    auto patron2 = make_shared<Patron>("Themba Nkosi", PatronType::GROUP, 4, true);
    auto patron3 = make_shared<Patron>("Zanele Mbatha", PatronType::INDIVIDUAL, 1, false);
    auto patron4 = make_shared<Patron>("Mandla Cele", PatronType::GROUP, 6, true);
    auto patron5 = make_shared<Patron>("Lerato Molefe", PatronType::INDIVIDUAL, 1, false);
    auto patron6 = make_shared<Patron>("Kagiso Mokoena", PatronType::GROUP, 3, true);
    auto patron7 = make_shared<Patron>("Amahle Ngcobo", PatronType::INDIVIDUAL, 1, true);
    auto patron8 = make_shared<Patron>("Sibusiso Khumalo", PatronType::GROUP, 5, true);
    
    // Add orders with realistic South African prices in Rands and simulated timestamps
    restaurant.addOrder(patron1, OrderType::SIT_IN, 125.50, waiter1, "Burger, Chips, Coke", Timestamp(2024, 12, 15, 12, 30, 15));
    restaurant.addOrder(patron2, OrderType::SIT_IN, 489.75, waiter2, "4x Pasta, 4x Wine, 2x Dessert", Timestamp(2024, 12, 15, 13, 15, 42));
    restaurant.addOrder(patron3, OrderType::TAKE_OUT, 118.25, waiter1, "Pizza Slice, Soda", Timestamp(2024, 12, 15, 13, 45, 23));
    restaurant.addOrder(patron4, OrderType::SIT_IN, 856.40, waiter3, "6x Steak, 6x Beer, 3x Appetizer", Timestamp(2024, 12, 15, 14, 20, 8));
    restaurant.addOrder(patron5, OrderType::TAKE_OUT, 232.80, waiter2, "2x Sandwich, Chips, Coffee", Timestamp(2024, 12, 15, 15, 5, 37));
    restaurant.addOrder(patron6, OrderType::SIT_IN, 367.90, waiter1, "3x Fish, 3x Wine, Salad", Timestamp(2024, 12, 15, 16, 12, 55));
    restaurant.addOrder(patron7, OrderType::SIT_IN, 242.15, waiter3, "Salmon, Rice, Tea", Timestamp(2024, 12, 15, 17, 30, 12));
    restaurant.addOrder(patron8, OrderType::SIT_IN, 734.60, waiter2, "5x Chicken, 5x Beer, 2x Dessert", Timestamp(2024, 12, 15, 18, 45, 29));
    restaurant.addOrder(patron1, OrderType::TAKE_OUT, 128.45, waiter1, "Salad, Soup, Bread", Timestamp(2024, 12, 15, 19, 15, 44));
    restaurant.addOrder(patron3, OrderType::SIT_IN, 355.30, waiter3, "Pasta, Wine, Tiramisu", Timestamp(2024, 12, 15, 20, 30, 18));
}

// Menu system functions
void displayMainMenu() {
    cout << "\n" << string(60, '=') << endl;
    cout << "    RESTAURANT SIMULATION MANAGEMENT SYSTEM" << endl;
    cout << string(60, '=') << endl;
    cout << "1. View All Reports" << endl;
    cout << "2. View Order Count Report" << endl;
    cout << "3. View Total Sales Report" << endl;
    cout << "4. View Waiter Sales Report" << endl;
    cout << "5. View Waiter Commission Report" << endl;
    cout << "6. View Detailed Order Report" << endl;
    cout << "7. Add New Order" << endl;
    cout << "8. View Restaurant Statistics" << endl;
    cout << "9. View Orders by Time Range" << endl;
    cout << "10. Clear Screen" << endl;
    cout << "0. Exit Program" << endl;
    cout << string(60, '=') << endl;
    cout << "Enter your choice (0-10): ";
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int getValidChoice() {
    int choice;
    while (!(cin >> choice) || choice < 0 || choice > 10) {
        cout << "Invalid input! Please enter a number between 0 and 10: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
}

void displayRestaurantStats(const Restaurant& restaurant) {
    cout << "\n=== RESTAURANT STATISTICS ===" << endl;
    cout << string(50, '-') << endl;
    cout << "Restaurant Name: " << restaurant.getName() << endl;
    cout << "Total Waiters: " << restaurant.getWaiters().size() << endl;
    cout << "Total Orders: " << restaurant.getOrders().size() << endl;
    
    double totalSales = 0.0;
    for (const auto& order : restaurant.getOrders()) {
        totalSales += order->getTotalAmount();
    }
    cout << "Total Sales: R" << fixed << setprecision(2) << totalSales << endl;
    
    double totalCommission = 0.0;
    for (const auto& waiter : restaurant.getWaiters()) {
        totalCommission += waiter->getCommission();
    }
    cout << "Total Commission Paid: R" << fixed << setprecision(2) << totalCommission << endl;
    cout << string(50, '-') << endl;
}

void addNewOrder(Restaurant& restaurant) {
    cout << "\n=== ADD NEW ORDER ===" << endl;
    cout << string(40, '-') << endl;
    
    // Get patron information
    string patronName;
    cout << "Enter patron name: ";
    cin.ignore();
    getline(cin, patronName);
    
    int patronTypeChoice;
    cout << "Patron type:\n1. Individual\n2. Group\nEnter choice (1-2): ";
    cin >> patronTypeChoice;
    
    PatronType patronType = (patronTypeChoice == 1) ? PatronType::INDIVIDUAL : PatronType::GROUP;
    
    int groupSize = 1;
    if (patronType == PatronType::GROUP) {
        cout << "Enter group size: ";
        cin >> groupSize;
    }
    
    int orderTypeChoice;
    cout << "Order type:\n1. Sit-in\n2. Take-out\nEnter choice (1-2): ";
    cin >> orderTypeChoice;
    
    OrderType orderType = (orderTypeChoice == 1) ? OrderType::SIT_IN : OrderType::TAKE_OUT;
    
    // Select waiter
    cout << "\nAvailable waiters:" << endl;
    for (const auto& waiter : restaurant.getWaiters()) {
        cout << waiter->getWaiterId() << ". " << waiter->getName() << endl;
    }
    
    int waiterChoice;
    cout << "Select waiter ID: ";
    cin >> waiterChoice;
    
    auto selectedWaiter = restaurant.getWaiters()[waiterChoice - 1];
    
    // Get order details
    double amount;
    cout << "Enter order amount (R): ";
    cin >> amount;
    
    string items;
    cout << "Enter order items: ";
    cin.ignore();
    getline(cin, items);
    
    // Create patron and add order
    auto patron = make_shared<Patron>(patronName, patronType, groupSize, (orderType == OrderType::SIT_IN));
    restaurant.addOrder(patron, orderType, amount, selectedWaiter, items);
    
    cout << "\n✅ Order added successfully!" << endl;
    cout << "Order ID: " << restaurant.getOrders().back()->getOrderId() << endl;
    cout << "Timestamp: " << restaurant.getOrders().back()->getTimestamp().toString() << endl;
}

void displayOrdersByTimeRange(const Restaurant& restaurant) {
    cout << "\n=== ORDERS BY TIME RANGE ===" << endl;
    cout << string(50, '-') << endl;
    
    cout << "Enter start hour (0-23): ";
    int startHour;
    cin >> startHour;
    
    cout << "Enter end hour (0-23): ";
    int endHour;
    cin >> endHour;
    
    cout << "\nOrders between " << startHour << ":00 and " << endHour << ":00:" << endl;
    cout << string(120, '-') << endl;
    cout << setw(8) << left << "Order ID" << setw(20) << left << "Patron" 
         << setw(15) << left << "Type" << setw(15) << left << "Order Type"
         << setw(20) << left << "Waiter" << setw(20) << left << "Timestamp"
         << setw(15) << right << "Amount" << endl;
    cout << string(120, '-') << endl;
    
    int count = 0;
    for (const auto& order : restaurant.getOrders()) {
        int orderHour = order->getTimestamp().toString().substr(11, 2)[0] - '0' * 10 + 
                       order->getTimestamp().toString().substr(12, 1)[0] - '0';
        if (orderHour >= startHour && orderHour <= endHour) {
            cout << setw(8) << left << order->getOrderId()
                 << setw(20) << left << order->getPatron()->getName()
                 << setw(15) << left << order->getPatron()->getTypeString()
                 << setw(15) << left << order->getTypeString()
                 << setw(20) << left << order->getWaiter()->getName()
                 << setw(20) << left << order->getTimestamp().toString()
                 << "R" << setw(14) << right << fixed << setprecision(2) << order->getTotalAmount() << endl;
            count++;
        }
    }
    
    if (count == 0) {
        cout << "No orders found in the specified time range." << endl;
    } else {
        cout << string(120, '-') << endl;
        cout << "Total orders in time range: " << count << endl;
    }
}

void processMenuChoice(int choice, Restaurant& restaurant) {
    switch (choice) {
        case 1:
            restaurant.generateAllReports();
            break;
        case 2:
            restaurant.reportOrderCounts();
            break;
        case 3:
            restaurant.reportTotalSales();
            break;
        case 4:
            restaurant.reportWaiterSales();
            break;
        case 5:
            restaurant.reportWaiterCommission();
            break;
        case 6:
            restaurant.displayAllOrders();
            break;
        case 7:
            addNewOrder(restaurant);
            break;
        case 8:
            displayRestaurantStats(restaurant);
            break;
        case 9:
            displayOrdersByTimeRange(restaurant);
            break;
        case 10:
            clearScreen();
            break;
        case 0:
            cout << "\nThank you for using the Restaurant Simulation System!" << endl;
            cout << "Goodbye! 👋" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
}

int main() {
    cout << "Restaurant Simulation Program" << endl;
    cout << "Algorithm Analysis and Program Design - Data Structures" << endl;
    cout << string(50, '=') << endl;
    
    // Create restaurant
    Restaurant restaurant("Mama's Kitchen - Johannesburg");
    
    // Create sample data
    createSampleData(restaurant);
    
    cout << "✅ Sample data loaded successfully!" << endl;
    cout << "Welcome to " << restaurant.getName() << " Management System" << endl;
    
    int choice;
    do {
        displayMainMenu();
        choice = getValidChoice();
        processMenuChoice(choice, restaurant);
        
        if (choice != 0 && choice != 10) {
            cout << "\nPress Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
    } while (choice != 0);
    
    return 0;
} 