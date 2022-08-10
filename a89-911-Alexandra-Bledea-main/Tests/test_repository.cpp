//
// Created by Alexandra on 3/23/2021.
//

#include "test_repository.h"
#include <vector>
#include "Exceptions.h"

void Test_Repository::Test_init_repository() {
    Repository repo;
    repo.init_repository();
    assert(repo.GetDynArr()[0].GetSize() == "M");
    assert(repo.GetDynArr()[0].GetColor() == "Blue");
    assert(repo.GetDynArr()[0].GetPrice() == 100);
    assert(repo.GetDynArr()[0].GetQuantity() == 10);
    assert(repo.GetDynArr()[0].GetPhotograph() == "https://www.morganclare.co.uk/images/luxe-blue-coat-p36372-114149_image.jpg");

}

void Test_Repository::TestGetSize() {
    Repository repo;
    repo.init_repository();
    assert(repo.GetSize() == 10);

}

//void Test_Repository::TestGetDynArr() {
//    Repository repo;
//    assert(repo.GetDynArr() == repo.GetDynArr());
//}

void Test_Repository::TestAddRepo() {
    Repository repo;
    repo.AddRepo("M", "Blue", 100, 10, "https://www.morganclare.co.uk/images/luxe-blue-coat-p36372-114149_image.jpg");
    assert(repo.GetDynArr()[0].GetSize() == "M");
    assert(repo.GetDynArr()[0].GetColor() == "Blue");
    assert(repo.GetDynArr()[0].GetPrice() == 100);
    assert(repo.GetDynArr()[0].GetQuantity() == 10);
    assert(repo.GetDynArr()[0].GetPhotograph() == "https://www.morganclare.co.uk/images/luxe-blue-coat-p36372-114149_image.jpg");
    try{
        repo.AddRepo("M", "Blue", 100, 10, "https://www.morganclare.co.uk/images/luxe-blue-coat-p36372-114149_image.jpg");
        assert(false);
    }
    catch(ExceptionsRepository&)
    {
        assert(true);
    }


}

void Test_Repository::TestCheckExistenceCoat() {
    Repository repo;
    repo.AddRepo("M", "Blue", 100, 10, "https://www.morganclare.co.uk/images/luxe-blue-coat-p36372-114149_image.jpg");
    assert(repo.CheckExistenceCoat("M", "Blue", "https://www.morganclare.co.uk/images/luxe-blue-coat-p36372-114149_image.jpg") == 0);
    assert(repo.CheckExistenceCoat("S", "Pink", "https://sagsahj.jpg/saghsa") == -1);
}

void Test_Repository::TestDeleteEntireProductRepo() {
    Repository repo;
    repo.AddRepo("M", "Blue", 100, 10, "https://www.morganclare.co.uk/images/luxe-blue-coat-p36372-114149_image.jpg");
    repo.DeleteEntireProductRepo("M", "Blue", "https://www.morganclare.co.uk/images/luxe-blue-coat-p36372-114149_image.jpg");
    try{
        repo.DeleteEntireProductRepo("s", "Purple", "https://safghsajk.jpg");
        assert(false);
    }
    catch(ExceptionsRepository&)
    {
        assert(true);
    }

}

void Test_Repository::TestDeleteSoldOutProductRepo() {
    Repository repo;
    repo.AddRepo("M", "Blue", 100, 10, "https://www.morganclare.co.uk/images/luxe-blue-coat-p36372-114149_image.jpg");
    repo.AddRepo("M", "Pink", 100, 0, "https://abcdef.jpg");
    repo.DeleteSoldOutProductRepo("M", "Pink", "https://abcdef.jpg");
    try{
        repo.DeleteSoldOutProductRepo("M", "Blue", "https://www.morganclare.co.uk/images/luxe-blue-coat-p36372-114149_image.jpg");
        assert(false);
    }
    catch(ExceptionsRepository&)
    {
        assert(true);
    }
}

void Test_Repository::TestUpdatePriceRepo() {
    Repository repo;
    repo.AddRepo("M", "Pink", 100, 0, "https://abcdef.jpg");
    repo.UpdatePriceRepo("M", "Pink", "https://abcdef.jpg", 999);
    assert(repo.GetDynArr()[0].GetPrice() == 999);
    try {
        repo.UpdatePriceRepo("S", "Blue", "https://abcdesaff.jpg", 999);
        assert(false);
    }
    catch(ExceptionsRepository&)
    {
        assert(true);
    }
}

void Test_Repository::TestUpdateQuantityRepo() {
    Repository repo;
    repo.AddRepo("M", "Pink", 100, 0, "https://abcdef.jpg");
    repo.UpdateQuantityRepo("M", "Pink", "https://abcdef.jpg", 999);
    assert(repo.GetDynArr()[0].GetQuantity() == 999);
    try{
        repo.UpdateQuantityRepo("S", "Blue", "https://abcdesaff.jpg", 999);
        assert(false);
    }
    catch(ExceptionsRepository&)
    {
        assert(true);
    }


}

void Test_Repository::TestAllRepository() {
    Test_init_repository();
    TestGetSize();
    TestAddRepo();
    TestCheckExistenceCoat();
    TestDeleteEntireProductRepo();
    TestDeleteSoldOutProductRepo();
    TestUpdatePriceRepo();
    TestUpdateQuantityRepo();

}
