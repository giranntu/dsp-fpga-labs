// (C) 2001-2013 Altera Corporation. All rights reserved.
// Your use of Altera Corporation's design tools, logic functions and other 
// software and tools, and its AMPP partner logic functions, and any output 
// files any of the foregoing (including device programming or simulation 
// files), and any associated documentation or information are expressly subject 
// to the terms and conditions of the Altera Program License Subscription 
// Agreement, Altera MegaCore Function License Agreement, or other applicable 
// license agreement, including, without limitation, that your use is for the 
// sole purpose of programming logic devices manufactured by Altera and sold by 
// Altera or its authorized distributors.  Please refer to the applicable 
// agreement for further details.


// (C) 2001-2013 Altera Corporation. All rights reserved.
// Your use of Altera Corporation's design tools, logic functions and other 
// software and tools, and its AMPP partner logic functions, and any output 
// files any of the foregoing (including device programming or simulation 
// files), and any associated documentation or information are expressly subject 
// to the terms and conditions of the Altera Program License Subscription 
// Agreement, Altera MegaCore Function License Agreement, or other applicable 
// license agreement, including, without limitation, that your use is for the 
// sole purpose of programming logic devices manufactured by Altera and sold by 
// Altera or its authorized distributors.  Please refer to the applicable 
// agreement for further details.


// $Id: //acds/rel/13.0sp1/ip/merlin/altera_merlin_router/altera_merlin_router.sv.terp#1 $
// $Revision: #1 $
// $Date: 2013/03/07 $
// $Author: swbranch $

// -------------------------------------------------------
// Merlin Router
//
// Asserts the appropriate one-hot encoded channel based on 
// either (a) the address or (b) the dest id. The DECODER_TYPE
// parameter controls this behaviour. 0 means address decoder,
// 1 means dest id decoder.
//
// In the case of (a), it also sets the destination id.
// -------------------------------------------------------

`timescale 1 ns / 1 ns

module de2i_150_addr_router_001_default_decode
  #(
     parameter DEFAULT_CHANNEL = 1,
               DEFAULT_WR_CHANNEL = -1,
               DEFAULT_RD_CHANNEL = -1,
               DEFAULT_DESTID = 16 
   )
  (output [86 - 82 : 0] default_destination_id,
   output [26-1 : 0] default_wr_channel,
   output [26-1 : 0] default_rd_channel,
   output [26-1 : 0] default_src_channel
  );

  assign default_destination_id = 
    DEFAULT_DESTID[86 - 82 : 0];

  generate begin : default_decode
    if (DEFAULT_CHANNEL == -1) begin
      assign default_src_channel = '0;
    end
    else begin
      assign default_src_channel = 26'b1 << DEFAULT_CHANNEL;
    end
  end
  endgenerate

  generate begin : default_decode_rw
    if (DEFAULT_RD_CHANNEL == -1) begin
      assign default_wr_channel = '0;
      assign default_rd_channel = '0;
    end
    else begin
      assign default_wr_channel = 26'b1 << DEFAULT_WR_CHANNEL;
      assign default_rd_channel = 26'b1 << DEFAULT_RD_CHANNEL;
    end
  end
  endgenerate

endmodule


module de2i_150_addr_router_001
(
    // -------------------
    // Clock & Reset
    // -------------------
    input clk,
    input reset,

    // -------------------
    // Command Sink (Input)
    // -------------------
    input                       sink_valid,
    input  [97-1 : 0]    sink_data,
    input                       sink_startofpacket,
    input                       sink_endofpacket,
    output                      sink_ready,

    // -------------------
    // Command Source (Output)
    // -------------------
    output                          src_valid,
    output reg [97-1    : 0] src_data,
    output reg [26-1 : 0] src_channel,
    output                          src_startofpacket,
    output                          src_endofpacket,
    input                           src_ready
);

    // -------------------------------------------------------
    // Local parameters and variables
    // -------------------------------------------------------
    localparam PKT_ADDR_H = 55;
    localparam PKT_ADDR_L = 36;
    localparam PKT_DEST_ID_H = 86;
    localparam PKT_DEST_ID_L = 82;
    localparam PKT_PROTECTION_H = 90;
    localparam PKT_PROTECTION_L = 88;
    localparam ST_DATA_W = 97;
    localparam ST_CHANNEL_W = 26;
    localparam DECODER_TYPE = 0;

    localparam PKT_TRANS_WRITE = 58;
    localparam PKT_TRANS_READ  = 59;

    localparam PKT_ADDR_W = PKT_ADDR_H-PKT_ADDR_L + 1;
    localparam PKT_DEST_ID_W = PKT_DEST_ID_H-PKT_DEST_ID_L + 1;



    // -------------------------------------------------------
    // Figure out the number of bits to mask off for each slave span
    // during address decoding
    // -------------------------------------------------------
    localparam PAD0 = log2ceil(64'h80000 - 64'h40000); 
    localparam PAD1 = log2ceil(64'h81000 - 64'h80800); 
    localparam PAD2 = log2ceil(64'h81060 - 64'h81040); 
    localparam PAD3 = log2ceil(64'h81070 - 64'h81060); 
    localparam PAD4 = log2ceil(64'h81080 - 64'h81070); 
    localparam PAD5 = log2ceil(64'h81090 - 64'h81080); 
    localparam PAD6 = log2ceil(64'h810a0 - 64'h81090); 
    localparam PAD7 = log2ceil(64'h810b0 - 64'h810a0); 
    localparam PAD8 = log2ceil(64'h810c0 - 64'h810b0); 
    localparam PAD9 = log2ceil(64'h810d0 - 64'h810c0); 
    localparam PAD10 = log2ceil(64'h810e0 - 64'h810d0); 
    localparam PAD11 = log2ceil(64'h810f0 - 64'h810e0); 
    localparam PAD12 = log2ceil(64'h81100 - 64'h810f0); 
    localparam PAD13 = log2ceil(64'h81110 - 64'h81100); 
    localparam PAD14 = log2ceil(64'h81120 - 64'h81110); 
    localparam PAD15 = log2ceil(64'h81130 - 64'h81120); 
    localparam PAD16 = log2ceil(64'h81140 - 64'h81130); 
    localparam PAD17 = log2ceil(64'h81160 - 64'h81150); 
    localparam PAD18 = log2ceil(64'h81170 - 64'h81160); 
    localparam PAD19 = log2ceil(64'h81180 - 64'h81170); 
    localparam PAD20 = log2ceil(64'h81190 - 64'h81180); 
    localparam PAD21 = log2ceil(64'h811a0 - 64'h81190); 
    localparam PAD22 = log2ceil(64'h811b0 - 64'h811a0); 
    localparam PAD23 = log2ceil(64'h811c0 - 64'h811b0); 
    localparam PAD24 = log2ceil(64'h811c8 - 64'h811c0); 
    localparam PAD25 = log2ceil(64'h811d0 - 64'h811c8); 
    // -------------------------------------------------------
    // Work out which address bits are significant based on the
    // address range of the slaves. If the required width is too
    // large or too small, we use the address field width instead.
    // -------------------------------------------------------
    localparam ADDR_RANGE = 64'h811d0;
    localparam RANGE_ADDR_WIDTH = log2ceil(ADDR_RANGE);
    localparam OPTIMIZED_ADDR_H = (RANGE_ADDR_WIDTH > PKT_ADDR_W) ||
                                  (RANGE_ADDR_WIDTH == 0) ?
                                        PKT_ADDR_H :
                                        PKT_ADDR_L + RANGE_ADDR_WIDTH - 1;

    localparam RG = RANGE_ADDR_WIDTH-1;

      wire [PKT_ADDR_W-1 : 0] address = sink_data[OPTIMIZED_ADDR_H : PKT_ADDR_L];

    // -------------------------------------------------------
    // Pass almost everything through, untouched
    // -------------------------------------------------------
    assign sink_ready        = src_ready;
    assign src_valid         = sink_valid;
    assign src_startofpacket = sink_startofpacket;
    assign src_endofpacket   = sink_endofpacket;

    wire [PKT_DEST_ID_W-1:0] default_destid;
    wire [26-1 : 0] default_src_channel;





    de2i_150_addr_router_001_default_decode the_default_decode(
      .default_destination_id (default_destid),
      .default_wr_channel   (),
      .default_rd_channel   (),
      .default_src_channel  (default_src_channel)
    );

    always @* begin
        src_data    = sink_data;
        src_channel = default_src_channel;
        src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = default_destid;

        // --------------------------------------------------
        // Address Decoder
        // Sets the channel and destination ID based on the address
        // --------------------------------------------------

    // ( 0x40000 .. 0x80000 )
    if ( {address[RG:PAD0],{PAD0{1'b0}}} == 20'h40000   ) begin
            src_channel = 26'b00000000000000000000000010;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 16;
    end

    // ( 0x80800 .. 0x81000 )
    if ( {address[RG:PAD1],{PAD1{1'b0}}} == 20'h80800   ) begin
            src_channel = 26'b00000000000000000000000001;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 15;
    end

    // ( 0x81040 .. 0x81060 )
    if ( {address[RG:PAD2],{PAD2{1'b0}}} == 20'h81040   ) begin
            src_channel = 26'b00000000000000000000000100;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 25;
    end

    // ( 0x81060 .. 0x81070 )
    if ( {address[RG:PAD3],{PAD3{1'b0}}} == 20'h81060   ) begin
            src_channel = 26'b10000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 1;
    end

    // ( 0x81070 .. 0x81080 )
    if ( {address[RG:PAD4],{PAD4{1'b0}}} == 20'h81070   ) begin
            src_channel = 26'b01000000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 23;
    end

    // ( 0x81080 .. 0x81090 )
    if ( {address[RG:PAD5],{PAD5{1'b0}}} == 20'h81080   ) begin
            src_channel = 26'b00100000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 22;
    end

    // ( 0x81090 .. 0x810a0 )
    if ( {address[RG:PAD6],{PAD6{1'b0}}} == 20'h81090   ) begin
            src_channel = 26'b00010000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 21;
    end

    // ( 0x810a0 .. 0x810b0 )
    if ( {address[RG:PAD7],{PAD7{1'b0}}} == 20'h810a0   ) begin
            src_channel = 26'b00001000000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 20;
    end

    // ( 0x810b0 .. 0x810c0 )
    if ( {address[RG:PAD8],{PAD8{1'b0}}} == 20'h810b0   ) begin
            src_channel = 26'b00000100000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 11;
    end

    // ( 0x810c0 .. 0x810d0 )
    if ( {address[RG:PAD9],{PAD9{1'b0}}} == 20'h810c0   ) begin
            src_channel = 26'b00000010000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 10;
    end

    // ( 0x810d0 .. 0x810e0 )
    if ( {address[RG:PAD10],{PAD10{1'b0}}} == 20'h810d0   ) begin
            src_channel = 26'b00000001000000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 9;
    end

    // ( 0x810e0 .. 0x810f0 )
    if ( {address[RG:PAD11],{PAD11{1'b0}}} == 20'h810e0   ) begin
            src_channel = 26'b00000000100000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 13;
    end

    // ( 0x810f0 .. 0x81100 )
    if ( {address[RG:PAD12],{PAD12{1'b0}}} == 20'h810f0   ) begin
            src_channel = 26'b00000000010000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 3;
    end

    // ( 0x81100 .. 0x81110 )
    if ( {address[RG:PAD13],{PAD13{1'b0}}} == 20'h81100   ) begin
            src_channel = 26'b00000000001000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 6;
    end

    // ( 0x81110 .. 0x81120 )
    if ( {address[RG:PAD14],{PAD14{1'b0}}} == 20'h81110   ) begin
            src_channel = 26'b00000000000100000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 14;
    end

    // ( 0x81120 .. 0x81130 )
    if ( {address[RG:PAD15],{PAD15{1'b0}}} == 20'h81120   ) begin
            src_channel = 26'b00000000000010000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 2;
    end

    // ( 0x81130 .. 0x81140 )
    if ( {address[RG:PAD16],{PAD16{1'b0}}} == 20'h81130   ) begin
            src_channel = 26'b00000000000001000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 5;
    end

    // ( 0x81150 .. 0x81160 )
    if ( {address[RG:PAD17],{PAD17{1'b0}}} == 20'h81150   ) begin
            src_channel = 26'b00000000000000100000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 18;
    end

    // ( 0x81160 .. 0x81170 )
    if ( {address[RG:PAD18],{PAD18{1'b0}}} == 20'h81160   ) begin
            src_channel = 26'b00000000000000010000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 17;
    end

    // ( 0x81170 .. 0x81180 )
    if ( {address[RG:PAD19],{PAD19{1'b0}}} == 20'h81170   ) begin
            src_channel = 26'b00000000000000001000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 4;
    end

    // ( 0x81180 .. 0x81190 )
    if ( {address[RG:PAD20],{PAD20{1'b0}}} == 20'h81180   ) begin
            src_channel = 26'b00000000000000000100000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 0;
    end

    // ( 0x81190 .. 0x811a0 )
    if ( {address[RG:PAD21],{PAD21{1'b0}}} == 20'h81190   ) begin
            src_channel = 26'b00000000000000000010000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 8;
    end

    // ( 0x811a0 .. 0x811b0 )
    if ( {address[RG:PAD22],{PAD22{1'b0}}} == 20'h811a0   ) begin
            src_channel = 26'b00000000000000000001000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 19;
    end

    // ( 0x811b0 .. 0x811c0 )
    if ( {address[RG:PAD23],{PAD23{1'b0}}} == 20'h811b0   ) begin
            src_channel = 26'b00000000000000000000100000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 12;
    end

    // ( 0x811c0 .. 0x811c8 )
    if ( {address[RG:PAD24],{PAD24{1'b0}}} == 20'h811c0   ) begin
            src_channel = 26'b00000000000000000000010000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 24;
    end

    // ( 0x811c8 .. 0x811d0 )
    if ( {address[RG:PAD25],{PAD25{1'b0}}} == 20'h811c8   ) begin
            src_channel = 26'b00000000000000000000001000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 7;
    end

end


    // --------------------------------------------------
    // Ceil(log2()) function
    // --------------------------------------------------
    function integer log2ceil;
        input reg[65:0] val;
        reg [65:0] i;

        begin
            i = 1;
            log2ceil = 0;

            while (i < val) begin
                log2ceil = log2ceil + 1;
                i = i << 1;
            end
        end
    endfunction

endmodule


