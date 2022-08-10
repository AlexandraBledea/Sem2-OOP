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
#include <windows.h>
using namespace std;


int main(int argc, char* argv[])
{

    DynamicArray<Coat>* UserDA = new DynamicArray<Coat>(100);
    DynamicArray<Coat>* DA = new DynamicArray<Coat>(100);
    Repository* UserRepo = new Repository(UserDA);
    Repository* repo = new Repository(DA);
    repo->init_repository();
    Service* service = new Service(repo, UserRepo);
    Validator* validator = new Validator();
    Console* console = new Console(service, validator);


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
    console->Start();
    delete console;

    _CrtDumpMemoryLeaks();
    _CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_FILE );
    _CrtSetReportFile( _CRT_WARN, _CRTDBG_FILE_STDOUT );
    _CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_FILE );
    _CrtSetReportFile( _CRT_ERROR, _CRTDBG_FILE_STDOUT );
    _CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_FILE );
    _CrtSetReportFile( _CRT_ASSERT, _CRTDBG_FILE_STDOUT );

    return 0;

}

//    ShellExecute(NULL, "open", "http://google.net",
//                 NULL, NULL, SW_SHOWNORMAL);