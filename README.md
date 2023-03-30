# Projecto 2 - IAED 2022/2023

## Enunciado

O enunciado do projecto está disponível em [enunciado.md](enunciado.md). 

## Data de entrega: 14 de abril de 2023, às 19h59

Informações detalhadas sobre o processo de submissão estão disponíveis em [informacoes.md](informacoes.md).



# Evaluation

2023-03-30T18:51:22

## Test 1: [+ Accepted+].
## Test 2: [+ Accepted+].
## Test 3: [+ Accepted+].
## Test 4: [- Wrong Answer-].


## Test 5: [+ Accepted+].
## Test 6: [+ Accepted+].
## Test 7: [- Wrong Answer-].


## Test 8: [- Wrong Answer-].


## Test 9: [- Wrong Answer-].


## Test 10: [- Wrong Answer-].


## Test 11: [- Wrong Answer-].


## Test 12: [- Wrong Answer-].


## Test 13: [- Wrong Answer-].


## Test 14: [- Wrong Answer-].


## Test 15: [- Wrong Answer-].


## Test 16: [- Wrong Answer-].


## Test 17: [- Wrong Answer-].


## Test 18: [- Command terminated by signal (6: SIGABRT)-].

## Test 19: [- Command terminated by signal (6: SIGABRT)-].

## Test 20: [- Wrong Answer-].


## Test 21: [- Wrong Answer-].


## Test 22: [+ Accepted+].
## Test 23: [- Command terminated by signal (6: SIGABRT)-].

## Test 24: [- Wrong Answer-].


## Test 25: [- Command terminated by signal (11: SIGSEGV)-].

## Test 26: [- Command terminated by signal (11: SIGSEGV)-].

## Test 27: [+ Accepted+].
## Test 28: [- Command terminated by signal (6: SIGABRT)-].

## Test 29: [+ Accepted+].
## Test 30: [- Command terminated by signal (11: SIGSEGV)-].

## Test 31: [- Wrong Answer-].


## Test 32: [- Wrong Answer-].




## Number of passed tests: 8/32


## Valgrind Output:


```
==11041== Memcheck, a memory error detector
==11041== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==11041== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==11041== Command: ./proj.out
==11041== 
==11041== Invalid read of size 8
==11041==    at 0x109B4E: list_lines (lines.c:125)
==11041==    by 0x10922A: prompt_command (proj2.c:27)
==11041==    by 0x10922A: main (proj2.c:7)
==11041==  Address 0x4b941c0 is 0 bytes inside a block of size 40 free'd
==11041==    at 0x48369AB: free (vg_replace_malloc.c:530)
==11041==    by 0x10A9E0: remove_stop (remove.c:62)
==11041==    by 0x10920A: prompt_command (proj2.c:42)
==11041==    by 0x10920A: main (proj2.c:7)
==11041==  Block was alloc'd at
==11041==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==11041==    by 0x109E40: wrap_calloc (memory.c:8)
==11041==    by 0x10AAD4: create_stop (stops.c:35)
==11041==    by 0x1091DA: prompt_command (proj2.c:30)
==11041==    by 0x1091DA: main (proj2.c:7)
==11041== 
==11041== Invalid read of size 1
==11041==    at 0x4838CC2: __strlen_sse2 (vg_replace_strmem.c:462)
==11041==    by 0x4A21B1E: vfprintf (vfprintf.c:1638)
==11041==    by 0x4A28735: printf (printf.c:33)
==11041==    by 0x109B57: list_lines (lines.c:125)
==11041==    by 0x10922A: prompt_command (proj2.c:27)
==11041==    by 0x10922A: main (proj2.c:7)
==11041==  Address 0x4b940d0 is 0 bytes inside a block of size 9 free'd
==11041==    at 0x48369AB: free (vg_replace_malloc.c:530)
==11041==    by 0x10A1BB: free_stop (memory.c:121)
==11041==    by 0x10A9E0: remove_stop (remove.c:62)
==11041==    by 0x10920A: prompt_command (proj2.c:42)
==11041==    by 0x10920A: main (proj2.c:7)
==11041==  Block was alloc'd at
==11041==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==11041==    by 0x109E40: wrap_calloc (memory.c:8)
==11041==    by 0x10A47A: read_line (parsing.c:16)
==11041==    by 0x10912D: main (proj2.c:5)
==11041== 
==11041== Invalid read of size 1
==11041==    at 0x4838CD4: __strlen_sse2 (vg_replace_strmem.c:462)
==11041==    by 0x4A21B1E: vfprintf (vfprintf.c:1638)
==11041==    by 0x4A28735: printf (printf.c:33)
==11041==    by 0x109B57: list_lines (lines.c:125)
==11041==    by 0x10922A: prompt_command (proj2.c:27)
==11041==    by 0x10922A: main (proj2.c:7)
==11041==  Address 0x4b940d1 is 1 bytes inside a block of size 9 free'd
==11041==    at 0x48369AB: free (vg_replace_malloc.c:530)
==11041==    by 0x10A1BB: free_stop (memory.c:121)
==11041==    by 0x10A9E0: remove_stop (remove.c:62)
==11041==    by 0x10920A: prompt_command (proj2.c:42)
==11041==    by 0x10920A: main (proj2.c:7)
==11041==  Block was alloc'd at
==11041==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==11041==    by 0x109E40: wrap_calloc (memory.c:8)
==11041==    by 0x10A47A: read_line (parsing.c:16)
==11041==    by 0x10912D: main (proj2.c:5)
==11041== 
==11041== Invalid read of size 1
==11041==    at 0x483D4E0: mempcpy (vg_replace_strmem.c:1536)
==11041==    by 0x4A4BB24: _IO_new_file_xsputn (fileops.c:1243)
==11041==    by 0x4A4BB24: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1204)
==11041==    by 0x4A2032A: vfprintf (vfprintf.c:1638)
==11041==    by 0x4A28735: printf (printf.c:33)
==11041==    by 0x109B57: list_lines (lines.c:125)
==11041==    by 0x10922A: prompt_command (proj2.c:27)
==11041==    by 0x10922A: main (proj2.c:7)
==11041==  Address 0x4b940d7 is 7 bytes inside a block of size 9 free'd
==11041==    at 0x48369AB: free (vg_replace_malloc.c:530)
==11041==    by 0x10A1BB: free_stop (memory.c:121)
==11041==    by 0x10A9E0: remove_stop (remove.c:62)
==11041==    by 0x10920A: prompt_command (proj2.c:42)
==11041==    by 0x10920A: main (proj2.c:7)
==11041==  Block was alloc'd at
==11041==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==11041==    by 0x109E40: wrap_calloc (memory.c:8)
==11041==    by 0x10A47A: read_line (parsing.c:16)
==11041==    by 0x10912D: main (proj2.c:5)
==11041== 
==11041== Invalid read of size 1
==11041==    at 0x483D4F1: mempcpy (vg_replace_strmem.c:1536)
==11041==    by 0x4A4BB24: _IO_new_file_xsputn (fileops.c:1243)
==11041==    by 0x4A4BB24: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1204)
==11041==    by 0x4A2032A: vfprintf (vfprintf.c:1638)
==11041==    by 0x4A28735: printf (printf.c:33)
==11041==    by 0x109B57: list_lines (lines.c:125)
==11041==    by 0x10922A: prompt_command (proj2.c:27)
==11041==    by 0x10922A: main (proj2.c:7)
==11041==  Address 0x4b940d5 is 5 bytes inside a block of size 9 free'd
==11041==    at 0x48369AB: free (vg_replace_malloc.c:530)
==11041==    by 0x10A1BB: free_stop (memory.c:121)
==11041==    by 0x10A9E0: remove_stop (remove.c:62)
==11041==    by 0x10920A: prompt_command (proj2.c:42)
==11041==    by 0x10920A: main (proj2.c:7)
==11041==  Block was alloc'd at
==11041==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==11041==    by 0x109E40: wrap_calloc (memory.c:8)
==11041==    by 0x10A47A: read_line (parsing.c:16)
==11041==    by 0x10912D: main (proj2.c:5)
==11041== 
==11041== Invalid read of size 8
==11041==    at 0x109D83: free_line (memory.c:77)
==11041==    by 0x109D83: clean_db (memory.c:51)
==11041==    by 0x10A323: wrap_realloc (memory.c:26)
==11041==    by 0x10A323: wrap_realloc (memory.c:22)
==11041==    by 0x10A323: VECremove (memory.c:148)
==11041==    by 0x10A9F6: remove_stop (remove.c:63)
==11041==    by 0x10920A: prompt_command (proj2.c:42)
==11041==    by 0x10920A: main (proj2.c:7)
==11041==  Address 0x10 is not stack'd, malloc'd or (recently) free'd
==11041== 
==11041== 
==11041== Process terminating with default action of signal 11 (SIGSEGV)
==11041==  Access not within mapped region at address 0x10
==11041==    at 0x109D83: free_line (memory.c:77)
==11041==    by 0x109D83: clean_db (memory.c:51)
==11041==    by 0x10A323: wrap_realloc (memory.c:26)
==11041==    by 0x10A323: wrap_realloc (memory.c:22)
==11041==    by 0x10A323: VECremove (memory.c:148)
==11041==    by 0x10A9F6: remove_stop (remove.c:63)
==11041==    by 0x10920A: prompt_command (proj2.c:42)
==11041==    by 0x10920A: main (proj2.c:7)
==11041==  If you believe this happened as a result of a stack
==11041==  overflow in your program's main thread (unlikely but
==11041==  possible), you can try to increase the size of the
==11041==  main thread stack using the --main-stacksize= flag.
==11041==  The main thread stack size used in this run was 8388608.
==11041== 
==11041== HEAP SUMMARY:
==11041==     in use at exit: 1,609 bytes in 38 blocks
==11041==   total heap usage: 289 allocs, 251 frees, 12,168 bytes allocated
==11041== 
==11041== LEAK SUMMARY:
==11041==    definitely lost: 768 bytes in 16 blocks
==11041==    indirectly lost: 192 bytes in 4 blocks
==11041==      possibly lost: 0 bytes in 0 blocks
==11041==    still reachable: 649 bytes in 18 blocks
==11041==         suppressed: 0 bytes in 0 blocks
==11041== Rerun with --leak-check=full to see details of leaked memory
==11041== 
==11041== For counts of detected and suppressed errors, rerun with: -v
==11041== ERROR SUMMARY: 73 errors from 6 contexts (suppressed: 0 from 0)

```


Your code will not be reevaluated if you submit before 2023-03-30 19:01:22 @ Lisbon, Portugal. You need to wait 10 minute(s).

