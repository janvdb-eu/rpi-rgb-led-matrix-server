#include <memory>
#include "displays/Display.h"
#include "server/NetworkServer.h"

int main(int argc, char* argv[]) {
    std::shared_ptr<displays::Display> display(displays::createDisplay());
    if (!display->Initialize(argc, argv)) {
        return 1;
    }

    NetworkServer networkServer(display);
    networkServer.RunServer(1236);

    return 0;
}
