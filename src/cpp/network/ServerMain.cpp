#include "../display/Display.h"
#include "NetworkServer.h"

int main(int argc, char *argv[]) {
	boost::shared_ptr<Display> display(CreateDisplay());
	if (!display->Initialize(argc, argv)) {
		return 1;
	}

	Server networkServer(display, 1236);

	networkServer.StartServerAndBlock();

	return 0;
}
