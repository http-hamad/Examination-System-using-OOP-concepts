#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

string email;
string password;
string loggedInEmail;
const int MAX_QUESTIONS = 100;
const int MAX_OPTIONS = 4;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class User

{

protected:

    int user_id;
    string name;
    int role;
    

public:
   
    
    void showMainMenu()
    {
        cout << "\n\n    Welcome to FAST Examination system\n\n"
             << endl;
        cout << "1. Teacher Menu\n\n";
        cout << "2. Student Menu\n\n";
        cout << "3. Exit\n\n";
        cout << "Enter your choice: \n\n";
    }

    bool login(int role)
    {
        string fileName;
        string header;
        char ch;
        if (role == 1)
        {
            fileName = "teachers.csv";
            header = "Couses,Teachers,userEmail,userPassword";
        }
        else if (role == 2)
        {
            fileName = "students.csv";
            header = "Rollno,Names,userEmail,userPassword";
        }
        else
        {
            return false;
        }
        cout << "\n Please login first to view the menu\n\n";

        cout << "\nEnter your email: ";
        cin >> email;

        cout << "\nEnter your password: ";
        cin >> password;

        ifstream file(fileName);
        string line, userEmail, userPassword;

        
        if (!file.good())
        {
            cout << "\nError: " << fileName << " could not be opened." << endl;
            return false;
        }
        string fileHeader;
        getline(file, fileHeader);
        if (fileHeader != header)
        {
            cout << "\nError: " << fileName << " has an invalid header." << endl;
            return false;
        }

        while (getline(file, line))
        {
            stringstream ss(line);
            string userRollno, userName;
            getline(ss, userRollno, ',');
            getline(ss, userName, ',');
            getline(ss, userEmail, ',');
            getline(ss, userPassword, ',');

            if (userEmail == email && userPassword == password)
            {
                name = userName;
                password = userPassword;
                role = role;
                loggedInEmail = email;
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }
};









//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Teacher : public User

{

private:

    int teacher_id;

public:

    string qbank;

    void showTeacherMenu()
    {
        cout << "\n     Teacher Menu\n";
        cout << "\n1. View Question Bank\n";
        cout << "\n2. Create Quiz\n";
        cout << "\n3. View Quiz Analytics\n";
        cout << "\n4. View Attendance of the Students\n";
        cout << "\n5. Update password\n";
        cout << "\n6. Logout\n";
        cout << "\nEnter your choice: ";
    }
    
   

    void courses()
    {

        // 1
        if (email == "Ansa.Liyaqat@nu.edu.pk")
        {

            qbank = "pfbank.txt";

            ofstream file("pfbank.txt");
        }

        // 2
        else if (email == "Adil.Majeed@nu.edu.pk")
        {

            qbank = "oopbank.txt";

            ofstream file("oopbank.txt");
        }

        // 3
        else if (email == "Sehrish.Raza@nu.edu.pk")
        {

            qbank = "itcbank.txt";

            ofstream file("itcbank.txt");
        }

        // 4
        else if (email == "Hassan.Raza@nu.edu.pk")
        {

            qbank = "dsbank.txt";

            ofstream file("dsbank.txt");
        }

        // 5
        else if (email == "Muhammad.Ishtiaq@nu.edu.pk")
        {

            qbank = "aabank.txt";

            ofstream file("aabank.txt");
        }

        // 6
        else if (email == "Hasan.Mujtaba@nu.edu.pk")
        {

            qbank = "srebank.txt";

            ofstream file("srebank.txt");
        }

        // 7
        else if (email == "Naveed.Ahmad@nu.edu.pk")
        {

            qbank = "rmbank.txt";

            ofstream file("rmbank.txt");
        }

        // 8
        else if (email == "Khadija.Mahmood@nu.edu.pk")
        {

            qbank = "bdabank.txt";

            ofstream file("bdabank.txt");
        }

        // 9
        else if (email == "Saira.Qamar@nu.edu.pk")
        {

            qbank = "aibank.txt";

            ofstream file("aibank.txt");
        }

        // 10
        else if (email == "Asim.Sheikh@nu.edu.pk")
        {

            qbank = "dlbank.txt";

            ofstream file("dlbank.txt");
        }

        // 11
        else if (email == "Irfan.Shah@nu.edu.pk")
        {

            qbank = "dipbank.txt";

            ofstream file("dipbank.txt");
        }
    }

    //////////////////////////////////////////////////////
    void update_password()
    {
        cout << "\nEnter old password: ";
        string oldPassword;
        cin >> oldPassword;

        if (password != oldPassword)
        {
            cout << "\nError: Old password does not match the current password." << endl;
            return;
        }

        cout << "\nEnter new password: ";
        string newPassword;
        cin >> newPassword;

        cout << "\nRe-enter new password to confirm: ";
        string confirmPassword;
        cin >> confirmPassword;

        if (newPassword != confirmPassword)
        {
            cout << "\nError: Passwords do not match." << endl;
            return;
        }

        string fileName = "teachers.csv";
        string tempfileName = "temp.csv";
        string header = "Couses,Teachers,userEmail,userPassword";

        ifstream fileIn(fileName);
        ofstream fileOut(tempfileName);

     
        if (!fileIn.good())
        {
            cout << "\nError: " << fileName << " could not be opened." << endl;
            return;
        }
        string line, userEmail, userPassword;
        getline(fileIn, header);
        if (header != "Couses,Teachers,userEmail,userPassword")
        {
            cout << "\nError: " << fileName << " has an invalid header." << endl;
            return;
        }
       
        fileOut << header << endl;

        bool found = false;
        while (getline(fileIn, line))
        {
            stringstream ss(line);
            string courses, teachers;

            getline(ss, courses, ',');
            getline(ss, teachers, ',');
            getline(ss, userEmail, ',');
            getline(ss, userPassword, ',');

            if (userEmail == loggedInEmail)

            {
                found = true;
                cout << "\nUpdating password for user: " << userEmail << endl;
                fileOut << courses << "," << teachers << "," << userEmail << "," << newPassword << "\n";
            }
            else
            {
                fileOut << line << "\n";
            }
        }

        fileIn.close();
        fileOut.close();

        if (!found)
        {
            cout << "\nError: Record not found." << endl;
            return;
        }

        remove(fileName.c_str());
        rename(tempfileName.c_str(), fileName.c_str());

        cout << "\nPassword updated successfully." << endl;
    }


    void view_quiz_analytics(){

            cout<< "\n  ****Sorry, no analytics avaliable yet!!!****\n";

    }
};







//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Student : public User
{
private:
    int student_id;

public:
    

    void showStudentMenu()
    {
        cout << "\n     Student Menu\n";
        cout << "\n1. Please, Mark Your Attendance First\n";
        cout << "\n2. See the courses You're Registered in: \n";
        cout << "\n3. Attempt Quiz\n";
        cout << "\n4. View Result\n";
        cout << "\n5. Update password\n";
        cout << "\n6. Logout\n";
        cout << "\nEnter your choice: ";
    }



    void update_password()
    {
        cout << "\nEnter old password: ";
        string oldPassword;
        cin >> oldPassword;

        if (password != oldPassword)
        {
            cout << "\nError: Old password does not match the current password." << endl;
            return;
        }

        cout << "\nEnter new password: ";
        string newPassword;
        cin >> newPassword;

        cout << "\nRe-enter new password to confirm: ";
        string confirmPassword;
        cin >> confirmPassword;

        if (newPassword != confirmPassword)
        {
            cout << "\nError: Passwords do not match." << endl;
            return;
        }

        string fileName = "students.csv";
        string tempfileName = "temp.csv";
        string header = "Rollno,Names,userEmail,userPassword";

        ifstream fileIn(fileName);
        ofstream fileOut(tempfileName);

        
        if (!fileIn.good())
        {
            cout << "\nError: " << fileName << " could not be opened." << endl;
            return;
        }
        string line, userEmail, userPassword;
        getline(fileIn, header);
        if (header != "Rollno,Names,userEmail,userPassword")
        {
            cout << "\nError: " << fileName << " has an invalid header." << endl;
            return;
        }
        
        fileOut << header << endl;

        bool found = false;
        while (getline(fileIn, line))
        {
            stringstream ss(line);
            string Rollno, Names;

            getline(ss, Rollno, ',');
            getline(ss, Names, ',');
            getline(ss, userEmail, ',');
            getline(ss, userPassword, ',');

            if (userEmail == loggedInEmail)

            {
                found = true;
                cout << "\nUpdating password for user: " << userEmail << endl;
                fileOut << Rollno << "," << Names << "," << userEmail << "," << newPassword << "\n";
            }
            else
            {
                fileOut << line << "\n";
            }
        }

        fileIn.close();
        fileOut.close();

        if (!found)
        {
            cout << "\nError: Record not found." << endl;
            return;
        }

        remove(fileName.c_str());
        rename(tempfileName.c_str(), fileName.c_str());

        cout << "\nPassword updated successfully." << endl;
    }
};







//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Attendance
{


public:
    string student_name;
    string student_id;
    bool is_present;

void mark_attendance()
{
    ofstream file("attendance.csv", ios::app); 

    if (file.good())
    {
        cout << "\nEnter student name: ";
        cin.ignore();
        getline(cin, student_name);
        
        cout << "\nEnter student ID: ";
        cin >> student_id;

        cout << "\nEnter attendance status (1 for present, 0 for absent): ";
        cin >> is_present;

        file << student_name << "," << student_id << "," << is_present << "\n";
        cout << "\nAttendance marked successfully!" << endl;
    }
    else
    {
        cout << "\nFailed to open file for marking attendance!" << endl;
    }

    file.close();
}


    void view_attendance()
    {
        ifstream file("attendance.csv"); 
        string line;

        if (file.good())
        {
            cout << "\n      Attendance List:\n";
            while (getline(file, line))
            {
                istringstream dataStream(line);
                string name, id, present;

                getline(dataStream, name, ',');
                getline(dataStream, id, ',');
                getline(dataStream, present, ',');

                cout << "\nName: " << name << ", ID: " << id;
                cout << ", Present: " << (present == "1" ? "Yes" : "No") << endl;
            }
        }
        else
        {
            cout << "\nFailed to open file for viewing attendance!" << endl;
        }

        file.close();
    }
};







//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Course

{

public:

    vector<string> courses;

    void useTeacher(Teacher &teacher)
    {

        teacher.courses();

    }

    void view_registered_course()
    {
        ifstream file("course_data.csv"); 
        string line;

        if (file.good())
        {
            
            if (getline(file, line))
            {
                istringstream headerStream(line);
                string header;

                
                while (getline(headerStream, header, ','))
                {
                    courses.push_back(header);
                }
            }

            
            while (getline(file, line))
            {
                istringstream dataStream(line);
                string rollno, name, cheackemail, password;
                vector<int> courseMarks;
                vector<string> registeredCourses;

                
                getline(dataStream, rollno, ',');
                getline(dataStream, name, ',');
                getline(dataStream, cheackemail, ',');
                getline(dataStream, password, ',');

                
                int mark;
                while (dataStream >> mark)
                {
                    courseMarks.push_back(mark);

                    if (dataStream.peek() == ',')
                        dataStream.ignore();
                }

                
                if (cheackemail == email)
                {
                    
                    for (int i = 0; i < courseMarks.size(); i++)
                    {
                        if (courseMarks[i] == 1)
                        {
                            registeredCourses.push_back(courses[i + 4]);
                        }
                    }

                    
                    int numCourses = registeredCourses.size();
                    cout << endl << name << " is registered in " << numCourses << " course" << (numCourses > 1 ? "s" : "") << " which ";
                    if (numCourses == 1)
                    {
                        cout << "is ";
                    }
                    else
                    {
                        cout << "are ";
                    }

                    for (int i = 0; i < numCourses; i++)
                    {
                        cout << registeredCourses[i];
                        if (i != numCourses - 1)
                        {
                            cout << " and ";
                        }
                    }

                    cout << endl;
                }
            }
        }
        else
        {
            cout << "Failed to open file!" << endl;
        }

        file.close();
    }
};





//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Question
{
public:
    string id;
    string text;
    string* options[MAX_OPTIONS];
    int numOptions = 0;

    
};






///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Quiz : public Teacher
{
private:

    Student student;
    Question questions[MAX_QUESTIONS];
    string answer_key[MAX_QUESTIONS];
    string student_answers[MAX_QUESTIONS];
    int num_questions;
    Course courses;

public:


    void course()

    {
        courses.useTeacher(*this);
    }

    void view_question_bank()
    {
        ifstream file;

        if (email == "Ansa.Liyaqat@nu.edu.pk")
        {
            qbank = "pfbank.txt";
        }
        else if (email == "Adil.Majeed@nu.edu.pk")
        {
            qbank = "oopbank.txt";
        }
        else if (email == "Sehrish.Raza@nu.edu.pk")
        {
            qbank = "itcbank.txt";
        }
        else if (email == "Hassan.Raza@nu.edu.pk")
        {
            qbank = "dsbank.txt";
        }
        else if (email == "Muhammad.Ishtiaq@nu.edu.pk")
        {
            qbank = "aabank.txt";
        }
        else if (email == "Hasan.Mujtaba@nu.edu.pk")
        {
            qbank = "srebank.txt";
        }
        else if (email == "Naveed.Ahmad@nu.edu.pk")
        {
            qbank = "rmbank.txt";
        }
        else if (email == "Khadija.Mahmood@nu.edu.pk")
        {
            qbank = "bdabank.txt";
        }
        else if (email == "Saira.Qamar@nu.edu.pk")
        {
            qbank = "aibank.txt";
        }
        else if (email == "Asim.Sheikh@nu.edu.pk")
        {
            qbank = "dlbank.txt";
        }
        else if (email == "Irfan.Shah@nu.edu.pk")
        {
            qbank = "dipbank.txt";
        }

        file.open(qbank);
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                cout << line << endl;
            }
            file.close();
        }
        else
        {
            cout << "Question bank file not found." << endl;
        }
    }




void create_quiz() {
    ifstream file;
    int questionCount = 0;

    if (email == "Ansa.Liyaqat@nu.edu.pk") 
    {
        qbank = "pfbank.txt";
    }
     else if (email == "Adil.Majeed@nu.edu.pk") 
    {
        qbank = "oopbank.txt";
    }
     else if (email == "Sehrish.Raza@nu.edu.pk") 
    {
        qbank = "itcbank.txt";
    }
     else if (email == "Hassan.Raza@nu.edu.pk") 
    {
        qbank = "dsbank.txt";
    }
     else if (email == "Muhammad.Ishtiaq@nu.edu.pk") 
    {
        qbank = "aabank.txt";
    }
     else if (email == "Hasan.Mujtaba@nu.edu.pk") 
    {
        qbank = "srebank.txt";   
    }
     else if (email == "Naveed.Ahmad@nu.edu.pk") 
    {
        qbank = "rmbank.txt";
    }
     else if (email == "Khadija.Mahmood@nu.edu.pk") 
    {
        qbank = "bdabank.txt";
    }
     else if (email == "Saira.Qamar@nu.edu.pk") 
    {
        qbank = "aibank.txt";
    }
     else if (email == "Asim.Sheikh@nu.edu.pk") 
    {
        qbank = "dlbank.txt";
    }
     else if (email == "Irfan.Shah@nu.edu.pk") 
    {
        qbank = "dipbank.txt";
    }

    file.open(qbank);
    if (file.is_open()) {
        string line;
        string question;
        bool selectQuestion = false;
        string questionType;

        cout << "Select questions for the quiz:\n";

        ofstream quizfile("quiz.txt", ios::app); 

        while (getline(file, line)) 
        {
            if (line.empty()) 
            {
                if (selectQuestion) 
                {
                    char addQuestion;
                    cout << question << "\nAdd this question to the quiz? (y/n): ";
                    cin >> addQuestion;
                    if (addQuestion == 'y') {
                        quizfile << question << "\n\n";
                        cout << "Added question to the quiz.\n";

                        string answer;
                        if (questionType == "2efcde9") 
                        { // Multiple choice
                            cout << "Enter the correct option (1-4) for this question: ";
                            cin >> answer;
                        } 
                        
                        else if (questionType == "b94d27b") 
                        { // True/False
                            cout << "Enter the correct option (1-2) for this question: ";
                            cin >> answer;
                        } 
                        
                        else     if (questionType == "88f7ace") { // Descriptive
                        cout << "Enter the correct answer for this question: ";
                        cin.ignore(); 
                        getline(cin, answer); 
                    } 

                        
                        answer_key[questionCount] = answer;
                        questionCount++;
                        num_questions++;
                    }

                }
                selectQuestion = false;
                question.clear();
                continue;
            }

            if (line == "2efcde9" || line == "b94d27b" || line == "88f7ace") {
                selectQuestion = true;
                questionType = line;
            }

            if (selectQuestion) 
            {
                if (!question.empty()) {
                    question += "\n";
                }
                question += line;
            }
        }

        file.close();
        quizfile.close();
        cout << "Quiz creation completed.\n";
    }
    else {
        cout << "Question bank file not found." << endl;
    }
}


void attempt_quiz()
{
    ifstream quizFile("quiz.txt");
    if (quizFile.is_open()) 
    {
        string line;
        int questionIndex = -1;
        bool readingOptions = false;

        cout << "\n\n    Starting the quiz...\n\n";

        while (getline(quizFile, line)) 
        {
            if (line.empty()) 
            {
                questionIndex++;
                readingOptions = false;
                continue;
            } else {
                if (!readingOptions) {
                    // This line is a question ID
                    if (line == "2efcde9" || line == "b94d27b" || line == "88f7ace") {
                        questions[questionIndex].id = line;
                    } else {
                        // This line is a question text
                        questions[questionIndex].text = line;
                        if (questions[questionIndex].id == "88f7ace") {
                            questionIndex++;
                        } else {
                            readingOptions = true;
                        }
                    }
                } else {
                    // This line is an option
                    string optionText = line.substr(line.find(':') + 2); // Cut off "option dabfac4: "
                    questions[questionIndex].options[questions[questionIndex].numOptions] = new string(optionText);
                    questions[questionIndex].numOptions++;
                }
            }
        }

        quizFile.close();

        // the questions are stored in the 'questions' array
        for (int i = 0; i <= questionIndex; i++)
        {
            // Display the question and its options
            cout << "Question " << i + 1 << ": " << questions[i].text << "\n";

            for (int j = 0; j < questions[i].numOptions; j++)
            {
                cout << j + 1 << ". " << *questions[i].options[j] << "\n";
            }

            // Get the student's answer

            string answer;

            cout << "Enter your answer: ";
            if (i == 0) {
                cin.ignore();
            }
            getline(cin, answer);
            student_answers[i] = answer;

            // Skip a line after each input

            cout << "\n";
        }

        cout << "Quiz completed.\n";
    }
    else {
        cout << "Quiz file not found." << endl;
    }
}





void view_result()
{
    // answer key is stored in the 'answer_key' array
    int correct_answers = 0;
    for (int i = 0; i < num_questions; i++)
    {
        if (student_answers[i] == answer_key[i])
        {
            correct_answers++;
        }
    }
    int total_marks = correct_answers * 10; // each question carries 10 marks
    cout << "Total marks obtained: " << total_marks << "/" << num_questions * 10 << "\n";
}

};





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Result

{
private:
    int result_id;
    int student_id;
    int quiz_id;
    int marks_obtained;

public:
    // Constructor and other methods
    void save_result();
    void view_result();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////








int main()

{
    int choice;
    User user;
    Teacher teacher;
    Student student;
    Course course;
    Quiz quiz;
    Result result;
    Attendance attendance;

    while (true)

    {
        user.showMainMenu();
        cin >> choice;
        

        switch (choice)
        {
        case 1:
            if (user.login(1))
            {
                while (true)
                { ////////////////////////////////////////////////
                    teacher.showTeacherMenu();
                    cin >> choice;
                    

                    switch (choice)
                    {
                    case 1:
                        quiz.view_question_bank();
                        break;
                    case 2:
                        quiz.create_quiz();
                        break;
                    case 3:
                        teacher.view_quiz_analytics();
                        break;
                    case 4:
                        attendance.view_attendance();
                        break;
                    case 5:
                        teacher.update_password();
                        break;
                    case 6:
                        cout << "\nLogging out..." << endl;
                        break;

                    default:
                        cout << "Invalid choice! Please try again." << endl;
                        break;
                    }

                    if (choice == 6)
                    {
                        break;
                    }
                }
            }

            else
            {
                cout << "Invalid email or password. Please try again.\n";
            }
            break;

            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        case 2:
            if (user.login(2))
            {
                while (true)
                { ///////////////////////////////////////////
                    student.showStudentMenu();
                    cin >> choice;
                    
                    
                    switch (choice)
                    {
                    case 1:
                        attendance.mark_attendance();
                        break;
                    case 2:
                        course.view_registered_course();
                        break;
                    case 3:
                        quiz.attempt_quiz();
                        break;
                    case 4:
                        quiz.view_result();
                        break;
                    case 5:
                        student.update_password();
                        break;
                    case 6:
                        cout << "\nLogging out..." << endl;
                        break;
                    default:
                        cout << "\nInvalid choice! Please try again." << endl;
                        break;
                    }

                    if (choice == 6)
                    {
                        break;
                    }
                }
            }
            else
            {
                cout << "\nIncorrect email or password. Please try again.\n";
            }
            break;

            ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        case 3:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}
