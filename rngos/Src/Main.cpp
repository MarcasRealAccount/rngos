#include "Utils/Core.h"

#include <bit>
#include <chrono>
#include <fstream>
#include <iostream>
#include <random>

#include <intrin.h>

extern "C" std::uint8_t  rngos_intrin_add8_f(std::uint8_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint16_t rngos_intrin_add16_f(std::uint16_t a, std::uint16_t b, std::uint64_t* pFlags);
extern "C" std::uint8_t  rngos_intrin_adc8_f(std::uint8_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint16_t rngos_intrin_adc16_f(std::uint16_t a, std::uint16_t b, std::uint64_t* pFlags);

extern "C" std::uint8_t  rngos_intrin_sub8_f(std::uint8_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint16_t rngos_intrin_sub16_f(std::uint16_t a, std::uint16_t b, std::uint64_t* pFlags);
extern "C" std::uint8_t  rngos_intrin_sbb8_f(std::uint8_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint16_t rngos_intrin_sbb16_f(std::uint16_t a, std::uint16_t b, std::uint64_t* pFlags);

extern "C" std::uint16_t rngos_intrin_mul8_f(std::uint8_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint16_t rngos_intrin_imul8_f(std::uint8_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint32_t rngos_intrin_mul16_f(std::uint16_t a, std::uint16_t b, std::uint64_t* pFlags);
extern "C" std::uint32_t rngos_intrin_imul16_f(std::uint16_t a, std::uint16_t b, std::uint64_t* pFlags);

extern "C" std::uint16_t rngos_intrin_div8_f(std::uint16_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint16_t rngos_intrin_idiv8_f(std::uint16_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint32_t rngos_intrin_div16_f(std::uint16_t a, std::uint16_t b, std::uint16_t c, std::uint64_t* pFlags);
extern "C" std::uint32_t rngos_intrin_idiv16_f(std::uint16_t a, std::uint16_t b, std::uint16_t c, std::uint64_t* pFlags);

extern "C" std::uint8_t  rngos_intrin_rol8_f(std::uint8_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint8_t  rngos_intrin_ror8_f(std::uint8_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint8_t  rngos_intrin_rcl8_f(std::uint8_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint8_t  rngos_intrin_rcr8_f(std::uint8_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint8_t  rngos_intrin_shl8_f(std::uint8_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint8_t  rngos_intrin_shr8_f(std::uint8_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint8_t  rngos_intrin_sar8_f(std::uint8_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint16_t rngos_intrin_rol16_f(std::uint16_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint16_t rngos_intrin_ror16_f(std::uint16_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint16_t rngos_intrin_rcl16_f(std::uint16_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint16_t rngos_intrin_rcr16_f(std::uint16_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint16_t rngos_intrin_shl16_f(std::uint16_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint16_t rngos_intrin_shr16_f(std::uint16_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint16_t rngos_intrin_sar16_f(std::uint16_t a, std::uint8_t b, std::uint64_t* pFlags);

extern "C" std::uint8_t  rngos_intrin_and8_f(std::uint8_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint16_t rngos_intrin_and16_f(std::uint16_t a, std::uint8_t b, std::uint64_t* pFlags);

extern "C" std::uint8_t  rngos_intrin_or8_f(std::uint8_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint16_t rngos_intrin_or16_f(std::uint16_t a, std::uint8_t b, std::uint64_t* pFlags);

extern "C" std::uint8_t  rngos_intrin_xor8_f(std::uint8_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" std::uint16_t rngos_intrin_xor16_f(std::uint16_t a, std::uint8_t b, std::uint64_t* pFlags);

extern "C" std::uint8_t  rngos_intrin_not8_f(std::uint8_t a, std::uint64_t* pFlags);
extern "C" std::uint16_t rngos_intrin_not16_f(std::uint16_t a, std::uint64_t* pFlags);

extern "C" void rngos_intrin_cmp8_f(std::uint8_t a, std::uint8_t b, std::uint64_t* pFlags);
extern "C" void rngos_intrin_cmp16_f(std::uint16_t a, std::uint16_t b, std::uint64_t* pFlags);

std::mt19937_64 s_RNG { std::random_device {}() };

void randomize(std::uint8_t* bytes, std::size_t count)
{
	std::size_t end = (count / 8) * 8;
	for (std::size_t i = 0; i < end; i += 8)
		*reinterpret_cast<std::uint64_t*>(bytes + i) = s_RNG();
	if (end == count)
		return;
	std::uint64_t value = s_RNG();
	for (std::uint8_t i = 0; i < count - end; ++i)
		bytes[end + i] = reinterpret_cast<std::uint8_t*>(&value)[i];
}

struct ModRM
{
	std::uint8_t mod : 2;
	std::uint8_t reg : 3;
	std::uint8_t rm : 3;
};

struct CPU
{
public:
	void boot(std::uint8_t* bytes, std::size_t count)
	{
		AX = 0;
		DX = 0;
		CX = 0;
		BX = 0;
		BP = 0;
		SI = 0;
		DI = 0;
		SP = 0;
		CS = 0;
		DS = 0;
		SS = 0;
		ES = 0;
		F  = 0;
		IP = 0x7C00;
		std::memset(memory, 0, 0x7C00);
		std::memcpy(memory + 0x7C00, bytes, count);
		std::memset(memory + 0x7C00 + count, 0, sizeof(memory) - 0x7C00 - count);

		run();
	}

	void run()
	{
		while (Interrupt == 0)
		{
			executeInstruction();
		}
	}

	void executeInstruction()
	{
		bool         prefix      = true;
		std::uint8_t rep         = 0;
		std::uint8_t so          = 0;
		std::uint8_t instruction = memory[EIP()];
		++IP;
		while (prefix)
		{
			switch (instruction)
			{
			case 0b00'10'01'10: [[fallthrough]]; // SO ES
			case 0b00'10'11'10: [[fallthrough]]; // SO CS
			case 0b00'11'01'10: [[fallthrough]]; // SO SS
			case 0b00'11'11'10:                  // SO DS
				so          = instruction;
				instruction = memory[EIP()];
				++IP;
				break;
			case 0b11'11'00'10: [[fallthrough]]; // REP
			case 0b11'11'00'11:                  // REPN
				rep         = instruction;
				instruction = memory[EIP()];
				++IP;
				break;
			default:
				prefix = false;
				break;
			}
		}

		switch (instruction)
		{
		// MOV
		case 0b10'00'10'00: // MOV 8 bit Reg to Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;
			switch (modrm.mod)
			{
			case 0b11: // Reg to Reg
				setReg8Bit(modrm.rm, reg8Bit(modrm.reg));
				break;
			default: // Reg to Mem
				write8Bit(realAddress(modrm, so), reg8Bit(modrm.reg));
				break;
			}
			break;
		}
		case 0b10'00'10'01: // MOV 16 bit Reg to Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;
			switch (modrm.mod)
			{
			case 0b11: // Reg to Reg
				setReg16Bit(modrm.rm, reg16Bit(modrm.reg));
				break;
			default: // Reg to Mem
				write16Bit(realAddress(modrm, so), reg16Bit(modrm.reg));
				break;
			}
			break;
		}
		case 0b10'00'10'10: // MOV 8 bit Reg/Mem to Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;
			switch (modrm.mod)
			{
			case 0b11: // Reg to Reg
				setReg8Bit(modrm.reg, reg8Bit(modrm.rm));
				break;
			default: // Mem to Reg
				setReg8Bit(modrm.reg, read8Bit(realAddress(modrm, so)));
				break;
			}
			break;
		}
		case 0b10'00'10'11: // MOV 16 bit Reg/Mem to Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;
			switch (modrm.mod)
			{
			case 0b11: // Reg to Reg
				setReg16Bit(modrm.reg, reg16Bit(modrm.rm));
				break;
			default: // Mem to Reg
				setReg16Bit(modrm.reg, read16Bit(realAddress(modrm, so)));
				break;
			}
			break;
		}
		case 0b11'00'01'10: // MOV 8 bit Imm to Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			if (modrm.reg != 0)
			{
				interrupt(s_InvalidInstruction);
				return;
			}

			std::uint32_t ea = realAddress(modrm, so);

			std::uint8_t imm = memory[EIP()];
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Imm to Reg
				setReg8Bit(modrm.rm, imm);
				break;
			default: // Imm to Mem
				write8Bit(ea, imm);
				break;
			}
			break;
		}
		case 0b11'00'01'11: // MOV 16 bit Imm to Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			if (modrm.reg != 0)
			{
				interrupt(s_InvalidInstruction);
				return;
			}

			std::uint32_t ea = realAddress(modrm, so);

			std::uint16_t imm = memory[EIP()] << 8;
			++IP;
			imm |= memory[EIP()];
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Imm to Reg
				setReg16Bit(modrm.rm, imm);
				break;
			default: // Imm to Mem
				write16Bit(ea, imm);
				break;
			}
			break;
		}
		case 0b10'11'00'00: [[fallthrough]]; // MOV 8 bit Imm to AL
		case 0b10'11'00'01: [[fallthrough]]; // MOV 8 bit Imm to CL
		case 0b10'11'00'10: [[fallthrough]]; // MOV 8 bit Imm to DL
		case 0b10'11'00'11: [[fallthrough]]; // MOV 8 bit Imm to BL
		case 0b10'11'01'00: [[fallthrough]]; // MOV 8 bit Imm to AH
		case 0b10'11'01'01: [[fallthrough]]; // MOV 8 bit Imm to CH
		case 0b10'11'01'10: [[fallthrough]]; // MOV 8 bit Imm to DH
		case 0b10'11'01'11:                  // MOV 8 bit Imm to BH
		{
			std::uint8_t imm = memory[EIP()];
			++IP;
			setReg8Bit(instruction & 0b111, imm);
			break;
		}
		case 0b10'11'10'00: [[fallthrough]]; // MOV 16 bit Imm to AX
		case 0b10'11'10'01: [[fallthrough]]; // MOV 16 bit Imm to CX
		case 0b10'11'10'10: [[fallthrough]]; // MOV 16 bit Imm to DX
		case 0b10'11'10'11: [[fallthrough]]; // MOV 16 bit Imm to BX
		case 0b10'11'11'00: [[fallthrough]]; // MOV 16 bit Imm to SP
		case 0b10'11'11'01: [[fallthrough]]; // MOV 16 bit Imm to BP
		case 0b10'11'11'10: [[fallthrough]]; // MOV 16 bit Imm to SI
		case 0b10'11'11'11:                  // MOV 16 bit Imm to DI
		{
			std::uint16_t imm = memory[EIP()] << 8;
			++IP;
			imm |= memory[EIP()];
			++IP;
			setReg16Bit(instruction & 0b111, imm);
			break;
		}
		case 0b10'10'00'00: // MOV 8 bit Mem to AL
		{
			std::uint16_t addr = memory[EIP()];
			++IP;
			addr |= memory[EIP()] << 8;
			++IP;

			AL(read8Bit((segmentOverride(so, DS) << 4) + addr));
			break;
		}
		case 0b10'10'00'01: // MOV 16 bit Mem to AX
		{
			std::uint16_t addr = memory[EIP()];
			++IP;
			addr |= memory[EIP()] << 8;
			++IP;

			AX = read16Bit((segmentOverride(so, DS) << 4) + addr);
			break;
		}
		case 0b10'10'00'10: // MOV 8 bit AL to Mem
		{
			std::uint16_t addr = memory[EIP()];
			++IP;
			addr |= memory[EIP()] << 8;
			++IP;

			write8Bit((segmentOverride(so, DS) << 4) + addr, AL());
			break;
		}
		case 0b10'10'00'11: // MOV 16 bit AX to Mem
		{
			std::uint16_t addr = memory[EIP()];
			++IP;
			addr |= memory[EIP()] << 8;
			++IP;

			write16Bit((segmentOverride(so, DS) << 4) + addr, AX);
			break;
		}
		case 0b10'00'11'10: // MOV Reg/Mem to Segment Register
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			if (modrm.reg & 0b100)
			{
				interrupt(s_InvalidInstruction);
				return;
			}

			switch (modrm.mod)
			{
			case 0b11: // Reg to Segment Register
				setRegSeg(modrm.reg, reg16Bit(modrm.rm));
				break;
			default:
				setRegSeg(modrm.reg, read16Bit(realAddress(modrm, so)));
				break;
			}
			break;
		}
		case 0b10'00'11'00: // MOV Segment Register to Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			if (modrm.reg & 0b100)
			{
				interrupt(s_InvalidInstruction);
				return;
			}

			switch (modrm.mod)
			{
			case 0b11: // Segment Register to Reg
				setReg16Bit(modrm.rm, regSeg(modrm.reg));
				break;
			default:
				write16Bit(realAddress(modrm, so), regSeg(modrm.reg));
				break;
			}
			break;
		}

		// PUSH
		case 0b11'11'11'11: // PUSH Mem | INC 16 bit Reg/Mem | DEC 16 bit Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.reg)
			{
			case 0b000: // INC 16 bit Reg/Mem
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, add16Bit(reg16Bit(modrm.rm), 1));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write16Bit(ra, add16Bit(read16Bit(ra), 1));
					break;
				}
				}
				break;
			case 0b001: // DEC 16 bit Reg/Mem
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, sub16Bit(reg16Bit(modrm.rm), 1));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write16Bit(ra, sub16Bit(read16Bit(ra), 1));
					break;
				}
				}
				break;
			case 0b110: // PUSH Mem
				push16Bit(read16Bit(realAddress(modrm, so)));
				break;
			default:
				interrupt(s_InvalidInstruction);
				return;
			}
			break;
		}
		case 0b01'01'00'00: [[fallthrough]]; // PUSH AX
		case 0b01'01'00'01: [[fallthrough]]; // PUSH CX
		case 0b01'01'00'10: [[fallthrough]]; // PUSH DX
		case 0b01'01'00'11: [[fallthrough]]; // PUSH BX
		case 0b01'01'01'00: [[fallthrough]]; // PUSH SP
		case 0b01'01'01'01: [[fallthrough]]; // PUSH BP
		case 0b01'01'01'10: [[fallthrough]]; // PUSH SI
		case 0b01'01'01'11:                  // PUSH DI
		{
			push16Bit(reg16Bit(instruction & 0b111));
			break;
		}
		case 0b00'00'01'10: [[fallthrough]]; // PUSH ES
		case 0b00'00'11'10: [[fallthrough]]; // PUSH CS
		case 0b00'01'01'10: [[fallthrough]]; // PUSH SS
		case 0b00'01'11'10:                  // PUSH DS
		{
			push16Bit(regSeg((instruction >> 3) & 0b11));
			break;
		}
		case 0b01'10'10'10: // PUSH 8 bit
		{
			std::uint8_t imm = memory[EIP()];
			++IP;
			push8Bit(imm);
			break;
		}
		case 0b01'10'10'00: // PUSH 16 bit
		{
			std::uint16_t imm = memory[EIP()];
			++IP;
			imm |= memory[EIP()] << 8;
			++IP;
			push16Bit(imm);
			break;
		}
		case 0b01'10'00'00: // PUSHA
		{
			std::uint16_t temp = SP;
			push16Bit(AX);
			push16Bit(CX);
			push16Bit(DX);
			push16Bit(BX);
			push16Bit(temp);
			push16Bit(BP);
			push16Bit(SI);
			push16Bit(DI);
			break;
		}
		case 0b10'01'11'00: // PUSHF
		{
			push16Bit(F);
			break;
		}

		// POP
		case 0b10'00'11'11: // POP Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			if (modrm.reg != 0b110 || modrm.mod == 0b11)
			{
				interrupt(s_InvalidInstruction);
				return;
			}

			write16Bit(realAddress(modrm, so), pop16Bit());
			break;
		}
		case 0b01'01'10'00: [[fallthrough]]; // POP AX
		case 0b01'01'10'01: [[fallthrough]]; // POP CX
		case 0b01'01'10'10: [[fallthrough]]; // POP DX
		case 0b01'01'10'11: [[fallthrough]]; // POP BX
		case 0b01'01'11'00: [[fallthrough]]; // POP SP
		case 0b01'01'11'01: [[fallthrough]]; // POP BP
		case 0b01'01'11'10: [[fallthrough]]; // POP SI
		case 0b01'01'11'11:                  // POP DI
		{
			setReg16Bit(instruction & 0b111, pop16Bit());
			break;
		}
		case 0b00'00'01'11: [[fallthrough]]; // POP ES
		case 0b00'00'11'11: [[fallthrough]]; // POP CS
		case 0b00'01'01'11: [[fallthrough]]; // POP SS
		case 0b00'01'11'11:                  // POP DS
		{
			if (instruction == 0b00'00'11'11)
			{
				interrupt(s_InvalidInstruction);
				return;
			}

			setRegSeg((instruction >> 3) & 0b11, pop16Bit());
			break;
		}
		case 0b01'10'00'01: // POPA
		{
			DI                 = pop16Bit();
			SI                 = pop16Bit();
			BP                 = pop16Bit();
			std::uint16_t temp = pop16Bit();
			BX                 = pop16Bit();
			DX                 = pop16Bit();
			CX                 = pop16Bit();
			AX                 = pop16Bit();
			SP                 = temp;
			break;
		}
		case 0b10'01'11'01: // POPF
		{
			F = pop16Bit();
			break;
		}

		// XCHG
		case 0b10'00'01'10: // XCHG 8 bit Reg/Mem with Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg with Reg
			{
				std::uint8_t value = reg8Bit(modrm.rm);
				setReg8Bit(modrm.rm, reg8Bit(modrm.reg));
				setReg8Bit(modrm.reg, value);
				break;
			}
			default: // Mem with Reg
			{
				std::uint32_t ea    = realAddress(modrm, so);
				std::uint8_t  value = read8Bit(ea);
				write8Bit(ea, reg8Bit(modrm.reg));
				setReg8Bit(modrm.reg, value);
				break;
			}
			}
			break;
		}
		case 0b10'00'01'11: // XCHG 16 bit Reg/Mem with Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg with Reg
			{
				std::uint16_t value = reg16Bit(modrm.rm);
				setReg16Bit(modrm.rm, reg16Bit(modrm.reg));
				setReg16Bit(modrm.reg, value);
				break;
			}
			default: // Mem with Reg
			{
				std::uint32_t ea    = realAddress(modrm, so);
				std::uint16_t value = read16Bit(ea);
				write16Bit(ea, reg16Bit(modrm.reg));
				setReg16Bit(modrm.reg, value);
				break;
			}
			}
			break;
		}
		case 0b10'01'00'00: return;          // XCHG AX with AX => NOP
		case 0b10'01'00'01: [[fallthrough]]; // XCHG CX with AX
		case 0b10'01'00'10: [[fallthrough]]; // XCHG DX with AX
		case 0b10'01'00'11: [[fallthrough]]; // XCHG BX with AX
		case 0b10'01'01'00: [[fallthrough]]; // XCHG SP with AX
		case 0b10'01'01'01: [[fallthrough]]; // XCHG BP with AX
		case 0b10'01'01'10: [[fallthrough]]; // XCHG SI with AX
		case 0b10'01'01'11:                  // XCHG DI with AX
		{
			std::uint16_t value = reg16Bit(instruction & 0b111);
			setReg16Bit(instruction & 0b111, AX);
			setReg16Bit(AX, value);
			break;
		}

		// IN
		case 0b11'10'01'00: // IN 8 bit PORT
		{
			std::uint8_t port = memory[EIP()];
			++IP;
			AX = in8Bit(port);
			break;
		}
		case 0b11'10'01'01: // IN 16 bit PORT
		{
			std::uint8_t port = memory[EIP()];
			++IP;
			AX = in16Bit(port);
			break;
		}
		case 0b11'10'11'00: // IN 8 bit vPORT
		{
			AX = in8Bit(DX);
			break;
		}
		case 0b11'10'11'01: // IN 16 bit vPORT
		{
			AX = in16Bit(DX);
			break;
		}

		// OUT
		case 0b11'10'01'10: // OUT 8 bit PORT
		{
			std::uint8_t port = memory[EIP()];
			++IP;
			out8Bit(port, AL());
			break;
		}
		case 0b11'10'01'11: // OUT 16 bit PORT
		{
			std::uint8_t port = memory[EIP()];
			++IP;
			out16Bit(port, AX);
			break;
		}
		case 0b11'10'11'10: // OUT 8 bit vPORT
		{
			out8Bit(DX, AL());
			break;
		}
		case 0b11'10'11'11: // OUT 16 bit vPORT
		{
			out16Bit(DX, AX);
			break;
		}

		case 0b11'01'01'11: // XLAT
		{
			AX = (segmentOverride(so, DS) << 4) + BX + AL();
			break;
		}

		case 0b10'00'11'01: // LEA EA to Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;
			setReg16Bit(modrm.reg, effectiveAddress(modrm));
			break;
		}

		case 0b11'00'01'01: // LDS Pointer to DS
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;
			if (modrm.mod == 11)
			{
				interrupt(s_InvalidInstruction);
				return;
			}

			setReg16Bit(modrm.reg, effectiveAddress(modrm));
			DS = static_cast<std::uint16_t>(segmentOverride(so, DS));
			break;
		}
		case 0b11'00'01'00: // LES Pointer to ES
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;
			if (modrm.mod == 11)
			{
				interrupt(s_InvalidInstruction);
				return;
			}

			setReg16Bit(modrm.reg, effectiveAddress(modrm));
			ES = static_cast<std::uint16_t>(segmentOverride(so, DS));
			break;
		}

		case 0b10'01'11'11: // LAHF
		{
			AH(static_cast<std::uint8_t>(F));
			break;
		}
		case 0b10'01'11'10: // SAHF
		{
			F = F & 0xFF00 | AH();
			break;
		}

		// ADD
		case 0b00'00'00'00: // ADD 8 bit Reg to Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg to Reg
				setReg8Bit(modrm.rm, add8Bit(reg8Bit(modrm.rm), reg8Bit(modrm.reg)));
				break;
			default: // Reg to Mem
			{
				std::uint32_t ra = realAddress(modrm, so);
				write8Bit(ra, add8Bit(read8Bit(ra), reg8Bit(modrm.reg)));
				break;
			}
			}
			break;
		}
		case 0b00'00'00'01: // ADD 16 bit Reg to Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg to Reg
				setReg16Bit(modrm.rm, add16Bit(reg16Bit(modrm.rm), reg16Bit(modrm.reg)));
				break;
			default: // Reg to Mem
			{
				std::uint32_t ra = realAddress(modrm, so);
				write16Bit(ra, add16Bit(read16Bit(ra), reg16Bit(modrm.reg)));
				break;
			}
			}
			break;
		}
		case 0b00'00'00'10: // ADD 8 bit Reg/Mem to Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg to Reg
				setReg8Bit(modrm.reg, add8Bit(reg8Bit(modrm.reg), reg8Bit(modrm.rm)));
				break;
			default: // Mem to Reg
			{
				std::uint32_t ra = realAddress(modrm, so);
				setReg8Bit(modrm.reg, add8Bit(reg8Bit(modrm.reg), read8Bit(ra)));
				break;
			}
			}
			break;
		}
		case 0b00'00'00'11: // ADD 16 bit Reg/Mem to Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg to Reg
				setReg16Bit(modrm.reg, add16Bit(reg16Bit(modrm.reg), reg16Bit(modrm.rm)));
				break;
			default: // Mem to Reg
			{
				std::uint32_t ra = realAddress(modrm, so);
				setReg16Bit(modrm.reg, add16Bit(reg16Bit(modrm.reg), read16Bit(ra)));
				break;
			}
			}
			break;
		}
		case 0b10'00'00'00: // ADD 8 bit Imm to Reg/Mem | ADC 8 bit Imm to Reg/Mem | SUB 8 bit Imm from Reg/Mem | SBB 8 bit Imm from Reg/Mem | CMP 8 bit Imm to Reg/Mem | AND 8 bit Imm with Reg/Mem | OR 8 bit Imm with Reg/Mem | XOR 8 bit Imm with Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			std::uint32_t ra = realAddress(modrm, so);

			std::uint8_t imm = memory[EIP()];
			++IP;

			std::uint8_t a = 0;
			switch (modrm.mod)
			{
			case 0b11: // Reg
				a = reg8Bit(modrm.rm);
				break;
			default: // Mem
				a = read8Bit(ra);
				break;
			}
			std::uint8_t r = 0;

			switch (modrm.reg)
			{
			case 0b000: // ADD
				r = add8Bit(a, imm);
				break;
			case 0b010: // ADC
				r = adc8Bit(a, imm);
				break;
			case 0b101: // SUB
				r = sub8Bit(a, imm);
				break;
			case 0b011: // SBB
				r = sbb8Bit(a, imm);
				break;
			case 0b111: // CMP
				r = a;
				cmp8Bit(a, imm);
				break;
			case 0b100: // AND
				r = and8Bit(a, imm);
				break;
			case 0b001: // OR
				r = or8Bit(a, imm);
				break;
			case 0b110: // XOR
				r = xor8Bit(a, imm);
				break;
			default:
				interrupt(s_InvalidInstruction);
				return;
			}

			switch (modrm.mod)
			{
			case 0b11: // Reg
				setReg8Bit(modrm.rm, r);
				break;
			default: // Mem
				write8Bit(ra, r);
				break;
			}
			break;
		}
		case 0b10'00'00'01: // ADD 16 bit Imm to Reg/Mem | ADC 16 bit Imm to Reg/Mem | SUB 16 bit Imm from Reg/Mem | SBB 16 bit Imm from Reg/Mem | CMP 16 bit Imm to Reg/Mem | AND 16 bit Imm with Reg/Mem | OR 16 bit Imm with Reg/Mem | XOR 16 bit Imm with Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			std::uint32_t ra = realAddress(modrm, so);

			std::uint8_t imm = memory[EIP()] << 8;
			++IP;
			imm |= memory[EIP()];
			++IP;

			std::uint16_t a = 0;
			switch (modrm.mod)
			{
			case 0b11: // Reg
				a = reg16Bit(modrm.rm);
				break;
			default: // Mem
				a = read16Bit(ra);
				break;
			}
			std::uint16_t r = 0;

			switch (modrm.reg)
			{
			case 0b000: // ADD
				r = add16Bit(a, imm);
				break;
			case 0b010: // ADC
				r = adc16Bit(a, imm);
				break;
			case 0b101: // SUB
				r = sub16Bit(a, imm);
				break;
			case 0b011: // SBB
				r = sbb16Bit(a, imm);
				break;
			case 0b111: // CMP
				r = a;
				cmp16Bit(a, imm);
				break;
			case 0b100: // AND
				r = and16Bit(a, imm);
				break;
			case 0b001: // OR
				r = or16Bit(a, imm);
				break;
			case 0b110: // XOR
				r = xor16Bit(a, imm);
				break;
			default:
				interrupt(s_InvalidInstruction);
				return;
			}

			switch (modrm.mod)
			{
			case 0b11: // Reg
				setReg16Bit(modrm.rm, r);
				break;
			default: // Mem
				write16Bit(ra, r);
				break;
			}
			break;
		}
		case 0b10'00'00'10: // ADD sign extended 8 bit Imm to Reg/Mem | ADC sign extended 8 bit Imm to Reg/Mem | SUB sign extended 8 bit Imm from Reg/Mem | SBB sign extended 8 bit Imm from Reg/Mem | CMP sign extended 8 bit Imm to Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			std::uint32_t ra = realAddress(modrm, so);

			std::uint16_t imm = static_cast<std::uint16_t>(static_cast<std::int16_t>(static_cast<std::int8_t>(memory[EIP()])));
			++IP;

			std::uint16_t a = 0;
			switch (modrm.mod)
			{
			case 0b11: // Reg
				a = reg16Bit(modrm.rm);
				break;
			default: // Mem
				a = read16Bit(ra);
				break;
			}
			std::uint16_t r = 0;

			switch (modrm.reg)
			{
			case 0b000: // ADD
				r = add16Bit(a, imm);
				break;
			case 0b010: // ADC
				r = adc16Bit(a, imm);
				break;
			case 0b101: // SUB
				r = sub16Bit(a, imm);
				break;
			case 0b011: // SBB
				r = sbb16Bit(a, imm);
				break;
			case 0b111: // CMP
				r = a;
				cmp16Bit(a, imm);
				break;
			default:
				interrupt(s_InvalidInstruction);
				return;
			}

			switch (modrm.mod)
			{
			case 0b11: // Reg
				setReg16Bit(modrm.rm, r);
				break;
			default: // Mem
				write16Bit(ra, r);
				break;
			}
			break;
		}
		case 0b00'00'01'00: // ADD 8 bit Imm to AL
		{
			std::uint8_t imm = memory[EIP()];
			++IP;

			AX = add8Bit(AL(), imm);
			break;
		}
		case 0b00'00'01'01: // ADD 16 bit Imm to AX
		{
			std::uint8_t imm = memory[EIP()] << 8;
			++IP;
			imm |= memory[EIP()];
			++IP;

			AX = add16Bit(AX, imm);
			break;
		}

		// ADC
		case 0b00'01'00'00: // ADC 8 bit Reg to Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg to Reg
				setReg8Bit(modrm.rm, adc8Bit(reg8Bit(modrm.rm), reg8Bit(modrm.reg)));
				break;
			default: // Reg to Mem
			{
				std::uint32_t ra = realAddress(modrm, so);
				write8Bit(ra, adc8Bit(read8Bit(ra), reg8Bit(modrm.reg)));
				break;
			}
			}
			break;
		}
		case 0b00'01'00'01: // ADC 16 bit Reg to Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg to Reg
				setReg16Bit(modrm.rm, adc16Bit(reg16Bit(modrm.rm), reg16Bit(modrm.reg)));
				break;
			default: // Reg to Mem
			{
				std::uint32_t ra = realAddress(modrm, so);
				write16Bit(ra, adc16Bit(read16Bit(ra), reg16Bit(modrm.reg)));
				break;
			}
			}
			break;
		}
		case 0b00'01'00'10: // ADC 8 bit Reg/Mem to Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg to Reg
				setReg8Bit(modrm.reg, adc8Bit(reg8Bit(modrm.reg), reg8Bit(modrm.rm)));
				break;
			default: // Mem to Reg
			{
				std::uint32_t ra = realAddress(modrm, so);
				setReg8Bit(modrm.reg, adc8Bit(reg8Bit(modrm.reg), read8Bit(ra)));
				break;
			}
			}
			break;
		}
		case 0b00'01'00'11: // ADC 16 bit Reg/Mem to Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg to Reg
				setReg16Bit(modrm.reg, adc16Bit(reg16Bit(modrm.reg), reg16Bit(modrm.rm)));
				break;
			default: // Mem to Reg
			{
				std::uint32_t ra = realAddress(modrm, so);
				setReg16Bit(modrm.reg, adc16Bit(reg16Bit(modrm.reg), read16Bit(ra)));
				break;
			}
			}
			break;
		}
		case 0b00'01'01'00: // ADC 8 bit Imm to AL
		{
			std::uint8_t imm = memory[EIP()];
			++IP;

			AX = adc8Bit(AL(), imm);
			break;
		}
		case 0b00'01'01'01: // ADC 16 bit Imm to AX
		{
			std::uint8_t imm = memory[EIP()] << 8;
			++IP;
			imm |= memory[EIP()];
			++IP;

			AX = adc16Bit(AX, imm);
			break;
		}

		// INC
		case 0b11'11'11'10: // INC 8 bit Reg/Mem | DEC 8 bit Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.reg)
			{
			case 0b000: // INC 8 bit Reg/Mem
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, add8Bit(reg8Bit(modrm.rm), 1));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write8Bit(ra, add8Bit(read8Bit(ra), 1));
					break;
				}
				}
				break;
			case 0b001: // DEC 8 bit Reg/Mem
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, sub8Bit(reg8Bit(modrm.rm), 1));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write8Bit(ra, sub8Bit(read8Bit(ra), 1));
					break;
				}
				}
				break;
			default:
				interrupt(s_InvalidInstruction);
				return;
			}
			break;
		}
		case 0b01'00'00'00: [[fallthrough]]; // INC AX
		case 0b01'00'00'01: [[fallthrough]]; // INC CX
		case 0b01'00'00'10: [[fallthrough]]; // INC DX
		case 0b01'00'00'11: [[fallthrough]]; // INC BX
		case 0b01'00'01'00: [[fallthrough]]; // INC SP
		case 0b01'00'01'01: [[fallthrough]]; // INC BP
		case 0b01'00'01'10: [[fallthrough]]; // INC SI
		case 0b01'00'01'11:                  // INC DI
		{
			setReg16Bit(instruction & 0b111, add16Bit(reg16Bit(instruction & 0b111), 1));
			break;
		}

		// SUB
		case 0b00'10'10'00: // SUB 8 bit Reg from Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg from Reg
				setReg8Bit(modrm.rm, sub8Bit(reg8Bit(modrm.rm), reg8Bit(modrm.reg)));
				break;
			default: // Reg from Mem
			{
				std::uint32_t ra = realAddress(modrm, so);
				write8Bit(ra, sub8Bit(read8Bit(ra), reg8Bit(modrm.reg)));
				break;
			}
			}
			break;
		}
		case 0b00'10'10'01: // SUB 16 bit Reg from Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg from Reg
				setReg16Bit(modrm.rm, sub16Bit(reg16Bit(modrm.rm), reg16Bit(modrm.reg)));
				break;
			default: // Reg from Mem
			{
				std::uint32_t ra = realAddress(modrm, so);
				write16Bit(ra, sub16Bit(read16Bit(ra), reg16Bit(modrm.reg)));
				break;
			}
			}
			break;
		}
		case 0b00'10'10'10: // SUB 8 bit Reg/Mem from Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg from Reg
				setReg8Bit(modrm.reg, sub8Bit(reg8Bit(modrm.reg), reg8Bit(modrm.rm)));
				break;
			default: // Mem from Reg
			{
				std::uint32_t ra = realAddress(modrm, so);
				setReg8Bit(modrm.reg, sub8Bit(reg8Bit(modrm.reg), read8Bit(ra)));
				break;
			}
			}
			break;
		}
		case 0b00'10'10'11: // SUB 16 bit Reg/Mem from Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg from Reg
				setReg16Bit(modrm.reg, sub16Bit(reg16Bit(modrm.reg), reg16Bit(modrm.rm)));
				break;
			default: // Mem from Reg
			{
				std::uint32_t ra = realAddress(modrm, so);
				setReg16Bit(modrm.reg, sub16Bit(reg16Bit(modrm.reg), read16Bit(ra)));
				break;
			}
			}
			break;
		}
		case 0b00'10'11'00: // SUB 8 bit Imm from AL
		{
			std::uint8_t imm = memory[EIP()];
			++IP;

			AX = sub8Bit(AL(), imm);
			break;
		}
		case 0b00'10'11'01: // SUB 16 bit Imm from AX
		{
			std::uint8_t imm = memory[EIP()] << 8;
			++IP;
			imm |= memory[EIP()];

			AX = sub16Bit(AX, imm);
			break;
		}

		// SBB
		case 0b00'01'10'00: // SBB 8 bit Reg from Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg from Reg
				setReg8Bit(modrm.rm, sbb8Bit(reg8Bit(modrm.rm), reg8Bit(modrm.reg)));
				break;
			default: // Reg from Mem
			{
				std::uint32_t ra = realAddress(modrm, so);
				write8Bit(ra, sbb8Bit(read8Bit(ra), reg8Bit(modrm.reg)));
				break;
			}
			}
			break;
		}
		case 0b00'01'10'01: // SBB 16 bit Reg from Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg from Reg
				setReg16Bit(modrm.rm, sbb16Bit(reg16Bit(modrm.rm), reg16Bit(modrm.reg)));
				break;
			default: // Reg from Mem
			{
				std::uint32_t ra = realAddress(modrm, so);
				write16Bit(ra, sbb16Bit(read16Bit(ra), reg16Bit(modrm.reg)));
				break;
			}
			}
			break;
		}
		case 0b00'01'10'10: // SBB 8 bit Reg/Mem from Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg from Reg
				setReg8Bit(modrm.reg, sbb8Bit(reg8Bit(modrm.reg), reg8Bit(modrm.rm)));
				break;
			default: // Mem from Reg
			{
				std::uint32_t ra = realAddress(modrm, so);
				setReg8Bit(modrm.reg, sbb8Bit(reg8Bit(modrm.reg), read8Bit(ra)));
				break;
			}
			}
			break;
		}
		case 0b00'01'10'11: // SBB 16 bit Reg/Mem from Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg from Reg
				setReg16Bit(modrm.reg, sbb16Bit(reg16Bit(modrm.reg), reg16Bit(modrm.rm)));
				break;
			default: // Mem from Reg
			{
				std::uint32_t ra = realAddress(modrm, so);
				setReg16Bit(modrm.reg, sbb16Bit(reg16Bit(modrm.reg), read16Bit(ra)));
				break;
			}
			}
			break;
		}
		case 0b00'01'11'00: // SBB 8 bit Imm from AL
		{
			std::uint8_t imm = memory[EIP()];
			++IP;

			AX = sbb8Bit(AL(), imm);
			break;
		}
		case 0b00'01'11'01: // SBB 16 bit Imm from AX
		{
			std::uint8_t imm = memory[EIP()] << 8;
			++IP;
			imm |= memory[EIP()];

			AX = sbb16Bit(AX, imm);
			break;
		}

		// DEC
		case 0b01'00'10'00: [[fallthrough]]; // DEC AX
		case 0b01'00'10'01: [[fallthrough]]; // DEC CX
		case 0b01'00'10'10: [[fallthrough]]; // DEC DX
		case 0b01'00'10'11: [[fallthrough]]; // DEC BX
		case 0b01'00'11'00: [[fallthrough]]; // DEC SP
		case 0b01'00'11'01: [[fallthrough]]; // DEC BP
		case 0b01'00'11'10: [[fallthrough]]; // DEC SI
		case 0b01'00'11'11:                  // DEC DI
		{
			setReg16Bit(instruction & 0b111, sub16Bit(reg16Bit(instruction & 0b111), 1));
			break;
		}

		// CMP
		case 0b00'11'10'10: // CMP 8 bit Reg/Mem with Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg with Reg
				cmp8Bit(reg8Bit(modrm.rm), reg8Bit(modrm.reg));
				break;
			default: // Mem with Reg
				cmp8Bit(read8Bit(realAddress(modrm, so)), reg8Bit(modrm.reg));
				break;
			}
			break;
		}
		case 0b00'11'10'11: // CMP 16 bit Reg/Mem with Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg with Reg
				cmp16Bit(reg16Bit(modrm.rm), reg16Bit(modrm.reg));
				break;
			default: // Mem with Reg
				cmp16Bit(read16Bit(realAddress(modrm, so)), reg16Bit(modrm.reg));
				break;
			}
			break;
		}
		case 0b00'11'10'00: // CMP 8 bit Reg with Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg with Reg
				cmp8Bit(reg8Bit(modrm.reg), reg8Bit(modrm.rm));
				break;
			default: // Mem with Reg
				cmp8Bit(reg8Bit(modrm.reg), read8Bit(realAddress(modrm, so)));
				break;
			}
			break;
		}
		case 0b00'11'10'01: // CMP 16 bit Reg with Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg with Reg
				cmp16Bit(reg16Bit(modrm.reg), reg16Bit(modrm.rm));
				break;
			default: // Mem with Reg
				cmp16Bit(reg16Bit(modrm.reg), read16Bit(realAddress(modrm, so)));
				break;
			}
			break;
		}
		case 0b00'11'11'00: // CMP 8 bit Imm with AL
		{
			std::uint8_t imm = memory[EIP()];
			++IP;

			cmp8Bit(AL(), imm);
			break;
		}
		case 0b00'11'11'01: // CMP 16 bit Imm with AX
		{
			std::uint16_t imm = memory[EIP()] << 8;
			++IP;
			imm |= memory[EIP()];
			++IP;

			cmp16Bit(AX, imm);
			break;
		}

		// NEG
		case 0b11'11'01'10: // NEG 8 bit Reg/Mem | MUL 8 bit Reg/Mem with AX | IMUL 8 bit Reg/Mem with AX | DIV 8 bit Reg/Mem with AX | IDIV 8 bit Reg/Mem with AX | TEST 8 bit Imm with Reg/Mem | NOT 8 bit Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.reg)
			{
			case 0b011: // NEG 8 bit Reg/Mem
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, sub8Bit(0, reg8Bit(modrm.rm)));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write8Bit(ra, sub8Bit(0, read8Bit(ra)));
					break;
				}
				}
				break;
			case 0b100: // MUL 8 bit Reg/Mem with AX
				switch (modrm.mod)
				{
				case 0b11: // Reg
					AX = mul8Bit(AX & 0xFF, reg8Bit(modrm.rm));
					break;
				default: // Mem
					AX = mul8Bit(AX & 0xFF, read8Bit(realAddress(modrm, so)));
					break;
				}
				break;
			case 0b101: // IMUL 8 bit Reg/Mem with AX
				switch (modrm.mod)
				{
				case 0b11: // Reg
					AX = imul8Bit(AX & 0xFF, reg8Bit(modrm.rm));
					break;
				default: // Mem
					AX = imul8Bit(AX & 0xFF, read8Bit(realAddress(modrm, so)));
					break;
				}
				break;
			case 0b110: // DIV 8 bit Reg/Mem with AX
				switch (modrm.mod)
				{
				case 0b11: // Reg
					AX = div8Bit(AX, reg8Bit(modrm.rm));
					break;
				default: // Mem
					AX = div8Bit(AX, read8Bit(realAddress(modrm, so)));
					break;
				}
				break;
			case 0b111: // IDIV 8 bit Reg/Mem with AX
				switch (modrm.mod)
				{
				case 0b11: // Reg
					AX = idiv8Bit(AX, reg8Bit(modrm.rm));
					break;
				default: // Mem
					AX = idiv8Bit(AX, read8Bit(realAddress(modrm, so)));
					break;
				}
				break;
			case 0b000: // TEST 8 bit Imm with Reg/Mem
			{
				std::uint32_t ra = realAddress(modrm, so);

				std::uint8_t imm = memory[EIP()];
				++IP;

				switch (modrm.mod)
				{
				case 0b11: // Imm with Reg
					and8Bit(reg8Bit(modrm.rm), imm);
					break;
				default: // Imm with Mem
					and8Bit(read8Bit(ra), imm);
					break;
				}
				break;
			}
			case 0b010: // NOT 8 bit Reg/Mem
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, not8Bit(reg8Bit(modrm.rm)));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write8Bit(ra, not8Bit(read8Bit(ra)));
					break;
				}
				}
				break;
			default:
				interrupt(s_InvalidInstruction);
				return;
			}
			break;
		}
		case 0b11'11'01'11: // NEG 16 bit Reg/Mem | MUL 16 bit Reg/Mem with AX | IMUL 16 bit Reg/Mem with AX | DIV 16 bit Reg/Mem with AX | IDIV 16 bit Reg/Mem with AX | TEST 16 bit Imm with Reg/Mem | NOT 16 bit Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.reg)
			{
			case 0b011: // NEG 16 bit Reg/Mem
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, sub16Bit(0, reg16Bit(modrm.rm)));
					break;
				default:
				{
					std::uint32_t ra = realAddress(modrm, so);
					write16Bit(ra, sub16Bit(0, read16Bit(ra)));
					break;
				}
				}
				break;
			case 0b100: // MUL 16 bit Reg/Mem with AX
				switch (modrm.mod)
				{
				case 0b11: // Reg
				{
					std::uint32_t r = mul16Bit(AX, reg16Bit(modrm.rm));
					AX              = r & 0xFFFF;
					DX              = (r >> 16) & 0xFFFF;
					break;
				}
				default:
				{
					std::uint32_t r = mul16Bit(AX, read16Bit(realAddress(modrm, so)));
					AX              = r & 0xFFFF;
					DX              = (r >> 16) & 0xFFFF;
					break;
				}
				}
				break;
			case 0b101: // IMUL 16 bit Reg/Mem with AX
				switch (modrm.mod)
				{
				case 0b11: // Reg
				{
					std::uint32_t r = imul16Bit(AX, reg16Bit(modrm.rm));
					AX              = r & 0xFFFF;
					DX              = (r >> 16) & 0xFFFF;
					break;
				}
				default:
				{
					std::uint32_t r = imul16Bit(AX, read16Bit(realAddress(modrm, so)));
					AX              = r & 0xFFFF;
					DX              = (r >> 16) & 0xFFFF;
					break;
				}
				}
				break;
			case 0b110: // DIV 16 bit Reg/Mem with AX
				switch (modrm.mod)
				{
				case 0b11: // Reg
				{
					std::uint32_t r = div16Bit(AX, DX, reg8Bit(modrm.rm));
					AX              = r & 0xFFFF;
					DX              = (r >> 16) & 0xFFFF;
					break;
				}
				default: // Mem
				{
					std::uint32_t r = div16Bit(AX, DX, read8Bit(realAddress(modrm, so)));
					AX              = r & 0xFFFF;
					DX              = (r >> 16) & 0xFFFF;
					break;
				}
				}
				break;
			case 0b111: // IDIV 16 bit Reg/Mem with AX
				switch (modrm.mod)
				{
				case 0b11: // Reg
				{
					std::uint32_t r = idiv16Bit(AX, DX, reg16Bit(modrm.rm));
					AX              = r & 0xFFFF;
					DX              = (r >> 16) & 0xFFFF;
					break;
				}
				default: // Mem
				{
					std::uint32_t r = idiv16Bit(AX, DX, read16Bit(realAddress(modrm, so)));
					AX              = r & 0xFFFF;
					DX              = (r >> 16) & 0xFFFF;
					break;
				}
				}
				break;
			case 0b000: // TEST 16 bit Imm with Reg/Mem
			{
				std::uint32_t ra = realAddress(modrm, so);

				std::uint16_t imm = memory[EIP()] << 8;
				++IP;
				imm |= memory[EIP()];
				++IP;

				switch (modrm.mod)
				{
				case 0b11: // Imm with Reg
					and16Bit(reg16Bit(modrm.rm), imm);
					break;
				default: // Imm with Mem
					and16Bit(read16Bit(ra), imm);
					break;
				}
				break;
			}
			case 0b010: // NOT168 bit Reg/Mem
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, not16Bit(reg16Bit(modrm.rm)));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write16Bit(ra, not16Bit(read16Bit(ra)));
					break;
				}
				}
				break;
			default:
				interrupt(s_InvalidInstruction);
				return;
			}
			break;
		}

		case 0b00'11'01'11: // AAA
		{
			if ((AX & 0xFF) > 9 || AF())
			{
				AL(AL() + 6);
				AH(AH() + 1);
				setAF(true);
				setCF(true);
			}
			else
			{
				setAF(false);
				setCF(false);
			}
			AX = AX & 0xFF0F;
			break;
		}
		case 0b00'10'01'11: // DAA
		{
			std::uint8_t oldAL = AX & 0xFF;
			bool         oldCF = CF();
			if ((AX & 0xFF) > 9 || AF())
			{
				setCF(oldCF || (0xFF - 6) > (AX & 0xFF));
				setAF(true);
				AL(AL() + 6);
			}
			else
			{
				setAF(false);
			}

			if (oldAL > 0x99 || oldCF)
			{
				AL(AL() + 0x60);
				setCF(true);
			}
			else
			{
				setCF(false);
			}
			break;
		}
		case 0b00'11'11'11: // AAS
		{
			if ((AX & 0xFF) > 9 || AF())
			{
				AL(AL() - 6);
				AH(AH() - 1);
				setAF(true);
				setCF(true);
			}
			else
			{
				setAF(false);
				setCF(false);
			}
			AX &= 0xFF0F;
			break;
		}
		case 0b00'10'11'11: // DAS
		{
			std::uint8_t oldAL = AX & 0xFF;
			bool         oldCF = CF();

			if ((AX & 0xFF) > 9 || AF())
			{
				setCF(oldCF || (0xFF - 6) < (AX & 0xFF));
				AL(AL() - 6);
				setAF(true);
			}
			else
			{
				setAF(false);
			}

			if (oldAL > 0x99 || oldCF)
			{
				AL(AL() - 0x60);
				setCF(true);
			}
			else
			{
				setCF(false);
			}
			break;
		}

		// IMUL
		case 0b01'10'10'11: // IMUL 8 bit Imm with Reg/Mem into Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			std::uint8_t imm = memory[EIP()];
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Imm with Reg into Reg
				setReg8Bit(modrm.reg, imul8Bit(reg8Bit(modrm.rm), imm));
				break;
			default: // Imm with Mem into Reg
			{
				setReg8Bit(modrm.reg, imul8Bit(read8Bit(realAddress(modrm, so)), imm));
				break;
			}
			}
			break;
		}
		case 0b01'10'10'01: // IMUL 16 bit Imm with Reg/Mem into Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			std::uint16_t imm = memory[EIP()] << 8;
			++IP;
			imm |= memory[EIP()];
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Imm with Reg into Reg
				setReg16Bit(modrm.reg, imul16Bit(reg16Bit(modrm.rm), imm));
				break;
			default: // Imm with Mem into Reg
			{
				setReg16Bit(modrm.reg, imul16Bit(read16Bit(realAddress(modrm, so)), imm));
				break;
			}
			}
			break;
		}

		case 0b11'01'01'00: // AAM
		{
			std::uint8_t secondInstruction = memory[EIP()];
			++IP;

			switch (secondInstruction)
			{
			case 0b00'00'10'10: // AAM
			{
				std::uint16_t r = div8Bit(AL(), 10);
				AX              = (r & 0xFF) << 8 | (r >> 8) & 0xFF;
				break;
			}
			default:
				interrupt(s_InvalidInstruction);
				return;
			}
			break;
		}
		case 0b11'01'01'01: // AAD
		{
			std::uint8_t secondInstruction = memory[EIP()];
			++IP;

			switch (secondInstruction)
			{
			case 0b00'00'10'10: // AAD
				AX = add8Bit(mul8Bit(AH(), 10), AL());
				break;
			default:
				interrupt(s_InvalidInstruction);
				return;
			}
			break;
		}

		case 0b10'01'10'00: // CBW
		{
			AX = static_cast<std::uint16_t>(static_cast<std::int16_t>(static_cast<std::int8_t>(AL())));
			break;
		}
		case 0b10'01'10'01: // CWD
		{
			std::uint32_t value = static_cast<std::uint32_t>(static_cast<std::int32_t>(static_cast<std::int16_t>(AX)));
			AX                  = value & 0xFFFF;
			DX                  = (value >> 16) & 0xFFFF;
			break;
		}

		// Shift/Rotate
		case 0b11'01'00'00: // Shift/Rotate 8 bit Reg/Mem by 1
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.reg)
			{
			case 0b000: // ROL
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, rol8Bit(reg8Bit(modrm.rm), 1));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write8Bit(ra, rol8Bit(read8Bit(ra), 1));
					break;
				}
				}
				break;
			case 0b001: // ROR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, ror8Bit(reg8Bit(modrm.rm), 1));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write8Bit(ra, ror8Bit(read8Bit(ra), 1));
					break;
				}
				}
				break;
			case 0b010: // RCL
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, rcl8Bit(reg8Bit(modrm.rm), 1));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write8Bit(ra, rcl8Bit(read8Bit(ra), 1));
					break;
				}
				}
				break;
			case 0b011: // RCR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, rcr8Bit(reg8Bit(modrm.rm), 1));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write8Bit(ra, rcr8Bit(read8Bit(ra), 1));
					break;
				}
				}
				break;
			case 0b100: // SHL/SAL
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, shl8Bit(reg8Bit(modrm.rm), 1));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write8Bit(ra, shl8Bit(read8Bit(ra), 1));
					break;
				}
				}
				break;
			case 0b101: // SHR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, shr8Bit(reg8Bit(modrm.rm), 1));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write8Bit(ra, shr8Bit(read8Bit(ra), 1));
					break;
				}
				}
				break;
			case 0b111: // SAR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, sar8Bit(reg8Bit(modrm.rm), 1));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write8Bit(ra, sar8Bit(read8Bit(ra), 1));
					break;
				}
				}
				break;
			default:
				interrupt(s_InvalidInstruction);
				return;
			}
			break;
		}
		case 0b11'01'00'01: // Shift/Rotate 16 bit Reg/Mem by 1
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.reg)
			{
			case 0b000: // ROL
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, rol16Bit(reg16Bit(modrm.rm), 1));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write16Bit(ra, rol8Bit(read16Bit(ra), 1));
					break;
				}
				}
				break;
			case 0b001: // ROR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, ror16Bit(reg16Bit(modrm.rm), 1));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write16Bit(ra, ror16Bit(read16Bit(ra), 1));
					break;
				}
				}
				break;
			case 0b010: // RCL
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, rcl16Bit(reg16Bit(modrm.rm), 1));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write16Bit(ra, rcl16Bit(read16Bit(ra), 1));
					break;
				}
				}
				break;
			case 0b011: // RCR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, rcr16Bit(reg16Bit(modrm.rm), 1));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write16Bit(ra, rcr16Bit(read16Bit(ra), 1));
					break;
				}
				}
				break;
			case 0b100: // SHL/SAL
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, shl16Bit(reg16Bit(modrm.rm), 1));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write16Bit(ra, shl16Bit(read16Bit(ra), 1));
					break;
				}
				}
				break;
			case 0b101: // SHR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, shr16Bit(reg16Bit(modrm.rm), 1));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write16Bit(ra, shr16Bit(read16Bit(ra), 1));
					break;
				}
				}
				break;
			case 0b111: // SAR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, sar16Bit(reg16Bit(modrm.rm), 1));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write16Bit(ra, sar16Bit(read16Bit(ra), 1));
					break;
				}
				}
				break;
			default:
				interrupt(s_InvalidInstruction);
				return;
			}
			break;
		}
		case 0b11'01'00'10: // Shift/Rotate 8 bit Reg/Mem by CL
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.reg)
			{
			case 0b000: // ROL
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, rol8Bit(reg8Bit(modrm.rm), CL()));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write8Bit(ra, rol8Bit(read8Bit(ra), CL()));
					break;
				}
				}
				break;
			case 0b001: // ROR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, ror8Bit(reg8Bit(modrm.rm), CL()));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write8Bit(ra, ror8Bit(read8Bit(ra), CL()));
					break;
				}
				}
				break;
			case 0b010: // RCL
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, rcl8Bit(reg8Bit(modrm.rm), CL()));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write8Bit(ra, rcl8Bit(read8Bit(ra), CL()));
					break;
				}
				}
				break;
			case 0b011: // RCR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, rcr8Bit(reg8Bit(modrm.rm), CL()));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write8Bit(ra, rcr8Bit(read8Bit(ra), CL()));
					break;
				}
				}
				break;
			case 0b100: // SHL/SAL
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, shl8Bit(reg8Bit(modrm.rm), CL()));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write8Bit(ra, shl8Bit(read8Bit(ra), CL()));
					break;
				}
				}
				break;
			case 0b101: // SHR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, shr8Bit(reg8Bit(modrm.rm), CL()));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write8Bit(ra, shr8Bit(read8Bit(ra), CL()));
					break;
				}
				}
				break;
			case 0b111: // SAR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, sar8Bit(reg8Bit(modrm.rm), CL()));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write8Bit(ra, sar8Bit(read8Bit(ra), CL()));
					break;
				}
				}
				break;
			default:
				interrupt(s_InvalidInstruction);
				return;
			}
			break;
		}
		case 0b11'01'00'11: // Shift/Rotate 16 bit Reg/Mem by CL
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.reg)
			{
			case 0b000: // ROL
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, rol16Bit(reg16Bit(modrm.rm), CL()));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write16Bit(ra, rol8Bit(read16Bit(ra), CL()));
					break;
				}
				}
				break;
			case 0b001: // ROR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, ror16Bit(reg16Bit(modrm.rm), CL()));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write16Bit(ra, ror16Bit(read16Bit(ra), CL()));
					break;
				}
				}
				break;
			case 0b010: // RCL
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, rcl16Bit(reg16Bit(modrm.rm), CL()));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write16Bit(ra, rcl16Bit(read16Bit(ra), CL()));
					break;
				}
				}
				break;
			case 0b011: // RCR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, rcr16Bit(reg16Bit(modrm.rm), CL()));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write16Bit(ra, rcr16Bit(read16Bit(ra), CL()));
					break;
				}
				}
				break;
			case 0b100: // SHL/SAL
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, shl16Bit(reg16Bit(modrm.rm), CL()));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write16Bit(ra, shl16Bit(read16Bit(ra), CL()));
					break;
				}
				}
				break;
			case 0b101: // SHR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, shr16Bit(reg16Bit(modrm.rm), CL()));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write16Bit(ra, shr16Bit(read16Bit(ra), CL()));
					break;
				}
				}
				break;
			case 0b111: // SAR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, sar16Bit(reg16Bit(modrm.rm), CL()));
					break;
				default: // Mem
				{
					std::uint32_t ra = realAddress(modrm, so);
					write16Bit(ra, sar16Bit(read16Bit(ra), CL()));
					break;
				}
				}
				break;
			default:
				interrupt(s_InvalidInstruction);
				return;
			}
			break;
		}
		case 0b11'00'00'00: // Shift/Rotate 8 bit Reg/Mem by Imm8
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			std::uint32_t ra = realAddress(modrm, so);

			std::uint8_t imm = memory[EIP()];
			++IP;

			switch (modrm.reg)
			{
			case 0b000: // ROL
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, rol8Bit(reg8Bit(modrm.rm), imm));
					break;
				default: // Mem
					write8Bit(ra, rol8Bit(read8Bit(ra), imm));
					break;
				}
				break;
			case 0b001: // ROR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, ror8Bit(reg8Bit(modrm.rm), imm));
					break;
				default: // Mem
					write8Bit(ra, ror8Bit(read8Bit(ra), imm));
					break;
				}
				break;
			case 0b010: // RCL
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, rcl8Bit(reg8Bit(modrm.rm), imm));
					break;
				default: // Mem
					write8Bit(ra, rcl8Bit(read8Bit(ra), imm));
					break;
				}
				break;
			case 0b011: // RCR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, rcr8Bit(reg8Bit(modrm.rm), imm));
					break;
				default: // Mem
					write8Bit(ra, rcr8Bit(read8Bit(ra), imm));
					break;
				}
				break;
			case 0b100: // SHL/SAL
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, shl8Bit(reg8Bit(modrm.rm), imm));
					break;
				default: // Mem
					write8Bit(ra, shl8Bit(read8Bit(ra), imm));
					break;
				}
				break;
			case 0b101: // SHR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, shr8Bit(reg8Bit(modrm.rm), imm));
					break;
				default: // Mem
					write8Bit(ra, shr8Bit(read8Bit(ra), imm));
					break;
				}
				break;
			case 0b111: // SAR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg8Bit(modrm.rm, sar8Bit(reg8Bit(modrm.rm), imm));
					break;
				default: // Mem
					write8Bit(ra, sar8Bit(read8Bit(ra), imm));
					break;
				}
				break;
			default:
				interrupt(s_InvalidInstruction);
				return;
			}
			break;
		}
		case 0b11'00'00'01: // Shift/Rotate 16 bit Reg/Mem by imm8
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			std::uint32_t ra = realAddress(modrm, so);

			std::uint8_t imm = memory[EIP()];
			++IP;

			switch (modrm.reg)
			{
			case 0b000: // ROL
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, rol16Bit(reg16Bit(modrm.rm), imm));
					break;
				default: // Mem
					write16Bit(ra, rol8Bit(read16Bit(ra), imm));
					break;
				}
				break;
			case 0b001: // ROR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, ror16Bit(reg16Bit(modrm.rm), imm));
					break;
				default: // Mem
					write16Bit(ra, ror16Bit(read16Bit(ra), imm));
					break;
				}
				break;
			case 0b010: // RCL
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, rcl16Bit(reg16Bit(modrm.rm), imm));
					break;
				default: // Mem
					write16Bit(ra, rcl16Bit(read16Bit(ra), imm));
					break;
				}
				break;
			case 0b011: // RCR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, rcr16Bit(reg16Bit(modrm.rm), imm));
					break;
				default: // Mem
					write16Bit(ra, rcr16Bit(read16Bit(ra), imm));
					break;
				}
				break;
			case 0b100: // SHL/SAL
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, shl16Bit(reg16Bit(modrm.rm), imm));
					break;
				default: // Mem
					write16Bit(ra, shl16Bit(read16Bit(ra), imm));
					break;
				}
				break;
			case 0b101: // SHR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, shr16Bit(reg16Bit(modrm.rm), imm));
					break;
				default: // Mem
					write16Bit(ra, shr16Bit(read16Bit(ra), imm));
					break;
				}
				break;
			case 0b111: // SAR
				switch (modrm.mod)
				{
				case 0b11: // Reg
					setReg16Bit(modrm.rm, sar16Bit(reg16Bit(modrm.rm), imm));
					break;
				default: // Mem
					write16Bit(ra, sar16Bit(read16Bit(ra), imm));
					break;
				}
				break;
			default:
				interrupt(s_InvalidInstruction);
				return;
			}
			break;
		}

		// AND
		case 0b00'10'00'00: // AND 8 bit Reg with Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg with Reg
				setReg8Bit(modrm.rm, and8Bit(reg8Bit(modrm.rm), reg8Bit(modrm.reg)));
				break;
			default: // Reg with Mem
			{
				std::uint32_t ra = realAddress(modrm, so);
				write8Bit(ra, and8Bit(read8Bit(ra), reg8Bit(modrm.reg)));
				break;
			}
			}
			break;
		}
		case 0b00'10'00'01: // AND 16 bit Reg with Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg with Reg
				setReg16Bit(modrm.rm, and16Bit(reg16Bit(modrm.rm), reg16Bit(modrm.reg)));
				break;
			default: // Reg with Mem
			{
				std::uint32_t ra = realAddress(modrm, so);
				write16Bit(ra, and16Bit(read16Bit(ra), reg16Bit(modrm.reg)));
				break;
			}
			}
			break;
		}
		case 0b00'10'00'10: // AND 8 bit Reg/Mem with Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg with Reg
				setReg8Bit(modrm.reg, and8Bit(reg8Bit(modrm.reg), reg8Bit(modrm.rm)));
				break;
			default: // Mem with Reg
				setReg8Bit(modrm.reg, and8Bit(reg8Bit(modrm.reg), read8Bit(realAddress(modrm, so))));
				break;
			}
			break;
		}
		case 0b00'10'00'11: // AND 16 bit Reg/Mem with Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg with Reg
				setReg16Bit(modrm.reg, and16Bit(reg16Bit(modrm.reg), reg16Bit(modrm.rm)));
				break;
			default: // Mem with Reg
				setReg16Bit(modrm.reg, and16Bit(reg16Bit(modrm.reg), read16Bit(realAddress(modrm, so))));
				break;
			}
			break;
		}
		case 0b00'10'01'00: // AND 8 bit imm with AL
		{
			std::uint8_t imm = memory[EIP()];
			++IP;

			AX = and8Bit(AL(), imm);
			break;
		}
		case 0b00'10'01'01: // AND 16 bit imm with AX
		{
			std::uint16_t imm = memory[EIP()] << 8;
			++IP;
			imm |= memory[EIP()];
			++IP;

			AX = and16Bit(AX, imm);
			break;
		}

		// TEST
		case 0b10'00'01'00: // TEST 8 bit Reg with Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg with Reg
				and8Bit(reg8Bit(modrm.rm), reg8Bit(modrm.reg));
				break;
			default: // Reg with Mem
				and8Bit(read8Bit(realAddress(modrm, so)), reg8Bit(modrm.reg));
				break;
			}
			break;
		}
		case 0b10'00'01'01: // TEST 16 bit Reg with Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg with Reg
				and16Bit(reg16Bit(modrm.rm), reg16Bit(modrm.reg));
				break;
			default: // Reg with Mem
				and16Bit(read16Bit(realAddress(modrm, so)), reg16Bit(modrm.reg));
				break;
			}
			break;
		}
		case 0b10'10'10'00: // TEST 8 bit with AL
		{
			std::uint8_t imm = memory[EIP()];
			++IP;

			and8Bit(AL(), imm);
			break;
		}
		case 0b10'10'10'01: // TEST 16 bit with AX
		{
			std::uint16_t imm = memory[EIP()] << 8;
			++IP;
			imm |= memory[EIP()];
			++IP;

			and16Bit(AX, imm);
			break;
		}

		// OR
		case 0b00'00'10'00: // OR 8 bit Reg with Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg with Reg
				setReg8Bit(modrm.rm, or8Bit(reg8Bit(modrm.rm), reg8Bit(modrm.reg)));
				break;
			default: // Reg with Mem
			{
				std::uint32_t ra = realAddress(modrm, so);
				write8Bit(ra, or8Bit(read8Bit(ra), reg8Bit(modrm.reg)));
				break;
			}
			}
			break;
		}
		case 0b00'00'10'01: // OR 16 bit Reg with Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg with Reg
				setReg16Bit(modrm.rm, or16Bit(reg16Bit(modrm.rm), reg16Bit(modrm.reg)));
				break;
			default: // Reg with Mem
			{
				std::uint32_t ra = realAddress(modrm, so);
				write16Bit(ra, or16Bit(read16Bit(ra), reg16Bit(modrm.reg)));
				break;
			}
			}
			break;
		}
		case 0b00'00'10'10: // OR 8 bit Reg/Mem with Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg with Reg
				setReg8Bit(modrm.reg, or8Bit(reg8Bit(modrm.reg), reg8Bit(modrm.rm)));
				break;
			default: // Mem with Reg
				setReg8Bit(modrm.reg, or8Bit(reg8Bit(modrm.reg), read8Bit(realAddress(modrm, so))));
				break;
			}
			break;
		}
		case 0b00'00'10'11: // OR 16 bit Reg/Mem with Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg with Reg
				setReg16Bit(modrm.reg, or16Bit(reg16Bit(modrm.reg), reg16Bit(modrm.rm)));
				break;
			default: // Mem with Reg
				setReg16Bit(modrm.reg, or16Bit(reg16Bit(modrm.reg), read16Bit(realAddress(modrm, so))));
				break;
			}
			break;
		}
		case 0b00'00'11'00: // OR 8 bit Imm with AL
		{
			std::uint8_t imm = memory[EIP()];
			++IP;

			AX = or8Bit(AL(), imm);
			break;
		}
		case 0b00'00'11'01: // OR 16 bit Imm with AL
		{
			std::uint16_t imm = memory[EIP()] << 8;
			++IP;
			imm |= memory[EIP()];
			++IP;

			AX = or16Bit(AX, imm);
			break;
		}

		// XOR
		case 0b00'11'00'00: // XOR 8 bit Reg with Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg with Reg
				setReg8Bit(modrm.rm, xor8Bit(reg8Bit(modrm.rm), reg8Bit(modrm.reg)));
				break;
			default: // Reg with Mem
			{
				std::uint32_t ra = realAddress(modrm, so);
				write8Bit(ra, xor8Bit(read8Bit(ra), reg8Bit(modrm.reg)));
				break;
			}
			}
			break;
		}
		case 0b00'11'00'01: // XOR 16 bit Reg with Reg/Mem
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg with Reg
				setReg16Bit(modrm.rm, xor16Bit(reg16Bit(modrm.rm), reg16Bit(modrm.reg)));
				break;
			default: // Reg with Mem
			{
				std::uint32_t ra = realAddress(modrm, so);
				write16Bit(ra, xor16Bit(read16Bit(ra), reg16Bit(modrm.reg)));
				break;
			}
			}
			break;
		}
		case 0b00'11'00'10: // XOR 8 bit Reg/Mem with Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg with Reg
				setReg8Bit(modrm.reg, xor8Bit(reg8Bit(modrm.reg), reg8Bit(modrm.rm)));
				break;
			default: // Mem with Reg
				setReg8Bit(modrm.reg, xor8Bit(reg8Bit(modrm.reg), read8Bit(realAddress(modrm, so))));
				break;
			}
			break;
		}
		case 0b00'11'00'11: // XOR 16 bit Reg/Mem with Reg
		{
			ModRM modrm = std::bit_cast<ModRM>(memory[EIP()]);
			++IP;

			switch (modrm.mod)
			{
			case 0b11: // Reg with Reg
				setReg16Bit(modrm.reg, xor16Bit(reg16Bit(modrm.reg), reg16Bit(modrm.rm)));
				break;
			default: // Mem with Reg
				setReg16Bit(modrm.reg, xor16Bit(reg16Bit(modrm.reg), read16Bit(realAddress(modrm, so))));
				break;
			}
			break;
		}
		case 0b00'11'01'00: // XOR 8 bit Imm with AL
		{
			std::uint8_t imm = memory[EIP()];
			++IP;

			AX = xor8Bit(AL(), imm);
			break;
		}
		case 0b00'11'01'01: // XOR 16 bit Imm with AX
		{
			std::uint16_t imm = memory[EIP()] << 8;
			++IP;
			imm |= memory[EIP()];
			++IP;

			AX = xor16Bit(AX, imm);
			break;
		}

		// TODO: Add REP prefix
		case 0b10'10'01'00: // MOVS 8 bit
		{
			if (rep)
			{
				if (rep != 0b11'11'00'10)
				{
					interrupt(s_InvalidInstruction);
					return;
				}

				std::uint32_t srcAddress = (segmentOverride(so, DS) << 4) + SI;
				std::uint32_t dstAddress = (ES << 4) + DI;
				while (CX > 0)
				{
					write8Bit(dstAddress, read8Bit(srcAddress));
					if (DF())
					{
						++srcAddress;
						++dstAddress;
						++SI;
						++DI;
					}
					else
					{
						--srcAddress;
						--dstAddress;
						--SI;
						--DI;
					}
					--CX;
				}
			}
			else
			{
				std::uint32_t srcAddress = (segmentOverride(so, DS) << 4) + SI;
				std::uint32_t dstAddress = (ES << 4) + DI;
				write8Bit(dstAddress, read8Bit(srcAddress));
				if (DF())
				{
					++SI;
					++DI;
				}
				else
				{
					--SI;
					--DI;
				}
			}
			break;
		}
		case 0b10'10'01'01: // MOVS 16 bit
		{
			if (rep)
			{
				if (rep != 0b11'11'00'10)
				{
					interrupt(s_InvalidInstruction);
					return;
				}

				std::uint32_t srcAddress = (segmentOverride(so, DS) << 4) + SI;
				std::uint32_t dstAddress = (ES << 4) + DI;
				while (CX > 0)
				{
					write16Bit(dstAddress, read16Bit(srcAddress));
					if (DF())
					{
						srcAddress += 2;
						dstAddress += 2;
						SI += 2;
						DI += 2;
					}
					else
					{
						srcAddress -= 2;
						dstAddress -= 2;
						SI -= 2;
						DI -= 2;
					}
					--CX;
				}
			}
			else
			{
				std::uint32_t srcAddress = (segmentOverride(so, DS) << 4) + SI;
				std::uint32_t dstAddress = (ES << 4) + DI;
				write16Bit(dstAddress, read16Bit(srcAddress));
				if (DF())
				{
					SI += 2;
					DI += 2;
				}
				else
				{
					SI -= 2;
					DI -= 2;
				}
			}
			break;
		}

		case 0b10'10'01'10: // CMPS 8 bit
		{
			if (rep)
			{
				std::uint32_t srcAddress = (segmentOverride(so, DS) << 4) + SI;
				std::uint32_t dstAddress = (ES << 4) + DI;
				while (CX > 0 && rep == 0b11'11'00'10 ? !ZF() : ZF())
				{
					cmp8Bit(read8Bit(dstAddress), read8Bit(srcAddress));
					if (DF())
					{
						++srcAddress;
						++dstAddress;
						++SI;
						++DI;
					}
					else
					{
						--srcAddress;
						--dstAddress;
						--SI;
						--DI;
					}
					--CX;
				}
			}
			else
			{
				std::uint32_t srcAddress = (segmentOverride(so, DS) << 4) + SI;
				std::uint32_t dstAddress = (ES << 4) + DI;
				cmp8Bit(read8Bit(srcAddress), read8Bit(dstAddress));
				if (DF())
				{
					++SI;
					++DI;
				}
				else
				{
					--SI;
					--DI;
				}
			}
			break;
		}
		case 0b10'10'01'11: // CMPS 16 bit
		{
			if (rep)
			{
				std::uint32_t srcAddress = (segmentOverride(so, DS) << 4) + SI;
				std::uint32_t dstAddress = (ES << 4) + DI;
				while (CX > 0 && rep == 0b11'11'00'10 ? !ZF() : ZF())
				{
					cmp16Bit(read16Bit(dstAddress), read16Bit(srcAddress));
					if (DF())
					{
						srcAddress += 2;
						dstAddress += 2;
						SI += 2;
						DI += 2;
					}
					else
					{
						srcAddress -= 2;
						dstAddress -= 2;
						SI -= 2;
						DI -= 2;
					}
					--CX;
				}
			}
			else
			{
				std::uint32_t srcAddress = (segmentOverride(so, DS) << 4) + SI;
				std::uint32_t dstAddress = (ES << 4) + DI;
				cmp16Bit(read16Bit(srcAddress), read16Bit(dstAddress));
				if (DF())
				{
					SI += 2;
					DI += 2;
				}
				else
				{
					SI -= 2;
					DI -= 2;
				}
			}
			break;
		}

		case 0b10'10'11'10: // SCAS 8 bit
		{
			if (rep)
			{
				std::uint32_t srcAddress = (ES << 4) + DI;
				while (CX > 0 && rep == 0b11'11'00'10 ? !ZF() : ZF())
				{
					cmp8Bit(AL(), read8Bit(srcAddress));
					if (DF())
					{
						++srcAddress;
						++DI;
					}
					else
					{
						--srcAddress;
						--DI;
					}
					--CX;
				}
			}
			else
			{
				std::uint32_t srcAddress = (ES << 4) + DI;
				cmp8Bit(AL(), read8Bit(srcAddress));
				if (DF())
					++DI;
				else
					--DI;
			}
			break;
		}
		case 0b10'10'11'11: // SCAS 16 bit
		{
			if (rep)
			{
				std::uint32_t srcAddress = (ES << 4) + DI;
				while (CX > 0 && rep == 0b11'11'00'10 ? !ZF() : ZF())
				{
					cmp16Bit(AX, read16Bit(srcAddress));
					if (DF())
					{
						srcAddress += 2;
						DI += 2;
					}
					else
					{
						srcAddress -= 2;
						DI -= 2;
					}
					--CX;
				}
			}
			else
			{
				std::uint32_t srcAddress = (ES << 4) + DI;
				cmp16Bit(AX, read16Bit(srcAddress));
				if (DF())
					DI += 2;
				else
					DI -= 2;
			}
			break;
		}

		case 0b10'10'11'00: // LODS 8 bit
		{
			if (rep)
			{
				if (rep != 0b11'11'00'10)
				{
					interrupt(s_InvalidInstruction);
					return;
				}

				std::uint32_t srcAddress = (segmentOverride(so, DS) << 4) + SI;
				while (CX > 0)
				{
					AX = read8Bit(srcAddress);
					if (DF())
					{
						++srcAddress;
						++SI;
					}
					else
					{
						--srcAddress;
						--SI;
					}
					--CX;
				}
			}
			else
			{
				std::uint32_t srcAddress = (segmentOverride(so, DS) << 4) + SI;
				AX                       = read8Bit(srcAddress);
				if (DF())
					++SI;
				else
					--SI;
			}
			break;
		}
		case 0b10'10'11'01: // LODS 16 bit
		{
			if (rep)
			{
				if (rep != 0b11'11'00'10)
				{
					interrupt(s_InvalidInstruction);
					return;
				}

				std::uint32_t srcAddress = (segmentOverride(so, DS) << 4) + SI;
				while (CX > 0)
				{
					AX = read16Bit(srcAddress);
					if (DF())
					{
						srcAddress += 2;
						SI += 2;
					}
					else
					{
						srcAddress -= 2;
						SI -= 2;
					}
					--CX;
				}
			}
			else
			{
				std::uint32_t srcAddress = (segmentOverride(so, DS) << 4) + SI;
				AX                       = read16Bit(srcAddress);
				if (DF())
					SI += 2;
				else
					SI -= 2;
			}
			break;
		}

		case 0b10'10'10'10: // STOS 8 bit
		{
			if (rep)
			{
				if (rep != 0b11'11'00'10)
				{
					interrupt(s_InvalidInstruction);
					return;
				}

				std::uint32_t dstAddress = (ES << 4) + DI;
				while (CX > 0)
				{
					write8Bit(dstAddress, AL());
					if (DF())
					{
						++dstAddress;
						++DI;
					}
					else
					{
						--dstAddress;
						--DI;
					}
					--CX;
				}
			}
			else
			{
				std::uint32_t dstAddress = (ES << 4) + DI;
				write8Bit(dstAddress, AL());
				if (DF())
					++DI;
				else
					--DI;
			}
			break;
		}
		case 0b10'10'10'11: // STOS 16 bit
		{
			if (rep)
			{
				if (rep != 0b11'11'00'10)
				{
					interrupt(s_InvalidInstruction);
					return;
				}

				std::uint32_t dstAddress = (ES << 4) + DI;
				while (CX > 0)
				{
					write16Bit(dstAddress, AX);
					if (DF())
					{
						dstAddress += 2;
						DI += 2;
					}
					else
					{
						dstAddress -= 2;
						DI -= 2;
					}
					--CX;
				}
			}
			else
			{
				std::uint32_t dstAddress = (ES << 4) + DI;
				write16Bit(dstAddress, AX);
				if (DF())
					DI += 2;
				else
					DI -= 2;
			}
			break;
		}

		case 0b01'10'11'00: // INS 8 bit
		{
			if (rep)
			{
				if (rep != 0b11'11'00'10)
				{
					interrupt(s_InvalidInstruction);
					return;
				}

				std::uint32_t dstAddress = (ES << 4) + DI;
				while (CX > 0)
				{
					write8Bit(dstAddress, in8Bit(DX));
					if (DF())
					{
						++dstAddress;
						++DI;
					}
					else
					{
						--dstAddress;
						--DI;
					}
					--CX;
				}
			}
			else
			{
				std::uint32_t dstAddress = (ES << 4) + DI;
				write8Bit(dstAddress, in8Bit(DX));
				if (DF())
					++DI;
				else
					--DI;
			}
			break;
		}
		case 0b01'10'11'01: // INS 16 bit
		{
			if (rep)
			{
				if (rep != 0b11'11'00'10)
				{
					interrupt(s_InvalidInstruction);
					return;
				}

				std::uint32_t dstAddress = (ES << 4) + DI;
				while (CX > 0)
				{
					write16Bit(dstAddress, in16Bit(DX));
					if (DF())
					{
						dstAddress += 2;
						DI += 2;
					}
					else
					{
						dstAddress -= 2;
						DI -= 2;
					}
					--CX;
				}
			}
			else
			{
				std::uint32_t dstAddress = (ES << 4) + DI;
				write16Bit(dstAddress, in16Bit(DX));
				if (DF())
					DI += 2;
				else
					DI -= 2;
			}
			break;
		}

		case 0b01'10'11'10: // OUTS 8 bit
		{
			if (rep)
			{
				if (rep != 0b11'11'00'10)
				{
					interrupt(s_InvalidInstruction);
					return;
				}

				std::uint32_t srcAddress = (segmentOverride(so, DS) << 4) + SI;
				while (CX > 0)
				{
					out8Bit(DX, read8Bit(srcAddress));
					if (DF())
					{
						++srcAddress;
						++SI;
					}
					else
					{
						--srcAddress;
						--SI;
					}
					--CX;
				}
			}
			else
			{
				std::uint32_t srcAddress = (segmentOverride(so, DS) << 4) + SI;
				out8Bit(DX, read8Bit(srcAddress));
				if (DF())
					++SI;
				else
					--SI;
			}
			break;
		}
		case 0b01'10'11'11: // OUTS 16 bit
		{
			if (rep)
			{
				if (rep != 0b11'11'00'10)
				{
					interrupt(s_InvalidInstruction);
					return;
				}

				std::uint32_t srcAddress = (segmentOverride(so, DS) << 4) + SI;
				while (CX > 0)
				{
					out16Bit(DX, read16Bit(srcAddress));
					if (DF())
					{
						srcAddress += 2;
						SI += 2;
					}
					else
					{
						srcAddress -= 2;
						SI -= 2;
					}
					--CX;
				}
			}
			else
			{
				std::uint32_t srcAddress = (segmentOverride(so, DS) << 4) + SI;
				out16Bit(DX, read16Bit(srcAddress));
				if (DF())
					SI += 2;
				else
					SI -= 2;
			}
			break;
		}

		default:
		{
			interrupt(s_InvalidInstruction);
			return;
		}
		}
	}

	std::uint8_t add8Bit(std::uint8_t a, std::uint8_t b)
	{
		std::uint64_t flags = 0;
		std::uint8_t  r     = rngos_intrin_add8_f(a, b, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint8_t adc8Bit(std::uint8_t a, std::uint8_t b)
	{
		std::uint64_t flags = F;
		std::uint8_t  r     = rngos_intrin_adc8_f(a, b, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint16_t add16Bit(std::uint16_t a, std::uint16_t b)
	{
		std::uint64_t flags = 0;
		std::uint16_t r     = rngos_intrin_add16_f(a, b, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint16_t adc16Bit(std::uint16_t a, std::uint16_t b)
	{
		std::uint64_t flags = F;
		std::uint16_t r     = rngos_intrin_adc16_f(a, b, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint8_t sub8Bit(std::uint8_t a, std::uint8_t b)
	{
		std::uint64_t flags = 0;
		std::uint8_t  r     = rngos_intrin_sub8_f(a, b, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint8_t sbb8Bit(std::uint8_t a, std::uint8_t b)
	{
		std::uint64_t flags = F;
		std::uint8_t  r     = rngos_intrin_sbb8_f(a, b, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint16_t sub16Bit(std::uint16_t a, std::uint16_t b)
	{
		std::uint64_t flags = 0;
		std::uint16_t r     = rngos_intrin_sub16_f(a, b, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint16_t sbb16Bit(std::uint16_t a, std::uint16_t b)
	{
		std::uint64_t flags = F;
		std::uint16_t r     = rngos_intrin_sbb16_f(a, b, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint16_t mul8Bit(std::uint8_t a, std::uint8_t b)
	{
		std::uint64_t flags = 0;
		std::uint16_t r     = rngos_intrin_mul8_f(a, b, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint16_t imul8Bit(std::uint8_t a, std::uint8_t b)
	{
		std::uint64_t flags = 0;
		std::uint16_t r     = rngos_intrin_imul8_f(a, b, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint32_t mul16Bit(std::uint16_t a, std::uint16_t b)
	{
		std::uint64_t flags = 0;
		std::uint32_t r     = rngos_intrin_mul16_f(a, b, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint32_t imul16Bit(std::uint16_t a, std::uint16_t b)
	{
		std::uint64_t flags = 0;
		std::uint32_t r     = rngos_intrin_imul16_f(a, b, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint16_t div8Bit(std::uint16_t a, std::uint8_t b)
	{
		std::uint64_t flags = 0;
		std::uint16_t r     = rngos_intrin_div8_f(a, b, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint16_t idiv8Bit(std::uint16_t a, std::uint8_t b)
	{
		std::uint64_t flags = 0;
		std::uint16_t r     = rngos_intrin_idiv8_f(a, b, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint32_t div16Bit(std::uint16_t a, std::uint16_t b, std::uint16_t c)
	{
		std::uint64_t flags = 0;
		std::uint32_t r     = rngos_intrin_div16_f(a, b, c, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint32_t idiv16Bit(std::uint16_t a, std::uint16_t b, std::uint16_t c)
	{
		std::uint64_t flags = 0;
		std::uint32_t r     = rngos_intrin_idiv16_f(a, b, c, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint8_t rol8Bit(std::uint8_t a, std::uint8_t count)
	{
		std::uint64_t flags = 0;
		std::uint8_t  r     = rngos_intrin_rol8_f(a, count, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint8_t ror8Bit(std::uint8_t a, std::uint8_t count)
	{
		std::uint64_t flags = 0;
		std::uint8_t  r     = rngos_intrin_ror8_f(a, count, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint8_t rcl8Bit(std::uint8_t a, std::uint8_t count)
	{
		std::uint64_t flags = 0;
		std::uint8_t  r     = rngos_intrin_rcl8_f(a, count, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint8_t rcr8Bit(std::uint8_t a, std::uint8_t count)
	{
		std::uint64_t flags = 0;
		std::uint8_t  r     = rngos_intrin_rcr8_f(a, count, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint8_t shl8Bit(std::uint8_t a, std::uint8_t count)
	{
		std::uint64_t flags = 0;
		std::uint8_t  r     = rngos_intrin_shl8_f(a, count, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint8_t shr8Bit(std::uint8_t a, std::uint8_t count)
	{
		std::uint64_t flags = 0;
		std::uint8_t  r     = rngos_intrin_shr8_f(a, count, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint8_t sar8Bit(std::uint8_t a, std::uint8_t count)
	{
		std::uint64_t flags = 0;
		std::uint8_t  r     = rngos_intrin_sar8_f(a, count, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint16_t rol16Bit(std::uint16_t a, std::uint8_t count)
	{
		std::uint64_t flags = 0;
		std::uint16_t r     = rngos_intrin_rol16_f(a, count, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint16_t ror16Bit(std::uint16_t a, std::uint8_t count)
	{
		std::uint64_t flags = 0;
		std::uint16_t r     = rngos_intrin_ror16_f(a, count, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint16_t rcl16Bit(std::uint16_t a, std::uint8_t count)
	{
		std::uint64_t flags = 0;
		std::uint16_t r     = rngos_intrin_rcl16_f(a, count, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint16_t rcr16Bit(std::uint16_t a, std::uint8_t count)
	{
		std::uint64_t flags = 0;
		std::uint16_t r     = rngos_intrin_rcr16_f(a, count, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint16_t shl16Bit(std::uint16_t a, std::uint8_t count)
	{
		std::uint64_t flags = 0;
		std::uint16_t r     = rngos_intrin_shl16_f(a, count, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint16_t shr16Bit(std::uint16_t a, std::uint8_t count)
	{
		std::uint64_t flags = 0;
		std::uint16_t r     = rngos_intrin_shr16_f(a, count, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint16_t sar16Bit(std::uint16_t a, std::uint8_t count)
	{
		std::uint64_t flags = 0;
		std::uint16_t r     = rngos_intrin_sar16_f(a, count, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint8_t and8Bit(std::uint8_t a, std::uint8_t b)
	{
		std::uint64_t flags = 0;
		std::uint8_t  r     = rngos_intrin_and8_f(a, b, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint16_t and16Bit(std::uint16_t a, std::uint16_t b)
	{
		std::uint64_t flags = 0;
		std::uint16_t r     = rngos_intrin_and16_f(a, b, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint8_t or8Bit(std::uint8_t a, std::uint8_t b)
	{
		std::uint64_t flags = 0;
		std::uint8_t  r     = rngos_intrin_or8_f(a, b, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint16_t or16Bit(std::uint16_t a, std::uint16_t b)
	{
		std::uint64_t flags = 0;
		std::uint16_t r     = rngos_intrin_or16_f(a, b, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint8_t xor8Bit(std::uint8_t a, std::uint8_t b)
	{
		std::uint64_t flags = 0;
		std::uint8_t  r     = rngos_intrin_xor8_f(a, b, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint16_t xor16Bit(std::uint16_t a, std::uint16_t b)
	{
		std::uint64_t flags = 0;
		std::uint16_t r     = rngos_intrin_xor16_f(a, b, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint8_t not8Bit(std::uint8_t a)
	{
		std::uint64_t flags = 0;
		std::uint8_t  r     = rngos_intrin_not8_f(a, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	std::uint16_t not16Bit(std::uint16_t a)
	{
		std::uint64_t flags = 0;
		std::uint16_t r     = rngos_intrin_not16_f(a, &flags);
		F                   = flags & 0xFFFF;
		return r;
	}

	void cmp8Bit(std::uint8_t a, std::uint8_t b)
	{
		std::uint64_t flags = 0;
		rngos_intrin_cmp8_f(a, b, &flags);
		F = flags & 0xFFFF;
	}

	void cmp16Bit(std::uint16_t a, std::uint16_t b)
	{
		std::uint64_t flags = 0;
		rngos_intrin_cmp16_f(a, b, &flags);
		F = flags & 0xFFFF;
	}

	void interrupt(std::uint16_t interrupt) { Interrupt = interrupt; }

	std::uint8_t in8Bit(std::uint16_t port)
	{
		// IDK wtf this instruction should return...
		return 0;
	}

	void out8Bit(std::uint16_t port, std::uint8_t value)
	{
		// IDK wtf this instruction should do...
	}

	std::uint16_t in16Bit(std::uint16_t port) { return in8Bit(port) | in8Bit(port) << 8; }

	void out16Bit(std::uint16_t port, std::uint16_t value)
	{
		out8Bit(port, value & 0xFF);
		out8Bit(port, (value >> 8) & 0xFF);
	}

	std::uint32_t segmentOverride(std::uint8_t so, std::uint32_t def)
	{
		switch (so)
		{
		case 0b00'10'01'10: return ES;
		case 0b00'10'11'10: return CS;
		case 0b00'11'01'10: return SS;
		case 0b00'11'11'10: return DS;
		default: return def;
		}
	}

	std::uint32_t realAddress(ModRM modrm, std::uint8_t so)
	{
		std::uint32_t base = 0;
		switch (modrm.rm)
		{
		case 0b010: base = SS; break;
		case 0b011: base = ES; break;
		case 0b101: base = ES; break;
		case 0b110: base = SS; break;
		default: base = segmentOverride(so, DS); break;
		}

		return (base << 4) + effectiveAddress(modrm);
	}

	std::uint16_t effectiveAddress(ModRM modrm)
	{
		if (modrm.mod == 0b11)
			return 0;

		std::int16_t disp = 0;
		switch (modrm.mod)
		{
		case 0b00: // DISP = 0, except rm == 0b110 => DISP = disp-high: disp-low
			if (modrm.rm == 0b110)
			{
				disp = memory[EIP()];
				++IP;
				disp |= memory[EIP()] << 8;
				++IP;
			}
			break;
		case 0b01: // DISP = disp-low sign-extended to 16-bits, disp-high absent
			disp = static_cast<std::int16_t>(static_cast<std::int8_t>(memory[EIP()]));
			++IP;
			break;
		case 0b10: // DISP = disp-high: disp-low
			disp = memory[EIP()];
			++IP;
			disp |= memory[EIP()] << 8;
			++IP;
			break;
		}

		switch (modrm.rm)
		{
		case 0b000: return BX + SI + disp;
		case 0b001: return BX + DI + disp;
		case 0b010: return BP + SI + disp;
		case 0b011: return BP + DI + disp;
		case 0b100: return SI + disp;
		case 0b101: return DI + disp;
		case 0b110: return BP + disp;
		case 0b111: return BX + disp;
		}
	}

	void push8Bit(std::uint8_t value)
	{
		std::uint32_t ea = (SS << 4) + SP;
		write8Bit(ea, value);
		++SP;
	}

	void push16Bit(std::uint16_t value)
	{
		std::uint32_t ea = (SS << 4) + SP;
		write16Bit(ea, value);
		SP += 2;
	}

	std::uint8_t pop8Bit()
	{
		std::uint32_t ea = (SS << 4) + (SP - 1);
		--SP;
		return read8Bit(ea);
	}

	std::uint16_t pop16Bit()
	{
		std::uint32_t ea = (SS << 4) + (SP - 2);
		SP -= 2;
		return read16Bit(ea);
	}

	void          write8Bit(std::uint32_t address, std::uint8_t value) { memory[address] = value; }
	void          write16Bit(std::uint32_t address, std::uint16_t value) { *reinterpret_cast<std::uint16_t*>(memory + address) = value; }
	std::uint8_t  read8Bit(std::uint32_t address) { return memory[address]; }
	std::uint16_t read16Bit(std::uint32_t address) { return *reinterpret_cast<std::uint16_t*>(memory + address); }

	void setReg8Bit(std::uint8_t dst, std::uint8_t value)
	{
		switch (dst)
		{
		case 0b000: AL(value); return;
		case 0b001: CL(value); return;
		case 0b010: DL(value); return;
		case 0b011: BL(value); return;
		case 0b100: AH(value); return;
		case 0b101: CH(value); return;
		case 0b110: DH(value); return;
		case 0b111: BH(value); return;
		}
	}

	void setReg16Bit(std::uint8_t dst, std::uint16_t value)
	{
		switch (dst)
		{
		case 0b000: AX = value; return;
		case 0b001: CX = value; return;
		case 0b010: DX = value; return;
		case 0b011: BX = value; return;
		case 0b100: SP = value; return;
		case 0b101: BP = value; return;
		case 0b110: SI = value; return;
		case 0b111: DI = value; return;
		}
	}

	void setRegSeg(std::uint8_t dst, std::uint16_t value)
	{
		switch (dst)
		{
		case 0b00: ES = value; return;
		case 0b01: CS = value; return;
		case 0b10: SS = value; return;
		case 0b11: DS = value; return;
		}
	}

	std::uint8_t reg8Bit(std::uint8_t src)
	{
		switch (src)
		{
		case 0b000: return AL();
		case 0b001: return CL();
		case 0b010: return DL();
		case 0b011: return BL();
		case 0b100: return AH();
		case 0b101: return CH();
		case 0b110: return DH();
		case 0b111: return BH();
		default: return 0;
		}
	}

	std::uint16_t reg16Bit(std::uint8_t src)
	{
		switch (src)
		{
		case 0b000: return AX;
		case 0b001: return CX;
		case 0b010: return DX;
		case 0b011: return BX;
		case 0b100: return SP;
		case 0b101: return BP;
		case 0b110: return SI;
		case 0b111: return DI;
		default: return 0;
		}
	}

	std::uint16_t regSeg(std::uint8_t src)
	{
		switch (src)
		{
		case 0b00: return ES;
		case 0b01: return CS;
		case 0b10: return SS;
		case 0b11: return DS;
		default: return 0;
		}
	}

	std::uint8_t AL() const { return static_cast<std::uint8_t>(AX & 0xFF); }
	std::uint8_t AH() const { return static_cast<std::uint8_t>((AX >> 1) & 0xFF); }
	void         AL(std::uint8_t value) { AX = AX & 0xFF00 | value; }
	void         AH(std::uint8_t value) { AX = AX & 0x00FF | (value << 8); }

	std::uint8_t DL() const { return static_cast<std::uint8_t>(DX & 0xFF); }
	std::uint8_t DH() const { return static_cast<std::uint8_t>((DX >> 1) & 0xFF); }
	void         DL(std::uint8_t value) { DX = DX & 0xFF00 | value; }
	void         DH(std::uint8_t value) { DX = DX & 0x00FF | (value << 8); }

	std::uint8_t CL() const { return static_cast<std::uint8_t>(CX & 0xFF); }
	std::uint8_t CH() const { return static_cast<std::uint8_t>((CX >> 1) & 0xFF); }
	void         CL(std::uint8_t value) { CX = CX & 0xFF00 | value; }
	void         CH(std::uint8_t value) { CX = CX & 0x00FF | (value << 8); }

	std::uint8_t BL() const { return static_cast<std::uint8_t>(BX & 0xFF); }
	std::uint8_t BH() const { return static_cast<std::uint8_t>((BX >> 1) & 0xFF); }
	void         BL(std::uint8_t value) { BX = BX & 0xFF00 | value; }
	void         BH(std::uint8_t value) { BX = BX & 0x00FF | (value << 8); }

	bool OF() const { return static_cast<bool>((F >> 11) & 1); }
	bool DF() const { return static_cast<bool>((F >> 10) & 1); }
	bool IF() const { return static_cast<bool>((F >> 9) & 1); }
	bool TF() const { return static_cast<bool>((F >> 8) & 1); }
	bool SF() const { return static_cast<bool>((F >> 7) & 1); }
	bool ZF() const { return static_cast<bool>((F >> 6) & 1); }
	bool AF() const { return static_cast<bool>((F >> 4) & 1); }
	bool PF() const { return static_cast<bool>((F >> 2) & 1); }
	bool CF() const { return static_cast<bool>(F & 1); }
	void setOF(bool value) { F = F & ~(1 << 11) | (value << 11); }
	void setDF(bool value) { F = F & ~(1 << 10) | (value << 10); }
	void setIF(bool value) { F = F & ~(1 << 9) | (value << 9); }
	void setTF(bool value) { F = F & ~(1 << 8) | (value << 8); }
	void setSF(bool value) { F = F & ~(1 << 7) | (value << 7); }
	void setZF(bool value) { F = F & ~(1 << 6) | (value << 6); }
	void setAF(bool value) { F = F & ~(1 << 4) | (value << 4); }
	void setPF(bool value) { F = F & ~(1 << 2) | (value << 2); }
	void setCF(bool value) { F = F & ~1 | value; }

	std::uint32_t EIP() const { return static_cast<std::uint32_t>(CS) << 4 + IP; }

	std::uint16_t AX = 0;
	std::uint16_t DX = 0;
	std::uint16_t CX = 0;
	std::uint16_t BX = 0;
	std::uint16_t BP = 0;
	std::uint16_t SI = 0;
	std::uint16_t DI = 0;
	std::uint16_t SP = 0;

	std::uint16_t CS = 0;
	std::uint16_t DS = 0;
	std::uint16_t SS = 0;
	std::uint16_t ES = 0;

	std::uint16_t F  = 0;
	std::uint16_t IP = 0;

	std::uint16_t Interrupt = 0;

	std::uint8_t memory[1048576] { 0 };
};

int main(int argc, char** argv)
{
	std::size_t run = 0;

	CPU* cpu = new CPU();

	using Clock = std::chrono::high_resolution_clock;

	std::uint8_t drive[512];

	while (true)
	{
		auto start = Clock::now();
		randomize(drive, sizeof(drive));
		drive[510] = 0xAA;
		drive[511] = 0x55;
		cpu->boot(drive, sizeof(drive));
		auto  end  = Clock::now();
		float time = std::chrono::duration_cast<std::chrono::duration<float>>(end - start).count();
		if (cpu->Interrupt == 0)
		{
			std::cout << "Run " << run << ": Successful execution in " << time << " seconds\n";
			std::ofstream file { "os_" + std::to_string(run) + ".bin", std::ios::binary };
			if (file)
			{
				file.write(reinterpret_cast<char*>(drive), sizeof(drive));
				file.close();
			}
		}
		else
		{
			std::cout << "Run " << run << ": Unsuccessful execution in " << time << " seconds, Interrupt=" << cpu->Interrupt << '\n';
		}

		++run;
	}
}