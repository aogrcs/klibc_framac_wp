/*
 * strcpy.c
 *
 * strcpy()
 */

#include <string.h>

/*@
	requires \exists integer i; 0 <= i <= 20000 && Length_of_str_is(src, i);
	requires \valid(dst+(0..Length(src)));
	requires \separated(src+(0..Length(src)), dst+(0..Length(src)));
	assigns dst[0..Length(src)];
	ensures \exists integer i; 0 <= i && Length_of_str_is(src,i) && Length_of_str_is(dst,i);
	ensures \forall integer i; 0 <= i <= Length(src) ==> dst[i] == src[i];
	ensures \result == dst;
@*/
char *strcpy(char *dst, const char *src)
{
	char *q = dst;
	const char *p = src;
	char ch;
	// ghost int k = 0;

 	/*@
 		loop invariant q != dst ==> ch != 0;
		loop invariant p != src ==> ch != 0;
		//loop invariant k != 0 ==> ch != 0;
 		loop invariant 0 <= (\at(p, Here) - \at(p, Pre)) <= Length(src);
 		//loop invariant k == p - src;
		loop invariant \base_addr(q) == \base_addr(dst);
		loop invariant \base_addr(p) == \base_addr(src);
		loop invariant dst <= q <= dst + Length(src);
		loop invariant src <= p <= src + Length(src);
		loop invariant q == dst + (\at(p, Here) - \at(p, Pre));
		loop invariant p == src + (\at(p, Here) - \at(p, Pre));
		loop invariant \forall integer i; 0 <= i < (\at(p, Here) - \at(p, Pre)) ==> dst[i] == src[i];
		loop invariant \forall integer i; 0 <= i < (\at(p, Here) - \at(p, Pre)) ==> src[i] != 0;
		loop assigns ch, p, q, dst[0..(\at(p, Here) - \at(p, Pre) - 1)];
		loop variant Length(src) - (\at(p, Here) - \at(p, Pre)); //k;

	@*/
  do {
	//while(ch)
		*q++ = ch = *p++;
		// ghost k++;

  } while (ch);

	return dst;
}
