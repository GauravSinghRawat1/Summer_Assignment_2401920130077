#include <bits/stdc++.h>
using namespace std;
class LibraryUser{
    public:
        virtual ~LibraryUser() = default;
        virtual void registerAccount() = 0;
        virtual void requestBook() = 0;
};
class KidUsers : public LibraryUser{
    public:
        int age;
        string bookType;
        KidUsers(int age, string bookType){
            this->age = age;
            this->bookType = bookType;
        }
        void registerAccount() override{
            if(age<=12){
                cout << "You have successfully registered into an Kids Account\n";
            } 
            else{
                cout << "Sorry, Age must be less than or equal to 12 to register as a kid\n";
            }
        }   
        void requestBook() override{
            if(bookType == "Fiction"){
                cout << "Book Issued successfully, please return the book within 10 days\n";
            }
            else{
                cout << "Oops, you are allowed to take only kids books\n"; 
            }
        }
};
class AdultUsers: public LibraryUser{
    public: 
        int age;
        string bookType;
        AdultUsers(int age, string bookType){
            this->age = age;
            this->bookType = bookType;
        }
        void registerAccount() override{
            if(age>12){
                cout << "You have successfully registered into an Adult Account\n";
            } 
            else{
                cout << "Sorry, Age must be greater than 12 to register as a Adult\n";
            }
        }   
        void requestBook() override{
            if(bookType == "Adult"){
                cout << "Book Issued successfully, please return the book within 7 days\n";
            }
            else{
                cout << "Oops, you are allowed to take only kids books\n"; 
            }
        }
};
int main(){
    KidUsers* kid1 = new KidUsers(10,"Kids");
    KidUsers* kid2 = new KidUsers(18,"Fiction");
    kid1->registerAccount();
    kid2->registerAccount();
    kid1->requestBook();
    kid2->requestBook();
    AdultUsers* adult1 = new AdultUsers(5,"Kids");
    AdultUsers* adult2 = new AdultUsers(23,"Fiction");
    adult1->registerAccount();
    adult2->registerAccount();
    adult1->requestBook();
    adult2->requestBook();

}