#include <iostream>
#include <map>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
    int students = 0;
    cout << "How many students? ";
    cin >> students;

    cin.ignore();

    vector<string> names(students);
    vector<double> GPA(students);

    map<string, double> Grading
    {
        {"A+", 4}, {"A", 4}, {"A-", 3.7},
        {"B+", 3.3}, {"B", 3}, {"B-", 2.7},
        {"C+", 2.3}, {"C", 2}, {"C-", 1.7},
        {"D+", 1.3}, {"D", 1},
        {"F", 0}
    };

    for (int i = 0; i < students; ++i)
    {
        int subjects = 0, totalHours = 0;
        double totalGPA = 0;

        cout << "\nName: ";
        getline(cin, names[i]);

        cout << "How many subjects? ";
        cin >> subjects;

        vector<int> hours(subjects);
        vector<string> grades(subjects);

        cout << "Enter credit hours for " << subjects << " subjects: ";
        for (int j = 0; j < subjects; ++j)
        {
            cin >> hours[j];
            totalHours += hours[j];
        }

        cout << "Enter grades: ";
        for (int j = 0; j < subjects; ++j)
        {
            while (true)
            {
                cout << "Grade for subject " << j + 1 << ": ";
                cin >> grades[j];
                if (Grading.find(grades[j]) != Grading.end())
                {
                    break;
                }
                else
                {
                    cout << "Invalid grade. Please enter a valid grade.\n";
                }
            }
        }

        for (int j = 0; j < subjects; ++j)
        {
            totalGPA += Grading[grades[j]] * hours[j];
        }

        GPA[i] = totalGPA / totalHours;
    }

    for (int i = 0; i < students - 1; i++)
    {
        for (int j = 0; j < students - i - 1; j++)
        {
            if (GPA[j] < GPA[j + 1])
            {
                swap(GPA[j], GPA[j + 1]);
                swap(names[j], names[j + 1]);
            }
        }
    }

    cout << "\nStudent Name\tGPA\n";
    for (int i = 0; i < students; ++i)
    {
        cout << names[i] << "\t" << fixed << setprecision(2) << GPA[i] << endl;
    }

    ofstream outFile("Student_GPA_Report.txt");
    outFile << "Student Name\tGPA\n";
    for (int i = 0; i < students; i++)
    {
        outFile << names[i] << '\t' << fixed << setprecision(2) << GPA[i] << '\n';
    }
    outFile.close();
    cout << "\nResults saved to Student_GPA_Report.txt\n";

}
