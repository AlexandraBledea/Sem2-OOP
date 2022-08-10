//
// Created by Alexandra on 3/12/2021.
//
#include <stdlib.h>
#include "tests.h"
#include "domain.h"
#include "repository.h"
#include "../undo_redo/repo_undo.h"
#include "../validation/validation.h"
#include "service.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

void test_createDynamicArray()
{
    DynamicArray* DA = createDynamicArray(100);
    assert(DA->count == 0);
    assert(DA->max_length == 100);
    destroy(DA);
}

void test_addTElem()
{
    Product p = createProduct("Banana", "fruit", 100, "11.12.2023");
    DynamicArray* array = createDynamicArray(100);
    add_TElem(array, p);
    assert(strcmp(array->data[0].name, "Banana") == 0);
    assert(strcmp(array->data[0].type, "fruit") == 0);
    assert(array->data[0].quantity == 100);
    assert(strcmp(array->data[0].date, "11.12.2023") == 0);
    destroy(array);

}

void test_delete_TELEM()
{
    Product p = createProduct("Banana", "fruit", 100, "11.12.2023");
    Product p2 = createProduct("Apple", "fruit", 100, "11.09.2023");
    DynamicArray* array = createDynamicArray(100);
    add_TElem(array, p);
    add_TElem(array, p2);
    assert(strcmp(array->data[0].name, "Banana") == 0);
    assert(strcmp(array->data[0].type, "fruit") == 0);
    assert(array->data[0].quantity == 100);
    assert(strcmp(array->data[0].date, "11.12.2023") == 0);
    delete_TElem(array, 0);
    assert(strcmp(array->data[0].name, "Apple") == 0);
    assert(strcmp(array->data[0].type, "fruit") == 0);
    assert(array->data[0].quantity == 100);
    assert(strcmp(array->data[0].date, "11.09.2023") == 0);
    destroy(array);

}

void test_update_TElem()
{
    Product p = createProduct("Banana", "fruit", 100, "11.12.2023");
    Product p2 = createProduct("Apple", "fruit", 100, "09.09.2040");
    DynamicArray* array = createDynamicArray(100);
    add_TElem(array, p);
    assert(strcmp(array->data[0].name, "Banana") == 0);
    assert(strcmp(array->data[0].type, "fruit") == 0);
    assert(array->data[0].quantity == 100);
    assert(strcmp(array->data[0].date, "11.12.2023") == 0);
    update_TElem(array, p2, 0);
    assert(strcmp(array->data[0].date, "09.09.2040") == 0);
    destroy(array);
}

void test_domain_getters()
{
    Product p = createProduct("Banana", "fruit", 100, "11.12.2023");
    assert(strcmp(getName(&p), "Banana") == 0);
    assert(strcmp(getType(&p), "fruit") == 0);
    assert(getQuantity(&p) == 100);
    assert(strcmp(getDate(&p), "11.12.2023") == 0);

}

void test_createProduct()
{
    Product p = createProduct("Banana", "fruit", 100, "11.12.2023");
    assert(strcmp(p.name, "Banana") == 0);
    assert(strcmp(p.type, "fruit") == 0);
    assert(p.quantity == 100);
    assert(strcmp(p.date, "11.12.2023") == 0);
}

void test_createRepo()
{
    DynamicArray* DA = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    init_repo(repo);
    assert(repo->array.max_length == 100);
    assert(repo->array.count == 10);
    assert(strcmp(repo->array.data[0].name, "Banana") == 0);
    assert(strcmp(repo->array.data[0].type, "fruit") == 0);
    assert(repo->array.data[0].quantity == 100);
    assert(strcmp(repo->array.data[0].date, "01.04.2022") == 0);
    destroy_r(repo);
    destroy(DA);
}

void test_assign_values()
{
    Product p = createProduct("Banana", "fruit", 100, "11.12.2023");
    Product new_p;
    assign_values(&new_p, p);
    assert(strcmp(p.name, new_p.name) == 0);
    assert(strcmp(p.type, new_p.type) == 0);
    assert(p.quantity == new_p.quantity);
    assert(strcmp(p.date, new_p.date) == 0);

}

void test_getCount()
{
    DynamicArray* DA = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    init_repo(repo);
    assert(getCount(repo) == 10);
    destroy_r(repo);
    destroy(DA);
}

void test_add_product_r()
{
    DynamicArray* DA = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    init_repo(repo);
    add_product_r(repo, "Strawberry", "fruit", 100, "11.12.2034");
    assert(strcmp(repo->array.data[10].name, "Strawberry") == 0);
    assert(strcmp(repo->array.data[10].type, "fruit") == 0);
    assert(repo->array.data[10].quantity == 100);
    assert(strcmp(repo->array.data[10].date, "11.12.2034") == 0);
    destroy_r(repo);
    destroy(DA);
}

void test_delete_product_r()
{
    DynamicArray* DA = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    init_repo(repo);
    assert(strcmp(repo->array.data[0].name, "Banana") == 0);
    assert(strcmp(repo->array.data[0].type, "fruit") == 0);
    assert(repo->array.data[0].quantity == 100);
    assert(strcmp(repo->array.data[0].date, "01.04.2022") == 0);
    assert(repo->array.count == 10);
    assert(delete_product_r(repo, "Banana", "fruit") == 1);
    assert(repo->array.count == 9);
    assert(strcmp(repo->array.data[0].name, "Apple") == 0);
    assert(strcmp(repo->array.data[0].type, "fruit") == 0);
    assert(repo->array.data[0].quantity == 50);
    assert(strcmp(repo->array.data[0].date, "01.04.2021") == 0);
    assert(delete_product_r(repo, "SoyaMilk", "dairy") == 0);
    destroy_r(repo);
    destroy(DA);

}

void test_update_products_quantity_r()
{
    DynamicArray* DA = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    init_repo(repo);
    assert(strcmp(repo->array.data[0].name, "Banana") == 0);
    assert(strcmp(repo->array.data[0].type, "fruit") == 0);
    assert(repo->array.data[0].quantity == 100);
    assert(strcmp(repo->array.data[0].date, "01.04.2022") == 0);
    update_products_quantity_r(repo, "Banana", "fruit", 999);
    assert(repo->array.data[0].quantity == 999);
    destroy_r(repo);
    destroy(DA);

}

void test_update_expiration_date_r()
{
    DynamicArray* DA = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    init_repo(repo);
    assert(strcmp(repo->array.data[0].name, "Banana") == 0);
    assert(strcmp(repo->array.data[0].type, "fruit") == 0);
    assert(repo->array.data[0].quantity == 100);
    assert(strcmp(repo->array.data[0].date, "01.04.2022") == 0);
    update_products_expiration_date_r(repo, "Banana", "fruit", "09.09.9999");
    assert(strcmp(repo->array.data[0].date, "09.09.9999") == 0);
    destroy_r(repo);
    destroy(DA);
}

void test_search_elements_by_string_r()
{
    DynamicArray* DA = createDynamicArray(100);
    DynamicArray* da = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    Repository* r = createRepo(*da);
    init_repo(repo);
    init_repo(r);
    delete_product_r(r, "Banana", "fruit");
    delete_product_r(r, "Apple", "fruit");
    delete_product_r(r, "Chicken", "meat");
    delete_product_r(r, "Pork", "meat");
    delete_product_r(r, "Chocolate", "sweets");
    delete_product_r(r, "Cake", "sweets");
    delete_product_r(r, "Milk", "dairy");
    delete_product_r(r, "Yogurt", "dairy");
    delete_product_r(r, "Cherry", "fruit");
    delete_product_r(r, "Cupcake", "sweets");
    search_elements_by_string_r(repo, "\n", r);
    assert(r->array.count == 10);
    delete_product_r(r, "Banana", "fruit");
    delete_product_r(r, "Apple", "fruit");
    delete_product_r(r, "Chicken", "meat");
    delete_product_r(r, "Pork", "meat");
    delete_product_r(r, "Chocolate", "sweets");
    delete_product_r(r, "Cake", "sweets");
    delete_product_r(r, "Milk", "dairy");
    delete_product_r(r, "Yogurt", "dairy");
    delete_product_r(r, "Cherry", "fruit");
    delete_product_r(r, "Cupcake", "sweets");
    search_elements_by_string_r(repo, "C\n", r);
    assert(r->array.count == 5);
    destroy_r(repo);
    destroy_r(r);
    destroy(DA);
    destroy(da);

}

void test_search_elements_by_category_r()
{
    DynamicArray* DA = createDynamicArray(100);
    DynamicArray* da = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    Repository* r = createRepo(*da);
    init_repo(repo);
    init_repo(r);
    delete_product_r(r, "Banana", "fruit");
    delete_product_r(r, "Apple", "fruit");
    delete_product_r(r, "Chicken", "meat");
    delete_product_r(r, "Pork", "meat");
    delete_product_r(r, "Chocolate", "sweets");
    delete_product_r(r, "Cake", "sweets");
    delete_product_r(r, "Milk", "dairy");
    delete_product_r(r, "Yogurt", "dairy");
    delete_product_r(r, "Cherry", "fruit");
    delete_product_r(r, "Cupcake", "sweets");
    assert(search_elements_by_category_r(repo, "fruit", r) == 1);
    assert(r->array.count == 3);
    delete_product_r(r, "Banana", "fruit");
    delete_product_r(r, "Apple", "fruit");
    delete_product_r(r, "Cherry", "fruit");
    delete_product_r(repo, "Banana", "fruit");
    delete_product_r(repo, "Apple", "fruit");
    delete_product_r(repo, "Cherry", "fruit");
    assert(search_elements_by_category_r(repo, "fruit", r) == 0);
    assert(r->array.count == 7);
    destroy_r(repo);
    destroy_r(r);
    destroy(DA);
    destroy(da);

}

void test_check_existence_product()
{
    DynamicArray* DA = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    init_repo(repo);
    assert(check_existence_product(repo, "Banana", "fruit") == 0);
    assert(check_existence_product(repo, "Capsuni", "fruit") == -1);
    destroy_r(repo);
    destroy(DA);

}

void test_duplicate_repo()
{
    DynamicArray* DA = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    init_repo(repo);
    Repository new_repo = duplicate_repo(repo);
    assert(strcmp(new_repo.array.data[0].name, repo->array.data[0].name) == 0);
    assert(strcmp(new_repo.array.data[0].type, repo->array.data[0].type) == 0);
    assert(new_repo.array.data[0].quantity == repo->array.data[0].quantity);
    assert(strcmp(new_repo.array.data[0].date, repo->array.data[0].date) == 0);
    assert(new_repo.array.count == repo->array.count);
    assert(new_repo.array.max_length == repo->array.max_length);
    free(new_repo.array.data);
    destroy_r(repo);
    destroy(DA);
}

void test_copy_repo()
{
    DynamicArray* DA = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    init_repo(repo);
    Repository new_repo;
    new_repo.array.max_length = repo->array.max_length;
    new_repo.array.count = repo->array.count;
    new_repo.array.data = (Product*) malloc(new_repo.array.max_length * sizeof(Product));
    copy_repo(repo, new_repo);
    assert(strcmp(new_repo.array.data[0].name, repo->array.data[0].name) == 0);
    assert(strcmp(new_repo.array.data[0].type, repo->array.data[0].type) == 0);
    assert(new_repo.array.data[0].quantity == repo->array.data[0].quantity);
    assert(strcmp(new_repo.array.data[0].date, repo->array.data[0].date) == 0);

    assert(strcmp(new_repo.array.data[1].name, repo->array.data[1].name) == 0);
    assert(strcmp(new_repo.array.data[1].type, repo->array.data[1].type) == 0);
    assert(new_repo.array.data[1].quantity == repo->array.data[1].quantity);
    assert(strcmp(new_repo.array.data[1].date, repo->array.data[1].date) == 0);
    destroy_r(repo);
    destroy(DA);
    free(new_repo.array.data);

}

void test_add_product_s()
{
    DynamicArray* DA = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    init_repo(repo);
    UndoRepo* UndoRedo = createUndoRepo(100, repo);
    Service* service = createService(*repo, *UndoRedo);

    add_product_s(service, "Strawberry", "fruit", 100, "11.12.2034");
    assert(strcmp(service->repo.array.data[10].name, "Strawberry") == 0);
    assert(strcmp(service->repo.array.data[10].type, "fruit") == 0);
    assert(service->repo.array.data[10].quantity == 100);
    assert(strcmp(service->repo.array.data[10].date, "11.12.2034") == 0);
    destroy_s(service);
    destroy_ur(UndoRedo);
    destroy_r(repo);
    destroy(DA);
}

void test_delete_product_s()
{
    DynamicArray* DA = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    init_repo(repo);
    UndoRepo* UndoRedo = createUndoRepo(100, repo);
    Service* service = createService(*repo, *UndoRedo);
    assert(strcmp(repo->array.data[0].name, "Banana") == 0);
    assert(strcmp(repo->array.data[0].type, "fruit") == 0);
    assert(repo->array.data[0].quantity == 100);
    assert(strcmp(repo->array.data[0].date, "01.04.2022") == 0);
    assert(delete_product_s(service, "Banana", "fruit") == 1);
    assert(strcmp(repo->array.data[0].name, "Apple") == 0);
    assert(strcmp(repo->array.data[0].type, "fruit") == 0);
    assert(repo->array.data[0].quantity == 50);
    assert(strcmp(repo->array.data[0].date, "01.04.2021") == 0);
    destroy_s(service);
    destroy_r(repo);
    destroy_ur(UndoRedo);
    destroy(DA);

}
void test_update_products_quantity_s()
{
    DynamicArray* DA = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    init_repo(repo);
    UndoRepo* UndoRedo = createUndoRepo(100, repo);
    Service* service = createService(*repo, *UndoRedo);
    assert(strcmp(repo->array.data[0].name, "Banana") == 0);
    assert(strcmp(repo->array.data[0].type, "fruit") == 0);
    assert(repo->array.data[0].quantity == 100);
    assert(strcmp(repo->array.data[0].date, "01.04.2022") == 0);
    assert(update_products_quantity_s(service, "Banana", "fruit", 999) == 1);
    assert(repo->array.data[0].quantity == 999);
    destroy_s(service);
    destroy_r(repo);
    destroy_ur(UndoRedo);
    destroy(DA);

}

void test_update_products_expiration_date_s()
{
    DynamicArray* DA = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    init_repo(repo);
    UndoRepo* UndoRedo = createUndoRepo(100, repo);
    Service* service = createService(*repo, *UndoRedo);
    assert(strcmp(repo->array.data[0].name, "Banana") == 0);
    assert(strcmp(repo->array.data[0].type, "fruit") == 0);
    assert(repo->array.data[0].quantity == 100);
    assert(strcmp(repo->array.data[0].date, "01.04.2022") == 0);
    assert(update_products_expiration_date_s(service, "Banana", "fruit", "09.09.9999") == 1);
    assert(strcmp(repo->array.data[0].date, "09.09.9999") == 0);
    destroy_s(service);
    destroy_r(repo);
    destroy_ur(UndoRedo);
    destroy(DA);
}

void test_sort_function_name()
{
    DynamicArray* DA = createDynamicArray(100);
    DynamicArray* da = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    Repository* R = createRepo(*da);
    add_product_r(R, "Apple", "fruit", 50, "01.04.2021");
    add_product_r(R, "Banana", "fruit", 100, "01.04.2022");
    add_product_r(R, "Cake", "sweets", 124, "18.03.2021");
    add_product_r(R, "Cherry", "fruit", 150, "01.04.2022");
    add_product_r(R, "Chicken", "meat", 10, "16.03.2022");
    add_product_r(R, "Chocolate", "sweets", 70, "06.09.2021");
    add_product_r(R, "Cupcake", "sweets", 70, "18.03.2021");
    add_product_r(R, "Milk", "dairy", 3, "16.06.2021");
    add_product_r(R, "Pork", "meat", 40, "16.03.2023");
    add_product_r(R, "Yogurt", "dairy", 5, "16.06.2021");
    init_repo(repo);
    UndoRepo* UndoRedo = createUndoRepo(100, repo);
    Service* service = createService(*repo, *UndoRedo);
    sort_function_name(service, repo);
    for(int i = 0; i < R->array.count; i++)
    {
        assert(strcmp(R->array.data[i].name, repo->array.data[i].name) == 0);
        assert(strcmp(R->array.data[i].type, repo->array.data[i].type) == 0);
        assert(R->array.data[i].quantity == repo->array.data[i].quantity);
        assert(strcmp(R->array.data[i].date, repo->array.data[i].date) == 0);
    }
    destroy_s(service);
    destroy_r(repo);
    destroy_r(R);
    destroy_ur(UndoRedo);
    destroy(DA);
    destroy(da);
}

void test_sort_function_quantity()
{
    DynamicArray* DA = createDynamicArray(100);
    DynamicArray* da = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    Repository* R = createRepo(*da);
    add_product_r(R, "Milk", "dairy", 3, "16.06.2021");
    add_product_r(R, "Yogurt", "dairy", 5, "16.06.2021");
    add_product_r(R, "Chicken", "meat", 10, "16.03.2022");
    add_product_r(R, "Pork", "meat", 40, "16.03.2023");
    add_product_r(R, "Apple", "fruit", 50, "01.04.2021");
    add_product_r(R, "Chocolate", "sweets", 70, "06.09.2021");
    add_product_r(R, "Cupcake", "sweets", 70, "18.03.2021");
    add_product_r(R, "Banana", "fruit", 100, "01.04.2022");
    add_product_r(R, "Cake", "sweets", 124, "18.03.2021");
    add_product_r(R, "Cherry", "fruit", 150, "01.04.2022");
    init_repo(repo);
    UndoRepo* UndoRedo = createUndoRepo(100, repo);
    Service* service = createService(*repo, *UndoRedo);
    sort_function_quantity(service, repo);
    for(int i = 0; i < R->array.count; i++)
    {
        assert(strcmp(R->array.data[i].name, repo->array.data[i].name) == 0);
        assert(strcmp(R->array.data[i].type, repo->array.data[i].type) == 0);
        assert(R->array.data[i].quantity == repo->array.data[i].quantity);
        assert(strcmp(R->array.data[i].date, repo->array.data[i].date) == 0);
    }
    destroy_s(service);
    destroy_r(repo);
    destroy_r(R);
    destroy_ur(UndoRedo);
    destroy(DA);
    destroy(da);
}

void test_search_elements_by_string_s()
{
    DynamicArray* DA = createDynamicArray(100);
    DynamicArray* da = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    Repository* r = createRepo(*da);
    init_repo(repo);
    init_repo(r);
    int criteria = 1;
    UndoRepo* UndoRedo = createUndoRepo(100, repo);
    Service* service = createService(*repo, *UndoRedo);
    delete_product_r(r, "Banana", "fruit");
    delete_product_r(r, "Apple", "fruit");
    delete_product_r(r, "Chicken", "meat");
    delete_product_r(r, "Pork", "meat");
    delete_product_r(r, "Chocolate", "sweets");
    delete_product_r(r, "Cake", "sweets");
    delete_product_r(r, "Milk", "dairy");
    delete_product_r(r, "Yogurt", "dairy");
    delete_product_r(r, "Cherry", "fruit");
    delete_product_r(r, "Cupcake", "sweets");
    search_elements_by_string_s(service, "\n", r, criteria);
    assert(r->array.count == 10);
    delete_product_r(r, "Banana", "fruit");
    delete_product_r(r, "Apple", "fruit");
    delete_product_r(r, "Chicken", "meat");
    delete_product_r(r, "Pork", "meat");
    delete_product_r(r, "Chocolate", "sweets");
    delete_product_r(r, "Cake", "sweets");
    delete_product_r(r, "Milk", "dairy");
    delete_product_r(r, "Yogurt", "dairy");
    delete_product_r(r, "Cherry", "fruit");
    delete_product_r(r, "Cupcake", "sweets");
    search_elements_by_string_s(service, "C\n", r, criteria);
    assert(r->array.count == 5);
    destroy_r(repo);
    destroy_r(r);
    destroy_s(service);
    destroy_ur(UndoRedo);
    destroy(DA);
    destroy(da);

}

void test_search_elements_by_category_s()
{
    DynamicArray* DA = createDynamicArray(100);
    DynamicArray* da = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    Repository* r = createRepo(*da);
    init_repo(repo);
    init_repo(r);
    int number_of_days = 17;
    UndoRepo* UndoRedo = createUndoRepo(100, repo);
    Service* service = createService(*repo, *UndoRedo);
    delete_product_r(r, "Banana", "fruit");
    delete_product_r(r, "Apple", "fruit");
    delete_product_r(r, "Chicken", "meat");
    delete_product_r(r, "Pork", "meat");
    delete_product_r(r, "Chocolate", "sweets");
    delete_product_r(r, "Cake", "sweets");
    delete_product_r(r, "Milk", "dairy");
    delete_product_r(r, "Yogurt", "dairy");
    delete_product_r(r, "Cherry", "fruit");
    delete_product_r(r, "Cupcake", "sweets");
    assert(search_elements_by_category_s(service, "fruit", r, number_of_days) == 2);
    assert(r->array.count == 1);
    number_of_days = 373;
    delete_product_r(r, "Apple", "fruit");
    assert(search_elements_by_category_s(service, "fruitsss", r, number_of_days) == 1);
    assert(r->array.count == 1);
    delete_product_r(r, "Chicken", "meat");
    number_of_days = 372;
    assert(search_elements_by_category_s(service, "fruitsss", r, number_of_days) == 0);
    assert(r->array.count == 0);
    destroy_r(repo);
    destroy_r(r);
    destroy_s(service);
    destroy_ur(UndoRedo);
    destroy(DA);
    destroy(da);
}

void test_compute_number_days_between_two_dates()
{
    DynamicArray* DA = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    init_repo(repo);
    UndoRepo* UndoRedo = createUndoRepo(100, repo);
    Service* service = createService(*repo, *UndoRedo);

    char date1[10] = "16.03.2022";
    assert(compute_number_days_between_two_dates(service, date1) == 373);
    char date2[10] = "17.03.2021";
    assert(compute_number_days_between_two_dates(service, date2) == 2);
    char date3[10] = "18.05.2021";
    assert(compute_number_days_between_two_dates(service, date3) == 65);
    char date4[10] = "15.03.2022";
    assert(compute_number_days_between_two_dates(service, date4) == 372);
    char date5[10] = "18.03.2022";
    assert(compute_number_days_between_two_dates(service, date5) == 375);
    char date6[10] = "13.03.2022";
    assert(compute_number_days_between_two_dates(service, date6) == 370);
    char date7[10] = "15.02.2022";
    assert(compute_number_days_between_two_dates(service, date7) == 341);

    destroy_r(repo);
    destroy_s(service);
    destroy_ur(UndoRedo);
    destroy(DA);
}

void test_copy_repo_service()
{
    DynamicArray* DA = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    init_repo(repo);
    UndoRepo* UndoRedo = createUndoRepo(100, repo);
    Service* service = createService(*repo, *UndoRedo);
    add_product_s(service, "Capsuni", "fruit", 100, "11.12.2022");
    UndoOperation(UndoRedo);
    copy_repo_service(service, UndoRedo);

    assert(strcmp(repo->array.data[0].name, "Banana") == 0);
    assert(strcmp(repo->array.data[0].type, "fruit") == 0);
    assert(repo->array.data[0].quantity == 100);
    assert(strcmp(repo->array.data[0].date, "01.04.2022") == 0);

    destroy_r(repo);
    destroy_s(service);
    destroy_ur(UndoRedo);
    destroy(DA);
}

void test_createUndoRepo()
{
    DynamicArray* DA = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    init_repo(repo);
    UndoRepo* UndoRedo = createUndoRepo(100, repo);
    assert(UndoRedo->max_length == 100);
    assert(UndoRedo->count == 0);
    assert(UndoRedo->current_position == 0);
    assert(UndoRedo->total_operations == 0);
    destroy_r(repo);
    destroy_ur(UndoRedo);
    destroy(DA);

}

void test_add_repo_ur()
{
    DynamicArray* DA = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    Repository new_repo;
    init_repo(repo);
    new_repo = duplicate_repo(repo);
    UndoRepo* UndoRedo = createUndoRepo(100, &new_repo);
    Service* service = createService(*repo, *UndoRedo);
    add_product_s(service, "Capsuni", "fruit", 100, "11.12.2022");
//
//    for(int i = 0; i < repo->array.count; i++)
//    {
//        assert(strcmp(UndoRedo->data[UndoRedo->current_position].array.data[i].name, repo->array.data[i].name) == 0);
//        assert(strcmp(UndoRedo->data[UndoRedo->current_position].array.data[i].type, repo->array.data[i].type) == 0);
//        assert(UndoRedo->data[UndoRedo->current_position].array.data[i].quantity ==  repo->array.data[i].quantity);
//        assert(strcmp(UndoRedo->data[UndoRedo->current_position].array.data[i].date, repo->array.data[i].date) == 0);
//    }

    destroy_s(service);
    destroy_ur(UndoRedo);
    destroy_r(repo);
    destroy(DA);
    free(new_repo.array.data);
}

void test_UndoOperation()
{
    DynamicArray* DA = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    init_repo(repo);
    UndoRepo* UndoRedo = createUndoRepo(100, repo);
    UndoRedo->current_position++;
    assert(UndoOperation(UndoRedo) == 1);
    assert(UndoOperation(UndoRedo) == 0);
    destroy_r(repo);
    destroy(DA);
    destroy_ur(UndoRedo);
}

void test_RedoOperation()
{
    DynamicArray* DA = createDynamicArray(100);
    Repository* repo = createRepo(*DA);
    init_repo(repo);
    UndoRepo* UndoRedo = createUndoRepo(100, repo);
    UndoRedo->total_operations++;
    assert(RedoOperation(UndoRedo) == 1);
    assert(RedoOperation(UndoRedo) == 0);
    destroy_r(repo);
    destroy_ur(UndoRedo);
    destroy(DA);
}

void test_validate_product_name()
{
    char name[100] = "";
    assert(validate_product_name(name) == 0);
    char name2[100] = "1Ale24";
    assert(validate_product_name(name2) == 0);
    char name3[100] = "Ale";
    assert(validate_product_name(name3) == 1);
}

void test_validate_product_quantity()
{
    char quantity[100] = "";
    assert(validate_product_quantity(quantity) == 0);
    char quantity1[100] = "001";
    assert(validate_product_quantity(quantity1) == 0);
    char quantity2[100] = "100A";
    assert(validate_product_quantity(quantity2) == 0);
    char quantity3[100] = "0";
    assert(validate_product_quantity(quantity3) == 0);
    char quantity4[100] = "123";
    assert(validate_product_quantity(quantity4) == 123);
}

void test_validate_product_type()
{
    char type[100] = "fruit";
    assert(validate_product_type(type) == 1);
    char type1[100] = "fruits";
    assert(validate_product_type(type1) == 0);
}

void test_validate_expiration_date()
{
    char date1[100] = "10.10.11111";
    assert(validate_expiration_date(date1) == 0);
    char date2[100] = "10/10.1111";
    assert(validate_expiration_date(date2) == 0);
    char date3[100] = "10.10/1111";
    assert(validate_expiration_date(date3) == 0);
    char date4[100] = "00.10.2022";
    assert(validate_expiration_date(date4) == 0);
    char date5[100] = "11.00.2022";
    assert(validate_expiration_date(date5) == 0);
    char date6[100] = "11.11.0000";
    assert(validate_expiration_date(date6) == 0);
    char date7[100] = "32.11.2022";
    assert(validate_expiration_date(date7) == 0);
    char date8[100] = "12.13.2022";
    assert(validate_expiration_date(date8) == 0);
    char date9[100] = "12.13.2020";
    assert(validate_expiration_date(date9) == 0);
    char date10[100] = "15.03.2022";
    assert(validate_expiration_date(date10) == 1);
    char date11[100] = "11.A3.20AB";
    assert(validate_expiration_date(date11) == 0);
    char date12[100] = "11.12.2022";
    assert(validate_expiration_date(date12) == 1);
}

void test_validate_criteria()
{
    int criteria = 3;
    assert(validate_criteria(criteria) == 0);
    criteria = 1;
    assert(validate_criteria(criteria) == 1);
}

void testALL()
{
/// These are the 6 tests which cause memory leaks
    test_add_repo_ur();
//    test_copy_repo_service();
//    test_update_products_expiration_date_s();
//    test_update_products_quantity_s();
//    test_delete_product_s();
//    test_add_product_s();


/// These are the tests which don't cause memory leaks
//    test_update_TElem();
//    test_delete_TELEM();
//    test_createDynamicArray();
//    test_addTElem();
//    test_validate_expiration_date();
//    test_validate_product_type();
//    test_validate_product_quantity();
//    test_validate_product_name();
//    test_RedoOperation();
//    test_UndoOperation();
//    test_createUndoRepo();
//    test_compute_number_days_between_two_dates();
//    test_search_elements_by_category_s();
//    test_search_elements_by_string_s();
//    test_sort_function_quantity();
//    test_sort_function_name();
//    test_duplicate_repo();
//    test_check_existence_product();
//    test_search_elements_by_category_r();
//    test_search_elements_by_string_r();
//    test_createProduct();
//    test_domain_getters();
//    test_assign_values();
//    test_copy_repo();
//    test_update_products_quantity_r();
//    test_getCount();
//    test_update_expiration_date_r();
//    test_add_product_r();
//    test_delete_product_r();
//    test_createRepo();


    _CrtDumpMemoryLeaks();
    _CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_FILE );
    _CrtSetReportFile( _CRT_WARN, _CRTDBG_FILE_STDOUT );
    _CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_FILE );
    _CrtSetReportFile( _CRT_ERROR, _CRTDBG_FILE_STDOUT );
    _CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_FILE );
    _CrtSetReportFile( _CRT_ASSERT, _CRTDBG_FILE_STDOUT );
}