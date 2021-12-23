#include <iostream>
#include <fstream>
#include <cstdint>

int Dissassemble8080p(unsigned char* codeBuffer, int pc)
{
	unsigned char* code = &codeBuffer[pc];

	int opBytes = 1;

	printf("%04x ", pc);

	switch (*code)
	{
	case 0x00: printf("NOP"); break;
	case 0x01: printf("LXI		B, #$%02x%02x", code[2], code[1]); opBytes = 3; break;
	case 0x02: printf("STAX		B"); break;
	case 0x03: printf("INX		B"); break;
	case 0x04: printf("INR		B"); break;
	case 0x05: printf("MVI		B, #$%02x", code[1]); opBytes = 2; break;
	case 0x06: printf("RLC"); break;
	case 0x07: printf("RLC"); break;
	case 0x08: printf("NOP"); break;
	case 0x09: printf("DAD 		B"); break;
	case 0x0a: printf("LDAX		B"); break;
	case 0x0b: printf("DCX 		B"); break;
	case 0x0c: printf("INR 		C"); break;
	case 0x0d: printf("DCR 		C"); break;
	case 0x0e: printf("MVI		C, #$%02x", code[1]); opBytes = 2; break;
	case 0x0f: printf("RRC"); break;

	case 0x10: printf("NOP"); break;
	case 0x11: printf("LXI 		D, #$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0x12: printf("STAX		D"); break;
	case 0x13: printf("INX 		D"); break;
	case 0x14: printf("INR 		D"); break;
	case 0x15: printf("DCR 		D"); break;
	case 0x16: printf("MVI 		D, #$%02x", code[1]); opBytes = 2; break;
	case 0x17: printf("RAL"); break;
	case 0x18: printf("NOP"); break;
	case 0x19: printf("DAD 		D"); break;
	case 0x1a: printf("LDAX		D"); break;
	case 0x1b: printf("DCX 		D"); break;
	case 0x1c: printf("INR 		E"); break;
	case 0x1d: printf("DCR 		E"); break;
	case 0x1e: printf("MVI 		E, #$%02x", code[1]); opBytes = 2; break;
	case 0x1f: printf("RAR"); break;

	case 0x20: printf("RIM"); break;
	case 0x21: printf("LXI		H, #$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0x22: printf("SHLD 	$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0x23: printf("INX 		H"); break;
	case 0x24: printf("INR 		H"); break;
	case 0x25: printf("DCR 		H"); break;
	case 0x26: printf("MVI 		H, #$%02x", code[1]); opBytes = 2; break;
	case 0x27: printf("DAA"); break;
	case 0x28: printf("NOP"); break;
	case 0x29: printf("DAD 		H"); break;
	case 0x2a: printf("LHLD		$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0x2b: printf("DCX 		H");	break;
	case 0x2c: printf("INR		L"); break;
	case 0x2d: printf("DCR 		L"); break;
	case 0x2e: printf("MVI 		L, #$%02x02x", code[1]); opBytes = 2; break;
	case 0x2f: printf("CMA"); break;

	case 0x30: printf("SIM"); break;
	case 0x31: printf("LXI		SP, #$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0x32: printf("STA 		$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0x33: printf("INX 		SP"); break;
	case 0x34: printf("INR 		M"); break;
	case 0x35: printf("DCR 		M"); break;
	case 0x36: printf("MVI 		M, #$%02x", code[1]); opBytes = 2; break;
	case 0x37: printf("STC"); break;
	case 0x38: printf("NOP"); break;
	case 0x39: printf("DAD 		SP"); break;
	case 0x3a: printf("LDA 		$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0x3b: printf("DCX 		SP"); break;
	case 0x3c: printf("INR 		A"); break;
	case 0x3d: printf("DCR 		A"); break;
	case 0x3e: printf("MVI 		A, #$%02x", code[1]); opBytes = 2; break;
	case 0x3f: printf("CMC"); break;

	case 0x40: printf("MOV 		B,B"); break;
	case 0x41: printf("MOV 		B,C"); break;
	case 0x42: printf("MOV 		B,D"); break;
	case 0x43: printf("MOV		B,E"); break;
	case 0x44: printf("MOV    B,H"); break;
	case 0x45: printf("MOV    B,L"); break;
	case 0x46: printf("MOV    B,M"); break;
	case 0x47: printf("MOV    B,A"); break;
	case 0x48: printf("MOV    C,B"); break;
	case 0x49: printf("MOV    C,C"); break;
	case 0x4a: printf("MOV    C,D"); break;
	case 0x4b: printf("MOV    C,E"); break;
	case 0x4c: printf("MOV    C,H"); break;
	case 0x4d: printf("MOV    C,L"); break;
	case 0x4e: printf("MOV    C,M"); break;
	case 0x4f: printf("MOV    C,A"); break;

	case 0x50: printf("MOV    D,B"); break;
	case 0x51: printf("MOV    D,C"); break;
	case 0x52: printf("MOV    D,D"); break;
	case 0x53: printf("MOV    D.E"); break;
	case 0x54: printf("MOV    D,H"); break;
	case 0x55: printf("MOV    D,L"); break;
	case 0x56: printf("MOV    D,M"); break;
	case 0x57: printf("MOV    D,A"); break;
	case 0x58: printf("MOV    E,B"); break;
	case 0x59: printf("MOV    E,C"); break;
	case 0x5a: printf("MOV    E,D"); break;
	case 0x5b: printf("MOV    E,E"); break;
	case 0x5c: printf("MOV    E,H"); break;
	case 0x5d: printf("MOV    E,L"); break;
	case 0x5e: printf("MOV    E,M"); break;
	case 0x5f: printf("MOV    E,A"); break;

	case 0x60: printf("MOV    H,B"); break;
	case 0x61: printf("MOV    H,C"); break;
	case 0x62: printf("MOV    H,D"); break;
	case 0x63: printf("MOV    H.E"); break;
	case 0x64: printf("MOV    H,H"); break;
	case 0x65: printf("MOV    H,L"); break;
	case 0x66: printf("MOV    H,M"); break;
	case 0x67: printf("MOV    H,A"); break;
	case 0x68: printf("MOV    L,B"); break;
	case 0x69: printf("MOV    L,C"); break;
	case 0x6a: printf("MOV    L,D"); break;
	case 0x6b: printf("MOV    L,E"); break;
	case 0x6c: printf("MOV    L,H"); break;
	case 0x6d: printf("MOV    L,L"); break;
	case 0x6e: printf("MOV    L,M"); break;
	case 0x6f: printf("MOV    L,A"); break;

	case 0x70: printf("MOV    M,B"); break;
	case 0x71: printf("MOV    M,C"); break;
	case 0x72: printf("MOV    M,D"); break;
	case 0x73: printf("MOV    M.E"); break;
	case 0x74: printf("MOV    M,H"); break;
	case 0x75: printf("MOV    M,L"); break;
	case 0x76: printf("HLT");        break;
	case 0x77: printf("MOV    M,A"); break;
	case 0x78: printf("MOV    A,B"); break;
	case 0x79: printf("MOV    A,C"); break;
	case 0x7a: printf("MOV    A,D"); break;
	case 0x7b: printf("MOV    A,E"); break;
	case 0x7c: printf("MOV    A,H"); break;
	case 0x7d: printf("MOV    A,L"); break;
	case 0x7e: printf("MOV    A,M"); break;
	case 0x7f: printf("MOV    A,A"); break;

	case 0x80: printf("ADD    B"); break;
	case 0x81: printf("ADD    C"); break;
	case 0x82: printf("ADD    D"); break;
	case 0x83: printf("ADD    E"); break;
	case 0x84: printf("ADD    H"); break;
	case 0x85: printf("ADD    L"); break;
	case 0x86: printf("ADD    M"); break;
	case 0x87: printf("ADD    A"); break;
	case 0x88: printf("ADC    B"); break;
	case 0x89: printf("ADC    C "); break;
	case 0x8a: printf("ADC    D"); break;
	case 0x8b: printf("ADC    E"); break;
	case 0x8c: printf("ADC    H"); break;
	case 0x8d: printf("ADC    L"); break;
	case 0x8e: printf("ADC    M"); break;
	case 0x8f: printf("ADC    A"); break;

	case 0x90: printf("SUB    B"); break;
	case 0x91: printf("SUB    C"); break;
	case 0x92: printf("SUB    D"); break;
	case 0x93: printf("SUB    E"); break;
	case 0x94: printf("SUB    H"); break;
	case 0x95: printf("SUB    L"); break;
	case 0x96: printf("SUB    M"); break;
	case 0x97: printf("SUB    A"); break;
	case 0x98: printf("SBB    B"); break;
	case 0x99: printf("SBB    C"); break;
	case 0x9a: printf("SBB    D"); break;
	case 0x9b: printf("SBB    E"); break;
	case 0x9c: printf("SBB    H"); break;
	case 0x9d: printf("SBB    L"); break;
	case 0x9e: printf("SBB    M"); break;
	case 0x9f: printf("SBB    A"); break;

	case 0xa0: printf("ANA    B"); break;
	case 0xa1: printf("ANA    C"); break;
	case 0xa2: printf("ANA    D"); break;
	case 0xa3: printf("ANA    E"); break;
	case 0xa4: printf("ANA    H"); break;
	case 0xa5: printf("ANA    L"); break;
	case 0xa6: printf("ANA    M"); break;
	case 0xa7: printf("ANA    A"); break;
	case 0xa8: printf("XRA    B"); break;
	case 0xa9: printf("XRA    C"); break;
	case 0xaa: printf("XRA    D"); break;
	case 0xab: printf("XRA    E"); break;
	case 0xac: printf("XRA    H"); break;
	case 0xad: printf("XRA    L"); break;
	case 0xae: printf("XRA    M"); break;
	case 0xaf: printf("XRA    A"); break;

	case 0xb0: printf("ORA    B"); break;
	case 0xb1: printf("ORA    C"); break;
	case 0xb2: printf("ORA    D"); break;
	case 0xb3: printf("ORA    E"); break;
	case 0xb4: printf("ORA    H"); break;
	case 0xb5: printf("ORA    L"); break;
	case 0xb6: printf("ORA    M"); break;
	case 0xb7: printf("ORA    A"); break;
	case 0xb8: printf("CMP    B"); break;
	case 0xb9: printf("CMP    C"); break;
	case 0xba: printf("CMP    D"); break;
	case 0xbb: printf("CMP    E"); break;
	case 0xbc: printf("CMP    H"); break;
	case 0xbd: printf("CMP    L"); break;
	case 0xbe: printf("CMP    M"); break;
	case 0xbf: printf("CMP    A"); break;

	case 0xc0: printf("RNZ"); break;
	case 0xc1: printf("POP 		B"); break;
	case 0xc2: printf("JNZ 		$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0xc3: printf("JMP 		#$02x02x", code[2], code[1]); opBytes = 3; break;
	case 0xc4: printf("CNZ 		$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0xc5: printf("PUSH		B"); break;
	case 0xc6: printf("ADI 		D, #$%02x", code[1]); opBytes = 2; break;
	case 0xc7: printf("RST 		0"); break;
	case 0xc8: printf("JZ			$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0xc9: printf("RET"); break;
	case 0xca: printf("JZ 		$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0xcb: printf("JMP		$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0xcc: printf("CZ 		$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0xcd: printf("CALL 	$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0xce: printf("ACI 		$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0xcf: printf("RST		1"); break;

	case 0xd0: printf("RNC"); break;
	case 0xd1: printf("POP 		D"); break;
	case 0xd2: printf("JNC		$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0xd3: printf("OUT 		$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0xd4: printf("CNC 		$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0xd5: printf("PUSH 	D"); break;
	case 0xd6: printf("SUI 		$%02x", code[1]); opBytes = 2; break;
	case 0xd7: printf("RTS 		2"); break;
	case 0xd8: printf("RC"); break;
	case 0xd9: printf("RET"); break;
	case 0xda: printf("JC 		$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0xdb: printf("IN 		$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0xdc: printf("CC 		$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0xdd: printf("CALL 	$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0xde: printf("SBI 		$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0xdf: printf("RST		3"); break;

	case 0xe0: printf("RPO"); break;
	case 0xe1: printf("POP 		H"); break;
	case 0xe2: printf("JPO 		$%02x02x", code[2], code[1]); break;
	case 0xe3: printf("XHTL"); break;
	case 0xe4: printf("CPO 		$%02x02x", code[2], code[1]); break;
	case 0xe5: printf("PUSH 	H"); break;
	case 0xe6: printf("ANI		$%02x02x", code[2], code[1]); break;
	case 0xe7: printf("RST 		4"); break;
	case 0xe8: printf("RPE"); break;
	case 0xe9: printf("PCHL"); break;
	case 0xea: printf("JPE 		$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0xeb: printf("XCHG"); break;
	case 0xec: printf("CPE 		$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0xed: printf("CALL 	$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0xee: printf("XRI		$%02x02x", code[2], code[1]); opBytes = 3; break;
	case 0xef: printf("RST 		5"); break;

	case 0xf0: printf("RP");  break;
	case 0xf1: printf("POP    PSW"); break;
	case 0xf2: printf("JP     $%02x%02x", code[2], code[1]); opBytes = 3; break;
	case 0xf3: printf("DI");  break;
	case 0xf4: printf("CP     $%02x%02x", code[2], code[1]); opBytes = 3; break;
	case 0xf5: printf("PUSH   PSW"); break;
	case 0xf6: printf("ORI    #$%02x", code[1]); opBytes = 2; break;
	case 0xf7: printf("RST    6"); break;
	case 0xf8: printf("RM");  break;
	case 0xf9: printf("SPHL"); break;
	case 0xfa: printf("JM     $%02x%02x", code[2], code[1]); opBytes = 3; break;
	case 0xfb: printf("EI");  break;
	case 0xfc: printf("CM     $%02x%02x", code[2], code[1]); opBytes = 3; break;
	case 0xfd: printf("CALL   $%02x%02x", code[2], code[1]); opBytes = 3; break;
	case 0xfe: printf("CPI    #$%02x", code[1]); opBytes = 2; break;
	case 0xff: printf("RST    7"); break;
	}

	printf("\n");

	return opBytes;
}

typedef struct ConditionCodes {

	uint8_t z : 1;
	uint8_t s : 1;
	uint8_t p : 1;
	uint8_t cy : 1;
	uint8_t ac : 1;
	uint8_t pad : 3;

}	ConditionCodes;

typedef struct State8080 {

	uint8_t a;
	uint8_t b;
	uint8_t c;
	uint8_t d;
	uint8_t e;
	uint8_t h;
	uint8_t l;
	uint16_t sp;
	uint16_t pc;
	uint8_t* memory;
	struct	ConditionCodes cc;
	uint8_t int_enable;

} State8080;

int Eumulate8080p(State8080* state)
{
	unsigned char* opcode = &state->memory[state->pc];

	switch (*opcode)
	{
	case 0x00: break; 										//NOP

	case 0x01: state->c = opcode[1];		//LXI 	B, word
		state->b = opcode[2];
		state->pc += 2;					//Advance program counter 2 more bytes
		break;

	case 0x02:                             // STAX B - Stores register pair BC in accumulator
		uint16_t register_pair_BC = (state->b << 8) | (state->c);
		state->a = register_pair_BC;
		break;
	case 0x03:   // INX B - Increments register pair BC by 1. The most significant byte of the result is stored in register B and the least significant byte is stored in register C.
		uint16_t register_pair_BC = (state->b << 8) | (state->c);

		register_pair_BC += 1;

		state->b = register_pair_BC & 0xFF00; // Register B gets MS byte
		state->c = register_pair_BC & 0x00FF; // Register C gets LS byte
		break;
	case 0x04: // INR B - Increment register B by 1 and store the result in register B. Set Z, S, P, AC flags.
		state->b = state->b + 1;
		state->cc.z = ((state->b) == 0);
		state->cc.s = ((state->b & 0x80) == 0x80);
		state->cc.p = parity(state->b, 8);
		state->cc.ac = ((state->b & 0xf) == 0xf);
		break;
	case 0x05: // DCR B - Decrement register B by 1 and store the result in register B. Set Z, S, P, AC flags.
		state->b = state->b - 1;
		state->cc.z = ((state->b) == 0);
		state->cc.s = ((state->b & 0x80) == 0x80);
		state->cc.p = parity(state->b, 8);
		state->cc.ac = ((state->b & 0xf) == 0x0);
		break;
	case 0x06: //MVI B, D8 - Move immediate 8 bit value into register B. Instruction length: 2 bytes
		uint16_t immediate_value = (opcode[2] << 8) | (opcode[1]);
		state->b = immediate_value;
		state->pc++; // increment program counter by one since this instruction is 2 bytes long
		break;

	// Instruction 0x07 (RLC) not implemented yet
	// Instruction 0x08 does nothing

	case 0x09: // DAD B - Add register pair HL and register pair BC. Store the result in register pair HL. Set carry flag.
		uint32_t register_pair_HL = (state->h << 8) | (state->l);
		uint32_t register_pair_BC = (state->b << 8) | (state->c);

		register_pair_HL = register_pair_HL + register_pair_BC;

		state->h = register_pair_HL & 0xFFFF0000; // h  gets most significant byte
		state->l = register_pair_HL & 0x0000FFFF; // l gets least significant byte
		break;
	case 0x2f:														//NOT
		state->a = ~state->a;
		break;

	case 0x41: state->b = state->c; 	//MOV 	B, C
		break;
	case 0x42: state->b = state->d; 	//MOV 	B, D
		break;
	case 0x43: state->b = state->e; 	//MOV 	B, E
		break;

	case 0x81: 													//ADD 	C
		uint16_t answer = (uint16_t)state->a + (uint16_t)state->c;
		state->cc.z = ((answer & 0xff) == 0);
		state->cc.s = ((answer & 0x80) != 0);
		state->cc.cy = (answer > 0xff);
		state->cc.p = Parity(answer & 0xff);
		state->a = answer & 0xff;
		break;

	case 0x86:														//ADD 	M
		uint16_t offset = (state->h << 8) | (state->l);
		uint16_t answer = (uint16_t)state->a + state->memory[offset];
		state->cc.z = ((answer & 0xff));
		state->cc.s = ((answer & 0x80));
		state->cc.cy = (answer > 0xff);
		state->cc.p = Parity(answer & 0xff);
		state->a = answer & 0xff;
		break;

	case 0xc2: 													//JNZ adress
		if (0 == state->cc.z)
			state->pc = (opcode[2] << 8) | opcode[1];
		else
			state->pc += 2;
		break;

	case 0xc3: 													//JMP adress
		state->pc = (opcode[2] << 8) | opcode[1];
		break;

	case 0xc6:														//ADI 	byte
		uint16_t answer = (uint16_t)state->a + (uint16_t)opcode[1];
		state->cc.z = ((answer & 0xff) == 0);
		state->cc.s = ((answer & 0x80) != 0);
		state->cc.cy = (answer > 0xff);
		state->cc.p = Parity(answer & 0xff);
		state->a = answer & 0xff;
		break;
	case 0x9c: 													//RET
		state->pc = state->memory[state->sp] | (state->memory[state->sp + 1] << 8);
		state->sp += 2;
		break;

	case 0xcd: 													//CALL address
		uint16_t ret = state->pc + 2;
		state->memory[state->sp - 1] = (ret >> 8) & 0xff;
		state->memory[state->sp - 2] = (ret & 0xff);
		state->sp = state->sp - 2;
		state->pc = (opcode[2] << 8) | opcode[1];
		break;

	case 0xe6:														//ANI byte
		uint8_t x = state -> & opcode[1];
		state->cc.z = (x == 0);
		state->cc.s = (0x80 == (x & 0x80));
		state->cc.p = Parity(x, 8);
		state->cc.cy = 0;
		state->a = x;
		state->pc++;
		break;

	}

	state->pc += 1;
}

int main()
{
	//Open the file at the designated location
	//std::ios::in opens the file for input operations
	//std::ios::binary opens the file in binary mode
	//std::ios::ate sets the initial position at the end of the file. If not set the initial position will be at the begining
	std::fstream myFile("rom/invaders", std::ios::in | std::ios::binary | std::ios::ate);

	//Declare the size a memoryblock variables
	std::streampos size;
	unsigned char* memblock;

	//If the file has opened successfuly
	if (myFile.is_open())
	{
		//Set the size to the current get positon of the file
		//std::ios::ate set the get positon at the end of the file so size is going to be equal to the size of the file
		size = myFile.tellg();
		//Alocate memory equal to the size of the File
		memblock = new unsigned char[size];
		//Set the get positon back to the begining
		myFile.seekg(0, std::ios::beg);
		//Read the file into the memory block
		myFile.read((char*)memblock, size);
		//Close the file after we're done reading it to return resources to the computer
		myFile.close();


		std::cout << "File loaded successfuly " << "\n";
	}
	else
		std::cout << "Could not open File" << "\n";


	int pc = 0;

	while (pc < size)
	{
		pc += Dissassemble8080p(memblock, pc);
	}


	return 0;
}
