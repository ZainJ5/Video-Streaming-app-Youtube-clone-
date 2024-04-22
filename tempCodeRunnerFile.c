#include <iostream>
using namespace std;


class User
{
private:
    string name;
    int age;
    string remail;
    string rpassword;
    string lemail;
    string lpassword;
    string checkusername;
    string checkpassword;
    int    emailline;
    int    nameline;
    int    rpin;
    string    totalbill;
    string subscription;
    bool   checkU=false;
    bool   checkP=false;
friend class Subscription;
friend void totalbill(User &u1);
public:
    User()
    {
      totalbill="0$";
      subscription="Standard Account";
    }
    void registration(string file)
    {
        cout << "Enter your name : ";
        cin >> name;
        cout << "Enter  your age : ";
        cin >> age;
        cout << "Enter Email : ";
        cin >> remail;
        cout << "Enter  Password : ";
        cin >> rpassword;
        cout << "Enter  Recovery 4 digit pin : ";
        cin >> rpin;
        // ofstream userdata("D:\\C++\\SpotifyClone.txt",ios::app);
        ofstream userdata(file,ios::app);
        if (userdata.is_open())
        {
            userdata << name<<endl;
            userdata << age<<endl;
            userdata << remail<<endl;
            userdata << rpassword<<endl;
            userdata << rpin<<endl;
            if (file=="D:\\C++\\User's Data.txt")
            {
            userdata << subscription<<endl;
            userdata << totalbill<<endl;
            }
            else
            userdata << 0 <<endl;
            

            cout << "\nRegistration Successful!!";
        }
        else
            cout << "Error while registring new user.Please TRY AGAIN!! ";
    }
    bool  login(string file){
        cout<<"Enter email : ";
        cin>>lemail;
        cout<<"Enter Password : ";
        cin>>lpassword;
        // ifstream readfile("D:\\C++\\SpotifyClone.txt");
        ifstream readfile(file);
        int line_number=0;
        while (getline(readfile,checkusername))
        {
            if (lemail==checkusername)
            {
                checkU=true;
                break;
            }
            line_number++;
        }
        emailline=line_number;
        line_number++;
        int currentline=0;
        readfile.seekg(0, ios::beg);
        if (checkU)
        {
            while (getline(readfile,checkpassword))
            {
                if (currentline==line_number)
                {
                    if (lpassword==checkpassword)
                    {
                    checkP=true;
                    } 
                }
                currentline++;
                
            }
        }
        readfile.clear();
        readfile .seekg(0, ios::beg);
        line_number=line_number-2;
       nameline =line_number;
        // cout<<line_number;
        currentline=1;
        string cname;
        while (getline(readfile,cname))
        {
            if (currentline==line_number)
            {
                name=cname;
            }
            if (currentline==line_number+1)
            {
                string sage=cname;
                age=stoi(sage);
            }
            
            currentline++;
        } 
        if ((checkU)  && (checkP))
        {
            cout<<"Login Successfull!!"<<endl;
            return true;
        }
        else if(!checkU){
            cout<<"User Not Found!!";
        }
        else {
            cout<<"Invalid Password!!";
        }
    }
    string getname(void){
        return name;
    }
    int getage(void){
        return age;
    }
     void changepassword(string file,string tempfile){
    string Srpin;
    string newpassword;
    cout << "Enter email : ";
    cin >> lemail;
    cout << "Enter Recovery Key : ";
    cin >> rpin;
    Srpin = to_string(rpin);
    // ifstream readfile("D:\\C++\\SpotifyClone.txt");
    ifstream readfile(file);
    int recoverykey = 0;
    while (getline(readfile, checkusername))
    {
        if (lemail == checkusername)
        {
            checkU = true;
            break;
        }
        recoverykey++;
    }
    readfile.seekg(0, ios::beg);
    recoverykey = recoverykey + 2;
    for (int i = 0; i <= recoverykey; i++)
    {
        getline(readfile, checkpassword);
        if (i==recoverykey)
        { 
        if (Srpin == checkpassword)
        {
            checkP = true;
            break;
        }
        }
    }
  
    // ofstream temp("D:\\C++\\temp.txt");
    ofstream temp(tempfile);
    readfile.seekg(0, ios::beg);
    if (!checkU)
    {
     cout<<"No User Found"<<endl;
     return;
    }
    if (!checkP)
    {
     cout << "Recovery Key Invalid!" << endl;
     return ; 
    }
    
    if ((checkU) && (checkP))
    {
        cout << "Enter New Password : ";
        cin >> newpassword;
        recoverykey = recoverykey;
            int cline = 0;
            string line;
            // ifstream readfile("D:\\C++\\SpotifyClone.txt");
            ifstream readfile(file);
            while (getline(readfile, line))
            {
                cline++;
                if (cline == recoverykey)
                {   
                    temp << newpassword << endl;
                }
                else
                    temp << line << endl;
            }
        cout << "Password Successfully Changed!!";
    }
    readfile.close();
    temp.close();
    // remove("D:\\C++\\SpotifyClone.txt");
    // rename("D:\\C++\\temp.txt", "D:\\C++\\SpotifyClone.txt");
    const char *ofile = file.c_str();
    const char *tfile = tempfile.c_str();
    remove(ofile);
    rename(tfile, ofile);
}
void deleteaccount(string file,string tempfile){
// ifstream readfile("D:\\C++\\SpotifyClone.txt");
// ofstream temp("D:\\C++\\temp.txt");
ifstream readfile(file);
ofstream temp(tempfile);
string dpass;
cout<<"Enter your password : ";
cin>>dpass;
if (!(dpass==lpassword))
{
cout<<"Authentication Failed!!"<<endl;
}
    cout<<"User authentication successful !!"<<endl;
    string temp1;
    cout<<"Account Deleted Successfully"<<endl;
    int deletestarting=nameline;
    int deleteending=nameline+6;
    int lineNumber=1;
    // cout<<"Delete Starting : "<<deletestarting<<endl;
    // cout<<"Delete Ending : "<<deleteending<<endl;
   while (getline(readfile, temp1)) {
        if (!(lineNumber >= deletestarting && lineNumber <= deleteending)) {
            temp << temp1 << endl;
        }
        lineNumber++; 
    }
    readfile.close();
    temp.close();
    // remove("D:\\C++\\SpotifyClone.txt");
    // rename("D:\\C++\\temp.txt", "D:\\C++\\SpotifyClone.txt");
   const char *oFile = file.c_str();
   const char *tFile = tempfile.c_str();
   remove(oFile);
   rename(tFile, oFile);

}
};

int main() {
    //THIS IS CODE TO CLONE YOUTUBE
    int choice;
    cout << "Youtube Clone" << endl;
    cout << "1.) Creator's Studio" << endl;
    cout << "2.) User's Screen" << endl;
    cout << "Enter your Choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            // Creator's Studio Menu
            cout << "Creators's Screen" << endl;
            cout << "&&-----MENU-----&&" << endl;
            cout << "1.) Register as a Creator" << endl;
            cout << "2.) Login" << endl;
            cout << "3.) Change Password" << endl;
            break;
        case 2:
            // User's Screen Menu
            int Uchoice;
            cout << "User Panel" << endl;
            cout << "&&-----MENU-----&&" << endl;
            cout << "1.) Register User" << endl;
            cout << "2.) Login" << endl;
            cout << "3.) Change Password" << endl;
            cin >> Uchoice;

            switch (Uchoice) {
                case 1:
                    // Register User 
                    break;
                case 2:
                    // Login 
                    int loginChoice;
                    bool loggedIn = login();   //Login Function will return boolean value for successful login
                    while (!loggedIn) {
                        cout << "1.) Play Video" << endl;
                        cout << "2.) Check Creators" << endl;
                        cout << "3.) Check Videos of Specific Creator" << endl;
                        cout << "4.) Recommended Videos" << endl;
                        cout << "5.) Like a Video" << endl;
                        cout << "6.) Comment on a Video" << endl;
                        cout << "7.) Create Playlist" << endl;
                        cout << "8.) Add Video to Playlist" << endl;
                        cout << "9.) Remove Video from Playlist" << endl;
                        cout << "10.) Edit Playlist" << endl;
                        cout << "11.) Delete Playlist" << endl;
                        cout << "12.) Check Total Bill" << endl;
                        cout << "13.) Check Account Type (Subscription Plan)" << endl;
                        cout << "14.) Change Subscription Plan" << endl;
                        cout << "15.) Logout" << endl;
                        cout << "16.) Delete Account" << endl;
                        cout << "Enter your choice: ";
                        cin >> loginChoice;

                        switch (loginChoice) {
                            case 1:
                                // Play video 
                                break;
                            case 2:
                                // Check Creators 
                                break;
                            case 3:
                                // Check Videos of Specific Creator 
                                break;
                            case 4:
                                // Recommended Videos functionality
                                break;
                            case 5:
                                // Like a Video 
                                break;
                            case 6:
                                // Comment on a Video 
                                break;
                            case 7:
                                // Create Playlist 
                                break;
                            case 8:
                                // Add Video to Playlist 
                                break;
                            case 9:
                                // Remove Video from Playlist 
                                break;
                            case 10:
                                // Edit Playlist 
                                break;
                            case 11:
                                // Delete Playlist 
                                break;
                            case 12:
                                // Check Total Bill 
                                break;
                            case 13:
                                // Check Account Type (Subscription Plan) 
                                break;
                            case 14:
                                // Change Subscription Plan 
                                break;
                            case 15:
                             //Logout 
                                loggedIn = true;
                                break;
                            case 16:
                                // Delete Account 
                                break;
                            default:
                                cout << "Invalid choice!" << endl;
                                break;
                        }
                    }
                    break;
                case 3:
                    // Change Password functionality
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
            }
            break;
        default:
            cout << "Invalid choice!! Exiting Program..." << endl;
            break;
    }
    return 0;
}
