#include <iostream>
#include "Test.h"
#include "Console.h"
#include "Repo.h"
#include "Entity.h"
int main() {
    Repo* repo = new Repo();
    Service* service = new Service(repo);
    Console* console = new Console(service);
    console->ConsoleOn();
    return 0;
}
