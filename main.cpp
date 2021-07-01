#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include "./lib/person.hpp"
#include "./lib/clinic.hpp"

using namespace std;

void readClinic(vector<Clinic> &clinics, int &totalClinics){
    int capacity, x, y;
    cin >> totalClinics;

    for (int i = 0; i < totalClinics; i++){
        cin >> capacity >> x >> y;
        Clinic clinic(capacity, x, y);
        clinics.push_back(clinic);
    }
}

void readPeople(vector<Person> &people, int &totalPeople)
{

    cin >> totalPeople;
    for (int i = 0; i < totalPeople; i++){
        int age, x, y;
        cin >> age >> x >> y;
        Person person(age, x, y, i);
        people.push_back(person);
    }
}

void galeShapley(vector<vector<int>> &vaccinatedPeople, vector<Clinic> &clinics, vector<Person> &people){

    for (int i = 0; i < people.size(); i++){

        float minDistance = numeric_limits<float>::max();
        int clinicIndex = -1;

        for (int j = 0; j < clinics.size(); j++){

            if (clinics[j].capacity != 0){

                float distance = pow(clinics[j].coordinates.first - people[i].coordinates.first, 2) + pow(clinics[j].coordinates.second - people[i].coordinates.second, 2);

                if (distance <= minDistance){

                    if (distance != minDistance){
                        clinicIndex = j;
                    }
                    minDistance = distance;
                }
            }
        }

        if (clinicIndex >= 0){

            vaccinatedPeople[clinicIndex].push_back(people[i].index);
            clinics[clinicIndex].capacity--;
        }
    }
}

void output(vector<vector<int>> &vaccinatedPeople, int totalClinics){

    for (int i = 0; i < totalClinics; i++){

        if (!vaccinatedPeople[i].empty()){

            cout << i << endl;
            bool primeiro = 1;
            for (int x : vaccinatedPeople[i]){

                if (primeiro == 1){
                    cout << x;
                    primeiro = 0;
                }

                else{
                    cout << " " << x;
                }
            }
            cout << endl;
        }
    }
}

int main(){

    int totalClinics, totalPeople;
    vector<Person> people;
    vector<Clinic> clinics;
    vector<vector<int>> vaccinatedPeople(totalClinics, vector<int>(0));

    readClinic(clinics, totalClinics);
    readPeople(people, totalPeople);
    sort(people.begin(), people.end(), Person::comparePeople);
    galeShapley(vaccinatedPeople, clinics, people);
    output(vaccinatedPeople, totalClinics);
}