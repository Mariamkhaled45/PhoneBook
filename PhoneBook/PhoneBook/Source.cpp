#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void welcomePrompts() {
    cout << "-------MENU-------" << endl;
    cout << "1- Add a New Contact" << endl;
    cout << "2- Show all Saved Contacts" << endl;
    cout << "3- Search for a Contact" << endl;
    cout << "4- Delete a Specific Contact" << endl;
    cout << "5- Update Existing Contact" << endl;
    cout << "6- Exit" << endl;
    cout << "Enter Your Choice : ";
}
char searchprompt() {
    char choice;
    cout << " Search Menu " << endl;
    cout << "==================" << endl;
    cout << " Select a method to search with : \n N-Name \n P-Phonenumber \n G-Gender \n E-Email \n";
    cin >> choice;
    cout << "===================" << endl;
    cout << " Enter what you search for : ";
}
void search_res(string firstname, string lastname, string number, string gender, string email) {
    cout << "First name : " << firstname << endl;
    cout << "Last name : " << lastname << endl;
    cout << "Phone number : " << number << endl;
    cout << "Gender : " << gender << endl;
    cout << "Email : " << email << endl;
    cout << " ___" << endl;
}
void srch() {
    ifstream try_file("C:\\Users\\pc\\source\\repos\\trying\\trying\\try.txt");

    string firstname, lastname, gender, number, email;
    char choice, gendervalue;
    string search;
    if (try_file.is_open()) {

        choice = searchprompt();

        if (choice == 'g' || choice == 'G') {
            cin >> gendervalue;
        }
        else {
            cin >> search;
        }

        cout << endl;
        cout << "==================" << endl;

        while (try_file >> firstname >> lastname >> number >> gender >> email) {

            switch (choice) {
            case 'N':
            case 'n':

                while ((firstname.find(search) != std::string::npos) ||
                    (lastname.find(search) != std::string::npos)) {

                    search_res(firstname, lastname, number, gender, email);

                    break;
                }
                break;
            case 'P':
            case 'p':

                while (number.find(search) != std::string::npos) {

                    search_res(firstname, lastname, number, gender, email);

                    break;
                }
                break;
            case 'g':
            case 'G':

                while (gender.find(gendervalue) != std::string::npos || gender.find(gendervalue - 32) != std::string::npos || gender.find(gendervalue + 32) != std::string::npos) {

                    search_res(firstname, lastname, number, gender, email);
                    break;
                }
                break;
            case 'E':
            case 'e':
                while (email.find(search) != std::string::npos) {

                    search_res(firstname, lastname, number, gender, email);
                    break;
                }
            }
        }
    }
    try_file.close();
}
void deletefunction(string searchvalue) {
    string Firstname, Lastname, Phonenumber, Gender, Email, Choice;
    char result;
    string Deletenumber;
    ifstream our;
    ofstream temp;
    our.open("C:\\Users\\pc\\source\\repos\\trying\\trying\\try.txt");
    temp.open("C:\\Users\\pc\\source\\repos\\trying\\trying\\try.txt");
    while (our >> Firstname >> Lastname >> Phonenumber >> Gender >> Email) {
        if (Firstname.find(searchvalue) != std::string::npos || (Lastname.find(searchvalue) != std::string::npos) ||
            (Gender.find(searchvalue) != std::string::npos) || (Phonenumber.find(searchvalue) != std::string::npos) ||
            (Email.find(searchvalue) != std::string::npos)) {
            cout << "This Contact is Already Saved" << endl;
            cout << "Would you like to delete this contact? (Y/N)" << endl;
            search_res(Firstname, Lastname, Phonenumber, Gender, Email);
            cin >> Choice;
            if (Choice == "y" || Choice == "Y") {
                Deletenumber = Phonenumber;
                break;
            }
        }
    }
    our.clear();
    our.seekg(0);
    while (our >> Firstname >> Lastname >> Phonenumber >> Gender >> Email) {
        if (Deletenumber != Phonenumber) {
            temp << Firstname << " " << Lastname << " " << Phonenumber << " " << Gender << " " << Email << endl;
        }
    }
    our.close();
    temp.close();
    remove("C:\\Users\\pc\\source\\repos\\trying\\trying\\try.txt");
    result = rename("C:\\Users\\pc\\source\\repos\\trying\\trying\\temp.txt", "C:\\Users\\pc\\source\\repos\\trying\\trying\\try.txt");
    if (result == 0)
        cout << " success";
    else
        cout << "failed";
}
int check(string searchvalue) {
    string name, gender, email, phonenumber, lastname;
    int found = 0;

    ifstream infile("E:\\c++\\phonebook\\phonebook.txt");
    while ((infile >> name >> lastname >> phonenumber >> gender >> email) && found == 0) {
        if (phonenumber == searchvalue) {
            cout << "This Contact is Already Saved:" << endl;
            search_res(name, lastname, phonenumber, gender, email);
            found = 1;
            break;
        }
    }
    infile.close();
    cout << found;
    return found;
}
void addcontact() {
    string Firstname, Lastname, Phonenumber, Email, Fn, L, P, G, E;
    char Gender, choice;
    ofstream phonebook;
    char result;

    cout << "Enter First Name: ";
    cin >> Firstname;
    cout << "Enter Last Name: ";
    cin >> Lastname;
    cout << "Enter number: ";
    cin >> Phonenumber;
    cout << "Enter gender (F/M): ";
    cin >> Gender;
    cout << "Enter E-mail: ";
    cin >> Email;

    if (check(Phonenumber) == 1) {
        cout << "would u like to replace it?";
        cin >> choice;
        if (choice == 'y') {
            ifstream myfile;
            ofstream temp;
            myfile.open("C:\\Users\\pc\\source\\repos\\trying\\trying\\try.txt");
            temp.open("c:\\c++\\trying\\temp.txt");
            while (myfile >> Fn >> L >> P >> G >> E) {
                if (P != Phonenumber) {
                    temp << Fn << " " << L << " " << P << " " << G << " " << E << endl;
                }
                else {
                    temp << Firstname << " " << Lastname << " " << Phonenumber << " " << Gender << " " << Email << endl;
                }
            }
            myfile.close();
            temp.close();
            remove("C:\\Users\\pc\\source\\repos\\trying\\trying\\try.txt");
            rename("C:\\Users\\pc\\source\\repos\\trying\\trying\\temp.txt", "C:\\Users\\pc\\source\\repos\\trying\\trying\\try.txt");



        }
    }
    else {
        phonebook.open("C:\\Users\\pc\\source\\repos\\trying\\trying\\try.txt", ios::app);
        phonebook << Firstname << " " << Lastname << " " << Phonenumber << " " << Gender << " " << Email << endl;
        phonebook.close();
    }
}
void display_contact() {
    string firstname, lastname, gender, number, email;
    ifstream infile("C:\\Users\\pc\\source\\repos\\trying\\trying\\try.txt");
    while (infile >> firstname >> lastname >> gender >> number >> email) {
        cout << "First name : " << firstname << endl;
        cout << "Last name : " << lastname << endl;
        cout << "Phone number : " << number << endl;
        cout << "Gender : " << gender << endl;
        cout << "Email : " << email << endl;
        cout << " ___" << endl;
    }
}
void update(string searchvalue) {
    string Firstname, Lastname, Phonenumber, Email;
    string updatefname, updatelname, updatephonenumber, updateemail;
    char Gender, updategender, Choice, choice2;
    string updatenumber;
    ifstream our;
    ofstream temp;
    our.open("C:\\Users\\pc\\source\\repos\\trying\\trying\\try.txt");
    temp.open("C:\\Users\\pc\\source\\repos\\trying\\trying\\temp.txt");
    while (our >> Firstname >> Lastname >> Phonenumber >> Gender >> Email) {
        if (Firstname.find(searchvalue) != std::string::npos || (Lastname.find(searchvalue) != std::string::npos) || (Phonenumber.find(searchvalue) != std::string::npos) ||
            (Email.find(searchvalue) != std::string::npos)) {
            search_res(Firstname, Lastname, Phonenumber, " " + Gender, Email);
            cin >> Choice;
            if (Choice == 'y' || Choice == 'Y') {
                updatenumber = Phonenumber;
                break;
            }
        }
    }
    cout << "Enter New Firstname" << endl;
    cin >> updatefname;
    cout << "Enter New Lastname" << endl;
    cin >> updatelname;
    cout << "Would you like to update the Phone number?";
    cin >> choice2;
    if (choice2 == 'y' || choice2 == 'Y') {
        cout << "Enter the New Phone number" << endl;
        cin >> updatephonenumber;
    }
    else {
        updatephonenumber = updatenumber;
    }
    cout << "Enter Gender" << endl;
    cin >> updategender;
    cout << "Enter New Email" << endl;
    cin >> updateemail;
    our.clear();
    our.seekg(0);
    while (our >> Firstname >> Lastname >> Phonenumber >> Gender >> Email) {
        if (updatenumber != Phonenumber) {
            temp << Firstname << " " << Lastname << " " << Phonenumber << " " << Gender << " " << Email << endl;
        }
        else {
            temp << updatefname << " " << updatelname << " " << updatephonenumber << " " << updategender << " " << updateemail;
        }

    }
    our.close();
    temp.close();
    remove("C:\\Users\\pc\\source\\repos\\trying\\trying\\try.txt");
    rename("C:\\Users\\pc\\source\\repos\\trying\\trying\\temp.txt", "C:\\Users\\pc\\source\\repos\\trying\\trying\\try.txt");
}
int main() {
    system("color f1");
    int option;
    string deletename;
    do {

        welcomePrompts();
        cin >> option;
        if (option > 6 || option < 0) {
            cout << "Invalid Option" << endl;
        }

        switch (option) {
        case 1:
            addcontact();
            break;
        case 2:
            display_contact();
            break;
        case 3:
            srch();
            break;
        case 4:
            cout << "Enter the value you want to delete: " << endl;
            cin >> deletename;
            deletefunction(deletename);
            break;
        case 5:
            cout << "Enter the value you want to update: " << endl;
            cin >> deletename;
            update(deletename);
            break;
        }
    } while (option != 6);
}