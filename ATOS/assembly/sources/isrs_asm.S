; In just a few pages in this tutorial, we will add our Interrupt
; Service Routines (ISRs) right here!


;0          Division By Zero Exception              No
;1          Debug Exception                         No
;2          Non Maskable Interrupt Exception        No
;3          Breakpoint Exception                    No
;4          Into Detected Overflow Exception        No
;5          Out of Bounds Exception                 No
;6          Invalid Opcode Exception                No
;7          No Coprocessor Exception                No
;8          Double Fault Exception                  Yes
;9          Coprocessor Segment Overrun Exception   No
;10         Bad TSS Exception                       Yes
;11         Segment Not Present Exception           Yes
;12         Stack Fault Exception                   Yes
;13         General Protection Fault Exception      Yes
;14         Page Fault Exception                    Yes
;15         Unknown Interrupt Exception             No
;16         Coprocessor Fault Exception             No
;17         Alignment Check Exception (486+)        No
;18         Machine Check Exception (Pentium/586+)  No
;19 to 31   Reserved Exceptions No

global isr0 
global isr1
global isr2
global isr3
global isr4
global isr5
global isr6
global isr7
global isr8
global isr9
global isr10
global isr11
global isr12
global isr13
global isr14
global isr15
global isr16
global isr17
global isr18
global isr19
global isr20
global isr21
global isr22
global isr23
global isr24
global isr25
global isr26
global isr27
global isr28
global isr29
global isr30
global isr31

global irq0
global irq1
global irq2
global irq3
global irq4
global irq5
global irq6
global irq7
global irq8
global irq9
global irq10
global irq11
global irq12
global irq13
global irq14
global irq15


;  0: Divide By Zero Exception
isr0:
    cli
    push byte 0    ; A normal ISR stub that pops a dummy error code to keep a
                   ; uniform stack frame
    push byte 0
    jmp isr_common_stub

;  1: Debug Exception
isr1:
    cli
    push byte 0
    push byte 1
    jmp isr_common_stub

;  2: Non masquable interrupt exception
isr2:
    cli
    push byte 0
    push byte 2
    jmp isr_common_stub

;  3: Breakpoint exception
isr3:
    cli
    push byte 0
    push byte 3
    jmp isr_common_stub

;  4: Overflow exception
isr4:
    cli
    push byte 0
    push byte 4
    jmp isr_common_stub

;   5: Out of bounds exception
isr5:
    cli
    push byte 0
    push byte 5
    jmp isr_common_stub

;   6: Invalid OPcode exception
isr6:
    cli
    push byte 0
    push byte 6
    jmp isr_common_stub

;   7: No coprocessor
isr7:
    cli
    push byte 0
    push byte 7
    jmp isr_common_stub

;  8: Double Fault Exception (With Error Code!)
isr8:
    cli
    push byte 8    ; Note that we DON'T push a value on the stack in this one!
                   ; It pushes one already! Use this type of stub for exceptions
                   ; that pop error codes!
    jmp isr_common_stub

;  9: Coprocessor segment overrun exception
isr9: 
    cli
    push byte 0
    push byte 9
    jmp isr_common_stub

;  10: Bad TSS exception
isr10:
    cli
    push byte 10
    jmp isr_common_stub

;  11: Segment not present exception
isr11:
    cli
    push byte 11
    jmp isr_common_stub

;  12: Stack fault exception
isr12:
    cli
    push byte 12
    jmp isr_common_stub

;  13: General Protection Flault exception
isr13: 
    cli
    push byte 13
    jmp isr_common_stub

;  14: Page fault exception
isr14: 
    cli
    push byte 14
    jmp isr_common_stub

;  15: Unknown interrupt exception
isr15: 
    cli
    push byte 0
    push byte 15
    jmp isr_common_stub

;  16: Coprocessor Fault exception
isr16: 
    cli
    push byte 0
    push byte 16
    jmp isr_common_stub

;  17: Alignement check exception
isr17: 
    cli
    push byte 0
    push byte 17
    jmp isr_common_stub

;  18: Machine check exception
isr18: 
    cli
    push byte 0
    push byte 18
    jmp isr_common_stub

;  Reserved exception
isr19: 
    cli
    push byte 0
    push byte 19
    jmp isr_common_stub

;  Reserved exception
isr20: 
    cli
    push byte 0
    push byte 20
    jmp isr_common_stub

;  Reserved exception
isr21: 
    cli
    push byte 0
    push byte 21
    jmp isr_common_stub

;  Reserved exception
isr22: 
    cli
    push byte 0
    push byte 22
    jmp isr_common_stub

;  Reserved exception
isr23: 
    cli
    push byte 0
    push byte 23
    jmp isr_common_stub

;  Reserved exception
isr24: 
    cli
    push byte 0
    push byte 24
    jmp isr_common_stub

;  Reserved exception
isr25: 
    cli
    push byte 0
    push byte 25
    jmp isr_common_stub

;  Reserved exception
isr26: 
    cli
    push byte 0
    push byte 26
    jmp isr_common_stub

;  Reserved exception
isr27: 
    cli
    push byte 0
    push byte 27
    jmp isr_common_stub

;  Reserved exception
isr28: 
    cli
    push byte 0
    push byte 28
    jmp isr_common_stub

;  Reserved exception
isr29: 
    cli
    push byte 0
    push byte 29
    jmp isr_common_stub

;  Reserved exception
isr30: 
    cli
    push byte 0
    push byte 30
    jmp isr_common_stub

;  Reserved exception
isr31: 
    cli
    push byte 0
    push byte 31
    jmp isr_common_stub

extern _fault_handler

; This is our common ISR stub. It saves the processor state, sets
; up for kernel mode segments, calls the C-level fault handler,
; and finally restores the stack frame.
isr_common_stub:
    pusha
    push ds
    push es
    push fs
    push gs
    mov ax, 0x10   ; Load the Kernel Data Segment descriptor!
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov eax, esp   ; Push us the stack
    push eax
    mov eax, _fault_handler
    call eax       ; A special call, preserves the 'eip' register
    pop eax
    pop gs
    pop fs
    pop es
    pop ds
    popa
    add esp, 8     ; Cleans up the pushed error code and pushed ISR number
    iret           ; pops 5 things at once: CS, EIP, EFLAGS, SS, and ESP!
        

; 32: IRQ0
irq0:
    cli
    push byte 0    ; Note that these don't push an error code on the stack:
                   ; We need to push a dummy error code
    push byte 32
    jmp irq_common_stub

irq1:
    cli
    push byte 0
    push byte 33
    jmp irq_common_stub

irq2:
    cli
    push byte 0
    push byte 34
    jmp irq_common_stub

irq3:
    cli
    push byte 0
    push byte 35
    jmp irq_common_stub

irq4:
    cli
    push byte 0
    push byte 36
    jmp irq_common_stub

irq5:
    cli
    push byte 0
    push byte 37
    jmp irq_common_stub

irq6:
    cli
    push byte 0
    push byte 38
    jmp irq_common_stub

irq7:
    cli
    push byte 0
    push byte 39
    jmp irq_common_stub

irq8:
    cli
    push byte 0
    push byte 40
    jmp irq_common_stub

irq9:
    cli
    push byte 0
    push byte 41
    jmp irq_common_stub

irq10:
    cli
    push byte 0
    push byte 42
    jmp irq_common_stub

irq11:
    cli
    push byte 0
    push byte 43
    jmp irq_common_stub

irq12:
    cli
    push byte 0
    push byte 44
    jmp irq_common_stub

irq13:
    cli
    push byte 0
    push byte 45
    jmp irq_common_stub

irq14:
    cli
    push byte 0
    push byte 46
    jmp irq_common_stub

; 47: IRQ15
irq15:
    cli
    push byte 0
    push byte 47
    jmp irq_common_stub


extern _irq_handler

; This is a stub that we have created for IRQ based ISRs. This calls
; '_irq_handler' in our C code. We need to create this in an 'irq.c'
irq_common_stub:
    pusha
    push ds
    push es
    push fs
    push gs
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov eax, esp
    push eax
    mov eax, _irq_handler
    call eax
    pop eax
    pop gs
    pop fs
    pop es
    pop ds
    popa
    add esp, 8
    iret