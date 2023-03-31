# Projecto 2 - IAED 2022/2023

## Enunciado

O enunciado do projecto está disponível em [enunciado.md](enunciado.md). 

## Data de entrega: 14 de abril de 2023, às 19h59

Informações detalhadas sobre o processo de submissão estão disponíveis em [informacoes.md](informacoes.md).



# Evaluation

2023-03-31T11:15:34

## Test 1: [+ Accepted+].
## Test 2: [+ Accepted+].
## Test 3: [- Wrong Answer-].


## Test 4: [- Wrong Answer-].


## Test 5: [- Wrong Answer-].


## Test 6: [- Wrong Answer-].


## Test 7: [- Command terminated by signal (11: SIGSEGV)-].

## Test 8: [- Command terminated by signal (11: SIGSEGV)-].

## Test 9: [- Wrong Answer-].


## Test 10: [- Wrong Answer-].


## Test 11: [- Wrong Answer-].


## Test 12: [- Wrong Answer-].


## Test 13: [- Wrong Answer-].


## Test 14: [- Wrong Answer-].


## Test 15: [- Wrong Answer-].


## Test 16: [- Wrong Answer-].


## Test 17: [- Wrong Answer-].


## Test 18: [- Command terminated by signal (11: SIGSEGV)-].

## Test 19: [- Command terminated by signal (11: SIGSEGV)-].

## Test 20: [- Command terminated by signal (11: SIGSEGV)-].

## Test 21: [- Command terminated by signal (11: SIGSEGV)-].

## Test 22: [+ Accepted+].
## Test 23: [+ Accepted+].
## Test 24: [- Command terminated by signal (11: SIGSEGV)-].

## Test 25: [- Command terminated by signal (11: SIGSEGV)-].

## Test 26: [- Command terminated by signal (11: SIGSEGV)-].

## Test 27: [+ Accepted+].
## Test 28: [+ Accepted+].
## Test 29: [+ Accepted+].
## Test 30: [- Command terminated by signal (6: SIGABRT)-].

## Test 31: [- Command terminated by signal (11: SIGSEGV)-].

## Test 32: [- Wrong Answer-].




## Number of passed tests: 7/32


## Valgrind Output:


```
==32217== Memcheck, a memory error detector
==32217== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==32217== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==32217== Command: ./proj.out
==32217== 
==32217== Invalid read of size 8
==32217==    at 0x109B47: list_lines (lines.c:125)
==32217==    by 0x10922A: prompt_command (proj2.c:27)
==32217==    by 0x10922A: main (proj2.c:7)
==32217==  Address 0x4b950e8 is 8 bytes inside a block of size 48 free'd
==32217==    at 0x48369AB: free (vg_replace_malloc.c:530)
==32217==    by 0x10AAAD: remove_stop (remove.c:56)
==32217==    by 0x10920A: prompt_command (proj2.c:42)
==32217==    by 0x10920A: main (proj2.c:7)
==32217==  Block was alloc'd at
==32217==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==32217==    by 0x109E5A: wrap_calloc (memory.c:8)
==32217==    by 0x1093B4: create_node (connect.c:70)
==32217==    by 0x1093B4: connect_connection (connect.c:57)
==32217==    by 0x109813: handle_connect (connect.c:28)
==32217==    by 0x1091EA: prompt_command (proj2.c:33)
==32217==    by 0x1091EA: main (proj2.c:7)
==32217== 
==32217== Invalid read of size 8
==32217==    at 0x109B4E: list_lines (lines.c:125)
==32217==    by 0x10922A: prompt_command (proj2.c:27)
==32217==    by 0x10922A: main (proj2.c:7)
==32217==  Address 0x4b941c0 is 0 bytes inside a block of size 40 free'd
==32217==    at 0x48369AB: free (vg_replace_malloc.c:530)
==32217==    by 0x10AB12: remove_stop (remove.c:63)
==32217==    by 0x10920A: prompt_command (proj2.c:42)
==32217==    by 0x10920A: main (proj2.c:7)
==32217==  Block was alloc'd at
==32217==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==32217==    by 0x109E5A: wrap_calloc (memory.c:8)
==32217==    by 0x10AC24: create_stop (stops.c:35)
==32217==    by 0x1091DA: prompt_command (proj2.c:30)
==32217==    by 0x1091DA: main (proj2.c:7)
==32217== 
==32217== Invalid read of size 1
==32217==    at 0x4838CC2: __strlen_sse2 (vg_replace_strmem.c:462)
==32217==    by 0x4A21B1E: vfprintf (vfprintf.c:1638)
==32217==    by 0x4A28735: printf (printf.c:33)
==32217==    by 0x109B57: list_lines (lines.c:125)
==32217==    by 0x10922A: prompt_command (proj2.c:27)
==32217==    by 0x10922A: main (proj2.c:7)
==32217==  Address 0x4b940d0 is 0 bytes inside a block of size 9 free'd
==32217==    at 0x48369AB: free (vg_replace_malloc.c:530)
==32217==    by 0x10A2AB: free_stop (memory.c:123)
==32217==    by 0x10AB12: remove_stop (remove.c:63)
==32217==    by 0x10920A: prompt_command (proj2.c:42)
==32217==    by 0x10920A: main (proj2.c:7)
==32217==  Block was alloc'd at
==32217==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==32217==    by 0x109E5A: wrap_calloc (memory.c:8)
==32217==    by 0x10A58A: read_line (parsing.c:16)
==32217==    by 0x10912D: main (proj2.c:5)
==32217== 
==32217== Invalid read of size 1
==32217==    at 0x4838CD4: __strlen_sse2 (vg_replace_strmem.c:462)
==32217==    by 0x4A21B1E: vfprintf (vfprintf.c:1638)
==32217==    by 0x4A28735: printf (printf.c:33)
==32217==    by 0x109B57: list_lines (lines.c:125)
==32217==    by 0x10922A: prompt_command (proj2.c:27)
==32217==    by 0x10922A: main (proj2.c:7)
==32217==  Address 0x4b940d1 is 1 bytes inside a block of size 9 free'd
==32217==    at 0x48369AB: free (vg_replace_malloc.c:530)
==32217==    by 0x10A2AB: free_stop (memory.c:123)
==32217==    by 0x10AB12: remove_stop (remove.c:63)
==32217==    by 0x10920A: prompt_command (proj2.c:42)
==32217==    by 0x10920A: main (proj2.c:7)
==32217==  Block was alloc'd at
==32217==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==32217==    by 0x109E5A: wrap_calloc (memory.c:8)
==32217==    by 0x10A58A: read_line (parsing.c:16)
==32217==    by 0x10912D: main (proj2.c:5)
==32217== 
==32217== Invalid read of size 1
==32217==    at 0x483D4E0: mempcpy (vg_replace_strmem.c:1536)
==32217==    by 0x4A4BB24: _IO_new_file_xsputn (fileops.c:1243)
==32217==    by 0x4A4BB24: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1204)
==32217==    by 0x4A2032A: vfprintf (vfprintf.c:1638)
==32217==    by 0x4A28735: printf (printf.c:33)
==32217==    by 0x109B57: list_lines (lines.c:125)
==32217==    by 0x10922A: prompt_command (proj2.c:27)
==32217==    by 0x10922A: main (proj2.c:7)
==32217==  Address 0x4b940d7 is 7 bytes inside a block of size 9 free'd
==32217==    at 0x48369AB: free (vg_replace_malloc.c:530)
==32217==    by 0x10A2AB: free_stop (memory.c:123)
==32217==    by 0x10AB12: remove_stop (remove.c:63)
==32217==    by 0x10920A: prompt_command (proj2.c:42)
==32217==    by 0x10920A: main (proj2.c:7)
==32217==  Block was alloc'd at
==32217==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==32217==    by 0x109E5A: wrap_calloc (memory.c:8)
==32217==    by 0x10A58A: read_line (parsing.c:16)
==32217==    by 0x10912D: main (proj2.c:5)
==32217== 
==32217== Invalid read of size 1
==32217==    at 0x483D4F1: mempcpy (vg_replace_strmem.c:1536)
==32217==    by 0x4A4BB24: _IO_new_file_xsputn (fileops.c:1243)
==32217==    by 0x4A4BB24: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1204)
==32217==    by 0x4A2032A: vfprintf (vfprintf.c:1638)
==32217==    by 0x4A28735: printf (printf.c:33)
==32217==    by 0x109B57: list_lines (lines.c:125)
==32217==    by 0x10922A: prompt_command (proj2.c:27)
==32217==    by 0x10922A: main (proj2.c:7)
==32217==  Address 0x4b940d5 is 5 bytes inside a block of size 9 free'd
==32217==    at 0x48369AB: free (vg_replace_malloc.c:530)
==32217==    by 0x10A2AB: free_stop (memory.c:123)
==32217==    by 0x10AB12: remove_stop (remove.c:63)
==32217==    by 0x10920A: prompt_command (proj2.c:42)
==32217==    by 0x10920A: main (proj2.c:7)
==32217==  Block was alloc'd at
==32217==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==32217==    by 0x109E5A: wrap_calloc (memory.c:8)
==32217==    by 0x10A58A: read_line (parsing.c:16)
==32217==    by 0x10912D: main (proj2.c:5)
==32217== 
==32217== Invalid write of size 8
==32217==    at 0x10AA90: remove_stop (remove.c:38)
==32217==    by 0x10920A: prompt_command (proj2.c:42)
==32217==    by 0x10920A: main (proj2.c:7)
==32217==  Address 0x4b950f0 is 16 bytes inside a block of size 48 free'd
==32217==    at 0x48369AB: free (vg_replace_malloc.c:530)
==32217==    by 0x10AAAD: remove_stop (remove.c:56)
==32217==    by 0x10920A: prompt_command (proj2.c:42)
==32217==    by 0x10920A: main (proj2.c:7)
==32217==  Block was alloc'd at
==32217==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==32217==    by 0x109E5A: wrap_calloc (memory.c:8)
==32217==    by 0x1093B4: create_node (connect.c:70)
==32217==    by 0x1093B4: connect_connection (connect.c:57)
==32217==    by 0x109813: handle_connect (connect.c:28)
==32217==    by 0x1091EA: prompt_command (proj2.c:33)
==32217==    by 0x1091EA: main (proj2.c:7)
==32217== 
==32217== Invalid read of size 16
==32217==    at 0x10AB53: remove_stop (remove.c:49)
==32217==    by 0x10920A: prompt_command (proj2.c:42)
==32217==    by 0x10920A: main (proj2.c:7)
==32217==  Address 0x4b95100 is 32 bytes inside a block of size 48 free'd
==32217==    at 0x48369AB: free (vg_replace_malloc.c:530)
==32217==    by 0x10AAAD: remove_stop (remove.c:56)
==32217==    by 0x10920A: prompt_command (proj2.c:42)
==32217==    by 0x10920A: main (proj2.c:7)
==32217==  Block was alloc'd at
==32217==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==32217==    by 0x109E5A: wrap_calloc (memory.c:8)
==32217==    by 0x1093B4: create_node (connect.c:70)
==32217==    by 0x1093B4: connect_connection (connect.c:57)
==32217==    by 0x109813: handle_connect (connect.c:28)
==32217==    by 0x1091EA: prompt_command (proj2.c:33)
==32217==    by 0x1091EA: main (proj2.c:7)
==32217== 
==32217== Invalid write of size 8
==32217==    at 0x10AB69: remove_stop (remove.c:51)
==32217==    by 0x10920A: prompt_command (proj2.c:42)
==32217==    by 0x10920A: main (proj2.c:7)
==32217==  Address 0x4b95100 is 32 bytes inside a block of size 48 free'd
==32217==    at 0x48369AB: free (vg_replace_malloc.c:530)
==32217==    by 0x10AAAD: remove_stop (remove.c:56)
==32217==    by 0x10920A: prompt_command (proj2.c:42)
==32217==    by 0x10920A: main (proj2.c:7)
==32217==  Block was alloc'd at
==32217==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==32217==    by 0x109E5A: wrap_calloc (memory.c:8)
==32217==    by 0x1093B4: create_node (connect.c:70)
==32217==    by 0x1093B4: connect_connection (connect.c:57)
==32217==    by 0x109813: handle_connect (connect.c:28)
==32217==    by 0x1091EA: prompt_command (proj2.c:33)
==32217==    by 0x1091EA: main (proj2.c:7)
==32217== 
==32217== Invalid read of size 8
==32217==    at 0x109B5F: list_lines (lines.c:126)
==32217==    by 0x10922A: prompt_command (proj2.c:27)
==32217==    by 0x10922A: main (proj2.c:7)
==32217==  Address 0x4b950e8 is 8 bytes inside a block of size 48 free'd
==32217==    at 0x48369AB: free (vg_replace_malloc.c:530)
==32217==    by 0x10AAAD: remove_stop (remove.c:56)
==32217==    by 0x10920A: prompt_command (proj2.c:42)
==32217==    by 0x10920A: main (proj2.c:7)
==32217==  Block was alloc'd at
==32217==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==32217==    by 0x109E5A: wrap_calloc (memory.c:8)
==32217==    by 0x1093B4: create_node (connect.c:70)
==32217==    by 0x1093B4: connect_connection (connect.c:57)
==32217==    by 0x109813: handle_connect (connect.c:28)
==32217==    by 0x1091EA: prompt_command (proj2.c:33)
==32217==    by 0x1091EA: main (proj2.c:7)
==32217== 
==32217== Invalid read of size 8
==32217==    at 0x109B63: list_lines (lines.c:126)
==32217==    by 0x10922A: prompt_command (proj2.c:27)
==32217==    by 0x10922A: main (proj2.c:7)
==32217==  Address 0x4b941c0 is 0 bytes inside a block of size 40 free'd
==32217==    at 0x48369AB: free (vg_replace_malloc.c:530)
==32217==    by 0x10AB12: remove_stop (remove.c:63)
==32217==    by 0x10920A: prompt_command (proj2.c:42)
==32217==    by 0x10920A: main (proj2.c:7)
==32217==  Block was alloc'd at
==32217==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==32217==    by 0x109E5A: wrap_calloc (memory.c:8)
==32217==    by 0x10AC24: create_stop (stops.c:35)
==32217==    by 0x1091DA: prompt_command (proj2.c:30)
==32217==    by 0x1091DA: main (proj2.c:7)
==32217== 
==32217== Invalid read of size 1
==32217==    at 0x4838CC2: __strlen_sse2 (vg_replace_strmem.c:462)
==32217==    by 0x4A21B1E: vfprintf (vfprintf.c:1638)
==32217==    by 0x4A28735: printf (printf.c:33)
==32217==    by 0x109B6C: list_lines (lines.c:126)
==32217==    by 0x10922A: prompt_command (proj2.c:27)
==32217==    by 0x10922A: main (proj2.c:7)
==32217==  Address 0x4b940d0 is 0 bytes inside a block of size 9 free'd
==32217==    at 0x48369AB: free (vg_replace_malloc.c:530)
==32217==    by 0x10A2AB: free_stop (memory.c:123)
==32217==    by 0x10AB12: remove_stop (remove.c:63)
==32217==    by 0x10920A: prompt_command (proj2.c:42)
==32217==    by 0x10920A: main (proj2.c:7)
==32217==  Block was alloc'd at
==32217==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==32217==    by 0x109E5A: wrap_calloc (memory.c:8)
==32217==    by 0x10A58A: read_line (parsing.c:16)
==32217==    by 0x10912D: main (proj2.c:5)
==32217== 
==32217== Invalid read of size 1
==32217==    at 0x4838CD4: __strlen_sse2 (vg_replace_strmem.c:462)
==32217==    by 0x4A21B1E: vfprintf (vfprintf.c:1638)
==32217==    by 0x4A28735: printf (printf.c:33)
==32217==    by 0x109B6C: list_lines (lines.c:126)
==32217==    by 0x10922A: prompt_command (proj2.c:27)
==32217==    by 0x10922A: main (proj2.c:7)
==32217==  Address 0x4b940d1 is 1 bytes inside a block of size 9 free'd
==32217==    at 0x48369AB: free (vg_replace_malloc.c:530)
==32217==    by 0x10A2AB: free_stop (memory.c:123)
==32217==    by 0x10AB12: remove_stop (remove.c:63)
==32217==    by 0x10920A: prompt_command (proj2.c:42)
==32217==    by 0x10920A: main (proj2.c:7)
==32217==  Block was alloc'd at
==32217==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==32217==    by 0x109E5A: wrap_calloc (memory.c:8)
==32217==    by 0x10A58A: read_line (parsing.c:16)
==32217==    by 0x10912D: main (proj2.c:5)
==32217== 
==32217== Invalid read of size 8
==32217==    at 0x109FA0: free_line (memory.c:76)
==32217==    by 0x10A9F4: remove_line (remove.c:18)
==32217==    by 0x10915A: prompt_command (proj2.c:39)
==32217==    by 0x10915A: main (proj2.c:7)
==32217==  Address 0x4b97630 is 16 bytes inside a block of size 48 free'd
==32217==    at 0x48369AB: free (vg_replace_malloc.c:530)
==32217==    by 0x10AAAD: remove_stop (remove.c:56)
==32217==    by 0x10920A: prompt_command (proj2.c:42)
==32217==    by 0x10920A: main (proj2.c:7)
==32217==  Block was alloc'd at
==32217==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==32217==    by 0x109E5A: wrap_calloc (memory.c:8)
==32217==    by 0x1093B4: create_node (connect.c:70)
==32217==    by 0x1093B4: connect_connection (connect.c:57)
==32217==    by 0x109813: handle_connect (connect.c:28)
==32217==    by 0x1091EA: prompt_command (proj2.c:33)
==32217==    by 0x1091EA: main (proj2.c:7)
==32217== 
==32217== Invalid read of size 8
==32217==    at 0x109F70: free_line (memory.c:79)
==32217==    by 0x10A9F4: remove_line (remove.c:18)
==32217==    by 0x10915A: prompt_command (proj2.c:39)
==32217==    by 0x10915A: main (proj2.c:7)
==32217==  Address 0x10 is not stack'd, malloc'd or (recently) free'd
==32217== 
==32217== 
==32217== Process terminating with default action of signal 11 (SIGSEGV)
==32217==  Access not within mapped region at address 0x10
==32217==    at 0x109F70: free_line (memory.c:79)
==32217==    by 0x10A9F4: remove_line (remove.c:18)
==32217==    by 0x10915A: prompt_command (proj2.c:39)
==32217==    by 0x10915A: main (proj2.c:7)
==32217==  If you believe this happened as a result of a stack
==32217==  overflow in your program's main thread (unlikely but
==32217==  possible), you can try to increase the size of the
==32217==  main thread stack using the --main-stacksize= flag.
==32217==  The main thread stack size used in this run was 8388608.
==32217== 
==32217== HEAP SUMMARY:
==32217==     in use at exit: 266 bytes in 10 blocks
==32217==   total heap usage: 293 allocs, 283 frees, 12,184 bytes allocated
==32217== 
==32217== LEAK SUMMARY:
==32217==    definitely lost: 0 bytes in 0 blocks
==32217==    indirectly lost: 0 bytes in 0 blocks
==32217==      possibly lost: 0 bytes in 0 blocks
==32217==    still reachable: 266 bytes in 10 blocks
==32217==         suppressed: 0 bytes in 0 blocks
==32217== Rerun with --leak-check=full to see details of leaked memory
==32217== 
==32217== For counts of detected and suppressed errors, rerun with: -v
==32217== ERROR SUMMARY: 246 errors from 15 contexts (suppressed: 0 from 0)

```


Your code will not be reevaluated if you submit before 2023-03-31 11:25:34 @ Lisbon, Portugal. You need to wait 10 minute(s).

