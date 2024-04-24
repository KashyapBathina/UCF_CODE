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
*/






#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    printf("hello, world");

    return 0;
}