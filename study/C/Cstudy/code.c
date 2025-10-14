#ifndef PIN
#error Please compile with -DPIN=<number>
#else
#ifndef _
#define _ __FILE__
#if PIN % 2 > 0
#define f
#endif
#if PIN % 4 > 1
#define n
#endif
#if PIN % 8 > 3
#define r
#endif
#if PIN % 16 > 7
#define I
#endif
#if PIN % 32 > 15
#define A
#endif
#if PIN % 64 > 31
#define g
#endif
#if PIN % 128 > 63
#define c
#endif
#if PIN % 256 > 127
#define s
#endif
#if PIN % 512 > 255
#define j
#endif
#if PIN % 1024 > 511
#define u
#endif
#if PIN % 2048 > 1023
#define B
#endif
#if PIN % 4096 > 2047
#define d
#endif
#if PIN % 8192 > 4095
#define E
#endif
#if PIN % 16384 > 8191
#define h
#endif
#if PIN % 32768 > 16383
#define o
#endif
#if PIN % 65536 > 32767
#define b
#endif
static const unsigned char O[] = {
#define C
#define e
#define w
#define v
#include _
#define k
#define e
#define G
#include _
#define C
#define J
#define m
#define y
#define z
#include _
#define y
#define k
#define w
#define C
#include _
#define e
#define k
#define C
#define t
#define m
#include _
#define z
#define w
#define G
#define C
#define J
#define m
#include _
#define w
#define z
#define C
#define G
#define k
#define e
#include _
#define J
#define z
#define m
#include _
#define y
#define J
#define C
#define m
#include _
#define z
#define J
#include _
#define w
#define y
#define C
#define z
#define k
#define e
#include _
#define C
#define w
#define m
#define y
#include _
#define k
#define w
#define J
#define C
#include _
#define z
#define C
#define e
#include _
};
#include<stdio.h>
int main() { return !fwrite(O, 14, 1, stdout); }
#else
#ifdef v
#undef v
#define F
#include _
#ifdef u
#define C
#endif
#ifdef E
#define e
#endif
#ifdef I
#define m
#endif
#ifdef n
#define y
#endif
#ifdef s
#define J
#endif
#ifdef b
#define w
#endif
#ifdef r
#define z
#endif
#ifdef d
#define k
#endif
#undef F
#include _
0,
#define v
#else
#ifdef t
#undef t
#include _
#define G
#include _
#define G
#endif
#ifdef G
#undef G
#include _
#define k
#include _
#define k
#endif
#ifdef k
#undef k
#include _
#define z
#include _
#define z
#endif
#ifdef z
#undef z
#include _
#define w
#include _
#define w
#endif
#ifdef w
#undef w
#include _
#define J
#include _
#define J
#endif
#ifdef J
#undef J
#include _
#define y
#include _
#define y
#endif
#ifdef y
#undef y
#include _
#define m
#include _
#define m
#endif
#ifdef m
#undef m
#include _
#define e
#include _
#define e
#endif
#ifdef e
#undef e
#include _
#define C
#include _
#define C
#endif
#ifdef C
#undef C
#ifdef F
#undef p
#ifdef r
#ifdef I
#ifdef g
#ifndef f
#define p
#endif
#else
#ifdef f
#define p
#endif
#endif
#else
#ifdef g
#ifdef f
#define p
#endif
#else
#ifndef f
#define p
#endif
#endif
#endif
#else
#ifdef I
#ifdef g
#ifdef f
#define p
#endif
#else
#ifndef f
#define p
#endif
#endif
#else
#ifdef g
#ifndef f
#define p
#endif
#else
#ifdef f
#define p
#endif
#endif
#endif
#endif
#undef f
#ifdef n
#define f
#endif
#undef n
#ifdef r
#define n
#endif
#undef r
#ifdef I
#define r
#endif
#undef I
#ifdef A
#define I
#endif
#undef A
#ifdef g
#define A
#endif
#undef g
#ifdef c
#define g
#endif
#undef c
#ifdef s
#define c
#endif
#undef s
#ifdef j
#define s
#endif
#undef j
#ifdef u
#define j
#endif
#undef u
#ifdef B
#define u
#endif
#undef B
#ifdef d
#define B
#endif
#undef d
#ifdef E
#define d
#endif
#undef E
#ifdef h
#define E
#endif
#undef h
#ifdef o
#define h
#endif
#undef o
#ifdef b
#define o
#endif
#undef b
#ifdef p
#define b
#endif
#else
-~
#endif
#endif
#endif
#endif
#endif
