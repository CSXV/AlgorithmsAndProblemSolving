#pragma once
#include "clsDate.h"
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

class clsQueueLine {
private:
  string _prefix;
  short _time;

  short _Total = 0;
  short _Served = 0;
  short _Waiting = 0;

  struct stTicket {
    string Name;
    string DateTime;
    short WaitingClients;
    short ServeTime;
  };

  queue<stTicket> _Client;

  void _QueueInfo() {
    cout << "\n________________________";
    cout << "\n     Queue Info";
    cout << "\n________________________";
    cout << "\nPerfix        : " << Perfix;
    cout << "\nTotal  tickets: " << _Total;
    cout << "\nServed Clients: " << _Served;
    cout << "\nWating Clients: " << _Waiting;
    cout << "\n________________________";
  }

  string _Date() { return clsDate::GetSystemDateTimeString(); }

  stTicket _MakeTicket() {
    stTicket ticket;

    ticket.Name = Perfix + to_string(_Total);
    ticket.DateTime = _Date();
    ticket.WaitingClients = _Waiting;
    ticket.ServeTime = Time * _Waiting;

    return ticket;
  }

  void _PrintTicket(stTicket S) {
    cout << "\n________________________";
    cout << "\n\t  " << S.Name;
    cout << "\n\n  " << S.DateTime;
    cout << "\n  Waiting Clients: " << S.WaitingClients;
    cout << "\n  Served Time In :\n  " << S.ServeTime << " Minutes.";
    cout << "\n________________________" << endl;
  }

  void _PrintAllTicket() {
    queue<stTicket> Temp = _Client;

    cout << "\n\n     ***Tickets***";

    for (short i = 0; i < _Waiting; i++) {
      _PrintTicket(Temp.front());
      Temp.pop();
    }
  }

public:
  clsQueueLine(string prefix, short time) {
    _prefix = prefix;
    _time = time;
  }

  void SetPerfix(string perfix) { _prefix = perfix; }
  string GetPerfix() { return _prefix; }
  __declspec(property(get = GetPerfix, put = SetPerfix)) string Perfix;

  void SetTime(short time) { _time = time; }
  short GetTime() { return _time; }
  __declspec(property(get = GetTime, put = SetTime)) short Time;

  void IssueTicket() {
    _Total++;

    _Client.push(_MakeTicket());

    _Waiting = _Total - _Served;
  }

  void PrintInfo() { _QueueInfo(); }

  void PrintTicketsLineRTL() {
    queue<stTicket> Temp = _Client;

    cout << "\n\nTickets: ";

    for (short i = 0; i < _Total; i++) {
      cout << Temp.front().Name << " <-- ";
      Temp.pop();
    }
  }

  void PrintTicketsLineLTR() {
    queue<stTicket> Temp = _Client;
    stack<stTicket> TempS;

    while (!Temp.empty()) {
      TempS.push(Temp.front());
      Temp.pop();
    }

    cout << "\n\nTickets: ";

    while (!TempS.empty()) {
      cout << TempS.top().Name << " --> ";
      TempS.pop();
    }
  }

  void PrintAllTickets() { _PrintAllTicket(); }

  void ServeNextClient() {
    if (_Client.empty())
      return;

    _Client.pop();

    _Served++;
    _Waiting--;
  }
};
