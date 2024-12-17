#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_SUBJECTS = 10; // Maximum number of subjects
const int MAX_SEMESTERS = 10; // Maximum number of semesters

void calculateGPA();
void calculateCGPA();
void methodOfCalculating();
void saveResultsToFile(const string& result);
void loadResultsFromFile(string& result);

int main() {
    int input;
    string results;
    // Loop used to display the menu until the user chooses to exit
    while (true) {
        cout << "-------- GPA & CGPA Calculator ------- " << endl;
        cout << endl;
        cout << "     Menu : \n" << endl;
        cout << "  1. Calculate GPA (Grade Point Average)" << endl;
        cout << "  2. Calculate CGPA (Cumulative Grade Point Average)" << endl;
        cout << "  3. Method to find GPA & CGPA" << endl;
        cout << "  4. Exit Application" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> input;

        // Switch case used to call the function according to the user input 
        switch (input) {
            case 1:
                calculateGPA(); // Call function to calculate GPA
                break;
            case 2:
                calculateCGPA(); // Call function to calculate CGPA
                break;
            case 3:
                methodOfCalculating(); // Call function to show method for calculating GPA & CGPA
                break;
            case 4:
                cout << "Exiting the application. Goodbye!" << endl;
                return 0; // Exit the program
            default:
                cout << "You have entered the wrong input. Try again!" << endl;
        }
    }
}

void calculateGPA() {
    int subjects;     
    cout << "\n •••••••• Calculating GPA ••••••••" << endl;
    cout << "Please tell the amount of subjects you want to calculate. (Max " << MAX_SUBJECTS << "): ";
    cin >> subjects; // Get number of subjects from user

    // Check if the number of subjects is valid
    if (subjects < 1 || subjects > MAX_SUBJECTS) {
        cout << "You can enter a maximum of " << MAX_SUBJECTS << " subjects. Please try again." << endl;
        return; // Exit if invalid
    }

    // Arrays used to store subject credit hours and grades
    float creditHour[MAX_SUBJECTS];
    float numbers[MAX_SUBJECTS];

    // Loop to get subject credit hours and grades from user
    for (int i = 0; i < subjects; i++) {
        cout << "Enter the number of credit hours for Subject " << i + 1 << ": ";
        cin >> creditHour[i];
        // Validate credit hours
        if (creditHour[i] < 0) {
            cout << "Credit hours cannot be negative. Please enter a valid number." << endl;
            return; // Exit if invalid
        }

        cout << "Enter the number earned in the subject " << i + 1 << " (0.0 to 4.0): ";
        cin >> numbers[i];
        // Validate grades
        if (numbers[i] < 0.0 || numbers[i] > 4.0) {
            cout << "Grades must be between 0.0 and 4.0. Please enter a valid number." << endl;
            return; // Exit if invalid
        }
    }

    float totalNumbers = 0;  // Variable to store total numbers earned in the subjects
    float totalCreditHour = 0; // Variable to store total credit hours

    for (int i = 0; i < subjects; i++) {
        totalNumbers += creditHour[i] * numbers[i]; // Calculate total numbers earned
        totalCreditHour += creditHour[i]; //
                // Sum of all credit hours
            }

            if (totalCreditHour == 0) {
                cout << "Credit hours cannot be zero. Please enter valid input." << endl;
                return; // Exit if credit hours is zero
            }

            float gpa = totalNumbers / totalCreditHour; // Calculate GPA
            cout << "Total GPA: " << gpa << endl; // Display GPA

            // Save the result to a file
            string result = "GPA: " + to_string(gpa);
            saveResultsToFile(result);
        }

        void calculateCGPA() {
            int semesters;
            cout << "\n****** CGPA Calculating ******" << endl;
            cout << "Enter the amount of semesters you want results for (Max " << MAX_SEMESTERS << "): ";
            cin >> semesters; // Get number of semesters from user

            // Check if the number of semesters is valid
            if (semesters < 1 || semesters > MAX_SEMESTERS) {
                cout << "You can enter a maximum of " << MAX_SEMESTERS << " semesters. Please try again." << endl;
                return; // Exit if invalid
            }

            // Array to store GPA of each semester
            float semesterGPA[MAX_SEMESTERS]; 

            for (int i = 0; i < semesters; i++) {
                cout << "Enter Semester " << i + 1 << " GPA: ";
                cin >> semesterGPA[i]; // Get GPA of each semester from user
                // Validate GPA
                if (semesterGPA[i] < 0.0 || semesterGPA[i] > 4.0) {
                    cout << "GPA must be between 0.0 and 4.0. Please enter a valid number." << endl;
                    return; // Exit if invalid
                }
            }

            float totalGPA = 0; // Variable to store total GPA
            for (int i = 0; i < semesters; i++) {
                totalGPA += semesterGPA[i]; // Sum of all GPA added to total GPA
            }

            float cgpa = totalGPA / semesters; // Calculate CGPA
            cout << "Your CGPA is: " << cgpa << endl; // Display CGPA

            // Save the result to a file
            string result = "CGPA: " + to_string(cgpa);
            saveResultsToFile(result);
        }

        void methodOfCalculating() {
            // Method used to calculate GPA & CGPA
            cout << "........ Method of Calculating GPA & CGPA .........." << endl;
            cout << "GPA = Sum of (CreditHour * number) / Total of Credit Hours" << endl;
            cout << "CGPA = Sum of GPA / Number of Semesters" << endl;
        }

        void saveResultsToFile(const string& result) {
            ofstream outFile("results.txt", ios::app); // Open file in append mode
            if (outFile.is_open()) {
                outFile << result << endl; // Write the result to the file
                outFile.close(); // Close the file
                cout << "Result saved to results.txt" << endl;
            } else {
                cout << "Unable to open file for writing." << endl;
            }
        }
        
        void loadResultsFromFile(string& result) {
            ifstream inFile("results.txt"); // Open file for reading
            if (inFile.is_open()) {
            string line;
                cout << "Previous results:" << endl;
                while (getline(inFile, line)) {
                    cout << line << endl; // Read and display each line
                }
              inFile.close(); // Close the file
            } else {
                cout << "Unable to open file for reading." << endl;
           }
}