swapnibbles:	swapnibbles.c
	gcc swapnibbles.c -o swapnibbles

zerohnibble:	zerohnibble.c
	gcc zerohnibble.c -o zerohnibble

mooncresta_decrypt:	mooncresta_decrypt.c
	gcc mooncresta_decrypt.c -o mooncresta_decrypt

clean:
	rm zerohnibble swapnibbles
