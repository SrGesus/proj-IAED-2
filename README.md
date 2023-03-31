# Projecto 2 - IAED 2022/2023

## Enunciado

O enunciado do projecto está disponível em [enunciado.md](enunciado.md). 

## Data de entrega: 14 de abril de 2023, às 19h59

Informações detalhadas sobre o processo de submissão estão disponíveis em [informacoes.md](informacoes.md).



# Evaluation

2023-03-31T11:58:10

## Test 1: [+ Accepted+].
## Test 2: [+ Accepted+].
## Test 3: [+ Accepted+].
## Test 4: [+ Accepted+].
## Test 5: [+ Accepted+].
## Test 6: [+ Accepted+].
## Test 7: [- Command terminated by signal (11: SIGSEGV)-].

## Test 8: [- Command terminated by signal (11: SIGSEGV)-].

## Test 9: [+ Accepted+].
## Test 10: [+ Accepted+].
## Test 11: [+ Accepted+].
## Test 12: [+ Accepted+].
## Test 13: [+ Accepted+].
## Test 14: [+ Accepted+].
## Test 15: [+ Accepted+].
## Test 16: [+ Accepted+].
## Test 17: [+ Accepted+].
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




## Number of passed tests: 20/32


## Valgrind Output:


```
==6424== Memcheck, a memory error detector
==6424== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6424== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==6424== Command: ./proj.out
==6424== 
==6424== Invalid read of size 8
==6424==    at 0x109B67: list_lines (lines.c:121)
==6424==    by 0x10922A: prompt_command (proj2.c:27)
==6424==    by 0x10922A: main (proj2.c:7)
==6424==  Address 0x4b950e8 is 8 bytes inside a block of size 48 free'd
==6424==    at 0x48369AB: free (vg_replace_malloc.c:530)
==6424==    by 0x10AA9D: remove_stop (remove.c:55)
==6424==    by 0x10920A: prompt_command (proj2.c:42)
==6424==    by 0x10920A: main (proj2.c:7)
==6424==  Block was alloc'd at
==6424==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==6424==    by 0x109E7A: wrap_calloc (memory.c:8)
==6424==    by 0x1094A1: create_node (connect.c:75)
==6424==    by 0x1094A1: connect_connection (connect.c:62)
==6424==    by 0x109843: handle_connect (connect.c:28)
==6424==    by 0x1091EA: prompt_command (proj2.c:33)
==6424==    by 0x1091EA: main (proj2.c:7)
==6424== 
==6424== Invalid read of size 8
==6424==    at 0x109B6E: list_lines (lines.c:121)
==6424==    by 0x10922A: prompt_command (proj2.c:27)
==6424==    by 0x10922A: main (proj2.c:7)
==6424==  Address 0x4b941c0 is 0 bytes inside a block of size 40 free'd
==6424==    at 0x48369AB: free (vg_replace_malloc.c:530)
==6424==    by 0x10AB07: remove_stop (remove.c:61)
==6424==    by 0x10920A: prompt_command (proj2.c:42)
==6424==    by 0x10920A: main (proj2.c:7)
==6424==  Block was alloc'd at
==6424==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==6424==    by 0x109E7A: wrap_calloc (memory.c:8)
==6424==    by 0x10ABD4: create_stop (stops.c:35)
==6424==    by 0x1091DA: prompt_command (proj2.c:30)
==6424==    by 0x1091DA: main (proj2.c:7)
==6424== 
==6424== Invalid read of size 1
==6424==    at 0x4838CC2: __strlen_sse2 (vg_replace_strmem.c:462)
==6424==    by 0x4A21B1E: vfprintf (vfprintf.c:1638)
==6424==    by 0x4A28735: printf (printf.c:33)
==6424==    by 0x109B77: list_lines (lines.c:121)
==6424==    by 0x10922A: prompt_command (proj2.c:27)
==6424==    by 0x10922A: main (proj2.c:7)
==6424==  Address 0x4b940d0 is 0 bytes inside a block of size 9 free'd
==6424==    at 0x48369AB: free (vg_replace_malloc.c:530)
==6424==    by 0x10A2CB: free_stop (memory.c:123)
==6424==    by 0x10AB07: remove_stop (remove.c:61)
==6424==    by 0x10920A: prompt_command (proj2.c:42)
==6424==    by 0x10920A: main (proj2.c:7)
==6424==  Block was alloc'd at
==6424==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==6424==    by 0x109E7A: wrap_calloc (memory.c:8)
==6424==    by 0x10A5AA: read_line (parsing.c:16)
==6424==    by 0x10912D: main (proj2.c:5)
==6424== 
==6424== Invalid read of size 1
==6424==    at 0x4838CD4: __strlen_sse2 (vg_replace_strmem.c:462)
==6424==    by 0x4A21B1E: vfprintf (vfprintf.c:1638)
==6424==    by 0x4A28735: printf (printf.c:33)
==6424==    by 0x109B77: list_lines (lines.c:121)
==6424==    by 0x10922A: prompt_command (proj2.c:27)
==6424==    by 0x10922A: main (proj2.c:7)
==6424==  Address 0x4b940d1 is 1 bytes inside a block of size 9 free'd
==6424==    at 0x48369AB: free (vg_replace_malloc.c:530)
==6424==    by 0x10A2CB: free_stop (memory.c:123)
==6424==    by 0x10AB07: remove_stop (remove.c:61)
==6424==    by 0x10920A: prompt_command (proj2.c:42)
==6424==    by 0x10920A: main (proj2.c:7)
==6424==  Block was alloc'd at
==6424==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==6424==    by 0x109E7A: wrap_calloc (memory.c:8)
==6424==    by 0x10A5AA: read_line (parsing.c:16)
==6424==    by 0x10912D: main (proj2.c:5)
==6424== 
==6424== Invalid read of size 1
==6424==    at 0x483D4E0: mempcpy (vg_replace_strmem.c:1536)
==6424==    by 0x4A4BB24: _IO_new_file_xsputn (fileops.c:1243)
==6424==    by 0x4A4BB24: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1204)
==6424==    by 0x4A2032A: vfprintf (vfprintf.c:1638)
==6424==    by 0x4A28735: printf (printf.c:33)
==6424==    by 0x109B77: list_lines (lines.c:121)
==6424==    by 0x10922A: prompt_command (proj2.c:27)
==6424==    by 0x10922A: main (proj2.c:7)
==6424==  Address 0x4b940d7 is 7 bytes inside a block of size 9 free'd
==6424==    at 0x48369AB: free (vg_replace_malloc.c:530)
==6424==    by 0x10A2CB: free_stop (memory.c:123)
==6424==    by 0x10AB07: remove_stop (remove.c:61)
==6424==    by 0x10920A: prompt_command (proj2.c:42)
==6424==    by 0x10920A: main (proj2.c:7)
==6424==  Block was alloc'd at
==6424==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==6424==    by 0x109E7A: wrap_calloc (memory.c:8)
==6424==    by 0x10A5AA: read_line (parsing.c:16)
==6424==    by 0x10912D: main (proj2.c:5)
==6424== 
==6424== Invalid read of size 1
==6424==    at 0x483D4F1: mempcpy (vg_replace_strmem.c:1536)
==6424==    by 0x4A4BB24: _IO_new_file_xsputn (fileops.c:1243)
==6424==    by 0x4A4BB24: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1204)
==6424==    by 0x4A2032A: vfprintf (vfprintf.c:1638)
==6424==    by 0x4A28735: printf (printf.c:33)
==6424==    by 0x109B77: list_lines (lines.c:121)
==6424==    by 0x10922A: prompt_command (proj2.c:27)
==6424==    by 0x10922A: main (proj2.c:7)
==6424==  Address 0x4b940d5 is 5 bytes inside a block of size 9 free'd
==6424==    at 0x48369AB: free (vg_replace_malloc.c:530)
==6424==    by 0x10A2CB: free_stop (memory.c:123)
==6424==    by 0x10AB07: remove_stop (remove.c:61)
==6424==    by 0x10920A: prompt_command (proj2.c:42)
==6424==    by 0x10920A: main (proj2.c:7)
==6424==  Block was alloc'd at
==6424==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==6424==    by 0x109E7A: wrap_calloc (memory.c:8)
==6424==    by 0x10A5AA: read_line (parsing.c:16)
==6424==    by 0x10912D: main (proj2.c:5)
==6424== 
==6424== Invalid write of size 8
==6424==    at 0x10AA80: remove_stop (remove.c:36)
==6424==    by 0x10920A: prompt_command (proj2.c:42)
==6424==    by 0x10920A: main (proj2.c:7)
==6424==  Address 0x4b950f0 is 16 bytes inside a block of size 48 free'd
==6424==    at 0x48369AB: free (vg_replace_malloc.c:530)
==6424==    by 0x10AA9D: remove_stop (remove.c:55)
==6424==    by 0x10920A: prompt_command (proj2.c:42)
==6424==    by 0x10920A: main (proj2.c:7)
==6424==  Block was alloc'd at
==6424==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==6424==    by 0x109E7A: wrap_calloc (memory.c:8)
==6424==    by 0x1094A1: create_node (connect.c:75)
==6424==    by 0x1094A1: connect_connection (connect.c:62)
==6424==    by 0x109843: handle_connect (connect.c:28)
==6424==    by 0x1091EA: prompt_command (proj2.c:33)
==6424==    by 0x1091EA: main (proj2.c:7)
==6424== 
==6424== Invalid read of size 16
==6424==    at 0x10AAE0: remove_stop (remove.c:47)
==6424==    by 0x10920A: prompt_command (proj2.c:42)
==6424==    by 0x10920A: main (proj2.c:7)
==6424==  Address 0x4b95100 is 32 bytes inside a block of size 48 free'd
==6424==    at 0x48369AB: free (vg_replace_malloc.c:530)
==6424==    by 0x10AA9D: remove_stop (remove.c:55)
==6424==    by 0x10920A: prompt_command (proj2.c:42)
==6424==    by 0x10920A: main (proj2.c:7)
==6424==  Block was alloc'd at
==6424==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==6424==    by 0x109E7A: wrap_calloc (memory.c:8)
==6424==    by 0x1094A1: create_node (connect.c:75)
==6424==    by 0x1094A1: connect_connection (connect.c:62)
==6424==    by 0x109843: handle_connect (connect.c:28)
==6424==    by 0x1091EA: prompt_command (proj2.c:33)
==6424==    by 0x1091EA: main (proj2.c:7)
==6424== 
==6424== Invalid write of size 8
==6424==    at 0x10AAF6: remove_stop (remove.c:49)
==6424==    by 0x10920A: prompt_command (proj2.c:42)
==6424==    by 0x10920A: main (proj2.c:7)
==6424==  Address 0x4b95100 is 32 bytes inside a block of size 48 free'd
==6424==    at 0x48369AB: free (vg_replace_malloc.c:530)
==6424==    by 0x10AA9D: remove_stop (remove.c:55)
==6424==    by 0x10920A: prompt_command (proj2.c:42)
==6424==    by 0x10920A: main (proj2.c:7)
==6424==  Block was alloc'd at
==6424==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==6424==    by 0x109E7A: wrap_calloc (memory.c:8)
==6424==    by 0x1094A1: create_node (connect.c:75)
==6424==    by 0x1094A1: connect_connection (connect.c:62)
==6424==    by 0x109843: handle_connect (connect.c:28)
==6424==    by 0x1091EA: prompt_command (proj2.c:33)
==6424==    by 0x1091EA: main (proj2.c:7)
==6424== 
==6424== Invalid read of size 8
==6424==    at 0x109B7F: list_lines (lines.c:122)
==6424==    by 0x10922A: prompt_command (proj2.c:27)
==6424==    by 0x10922A: main (proj2.c:7)
==6424==  Address 0x4b950e8 is 8 bytes inside a block of size 48 free'd
==6424==    at 0x48369AB: free (vg_replace_malloc.c:530)
==6424==    by 0x10AA9D: remove_stop (remove.c:55)
==6424==    by 0x10920A: prompt_command (proj2.c:42)
==6424==    by 0x10920A: main (proj2.c:7)
==6424==  Block was alloc'd at
==6424==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==6424==    by 0x109E7A: wrap_calloc (memory.c:8)
==6424==    by 0x1094A1: create_node (connect.c:75)
==6424==    by 0x1094A1: connect_connection (connect.c:62)
==6424==    by 0x109843: handle_connect (connect.c:28)
==6424==    by 0x1091EA: prompt_command (proj2.c:33)
==6424==    by 0x1091EA: main (proj2.c:7)
==6424== 
==6424== Invalid read of size 8
==6424==    at 0x109B83: list_lines (lines.c:122)
==6424==    by 0x10922A: prompt_command (proj2.c:27)
==6424==    by 0x10922A: main (proj2.c:7)
==6424==  Address 0x4b941c0 is 0 bytes inside a block of size 40 free'd
==6424==    at 0x48369AB: free (vg_replace_malloc.c:530)
==6424==    by 0x10AB07: remove_stop (remove.c:61)
==6424==    by 0x10920A: prompt_command (proj2.c:42)
==6424==    by 0x10920A: main (proj2.c:7)
==6424==  Block was alloc'd at
==6424==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==6424==    by 0x109E7A: wrap_calloc (memory.c:8)
==6424==    by 0x10ABD4: create_stop (stops.c:35)
==6424==    by 0x1091DA: prompt_command (proj2.c:30)
==6424==    by 0x1091DA: main (proj2.c:7)
==6424== 
==6424== Invalid read of size 1
==6424==    at 0x4838CC2: __strlen_sse2 (vg_replace_strmem.c:462)
==6424==    by 0x4A21B1E: vfprintf (vfprintf.c:1638)
==6424==    by 0x4A28735: printf (printf.c:33)
==6424==    by 0x109B8C: list_lines (lines.c:122)
==6424==    by 0x10922A: prompt_command (proj2.c:27)
==6424==    by 0x10922A: main (proj2.c:7)
==6424==  Address 0x4b940d0 is 0 bytes inside a block of size 9 free'd
==6424==    at 0x48369AB: free (vg_replace_malloc.c:530)
==6424==    by 0x10A2CB: free_stop (memory.c:123)
==6424==    by 0x10AB07: remove_stop (remove.c:61)
==6424==    by 0x10920A: prompt_command (proj2.c:42)
==6424==    by 0x10920A: main (proj2.c:7)
==6424==  Block was alloc'd at
==6424==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==6424==    by 0x109E7A: wrap_calloc (memory.c:8)
==6424==    by 0x10A5AA: read_line (parsing.c:16)
==6424==    by 0x10912D: main (proj2.c:5)
==6424== 
==6424== Invalid read of size 1
==6424==    at 0x4838CD4: __strlen_sse2 (vg_replace_strmem.c:462)
==6424==    by 0x4A21B1E: vfprintf (vfprintf.c:1638)
==6424==    by 0x4A28735: printf (printf.c:33)
==6424==    by 0x109B8C: list_lines (lines.c:122)
==6424==    by 0x10922A: prompt_command (proj2.c:27)
==6424==    by 0x10922A: main (proj2.c:7)
==6424==  Address 0x4b940d1 is 1 bytes inside a block of size 9 free'd
==6424==    at 0x48369AB: free (vg_replace_malloc.c:530)
==6424==    by 0x10A2CB: free_stop (memory.c:123)
==6424==    by 0x10AB07: remove_stop (remove.c:61)
==6424==    by 0x10920A: prompt_command (proj2.c:42)
==6424==    by 0x10920A: main (proj2.c:7)
==6424==  Block was alloc'd at
==6424==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==6424==    by 0x109E7A: wrap_calloc (memory.c:8)
==6424==    by 0x10A5AA: read_line (parsing.c:16)
==6424==    by 0x10912D: main (proj2.c:5)
==6424== 
==6424== Invalid read of size 8
==6424==    at 0x109FC0: free_line (memory.c:76)
==6424==    by 0x10A9FE: remove_line (remove.c:17)
==6424==    by 0x10915A: prompt_command (proj2.c:39)
==6424==    by 0x10915A: main (proj2.c:7)
==6424==  Address 0x4b97630 is 16 bytes inside a block of size 48 free'd
==6424==    at 0x48369AB: free (vg_replace_malloc.c:530)
==6424==    by 0x10AA9D: remove_stop (remove.c:55)
==6424==    by 0x10920A: prompt_command (proj2.c:42)
==6424==    by 0x10920A: main (proj2.c:7)
==6424==  Block was alloc'd at
==6424==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==6424==    by 0x109E7A: wrap_calloc (memory.c:8)
==6424==    by 0x1094A1: create_node (connect.c:75)
==6424==    by 0x1094A1: connect_connection (connect.c:62)
==6424==    by 0x109843: handle_connect (connect.c:28)
==6424==    by 0x1091EA: prompt_command (proj2.c:33)
==6424==    by 0x1091EA: main (proj2.c:7)
==6424== 
==6424== Invalid read of size 8
==6424==    at 0x109F90: free_line (memory.c:79)
==6424==    by 0x10A9FE: remove_line (remove.c:17)
==6424==    by 0x10915A: prompt_command (proj2.c:39)
==6424==    by 0x10915A: main (proj2.c:7)
==6424==  Address 0x10 is not stack'd, malloc'd or (recently) free'd
==6424== 
==6424== 
==6424== Process terminating with default action of signal 11 (SIGSEGV)
==6424==  Access not within mapped region at address 0x10
==6424==    at 0x109F90: free_line (memory.c:79)
==6424==    by 0x10A9FE: remove_line (remove.c:17)
==6424==    by 0x10915A: prompt_command (proj2.c:39)
==6424==    by 0x10915A: main (proj2.c:7)
==6424==  If you believe this happened as a result of a stack
==6424==  overflow in your program's main thread (unlikely but
==6424==  possible), you can try to increase the size of the
==6424==  main thread stack using the --main-stacksize= flag.
==6424==  The main thread stack size used in this run was 8388608.
==6424== 
==6424== HEAP SUMMARY:
==6424==     in use at exit: 266 bytes in 10 blocks
==6424==   total heap usage: 293 allocs, 283 frees, 12,184 bytes allocated
==6424== 
==6424== LEAK SUMMARY:
==6424==    definitely lost: 0 bytes in 0 blocks
==6424==    indirectly lost: 0 bytes in 0 blocks
==6424==      possibly lost: 0 bytes in 0 blocks
==6424==    still reachable: 266 bytes in 10 blocks
==6424==         suppressed: 0 bytes in 0 blocks
==6424== Rerun with --leak-check=full to see details of leaked memory
==6424== 
==6424== For counts of detected and suppressed errors, rerun with: -v
==6424== ERROR SUMMARY: 246 errors from 15 contexts (suppressed: 0 from 0)

```


Your code will not be reevaluated if you submit before 2023-03-31 12:08:10 @ Lisbon, Portugal. You need to wait 10 minute(s).

