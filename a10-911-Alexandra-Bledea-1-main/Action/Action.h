//
// Created by Alexandra on 5/23/2021.
//

#pragma once
#include "repository.h"

class Action {

public:

    virtual void executeUndo() = 0;
    virtual void executeRedo() = 0;

};

class AddAction: public Action{

private:
    Repository& repository;
    Coat addedCoat;

public:
    AddAction(Repository& repository, Coat addedCoat);
    void executeUndo() override;
    void executeRedo() override;

};

class DeleteAction: public Action{

private:
    Repository& repository;
    Coat deletedCoat;

public:
    DeleteAction(Repository& repository, Coat deletedCoat);
    void executeUndo() override;
    void executeRedo() override;

};


class DeleteSoldOutAction: public Action{

private:
    Repository& repository;
    Coat deletedCoat;

public:
    DeleteSoldOutAction(Repository& repository, Coat deletedCoat);
    void executeUndo() override;
    void executeRedo() override;

};


class UpdateQuantityAction: public Action{

private:
    Repository& repository;
    Coat oldCoat;
    Coat newCoat;

public:
    UpdateQuantityAction(Repository& repository, Coat oldCoat, Coat newCoat);
    void executeUndo() override;
    void executeRedo() override;

};

class UpdatePriceAction: public Action{

private:
    Repository& repository;
    Coat oldCoat;
    Coat newCoat;

public:
    UpdatePriceAction(Repository& repository, Coat oldCoat, Coat newCoat);
    void executeUndo() override;
    void executeRedo() override;

};

class AddActionUserMode: public Action{

private:
    Repository& repository;
    Repository& user_repository;
    Coat oldCoat;
    Coat newCoat;

public:
    AddActionUserMode(Repository& repository, Repository& user_repository, Coat oldCoat, Coat newCoat);
    void executeUndo() override;
    void executeRedo() override;
};

class UpdateActionUserMode: public Action{

private:
    Repository& repository;
    Repository& user_repository;
    Coat oldCoatUser;
    Coat newCoatUser;
    Coat oldCoatAdmin;

public:
    UpdateActionUserMode(Repository& repository, Repository& user_repository, Coat oldCoatUser, Coat newCoatUser, Coat oldCoatAdmin);
    void executeUndo() override;
    void executeRedo() override;

};

class UpdateActionDeletedUserMode: public Action{

private:
    Repository& repository;
    Repository& user_repository;
    Coat oldCoatUser;
    Coat newCoatUser;
    Coat oldCoatAdmin;

public:
    UpdateActionDeletedUserMode(Repository& repository, Repository& user_repository, Coat oldCoatUser, Coat newCoatUser, Coat oldCoatAdmin);
    void executeUndo() override;
    void executeRedo() override;

};

class AddDeleteActionUserMode: public Action{

private:
    Repository& repository;
    Repository& user_repository;
    Coat oldCoat;
    Coat newCoat;

public:
    AddDeleteActionUserMode(Repository& repository, Repository& user_repository, Coat oldCoat, Coat newCoat);
    void executeUndo() override;
    void executeRedo() override;

};