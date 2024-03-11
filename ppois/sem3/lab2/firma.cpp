

#include"RepairFirma.h"
#include<iostream>
using namespace std;
/*!
    \brief setter of request status
    \param index
    \return nothing (void type)
*/
void Client::setStatus(Status index)
{
    status = index;
}
/*!
    \brief constructor of class RepairFirma
    \param name,account
*/
RepairFirma::RepairFirma(string name, double account) :name(name), account(account) {};
/*!
    \brief full operation of a repair firma
    \param client
    \return nothing (void type)
*/
void RepairFirma::work(Client client)
{
    cout << client.name << "'s request:" << endl;
    checkRequests(client);
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
/*!
    \brief method of transfer of money from the client's account to the firma's account
    \param client
    \return nothing (void type)
*/
void RepairFirma::pay(Client client)
{
    double price = getPrice(client);
    client.money -= price;
    account += price;
    cout << "Payment was successful" << endl;
}
/*!
    \brief const method of checking whether the client has enough money
    \param client
    \return true or false
*/
bool RepairFirma::consultation(Client client)const
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
/*!
    \brief method of checking requests for correct prameter values
    \param client
    \return nothing (void type)
*/
void RepairFirma::checkRequests(Client client)
{
    for (int i = 0; i < client.requests.size(); i++)
    {
        (*client.requests[i]).checkOptions();
    }

}
/*!
    \brief method of getting total price of all requests
    \param client
    \return double price
*/
double RepairFirma::getPrice(Client client)const
{
    double price = 0;
    for (int i = 0; i < client.requests.size(); i++)
    {
        price += (*client.requests[i]).getPrice();
    }
    return price;
}
/*!
    \brief method of assignment of status accepted for all requests
    \param client
    \return nothing (void type)
*/
void RepairFirma::accept(Client client)
{
    for (int i = 0; i < client.requests.size(); i++)
    {
        (*client.requests[i]).setStatus(accepted);
    }
}
/*!
    \brief method of assignment of status inProgress for all requests
    \param client
    \return nothing (void type)
*/
void RepairFirma::start(Client client)
{
    for (int i = 0; i < client.requests.size(); i++)
    {
        (*client.requests[i]).setStatus(inProgress);
    }

}
/*!
    \brief method of assignment of status completed for all requests
    \param client
    \return nothing (void type)
*/
void RepairFirma::finish(Client client)
{
    for (int i = 0; i < client.requests.size(); i++)
    {
        (*client.requests[i]).setStatus(completed);
    }

}
/*!
    \brief const method of defining status of full request
    \param client
    \return Status status
*/
Status RepairFirma::defineStatus(Client client)const
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
/*!
    \brief method of showing status of full request
    \param client
    \return nothing (void type)
*/
void RepairFirma::showStatus(Client client)
{
    Status index = defineStatus(client);
    client.setStatus(index);
    if (client.status == 0)  cout << "Request is formed " << endl;
    if(client.status==1)  cout << "Request is accepted " << endl;
    if (client.status == 2)  cout << "Request is in progress " << endl;
    if (client.status == 3)  cout << "Request is completed " << endl;
}




