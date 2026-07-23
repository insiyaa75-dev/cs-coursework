#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Animal{

    protected:
        string name;
        int hunger;
        
    public:
        Animal(string n, int h) : name(n) , hunger(h){}
        virtual void makeSound() const = 0;
        virtual void feed() = 0;
        virtual ~Animal() {}
};

class Lion : public Animal{
    public:
        Lion(string n, int h ) : Animal(n,h){}
        void makeSound() const override{
            cout << "ROAR" << endl;
        };
        void feed() override {
            hunger -= 100;
            if(hunger<0){
                hunger = 0;
            }
            cout << hunger << endl;
        };
        ~Lion(){}
};

class Elephant : public Animal{
    public:
        Elephant(string n, int h ) : Animal(n,h){}
        void makeSound() const override{
            cout << "trumphet" << endl;
        };
        void feed() override {
            hunger -= 80;
            if(hunger<0){
                hunger = 0;
            }
            cout << hunger<< endl;
        };
        ~Elephant(){}
};

class Capybara : public Animal{
    public:
        Capybara(string n, int h ) : Animal(n,h){}
        void makeSound() const override{
            cout << "Bark" << endl;
        };
        void feed() override {
            hunger -= 30;
            if(hunger<0){
                hunger = 0;
            }
            cout << hunger << endl;
        };
        ~Capybara(){}
};

class Penguin : public Animal{
    public:
        Penguin(string n, int h ) : Animal(n,h){}
        void makeSound() const override{
            cout << "Honk" <<endl;
        };
        void feed() override {
            hunger -= 10;
            if (hunger<0){
                hunger = 0;
            }
            cout << hunger<< endl;
        };
        ~Penguin(){}
};

void print(){
    cout<< "Menu:" << endl;
    cout << "add" << endl;
    cout << "feedall" << endl;
    cout << "feedone" << endl;
    cout << "display" << endl;
    cout << "remove" << endl;
    cout << "exit" << endl;
}
int main(){
    vector<Animal*> zoo;
    print();

    while (true){

        string choice;
        cin >> choice;
        string name;
        int hunger;

        if (choice == "exit"){
            for (Animal* a : zoo) delete a;
            cout << "Goodbye" << endl;
            break;
        }

        else if(choice == "add"){
            char add_animal;
            cout << "initial of the animal you want to add" << endl;
            cin >> add_animal;
            cout << "name and starting hunger: ";
            cin >> name;
            cin >> hunger;
            if(add_animal == 'l')
                zoo.push_back(new Lion(name,hunger));
            else if(add_animal == 'e')
                zoo.push_back(new Elephant(name,hunger));
            else if(add_animal == 'p')
                zoo.push_back(new Penguin(name,hunger));
            else if (add_animal == 'c')
                zoo.push_back(new Capybara(name,hunger));
            else {cout << "Invalid type" << endl; 
                continue;} 
            }

        
        else if(choice == "display"){
            if (zoo.empty()){
                cout << "NO animals in the zoo" << endl;
                continue;
            }else{
                for (Animal* a : zoo){
                    a -> makeSound();
                }
            }
        }

        else if (choice == "feedall"){
            if (zoo.empty()){
                cout << "NO animals in the zoo" << endl;
                continue;
            }else{
                for(Animal* a : zoo){
                    a -> feed();
                }
            }
        }

        else if(choice == "feedone"){
            int idx;
            cout << "which animal do you want to feed? input the index" << endl;
            cin >> idx;
            if(idx >= zoo.size() || idx < 0 ){
                cout << "Zoo doesn't have that many animals" << endl;
                continue;
            }
            else{
                Animal* a = zoo[idx];
                a -> feed();
            }
        }

        else if (choice == "remove") {
            if (zoo.empty()) {
            cout << "Zoo is empty" << endl;
            continue;
        }
        cout << "Remove which index? ";
        int idx;
        cin >> idx;
        if (idx < 0 || idx >= zoo.size()) {
            cout << "Invalid index" << endl;
            continue;
        }
        delete zoo[idx];         
        zoo.erase(zoo.begin() + idx);
        }

        else{
            cout << "unknown" << endl;
            continue;
        }
    }
    return 0;
}