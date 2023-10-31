

#include"RepairFirma.h"
#include<iostream>
using namespace std;

void Client::setStatus(Status index)
{
    status = index;
}
RepairFirma::RepairFirma(string name, double account) :name(name), account(account) {};
void RepairFirma::work(Client client)
{
    cout << client.name << "'s request:" << endl;

    bool agreement = consultation(client);
    if (agreement == 1)
    {
        pay(client);
        accept(client);
        showStatus(client);
        start(client);
        showStatus(client);
        finish(client);
        showStatus(client);

    }
    else cout << "Request not accepted" << endl;
}

void RepairFirma::pay(Client client)
{
    double price = getPrice(client);
    client.money -= price;
    account += price;
    cout << "Payment was successful" << endl;
}
bool RepairFirma::consultation(Client client)
{
    cout << "Consultation starts" << endl;
    double price = getPrice(client);
    cout << "Price:" << price << endl;
    cout <<client.name<<"'s account is "<<client.money << endl;
    if (price <= client.money)
    {
        cout << "okay" << endl;
        return true;
    }
    else
    {
        cout << "too expensive" << endl;
        return false;
    }

}
double RepairFirma::getPrice(Client client)
{
    double price = 0;
    for (int i = 0; i < client.requests.size(); i++)
    {
        price += (*client.requests[i]).getPrice();
    }
    return price;
}

void RepairFirma::accept(Client client)
{
    for (int i = 0; i < client.requests.size(); i++)
    {
        (*client.requests[i]).setStatus(accepted);
    }
}
void RepairFirma::start(Client client)
{
    for (int i = 0; i < client.requests.size(); i++)
    {
        (*client.requests[i]).setStatus(inProgress);
    }

}
void RepairFirma::finish(Client client)
{
    for (int i = 0; i < client.requests.size(); i++)
    {
        (*client.requests[i]).setStatus(completed);
    }

}

Status RepairFirma::defineStatus(Client client)
{
    int formedCount = 0;
    int acceptedCount = 0;
    int inProgressCount = 0;
    int completedCount = 0;
    for (int i = 0; i < client.requests.size(); i++)
    {
        Status index = (*client.requests[i]).getStatus();
        if (index == formed) formedCount++;
        if (index == accepted) acceptedCount++;
        if (index == inProgress) inProgressCount++;
        if (index == completed) completedCount++;
    }
    if ((formedCount == client.requests.size()) || (formedCount != acceptedCount && acceptedCount != client.requests.size())) return formed;
    if ((acceptedCount == client.requests.size()) || inProgressCount != acceptedCount && inProgressCount != client.requests.size()) return accepted;
    if ((inProgressCount == client.requests.size()) || (inProgressCount != completedCount && completedCount != client.requests.size())) return inProgress;
    if (completedCount == client.requests.size()) return completed;
    else return formed;

}

void RepairFirma::showStatus(Client client)
{
    Status index = defineStatus(client);
    client.setStatus(index);
    if (client.status == 0)  cout << "Request is formed " << endl;
    if(client.status==1)  cout << "Request is accepted " << endl;
    if (client.status == 2)  cout << "Request is in progress " << endl;
    if (client.status == 3)  cout << "Request is completed " << endl;

   
}




