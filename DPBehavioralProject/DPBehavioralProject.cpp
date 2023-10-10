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

//#include "State.h"
//void StateExample()
//{
//    Machine* machine = new Machine(new FullPayMachineState(), 3);
//
//    machine->Start(120);
//}

//#include "Memento.h"
//void MementoExample()
//{
//    srand(time(nullptr));
//
//    Player* player = new Player();
//    GameHistory* history = new GameHistory();
//
//    player->Play();
//    player->Play();
//
//    history->Save(player->Save());
//
//    player->Play();
//    player->Play();
//
//    history->Save(player->Save());
//
//    player->Play();
//    player->Play();
//
//    player->Load(history->Load());
//    player->Load(history->Load());
//
//    player->Play();
//}

//#include "Visitor.h"
//void VisitorExample()
//{
//    Bank* sber = new Bank();
//
//    Person* bob = new Person();
//    bob->Name() = "Bobby";
//    bob->Number() = "12345_AD";
//    bob->Amount() = 250000;
//    sber->Add(bob);
//
//    Company* yandex = new Company();
//    yandex->Title() = "Yandex";
//    yandex->Number() = "TWE 162342 00 LP";
//    yandex->License() = "ASC-87600098";
//    yandex->Amount() = 5760000;
//    sber->Add(yandex);
//
//    sber->Accept(new XmlVisitor());
//}

//#include "Mediator.h"
//void MediatorExample()
//{
//    ManagerMediator* manager = new ManagerMediator();
//    Collegue* customer = new CustomerCollegue(manager);
//    Collegue* developer = new DeveloperCollegue(manager);
//    Collegue* tester = new TesterCollegue(manager);
//
//    manager->Customer() = customer;
//    manager->Developer() = developer;
//    manager->Tester() = tester;
//
//    customer->Send("Order! I need of program!");
//    developer->Send("Program is ready");
//    tester->Send("Program ready and testing");
//}

//#include "Observer.h"
//void ObserverExample()
//{
//    srand(time(nullptr));
//
//    Market* market = new Market();
//    Bank* bank = new Bank("Sber", market);
//    Broker* broker = new Broker("Jhon Smith", market);
//    market->AddObserver(bank);
//    market->AddObserver(broker);
//
//    market->Bidding();
//    std::cout << "\n";
//
//    market->Bidding();
//    std::cout << "\n";
//
//    broker->StopMarket();
//
//    market->Bidding();
//    std::cout << "\n";
//}

//#include "Command.h"
//void CommandExample()
//{
//    Television* tv = new Television();
//
//    Controller* pult = new Controller(
//        new TvOnCommand(tv),
//        new TvSoundUpCommand(tv),
//        new TvSoundDownCommand(tv)
//    );
//
//    MobileController* app = new MobileController(
//        new TvOnCommand(tv),
//        new TvOffCommand(tv),
//        new TvSoundUpCommand(tv),
//        new TvSoundDownCommand(tv)
//    );
//
//    pult->ButtonPower();
//    pult->ButtonVolumePlus();
//    app->MenuItemVolumePlus();
//    pult->ButtonVolumePlus();
//
//    app->MenuItemUndo();
//    app->MenuItemUndo();
//}

//#include "TemplateMethod.h"
//void TemplateMethodExample()
//{
//    Education* education = new School();
//    education->TemplateMethod();
//    std::cout << "\n";
//
//    delete education;
//    education = new Universitet();
//    education->TemplateMethod();
//    std::cout << "\n";
//}

#include "Interpreter.h"

int main()
{
    Context* context = new Context();
    context->SetVariable("a", 10);
    context->SetVariable("b", 20);
    context->SetVariable("c", 30);

    IExpression* expression1 = new AddExpression(
        new NumberExpression("a"),
        new MultExpression(
            new NumberExpression("b"),
            new NumberExpression("c")
        )
    );

    double result = expression1->Solve(context);
    std::cout << result << "\n";

    context->SetVariable("a", 50);
    result = expression1->Solve(context);
    std::cout << result << "\n";


    IExpression* expression2 = new MultExpression(
        new AddExpression(
            new NumberExpression("a"),
            new NumberExpression("b")
        ),
        new NumberExpression("c")
    );

    result = expression2->Solve(context);
    std::cout << result << "\n";
}
