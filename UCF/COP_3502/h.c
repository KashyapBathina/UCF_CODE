/*
hash-table:
    abstract data type that stores and retrieves records according to search key results; given situation a record is an individual row in the table (ie a database of students with 
    each row a record of certain student with pid, name, ect.); so if given table or records of database students, want to add, delete, and search records, it is inefficient to just
    regularly store into array, as then we don't know where each value is so we have to do O(n) to find in search and delete; howevr, faster way which has O(1) constnt time for add, 
    del, and search--called ddirect access table which is arr so large each record has exclusive cell, however this is still inefficient as an array with large number is impractical
    with memory, since we want reasonably sized array and O(1) time for each, solution is to map certain number or record, (ie id), to index such that ex: 553432432 maps to 50 instd 
    to be used as index insted of the large number, to do this, make a function that converts a key (ie id) to an index--this is a hash table--an array of table items wher indx calc
    by hash function; hence when searching for item with key 1323, dont need to search entire table, insted just use hash function to find immediate index--called hashing
    hash-function: a mathematical calc that maps the search key to index, should be O(1) and distribute items evenly and also arr size ! large; 3 simple hash functions for integers:
        1) selecting digits--insted of using whole integer, only select several digits, ie if id=3422, just use last 2 so h(3422)=22, often has collisions
        2) folding hash func--add digits of integer together in differnt ways, ie if id=3422, can use hash fucnt add togeth so h(3422)=11
        3) modulo arithmetic--using modulus as hash funct, ie h(x) = x % table_size, note using prime number as tableSize or mod mathematic reduces collisions
        4) string--keys don't just have to be ints like id, can use strings then covert that string into int to then apply to hash, 3 ways to convert string into int
            a) assign a-z to numbers 0-25 and add ints togeth b) use ascii or unicode int value for each char and add togethr c) use binary number for ascii or unicode int value for 
            each char and concatenate the binary nums together, ie covert each char->ascii(int)->binary->concaetonate all binary, 01+10=0110
    collision: however the main problem is collisions, as ideally hash funct maps each key into diff index, but more likely, hash funct maps 2 or more search keys into the same loci
        in the hash table so h(key1)=h(key2), ie when hash func last 2 digits, 3222 and 4222 will have the same index and can't store 2 items in same indx; conflict resolution:
        1) open addressing--one way is to re-assign search keys with same hash to diff loci in hash table is to while also keeping table even; method searches for open loci in hash 
            table, where the probe/search sequence is the seq of locations that are examined for possible open loci to put next item, 3 types of probing 
            a) linear probing--in case of collision, keeps going to next hash tbale until find open loci, ie if t[i]!=NULL, check t[i+1], t[i+2] etc, howevr problem is items tend to 
                cluster together in hash table; 
            b) quadratic probing--insted of checking next loci seq, check next location based on squares, ie t[i], t[i+1^2], t[i+2^2] ect, still clustring but not as bad
            c) double hashing--use 2 hash func, where 2nd hash deterimnes step size to next hash table indx, noting h2(key) != 0, and h2!=h1, note h2 just deterimnes seq of stepping 
                or probing, but unlike linear and quadratic, not same for all; if table size prime, probe seq visist all loci, w open addressing, increasing size reduces collisions, 
                but also have to reapply hash func to every item in old hash so old hash_funct vals scal with new size
        2) restructuring hash table--in case of clash and 2 items same index, structure of hash table changes so same index can store multiple items, 2 ways to restructure:
            a) bucket hashing--hash tbale has array at each loci (double arr) so item of same index stored there, choosing size of each bucket(arrr at each index) problematic, as if
                too small, collisions, and if too big will waste space
            b) seperate chaining--to fix issue of size of bucket, use linked list chain at each table[i] so items of same hash indx stored there, size dynamic and ! problematic

trie:
    can use BST to store strings, where each node is char, however, this results in many comparisons while traversing through tree and also time consuming; howevr, this is even more
    problematic if have large dictionary, especially with some that begin with same prefix, ie spaghhetti..1, spha..2, sp...3, so altrnt is trie, which efficiently stores and serchs 
    for strings; trie is another data struct from word re(trie)val and each node has 26 children with some of all NULL, 26 becuse 26 letters and each pointer arr[i] is for each char
    code: struct TrieNode{int count; struct TrieNode *children[26]}, stores children in arr to easily access; though we use tries to represent strings, strings insert are not stored 
    as data inside nodes, instead string node represents is based on path you take to reach node: ie for pie, to store in trie, from root, access child 15 (p), then from that node p
    , go child 8 (i), then from that i node, child 4 (e), at that value, set the int count=1, b/c at that point with that specific line (no other i index has that count=1 b/c this i 
    only avaiable with this specific line from p i e), there is a string starting from root till that (and inclding) the currnt node i; other children auto set to NULL; p 16th lettr
    but since index 0 (a) counting, p index 15; good applications for dictionary, spell check, and word prediction from typing
    run time: where k len of string inserting/del/looking, for insertion, worst and best o(k) b/c have to go through trie inserting each char, so in total, the length of word=k; for 
        look-up, wrst o(k) and best o(1), b/c worst is having to iterate thru all lettrs and get to end of len, meaning found value, else if not find string (meaning s[i]-'a' return 
        null), then the string isn't in tree so not iterating k, insted its O(1); for deletion, worst O(k), best O(1) b/c worst case is traverse down entire depth and finally delet
        by changing the count-=1 to note not string there anymore, best case is if item we want to delete isn't there
    accessing index: each letter represent 0-25 indexes, a=0, p=15, and to access something like root->children[0]->children[15]->etc; however, to find index, children['a'-'a'] reps
        children[0], children['p'-'a'] is 15 and so on, so to access, do char - 'a' which uses ascii calculations, genearlized to children[str[i]-'a']
    deleting strings: multiple cases: 1) if string not present, then delete not modifying 2) if string is prefix of another, ie deleting car, but also card in tree, then just make 
        count-=0 at that point 3) if str has has prefix in tree, ie deleting baller but ball in tree, then delete nodes from end of string till 1st leaft node of prefix ball, ie 3;
        in code just recurs till count=1, 4) if str doesn't contain another string (no other part of string contains other prefix), then just delete all nodes starting from bottom

bitwise operators:
    boolean logic like & | also work with single bits, ie 0 & 1 = 0 and 0 | 1 = 1; these bitwse operatrs also work with binary numbers by doing on each bit, ie 011 & 101 = 001; thus
    in c code  for bits, and is sole &, r is |, xor (only one of bits 1) is ^, not is ~;
    bitwise masking: masking is keeping change and removing desired part of info, mask defines which bits want to keep and what you want to clear, and masking is act of appling mask 
        to value, can be done by bitwise AND in order to A) "extract" subset of bits in val; B) OR to "set" subset of bits in val, XOR to C) "toggle" subset of bits ; ex, if num is
        00110010 and you want to set least significant to 1, remeber to set use OR, so do val | 00000001 so all other bits same and just LSB changed to 1; ex, to determine if int is
        odd/even, can just do val & 1, b/c remember only odd num in binary base is 2^0=1, rest are even, so ANDing ..001 (ie 1 at index 0), we extract and remving all bits excpt the
        LSB, and if value has LSB 1, & 1 returns 1 so odd, else returns 0 so even
        rules: if want to extract and get values, use AND on mask, where indexes you want to extract you set mask=1
        two's complement: to accomadate negative numbers and not rely purly on MSB (ie just doing sign bit 1 or 0 is wrong b/c for value 0, equals both 100 and 000 but no -0, so
            that introuces ambiguity on whether +0 and -0 distinct or equal and difficult circuit/hardware wise), so instead consistnt method, 2's complment which still uses MSB; if
            know original positive (ie since still use MSB,=1) and want to convert to -, then 1) bit inverse and flip digits then 2) add 1; when addin, if carrout and caryin for the 
            left most bit are same, then ignore that value, esle overflow
        left and right shift: left shift is << (pointing left) and right shift is >>, shift moves each bit in number to left a certain number of places, so as long as no overflow, x
            2 b/c of powers, ie ls k bits multiplies val * 2^k; right shift divides by 2; note both ls and rs cannot have - numbers in either operands, val or the shift num; when get
            array, order index switched, use MSB for last arr slot and LSB for index 0; note can do binary cal on integers, ie if i=32 and do i & (1) does comparison btwn 10.. & ..01

backtracking:
    technique used to solve problems with large search space by systematically tryiing and eliminating possibilites--ie going thru maze and when getting stuck in 1 path, backtrack to
    the function and then go other junction; to represent this maze in code, use n*n binary matrix where source m[0][0] and destination is somewere lowr right m[n-1][n-1], and to rep
    -resent dead ends or walls, use 0 and 1 to mean block can be used in path from source to destination; to walk thru maze, do right maz[i][j+1], up maz[i-1][j] etc, and bfore movin
    ensure you are out of matrix; thus backtracking algorithm is following, where we keep another solution array to dictate user path: if (destination reached) print solution matrix; 
    else a) mark current cell=1 b) move left and recurs check if leads to sol c) if above not work, do for right, up, and down in same fashion d) if none of solution work, unmark cell
    as 0 (backtrack) and return false; so algorithm is essentially 1) checking if solution, 2) else trying this path by setting=1, then 3) recurs doing movemnt in all 4 directions, if 
    all of these don't exit and print, then returns back and know none of above solutions work, 4) hence, note this path not possible by setting=0 (backtrack) and return false, to ch-
    eck direction and paths, just do recurse if(solveMaze(direction choice))==1, return so we dont have to try other paths right, down etc  
*/






#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    printf("hello, world");

    return 0;
}