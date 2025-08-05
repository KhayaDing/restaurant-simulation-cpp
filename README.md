# Restaurant Simulation Program

## 🍽️ Algorithm Analysis and Program Design - Data Structures Group Project 2025

A comprehensive C++ restaurant simulation program that models a real-world restaurant setting for a particular day. The program tracks patrons, waiters, orders, and generates detailed reports on sales and commissions as required by the course assignment.

## 📋 Project Requirements

### Core Requirements (90% of marks)

✅ **Report a)** Total number of sales divided into sit-in and take-out orders  
✅ **Report b)** Total sales for the day, divided into sit-in and take-out sales  
✅ **Report c)** Total sales made by each waiter  
✅ **Report d)** Commission for each waiter (15% of their total sales)  

### Bonus Features (10% of marks)

✅ **Object-Oriented Programming (5%)** - Encapsulation, inheritance, polymorphism  
✅ **Extra Mile Features (5%)** - Smart pointers, modern C++, professional formatting  

## 🏗️ System Architecture

### Class Design
```
Restaurant (Main Controller)
├── Manages Waiters
├── Manages Orders
└── Generates Reports

Waiter
├── Tracks Orders
├── Calculates Sales
└── Computes Commission

Order
├── Links Patron
├── Links Waiter
└── Contains Order Details

Patron
├── Individual/Group Type
├── Sit-in/Take-out Preference
└── Group Size Information
```

### Data Structures Used
- **Vectors**: Dynamic storage for waiters, orders, and patrons
- **Smart Pointers**: Automatic memory management with `shared_ptr`
- **Enums**: Type-safe classification for order and patron types
- **Strings**: Efficient text data handling

## 🚀 Features

### Core Functionality
- **Patron Management**: Supports both individual and group patrons with South African names
- **Order Types**: Handles both sit-in and take-out orders
- **Waiter Management**: Multiple waiters can serve various tables and orders
- **Sales Tracking**: Comprehensive sales tracking and reporting in South African Rands (R)
- **Commission Calculation**: Automatic 15% commission calculation for waiters

### Advanced Features
- **Object-Oriented Design**: Clean class hierarchy with proper encapsulation
- **Modern C++**: C++11 features including smart pointers and range-based loops
- **Professional Reporting**: Formatted output with proper alignment
- **Error Handling**: Robust input validation and error management
- **Extensible Architecture**: Easy to add new features and reports
- **Interactive Menu System**: User-friendly interface for program navigation

### 🎯 Additional Features Beyond Project Scope

#### **Timestamp Management System**
- **Real-time Timestamps**: Automatic timestamp generation using `chrono` library
- **Custom Timestamps**: Support for simulated timestamps for historical data
- **Multiple Format Options**: 
  - Full timestamp: `DD/MM/YYYY HH:MM:SS`
  - Time only: `HH:MM:SS`
  - Date only: `DD/MM/YYYY`

#### **Interactive Order Creation**
- **Dynamic Order Addition**: Add new orders during runtime
- **Patron Information Collection**: Name, type (individual/group), group size
- **Order Type Selection**: Sit-in vs take-out with validation
- **Waiter Assignment**: Interactive waiter selection from available staff
- **Order Details**: Amount, items, and automatic timestamp generation
- **Success Confirmation**: Order ID and timestamp display after creation

#### **Advanced Reporting Features**
- **Restaurant Statistics Dashboard**: 
  - Total waiters count
  - Total orders count
  - Total sales in Rands
  - Total commission paid
- **Detailed Order Reports**: Complete order listing with all details
- **Professional Formatting**: Aligned columns, proper spacing, currency formatting

#### **Enhanced User Experience**
- **Input Validation**: Robust error handling for all user inputs
- **Clear Screen Function**: Option to clear console for better readability
- **Press Enter to Continue**: User-friendly navigation between screens
- **Invalid Input Handling**: Graceful error messages and retry prompts
- **Menu Navigation**: Intuitive numbered menu system (0-10)

#### **Data Management Features**
- **Sample Data Loading**: Pre-populated with realistic South African restaurant data
- **Dynamic Data Addition**: Add new orders without restarting
- **Data Persistence**: Maintains all data during session
- **Order ID Management**: Automatic sequential order ID assignment
- **Waiter Order Tracking**: Each waiter maintains their own order list

#### **Professional Output Formatting**
- **Currency Formatting**: Proper Rands (R) formatting with decimal precision
- **Table Alignment**: Professional column alignment for all reports
- **Header Separators**: Clear visual separation with dashes and equals signs
- **Consistent Spacing**: Proper spacing and indentation throughout
- **Multi-platform Support**: Windows and Unix/Linux compatibility

#### **Error Handling and Validation**
- **Input Range Validation**: Ensures menu choices are within valid range (0-10)
- **Type Validation**: Validates numeric inputs and handles invalid characters
- **Data Integrity**: Ensures all required fields are provided
- **Graceful Degradation**: Continues operation even with invalid inputs
- **User Feedback**: Clear error messages and success confirmations

#### **Cross-Platform Compatibility**
- **Windows Support**: Uses `system("cls")` for Windows
- **Unix/Linux Support**: Uses `system("clear")` for Unix/Linux
- **Compiler Flexibility**: Supports g++, clang++, and MSVC
- **Standard Compliance**: C++11 standard compliance
- **Portable Code**: No platform-specific dependencies

## 📁 Project Structure

```
restaurant-simulation-cpp/
├── restaurant_simulation.cpp    # Main program with all classes and logic
├── Makefile                    # Unix/Linux compilation
├── compile.bat                 # Windows compilation
├── README.md                   # This comprehensive documentation
├── PROJECT_SUMMARY.md          # Detailed project summary
└── .gitignore                  # Version control exclusions
```

## 🛠️ Compilation and Execution

### Prerequisites
- C++11 compatible compiler (GCC, Clang, or MSVC)
- Make utility (optional, for using Makefile)

### Compilation Options

#### Using Makefile (Unix/Linux/macOS)
```bash
# Compile the program
make

# Compile and run
make run

# Clean build files
make clean

# Show help
make help
```

#### Using Batch File (Windows)
```cmd
# Run the batch file
compile.bat
```

#### Manual Compilation
```bash
# Using g++
g++ -std=c++11 -Wall -Wextra -O2 -o restaurant_simulation restaurant_simulation.cpp

# Using clang++
clang++ -std=c++11 -Wall -Wextra -O2 -o restaurant_simulation restaurant_simulation.cpp

# Using MSVC (Windows)
cl /std:c++11 /EHsc restaurant_simulation.cpp /Fe:restaurant_simulation.exe
```

### Execution
```bash
# Unix/Linux/macOS
./restaurant_simulation

# Windows
restaurant_simulation.exe
```

## 🎮 Interactive Menu System

The program features a comprehensive interactive menu system with the following options:

```
============================================================
    RESTAURANT SIMULATION MANAGEMENT SYSTEM
============================================================
1. View All Reports
2. View Order Count Report
3. View Total Sales Report
4. View Waiter Sales Report
5. View Waiter Commission Report
6. View Detailed Order Report
7. Add New Order
8. View Restaurant Statistics
9. View Orders by Time Range
10. Clear Screen
0. Exit Program
============================================================
```

### Menu Options Explained

1. **View All Reports** - Displays all four required reports in sequence
2. **View Order Count Report** - Shows sit-in vs take-out order counts
3. **View Total Sales Report** - Displays sales totals by order type
4. **View Waiter Sales Report** - Individual waiter performance metrics
5. **View Waiter Commission Report** - Commission calculations (15% of sales)
6. **View Detailed Order Report** - Complete order listing with timestamps
7. **Add New Order** - Interactive order creation with validation
8. **View Restaurant Statistics** - Summary statistics and overview
9. **View Orders by Time Range** - Filter orders by time period
10. **Clear Screen** - Clears the console for better readability
0. **Exit Program** - Safely exits the application

## 📊 Sample Output

The program generates professional-formatted reports including:

### Main Menu Interface
```
Restaurant Simulation Program
Algorithm Analysis and Program Design - Data Structures
==================================================
✓ Sample data loaded successfully!
Welcome to Mama's Kitchen - Johannesburg Management System

============================================================
    RESTAURANT SIMULATION MANAGEMENT SYSTEM
============================================================
1. View All Reports
2. View Order Count Report
3. View Total Sales Report
4. View Waiter Sales Report
5. View Waiter Commission Report
6. View Detailed Order Report
7. Add New Order
8. View Restaurant Statistics
9. View Orders by Time Range
10. Clear Screen
0. Exit Program
============================================================
Enter your choice (0-10):
```

### Sample Reports
```
=== ORDER COUNT REPORT ===
Report a) Total number of sales divided into sit-in and take-out orders
--------------------------------------------------------------------------------
Sit-in Orders:               7
Take-out Orders:             3
Total Orders:               10

=== TOTAL SALES REPORT ===
Report b) Total sales for the day, divided into sit-in and take-out sales
--------------------------------------------------------------------------------
Sit-in Sales:       R   3171.60
Take-out Sales:     R    479.50
Total Sales:        R   3651.10

=== WAITER SALES REPORT ===
Report c) Total sales made by each waiter
--------------------------------------------------------------------------------
ID   Waiter Name                  Orders    Total Sales
--------------------------------------------------------------------------------
1    Sipho Ndlovu                      4R        740.10
2    Thandi Maseko                     3R       1457.15
3    Lungile Zulu                      3R       1453.85

=== WAITER COMMISSION REPORT ===
Report d) Commission for each waiter (15% of total sales)
--------------------------------------------------------------------------------
ID   Waiter Name        Total Sales     Commission
--------------------------------------------------------------------------------
1    Sipho Ndlovu       R   740.10     R   111.02
2    Thandi Maseko     R  1457.15     R   218.57
3    Lungile Zulu      R  1453.85     R   218.08
```

### Detailed Order Report
```
=== DETAILED ORDER REPORT ===
------------------------------------------------------------------------------------------------------------------------
Order ID | Patron Name | Type | Order Type | Items | Amount | Waiter | Timestamp
------------------------------------------------------------------------------------------------------------------------
1        | Nokuthula Dlamini | Individual | Sit-in | Burger, Chips, Coke | R125.50 | Sipho Ndlovu | 15/12/2024 12:30:15
2        | Themba Nkosi | Group | Sit-in | 4x Pasta, 4x Wine, 2x Dessert | R489.75 | Thandi Maseko | 15/12/2024 13:15:42
3        | Zanele Mbatha | Individual | Take-out | Pizza Slice, Soda | R118.25 | Sipho Ndlovu | 15/12/2024 13:45:23
4        | Mandla Cele | Group | Sit-in | 6x Steak, 6x Beer, 3x Appetizer | R856.40 | Lungile Zulu | 15/12/2024 14:20:08
5        | Lerato Molefe | Individual | Take-out | 2x Sandwich, Chips, Coffee | R232.80 | Thandi Maseko | 15/12/2024 15:05:37
6        | Kagiso Mokoena | Group | Sit-in | 3x Fish, 3x Wine, Salad | R367.90 | Sipho Ndlovu | 15/12/2024 16:12:55
7        | Amahle Ngcobo | Individual | Sit-in | Salmon, Rice, Tea | R242.15 | Lungile Zulu | 15/12/2024 17:30:12
8        | Sibusiso Khumalo | Group | Sit-in | 5x Chicken, 5x Beer, 2x Dessert | R734.60 | Thandi Maseko | 15/12/2024 18:45:29
9        | Nokuthula Dlamini | Individual | Take-out | Salad, Soup, Bread | R128.45 | Sipho Ndlovu | 15/12/2024 19:15:44
10       | Zanele Mbatha | Individual | Sit-in | Pasta, Wine, Tiramisu | R355.30 | Lungile Zulu | 15/12/2024 20:30:18
```

## 🎯 Algorithm Analysis

### Time Complexity
- **Order Processing**: O(1) for adding orders
- **Report Generation**: O(n) where n is the number of orders
- **Sales Calculation**: O(m) where m is the number of orders per waiter
- **Menu Navigation**: O(1) for menu operations
- **Time Range Filtering**: O(n) where n is the number of orders

### Space Complexity
- **Storage**: O(n) where n is the total number of orders
- **Memory Management**: Automatic with smart pointers

## 🔧 Technical Implementation Details

### Advanced C++ Features Used
- **Smart Pointers**: `shared_ptr` for automatic memory management
- **Chrono Library**: Real-time timestamp generation and manipulation
- **STL Containers**: `vector` for dynamic data storage
- **Stream Manipulators**: `setw`, `setfill`, `setprecision` for formatting
- **Enum Classes**: Type-safe enumeration for order and patron types
- **Range-based For Loops**: Modern C++ iteration patterns

### Design Patterns and Architecture
- **Object-Oriented Design**: Clean separation of concerns with classes
- **Encapsulation**: Private data members with public accessors
- **Composition**: Restaurant contains waiters and orders
- **Association**: Orders link to patrons and waiters
- **Factory Pattern**: Timestamp creation with multiple constructors

### Error Handling and Validation
- **Input Validation**: Range checking and type validation
- **Exception Safety**: Robust error handling throughout
- **User Feedback**: Clear error messages and success confirmations
- **Graceful Degradation**: Continues operation with invalid inputs

### Cross-Platform Considerations
- **Conditional Compilation**: Platform-specific screen clearing
- **Standard Compliance**: C++11 standard for maximum compatibility
- **Portable Code**: No platform-specific dependencies
- **Compiler Flexibility**: Support for multiple C++ compilers

## 🏆 Educational Value

This project demonstrates:
- **Object-oriented programming principles** (Encapsulation, inheritance, polymorphism)
- **Modern C++ features** (Smart pointers, range-based loops, enums, chrono library)
- **Data structure implementation** (Vectors, dynamic memory management)
- **Algorithm design and analysis** (Time and space complexity considerations)
- **Professional software development practices** (Error handling, documentation, input validation)
- **Comprehensive reporting systems** (Multiple report formats, professional formatting)
- **User interface design** (Interactive menu system, user experience)
- **Time management systems** (Timestamp handling, time-based filtering)
- **Cross-platform development** (Windows/Unix compatibility, portable code)
- **Real-world application design** (Restaurant management, business logic)
- **Data validation and integrity** (Input validation, error handling, data consistency)
- **Professional output formatting** (Currency formatting, table alignment, visual design)

## 📅 Project Timeline

- **Presentations**: Week 5th - 10th October 2025
- **Submission**: Immediately after presentations
- **Maximum Marks**: 90% for core requirements + 10% for bonus features


## 👥 Group Project Information

**Course**: INFORMATION SYSTEMS III  
**Year**: 2025  
**Project Type**: Group Project  
**Language**: C++  
**Standard**: C++11  

## 📄 License

This project is created for educational purposes as part of the INFORMATION SYSTEMS III course.


## 🚀 Quick Start

1. **Clone or download** the project files
2. **Compile** using your preferred method:
   - Windows: `compile.bat`
   - Unix/Linux: `make`
   - Manual: `g++ -std=c++11 -Wall -Wextra -O2 -o restaurant_simulation restaurant_simulation.cpp`
3. **Run** the program:
   - Windows: `restaurant_simulation.exe`
   - Unix/Linux: `./restaurant_simulation`
4. **Navigate** the interactive menu to explore all features
5. **Experience** the South African restaurant simulation with local names, currency (Rands), and realistic pricing

## 📝 Usage Examples

### Adding a New Order
1. Select option 7 from the main menu
2. Enter patron details (name, type, group size if applicable)
3. Choose order type (sit-in or take-out)
4. Enter order amount and items
5. Select a waiter from the available list
6. The order is automatically added to the system

### Viewing Reports
- **Option 1**: View all reports at once
- **Options 2-5**: View individual reports
- **Option 6**: View detailed order listing with timestamps
- **Option 8**: View restaurant statistics overview
- **Option 9**: Filter orders by time range

---
