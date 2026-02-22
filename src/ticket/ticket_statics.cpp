#include "ticket.cpp"

// Initialize static members for Ticket
unordered_map<string, Ticket*> Ticket::ticketList;
int Ticket::ticketCount = 0;
