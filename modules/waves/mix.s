.file "mix.c";
.text;
	.align 4
.global _mix_mod;
.type _mix_mod, STT_FUNC;
_mix_mod:
	LINK 0;
	[FP+8] = R0;
	[FP+12] = R1;
	[FP+16] = R2;
	R0 = [FP+8];
	P2 = R0;
	P2 += 4;
	R0 = [P2];
	P2 = [FP+12];
	[P2] = R0;
	R0 = [FP+12];
	P1 = R0;
	P1 += 4;
	P2 = [FP+8];
	R0 = [P2];
	[P1] = R0;
	UNLINK;
	rts;
	.size	_mix_mod, .-_mix_mod
	.align 4
.global _mix_voice;
.type _mix_voice, STT_FUNC;
_mix_voice:
	LINK 12;
	[FP+8] = R0;
	[FP+12] = R1;
	[FP+16] = R2;
	P2 = [FP+8];
	R0 = [P2];
	[FP+-12] = R0;
	R0 = [FP+8];
	R0 += 4;
	[FP+8] = R0;
	P2 = [FP+8];
	R1 = [P2];
	R0 = [FP+-12];
	[FP+-4] = R0;
	[FP+-8] = R1;
	R1 = [FP+-4];
	R0 = [FP+-8];
	R0 = R1 + R0 (S);
	[FP+-12] = R0;
	P2 = [FP+12];
	R0 = [FP+-12];
	[P2] = R0;
	R0 = [FP+12];
	R0 += 4;
	[FP+12] = R0;
	P2 = [FP+12];
	R0 = [FP+-12];
	[P2] = R0;
	R0 = [FP+12];
	R0 += 4;
	[FP+12] = R0;
	P2 = [FP+12];
	R0 = [FP+-12];
	[P2] = R0;
	R0 = [FP+12];
	R0 += 4;
	[FP+12] = R0;
	P2 = [FP+12];
	R0 = [FP+-12];
	[P2] = R0;
	UNLINK;
	rts;
	.size	_mix_voice, .-_mix_voice
	.align 4
.global _mix_adc;
.type _mix_adc, STT_FUNC;
_mix_adc:
	LINK 32;
	[FP+8] = R0;
	[FP+12] = R1;
	[FP+16] = R2;
	P2 = [FP+12];
	R1 = [P2];
	P2 = [FP+8];
	R0 = [P2];
	[FP+-28] = R1;
	[FP+-32] = R0;
	R1 = [FP+-28];
	R0 = [FP+-32];
	R0 = R1 + R0 (S);
	P2 = [FP+12];
	[P2] = R0;
	R0 = [FP+12];
	R0 += 4;
	[FP+12] = R0;
	P2 = [FP+12];
	R1 = [P2];
	P2 = [FP+8];
	R0 = [P2];
	[FP+-20] = R1;
	[FP+-24] = R0;
	R1 = [FP+-20];
	R0 = [FP+-24];
	R0 = R1 + R0 (S);
	P2 = [FP+12];
	[P2] = R0;
	R0 = [FP+12];
	R0 += 4;
	[FP+12] = R0;
	P2 = [FP+12];
	R1 = [P2];
	P2 = [FP+8];
	R0 = [P2];
	[FP+-12] = R1;
	[FP+-16] = R0;
	R1 = [FP+-12];
	R0 = [FP+-16];
	R0 = R1 + R0 (S);
	P2 = [FP+12];
	[P2] = R0;
	R0 = [FP+12];
	R0 += 4;
	[FP+12] = R0;
	P2 = [FP+12];
	R1 = [P2];
	P2 = [FP+8];
	R0 = [P2];
	[FP+-4] = R1;
	[FP+-8] = R0;
	R1 = [FP+-4];
	R0 = [FP+-8];
	R0 = R1 + R0 (S);
	P2 = [FP+12];
	[P2] = R0;
	UNLINK;
	rts;
	.size	_mix_adc, .-_mix_adc
	.local	_i
	.comm	_i,4,4
	.local	_j
	.comm	_j,4,4
	.ident	"GCC: (ADI/svn-5865) 4.3.5"
