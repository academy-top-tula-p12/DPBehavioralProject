#include <iostream>
//#include "Chain.h"
//void ChainExample()
//{
//    Receiver* reciever1 = new Receiver(false, false, false);
//    Receiver* reciever2 = new Receiver(true, true, false);
//
//    PaymentHandler* handler1 = new BankPaymentHandler();
//    handler1->Add(new PayPaymentHandler());
//    handler1->Add(new CashPaymentHandler());
//
//    //handler1->Handle(reciever1);
//
//    handler1->Handle(reciever2);
//}

//#include "Iterator.h"
//void IteratorExample()
//{
//    Vector* v = new Vector();
//    v->PushBack(100);
//    v->PushBack(200);
//    v->PushBack(300);
//    v->PushBack(400);
//    v->PushBack(500);
//    v->Print();
//
//    Iterator* it = v->GetIterator();
//    it->Begin();
//    while (it->Next())
//        std::cout << it->Current() << " ";
//    std::cout << "\n";
//}

//#include "Strategy.h"
//void StrategyExample()
//{
//    std::string file = "myfile.txt";
//    Archiver* archiver = new Archiver(new ArjCompression());
//
//    archiver->Archiving(file);
//
//    archiver->Compression() = new RarCompression();
//    archiver->Archiving(file);
//
//    archiver->Compression() = new ZipCompression();
//    archiver->Archiving(file);
//}

#include "State.h"

int main()
{
    Machine* machine = new Machine(new FullPayMachineState(), 3);

    machine->Start(120);
}
