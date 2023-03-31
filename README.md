# Projecto 2 - IAED 2022/2023

## Enunciado

O enunciado do projecto está disponível em [enunciado.md](enunciado.md). 

## Data de entrega: 14 de abril de 2023, às 19h59

Informações detalhadas sobre o processo de submissão estão disponíveis em [informacoes.md](informacoes.md).



# Evaluation

2023-03-31T12:17:09

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

## Test 25: [- Wrong Answer-].


## Test 26: [- Wrong Answer-].


## Test 27: [+ Accepted+].
## Test 28: [+ Accepted+].
## Test 29: [+ Accepted+].
## Test 30: [- Command terminated by signal (6: SIGABRT)-].

## Test 31: [- Command terminated by signal (11: SIGSEGV)-].

## Test 32: [- Wrong Answer-].




## Number of passed tests: 20/32


## Valgrind Output:


```
==10804== Memcheck, a memory error detector
==10804== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==10804== Using Valgrind-3.14.0 and LibVEX; rerun with -h for copyright info
==10804== Command: ./proj.out
==10804== 
==10804== Invalid read of size 8
==10804==    at 0x109B67: list_lines (lines.c:121)
==10804==    by 0x10922A: prompt_command (proj2.c:27)
==10804==    by 0x10922A: main (proj2.c:7)
==10804==  Address 0x4b950e8 is 8 bytes inside a block of size 48 free'd
==10804==    at 0x48369AB: free (vg_replace_malloc.c:530)
==10804==    by 0x10AAAA: remove_stop (remove.c:59)
==10804==    by 0x10920A: prompt_command (proj2.c:42)
==10804==    by 0x10920A: main (proj2.c:7)
==10804==  Block was alloc'd at
==10804==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==10804==    by 0x109E7A: wrap_calloc (memory.c:8)
==10804==    by 0x1094A1: create_node (connect.c:75)
==10804==    by 0x1094A1: connect_connection (connect.c:62)
==10804==    by 0x109843: handle_connect (connect.c:28)
==10804==    by 0x1091EA: prompt_command (proj2.c:33)
==10804==    by 0x1091EA: main (proj2.c:7)
==10804== 
==10804== Invalid read of size 8
==10804==    at 0x109B6E: list_lines (lines.c:121)
==10804==    by 0x10922A: prompt_command (proj2.c:27)
==10804==    by 0x10922A: main (proj2.c:7)
==10804==  Address 0x4b941c0 is 0 bytes inside a block of size 40 free'd
==10804==    at 0x48369AB: free (vg_replace_malloc.c:530)
==10804==    by 0x10AB17: remove_stop (remove.c:65)
==10804==    by 0x10920A: prompt_command (proj2.c:42)
==10804==    by 0x10920A: main (proj2.c:7)
==10804==  Block was alloc'd at
==10804==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==10804==    by 0x109E7A: wrap_calloc (memory.c:8)
==10804==    by 0x10ABE4: create_stop (stops.c:35)
==10804==    by 0x1091DA: prompt_command (proj2.c:30)
==10804==    by 0x1091DA: main (proj2.c:7)
==10804== 
==10804== Invalid read of size 1
==10804==    at 0x4838CC2: __strlen_sse2 (vg_replace_strmem.c:462)
==10804==    by 0x4A21B1E: vfprintf (vfprintf.c:1638)
==10804==    by 0x4A28735: printf (printf.c:33)
==10804==    by 0x109B77: list_lines (lines.c:121)
==10804==    by 0x10922A: prompt_command (proj2.c:27)
==10804==    by 0x10922A: main (proj2.c:7)
==10804==  Address 0x4b940d0 is 0 bytes inside a block of size 9 free'd
==10804==    at 0x48369AB: free (vg_replace_malloc.c:530)
==10804==    by 0x10A2CB: free_stop (memory.c:123)
==10804==    by 0x10AB17: remove_stop (remove.c:65)
==10804==    by 0x10920A: prompt_command (proj2.c:42)
==10804==    by 0x10920A: main (proj2.c:7)
==10804==  Block was alloc'd at
==10804==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==10804==    by 0x109E7A: wrap_calloc (memory.c:8)
==10804==    by 0x10A5AA: read_line (parsing.c:16)
==10804==    by 0x10912D: main (proj2.c:5)
==10804== 
==10804== Invalid read of size 1
==10804==    at 0x4838CD4: __strlen_sse2 (vg_replace_strmem.c:462)
==10804==    by 0x4A21B1E: vfprintf (vfprintf.c:1638)
==10804==    by 0x4A28735: printf (printf.c:33)
==10804==    by 0x109B77: list_lines (lines.c:121)
==10804==    by 0x10922A: prompt_command (proj2.c:27)
==10804==    by 0x10922A: main (proj2.c:7)
==10804==  Address 0x4b940d1 is 1 bytes inside a block of size 9 free'd
==10804==    at 0x48369AB: free (vg_replace_malloc.c:530)
==10804==    by 0x10A2CB: free_stop (memory.c:123)
==10804==    by 0x10AB17: remove_stop (remove.c:65)
==10804==    by 0x10920A: prompt_command (proj2.c:42)
==10804==    by 0x10920A: main (proj2.c:7)
==10804==  Block was alloc'd at
==10804==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==10804==    by 0x109E7A: wrap_calloc (memory.c:8)
==10804==    by 0x10A5AA: read_line (parsing.c:16)
==10804==    by 0x10912D: main (proj2.c:5)
==10804== 
==10804== Invalid read of size 1
==10804==    at 0x483D4E0: mempcpy (vg_replace_strmem.c:1536)
==10804==    by 0x4A4BB24: _IO_new_file_xsputn (fileops.c:1243)
==10804==    by 0x4A4BB24: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1204)
==10804==    by 0x4A2032A: vfprintf (vfprintf.c:1638)
==10804==    by 0x4A28735: printf (printf.c:33)
==10804==    by 0x109B77: list_lines (lines.c:121)
==10804==    by 0x10922A: prompt_command (proj2.c:27)
==10804==    by 0x10922A: main (proj2.c:7)
==10804==  Address 0x4b940d7 is 7 bytes inside a block of size 9 free'd
==10804==    at 0x48369AB: free (vg_replace_malloc.c:530)
==10804==    by 0x10A2CB: free_stop (memory.c:123)
==10804==    by 0x10AB17: remove_stop (remove.c:65)
==10804==    by 0x10920A: prompt_command (proj2.c:42)
==10804==    by 0x10920A: main (proj2.c:7)
==10804==  Block was alloc'd at
==10804==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==10804==    by 0x109E7A: wrap_calloc (memory.c:8)
==10804==    by 0x10A5AA: read_line (parsing.c:16)
==10804==    by 0x10912D: main (proj2.c:5)
==10804== 
==10804== Invalid read of size 1
==10804==    at 0x483D4F1: mempcpy (vg_replace_strmem.c:1536)
==10804==    by 0x4A4BB24: _IO_new_file_xsputn (fileops.c:1243)
==10804==    by 0x4A4BB24: _IO_file_xsputn@@GLIBC_2.2.5 (fileops.c:1204)
==10804==    by 0x4A2032A: vfprintf (vfprintf.c:1638)
==10804==    by 0x4A28735: printf (printf.c:33)
==10804==    by 0x109B77: list_lines (lines.c:121)
==10804==    by 0x10922A: prompt_command (proj2.c:27)
==10804==    by 0x10922A: main (proj2.c:7)
==10804==  Address 0x4b940d5 is 5 bytes inside a block of size 9 free'd
==10804==    at 0x48369AB: free (vg_replace_malloc.c:530)
==10804==    by 0x10A2CB: free_stop (memory.c:123)
==10804==    by 0x10AB17: remove_stop (remove.c:65)
==10804==    by 0x10920A: prompt_command (proj2.c:42)
==10804==    by 0x10920A: main (proj2.c:7)
==10804==  Block was alloc'd at
==10804==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==10804==    by 0x109E7A: wrap_calloc (memory.c:8)
==10804==    by 0x10A5AA: read_line (parsing.c:16)
==10804==    by 0x10912D: main (proj2.c:5)
==10804== 
==10804== Invalid write of size 8
==10804==    at 0x10AA80: remove_stop (remove.c:36)
==10804==    by 0x10920A: prompt_command (proj2.c:42)
==10804==    by 0x10920A: main (proj2.c:7)
==10804==  Address 0x4b950f0 is 16 bytes inside a block of size 48 free'd
==10804==    at 0x48369AB: free (vg_replace_malloc.c:530)
==10804==    by 0x10AAAA: remove_stop (remove.c:59)
==10804==    by 0x10920A: prompt_command (proj2.c:42)
==10804==    by 0x10920A: main (proj2.c:7)
==10804==  Block was alloc'd at
==10804==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==10804==    by 0x109E7A: wrap_calloc (memory.c:8)
==10804==    by 0x1094A1: create_node (connect.c:75)
==10804==    by 0x1094A1: connect_connection (connect.c:62)
==10804==    by 0x109843: handle_connect (connect.c:28)
==10804==    by 0x1091EA: prompt_command (proj2.c:33)
==10804==    by 0x1091EA: main (proj2.c:7)
==10804== 
==10804== Invalid read of size 16
==10804==    at 0x10AAF0: remove_stop (remove.c:47)
==10804==    by 0x10920A: prompt_command (proj2.c:42)
==10804==    by 0x10920A: main (proj2.c:7)
==10804==  Address 0x4b95100 is 32 bytes inside a block of size 48 free'd
==10804==    at 0x48369AB: free (vg_replace_malloc.c:530)
==10804==    by 0x10AAAA: remove_stop (remove.c:59)
==10804==    by 0x10920A: prompt_command (proj2.c:42)
==10804==    by 0x10920A: main (proj2.c:7)
==10804==  Block was alloc'd at
==10804==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==10804==    by 0x109E7A: wrap_calloc (memory.c:8)
==10804==    by 0x1094A1: create_node (connect.c:75)
==10804==    by 0x1094A1: connect_connection (connect.c:62)
==10804==    by 0x109843: handle_connect (connect.c:28)
==10804==    by 0x1091EA: prompt_command (proj2.c:33)
==10804==    by 0x1091EA: main (proj2.c:7)
==10804== 
==10804== Invalid write of size 8
==10804==    at 0x10AB06: remove_stop (remove.c:49)
==10804==    by 0x10920A: prompt_command (proj2.c:42)
==10804==    by 0x10920A: main (proj2.c:7)
==10804==  Address 0x4b95100 is 32 bytes inside a block of size 48 free'd
==10804==    at 0x48369AB: free (vg_replace_malloc.c:530)
==10804==    by 0x10AAAA: remove_stop (remove.c:59)
==10804==    by 0x10920A: prompt_command (proj2.c:42)
==10804==    by 0x10920A: main (proj2.c:7)
==10804==  Block was alloc'd at
==10804==    at 0x4837B65: calloc (vg_replace_malloc.c:752)
==10804==    by 0x109E7A: wrap_calloc (memory.c:8)
==10804==    by 0x1094A1: create_node (connect.c:75)
==10804==    by 0x1094A1: connect_connection (connect.c:62)
==10804==    by 0x109843: handle_connect (connect.c:28)
==10804==    by 0x1091EA: prompt_command (proj2.c:33)
==10804==    by 0x1091EA: main (proj2.c:7)
==10804== 
==10804== Invalid read of size 8
==10804==    at 0x109B50: list_lines (lines.c:117)
==10804==    by 0x10922A: prompt_command (proj2.c:27)
==10804==    by 0x10922A: main (proj2.c:7)
==10804==  Address 0x4b94de0 is 0 bytes inside a block of size 32 free'd
==10804==    at 0x4837D7B: realloc (vg_replace_malloc.c:826)
==10804==    by 0x10A422: wrap_realloc (memory.c:23)
==10804==    by 0x10A422: VECremove (memory.c:150)
==10804==    by 0x10AA15: remove_line (remove.c:18)
==10804==    by 0x10915A: prompt_command (proj2.c:39)
==10804==    by 0x10915A: main (proj2.c:7)
==10804==  Block was alloc'd at
==10804==    at 0x4837D7B: realloc (vg_replace_malloc.c:826)
==10804==    by 0x10A317: wrap_realloc (memory.c:23)
==10804==    by 0x10A317: VECinsert (memory.c:134)
==10804==    by 0x109CF5: create_line (lines.c:70)
==10804==    by 0x109CF5: handle_line (lines.c:21)
==10804==    by 0x10922A: prompt_command (proj2.c:27)
==10804==    by 0x10922A: main (proj2.c:7)
==10804== 
==10804== Invalid read of size 8
==10804==    at 0x10994C: get_line (lines.c:49)
==10804==    by 0x10A9F1: remove_line (remove.c:8)
==10804==    by 0x10915A: prompt_command (proj2.c:39)
==10804==    by 0x10915A: main (proj2.c:7)
==10804==  Address 0x4b94de0 is 0 bytes inside a block of size 32 free'd
==10804==    at 0x4837D7B: realloc (vg_replace_malloc.c:826)
==10804==    by 0x10A422: wrap_realloc (memory.c:23)
==10804==    by 0x10A422: VECremove (memory.c:150)
==10804==    by 0x10AA15: remove_line (remove.c:18)
==10804==    by 0x10915A: prompt_command (proj2.c:39)
==10804==    by 0x10915A: main (proj2.c:7)
==10804==  Block was alloc'd at
==10804==    at 0x4837D7B: realloc (vg_replace_malloc.c:826)
==10804==    by 0x10A317: wrap_realloc (memory.c:23)
==10804==    by 0x10A317: VECinsert (memory.c:134)
==10804==    by 0x109CF5: create_line (lines.c:70)
==10804==    by 0x109CF5: handle_line (lines.c:21)
==10804==    by 0x10922A: prompt_command (proj2.c:27)
==10804==    by 0x10922A: main (proj2.c:7)
==10804== 
==10804== Invalid free() / delete / delete[] / realloc()
==10804==    at 0x4837D7B: realloc (vg_replace_malloc.c:826)
==10804==    by 0x10A422: wrap_realloc (memory.c:23)
==10804==    by 0x10A422: VECremove (memory.c:150)
==10804==    by 0x10AA15: remove_line (remove.c:18)
==10804==    by 0x10915A: prompt_command (proj2.c:39)
==10804==    by 0x10915A: main (proj2.c:7)
==10804==  Address 0x4b94de0 is 0 bytes inside a block of size 32 free'd
==10804==    at 0x4837D7B: realloc (vg_replace_malloc.c:826)
==10804==    by 0x10A422: wrap_realloc (memory.c:23)
==10804==    by 0x10A422: VECremove (memory.c:150)
==10804==    by 0x10AA15: remove_line (remove.c:18)
==10804==    by 0x10915A: prompt_command (proj2.c:39)
==10804==    by 0x10915A: main (proj2.c:7)
==10804==  Block was alloc'd at
==10804==    at 0x4837D7B: realloc (vg_replace_malloc.c:826)
==10804==    by 0x10A317: wrap_realloc (memory.c:23)
==10804==    by 0x10A317: VECinsert (memory.c:134)
==10804==    by 0x109CF5: create_line (lines.c:70)
==10804==    by 0x109CF5: handle_line (lines.c:21)
==10804==    by 0x10922A: prompt_command (proj2.c:27)
==10804==    by 0x10922A: main (proj2.c:7)
==10804== 
==10804== Invalid read of size 8
==10804==    at 0x109D75: clean_db (memory.c:51)
==10804==    by 0x10A453: wrap_realloc (memory.c:26)
==10804==    by 0x10A453: wrap_realloc (memory.c:22)
==10804==    by 0x10A453: VECremove (memory.c:150)
==10804==    by 0x10AA15: remove_line (remove.c:18)
==10804==    by 0x10915A: prompt_command (proj2.c:39)
==10804==    by 0x10915A: main (proj2.c:7)
==10804==  Address 0x4b94de0 is 0 bytes inside a block of size 32 free'd
==10804==    at 0x4837D7B: realloc (vg_replace_malloc.c:826)
==10804==    by 0x10A422: wrap_realloc (memory.c:23)
==10804==    by 0x10A422: VECremove (memory.c:150)
==10804==    by 0x10AA15: remove_line (remove.c:18)
==10804==    by 0x10915A: prompt_command (proj2.c:39)
==10804==    by 0x10915A: main (proj2.c:7)
==10804==  Block was alloc'd at
==10804==    at 0x4837D7B: realloc (vg_replace_malloc.c:826)
==10804==    by 0x10A317: wrap_realloc (memory.c:23)
==10804==    by 0x10A317: VECinsert (memory.c:134)
==10804==    by 0x109CF5: create_line (lines.c:70)
==10804==    by 0x109CF5: handle_line (lines.c:21)
==10804==    by 0x10922A: prompt_command (proj2.c:27)
==10804==    by 0x10922A: main (proj2.c:7)
==10804== 
==10804== Invalid free() / delete / delete[] / realloc()
==10804==    at 0x48369AB: free (vg_replace_malloc.c:530)
==10804==    by 0x109DD9: clean_db (memory.c:54)
==10804==    by 0x10A453: wrap_realloc (memory.c:26)
==10804==    by 0x10A453: wrap_realloc (memory.c:22)
==10804==    by 0x10A453: VECremove (memory.c:150)
==10804==    by 0x10AA15: remove_line (remove.c:18)
==10804==    by 0x10915A: prompt_command (proj2.c:39)
==10804==    by 0x10915A: main (proj2.c:7)
==10804==  Address 0x4b94de0 is 0 bytes inside a block of size 32 free'd
==10804==    at 0x4837D7B: realloc (vg_replace_malloc.c:826)
==10804==    by 0x10A422: wrap_realloc (memory.c:23)
==10804==    by 0x10A422: VECremove (memory.c:150)
==10804==    by 0x10AA15: remove_line (remove.c:18)
==10804==    by 0x10915A: prompt_command (proj2.c:39)
==10804==    by 0x10915A: main (proj2.c:7)
==10804==  Block was alloc'd at
==10804==    at 0x4837D7B: realloc (vg_replace_malloc.c:826)
==10804==    by 0x10A317: wrap_realloc (memory.c:23)
==10804==    by 0x10A317: VECinsert (memory.c:134)
==10804==    by 0x109CF5: create_line (lines.c:70)
==10804==    by 0x109CF5: handle_line (lines.c:21)
==10804==    by 0x10922A: prompt_command (proj2.c:27)
==10804==    by 0x10922A: main (proj2.c:7)
==10804== 
==10804== 
==10804== HEAP SUMMARY:
==10804==     in use at exit: 24 bytes in 1 blocks
==10804==   total heap usage: 298 allocs, 298 frees, 12,238 bytes allocated
==10804== 
==10804== LEAK SUMMARY:
==10804==    definitely lost: 24 bytes in 1 blocks
==10804==    indirectly lost: 0 bytes in 0 blocks
==10804==      possibly lost: 0 bytes in 0 blocks
==10804==    still reachable: 0 bytes in 0 blocks
==10804==         suppressed: 0 bytes in 0 blocks
==10804== Rerun with --leak-check=full to see details of leaked memory
==10804== 
==10804== For counts of detected and suppressed errors, rerun with: -v
==10804== ERROR SUMMARY: 102 errors from 14 contexts (suppressed: 0 from 0)

```


Your code will not be reevaluated if you submit before 2023-03-31 12:27:09 @ Lisbon, Portugal. You need to wait 10 minute(s).

