//
// Created by Alexandra on 3/2/2021.
//

#include "service.h"
#include "../undo_redo/repo_undo.h"
#include "repository.h"
#include "console.h"
#include <stdio.h>
#include <time.h>
#include <crtdbg.h>
#include <string.h>
#include "../tests/tests.h"
#include <stdlib.h>

int main()
{
    DynamicArray* DA = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    Repository new_repo;
    init_repo(repo);
    new_repo = duplicate_repo(repo);
    UndoRepo* UndoRedo = createUndoRepo(100, &new_repo);
    //UndoRepo* UndoRedo = createUndoRepo(100, repo);

    Service* service = createService(*repo, *UndoRedo);
    Console* console = createConsole(*service);
    start(console);
    //free(repo->data);
    destroy_ui(console);
    destroy_s(service);
    destroy_ur(UndoRedo);
    destroy_r(repo);
    destroy(DA);
//    for(int i = 0; i < UndoRedo->count; i++)
//        free(UndoRedo->data[i].data);
//    for(int i = 0; i < repo->count; i++)
//        free(repo->data);
    free(new_repo.array.data);


    testALL(); // the leaks come from here
    _CrtDumpMemoryLeaks();
    _CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_FILE );
    _CrtSetReportFile( _CRT_WARN, _CRTDBG_FILE_STDOUT );
    _CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_FILE );
    _CrtSetReportFile( _CRT_ERROR, _CRTDBG_FILE_STDOUT );
    _CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_FILE );
    _CrtSetReportFile( _CRT_ASSERT, _CRTDBG_FILE_STDOUT );



    return 0;
}
