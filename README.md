# OldRomUtils
Simple shell filters and maybe other utilities to help dealing with old Arcade (and other digital machines) that used lots of 4 bits wide PROMs

1) `swapnibbles`

It works as shell filter (example: cat ROM.bin | swapnibbles > ROMSWAP.bin)
As you can guess, it swaps high and low nibbles in each byte.

2) `zerohnibble`

It works as shell filter (example: cat ROM.bin | zerohnibble > ROML.bin)
As you can guess, it zeroes the high nibble in each byte.
