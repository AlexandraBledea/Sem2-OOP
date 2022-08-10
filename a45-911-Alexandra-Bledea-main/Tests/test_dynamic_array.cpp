//
// Created by Alexandra on 3/23/2021.
//
#include "dynamic_array.h"
#include "test_dynamic_array.h"
#include <assert.h>

void Test_DynamicArray::TestClear() {
    DynamicArray<int>* DA = new DynamicArray<int>(2);
    DA->Add(1);
    DA->Add(2);
    DA->Add(3);
    assert(DA->GetSize() == 3);
    DA->Delete(0);
    DA->Delete(0);
    DA->Delete(0);
    assert(DA->GetSize() == 0);
    delete DA;
}

void Test_DynamicArray::TestResize() {
    DynamicArray<int>* DA = new DynamicArray<int>(2);
    DA->Add(1);
    DA->Add(2);
    DA->Add(3);
    assert(DA->GetSize() == 3);
    delete DA;
}

void Test_DynamicArray::TestDelete() {
    DynamicArray<int>* DA = new DynamicArray<int>(2);
    DA->Add(1);
    DA->Add(2);
    assert((*DA)[0] == 1);
    assert((*DA)[1] == 2);
    assert(DA->GetSize() == 2);
    DA->Delete(0);
    assert((*DA)[0] == 2);
    assert(DA->GetSize() == 1);
    delete DA;
}

void Test_DynamicArray::TestAdd() {
    DynamicArray<int>* DA = new DynamicArray<int>(2);
    DA->Add(1);
    assert((*DA)[0] == 1);
    DA->Add(2);
    assert((*DA)[1] == 2);
    delete DA;
}

void Test_DynamicArray::TestUpdate() {
    DynamicArray<int>* DA = new DynamicArray<int>(2);
    DA->Add(1);
    DA->Add(2);
    DA->Add(3);
    DA->Update(4, 1);
    assert((*DA)[1] == 4);
    delete DA;
}

void Test_DynamicArray::TestGetSize() {

    DynamicArray<int>* DA = new DynamicArray<int>(2);
    DA->Add(1);
    DA->Add(2);
    assert(DA->GetSize() == 2);
    DA->Delete(1);
    assert(DA->GetSize() == 1);
    DA->Delete(0);
    assert(DA->GetSize() == 0);
    delete DA;
}

void Test_DynamicArray::TestAllDynamicArray() {
    TestClear();
    TestResize();
    TestDelete();
    TestAdd();
    TestUpdate();
    TestGetSize();
}
