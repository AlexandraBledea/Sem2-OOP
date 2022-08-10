//
// Created by Alexandra on 5/24/2021.
//

#include "Service.h"
#include <algorithm>
#include <iterator>

Service::Service(Repository &repository): repository{repository} {

}

Service::~Service() {

}

vector<weather> Service::getAll() {
    return this->repository.getAll();
}

vector<weather> Service::filterByPrecipitation(int precipitation) {
    vector<weather> filtered;
    for(auto & w: this->getAll()){
        if(w.getPrecipitation() <= precipitation){
            filtered.push_back(w);
        }
    }
    return filtered;
}

vector<weather> Service::filterByDescription(vector<string> descriptions) {
    vector<weather> filtered;
    for(auto & w: this->getAll()){
        for(auto & description : descriptions){
            if(w.getDescription() == description)
            {
                filtered.push_back(w);
            }
        }
    }
    return filtered;
}

vector<string> Service::getDescriptions() {
    vector<string> descriptions;
    for(auto & w: this->getAll()){
        descriptions.push_back(w.getDescription());
    }

    vector<string>::iterator  it;
    it = unique(descriptions.begin(), descriptions.end());
    descriptions.resize(distance(descriptions.begin(), it));
    return descriptions;
}

vector<weather> Service::filterByPrecipitationAndDescription(int precipitation, vector<string> descriptions) {
    vector<weather> filtered;
    filtered = this->filterByPrecipitation(precipitation);

    vector<weather> newFiltered;

    for(auto & w: filtered){
        for(auto & description : descriptions){
            if(w.getDescription() == description)
            {
                newFiltered.push_back(w);
            }
        }
    }
    return newFiltered;
}
