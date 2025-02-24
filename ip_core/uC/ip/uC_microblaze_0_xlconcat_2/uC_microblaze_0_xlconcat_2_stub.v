// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.2 (win64) Build 2258646 Thu Jun 14 20:03:12 MDT 2018
// Date        : Sun Jun 30 00:46:26 2019
// Host        : DESKTOP-V0A11EI running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               d:/Elektronika/Workspace/Xilinx/UEC2_Project/ip_core/uC/ip/uC_microblaze_0_xlconcat_2/uC_microblaze_0_xlconcat_2_stub.v
// Design      : uC_microblaze_0_xlconcat_2
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7a35tcpg236-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "xlconcat_v2_1_1_xlconcat,Vivado 2018.2" *)
module uC_microblaze_0_xlconcat_2(In0, In1, dout)
/* synthesis syn_black_box black_box_pad_pin="In0[0:0],In1[0:0],dout[1:0]" */;
  input [0:0]In0;
  input [0:0]In1;
  output [1:0]dout;
endmodule
