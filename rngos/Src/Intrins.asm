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
		mul cl, dl
		pushfq
		pop [r8]
		ret
	GlobalLabel rngos_intrin_imul8_f ; cl => a, dl => b, r8 => pFlags
		imul cl, dl
		pushfq
		pop [r8]
		ret
	GlobalLabel rngos_intrin_mul16_f ; cx => a, dx => b, r8 => pFlags
		mul cx, dx
		pushfq
		pop [r8]
		shl dx, 16
		or ax, dx
		ret
	GlobalLabel rngos_intrin_imul16_f ; cx => a, dx => b, r8 => pFlags
		imul cx, dx
		pushfq
		pop [r8]
		shl dx, 16
		or ax, dx
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