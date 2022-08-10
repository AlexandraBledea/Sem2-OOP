#include <iostream>
#include <QApplication>
#include "PeopleRepo.h"
#include "BuildingsRepo.h"
#include "PersonWindow.h"
#include "Service.h"

int main(int argc, char** argv) {
    QApplication a(argc, argv);

    PeopleRepo peopleRepo;
    BuildingsRepo buildingsRepo;
    Service service(peopleRepo, buildingsRepo);
    vector<PersonWindow*> windows;
    for(int i = 0; i < peopleRepo.getAll().size(); i++){
//        srand(time(NULL));
//        int f1 = rand()%300+i;
//        int f2 = rand()%200+i;
//        int f3 = rand()%100+i;
        windows.push_back(new PersonWindow(service, peopleRepo.getAll()[i]));
    }

    return a.exec();
}
