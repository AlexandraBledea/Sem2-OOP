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
#include "test_domain.h"
#include "test_repository.h"
#include "test_dynamic_array.h"
#include "test_service.h"
#include "test_validation.h"
#include "FileRepository.h"
#include <vector>
using namespace std;


int main(int argc, char* argv[])
{

//    FileRepository UserRepo(R"(C:\Users\Alexandra\Desktop\Facultate\Semestru 2\911\a67-911-Alexandra-Bledea\text.txt)");
    FileRepository repo(R"(C:\Users\Alexandra\Desktop\Facultate\Semestru 2\911\a67-911-Alexandra-Bledea\text.txt)");
//    Repository repo;
    Repository UserRepo;
//    repo.init_repository();
//    repo.AddRepo("S", "Pink", 1, 1, "https://asghsaj.com");
    Service service(repo, UserRepo);
    Console console(service);


    Test_Domain T;
    T.TestAllDomain();
    Test_Repository R;
    R.TestAllRepository();
    Test_DynamicArray D;
    D.TestAllDynamicArray();
    Test_Service S;
    S.TestAllService();
    Test_Validation V;
    V.TestAllValidation();
    console.Start();


    _CrtDumpMemoryLeaks();
    _CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_FILE );
    _CrtSetReportFile( _CRT_WARN, _CRTDBG_FILE_STDOUT );
    _CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_FILE );
    _CrtSetReportFile( _CRT_ERROR, _CRTDBG_FILE_STDOUT );
    _CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_FILE );
    _CrtSetReportFile( _CRT_ASSERT, _CRTDBG_FILE_STDOUT );

    return 0;

}
