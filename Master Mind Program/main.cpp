#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

// Various User Defined Function

void add(); // add a record
void search(); // search a record
void list(); //display the record
void degree();//display the available programs
void del(); // delete the record
void modify(); // modify the record
void rec(); //scan the new record
void mainpage(); //starting page
int logscreen(); // login screen
void callExit(); // exit function
void menu(); // Main Menu
void Programs();//available Programs
void date(); // to get current date
void empty(); // used in deleting the record
void title(); // title bar
void about();// about the master mind

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

/*declaring structure*/

struct information
{
    char ID[15]; //Student ID
    char name[30]; //Student name
    char cls[10]; //program of Student
    char Branch[35]; //Branch of class
    char address[50]; //Address of Student
    char email[30]; //Email of Student
    char age[15]; //age Of a Student
    char phoneno[15]; //Phone No Of a Student
};
information c;
fstream fpt;

int main()
{
    system("cls");
    mainpage();
    logscreen();
    return 0;
}

void title()
{
    cout << "\n\n";
    cout << "\t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t\t\t\t\t-----------------------\n";
    cout << "\t\t\t\t\t\t\t\t\t|Master Mind institute|\n";
    cout << "\t\t\t\t\t\t\t\t\t-----------------------\n";
    cout << "\n";
    cout << "\t\t\t\t" << endl;
}

void mainpage()
{
    int process = 0;
    system("cls");
    //date();
    cout << "\n\n";
    cout << "\t\t\t\t\t\t -----------------------\n";
    cout << "\t\t\t\t\t\t |Master Mind Institute|\n";
    cout << "\t\t\t\t\t\t -----------------------\n";
    cout << "\n";
    cout << "\t\t\t\t" << endl;
    cout << "\t\t\t\t\t\    *********************************" << endl;
    cout << "\t\t\t\t\t\    **         Welcome All         **" << endl;
    cout << "\t\t\t\t\t\    *********************************" << endl;
    cout << "\n\n\n\n";
    cout << endl;
    cout << "\t\t\* We are delighted to have you here and look forward to helping you achieve" << endl;
    cout << "\t\t\t\   your professional goals through our training programs." << endl;
    cout << endl;
    cout << "\n";
    cout<< "\t\t* Press Enter to continue......"<<endl;
    cout << "\n\n";
    getchar();
    cout << "\t\t\t\tLoading";

    for (process = 0; process < 15; process++)
    {
        delay(150);
        cout << ".";
    }
}

int logscreen()
{
    char username[30];
    char password[30];
    int try01 = 0;
    int isTrue = 1;

    do
    {
        system("cls");
        cout << "\n\n\n\n" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t\t\t\t\t\t   ======= LOGIN =======\n" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
        cout << "\n\n\n\n" << endl;
        cout << "\t\t\t\t\tUsername: ";
        cin >> username;
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
        cout << "\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
        cout << "\t\t\t\t\tPassword: ";
        cin >> password;

        if (strcmp(username, "admin") == 0 && strcmp(password, "pass") == 0)
        {
            cout << "\n\n";
            cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\t\t\You have successfully logged in!\n" << endl;
            cout << "\t\t\t\t\t\Press Enter to continue...";
            fflush(stdin);
            getchar();
            menu();
            system("cls");
            getchar();
            isTrue = 0;
        }
        else
        {
            system("cls");
            try01 = try01 + 1;
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
            cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
            cout << "\t\t\t\t\t\t\t\tIncorrect username or password.\n" << endl;
            cout << "\t\t\t\t\t\t\t\tAttempts remaining: " << 3 - try01 << "\n" << endl;
            fflush(stdin);
            getchar();
            if (try01 >= 3)
            {
                cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
                cout << "\t\t\t\t\t\t\t\tNo permission to enter the system!\n" << endl;
                getchar();
                callExit();
                getchar();
            }
        }
    } while (isTrue == 1);
}

void menu()
{
    int input;
system("cls");
title();
cout << "\t\t==============================" << endl;
cout << "\t\t         MAIN MENU             " << endl;
cout << "\t\t==============================" << endl;
cout << "\t\t|    1. Enter new Student     |" << endl;
cout << "\t\t|----------------------------|" << endl;
cout << "\t\t|    2. Modify Student        |" << endl;
cout << "\t\t|----------------------------|" << endl;
cout << "\t\t|    3. Delete Student        |" << endl;
cout << "\t\t|----------------------------|" << endl;
cout << "\t\t|    4. Search and view Student|" << endl;
cout << "\t\t|----------------------------|" << endl;
cout << "\t\t|    5. View available Training|" << endl;
cout << "\t\t|       Programs              |" << endl;
cout << "\t\t|----------------------------|" << endl;
cout << "\t\t|    6. Log out               |" << endl;
cout << "\t\t|----------------------------|" << endl;
cout << "\t\t|    7. Exit                  |" << endl;
cout << "\t\t|----------------------------|" << endl;
cout << "\t\t|    8. About us              |" << endl;
cout << "\t\t==============================" << endl;
cout << "\t\tChoose an option [1-8]: ";
    fflush(stdin);
    cin >> input;
    switch (input)
    {
    case 1:
    {
        system("cls");
        add();
    }
    break;

    case 2:
    {
        system("cls");
        modify();
        getchar();
    }
    break;

    case 3:
    {
        system("cls");
        del();
    }
    break;

    case 4:
    {
        system("cls");
        search();
    }
    break;



    case 5:
    {
       system("cls");
       cout << "it" << endl;
       cout << "english" << endl;
        degree();
    }
    break;


    case 6:
        {
            system("cls");
            cout << "logging out" << endl;
            logscreen();

        }
        break;


    case 7:
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
        fflush(stdin);
        cout << "\t\t\t\t" << endl;
        cout << "Press Enter Again to Exit";
        cout << "\n\n\n\n";
        exit(0);
    }
    break;

    default:
    {
        fflush(stdin);
        cout << "\n\n\n";
        cout << "\t\t\t\t" << endl;
        cout << " Invalid input!";
        cout << "\n\n";
        cout << "\t\t\t\t" << endl;
        cout << "Press Enter to choose again...";
        getchar();
        menu();
                }
        break;

    case 8:
        {


            system("cls");

    cout << " " << endl;
    cout << "                +++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "                ++     Master Mind institute Of Sri Lanka.         ++" << endl;
    cout << "                +++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << " " << endl;
    cout << " Master Mind Institute is a renowned institution dedicated to providing employment-based " << endl;
    cout << " training programs for both local and international students. With a focus on professional  " << endl;
    cout << " development, they offer a wide range of courses including Red Hat certifications, Java " << endl;
    cout << " Programming, Web Development, and soft skills development. As a result of their high- " << endl;
    cout << " quality programs and industry relevance, the institute has experienced a significant surge in  " << endl;
    cout << " student enrollment inquiries. To address the increased workload on the marketing and" << endl;
    cout << " student administration departments, the management is actively seeking a solution that will " << endl;
    cout << " Programming, Web Development, and soft skills development. As a result of their high- " << endl;
    cout << " reduce employee stress, improve performance, and enhance customer satisfaction through " << endl;
    cout << " improved service delivery." << endl;
    cout << " " << endl;

            system("pause");
            menu();

        }
        break;
    }
    }


void add()
{
    char input;
    system("cls");
    cout << "\n\n";
    cout << "\t\t\t\t\t\t-----------------------------\n";
    cout << "\t\t\t\t\t\t|     Add New Student       |\n";
    cout << "\t\t\t\t\t\t-----------------------------\n";
    cout << "\n\n";
    cout << "\t\t\t\t\tEnter The Information Below:\n\n";
    cout << "\t\t\t\t\tEnter ID : ";
    fflush(stdin);
    cin >> c.ID;
    cout << "\n\n";
    cout << "\t\t\t\t\tFull Name : ";
    fflush(stdin);
    cin.ignore();
    cin.getline(c.name, 30);
    cout << "\n\n";
    cout << "\t\t\t\t\tProgram : ";
    fflush(stdin);
    cin.getline(c.cls, 10);
    cout << "\n\n";
    cout << "\t\t\t\t\tBranch : ";
    fflush(stdin);
    cin.getline(c.Branch, 35);
    cout << "\n\n";
    cout << "\t\t\t\t\tAddress : ";
    fflush(stdin);
    cin.getline(c.address, 50);
    cout << "\n\n";
    cout << "\t\t\t\t\tEmail Address : ";
    fflush(stdin);
    cin.getline(c.email, 30);
    cout << "\n\n";
    cout << "\t\t\t\t\tAge : ";
    fflush(stdin);
    cin >> c.age;
    cout << "\n\n";
    cout << "\t\t\t\t\tPhone No. : ";
    fflush(stdin);
    cin >> c.phoneno;
    fflush(stdin);
    fpt.open("data.txt", ios::out | ios::app);
    fpt.write((char*)&c, sizeof(c));
    fpt.close();
    cout << "\n\n";
    cout << "\t\t\t\t\tRecord added successfully!!";

    cout << "\n\n";
    cout << "\t\t\t\t\tDo you want to add more? (Y/N): ";
    cin >> input;
    if (input == 'Y' || input == 'y')
    {
        add();
    }
    else
        menu();
    getchar();
}


void about()
{
    system("cls");
    getchar();
    system("pause");
    menu();
}

void degree()
{
   system("cls");
   cout << "\n\n\n" << endl;
    cout << "\t\t\t\t\t" << endl;
    cout << " 1.BA (Hons) Human Resource Management " << endl;
    cout << "\n" << endl;
    cout << " 2.BSc (Hons) in Digital Banking and Finance " << endl;
    cout << "\n" << endl;
    cout << " 3.Bachelor of Intelligent Digital Technologies " << endl;
    cout << "\n" << endl;
    cout << " 4.Bachelor of Engineering (Honours) -Civil Engineering " << endl;
    cout << "\n" << endl;
    cout << " 5.BSc (Hons) Quantity Surveying & Commercial Management " << endl;
    cout << "\n" << endl;
    cout << " 6.BA (Hons) Professional Design (Visual Communication) " << endl;
    cout << "\n" << endl;
    getchar();
    system("pause");
    menu();
}


void callExit()
{
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
    cout << "\t\t\t\t\t" << endl;
    fflush(stdin);
    cout << "You are out of the System.";
    cout << "\n\n";
    cout << "\t\t\t\t" << endl;
    cout << " Press Enter to Continue Exit Program...";
    getchar();
    exit(0);
}

void search()
{
    int ch;
    char sid[30];
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
    cout << "\t\t\t\t\t" << endl;
    fflush(stdin);
    cout << "Enter Full Name: ";
    cin.ignore();
    cin.getline(sid, 30);

    fpt.open("data.txt", ios::in);
    while (fpt.read((char*)&c, sizeof(c)))
    {
        if (strcmp(sid, c.name) == 0)
        {
            ch = 1;
            break;
        }
    }
    if (ch == 1)
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n" << endl;
        cout << "\t\t\t\t\t" << endl;

        cout << "<<==Search Successful==>>";
        fflush(stdin);
        getchar();
        list(); //display the record
        cout << "\n\n\n";
        cout << "\t\t\t\t\t" << endl;
        cout << "Press Enter For Main Menu...";
        getchar();
        menu();
    }
    else
    {
        system("cls");
        getchar();
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
        cout << "\t\t\t\t\t" << endl;

        cout << "<<--Record Not Found-->>";
        cout << "\n\n\n";
        cout << "\t\t\t\t\t" << endl;
        cout << "Press Enter For Main Menu...";
        getchar();
        menu();
    }

    fpt.close();
}




void list()
{
    cout << " ";
    cout << "\n";
    cout << "\t\t\t\t" << endl;
    cout << "\t\t\t\t" << endl;
    cout << "\n";
    cout << "\t\t\t\t" << endl;
    cout << "\n";
    cout << "\t\t\t\t" << endl;

    cout << "\tID : " << c.ID << endl;
    cout << "\n\n";
    cout << "\t\t\t\t" << endl;
    cout << "Full Name : " << c.name;

    cout << "\n\n";
    cout << "\t\t\t\t" << endl;
    cout << "program : " << c.cls;

    cout << "\n\n";
    cout << "\t\t\t\t" << endl;
    cout << "Branch : " << c.Branch;

    cout << "\n\n";
    cout << "\t\t\t\t" << endl;
    cout << "Address : " << c.address;

    cout << "\n\n";
    cout << "\t\t\t\t" << endl;
    cout << "Email Address : " << c.email;

    cout << "\n\n";
    cout << "\t\t\t\t" << endl;
    cout<< "age. : "<<c.age;

    cout<<"\n\n";
    cout<<"\t\t\t\t"<<endl;
    cout<<"Phone No. : "<<c.phoneno;
}

void del()
{
    fstream temp;
    int ch = 0;
    char sid[30];
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<endl;
    cout<<"\t\t\t\t"<<endl;
    fflush(stdin);
    cout<<"Enter Full Name:";
    cin.ignore();
    cin.getline(sid, 30);
    fflush(stdin);
    fpt.open("data.txt", ios::in);
    temp.open("temp.txt", ios::out);
    while (fpt.read((char*)&c, sizeof(c)))
    {
        if (strcmp(sid, c.name) != 0)
        {
            temp.write((char*)&c, sizeof(c));
        }
        else
        {
            ch = 1;
        }
    }
    if (ch == 1)
    {
        cout << "\n";
        cout << "\t\t\t\t\t" << endl;
        cout << "Record Deleted Successfully.\n";
    }
    else
    {
        cout << "\n";
        cout << "\t\t\t\t\t" << endl;
        cout << "Record Not Found.\n";
    }
    cout << "\n";
    cout << "\t\t\t\t\t" << endl;
    cout << "Press Enter For Main Menu...";
    getchar();
    menu();
    fpt.close();
    temp.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");
}

void empty() {
    strcpy(c.ID," ");
    strcpy(c.name," ");
    strcpy(c.cls," ");
    strcpy(c.Branch," ");
    strcpy(c.address," ");
    strcpy(c.email," ");
    strcpy(c.age," ");
    strcpy(c.phoneno," ");
}

void modify()
{
    char mid[30];
    int found=0;
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "\t\t\t\t\t";
    std::cin.ignore();
    std::cout << "Enter Full Name: ";
    std::cin.getline(mid, 30);
    std::cin.ignore();
    std::ofstream temp("temp.txt");
    std::fstream fpt("data.txt", std::ios::in | std::ios::out);
    while(fpt.read((char*)&c, sizeof(c)))
    {
        if(strcmp(mid, c.name) == 0)
        {
            std::cin.ignore();
            system("cls");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
            std::cout << "\t\t\t\t\t";
            std::cout << "<<<==Old Record==>>>";
            std::cout << "\n";
            std::cout << "\t\t\t\t\t";
            list();
            std::cout << "\n\n";
            std::cout << "\t\t\t\t\t";
            std::cout << "Press Enter to modify the record...";
            getchar();
            system("cls");
            rec(); // this will ask to enter new record
            fpt.seekg(-sizeof(c), std::ios::cur);
            fpt.write((char*)&c, sizeof(c)); //The new name will be added to the record.
            found = 1;
            std::cout << "\n\n";
            std::cout << "\t\t\t\t\t";
            std::cout << "Record Saved !!!";
            getchar();
        }
        fpt.close();
        menu();
    }

    if(!found)
    {
        system("cls");
        delay(200);
        std::cin.ignore();
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        std::cout << "\t\t\t\t";
        std::cin.ignore();
        std::cout << "<<--Record Not Found-->>";
        std::cin.get();
        menu();
    }
    fpt.close();
}

void rec()
{
    std::cout << " ";
    std::cout << "\n";
    std::cout << "\t\t\t\t";
    std::cout << "\n";
    std::cout << "\t\t\t\t";
    std::cout << "\n";
    std::cout << "\t\t\t\t";
    std::cout << "\n";
    std::cout << "\n\n\n\n";
    std::cout << "\t\t\t\t";
    std::cout << "Enter The Information Below: \n\n";
    std::cout << "\t\t\t\t";
    std::cout << "\tID : " << c.ID << "\n\n";
    std::cout << "\t\t\t\t";
    std::cout << "Full Name : ";
    std::cin.ignore();
    std::cin.getline(c.name, sizeof(c.name));
    std::cout << "\n\n";
    std::cout << "\t\t\t\t";
    std::cout << "program : ";
    std::cin.getline(c.cls, sizeof(c.cls));
    std::cout << "\n\n";
    std::cout << "\t\t\t\t";
    std::cout << "Branch : ";
    std::cin.getline(c.Branch, sizeof(c.Branch));
    std::cout << "\n\n";
    std::cout << "\t\t\t\t";
    std::cout << "Address : ";
    std::cin.ignore();
    std::cin.getline(c.address, sizeof(c.address));
    std::cout << "\n\n\t\t\t\t";
    std::cout << "Email Address : ";
    std::cin.getline(c.email, sizeof(c.email));
    std::cout << "\n\n\t\t\t\t";
    std::cout << "age : ";
    std::cin.getline(c.age, sizeof(c.age));
    std::cout << "\n\n\t\t\t\t";
    std::cout << "Phone No. : ";
    std::cin.getline(c.phoneno, sizeof(c.phoneno));
    std::cin.ignore();
}
