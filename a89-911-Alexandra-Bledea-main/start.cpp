//
// Created by Alexandra on 3/17/2021.
//

#include <iostream>
#include "repository.h"
#include "dynamic_array.h"
#include "domain.h"
#include "validation.h"
#include "service.h"
#include "console.h"
#include <crtdbg.h>
#include <QApplication>
#include "test_domain.h"
#include "test_repository.h"
#include "test_dynamic_array.h"
#include "test_service.h"
#include "test_validation.h"
#include "FileRepository.h"
#include "GUI.h"
#include "AdminModeGUI/AdminModeGUI.h"
#include "UserModeGUI/UserModeGUI.h"
using namespace std;


int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    FileRepository repo(R"(C:\Users\Alexandra\Desktop\Facultate\Semestru 2\911\a89-911-Alexandra-Bledea\text.txt)");
    Repository UserRepo;
    Service service(repo, UserRepo);

//    Test_Domain T;
//    T.TestAllDomain();
//    Test_Repository R;
//    R.TestAllRepository();
//    Test_DynamicArray D;
//    D.TestAllDynamicArray();
//    Test_Service S;
//    S.TestAllService();
//    Test_Validation V;
//    V.TestAllValidation();

    GUI gui{service};
    gui.setStyleSheet("QMainWindow {background: 'pink';}");
//    AbstractShoppingBasket* abs;
//    UserModeGUI umg{service, abs};
//    umg.show();

    gui.show();

    return a.exec();

}

///INPUT WITH TOKENS
//M,Blue,100,20,https://www.morganclare.co.uk/images/luxe-blue-coat-p36372-114149_image.jpg
//S,Pink,200,24,https://images-na.ssl-images-amazon.com/images/I/71IismvKi3L._AC_UL1447_.jpg
//L,Red,150,13,https://res.cloudinary.com/wolfandbadger/image/upload/s--6lJSlYAP--/q_auto:eco/products/f8mgtgse6mnpsegyxrxo
//S,Pink,200,25,https://images-na.ssl-images-amazon.com/images/I/71IismvKi3L._AC_UL1447_.jpg
//S,Yellow,175,33,https://i.pinimg.com/originals/36/34/57/363457f4a8f758c43fab554e04de1038.jpg
//XL,Grey,100,24,https://cdn.shopify.com/s/files/1/0024/0697/3485/products/407A7456.jpg?v=1604310704
//XS,Magenta,400,10,https://i.pinimg.com/originals/6e/b1/a9/6eb1a9282acc0aeef06dd693ae0301d9.jpg
//XL,Purple,243,10,https://images-na.ssl-images-amazon.com/images/I/51W49L9WQ8L._AC_UX385_.jpg
//XS,Green,135,17,https://i.etsystatic.com/6811060/r/il/f9e28e/1977783236/il_570xN.1977783236_4xx9.jpg



///INPUT WITHOUT TOKENS
//M Blue 100 6 https://www.morganclare.co.uk/images/luxe-blue-coat-p36372-114149_image.jpg
//L Red 150 3 https://res.cloudinary.com/wolfandbadger/image/upload/s--6lJSlYAP--/q_auto:eco/products/f8mgtgse6mnpsegyxrxo
//S Pink 200 1 https://images-na.ssl-images-amazon.com/images/I/71IismvKi3L._AC_UL1447_.jpg
//S Yellow 175 10 https://i.pinimg.com/originals/36/34/57/363457f4a8f758c43fab554e04de1038.jpg
//L Black 305 2 https://media.mauvetree.com/wp-content/uploads/2018/04/Black-trench-coat-for-men.jpg
//XL Grey 100 4 https://cdn.shopify.com/s/files/1/0024/0697/3485/products/407A7456.jpg?v=1604310704
//XS Magenta 400 1 https://i.pinimg.com/originals/6e/b1/a9/6eb1a9282acc0aeef06dd693ae0301d9.jpg
//XS Green 135 3 https://i.etsystatic.com/6811060/r/il/f9e28e/1977783236/il_570xN.1977783236_4xx9.jpg
//XL Purple 243 10 https://images-na.ssl-images-amazon.com/images/I/51W49L9WQ8L._AC_UX385_.jpg
