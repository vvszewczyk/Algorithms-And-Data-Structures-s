#include <iostream>
#include <queue>
#include <vector>


struct Transaction 
{
    double amount;
    std::string title;

    Transaction(double a, std::string t) : amount(a), title(t) {}
};

//do porównywania transakcji na podstawie ich kwot
struct TransactionComparator 
{
    bool operator()(const Transaction& t1, const Transaction& t2) 
    {
        return t1.amount < t2.amount;
    }
};

//funkcja do zebrania N transakcji o największych kwotach
std::vector<Transaction> getTopNTransactions(const std::vector<Transaction>& incomingData, int N) 
{
    std::priority_queue<Transaction, std::vector<Transaction>, TransactionComparator> pq;

    for (const Transaction& transaction : incomingData) 
    {
        pq.push(transaction);
        if (pq.size() > N) 
        {
            pq.pop();
        }
    }

    std::vector<Transaction> topTransactions;
    while (!pq.empty()) 
    {
        topTransactions.push_back(pq.top());
        pq.pop();
    }

    //odwrócenie kolejności aby transakcje były posortowane od największej do najmniejszej kwoty
    std::reverse(topTransactions.begin(), topTransactions.end());

    return topTransactions;
}

int main() 
{
    std::vector<Transaction> incomingData;
    incomingData.push_back(Transaction(1000.0, "Przelew 1"));
    incomingData.push_back(Transaction(500.0, "Przelew 2"));
    incomingData.push_back(Transaction(1500.0, "Przelew 3"));
    incomingData.push_back(Transaction(2000.0, "Przelew 4"));
    incomingData.push_back(Transaction(800.0, "Przelew 5"));

    //liczba transakcji o największych kwotach do zebrania
    int N = 3; 

    std::vector<Transaction> topNTransactions = getTopNTransactions(incomingData, N);


    for (const Transaction& transaction : topNTransactions) 
    {
        std::cout << "Kwota: " << transaction.amount << ", Tytuł: " << transaction.title << std::endl;
    }

    return 0;
}