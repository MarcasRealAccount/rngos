%include "Core.asminc"

%if BUILD_IS_SYSTEM_WINDOWS && BUILD_IS_PLATFORM_AMD64

section .text:
	GlobalLabel rngos_intrin_add8_f ; cl => a, dl => b, r8 => pFlags
		add cl, dl
		pushfq
		pop [r8]
		mov al, cl
		ret
	GlobalLabel rngos_intrin_add16_f ; cx => a, dx => b, r8 => pFlags
		add cx, dx
		pushfq
		pop [r8]
		mov ax, cx
		ret
	GlobalLabel rngos_intrin_adc8_f ; cl => a, dl => b, r8 => pFlags
		push [r8]
		popfq
		adc cl, dl
		pushfq
		pop [r8]
		mov al, cl
		ret
	GlobalLabel rngos_intrin_adc16_f ; cx => a, dx => b, r8 => pFlags
		push [r8]
		popfq
		adc cx, dx
		pushfq
		pop [r8]
		mov ax, cx
		ret

	GlobalLabel rngos_intrin_sub8_f ; cl => a, dl => b, r8 => pFlags
		sub cl, dl
		pushfq
		pop [r8]
		mov al, cl
		ret
	GlobalLabel rngos_intrin_sub16_f ; cx => a, dx => b, r8 => pFlags
		sub cx, dx
		pushfq
		pop [r8]
		mov ax, cx
		ret
	GlobalLabel rngos_intrin_sbb8_f ; cl => a, dl => b, r8 => pFlags
		push [r8]
		popfq
		sbb cl, dl
		pushfq
		pop [r8]
		mov al, cl
		ret
	GlobalLabel rngos_intrin_sbb16_f ; cx => a, dx => b, r8 => pFlags
		push [r8]
		popfq
		sbb cx, dx
		pushfq
		pop [r8]
		mov ax, cx
		ret

	GlobalLabel rngos_intrin_mul8_f ; cl => a, dl => b, r8 => pFlags
		mov al, cl
		mul dl
		pushfq
		pop [r8]
		ret
	GlobalLabel rngos_intrin_imul8_f ; cl => a, dl => b, r8 => pFlags
		mov al, cl
		imul dl
		pushfq
		pop [r8]
		ret
	GlobalLabel rngos_intrin_mul16_f ; cx => a, dx => b, r8 => pFlags
		mov ax, cx
		mul dx
		pushfq
		pop [r8]
		shl edx, 16
		or ax, dx
		ret
	GlobalLabel rngos_intrin_imul16_f ; cx => a, dx => b, r8 => pFlags
		mov ax, cx
		imul dx
		pushfq
		pop [r8]
		shl edx, 16
		or ax, dx
		ret

	GlobalLabel rngos_intrin_div8_f ; cx => a, dl => b, r8 => pFlags
		mov ax, cx
		div dl
		pushfq
		pop [r8]
		ret
	GlobalLabel rngos_intrin_idiv8_f ; cx => a, dl => b, r8 => pFlags
		mov ax, cx
		idiv dl
		pushfq
		pop [r8]
		ret
	GlobalLabel rngos_intrin_div16_f ; cx => a, dx => b, r8d => c, r9 => pFlags
		mov ax, cx
		div r8d
		pushfq
		pop [r9]
		shl edx, 16
		or ax, dx
		ret
	GlobalLabel rngos_intrin_idiv16_f ; cx => a, dx => b, r8d => c, r9 => pFlags
		mov ax, cx
		idiv r8d
		pushfq
		pop [r9]
		shl edx, 16
		or ax, dx
		ret
		
	GlobalLabel rngos_intrin_rol8_f ; cl => a, dl => count, r9 => pFlags
		mov ax, cx
		mov cl, dl
		rol al, cl
		pushfq
		pop [r9]
		ret
	GlobalLabel rngos_intrin_ror8_f ; cl => a, dl => count, r9 => pFlags
		mov ax, cx
		mov cl, dl
		ror al, cl
		pushfq
		pop [r9]
		ret
	GlobalLabel rngos_intrin_rcl8_f ; cl => a, dl => count, r9 => pFlags
		mov ax, cx
		mov cl, dl
		rcl al, cl
		pushfq
		pop [r9]
		ret
	GlobalLabel rngos_intrin_rcr8_f ; cl => a, dl => count, r9 => pFlags
		mov ax, cx
		mov cl, dl
		rcr al, cl
		pushfq
		pop [r9]
		ret
	GlobalLabel rngos_intrin_shl8_f ; cl => a, dl => count, r9 => pFlags
		mov ax, cx
		mov cl, dl
		shl al, cl
		pushfq
		pop [r9]
		ret
	GlobalLabel rngos_intrin_shr8_f ; cl => a, dl => count, r9 => pFlags
		mov ax, cx
		mov cl, dl
		shr al, cl
		pushfq
		pop [r9]
		ret
	GlobalLabel rngos_intrin_sar8_f ; cl => a, dl => count, r9 => pFlags
		mov ax, cx
		mov cl, dl
		sar al, cl
		pushfq
		pop [r9]
		ret
	GlobalLabel rngos_intrin_rol16_f ; cx => a, dl => count, r9 => pFlags
		mov ax, cx
		mov cl, dl
		rol ax, cl
		pushfq
		pop [r9]
		ret
	GlobalLabel rngos_intrin_ror16_f ; cx => a, dl => count, r9 => pFlags
		mov ax, cx
		mov cl, dl
		ror ax, cl
		pushfq
		pop [r9]
		ret
	GlobalLabel rngos_intrin_rcl16_f ; cx => a, dl => count, r9 => pFlags
		mov ax, cx
		mov cl, dl
		rcl ax, cl
		pushfq
		pop [r9]
		ret
	GlobalLabel rngos_intrin_rcr16_f ; cx => a, dl => count, r9 => pFlags
		mov ax, cx
		mov cl, dl
		rcr ax, cl
		pushfq
		pop [r9]
		ret
	GlobalLabel rngos_intrin_shl16_f ; cx => a, dl => count, r9 => pFlags
		mov ax, cx
		mov cl, dl
		shl ax, cl
		pushfq
		pop [r9]
		ret
	GlobalLabel rngos_intrin_shr16_f ; cx => a, dl => count, r9 => pFlags
		mov ax, cx
		mov cl, dl
		shr ax, cl
		pushfq
		pop [r9]
		ret
	GlobalLabel rngos_intrin_sar16_f ; cx => a, dl => count, r9 => pFlags
		mov ax, cx
		mov cl, dl
		sar ax, cl
		pushfq
		pop [r9]
		ret

	GlobalLabel rngos_intrin_and8_f ; cl => a, dl => b, r8 => pFlags
		and cl, dl
		pushfq
		pop [r8]
		mov al, cl
		ret
	GlobalLabel rngos_intrin_and16_f ; cx => a, dx => b, r8 => pFlags
		and cx, dx
		pushfq
		pop [r8]
		mov ax, cx
		ret

	GlobalLabel rngos_intrin_or8_f ; cl => a, dl => b, r8 => pFlags
		or cl, dl
		pushfq
		pop [r8]
		mov al, cl
		ret
	GlobalLabel rngos_intrin_or16_f ; cx => a, dx => b, r8 => pFlags
		or cx, dx
		pushfq
		pop [r8]
		mov ax, cx
		ret

	GlobalLabel rngos_intrin_xor8_f ; cl => a, dl => b, r8 => pFlags
		xor cl, dl
		pushfq
		pop [r8]
		mov al, cl
		ret
	GlobalLabel rngos_intrin_xor16_f ; cx => a, dx => b, r8 => pFlags
		xor cx, dx
		pushfq
		pop [r8]
		mov ax, cx
		ret

	GlobalLabel rngos_intrin_not8_f ; cl => a, rdx => pFlags
		not cl
		pushfq
		pop [rdx]
		mov al, cl
		ret
	GlobalLabel rngos_intrin_not16_f ; cx => a, rdx => pFlags
		not cx
		pushfq
		pop [rdx]
		mov ax, cx
		ret

	GlobalLabel rngos_intrin_cmp8_f ; cl => a, dl => b, r8 => pFlags
		cmp cl, dl
		pushfq
		pop [r8]
		mov al, cl
		ret
	GlobalLabel rngos_intrin_cmp16_f ; cx => a, dx => b, r8 => pFlags
		cmp cx, dx
		pushfq
		pop [r8]
		mov ax, cx
		ret

%endif