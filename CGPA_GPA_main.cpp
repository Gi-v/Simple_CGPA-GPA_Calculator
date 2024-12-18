#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX_SUBJECTS = 10; // Maximum number of subjects. const usewd so it stores value as int and cant be changed later 
const int MAX_SEMESTERS = 8; // Maximum number of semesters

void calculateGPA();
void calculateCGPA();
void methodOfCalculating();
void saveResultsToFile(const string& result);
void loadResultsFromFile();
void helpFunction();
bool isNumeric(const string &input);

int main() {
    int input;
    string results,userInput;
    // Loop used to display the menu until the user chooses to exit
    while (true) {
        cout << "-------- GPA & CGPA Calculator ------- " << endl;
        cout << endl;
        cout << "  |------Menu------| \n" << endl;
        cout << "  1. Calculate GPA (Grade Point Average)" << endl;
        cout << "  2. Calculate CGPA (Cumulative Grade Point Average)" << endl;
        cout << "  3. Method to find GPA & CGPA" << endl;
        cout << "  4. Load calculated results" << endl;
        cout << "  5. How to perform the operation << endl;
        cout << "  6. Exit Application" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> userInput;

        if(!isNumeric(userInput)){
            cout << "Invalid input.Please enter a number between 1 and 4 \n "<<endl;
            continue;
        }
        input = stoi(userInput); // stoi for string to integer. Trys to convert userinput of string to input for switch function
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
                loadResultsFromFile();
                break;
                case 5:
                helpFunction();
                break;
            case 6;
            cout << "Exiting the application. Goodbye!" << endl;
                return 0; // Exit the program
            default:
                cout << "Invalid input.Please enter a number between 1 and 4 \n " << endl;
        }
    }
}

void calculateGPA() {
    int subjects;     
    cout << "\n ******** Calculating GPA ********" << endl;
    cout << "Please tell the amount of subjects you want to calculate. (Max " << MAX_SUBJECTS << "): ";
    cin >> subjects; // Get number of subjects from user

    // Check if the number of subjects is valid
    if (subjects < 1 || subjects > MAX_SUBJECTS) {
        cout << "You can enter a maximum of " << MAX_SUBJECTS << " subjects. Please try again." << endl;
        return; // Exit if invalid
    }

    // Arrays used to store subject credit hours and grades
    float creditHour[MAX_SUBJECTS]; // size of array is the max num of subjects
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
            string result = "GPA: " + to_string(gpa); // converts the numerical value of gpa to string using this
            saveResultsToFile(result); // saves results to the file
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
        
        void loadResultsFromFile() {
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
bool isNumeric(const string &input){
    for (char c : input) {
        if (c < '0' || c > '9') { // Check if any character is not a digit
            return false;
        }
    }
    return true;
}
void helpFunction() {
    cout << "\n******** Help Information ********" << endl;
    cout << "This application allows you to calculate your GPA (Grade Point Average) and CGPA (Cumulative Grade Point Average)." << endl;
    cout << "Here are some instructions on how to use the application:" << endl;
    cout << "1. Calculate GPA:" << endl;
    cout << "   - You will be prompted to enter the number of subjects." << endl;
    cout << "   - For each subject, enter the number of credit hours and the grade earned (between 0.0 and 4.0)." << endl;
    cout << "   - The application will calculate and display your GPA." << endl;
    cout << "   - The GPA will also be saved to a file for future reference." << endl;
    cout << endl;
    cout << "2. Calculate CGPA:" << endl;
    cout << "   - You will be prompted to enter the number of semesters." << endl;
    cout << "   - For each semester, enter the GPA earned (between 0.0 and 4.0)." << endl;
    cout << "   - The application will calculate and display your CGPA." << endl;
    cout << "   - The CGPA will also be saved to a file for future reference." << endl;
    cout << endl;
    cout << "3. Method to find GPA & CGPA:" << endl;
    cout << "   - This option will display the formulas used to calculate GPA and CGPA." << endl;
    cout << endl;
    cout << "4. Load calculated results:" << endl;
    cout << "   - This option will display previously saved GPA and CGPA results from the file." << endl;
    cout << endl;
    cout << "5. Clear saved results:" << endl;
    cout << "   - This option will clear all previously saved results from the file." << endl;
    cout << endl;
    cout << "6. Calculate Highest and Lowest GPA:" << endl;
    cout << "   - This option allows you to input multiple GPAs and find the highest and lowest among them." << endl;
    cout << endl;
    cout << "7. Exit Application:" << endl;
    cout << "   - This option will exit the application." << endl;
    cout << endl;
    cout << "Please follow the prompts carefully and enter valid data." << endl;
    cout << "************************************" << endl;
}
