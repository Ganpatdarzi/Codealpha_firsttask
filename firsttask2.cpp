#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// Structure to store course information
struct Course {
    string courseName;
    int creditHours;
    string grade;
    float gradePoints;
};

// Function to convert letter grade to grade points
float getGradePoints(string grade) {
    if (grade == "A" || grade == "a") return 4.0;
    if (grade == "A-" || grade == "a-") return 3.7;
    if (grade == "B+" || grade == "b+") return 3.3;
    if (grade == "B" || grade == "b") return 3.0;
    if (grade == "B-" || grade == "b-") return 2.7;
    if (grade == "C+" || grade == "c+") return 2.3;
    if (grade == "C" || grade == "c") return 2.0;
    if (grade == "C-" || grade == "c-") return 1.7;
    if (grade == "D+" || grade == "d+") return 1.3;
    if (grade == "D" || grade == "d") return 1.0;
    if (grade == "F" || grade == "f") return 0.0;
    return -1; // Invalid grade
}

// Function to validate grade input
bool isValidGrade(string grade) {
    return getGradePoints(grade) != -1;
}

int main() {
    vector<Course> courses;
    int numCourses;
    float totalCreditHours = 0;
    float totalGradePoints = 0;
    
    cout << "\n=== SEMESTER CGPA CALCULATOR ===" << endl;
    
    // Get number of courses
    do {
        cout << "\nEnter the number of courses: ";
        cin >> numCourses;
        if (numCourses <= 0) {
            cout << "Please enter a valid number of courses!" << endl;
        }
    } while (numCourses <= 0);
    
    // Clear input buffer
    cin.ignore();
    
    // Input course details
    for (int i = 0; i < numCourses; i++) {
        Course course;
        cout << "\nCourse " << i + 1 << " Details:" << endl;
        
        cout << "Enter course name: ";
        getline(cin, course.courseName);
        
        do {
            cout << "Enter credit hours: ";
            cin >> course.creditHours;
            if (course.creditHours <= 0) {
                cout << "Please enter valid credit hours!" << endl;
            }
        } while (course.creditHours <= 0);
        
        do {
            cout << "Enter grade (A, A-, B+, B, B-, C+, C, C-, D+, D, F): ";
            cin >> course.grade;
            if (!isValidGrade(course.grade)) {
                cout << "Please enter a valid grade!" << endl;
            }
        } while (!isValidGrade(course.grade));
        
        course.gradePoints = getGradePoints(course.grade);
        courses.push_back(course);
        
        // Clear input buffer
        cin.ignore();
    }
    
    // Calculate total credit hours and grade points
    for (const Course& course : courses) {
        totalCreditHours += course.creditHours;
        totalGradePoints += (course.gradePoints * course.creditHours);
    }
    
    // Calculate CGPA
    float cgpa = totalGradePoints / totalCreditHours;
    
    // Display results
    cout << "\n=== SEMESTER RESULTS ===" << endl;
    cout << fixed << setprecision(2);
    cout << "\nCourse Details:" << endl;
    cout << setw(30) << left << "Course Name" 
         << setw(15) << "Credit Hours" 
         << setw(10) << "Grade" 
         << "Grade Points" << endl;
    cout << string(70, '-') << endl;
    
    for (const Course& course : courses) {
        cout << setw(30) << left << course.courseName 
             << setw(15) << course.creditHours 
             << setw(10) << course.grade 
             << course.gradePoints << endl;
    }
    
    cout << "\nSummary:" << endl;
    cout << "Total Credit Hours: " << totalCreditHours << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Semester CGPA: " << cgpa << endl;
    
    // Provide academic standing
    cout << "\nAcademic Standing: ";
    if (cgpa >= 3.7) cout << "Excellent";
    else if (cgpa >= 3.0) cout << "Very Good";
    else if (cgpa >= 2.3) cout << "Good";
    else if (cgpa >= 2.0) cout << "Satisfactory";
    else if (cgpa >= 1.0) cout << "Pass";
    else cout << "Fail";
    cout << endl;
    
    return 0;
}