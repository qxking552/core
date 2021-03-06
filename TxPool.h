
#ifndef TX_TXPOOL_H
#define TX_TXPOOL_H

#include <string>
#include <vector>
#include <unordered_map>
#include <mutex>
#include "Transaction/Transaction.h"
#include "Block/Block.h"
#include "Transaction/TransactionError.h"

class TxPool {
private:
    std::unordered_map<std::string, TransactionForNetwork> transactionList;
    std::unordered_map<std::string, TxIn> txInputs;

    bool isTxInputPresent(TxIn txIn);
    bool isTxInputPresent(TransactionForNetwork* transaction);
public:
    static TxPool& Instance(){
        static TxPool instance;
        return instance;
    }

    static std::mutex transactionListLock;
    static std::mutex txInputsLock;

    std::unordered_map<std::string, TransactionForNetwork> getTransactionList();
    void setTransactionList(std::unordered_map<std::string, TransactionForNetwork> transactionList);
    void popTransaction(std::vector<unsigned char> txId);
    bool appendTransaction(TransactionForNetwork transaction, bool broadcast, TransactionError *transactionError);
    void appendTransactionsFromBlock(Block* block);
    uint32_t getTxCount();
    TransactionForNetwork* popTransaction();
};


#endif //TX_TXPOOL_H
