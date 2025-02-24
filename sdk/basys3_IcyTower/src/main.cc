#include "../include/fpga_interface.h"

int main(){

	fpga_interface_initialize_hardware();
	Game GameInstance(fpga_interface_get_buffer(), fpga_interface_get_keyboard());
	fpga_interface_initialize(&GameInstance);

    while(1){
    	fpga_interface_run();
    }
}

